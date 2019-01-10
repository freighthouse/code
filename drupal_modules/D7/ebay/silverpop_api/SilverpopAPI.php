<?php

/**
 * SilverpopAPI Class for PHP.
 *
 * Goal is to provide a thin PHP wrapper for Silverpop API. You can call this
 * class directly, or subclass it to add business logic. See Silverpop API
 * documentation for details of what each function does. Some functions you
 * require a call to login() before you can use them. Requires a PHP install
 * with cURL extensions installed on your server.
 *
 * Note: If you are on an Engage pod other than 1, you will need to adjust
 * your $api_url either in the class below or at runtime.
 *
 * Last updated: 2010-02-14
 *
 * @author Eli Dickinson <eli@fiercemarkets.com>
 *
 * Example:
 *
 * $sp_api = new SilverpopAPI();
 *
 * // add user to a list
 * $demographics = array('First Name'=> 'Eli', 'EMAIL'=>'eli@fiercemarkets.com');
 * $list_id = 123456;
 * $sp_api->add_recipient($list_id, $demographics);
 *
 * // Returns a bunch of data on a given user in a given list
 * $recipient_data = $sp_api->get_recipient($list_id, 'eli@fiercemarkets.com')
 * 
 * // Get a list of all your lists (aka databases). Requires login.
 * $sp_api->login('api@example.com','p4ssw0rd');
 * $lists = $sp_api->get_lists();
 * 
 */

// Constants defined in API spec
DEFINE('SP_CREATED_FROM_IMPORTED', 0);
DEFINE('SP_CREATED_FROM_MANUAL', 1);
DEFINE('SP_CREATED_FROM_OPT_IN', 2);
DEFINE('SP_CREATED_FROM_TRACKING_LIST', 3);

DEFINE('SP_FORMAT_CSV',  0);
DEFINE('SP_FORMAT_PIPE', 1);
DEFINE('SP_FORMAT_TAB',	 2);

// Set this to TRUE to enable printing of debug messages
DEFINE('SP_PRINT_DEBUG_MESSAGES', FALSE); 

// Set TRUE to have curl verify HTTPS certificates. This works fine, but you may
//	have to set up root certificates for curl.
DEFINE('SP_API_VERIFY_SSL_CERT', FALSE); 


require_once('xmltools.php');

class SilverpopException extends Exception { }
class SilverpopNoUserException extends SilverpopException { }
class SilverpopUserExistsException extends SilverpopException { }

class SilverpopAPI {
	public $api_url = 'https://api3.silverpop.com/XMLAPI';
	public $transfer_sftp_host = 'transfer1.silverpop.com';
	public $tranfser_sftp_fingerprint = '1B048727E694055C5D0A2E20FCD5A081';
	public $http_timeout = 20; // in seconds
	public $sessionid; // contains current session ID if logged in (i.e. after call to login())
	public $last_request;  // XML string of the most recent request.
	
	/**
	 * The Engage system requires you to login against an account prior to certain API requests. This
	 *	function does the login and saves the authentication token so that all subsequent api calls in
	 *	this instance will be authenticated.
	 */
	function login($username,$password) {
		$data = array('USERNAME' => $username, 'PASSWORD' => $password);
		$response = $this->call_api('Login',$data);
		$this->sessionid = (string)$response->SESSIONID;
		return $response;
	}	
	
