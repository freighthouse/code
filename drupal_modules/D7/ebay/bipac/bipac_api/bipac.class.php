<?php

/**
 * @file
 *   This is the core BIPAC API class
 *   Note that it handles API access but is agnostic when it comes
 *   to the data itself.  The module should handle this.
 */

class Bipac {

  public $operation = NULL;
  public $test = NULL;

  protected $endpoint = NULL;
  protected $apikey = NULL;
  protected $group = NULL;

  private $operations = array();

  /** These are used for storage **/
  public $address_1;
  public $address_2;
  public $city;
  public $state;
  public $zip;
  public $lat;
  public $lon;
  public $email;
  public $phone;
  public $first_name;
  public $last_name;
  public $middle_name;
  public $prefix;
  public $suffix;

  /**
   * Send the ID when initializing this object
   */
  function __construct($apikey, $group, $publisher, $test = FALSE) {
    $this->apikey = $apikey;
    $this->g = $group;
    $this->test = $test;
  }

  /**
   * These are our consumer functions.
   * Primarly the only thing they do is manage
   * endpoint requirements for the communication functions.
   */

  /**
   * Test Key
   * @note
   *   All methods follow this function.  See comments
   *   for more information.
   */
  public function TestAPIKey() {
    /**
     * $this->operation is the BIPAC method name.
     * @see
     *   load_operations method for details
     */
    $this->operation = 'TestAPIKey';

    /**
     * One dimensional requirements array
     * Should match $data keys
     */
    $requirements = array();

    /**
     * Array of data to be passed to BIPAC.
     * Follows $key => $value structure.
     * Note that keys should match args for BIPAC endpoints.
     */
    $data = array();

    /**
     * This checks requirements array vs. data array
     * and also loads any additional args into the array
     * that BIPAC requires (such as the API key).
     * It returns the URL endpoint if successful.
     */
    $endpoint = $this->check_requirements($requirements, $data);

    return $this->query($endpoint, $data);
  }

  /**
   * Campaign List Alerts
   * @args
   *   p = publisher (optional)
   */
  public function CampaignListAlerts($p = NULL) {
    $this->operation = 'CampaignListAlerts';
    $requirements = array();
    $data = array();
    if ($p != NULL) {
      $data['p'] = $p;
    }
    $endpoint = $this->check_requirements($requirements, $data);
    return $this->query($endpoint, $data);
  }

  /**
   * Campaign List Alerts
   */
  public function CampaignListLetterContent($GroupName = NULL, $ContentName, $ContentType = NULL) {
    $this->operation = 'CampaignListLetterContent';
    $requirements = array('ContentName');
    $data['GroupName'] = !empty($GroupName) ? $GroupName : $this->g;
    $data['ContentName'] = $ContentName;
    $data['ContentType'] = !empty($ContentType) ? $ContentType : NULL;
    $endpoint = $this->check_requirements($requirements, $data);
    return $this->query($endpoint, $data);
  }

  /**
   * Campaign Post Letter
   * @note
   *   $ID determines which campaign we're going against.
   *     If 0, this will not be associated with a campaign.
   *   $leg_id_num will send a letter only to this legislator.
   *     Note that BIPAC can create sets of legislators for a
   *     given $ID, but we will need to communicate with them
   *     for that functionality.
   */
  public function CampaignPostLetter($GroupName = NULL,
                                     $ID = '0',
                                     $ContentType = NULL,
                                     $leg_id_num = NULL,
                                     $writer_prefix = NULL,
                                     $writer_first_name,
                                     $writer_middle_name = NULL,
                                     $writer_suffix = NULL,
                                     $writer_last_name,
                                     $writer_email,
                                     $writer_address_1,
                                     $writer_address_2 = NULL,
                                     $writer_city,
                                     $writer_state,
                                     $writer_zip,
                                     $writer_phone = NULL,
                                     $subject,
                                     $message,
                                     $topic) {
    $this->operation = 'CampaignPostLetter';
    $requirements = array('writer_first_name',
                          'writer_last_name',
                          'writer_email',
                          'writer_address_1',
                          'writer_city',
                          'writer_state',
                          'writer_zip',
                          'subject',
                          'topic',
                          'message');
    $data['GroupName'] = !empty($GroupName) ? $GroupName : $this->g;
    $data['ID'] = $ID;
    $data['ContentType'] = $ContentType;
    $data['leg_id_num'] = $leg_id_num;
    $data['writer_prefix'] = $writer_prefix;
    $data['writer_first_name'] = $writer_first_name;
    $data['writer_middle_name'] = $writer_middle_name;
    $data['writer_last_name'] = $writer_last_name;
    $data['writer_email'] = $writer_email;
    $data['writer_address_1'] = $writer_address_1;
    $data['writer_address_2'] = $writer_address_2;
    $data['writer_city'] = $writer_city;
    $data['writer_state'] = $writer_state;
    $data['writer_zip'] = $writer_zip;
    $data['writer_phone'] = $writer_phone;
    $data['subject'] = $subject;
    $data['message'] = $message;
    $data['topic'] = $topic;
    $endpoint = $this->check_requirements($requirements, $data);
    return $this->query($endpoint, $data);
  }

