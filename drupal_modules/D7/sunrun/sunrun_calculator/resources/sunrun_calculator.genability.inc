<?php

/**
 * @file
 *  Genability REST service functionality
 */

use Curl\Curl;

define('PROJECT_DURATION', 20);

/**
 * Initialize the Curl object library.
 *
 * @return \Curl\Curl
 */
function _genability_curl_init() {
  libraries_load('php-curl-class');

  $c = new Curl();
  $c->setHeader('Content-Type', 'application/json');

  return $c;
}

/**
 * Create a Genability account, to be used for savings analysis.
 *
 * @param $address
 * @param $zip
 * @param $property_sqft
 *
 * @return null
 */
function _genability_create_account($address, $zip, $property_sqft) {
  $account = [
    'address' => [
      'address1' => $address,
      'zip' => $zip,
    ],
    'accountName' => $address,
    'properties' => [
      'customerClass' => [
        'keyName' => 'customerClass',
        'dataValue' => 1 // residential
      ],
      'buildingArea' => [
        'keyName' => 'buildingArea',
        'dataValue' => ($property_sqft) ? $property_sqft : "",
      ]
    ],
  ];

  $curl = _genability_curl_init();
  $curl->post(_genability_generate_svc_url('accounts'), json_encode($account));

  if ($curl->error) {
    watchdog('sunrun_calculator',
      'Unable to create Genability account for address [%address] and zip [%zip]. %error',
      [
        "%address" => $address,
        '%zip' => $zip,
        '%error' => $curl->errorMessage,
      ]);
    return NULL;
  }

  $response = $curl->response->results[0];

  return [
    'accountId' => $response->accountId,
    'lseId' => $response->tariffs[0]->lseId,
  ];
}

/**
 * Retrieve a savings analysis from Genability, based on the escalator and
 * rate provided.
 *
 * This method manages the first step in creating a Genability analysis.
 * - Create a genability account.
 *
 * @param $address
 * @param $state database response object
 * @param $zipcode
 * @param $monthly_bill
 * @param $property_size
 *
 * @return null/void
 */
function genability_get_savings($address, $state, $zipcode, $monthly_bill, $property_size) {
  $account = _genability_create_account($address, $zipcode, $property_size);

  $account_id = $account['accountId'];
  // If this state supports the use of LSEID, indicative that paying includes monthly
  // then we use the LSEID from Genability. Otherwise, we don't use a LSEID at all
  $lse_id = ($state['genability_utility_lseid']) ? $account['lseId'] : null;

  return genability_get_finance_estimate($account_id, $lse_id, $state, $monthly_bill);
}

/**
 * Retrieve financial estimate for a specific account with a specific estimated
 * monthly bill.
 *
 * This method handles the second part of retrieving an analysis.  Assumes that
 * step one (creating an account) has already been completed.
 *
 * 2. Determine the kWh month of usage based on the estimated monthly bill.
 * 3. Create a profile based on the kWh usage.
 * 4. Retrieve savings analysis based on profile as well as the type of financing
 * required for the state/lseid.  Ex: Florida only does loan and cash
 *
 * @param $account_id
 * @param $lse_id
 * @param $state
 * @param $monthly_bill
 *
 * @return mixed
 */