	/**
	 * Destroys authentication token. You must login() again if you wish to use methods that require it.
	 */
	function logout(){
		$response = $this->call_api('Logout');
		$this->sessionid = NULL;
		return $response;
	}

	
	/**
	 * Adds a recipient to the list identified by $list_id. $demographics is a hash array of field values for the recipient.
	 *	It MUST contain a key named 'EMAIL' that contains a valid email address.
	 * If $update_if_found is true (the default), this will also update the demographics of the person with the given email.
	 * $created_from is a flag that lets you indicate how the person signed up. Valid values: SP_CREATED_FROM_IMPORTED,
	 *	 SP_CREATED_FROM_MANUAL, SP_CREATED_FROM_OPT_IN, SP_CREATED_FROM_TRACKING_LIST.
	 * $allow_html (default: false) determines if HTML can be stored without escaping in field values
	 * $send_autoreply (default: true) indicates if any welcome message triggers should fire
	 * $opt_back_in (default: true) will make this person an active user again if they're already on the list, but have
	 *	opted out. Requires $update_if_found to be set. FIXME: this parameter no longer seems to be working!
	 */
	function add_recipient($list_id, $demographics = array(), $created_from = SP_CREATED_FROM_MANUAL, $send_autoreply = true, 
													$update_if_found = true, $allow_html = false, $opt_back_in = true) {
		
		// TODO: sanity check list_id and other parameters
		
		// translate parameter options to "true"/"false" strings
		$update_if_found = $update_if_found ? "true" : "false";
		$send_autoreply = $send_autoreply ? "true" : "false";
		$allow_html = $allow_html ? "true" : "false";
		
		if($opt_back_in) {
			$demographics['OPT_OUT'] = 'false';
		}
		
		$data = array('LIST_ID'=> $list_id, 'CREATED_FROM'=> $created_from, 'SEND_AUTOREPLY' => $send_autoreply, 
			'UPDATE_IF_FOUND'=> $update_if_found, 'ALLOW_HTML'=> $allow_html);

		// now build the demographics into a silly "column" format
		$data['COLUMN'] = array();
		foreach($demographics as $key => $value) {
			$data['COLUMN'][] = array('NAME'=> $key, 'VALUE' => $value);
		}	
		
		$response = $this->call_api('AddRecipient',$data);
		return $response;
	}
	
	/**
	 * Updates demographics for an existing user in the list. Does not appear to work
	 * if user is opted out. To change user email address, supply new address with EMAIL
	 * key in $demographics. Will throw exception if user not in list.
	 */
	function update_recipient($list_id, $old_email, $demographics = array(), $send_autoreply = true, $opt_back_in = true, $allow_html = false) {
		
		// Make parameter options into strings
		$send_autoreply = $send_autoreply ? "true" : "false";
		$allow_html = $allow_html ? "true" : "false";
		
		if(!is_array($demographics)) $demographics = array();
		
		$created_from = SP_CREATED_FROM_OPT_IN; // documentation unclear on this parameter
		
		$data = array('LIST_ID'=> $list_id, 'CREATED_FROM'=> $created_from, 'SEND_AUTOREPLY' => $send_autoreply, 
			'ALLOW_HTML'=> $allow_html, 'OLD_EMAIL' => $old_email);
		
		if(!@$demographics['EMAIL']) {
			$demographics['EMAIL'] = $old_email;
		}
		
//		if($demographics['EMAIL'] == $old_email) {
//			unset($demographics['EMAIL']);
//		}
		
		if($opt_back_in) {
			$demographics['OPT_OUT'] = 'False';
		}

		
		// now build demographics in "column" format
		if(sizeof($demographics) > 0 ) {
			$data['COLUMN'] = array();
			foreach($demographics as $key => $value) {
				$data['COLUMN'][] = array('NAME'=> $key, 'VALUE' => $value);
			}	
		}
		
		$response = $this->call_api('UpdateRecipient',$data);
		return $response;
	}
	
	/**
	 * get_recipient() - gets an array of data about the person
	 *  Uses SelectRecipientData API
	 * TODO: rename to select_recipient_data()
	 */
	function get_recipient($list_id, $email) {
		
		$parameters = array('LIST_ID' => $list_id, 'EMAIL' => $email);
		$response = $this->call_api('SelectRecipientData',$parameters);
		
		$data = array();
		$data['email'] = (string)$response->EMAIL;
		$data['recipientid'] = (string)$response->RecipientId;
		$data['emailtype'] = (string)$response->EmailType;
		$data['lastmodified'] = (string)$response->LastModified;
		$data['createdfrom'] = (string)$response->CreatedFrom;
		$data['optedin'] = (string)$response->OptedIn;
		$data['optedout'] = (string)$response->OptedOut;
		$data['demographics'] = array();
		
		foreach($response->COLUMNS->COLUMN as $column) {
			$key = (string)$column->NAME;
			$value = (string)$column->VALUE;
			$data['demographics'][$key] = $value;
		}
		return $data;			
		
	}
	
	function list_recipient_mailings($list_id, $recipient_id) {
		$data = array('LIST_ID' => $list_id, 'RECIPIENT_ID' => $recipient_id);
		$response = $this->call_api('ListRecipientMailings',$data);
		return $response;
	}
	
	/**
	 * optout_recipient() opts user out of active list, but keeps all demographics
	 */
	function optout_recipient($list_id, $email) {
		$data = array('LIST_ID' => $list_id, 'EMAIL' => $email);
		$response = $this->call_api('OptOutRecipient',$data);
		return $response;		
	}
	