  /**
   * From Address List Legislators
   *
   * @note
   *   This method seems to allow for a multiple states search, but address, city, and zip
   *   are marked as required, so I'm not sure how that would work.
   *
   *   $RestrictStates		An optional array of two letter staps, caps
   *   $RestrictTypes		An optional array of numerical codes (see below)
   *   				0 - U.S. Senators
   * 				1 - U.S. Reps
   *				2 - State Senators
   *				3 - State House
   *				7 - Governors
   * 				8 - Lt. Governors
   * 				9 - Attorneys General
   * 				10 - Secretaries of State
   */
  public function FromAddressListLegislators($address_1, $address_2 = NULL, $city, $state, $zip, $RestrictStates = NULL, $RestrictTypes = NULL) {
    $this->operation = 'FromAddressListLegislators';
    $requirements = array('address_1', 'city', 'state', 'zip');
    $data['address_1'] = $address_1;
    $data['address_2'] = $address_2;
    $data['city'] = $city;
    $data['state'] = $state;
    $data['zip'] = $zip;
    $data['RestrictStates'] = !empty($RestrictStates) ? $RestrictStates : NULL;
    $data['RestrictTypes'] = !empty($RestrictTypes) ? $RestrictTypes : '0,1,2,3,7';
    $endpoint = $this->check_requirements($requirements, $data);
    return $this->query($endpoint, $data);
  }

  /**
   * From State List Legislators
   */
  public function FromStateListLegislators($state) {
    $this->operation = 'FromStateListLegislators';
    $requirements = array('state');
    $data['state'] = $state;
    $endpoint = $this->check_requirements($requirements, $data);
    return $this->query($endpoint, $data);
  }

  /**
   * From Lat/Lon List Legislators
   */
  public function FromLatLonListLegislators($lat, $lon) {
    $this->operation = 'FromLatLonListLegislators';
    $requirements = array('lat', 'lon');
    $data['lat'] = $lat;
    $data['lon'] = $lon;
    $endpoint = $this->check_requirements($requirements, $data);
    return $this->query($endpoint, $data);
  }

  /**
   * From ID List Legislators
   */
  public function FromIDListLegislators($leg_id_num) {
    $this->operation = 'FromIDListLegislators';
    $requirements = array('leg_id_num');
    $data['leg_id_num'] = $leg_id_num;
    $endpoint = $this->check_requirements($requirements, $data);
    return $this->query($endpoint, $data);
  }

  /**
   * From ID Get Bio
   */
  public function FromIDGetBio($leg_id_num) {
    $this->operation = 'FromIDGetBio';
    $requirements = array('leg_id_num');
    $data['leg_id_num'] = $leg_id_num;
    $endpoint = $this->check_requirements($requirements, $data);
    return $this->query($endpoint, $data);
  }

  /**
   * Get Vote Record
   */
  public function GetVoteRecord($leg_id_num, $p = NULL) {
    $this->operation = 'GetVoteRecord';
    $requirements = array('leg_id_name');
    $data['leg_id_num'] = $leg_id_num;
    $data['p'] = !empty($p) ? $p : NULL;
    $endpoint = $this->check_requirements($requirements, $data);
    return $this->query($endpoint, $data);
  }

  /**
   * Get Vote Scores
   */
  public function GetVoteScores($leg_id_num) {
    $this->operation = 'GetVoteScores';
    $requirements = array('leg_id_name');
    $data['leg_id_num'] = $leg_id_num;
    $data['p'] = !empty($p) ? $p : NULL;
    $endpoint = $this->check_requirements($requirements, $data);
    return $this->query($endpoint, $data);
  }

  /**
   * Go To Vote
   */
  public function FromZIPListGOTV($zip) {
    $this->operation = 'FromZIPListGOTV';
    $requirements = array('zip');
    $data['zip'] = $zip;
    $endpoint = $this->check_requirements($requirements, $data);
    return $this->query($endpoint, $data);
  }

  /**
   * Get Election Dates
   */
  public function FromZIPListElections($zip) {
    $this->operation = 'FromZIPListElections';
    $requirements = array('zip');
    $data['zip'] = $zip;
    $endpoint = $this->check_requirements($requirements, $data);
    return $this->query($endpoint, $data);
  }

  /** Reporting Endpoints **/

  /**
   * Get number of voter registration forms downloaded for all
   * P2 site users for the current campaign period
   */
  public function RegistrationDownloads() {
    $this->operation = 'RegistrationDownloads';
    $requirements = array();
    $data = array();
    $endpoint = $this->check_requirements($requirements, $data);	// Always do this even if no field requirements
    return $this->query($endpoint, $data);
  }

  /** Admin Endpoints **/