function genability_get_finance_estimate($account_id, $lse_id, $state, $monthly_bill) {
  $state_pricing = (is_array($state)) ? $state : genability_get_state_pricing($state, $lse_id);

  if (! $state_pricing) {
    watchdog('sunrun_calculator',
      'State pricing data doesn\'t exist for [%state].',
      [
        '%state' => $state,
      ]);

    // Although a state may be represented in the database, the utility for the address given
    // may not match any of the utilities provided to us for that state, by Sunrun
    header('HTTP/1.1 404 Not Found');
    $msg = "Solar savings data doesn't exist for that address in " . $state . ".";
    echo drupal_json_encode(_assemble_payload($msg, 'error'));
    drupal_exit();
  }

  // Convert monthly estimated bill to kWh usage to be used in profile creation
  $kwh_monthly = _genability_get_kwh_month($account_id, $monthly_bill);
  // Generate a profile that helps the analysis understand how much energy is being used monthly
  $profile_id = _genability_create_profile($account_id, $kwh_monthly);

  $raw_genability_results = [];

  $savings['account_id'] = $account_id;
  $savings['lse_id'] = $lse_id;

  //--------------------------------------
  // Monthly Payment Analysis
  //--------------------------------------
  if($state_pricing['escalator'] && $state_pricing['rate'] ) {
    $ppa_raw = _genability_get_savings_ppa($account_id, $profile_id, $state_pricing);
    $savings['monthly'] = _genability_process_ppa_analysis($ppa_raw);

    $raw_genability_results['ppa'] = $ppa_raw;
  }

  //--------------------------------------
  // Cash Payment Analysis
  //--------------------------------------
  if($state_pricing['cash_cost']) {
    $r = (isset($ppa_raw)) ? $ppa_raw : _genability_get_savings_own_vanilla($account_id, $profile_id);
    
    $cash_upfront = _genability_math_upfront($r->seriesCosts, $state_pricing['cash_cost']);

    $fixed_price = (($cash_upfront * 0.7) / PROJECT_DURATION) / 12;
    $cash_raw = _genability_get_savings_own($account_id, $profile_id, $fixed_price);
    $savings['buy'] = _genability_process_own_analysis($cash_raw, $state_pricing['cash_cost']);

    $raw_genability_results['cash'] = $cash_raw;
  }

  //--------------------------------------
  // Loan Payment Analysis
  //--------------------------------------
  if($state_pricing['loan_cost'] && isset($cash_raw)) {
    // Loan Payment analysis requires information from the results of the cash analysis
    // in order to calculate and analyze the loan amortization correctly
    $monthly_loan_payment = _genability_calculate_loan_payment($cash_raw, $state_pricing['loan_cost']);
    $loan_raw = _genability_get_savings_loan($account_id, $profile_id, $monthly_loan_payment);
    $savings['advantage'] = _genability_process_loan_analysis($loan_raw, $monthly_loan_payment);

    $raw_genability_results['loan'] = $loan_raw;
  }

  //--------------------------------------
  // Prepay Payment Analysis
  //--------------------------------------
  if($state_pricing['prepay_cost'] && isset($cash_raw)) {
    $prepaid_upfront = _genability_math_upfront($cash_raw->seriesCosts, $state_pricing['prepay_cost']);
    // Prepaid is based on 20 years, not to be confused with
    // [PROJECT_DURATION], this is separate.
    // Break upfront cost down into monthly payments over 20 years.
    $fixed_price = ($prepaid_upfront / 20) / 12;
    $prepaid_raw = _genability_get_savings_prepaid($account_id, $profile_id, $fixed_price);
    $savings['prepaid'] = _genability_process_prepaid_analysis($prepaid_raw);
    $savings['prepaid']['upfront_cost'] = $prepaid_upfront;
    
    $raw_genability_results['prepaid'] = $prepaid_raw;
  }

  _genability_get_other_savings($savings, $raw_genability_results);

  return $savings;
}

/**
 * Retrieves a state pricing record rom the  sunrun_calculator_pricing
 * table.
 *
 * @param $lse_id
 * @param $state_abbr
 *
 * @return mixed
 */
function genability_get_state_pricing($state_abbr, $lse_id) {
  if($lse_id != null) {
    // Record with matching LSEID
    $query = "SELECT *
    FROM {sunrun_calculator_pricing} s
    WHERE (s.state = :state)
    AND (s.genability_utility_lseid = :lseid OR s.genability_utility_lseid IS NULL)
    LIMIT 1";

    $result = db_query($query, [':state' => $state_abbr, ':lseid' => $lse_id]);

  } else {
    // Is state supported.  This happens at the very beginning of the request in order
    // to validate that the state the user is looking for is supported.
    $query = "SELECT *
    FROM {sunrun_calculator_pricing} s
    WHERE (s.state = :state)
    LIMIT 1";

    $result = db_query($query, [':state' => $state_abbr]);
  }

  return $result->fetchAssoc();
}

