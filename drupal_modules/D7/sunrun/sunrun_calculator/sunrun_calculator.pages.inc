<?php
/**
 * @file
 *  Sunrun Calculator pages.
 */

define('DEFAULT_API_ERROR', 'Sorry, we\'re unable to process your request at this time.');
define('CACHE_KEY_PREFIX', 'sunrun:savings_calculator:');

/**
 * Callback/Ajax Handler for savings
 */
function sunrun_calculator_get_analysis() {
  module_load_include('inc', 'sunrun_calculator',
    'resources/sunrun_calculator.zillow');
  module_load_include('inc', 'sunrun_calculator',
    'resources/sunrun_calculator.genability');

  drupal_json_output();

  $inputs = drupal_json_decode(file_get_contents('php://input'));
  $requirements = ['street_address', 'zipcode', 'est_monthly_bill', 'state'];

  if (_sunrun_calculator_validate_request($inputs, $requirements) && _sunrun_calculator_validate_state_support($inputs['state'])) {
    $address = $inputs['street_address'];
    $state = $inputs['state'];
    $zipcode = $inputs['zipcode'];
    $est_monthly_bill = $inputs['est_monthly_bill'];
  
    $cache_key = CACHE_KEY_PREFIX . 'analysis:' . $zipcode . '_' . $est_monthly_bill;
    
    if($cached = cache_get($cache_key)) {
      $analysis = $cached->data;
    } else {
      $property_size = (int) zillow_get_property_size($address, $zipcode);

      if($property_size == 0) {
        // This should be refactored, so that we aren't exiting in multiple
        // places with the same code. (DRY).
        $message = "Solar savings calculations for this property is currently not available.";
        // TODO: Add watchdog log
        _sunrun_calculator_log(['state' => $state], $message);
        echo drupal_json_encode(_assemble_payload($message, 'error'));
        drupal_exit();
      }

      $analysis = genability_get_savings($address, $state, $zipcode, $est_monthly_bill, $property_size);
      $analysis['property_size'] = $property_size;
      
      if(variable_get('sunrun_calculator_enable_caching', false)) {
        cache_set($cache_key, $analysis);
      }
    }
  
    _sunrun_calculator_respond($inputs, $analysis);
  }

  drupal_exit();
}

/**
 * Callback/Ajax Handler for Finance Estimate
 */
function sunrun_calculator_get_estimate() {
  module_load_include('inc', 'sunrun_calculator',
    'resources/sunrun_calculator.genability');

  drupal_json_output();

  $inputs = drupal_json_decode(file_get_contents('php://input'));
  $requirements = ['account_id', 'state', 'lse_id', 'est_monthly_bill'];

  if (_sunrun_calculator_validate_request($inputs, $requirements)) {
    $account_id = $inputs['account_id'];
    $state = $inputs['state'];
    $lse_id = $inputs['lse_id'];
    $est_monthly_bill = $inputs['est_monthly_bill'];
  
    $cache_key = CACHE_KEY_PREFIX . 'estimate:' . $lse_id . '_' . $est_monthly_bill;
    
    if($cached = cache_get($cache_key)) {
      $estimate = $cached->data;
    } else {
      $estimate = genability_get_finance_estimate($account_id, $lse_id, $state, $est_monthly_bill);
  
      if(variable_get('sunrun_calculator_enable_caching', false)) {
        cache_set($cache_key, $estimate);
      }
    }
  
    _sunrun_calculator_respond($inputs, $estimate);
  }

  drupal_exit();
}

/**
 * Helper method for echoing a json response.
 *
 * @param $inputs
 * @param $response
 */
function _sunrun_calculator_respond($inputs, $response) {
  
  if(variable_get('sunrun_calculator_enable_logging', false)) {
    _sunrun_calculator_log($inputs, $response);
  }
  
  echo drupal_json_encode(_assemble_payload($response));
}

/**
 * Log request and response.
 *
 * @param $request
 * @param $response
 */
function _sunrun_calculator_log($request, $response) {
  if(stripos($_SERVER['DOCUMENT_URI'], 'savings-analysis') !== false) {
    $type = 'analysis';
  } else {
    $type = 'estimate';
  }
  
  // Log Entry
  db_insert('sunrun_calculator_logging')
    ->fields([
      'service_type' => $type,
      'service_request' => serialize($request),
      'service_response' => serialize($response),
      'timestamp' => time()
    ])
    ->execute();
}

/**
 * Determines whether or not a request and it's associated inputs are valid.
 *
 * @param $inputs
 *
 * @return bool true if request is valid, exits otherwise
 */
function _sunrun_calculator_validate_request($inputs, $requirements) {
  _sunrun_calculator_validate_base_request($inputs);

  $valid = FALSE;

  foreach ($requirements as $req) {
    if (!key_exists($req, $inputs)) {
      $msg = 'The following parameters are required: ' . implode(", ", $requirements);
      $msg = rtrim($msg, ",");
      $response = _assemble_payload($msg, 'error');
      $valid = FALSE;
      break;
    }
    else {
      $valid = TRUE;
    }
  }

  if (!$valid) {
    _sunrun_calculator_log($inputs, $response);
    header('HTTP/1.1 405 Bad Request');
    echo drupal_json_encode($response);
    drupal_exit();
  }

  return TRUE;
}

/**
 * Determines whether or not a requested state is supported the savings
 * calculator.
 *
 * @param $state
 *
 * @return bool true if state is supported
 */
function _sunrun_calculator_validate_state_support($state) {
  if (! $s = genability_get_state_pricing($state, null)) {
    header('HTTP/1.1 404 Not Found');
    $message = "Solar savings calculations for {$state} are currently not available.";
    _sunrun_calculator_log(['state' => $state], $message);
    echo drupal_json_encode(_assemble_payload($message, 'error'));
    drupal_exit();
  }

  return $s;
}

/**
 * Base set of validation requirements.
 *
 * @param $inputs
 */
function _sunrun_calculator_validate_base_request($inputs) {
  if ($_SERVER['REQUEST_METHOD'] != 'POST') {
    header('HTTP/1.1 405 Method Not Allowed');
    $msg = 'Unsupported request method. This URL supports the following HTTP request methods: POST';
    $response = _assemble_payload($msg, 'error');
    echo drupal_json_encode($response);
    drupal_exit();
  }
}

/**
 * Helper method for assembling the payload response.
 *
 * @param $output
 * @param string $status
 *
 * @return array
 */
function _assemble_payload($output, $status = 'success') {
  if ($status !== 'success') {
    return [
      'status' => $status,
      'message' => $output,
    ];
  }
  else {
    return ['status' => $status] + $output;
  }
}
