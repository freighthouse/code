<?php

/**
 * @file
 *   This is the core BIPAC API class
 *   Note that it handles API access but is agnostic when it comes
 *   to the data itself.  The module should handle this.
 */

class Momentum {

  public $test = NULL;

  protected $endpoint = NULL;
  protected $apikey = NULL;
  protected $group = NULL;

  private $operations = array();

  /**
   * Send the ID when initializing this object.
   */
  function __construct($url, $apikey, $group) {
    $this->group = $group;
    $this->apikey = $apikey;
    $this->url = $url;
  }

  /**
   * Test Key.
   */
  function test() {
    $options = array();
    $options['method'] = 'GET';
    $options['timeout'] = 8;

    $endpoint = 'test';
    return $this->request($endpoint, $options);

  }

  function get_chambers() {
    $options = array();
    $options['method'] = 'GET';
    $options['timeout'] = 8;

    $endpoint = 'letters/chambers';
    return $this->request($endpoint, $options);
  }

  function get_states() {
    $options = array();
    $options['method'] = 'GET';
    $options['timeout'] = 8;

    $endpoint = 'letters/states';
    return $this->request($endpoint, $options);
  }

  /**
   * Submit letters.
   */
  function letters($data, $chambers, $momentum_id, $allow_manual, $test, $save, $states = "") {
    $options = array();
    $options['method'] = 'POST';
    $options['data'] = json_encode($data);
    $options['timeout'] = 120;
    $options['headers'] = array('Content-Type' => 'application/json');

    $query = array();
    $query['chambers'] = $chambers;
    $query['bipac_id'] = $momentum_id;
    $query['allow_manual'] = $allow_manual;
    $query['states'] = $states;
    $query['test'] = $test;
    $query['save'] = $save;
    $query_string = http_build_query($query, '', '&');
    $endpoint = 'letters?' . $query_string;

    return $this->request($endpoint, $options);
  }

  /**
   * Get Issues.
   */
  function issues() {
    $endpoint = 'letters/issues';
    return $this->request($endpoint, array());
  }

  /**
   * Users report.
   */
  function users($momentum_id, $format = NULL, $states = NULL, $us_house = NULL, $state_senate = NULL, $state_house = NULL, $county_name = NULL, $municipal_name = NULL, $count = NULL, $return = NULL, $send_to = NULL) {
    $options = array();
    $options['method'] = 'POST';
    $options['timeout'] = 120;
    $options['headers'] = array('Content-Type' => 'application/json');

    $query = array();
    $query['bipac_id'] = $momentum_id;
    $query['format'] = $format;
    $query['states'] = is_array($states) ? implode(",", $states) : $states;
    $query['us_house'] = $us_house;
    $query['state_senate'] = $state_senate;
    $query['state_house'] = $state_house;
    $query['county_name'] = $county_name;
    $query['municipal_name'] = $municipal_name;
    $query['count'] = $count;
    $query['return'] = $return;

    $query_string = http_build_query($query, '', '&');
    $query_string = $query_string != "" ? "?" . $query_string : "";
    $endpoint = 'reports/users' . $query_string;
    return $this->request($endpoint, $options);
  }

  /**
   * Campaigns report.
   */
  function report_campaigns($momentum_id, $count = NULL, $return = NULL, $format = NULL, $send_to = NULL) {
    $options = array();
    $options['method'] = 'GET';
    $options['timeout'] = 120;

    $query = array();
    $query['format'] = $format;
    $query['bipac_id'] = $momentum_id;
    $query['count'] = $count;
    $query['return'] = $return;

    $query_string = http_build_query($query, '', '&');
    $query_string = $query_string != "" ? "?" . $query_string : "";
    $endpoint = 'reports/campaigns' . $query_string;
    return $this->request($endpoint, $options);
  }

  function report_letters($momentum_id, $count = NULL, $return = NULL, $format = NULL, $send_to = NULL) {
    $options = array();
    $options['method'] = 'GET';
    $options['timeout'] = 120;

    $query = array();
    $query['format'] = $format;
    $query['bipac_id'] = $momentum_id;
    $query['count'] = $count;
    $query['return'] = $return;

    $query_string = http_build_query($query, '', '&');
    $query_string = $query_string != "" ? "?" . $query_string : "";
    $endpoint = 'reports/letters' . $query_string;
    return $this->request($endpoint, $options);
  }