/**
 * Helper method for retrieving savings analysis for PPA.
 *
 * @param $account_id
 * @param $profile_id
 * @param $rate_escalator
 *
 * @return array|null
 */
function _genability_get_savings_ppa($account_id, $profile_id, $rate_escalator) {
  $account = [
    'fromDateTime' => date('Y-m-d'),
    'accountId' => $account_id,
    'useIntelligentBaselining' => TRUE,
    'populateCosts' => TRUE,
    'propertyInputs' => [
      [
        'scenarios' => 'before,after',
        'keyName' => 'profileId',
        'dataValue' => $profile_id,
      ],
      [
        'scenarios' => 'solar,after',
        'keyName' => 'baselineType',
        'dataValue' => 'typicalSolarPv',
      ],
	    [
        'scenarios' => 'before,after,solar',
		    'keyName' => 'projectDuration',
		    'dataValue' => PROJECT_DURATION
	    ],
      [
        'scenarios' => 'before,after',
        'keyName' => 'rateInflation',
        'dataValue' => 3.5,
      ],
      [
        'scenarios' => 'solar',
        'keyName' => 'rateInflation',
        'dataValue' => $rate_escalator['escalator'],
      ],
      [
        'scenarios' => 'after,solar',
        'keyName' => 'solarDegradation',
        'dataValue' => 0.5,
      ],
    ],
    'rateInputs' => [
      [
        'scenarios' => 'solar',
        'chargeType' => 'CONSUMPTION_BASED',
        'rateBands' => [
          [
            'rateAmount' => $rate_escalator['rate'],
          ],
        ],
      ],
    ],
  ];

  $curl = _genability_curl_init();
  $curl->post(_genability_generate_svc_url('accounts/analysis'), json_encode($account));

  if ($curl->error) {
    watchdog('sunrun_calculator',
      'Unable to retrieve Genability savings analysis for account [%account_id]. %error',
      [
        "%account_id" => $account_id,
        '%error' => $curl->errorMessage,
      ]);
    return NULL;
  }

  return $curl->response->results[0];
}

/**
 * Retrieve a savings analysis from Genability for ownership.
 *
 * @param $account_id
 * @param $profile_id
 *
 * @return null/void
 */
function _genability_get_savings_own_vanilla($account_id, $profile_id) {
  $account = [
    'fromDateTime' => date('Y-m-d'),
    'accountId' => $account_id,
    'populateCosts' => TRUE,
    'useIntelligentBaselining' => TRUE,
    'propertyInputs' => [
      [
        'scenarios' => 'before,after',
        'keyName' => 'profileId',
        'dataValue' => $profile_id,
      ],
      [
        'scenarios' => 'before,after,solar',
        'keyName' => 'projectDuration',
        'dataValue' => PROJECT_DURATION
      ],
      [
        'scenarios' => 'before,after',
        'keyName' => 'rateInflation',
        'dataValue' => 3.5,
      ],
      [
        'scenarios' => 'solar',
        'keyName' => 'rateInflation',
        'dataValue' => 0,
      ],
      [
        'scenarios' => 'after,solar',
        'keyName' => 'solarDegradation',
        'dataValue' => 0.5,
      ],
      [
        'scenarios' => 'solar,after',
        'keyName' => 'baselineType',
        'dataValue' => 'typicalSolarPv',
      ],
    ],
    'rateInputs' => [
      [
        'scenarios' => 'solar',
        'chargeType' => 'FIXED_PRICE',
        'rateBands' => [
          [
            'rateAmount' => 0,
          ],
        ],
      ],
    ],
  ];
  
  $curl = _genability_curl_init();
  $curl->post(_genability_generate_svc_url('accounts/analysis'),
    json_encode($account));
  
  if ($curl->error) {
    watchdog('sunrun_calculator',
      'Unable to retrieve Genability savings ownership analysis for account [%account_id]. %error',
      [
        "%account_id" => $account_id,
        '%error' => $curl->errorMessage,
      ]);
    return NULL;
  }
  
  return $curl->response->results[0];
}

