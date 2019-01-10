<?php 

/**
* 
*/
class BT50Request
{
	protected $method = NULL;
	protected $timeout = NULL;
	protected $headers = NULL;
	protected $endpoint = NULL;
    protected $apikey = NULL;
    protected $url = NULL;

	function __construct()
	{
	    $this->method = 'GET';
	    $this->timeout = 8;
	    $this->headers = array('Content-Type' => 'application/json');
	    $this->apikey = '41C7F8B6-4B4B-415F-B88E-52300B3AC1EC';
	    $this->url = 'http://www.billtrack50.com/BT50Api/json/';
	}

	function lookupStateCodes(){
		$endpoint = 'LookupStateCodes';
		$url_params = NULL;
		$result = $this->request($endpoint, $url_params);
		return $result;
	}

	function lookupKnowWhoLegislator($knowWhoPersonID){
		$endpoint = 'LookupKnowWhoLegislator';
		$url_params['knowWhoPersonID'] = $knowWhoPersonID;
		$result = $this->request($endpoint, $url_params);
		return $result;
	}

	function lookupLegislator($legislatorName, $stateCodes = NULL){
		$endpoint = 'LookupLegislator';
		$url_params['legislatorName'] = $legislatorName;
		$url_params['stateCodes'] = $stateCodes;
		$result = $this->request($endpoint, $url_params);
		return $result;
	}

	function lookupStateBill($billNumber, $stateCodes){
		$endpoint = 'LookupStateBill';
		$url_params['billNumber'] = $billNumber;
		$url_params['stateCodes'] = $stateCodes;
		$result = $this->request($endpoint, $url_params);
		return $result;
	}

	function searchBill($stateCodes, $textAll = NULL, $textAny = NULL, $textNone = NULL, $billSponsorIDs = NULL, $billIDs = NULL){
		$endpoint = 'SearchBill';
		$url_params['stateCodes'] = $stateCodes;
		$url_params['textAll'] = $textAll;
		$url_params['textAny'] = $textAny;
		$url_params['textNone'] = $textNone;
		$url_params['billSponsorIDs'] = $billSponsorIDs;
		$url_params['billIDs'] = $billIDs;
		$result = $this->request($endpoint, $url_params);
		return $result;
	}

	function listBillVotes($billID){
		$endpoint = 'ListBillVotes';
		$url_params['billID'] = $billID;
		$result = $this->request($endpoint, $url_params);
		return $result;
	}

	function listVoteDetail($voteID){
		$endpoint = 'ListVoteDetail';
		$url_params['voteID'] = $voteID;
		$result = $this->request($endpoint, $url_params);
		return $result;
	}

	function listLegislatorVoteRecord($legislatorID){
		$endpoint = 'ListLegislatorVoteRecord';
		$url_params['legislatorID'] = $legislatorID;
		$result = $this->request($endpoint, $url_params);
		return $result;
	}

	protected function request($endpoint, $url_params){

		$curl = curl_init();
		$query = array();

		$url = $this->url;
		//anything that goes in the url query
		$query = $url_params;
		$query['apiKey'] = $this->apikey;

		$params = http_build_query($query);

		curl_setopt_array($curl, array(
		  CURLOPT_URL => $url . $endpoint .'?'. $params,
		  CURLOPT_RETURNTRANSFER => true,
		  //CURLOPT_ENCODING => "",
		  CURLOPT_HTTPHEADER => $this->headers,
		  CURLOPT_MAXREDIRS => 10,
		  CURLOPT_TIMEOUT => $this->timeout,
		  CURLOPT_HTTP_VERSION => CURL_HTTP_VERSION_1_1,
		  CURLOPT_CUSTOMREQUEST => $this->method,
		  CURLOPT_FOLLOWLOCATION => 1,
		  //CURLOPT_SSL_VERIFYHOST => false,
		));

		$response = curl_exec($curl);
		$err = curl_error($curl);
		curl_close($curl);

		if ($err) {
		  echo "cURL Error #:" . $err;
		} else {
		  $json = json_decode($response, true);
		 
		  if ($json['Code']=='200') {
		  	return $json;
		  }
		  //Response Codes from https://www.billtrack50.com/documentation/webservices#ResponseCodes
		  elseif($json['Code']=='403'){ echo $json['Message'];}
		  elseif($json['Code']=='429'){ echo $json['Message'];}
		  elseif($json['Code']=='1001'){ echo $json['Message'];}
		  elseif($json['Code']=='1002'){ echo 'Database Error';}
		}
	}
}



//========Class calls to BT50 API=========//
//$req->lookupStateCodes();
//$req->lookupLegislator('Buck', 'AK,CO');
//$req->lookupStateBill('HB170', 'AK,CO');
//$req->searchBill('CO', 'Tax Reform');
//$req->listBillVotes('473295');
//$req->listVoteDetail('309080');
//$req->listLegislatorVoteRecord('309080');
