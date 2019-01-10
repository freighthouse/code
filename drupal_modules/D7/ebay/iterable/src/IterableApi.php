<?php

namespace IterableApi;
/**
 * @file
 *   This is the core Iterable API class
 *   Provides payload structure for api calls to Iterable
 */

class IterableApi extends Request{

  const API_ENDPOINT = 'https://api.iterable.com/api/';

  /** @var string Iterable API key for the project that data is being inserted to */
  private $iterableApiKey;
  /** @var string Iterable List Id that will be used for inserting data */
  private $iterableListId;

  /**
   * Constructor
   *
   * @param string        $apiKey             The API key for the project
   * @param string|null   $listId (optional)  The List ID of where to insert data
   */
  public function __construct($apiKey, $listId = ''){
    $this->iterableApiKey = $apiKey;
    $this->iterableListId = $listId;
  }

  /**
   * Make an API call to get User Fields from Database
   *
   */
  public function usersGetFields(){
    $url = $this->buildUrl('users/getFields');
    $request = new Request();
    $response = $request->get($url);
    return $response;
  }

  public function listSubscribe($postData){
    $payload = new \stdClass();
    $payload->listId = (int)$this->iterableListId;
    $payload->subscribers = array();

    if(empty($postData['email'])){
      echo 'email field is required';
    }
    else{
      $postDataAsObject = (object)$postData;
      // Remove email and submit items from payload
      unset($postDataAsObject->email);
      unset($postDataAsObject->submit);

      // Create new object for subscriber data
      $subData = new \stdClass();
      $subData->email = $postData['email'];
      $subData->dataFields = $postDataAsObject;

      $payload->subscribers[] = $subData;

      $request = new Request();
      $url = $this->buildUrl('lists/subscribe');

      $response = $request->post($url, $payload);

      return $response;
    }
  }

  public function trackUser($data, $eventName = ''){
    $payload = new \stdClass();

    if(empty($data['email'])){
      echo 'email field is required';
    }
    else{
      // Convert data to object for Iterable
      $postDataAsObject = (object)$data;

      // Create new dataFields object
      $dataFields = new \stdClass();

      // Add email to payload, SHOULD THIS COME FROM COOKIE OR ENTERED DATA
      /**
       * Add eventName to payload
       * Add createdAt timestamp
       * Add datafields as object containing postObject $subData->dataFields = $postDataAsObject;
       * Get campaign ID from cookies
       * Get template ID from cookies
       */
      $payload->email = ( isset($_COOKIE['iterableEndUserId']) ) ? $_COOKIE['iterableEndUserId'] : $data['email'];
      $payload->eventName = $eventName;
      $payload->createdAt = time();
      $payload->dataFields = $postDataAsObject;

      if(isset($_COOKIE['iterableEmailCampaignId'])) $payload->campaignId = (int)$_COOKIE['iterableEmailCampaignId'];
      if(isset($_COOKIE['iterableTemplateId'])) $payload->templateId = (int)$_COOKIE['iterableTemplateId'];


      $request = new Request();
      $url = $this->buildUrl('events/track');

      $response = $request->post($url, $payload);

      return $response;
    }

  }

  /**
   * userLookup
   *
   * @param string    $email              The email of the user to lookup in the Iterable project
   *
   * @return object   $response           The response object from the Iterable API
   */
  public function userLookup($email){
    $request = new Request();

    $url = $this->buildUrl('users', $email);
    $response = $request->get($url);

    return $response;
  }

  public function updateUser($data){
    $payload = new \stdClass();

    // Convert data array to object
    $dataFields = (object)$data;

    $payload->email = $dataFields->email;
    unset($dataFields->email);
    $payload->dataFields = $dataFields;

    $url = $this->buildUrl('users/update');

    $request = new Request();

    $response = $request->post($url, $payload);

    return $response;
  }

  public function unsubscribeUserFromChannels($email){
    $payload = new \stdClass();

    // Hardcoded channel IDs from the Ebay iterable project
    //  TODO: Make not hardcoded
    $channelIds = array(
      10478,10477,10088,10087,10086
    );

    $payload->email = $email;
    $payload->unsubscribedChannelIds = $channelIds;

    $url = $this->buildUrl('users/updateSubscriptions');

    $request = new Request();

    $response = $request->post($url, $payload);

    return $response;
  }

  /**
   * buildUrl
   *
   * @param string    $apiMethod                The api method in iterable with which to call
   * @param string    $urlAddition (optional)   An addition to the URL method for making get requests that don't send params in the request body
   *
   * @return string   $url                      The response object from the Iterable API
   */
  private function buildUrl($apiMethod, $urlAddition = ''){
    if($urlAddition != '') $urlAddition = '/' . $urlAddition;
    $url = self::API_ENDPOINT . $apiMethod . $urlAddition . '?api_key=' . $this->iterableApiKey;
    return $url;
  }

  public function getChannels(){
    $url = $this->buildUrl('channels');
    $request = new Request();
    $response = $request->get($url);

    return (isset($response->channels)) ? $response->channels : false;
  }

  public function getMessageTypes(){
    $url = $this->buildUrl('messageTypes');
    $request = new Request();
    $response = $request->get($url);

    return (isset($response->messageTypes)) ? $response->messageTypes : false;
  }

  public function getUserData($email){
    $url = $this->buildUrl('users', $email);
    $request = new Request();
    $response = $request->get($url);

    return (isset($response->user)) ? $response->user->dataFields : false;
  }

  public function updateUserPhone($email, $phone){
    $fields = new \stdClass();
    $fields->phoneNumber = "" . $phone;

    $payload = new \stdClass();
    $payload->email = $email;
    $payload->dataFields = $fields;

    $url = $this->buildUrl('users/update');

    $request = new Request();
    $response = $request->post($url, $payload);

    return $response;
  }

  public function updateUserChannels($email, $channelIds){
    $payload = new \stdClass();
    $payload->email = $email;
    $payload->unsubscribedChannelIds = $channelIds;

    $url = $this->buildUrl('users/updateSubscriptions');

    $request = new Request();
    $response = $request->post($url, $payload);

    return $response;
  }

  public function updateUserMessageTypes($email, $typeIds){
    $payload = new \stdClass();
    $payload->email = $email;
    $payload->unsubscribedMessageTypeIds = $typeIds;

    $url = $this->buildUrl('users/updateSubscriptions');

    $request = new Request();
    $response = $request->post($url, $payload);

    return $response;
  }
  
}