	/**
	 * Completely deletes user from list, any demographics and mailing history is lost
	 */
	function remove_recipient($list_id, $email) {
		$data = array('LIST_ID' => $list_id, 'EMAIL' => $email);
		$response = $this->call_api('RemoveRecipient',$data);
		return $response;
		
	}
	
	
	/**
	 * Recalculate query. Docs claim it can only be called if query is more than 12 hours old.
	 * Must be already logged in with a previous call to login()
	 */
	function calculate_query($query_id, $notify_email = '') {
		$data = array('QUERY_ID' => $query_id);
		if($notify_email) {
			$data['EMAIL'] = $notify_email;
		}
		$response = $this->call_api('CalculateQuery',$data);
		return $response;	 	
	}
	
	/**
	 * Get stats on list. Requires login.
	 */
	function get_list_metadata($list_id) {
		$data = array('LIST_ID' => $list_id);
		$response = $this->call_api('GetListMetaData',$data);
		return $response;		
	}
	
	/**
	 * Gets a list of databases (lists)
	 */
	function get_lists($folder = NULL) {
		$data = array(
		  'VISIBILITY' => 1, // shared
		  'LIST_TYPE' => 0, // Databases
		  'INCLUDE_ALL_LISTS' => 'False',
		  'INCLUDE_TAGS' => 'False',
		  );
		if ($folder) {
		  $data['FOLDER_ID'] = $folder;
		}
		$response = $this->call_api('GetLists',$data);
		return $response;		
	}
	
	
	/**
	 * get_aggregate_tracking_for_mailing() Provides many stats on a specific mailing
	 * Requires prior login.
	 */
	function get_aggregate_tracking_for_mailing($mailing_id, $report_id, 
		$include_top_domains = false, $include_inbox_monitoring = false, $include_per_click = false) {
		$data = array('MAILING_ID'=> $mailing_id, 'REPORT_ID'=> $report_id);
		
		// add in optional parameters
		if($include_top_domains)
			$data['TOP_DOMAINS'] = '';
		if($include_inbox_monitoring)
			$data['INBOX_MONITORING'] = '';
		if($include_per_click)
			$data['PER_CLICK'] = '';
		
		$response = $this->call_api('GetAggregateTrackingForMailing', $data);
		return $response;
	}
	
	/**
	 * get_aggregate_tracking_for_org()
	 * Provide $date_start and $date_end as timestamps (i.e. an int returned by time())
	 */
	function get_aggregate_tracking_for_org($date_start, $date_end, $incl_per_click = false, $incl_private = false, $incl_shared = true ) {
		// Silverpop wants dates formatted "mm/dd/yyyy hh:mm:ss"
		$data = array('DATE_START'=> date('m/d/Y H:i:s', $date_start), 'DATE_END'=> date('m/d/Y H:i:s', $date_end));
		
		// TODO: assuming want SENT
		$data['SENT'] = '';
		
		if($incl_per_click)
			$data['PER_CLICK'] = '';
		if($incl_private)
			$data['PRIVATE'] = '';
		if($incl_shared)
			$data['SHARED'] = '';

		$response = $this->call_api('GetAggregateTrackingForOrg', $data);
		return $response;
	}
	
	/**
	 * GetSentMailingsForOrg - This interface extracts a listing of mailings sent for
	 *  an organization for a specified date range.
	 * Returns mailings in given date range along with their Mailing Name, List Name,
	 * Subject, Num Sent, etc
	 *
	 * Note: results are NOT in chronological order
	 * 
	 */
	function get_sent_mailings_for_org($date_start, $date_end, $mailing_types = array('SENT','SHARED'), $include_tags = TRUE) {
		// Silverpop wants dates formatted "mm/dd/yyyy hh:mm:ss"
		$data = array('DATE_START'=> date('m/d/Y H:i:s', $date_start), 'DATE_END'=> date('m/d/Y H:i:s', $date_end));
		
		// TODO: assuming want SENT & TAGS (adding a key with empty string as value to array creates an empty tag like <KEY/> in the XML)
		foreach($mailing_types as $mailing_type) {
			$data[strtoupper($mailing_type)] = '';
		}
		
		if($include_tags)
			$data['INCLUDE_TAGS'] = '';
		
		$response = $this->call_api('GetSentMailingsForOrg', $data);
		return $response->Mailing;
	}
	
