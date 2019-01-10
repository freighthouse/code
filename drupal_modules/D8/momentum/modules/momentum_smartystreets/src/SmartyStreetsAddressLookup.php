<?php

/**
 * @file
 * Contains Drupal\smartystreets\SmartyStreetsAddressLookup.
 */

namespace Drupal\smartystreets;

use Drupal\Component\Utility\Crypt;

/**
 * Class for verifying postal addresses via the SmartyStreets API.
 */
class SmartyStreetsAddressLookup {

  /**
   * Object containing the SmartyStreets configuration.
   *
   * @var object
   */
  private $config;

  /**
   * SmartyStreets Auth ID.
   *
   * @var string
   */
  private $authId;

  /**
   * SmartyStreets Auth Token.
   *
   * @var string
   */
  private $authToken;

  /**
   * Constructs a SmartyStreetsAddressLookup object.
   *
   * @var object $config
   *   The config settings for this module.
   * @var string $authId
   *   SmartyStreets Secret Auth ID.
   * @var string $authToken
   *   SmartyStreets Secret Auth Token.
   */
  public function __construct() {
    $config = \Drupal::config('smartystreets.settings');
    $auth_id = $config->get('auth_id');
    $auth_token = $config->get('auth_token');
    $this->config = $config;
    $this->authId = $auth_id;
    $this->authToken = $auth_token;
  }

  /**
   * Lookup a U.S. street address via the SmartyStreets API.
   *
   * @param string $location
   *   Comma-delimited string typically containing street, city, state and zip.
   *
   * @return array
   *   Decoded JSON returned by SmartyStreets.
   */
  public function USStreetAddress($location) {
    $client = \Drupal::httpClient();
    $config = $this->config;
    $response = FALSE;

    $url_hostname = $config->get('hostname_us_street_address');

    $url_template = 'https://%s/street-address?auth-id=%s&auth-token=%s&street=%s';

    // Add values to the URL template and build the URL.
    $url = sprintf($url_template, $url_hostname, $this->authId, $this->authToken, urlencode($location));

    try {
      // Send the address to SmartyStreets for verification.
      $request = $client->get($url);
      // Decode the JSON response.
      $response = json_decode($request->getBody());
    }
    catch (RequestException $e) {
      \Drupal::logger('smartystreets')->error($e->getMessage());
    }

    return $response;
  }

  /**
   * Lookup a U.S. city, state and zip combo via the SmartyStreets API.
   *
   * @param string $city
   *   U.S. city.
   * @param string $state
   *   U.S. state.
   * @param string $zipcode
   *   U.S. zip code.
   *
   * @return array
   *   Decoded JSON returned by SmartyStreets.
   */
  public function USZipCode($city, $state, $zipcode) {
    $client = \Drupal::httpClient();
    $config = $this->config;
    $response = FALSE;

    $url_hostname = $config->get('hostname_us_zip_code');

    $url_template = 'https://%s/lookup?auth-id=%s&auth-token=%s&city=%s&state=%s&zipcode=%s';

    // Add values to the URL template and build the URL.
    $url = sprintf($url_template, $url_hostname, $this->authId, $this->authToken, urlencode($city), urlencode($state), urlencode($zipcode));

    try {
      // Send the city, state and zip to SmartyStreets for verification.
      $request = $client->get($url);
      // Decode the JSON response.
      $response = json_decode($request->getBody());
    }
    catch (RequestException $e) {
      \Drupal::logger('smartystreets')->error($e->getMessage());
    }

    return $response;
  }

  /**
   * Lookup suggestions for an incomplete address via the SmartyStreets API.
   *
   * @param string $prefix
   *   The part of the address that has already been typed.
   * @return array
   *   Decoded JSON returned by SmartyStreets.
   */
  public function USAutocomplete($prefix) {
    $client = \Drupal::httpClient();
    $config = $this->config;
    $response = FALSE;

    $url_hostname = $config->get('hostname_us_autocomplete');

    $url_template = 'https://%s/suggest?auth-id=%s&auth-token=%s&prefix=%s';

    // Add values to the URL template and build the URL.
    $url = sprintf($url_template, $url_hostname, $this->authId, $this->authToken, urlencode($prefix));

    try {
      // Send the address to SmartyStreets for verification.
      $request = $client->get($url);
      // Decode the JSON response.
      $response = json_decode($request->getBody());
    }
    catch (RequestException $e) {
      \Drupal::logger('smartystreets')->error($e->getMessage());
    }

    return $response;
  }

  /**
   * Generates a base-64 encoded sha-256 hash from the SmartyStreets results.
   *
   * If you are validating full addresses (via USStreetAddress) and
   * then storing them, this hash serves as a unique lookup key,
   * preventing duplicate addresses from being stored in the database.
   *
   * @param array $results
   *   An array containing the 'components' object (via USStreetAddress)
   *
   * @return string
   *   A base-64 encoded sha-256 checksum, built from the 'components' object.
   */
  public function generateHash($results) {
    if (!empty($results[0]->components)) {
      $obj = $results[0]->components;
      $string = sprintf("%s_%s_%s_%s_%s_%s_%s_%s_%s", $obj->primary_number, $obj->street_name, $obj->street_suffix, $obj->city_name, $obj->state_abbreviation, $obj->zipcode, $obj->plus4_code, $obj->delivery_point, $obj->delivery_point_check_digit);
      return Crypt::hashBase64($string);
    }
  }

}
