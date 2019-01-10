<?php
$userkeyword = utf8_encode($_POST['keyword']);
$country = $_POST['country'];

if ( $country == "Canada" ) {	
	$user = 'kwcheckerca';
}
else {	
	$user = 'kwchecker';
}

$data = array(
	'User' => $user,
	'Password' => 'qwaszx',
	'Keyword' => $userkeyword
);
$curl = curl_init('https://app.eztexting.com/keywords/new?format=json&' . http_build_query($data));
curl_setopt($curl, CURLOPT_RETURNTRANSFER, 1);
$response = curl_exec($curl);

$json = json_decode($response);
$json = $json->Response;

echo((int) $json->Entry->Available);

?>