/**
 * Retrieve a savings analysis from Genability for ownership.
 *
 * @param $account_id
 * @param $profile_id
 * @param $fixed_price
 *
 * @return null/void
 */
function _genability_get_savings_own($account_id, $profile_id,
  $fixed_price) {
  $account = [
    'fromDateTime' => date('Y-m-d'),
    'accountId' => $account_id,
    'populateCosts' => TRUE,
    'useIntelligentBaselining' => TRUE,
    'propertyInputs' => [
      [
        'scenarios' => 'before,after',
        'keyName' => 'profileId',
        'dataValue' => $profile_id,
      ],
      [
        'scenarios' => 'before,after,solar',
        'keyName' => 'projectDuration',
        'dataValue' => PROJECT_DURATION
      ],
      [
        'scenarios' => 'before,after',
        'keyName' => 'rateInflation',
        'dataValue' => 3.5,
      ],
      [
        'scenarios' => 'solar',
        'keyName' => 'rateInflation',
        'dataValue' => 0,
      ],
      [
        'scenarios' => 'after,solar',
        'keyName' => 'solarDegradation',
        'dataValue' => 0.5,
      ],
      [
        'scenarios' => 'solar,after',
        'keyName' => 'baselineType',
        'dataValue' => 'typicalSolarPv',
      ],
    ],
    'rateInputs' => [
      [
        'scenarios' => 'solar',
        'chargeType' => 'FIXED_PRICE',
        'rateBands' => [
          [
            'rateAmount' => $fixed_price,
          ],
        ],
      ],
    ],
  ];

  $curl = _genability_curl_init();
  $curl->post(_genability_generate_svc_url('accounts/analysis'),
    json_encode($account));

  if ($curl->error) {
    watchdog('sunrun_calculator',
      'Unable to retrieve Genability savings ownership analysis for account [%account_id]. %error',
      [
        "%account_id" => $account_id,
        '%error' => $curl->errorMessage,
      ]);
    return NULL;
  }

  return $curl->response->results[0];
}

/**
 * Retrieve a savings analysis from Genability for loan.
 *
 * @param $account_id
 * @param $profile_id
 * @param $monthly_loan_pmt
 *
 * @return null/void
 */
function _genability_get_savings_loan($account_id, $profile_id, $monthly_loan_pmt) {
  $account = [
    'fromDateTime' => date('Y-m-d'),
    'accountId' => $account_id,
    'populateCosts' => TRUE,
    'useIntelligentBaselining' => TRUE,
    'propertyInputs' => [
      [
        'scenarios' => 'before,after',
        'keyName' => 'profileId',
        'dataValue' => $profile_id,
      ],
      [
        'scenarios' => 'before,after,solar',
        'keyName' => 'projectDuration',
        'dataValue' => PROJECT_DURATION
      ],
      [
        'scenarios' => 'before,after',
        'keyName' => 'rateInflation',
        'dataValue' => 3.5,
      ],
      [
        'scenarios' => 'solar',
        'keyName' => 'rateInflation',
        'dataValue' => 0,
      ],
      [
        'scenarios' => 'after,solar',
        'keyName' => 'solarDegradation',
        'dataValue' => 0.5,
      ],
      [
        'scenarios' => 'solar,after',
        'keyName' => 'baselineType',
        'dataValue' => 'typicalSolarPv',
      ],
    ],
    'rateInputs' => [
      [
        'scenarios' => 'solar',
        'chargeType' => 'FIXED_PRICE',
        'rateBands' => [
          [
            'rateAmount' => $monthly_loan_pmt,
          ],
        ],
      ],
    ],
  ];

  $curl = _genability_curl_init();
  $curl->post(_genability_generate_svc_url('accounts/analysis'),
    json_encode($account));

  if ($curl->error) {
    watchdog('sunrun_calculator',
      'Unable to retrieve Genability savings loan analysis for accountId [%account_id]. %error',
      [
        "%account_id" => $account_id,
        '%error' => $curl->errorMessage,
      ]);
    return NULL;
  }

  return $curl->response->results[0];
}

