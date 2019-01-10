<?php
///////////////////////////////////////////////////////////////////
// PERFECT                                                       //
// -------                                                       //
// PHP E-mail Receive Form Electronic Content Text               //
// File: feedback.php                                            //
// Version: 1.6 (April 2, 2005)                                  //
// Description: Processes a web form to read the user input and  //
//    then send the data to a predefined recipient.  You are     //
//    free to use and modify this script as you like.            //
// Instructions:  Go to "http://www.centerkey.com/php".          //
//                                                               //
// Center Key Software  *  www.centerkey.com  *  Dem Pilafian    //
///////////////////////////////////////////////////////////////////

function br2nl($text)
{
    $text = preg_replace('/<br\\\\s*?\\/??>/i', "\\n", $text);
    return str_replace("<br />","\n",$text);
}

$categorArr = array(1 => 'Help with your account',
    2 => 'Technical Support',
    3 => 'Sales'
);

$category = $categorArr[$_POST['category']];

if ($_POST['category'] == 1 || $_POST['category'] == 2) {
    /* SUBMIT TO ZENDESK */
    $ticket_form_id = 32897;
    $tag = "eztexting";
    $recipient = "answers@eztexting.com";
    $username = "nels@callfire.com";
    $token = "ZMtsy8WAG5lhBwBvAvHBQAX9j5iQ1IHJQ11L9eOV";
    $submitUrl = "https://answers.callfire.com/api/v2/tickets.json ";

    $message = br2nl($_POST['message']);
    $data = array(
        "ticket" => array(
            "recipient" => $recipient,
            "ticket_form_id" => $ticket_form_id,
            "tags" => ["eztexting"],
            "requester" => array(
                "name" => $_POST['name'],
                "email" => $_POST['email']
            ),
            "subject" => $_POST['subject'],
            "comment" => array(
                "body" => $message
            ),
            "custom_fields" => array(
                array(//username
                    "id" => '23853973',
                    "value" => $_POST['username']
                ),
                array(//phone number
                    "id" => '23893996',
                    "value" => $_POST['phone_number']
                ),
                array(//name
                    "id" => '23869018',
                    "value" => $_POST['name']
                ),
                array(//category
                    "id" => '24006516',
                    "value" => $category
                )

            )
        )
    );

    $json_data = json_encode($data);

    $zen_curl = curl_init($submitUrl);

    curl_setopt($zen_curl, CURLOPT_VERBOSE, 0);
    curl_setopt($zen_curl, CURLOPT_HEADER, 0);
    curl_setopt($zen_curl, CURLOPT_POST, 1);
    curl_setopt($zen_curl, CURLOPT_RETURNTRANSFER, 1);
    curl_setopt($zen_curl, CURLOPT_POSTFIELDS, $json_data);
    curl_setopt($zen_curl, CURLOPT_USERPWD, $username."/token:".$token);
    curl_setopt($zen_curl, CURLOPT_HTTPHEADER, array(
            'Content-Type: application/json',
            'Content-Length: ' . strlen($json_data))
    );

    $response = curl_exec($zen_curl);


    echo( '"' . $response . '"' );

} else {
    /* SUBMIT TO HUBSPOT */
    $hubspotutk      = $_POST['hubspot_token']; //grab the cookie from the visitors browser.
    $ip_addr         = $_POST['ip_address']; //IP address too.
    $hs_context      = array(
        'hutk' => $hubspotutk,
        'ipAddress' => $ip_addr,
        'pageUrl' => 'https://www.eztexting.com/help/contact-support',
        'pageName' => 'Contact EZ Texting Support'
    );
    $hs_context_json = json_encode($hs_context);

    //Need to populate these variable with values from the form.
    $str_post = "firstname=" . urlencode($_POST['name'])
        . "&email=" . urlencode($_POST['email'])
        . "&phone=" . urlencode($_POST['phone_number'])
        . "&subject_line=" . urlencode($_POST['subject'])
        . "&message=" . urlencode($_POST['message'])
        . "&reason_for_contacting_us_today" . urlencode($_POST['category'])
        . "&hs_context=" . urlencode($hs_context_json); //Leave this one be

    //replace the values in this URL with your portal ID and your form GUID
    $endpoint = 'https://forms.hubspot.com/uploads/form/v2/2627016/231c8836-4689-45ed-8a2d-339617484507';

    $ch = @curl_init();
    @curl_setopt($ch, CURLOPT_POST, true);
    @curl_setopt($ch, CURLOPT_POSTFIELDS, $str_post);
    @curl_setopt($ch, CURLOPT_URL, $endpoint);
    @curl_setopt($ch, CURLOPT_HTTPHEADER, array(
        'Content-Type: application/x-www-form-urlencoded'
    ));
    @curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
    $response    = @curl_exec($ch); //Log the response from HubSpot as needed.
    $status_code = @curl_getinfo($ch, CURLINFO_HTTP_CODE); //Log the response status code
    @curl_close($ch);
}

?>