	/**
	 * get_aggregate_tracking_for_user()
	 * Provide $date_start and $date_end as timestamps (i.e. an int returned by time())
	 */
	function get_aggregate_tracking_for_user($date_start, $date_end, $incl_per_click = false, $incl_private = false, $incl_shared = true ) {
		// Silverpop wants dates formatted “mm/dd/yyyy hh:mm:ss”
		$data = array('DATE_START'=> date('m/d/Y H:i:s', $date_start), 'DATE_END'=> date('m/d/Y H:i:s', $date_end));
		
		// TODO: assuming want SENT
		$data['SENT'] = '';
		
		if($incl_per_click)
			$data['PER_CLICK'] = '';
		if($incl_private)
			$data['PRIVATE'] = '';
		if($incl_shared)
			$data['SHARED'] = '';

		$response = $this->call_api('GetAggregateTrackingForOrg', $data);
		return $response;
	}
	
	/**
	 * raw_recipient_data_export - requests data export to FTP account
	 */
	function raw_recipient_data_export($list_id = NULL, $send_date_start = NULL, $send_date_end = NULL, $export_format = SP_FORMAT_CSV,
		$options = array('MOVE_TO_FTP', 'SHARED', 'SENT_MAILINGS', 'OPENS', 'INCLUDE_QUERIES')) {
		
		$data = array();
		
		$data['EXPORT_FORMAT'] = $export_format;
		
		foreach($options as $option) {
			$data[$option] = '';
		}
		
		if($list_id)
			$data['LIST_ID'] = $list_id;
		if($send_date_start)
			$data['SEND_DATE_START'] = date('m/d/Y H:i:s', $send_date_start);
		if($send_date_end)
			$data['SEND_DATE_END'] = date('m/d/Y H:i:s', $send_date_end);
		
		$response = $this->call_api('RawRecipientDataExport', $data);
		return $response;
	}
	
	
	/**
	 * export_list
	 *	$export_type is one of: ALL, OPT_IN, OPT_OUT, UNDELIVERABLE
	 *	$export_format is one of: CSV, TAB, Pipe
	 *	$add_to_stored_files: adds to stored files section if set, otherwise
	 *		sends files to FTP of current user 
	 *	$list_date_format: e.g. 'mm/dd/yyyy'. Defaults to yyyy-mm-dd
	 */
	function export_list($list_id, $export_type = 'ALL', $export_format = 'CSV', $add_to_stored_files = FALSE, $list_date_format = 'yyyy-mm-dd', $date_start = NULL, $date_end = NULL) {
		$data = array();
		$data['LIST_ID'] = $list_id;
		$data['EXPORT_TYPE'] = $export_type;
		$data['EXPORT_FORMAT'] = $export_format;
    $data['DATE_START'] = $date_start;
    $data['DATE_END'] = $date_end;
		if($add_to_stored_files)
			$data['ADD_TO_STORED_FILES'] = '';
		$data['LIST_DATE_FORMAT'] = $list_date_format;
		$response = $this->call_api('ExportList',$data);
		return $response;
	}


	/**
	 * ImportList API call
	 * Must be already logged in. Map file and Source file must exist in "upload" FTP directory
	 */
	public function import_list($map_file, $source_file) {
		$data = array('MAP_FILE' => $map_file, 'SOURCE_FILE' => $source_file);
		$response = $this->call_api('ImportList',$data);
		return $response;
	}

	/**
	 * GetJobStatus API call
	 */
	public function get_job_status($job_id) {
		$data = array('JOB_ID' => $job_id);
		$response = $this->call_api('GetJobStatus',$data);
		return $response;
	}
	
	/**
	 * is_subscribed - returns true if user is on the list and not opted-out, false otherwise.
	 * 	Works by attempting to call get_recipient and catching the NoUser 
	 * 	exception, then checking OptedOut date. This is a convenience function, not
	 *  a direct SP API. 
	 */
	function is_subscribed($list_id,$email) {
		try {
			$user_data = $this->get_recipient($list_id,$email);
			$optoutdate = $user_data['optedout'];
			if($optoutdate)
				return false;
			else
				return true;
		}
		catch (SilverpopNoUserException $e) {
			return false;
		}
	}
	
	
	/**
	 * call_api()  takes API function name and array of parameters, turns it into formatted
	 * XML and then actually calls the HTTP API (using call_api_xml).
	 */
	protected function call_api($function_name, $parameters = array()) {		
		
		// ArrayToXML converts array of arrays to string of XML. See xmltools.php. 
		$xml_data_string = ArrayToXML::toXML(array('Body' => array($function_name => $parameters )), 'Envelope');
		
		// call_api_xml() actually talks to SP server.
		$response_payload = $this->call_api_xml($xml_data_string);
		
		// return XML data enclosed in response
		return $response_payload;
	}
	