/**
 * Retrieve a savings analysis from Genability for pre-pay.
 *
 * @param $account_id
 * @param $profile_id
 * @param $fixed_price
 *
 * @return null/void
 */
function _genability_get_savings_prepaid($account_id, $profile_id, $fixed_price) {
  $account = [
    'fromDateTime' => date('Y-m-d'),
    'accountId' => $account_id,
    'populateCosts' => TRUE,
    'useIntelligentBaselining' => TRUE,
    'propertyInputs' => [
      [
        'scenarios' => 'before,after',
        'keyName' => 'profileId',
        'dataValue' => $profile_id,
      ],
      [
        'scenarios' => 'before,after,solar',
        'keyName' => 'projectDuration',
        'dataValue' => PROJECT_DURATION
      ],
      [
        'scenarios' => 'before,after',
        'keyName' => 'rateInflation',
        'dataValue' => 3.5,
      ],
      [
        'scenarios' => 'solar',
        'keyName' => 'rateInflation',
        'dataValue' => 0,
      ],
      [
        'scenarios' => 'after,solar',
        'keyName' => 'solarDegradation',
        'dataValue' => 0.5,
      ],
      [
        'scenarios' => 'solar,after',
        'keyName' => 'baselineType',
        'dataValue' => 'typicalSolarPv',
      ],
    ],
    'rateInputs' => [
      [
        'scenarios' => 'solar',
        'chargeType' => 'FIXED_PRICE',
        'rateBands' => [
          [
            'rateAmount' => $fixed_price,
          ],
        ],
      ],
    ],
  ];
  
  $curl = _genability_curl_init();
  $curl->post(_genability_generate_svc_url('accounts/analysis'),
    json_encode($account));
  
  if ($curl->error) {
    watchdog('sunrun_calculator',
      'Unable to retrieve Genability savings prepay analsis for accountId [%account_id]. %error',
      [
        "%account_id" => $account_id,
        '%error' => $curl->errorMessage,
      ]);
    return NULL;
  }
  
  return $curl->response->results[0];
}

/**
 * Takes an estimated monthly bill for an account and converts it into
 * an estimated kilowatt hours usage.
 *
 * @param $account_id
 * @param $est_monthly_bill
 *
 * @return array|null
 */
function _genability_get_kwh_month($account_id, $est_monthly_bill) {
  $sd = new DateTime('first day of last month');
  $start_date = $sd->format('Y-m-d');

  $ed = new DateTime('last day of last month');
  $end_date = $ed->format('Y-m-d');

  $bill = [
    'accountId' => $account_id,
    'fromDateTime' => $start_date,
    'toDateTime' => $end_date,
    'billingPeriod' => 'true',
    'tariffInputs' => [
      [
        'fromDateTime' => $start_date,
        'toDateTime' => $end_date,
        'keyName' => 'total',
        'dataValue' => $est_monthly_bill,
        'unit' => 'cost',
      ],
      [
        'fromDateTime' => $start_date,
        'toDateTime' => $end_date,
        'keyName' => 'baselineType',
        'dataValue' => 'typicalElectricity',
      ],
    ],
  ];

  $curl = _genability_curl_init();
  $curl->post(_genability_generate_svc_url('calculate'), json_encode($bill));

  if ($curl->error) {
    watchdog('sunrun_calculator',
      'Unable to retrieve calculated bill for accountID [%account_id] and amount [%bill]. %error',
      [
        "%account_id" => $account_id,
        '%bill' => $est_monthly_bill,
        '%error' => $curl->errorMessage,
      ]);
    return NULL;
  }

  return $curl->response->results[0]->summary->kWh;
}

/**
 * Create a profile from the estimated monthly kWh and return the associated
 * profileId.
 *
 * @param $account_id
 * @param $kWh
 *
 * @return String profileId
 */
