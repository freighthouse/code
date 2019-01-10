<?php

namespace IterableApi;
/**
 * @file
 *   This is a class solely for making CURL Requests
 */

class Request {

  /** @var Response details about the result of the last request */
  private $response;

  /**
   * Make GET requests to the API.
   *
   * @param string $path
   * @param array  $parameters
   *
   * @return array|object
   */
  public function get($path, array $parameters = array()){
    return $this->request('GET', $path, $parameters);
  }

  /**
   * Make POST requests to the API.
   *
   * @param string $path
   * @param array  $parameters
   *
   * @return array|object
   */
  public function post($path, \stdClass $parameters = null) {
    return $this->request('POST', $path, $parameters);
  }

  /**
   * Make HTTP Requests to API
   *
   * @param string $method
   * @param string $url
   * @param string $payload
   *
   * @return array|object
   */
  private function request($method, $url, $payload){

    /* Curl Settings */
    $options = array(
      // CURLOPT_CONNECTTIMEOUT => $this->connectionTimeout,
      CURLOPT_HEADER => true,
      CURLOPT_HTTPHEADER => array('Accept: application/json'),
      CURLOPT_RETURNTRANSFER => true,
      CURLOPT_URL => $url,
      CURLOPT_ENCODING => 'gzip',
    );

    switch ($method) {
      case 'GET':
        break;
      case 'POST':
        $payload = json_encode($payload);
        $options[CURLOPT_POST] = true;
        $options[CURLOPT_POSTFIELDS] = $payload;
      break;
      case 'DELETE':
        $options[CURLOPT_CUSTOMREQUEST] = 'DELETE';
      break;
      case 'PUT':
        $options[CURLOPT_CUSTOMREQUEST] = 'PUT';
      break;
    }

    $curl = curl_init();
    curl_setopt_array($curl, $options);
    $response = curl_exec($curl);

    if(curl_errno($curl) > 0){
      var_dump(curl_error($curl));
    }

    // Create Response object
    $this->response = new Response();
    // Set HTTP Code parameter of response object
    $this->response->setHttpCode(curl_getinfo($curl, CURLINFO_HTTP_CODE));
    // Retrieve HTTP Code
    $httpCode = $this->response->getHttpCode();
    // Break apart API Response
    $parts = explode("\r\n\r\n", $response);
    // Pop first part of Response Array into body
    $responseBody = array_pop($parts);
    // Convert string to JSON Response
    $responseBody = json_decode($responseBody);
    // Insert HTTP Code into Response Object
    $responseBody->httpCode = $httpCode;


    curl_close($curl);

    return $responseBody;
  }

}

?>
