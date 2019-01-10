<?php

/**
 * @file
 *  ZILLOW REST service functionality
 */

use Curl\Curl;

/**
 * Initialize the Curl object library.
 *
 * @return \Curl
 */
function _zillow_curl_init()
{
  libraries_load('php-curl-class');

  return new Curl();
}

/**
 * Retrieve the property size of a specific home address.
 *
 * @param $address
 * @param $zip
 *
 * @return int
 */
function zillow_get_property_size($address, $zip)
{
  $service_url = rtrim(variable_get('zillow_api_url'), '/');

  // URL Params
  $params['zws-id'] = variable_get('zillow_api_zwsid');
  $params['address'] = $address;
  $params['citystatezip'] = $zip;

  $url = $service_url . "/GetDeepSearchResults.htm?" . http_build_query
    ($params);

  $curl = _zillow_curl_init();
  $curl->get($url);

  $response = _zillow_xml2array($curl->rawResponse);

  if ($response['message']['code'] != 0) {
    watchdog('sunrun_calculator',
      'Unable to retrieve Zillow profile for address [%address] and zipcode [%zipcode]. %error',
      array("%address" => $address, '%zipcode' => $zip, '%error' =>
    $response['message']['text']));
    return null;
  }

  $sqFt = (isset($response['response']['results']['result']['finishedSqFt'])) ? $response['response']['results']['result']['finishedSqFt'] : 0;

  return $sqFt;
}

/**
 * Convert XML to Array
 *
 * NOTE: CDATA gets removed
 *
 * @param $xml
 *
 * @return mixed
 */
function _zillow_xml2array($initXml)
{
  $xml = simplexml_load_string($initXml, 'SimpleXMLElement', LIBXML_NOCDATA);
  return json_decode(json_encode((array)$xml), true);
}