function _genability_create_profile($account_id, $kWh) {
  $sd = new DateTime('first day of last month');
  $ed = new DateTime('last day of last month');

  $profile = [
    'accountId' => $account_id,
    'isDefault' => TRUE,
    'serviceTypes' => 'ELECTRICITY',
    'sourceId' => 'ReadingEntry',
    'readingData' => [
      [
        'fromDateTime' => $sd->format('Y-m-d'),
        'toDateTime' => $ed->format('Y-m-d'),
        'quantityUnit' => 'kWh',
        'quantityValue' => $kWh,
      ],
    ],
  ];

  $curl = _genability_curl_init();
  $curl->post(_genability_generate_svc_url('profiles'), json_encode($profile));

  if ($curl->error) {
    watchdog('sunrun_calculator',
      'Unable to add profile for accountID [%account_id] and kWh [%kWh]. %error',
      [
        "%account_id" => $account_id,
        '%kWh' => $kWh,
        '%error' => $curl->errorMessage,
      ]);
    return NULL;
  }

  return $curl->response->results[0]->profileId;
}

/**
 * Generates a URL to be used for making service requests to Genability.
 *
 * @param $uri
 *
 * @return string Generated url
 */
function _genability_generate_svc_url($uri) {
  $host = rtrim(variable_get('sunrun_genability_host'), '/');
  $user = variable_get('sunrun_genability_username');
  $password = variable_get('sunrun_genability_password');

  return $host . '/' . $uri . '?appId=' . $user . '&appKey=' . $password;
}

/**
 * Interpret data returned from Genability.
 *
 * @param $analysis
 *
 * @return array
 */
function _genability_process_ppa_analysis($analysis) {
  $results = [
    'upfront_cost' => 0,
    'monthly_pmt' => _genability_math_monthly_pmt($analysis->series),
    'lifetime_savings' => round($analysis->summary->lifetimeAvoidedCost),
  ];

  return $results;
}

/**
 * Interpret data returned from Genability.
 *
 * @param $analysis
 *
 * @return array
 */
function _genability_process_prepaid_analysis($analysis) {
  $results = [
    'monthly_pmt' => 0,
    'lifetime_savings' => round($analysis->summary->lifetimeAvoidedCost),
  ];

  return $results;
}

/**
 * Interpret data returned from Genability for a loan.  Similar to the
 * analysis provided for PPA, except the monthly_pmt includes
 * the loan interest rate as part of the calculation.
 *
 * @param $analysis
 * @param $monthly_loan_pmt
 *
 * @return array
 */
function _genability_process_loan_analysis($analysis, $monthly_loan_pmt) {
  $results = [
    'upfront_cost' => 0,
    'monthly_pmt' => $monthly_loan_pmt,
    'lifetime_savings' => round($analysis->summary->lifetimeAvoidedCost),
  ];

  return $results;
}

/**
 * Interpret data returned from Genability for ownership.
 *
 * @param $analysis
 * @param $price_per_watt
 *
 * @return array
 */
function _genability_process_own_analysis($analysis, $price_per_watt) {
  $results = [
    'upfront_cost' => _genability_math_upfront($analysis->seriesCosts, $price_per_watt),
    'monthly_pmt' => 0,
    'lifetime_savings' => round($analysis->summary->lifetimeAvoidedCost),
  ];
  
  return $results;
}

/**
 * Calculate the # of trees that could be planted in respect to kW saved.
 *
 * @see http://www.earthruns.org/index.php/learn/learn
 *
 * @param $kw_generated
 * @return int
 */
function _genability_math_trees_planted($kw_generated) {
  // Amount of energy created (per year).
  $kW_generated_year = $kw_generated;
  // Average amount of CO2 (in pounds) emitted from electricity generated
  // Sources:
  // https://carbonfund.org/how-we-calculate/
  // https://www.eia.gov/electricity/state/archive/2012/unitedstates/
  $co2_kWh = 1.2;
  $co2_offset_year = $kW_generated_year * $co2_kWh;

  // Rate at which a mature tree absorbs CO2 (in pounds)
  // Source:
  // http://www.americanforests.org/explore-forests/forest-facts/
  $tree_co2_per_year = 48;
  $planted = $co2_offset_year / $tree_co2_per_year;

  return round($planted);
}