  /**
   * Get Officials list from IDs.
   */
  function vote($state, $zip) {
    $options = array();
    $options['method'] = 'GET';
    $options['timeout'] = 120;

    $query = array();
    $query['state'] = $state;
    $query['zip'] = $zip;

    $query_string = http_build_query($query, '', '&');
    $endpoint = 'vote?' . $query_string;
    return $this->request($endpoint, $options);
  }

  /**
   * Get Officials list from IDs.
   */
  function ids($ids) {
    $options = array();
    $options['method'] = 'GET';
    $options['timeout'] = 8;

    $endpoint = 'officials/' . $ids;
    return $this->request($endpoint, $options);
  }

  /**
   * Get Officials from provided data.
   */
  function officials($data, $chambers = array(), $levels = array()) {
    $options = array();
    $options['method'] = 'GET';
    $options['timeout'] = 120;

    $query = array();
    $query['address_1'] = !empty($data['address_1']) ? $data['address_1'] : NULL;
    $query['city'] = !empty($data['city']) ? $data['city'] : NULL;
    $query['state'] = !empty($data['state']) ? $data['state'] : NULL;
    $query['zip'] = !empty($data['zip']) ? $data['zip'] : NULL;
    $query['latitude'] = !empty($data['latitude']) ? $data['latitude'] : NULL;
    $query['longitude'] = !empty($data['longitude']) ? $data['longitude'] : NULL;
    $query['plus_4'] = !empty($data['plus_4']) ? $data['plus_4'] : NULL;
    $query['chambers'] = implode(',', $chambers);
    $query['data'] = implode(',', $levels);

    $query_string = http_build_query($query, '', '&');
    $endpoint = 'officials?' . $query_string;
    return $this->request($endpoint, $options);
  }

  /**
   * Get candidates from provided .
   */
  function candidates($data, $chambers = array(), $election_year = '2016', $active_only = 'TRUE', $incumbents_only = 'FALSE') {
    $options = array();
    $options['method'] = 'GET';
    $options['timeout'] = 120;

    $query = array();
    $query['election_year'] = $election_year;
    $query['active_only'] = $active_only;
    $query['incumbents_only'] = $incumbents_only;
    $query['address_1'] = !empty($data['address_1']) ? $data['address_1'] : NULL;
    $query['city'] = !empty($data['city']) ? $data['city'] : NULL;
    $query['state'] = !empty($data['state']) ? $data['state'] : NULL;
    $query['zip'] = !empty($data['zip']) ? $data['zip'] : NULL;
    $query['latitude'] = !empty($data['latitude']) ? $data['latitude'] : NULL;
    $query['longitude'] = !empty($data['longitude']) ? $data['longitude'] : NULL;
    $query['plus_4'] = !empty($data['plus_4']) ? $data['plus_4'] : NULL;
    $query['chambers'] = implode(',', $chambers);

    $query_string = http_build_query($query, '', '&');
    $endpoint = 'candidates?' . $query_string;

    return $this->request($endpoint, $options);
  }

  /**
   * Get Candidates list from IDs.
   */
  function candidates_ids($ids) {
    $options = array();
    $options['method'] = 'GET';
    $options['timeout'] = 120;

    $endpoint = 'candidates/' . $ids;
    return $this->request($endpoint, $options);
  }

  /**
   * This is our communications method.
   */
  protected function request($endpoint, $options) {
    $headers['Momentum-API-Group'] = $this->group;
    $headers['Momentum-API-Key'] = $this->apikey;
    $options['headers'] = $headers;
    $url = $this->url . $endpoint;
    $debug = \Drupal::config('momentum_api.settings')->get('momentum_api_debug');
    if ($debug) {
      dsm($url, "Request");
    }
    // @FIXME
// drupal_http_request() has been replaced by the Guzzle HTTP client, which is bundled
// with Drupal core.
//
//
// @see https://www.drupal.org/node/1862446
// @see http://docs.guzzlephp.org/en/latest
// $result = drupal_http_request($url, $options);

    if ((!empty($result)) && (!empty($result->code)) && ($result->code == '200') && (!empty($result->data)) && ($json = json_decode($result->data, TRUE))) {
      return $json;
    }
    else {
      \Drupal::logger('momentum_error')->notice(json_encode($result), array());
      return $result;
    }
  }

}
