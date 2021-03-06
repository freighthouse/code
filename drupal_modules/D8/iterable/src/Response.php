<?php

namespace IterableApi;

/**
 * The result of the most recent API request.
 *
 */
class Response
{
  /** @var int HTTP status code from the most recent request */
  private $httpCode = 0;
  /** @var array HTTP headers from the most recent request */
  private $headers = array();
  /** @var array|object Response body from the most recent request */
  private $body = array();
  /** @var array HTTP headers from the most recent request that start with X */
  private $xHeaders = array();


  /**
   * @param array|object $body
   */
  public function setBody($body) {
    $this->body = $body;
  }

  /**
   * @return array|object|string
   */
  public function getBody() {
      return $this->body;
  }

  /**
   * @param int $httpCode
   */
  public function setHttpCode($httpCode){
      $this->httpCode = $httpCode;
  }

  /**
   * @return int
   */
  public function getHttpCode(){
    return $this->httpCode;
  }

  /**
   * @param array $headers
   */
  public function setHeaders($headers)
  {
    foreach ($headers as $key => $value) {
      if (substr($key, 0, 1) == 'x') {
        $this->xHeaders[$key] = $value;
      }
    }
    $this->headers = $headers;
  }

  /**
   * @return array
   */
  public function getsHeaders() {
    return $this->headers;
  }

  /**
   * @param array $xHeaders
   */
  public function setXHeaders($xHeaders) {
    $this->xHeaders = $xHeaders;
  }

  /**
   * @return array
   */
  public function getXHeaders() {
    return $this->xHeaders;
  }
}
