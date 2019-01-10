<?php


function strstr_after($haystack, $needle, $case_insensitive = false) {
	    $strpos = ($case_insensitive) ? 'stripos' : 'strpos';
	    $pos = $strpos($haystack, $needle);
	    if (is_int($pos)) {
	        return substr($haystack, $pos + strlen($needle));
	    }
	    // Most likely false or null
	    return $haystack;
}

function curlRequest($url, $username = null,$password = null) { 

	if(isset($url)) {	
	  	$http_request = curl_init($url);
	    curl_setopt($http_request,CURLOPT_RETURNTRANSFER,1);
	    if(isset($username,$password)) {
	      curl_setopt($http_request, CURLOPT_USERPWD, $username.":".$password);
	    }
	    $result = curl_exec($http_request);
	    $http_status = curl_getinfo($http_request, CURLINFO_HTTP_CODE);
	    return json_decode($result, true);
	}
	else
		echo "invalid request";
}
?>