/**
 * Calculate upfront cost and the system size.
 *
 * @param $seriesCost
 * @param $costPerW
 *
 * @return float|int|null
 */
function _genability_math_upfront($seriesCost, $costPerW = 3.8) {

  foreach ($seriesCost->{2}->assumptions as $assumption) {
    if ($assumption->keyName === 'systemSize') {
      $system_size = $assumption->dataValue;
      // Round value to nearest thousandth
      return round($costPerW * ($system_size * 1000) / 1000) * 1000;
    }
  }

  return 0;
}

/**
 * Calculate the system size.
 *
 * @param $seriesCosts
 *
 * @return float|int|null
 */
function _genability_math_system_size($seriesCosts) {

  foreach ($seriesCosts->{2}->assumptions as $assumption) {
    if ($assumption->keyName === 'systemSize') {
      return $assumption->dataValue;
    }
  }

  return 0;
}

/**
 * Calculate monthly payment.
 *
 * @param $series
 *
 * @return float|int
 */
function _genability_math_monthly_pmt($series) {
  $after_solar = _genability_get_series($series, 'after', 'month', 12);
  $solar_only = _genability_get_series($series, 'solar', 'month', 12);

  return ($after_solar / 12) + ($solar_only / 12);
}

/**
 * Returns the cost of the series based on the scenario, period, and duration.
 * Genability's documentation stresses that we shouldn't assume the seriesId will
 * be the same for each response, therefore we have to traverse the series each
 * time we need a cost.
 *
 * @see Series  section - http://developer.genability.com/api-reference/savings-api/savings-analysis/
 * @param $series
 * @param $scenario
 * @param $period
 * @param $duration
 *
 * @return mixed
 */
function _genability_get_series($series, $scenario, $period, $duration) {
  foreach($series as $s) {
    if(strtolower($s->scenario) == strtolower($scenario)
          && strtolower($s->seriesPeriod) == strtolower($period)
          && $s->seriesDuration == $duration) {
      return $s->cost;
    }
  }

  return 0; // should never be the case
}

/**
 * Retrieve the amount of a loan payment based on Amortization and a 5.99% interest.
 *
 * @param $analysis
 * @param $price_per_watt
 *
 * @return float|int|null
 */
function _genability_calculate_loan_payment($analysis, $price_per_watt) {
  $interest_per_period = (5.99 / 12)  / 100;
  $loan_amount = _genability_math_upfront($analysis->seriesCosts, $price_per_watt) * 0.7;
  $num_months = PROJECT_DURATION * 12;

  // Amortization Formula
  // @see https://math.stackexchange.com/questions/664029/whats-the-math-formula-that-is-used-to-calculate-the-monthly-payment-in-this-mo
  $amortization_top = $interest_per_period * pow(  1 + $interest_per_period, $num_months);
  $amortization_bottom = pow(1 + $interest_per_period, $num_months) - 1;
  $amortization = $loan_amount * ($amortization_top / $amortization_bottom);

  return $amortization;
}

/**
 * @param $savings
 */
function _genability_get_other_savings(&$savings, $raw_data) {
  foreach($raw_data as $raw) {
      $savings['electricity_cost_lifetime'] = $raw->summary->lifetimeWithoutCost;
      $savings['trees_planted'] = _genability_math_trees_planted($raw->summary->netAvoidedKWh);
      $savings['system_size'] = floatval(_genability_math_system_size($raw->seriesCosts));
      // @see http://news.energysage.com/home-solar-power-increase-property-values-across-us/
      // Home appreciation increases at $4 per watt.
      $savings['home_appreciation'] = ($savings['system_size'] * 1000) * 4;
  }
}