	/**
	 * Takes an already formatted XML string and calls Silverpop API. Also used
	 * directly by SilverpopQueue
	 * 
	 */
	public function call_api_xml($xml_data_string) {
		$post_variables = array();
		
		$url = $this->api_url;
		if($this->sessionid) {
		  $url .= ';jsessionid='.$this->sessionid;
		}
		
		$this->last_request = $xml_data_string;
		$post_variables['xml'] = $xml_data_string;
		
		if(SP_PRINT_DEBUG_MESSAGES)
			var_dump($post_variables);
		$result = $this->http_post_form($url,$post_variables);
		if(SP_PRINT_DEBUG_MESSAGES)
			print htmlentities($result);
		$xml = simplexml_load_string($result);
		$response_payload = $xml->Body->RESULT;
		$success = in_array(strtolower($response_payload->SUCCESS), array('true','success','yes'));
		if(!$success) {
			$error_message = @(string)$xml->Body->Fault->FaultString;
			$error_num = @(int)$xml->Body->Fault->detail->error->errorid;
			if((!$error_message) && (!$error_num)) {
				throw new SilverpopException("Unknown error");
			} else {
				if(($error_num == 128) || ($error_num == 155))
					throw new SilverpopNoUserException($error_message,$error_num);
				elseif($error_num == 122)
					throw new SilverpopUserExistsException($error_message,$error_num);
				else
					throw new SilverpopException($error_message,$error_num);
			}
			
		}
		return $response_payload;
	}
	
	/**
	 * Silverpop tags are case-sensitive for some reason. This function adjusts them to the proper
	 * case automatically.
	 */
	protected function fix_tag_case($string) {
		// TODO
	}
	
	
	/**
	 * Converts yes/no field to php boolean
	 */
	protected function yesno_value($value) {
		$value = strtolower($value);
		if($value == 'yes')
			return true;
		elseif($value == 'no')
			return false;
		
		return NULL;
	}
	
	/**
	 * POST data to an HTTP server. Requires the PHP CuRL extension. 
	 * $data is an array of data like array('key'=>'value')
	 */
	protected function http_post_form($url,$data = array()) {
		if(!function_exists("curl_exec")) {
			trigger_error("ERROR: PHP/cURL is not installed on this server");
		}
		
		$ch = curl_init(); 
		curl_setopt($ch, CURLOPT_URL,$url); // set url to post to 
		curl_setopt($ch, CURLOPT_FAILONERROR, 1); 
		curl_setopt($ch, CURLOPT_FOLLOWLOCATION, 1); // allow redirects 
		curl_setopt($ch, CURLOPT_RETURNTRANSFER,1); // return into a variable 
		curl_setopt($ch, CURLOPT_TIMEOUT, $this->http_timeout); // times out after $timeout secs 
		curl_setopt($ch, CURLOPT_POST, 1); // set POST method 
		
		// uncomment following two lines to skip SSL certificate validation
		if(!SP_API_VERIFY_SSL_CERT) {
			curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, false);
			curl_setopt($ch, CURLOPT_SSL_VERIFYHOST, false);
		}

		// Translate $data hash into form encoded string (e.g. "param1=val&param2=val&param3=val")
		$values = array();
		foreach($data as $key=>$value)
		$values[]="$key=".urlencode($value);
		$data_string=implode("&",$values);
		
