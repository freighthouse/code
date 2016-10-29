<?php
    require 'class/class.eloquaLookup.php';

    $siteID = 1852860672; //Turn's Eloqua Instance ID
    $lookupKey = '4fa29caf6d2f4ab7a0e580995e1dada3'; //Eloqua Data Lookup Key for Visitor Lookup
    $elqGUID = $_COOKIE['ELOQUA']; //Eloqua Visitor Cookie GUID (used as criteria for querying visitors from Eloqua)
    $docid = $_QUERY['docid']; //Document ID coming into the page download

    //Use the docid or some other id to query Drupal for more information on the requested download
    //We'll populate with static values for this example
    $cmpid = '70180000000SXmP'; //default salseforce campaign id (if download does not have a unique cmpid, this one should be used)
    $ecid = '274'; //default eloqua campaign id (if download does not have a unique ecid, this one should be used)
    $docName = 'Test Download'; //another field for this object in Drupal
    $docDescription = 'Lorem Ipsum...'; //another field for this object in Drupal

    //retrieving visitor profile data
    $visitor = new EloquaVisitorLookup($siteID, $lookupKey, $elqGUID);

    //check email
    $email = $visitor->data['V_ElqEmailAddress'];
if($email == null) {
    //present the form
    echo 'Present the Form';
} else {
    //use email to query for contact
    $lookupKey = '7e71589ad53d42d094eacfc104258ec1'; //Eloqua Data Lookup Key for Contact Lookup
    $criteria = array('C_EmailAddress' => $email);
    $contact = new EloquaContactLookup($siteID, $lookupKey, $criteria);

    //contact data
    $contact->data['C_FirstName'];
    $contact->data['C_LastName'];
    $contact->data['C_EmailAddress'];
    $contact->data['C_BusPhone'];
    $contact->data['C_Country'];
    $contact->data['C_State_Prov'];
    $contact->data['C_Company'];
    $contact->data['C_Industry1'];
    $contact->data['C_Job_Role1'];
    $contact->data['C_Department1'];
    $contact->data['C_Company_Type1'];

    //check if all contact data is filled
    if($contact->data['C_FirstName'] != null 
        && $contact->data['C_LastName'] != null 
        && $contact->data['C_EmailAddress'] != null 
        && $contact->data['C_BusPhone'] != null 
        && $contact->data['C_Country'] != null 
        && $contact->data['C_State_Prov'] != null 
        && $contact->data['C_Company'] != null 
        && $contact->data['C_Industry1'] != null 
        && $contact->data['C_Job_Role1'] != null 
        && $contact->data['C_Department1'] != null 
        && $contact->data['C_Company_Type1'] != null
    ) {

        //auto submit the form with the available contact data
        echo 'Auto submit the Form';

        //make sure to pass through: $cmpid, $ecid, $docName and maybe $docDescription depending on how long these might be
    } else {
        //present the form
        echo 'Present the Form';

        //you can optionally pre populate the data that is not null if you want..
    }

    //dump contact data to screen
    foreach($contact->data as $key => $value) {
        echo $key . ": " . $value . "<br/>\n";
    }
}
?>
