<?php

/**
 * @file
 *   This class handles most Smartystreets interactions
 */

class Smartystreets
{

  protected $key;	// Smartystreets key
  protected $id;	// Smartystreets ID
  protected $data;	// The data array we'll pass to SStreets

  function __construct($key, $id) {
    $this->key = $key;
    $this->id = $id;
    $this->data['auth-token'] = $key;
    $this->data['auth-id'] = $id;
  }

  /**
   * Takes a zip
   * @returns
   *   array	'city', 'state'
   *   or FALSE if failure
   */
  function city_state_from_zip($zip) {
    $json = $this->standard_zip($zip);

    // Here we only care about city_states
    if (empty($json[0]['city_states'])) {
      return FALSE;
    }

    foreach ($json[0]['city_states'] as $item) {
      if ((!empty($item['city'])) && (!empty($item['state_abbreviation']))) {
        return array('city' => $item['city'], 'state' => $item['state_abbreviation']);
      }
    }
    return FALSE;
  }

  /**
   * Same as above but for lat / long
   */
  function lat_lon_from_zip($zip) {
    $json = $this->standard_zip($zip);
    // Here we only care about zipcodes
    if (empty($json[0]['zipcodes'])) {
      return FALSE;
    }
    
    foreach ($json[0]['zipcodes'] as $item) {
      if ((!empty($item['latitude'])) && (!empty($item['longitude']))) {
        return array('lat' => $item['latitude'], 'lon' => $item['longitude'],'zip'=>$item['zipcode']);
      }
    }
    return FALSE;
  }

  /**
   * Arbitrary address for lat / long
   */
  function lat_lon_from_address($address) {
    $json = $this->full_address($address);
    // Here we only care about zipcodes
    if (empty($json[0]['metadata'])) {
      return FALSE;
    }

    $metadata = $json[0]['metadata'];

    if ((!empty($metadata['longitude'])) && (!empty($metadata['latitude']))) {
      return array('lat' => $metadata['latitude'], 'lon' => $metadata['longitude']);
    }
    return FALSE;
  }

  /**
   * Standard, reusable, address-based search
   */
  function full_address($address) {
    $this->data['street'] = $address;
    $endpoint = '/street-address';
    return $this->request($endpoint, $this->data);
  }

  /**
   * Standard, reusable zipcode-based search
   */
  private function standard_zip($zip) {
    $this->data['zipcode'] = $zip;
    $endpoint = '/zipcode';
    return $this->request($endpoint, $this->data);
  }

  /**
   * Needs an endpoint (e.g., /street-address)
   * and a data array (e.g., array('zip' => 21211)
   * @return
   *   array	decoded JSON
   *   FALSE	if failure
   */
  private function request($endpoint, $data) {
    $url = 'https://api.smartystreets.com' . $endpoint;
    $request = url($url, array('query' => $data));
    $result = drupal_http_request($request);
    if ((!empty($result->data)) && ($json = json_decode($result->data, TRUE))) {
      return $json;
    }
    return FALSE;
  }
}

?>