		curl_setopt($ch, CURLOPT_POSTFIELDS, $data_string); // add POST fields 
		$result = curl_exec($ch); // run the whole process 
		if($result === false) {
			throw New SilverpopException("CURL Error: ".curl_error($ch) . " " . curl_errno($ch)); 
		}
		curl_close($ch);
		return $result;
	}

	/**
	 * Recpient_ID is returned as a number in API, but obfuscated in web interface
	 *	and in mailings. This function de-obfuscates it. Takes a string of letters
	 *	and numbers and returns a number.
	 *
	 * Basically, the encoded id is a base 64-encoded version of the id number, 
	 *	with a slight twist. E.g. with the encoded id:
	 * MTM1ODgyNzM3NTMS1
	 * first replace the last two characters with single "=":
	 * MTM1ODgyNzM3NTM=
	 * and then do a base64-decode to get:
	 * 13588273753 
	 */
	static function decode_recipient_id($encoded_id) {
		$base64 = substr($encoded_id, 0, strlen($encoded_id) - 2) . '=';
		$decoded = base64_decode($base64);
		return $decoded;
	}
  
	/**
	 * @see SilverpopAPI::decode_recipient_id()
	 *
	 * Basically, the encoded id is a base 64-encoded version of the id number, 
	 *	with a slight twist. E.g. with the encoded id:
	 * MTM1ODgyNzM3NTMS1
	 * first replace the last two characters with single "=":
	 * MTM1ODgyNzM3NTM=
	 * and then do a base64-decode to get:
	 * 13588273753 
	 */
	static function encode_recipient_id($decoded_id) {
		$base64 = base64_encode($decoded_id);
		$encoded = substr($base64, 0, strlen($base64) - 1) . 'S1';
		return $encoded;
	}
  
	/**
	 * Uploads a file to the SFTP account in the "upload" directory
	 * $filename must be a path that copy() can use
	 * $username and $password are SFTP login credentials.
	 * Not all Engage accounts have SFTP accounts.
	 * Throws SilverpopException if the process fails before copying the file.
	 * Returns the return value of copy() (Success boolean)
	 *
	 */
	public function upload_file($username, $password, $filename) {
	  $connection = ftp_connect($this->transfer_sftp_host);
	  $login_result = ftp_login($connection, $username, $password); 
	
	  // check connection
	  if ((!$connection) || (!$login_result)) { 
	    $error_message = "FTP connection to $ftp_server failed.";
	    ftp_close($connection);
	    throw new SilverpopException($error_message);
	  }
	  
	  $file_parts = explode('/', $filename);
	  $name = $file_parts[count($file_parts) - 1];
	  $dest = 'upload/' . $name;
	
	  // switch to passive mode
	  ftp_pasv($connection, TRUE);
	  // upload the file
	  $upload = ftp_put($connection, $dest, $filename, FTP_BINARY); 
	
	  // check upload status
	  if (!$upload) { 
	    $error_message = "Upload failed - $filename";
	    ftp_close($connection);
	    throw new SilverpopException($error_message);
	  }
	
	  ftp_close($connection);
	
	  // SFTP - would work if we have ssh2_connect
	/*
	  $connection = ssh2_connect($this->transfer_sftp_host, 22);
	  $known_host = $this->transfer_sftp_fingerprint;
	  $fingerprint = ssh2_fingerprint($connection, SSH2_FINGERPRINT_MD5 | SSH2_FINGERPRINT_HEX);
	
	  if ($fingerprint != $known_host) {
	    $error_message = "HOSTKEY MISMATCH! - Possible Man-In-The-Middle Attack?";
	    throw new SilverpopException($error_message);
	  }
	
	  if (ssh2_auth_password($connection, $username, $password)) {
	    $sftp = ssh2_sftp($connection);
	    return copy($filename, "ssh2.sftp://$sftp/home/upload/$filename");
	  } else {
	    $error_message = "Authentication failed.";
	    throw new SilverpopException($error_message);
	  }
	*/
	}
	
	/**
	 * Downloads a file from the FTP account in the "download" directory
	 * $username and $password are FTP login credentials.
	 * Throws SilverpopException if the process fails before copying the file.
	 *
	 */
	public function download_file($username, $password, $filename, $local_path) {
	  $connection = ftp_connect($this->transfer_sftp_host);
	  $login_result = ftp_login($connection, $username, $password); 
	
	  // check connection
	  if ((!$connection) || (!$login_result)) { 
	    $error_message = "FTP connection to $ftp_server failed.";
	    ftp_close($connection);
	    throw new SilverpopException($error_message);
	  }
	
	  $file_parts = explode('/', $filename);
	  $name = $file_parts[count($file_parts) - 1];
	  $remote = 'download/' . $name;
	  $local = $local_path . '/' . $name;
	
	  // switch to passive mode
	  ftp_pasv($connection, TRUE);
	  // download the file
	  $download = ftp_get($connection, $local, $remote, FTP_BINARY); 
	
	  // check download status
	  if (!$download) { 
	    $error_message = "Download failed - $filename";
	    ftp_close($connection);
	    throw new SilverpopException($error_message);
	  }
	  ftp_close($connection);
	}


}