  /**
   * Placeholder method for requesting an API key
   */
  public function RequestKey ($email) {
    $this->operation = '';
  }
  /**
   * Manage query
   *
   * @return
   *   boolean	on success/failure
   * @note
   *   On success, results will be loaded in $this->$operation_data
   *   On fail, dump will be saved in $this->dump
   */
  protected function query($endpoint, $data) {
    $key = $this->operation . '_data';
    if ((!empty($endpoint)) && ($results = $this->run_query($endpoint, $data))) {
      $this->$key = $results;
      return TRUE;
    }
    else {
      // run_query will dump failed return into $this->dump
      return FALSE;
    }
  }

  /**
   * Actually perform the query
   *
   * @return
   *   $json	a json array
   * @note
   *   This uses a Drupal function (drupal_http_request)
   *   If using outside of Drupal, it will need to be rewritten
   *   with something more universal, like curl
   */
  protected function run_query($endpoint, $data) {
    $options = array();
    $options['method'] = 'POST';
    $options['data'] = http_build_query($data, '', '&');	// include & to prevent &amp; encoding, which breaks asp
    $options['timeout'] = 15;
    $options['headers'] = array('Content-Type' => 'application/x-www-form-urlencoded');
    if (($result = drupal_http_request($endpoint, $options)) &&
        (!empty($result->code)) &&
        ($result->code == '200') &&
        (empty($result->error)) &&
        (!empty($result->data)) &&
        ($json = json_decode($result->data, TRUE))) {
      return $json;
    }
    else {
      $this->dump = $result;
      $error = serialize($result);
      $alert = !empty($result->error) ? serialize($result->error) : NULL;
      watchdog('bipac_api', t('Error: %code %alert %error'), array('%error' => $error, '%code' => $result->code, '%alert' => $alert));
      return FALSE;
    }
  }

  /**
   * Check requirements
   * Return API key if all checks out
   * @args
   *   $requirements	an flat array of required fields
   *   $data		a multidimensional array of $field => $value
   * @note
   *   The field name in $requirements should match the key for $data
   */
  private function check_requirements($requirements, &$data) {
    $errors = array();
    if (empty($this->g)) {
      $errors[] = 'Group cannot be NULL';
    }
    else {
      $data['g'] = $this->g;
    }
    if (empty($this->apikey)) {
      $errors[] = 'Key cannot be NULL';
    }
    else {
      $data['apikey'] = $this->apikey;
    }
    if (empty($this->operation)) {
      $errors[] = 'You must choose an operation';
    }
    foreach ($requirements as $requirement) {
      if (empty($data[$requirement])) {
        $errors[] = $data[$requirement] . ' is required for this operation';
      }
    }
    if (empty($errors)) {
      return $this->load_operations($this->operation);
    }
    else {
      $this->errors = $errors;
      return FALSE;
    }
  }

  /**
   * Load operations with endpoints
   * This will return a specific endpoint if requested
   */
  private function load_operations($operation = NULL) {
    $operations = array();

    /** Consumer APIs **/
    $operations['TestAPIKey'] = 'http://bipac.net/modules/JSON/TestAPIKey.asp';
    $operations['CampaignListAlerts'] = 'http://bipac.net/modules/JSON/CampaignListAlerts.asp';
    $operations['CampaignListLetterContent'] = 'http://bipac.net/modules/JSON/CampaignListLetterContent.asp';
    $operations['CampaignPostLetter'] = 'http://bipac.net/modules/JSON/CampaignPostLetter.asp';
    $operations['FromAddressListLegislators'] = 'http://bipac.net/modules/JSON/FromAddressListLegislators.asp';
    $operations['FromStateListLegislators'] = 'http://bipac.net/modules/JSON/FromStateListLegislators.asp';
    $operations['FromLatLonListLegislators'] = 'http://bipac.net/modules/JSON/FromLatLonListLegislators.asp';
    $operations['FromIDListLegislators'] = 'http://bipac.net/modules/JSON/FromIDListLegislators.asp';
    $operations['FromIDGetBio'] = 'http://bipac.net/modules/JSON/FromIDGetBio.asp';
    $operations['GetVoteRecord'] = 'http://bipac.net/modules/JSON/GetVoteRecord.asp';
    $operations['GetVoteScores'] = 'http://bipac.net/modules/JSON/GetVoteScores.asp';
    $operations['FromZIPListElections'] = 'http://bipac.net/modules/JSON/FromZIPListElections.asp';
    $operations['FromZIPListGOTV'] = 'http://bipac.net/modules/JSON/FromZIPListGOTV.asp';
    $operations['ListAvailablePages'] = 'http://bipac.net/modules/JSON/ListAvailablePages.asp';
    $operations['GetPageContent'] = 'http://bipac.net/modules/JSON/GetPageContent.asp';

    /** Reporting APIs **/
    $operations['RegistrationDownloads'] = 'http://bipac.net/modules/JSON/RegistrationDownloads.asp';

    if (empty($this->operations)) {
      $this->operations = $operations;
    }
    if ((!empty($operation)) && (!empty($operations[$operation]))) {
      return $operations[$operation];		// Return endpoint
    }
  }

  /**
   * List operations
   */
  public function list_operations() {
    $this->load_operations();
    return array_keys($this->operations);
  }
}

?>
