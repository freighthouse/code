<?php
	//$path = "/var/www"; 
	$path = $_SERVER['DOCUMENT_ROOT']; /*For Local Use Only*/
	chdir($path."/drupal");
	if(!defined('DRUPAL_ROOT')) {
		define('DRUPAL_ROOT', getcwd());
	}
	require_once './includes/bootstrap.inc';
	drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

	if(isset($_REQUEST['contentlink'])) {

		if(isset($_REQUEST['dpg'])) {	
			$nid = substr($_REQUEST['dpg'],stripos($_REQUEST['dpg'], '/')+1);
			$node = node_load($nid);
			menu_set_active_item($_REQUEST['dpg']);

		}
		else  {
			$node = node_load(2268001); //2173002
		}
        $wsdl = get_node_field($node, 'field_wsdl');
		$pagehtml = get_node_field($node, 'field_template');
		$content_link = $wsdl . $_REQUEST['contentlink'];
		list($header, $sidebar, $maincontent) = explode("<!--section-->", $pagehtml);
		$results = renderHandlebars($content_link, $maincontent);
		echo $results;
	}
?>