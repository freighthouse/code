<?php

# @author: Jeremy Cerda
# @version: $Id: mniblogpub.php 3347 2012-03-16 20:21:01Z jcerda $

// #############################################################################
//    Load Configs
// #############################################################################
if(!is_file($argv[1])) {
	print "ERROR: Invalid config file. - ".$argv[1]."\n";
	exit(1);
}

global $mniblogpub_props;
$mniblogpub_props = parse_ini_file($argv[1], true);

// #############################################################################
//    Multi-site Support
// #############################################################################
if(isset($mniblogpub_props['mniblogpub.shared']['baseurl'])) {
	$drupal_base_url = parse_url(
		$mniblogpub_props['mniblogpub.shared']['baseurl']);

	$_SERVER['HTTP_HOST'] = $drupal_base_url['host'];
	$_SERVER['PHP_SELF'] = $drupal_base_url['path'].'/index.php';
	$_SERVER['REQUEST_URI'] = $_SERVER['SCRIPT_NAME'] = $_SERVER['PHP_SELF'];
	$_SERVER['REMOTE_ADDR'] = NULL;
	$_SERVER['REQUEST_METHOD'] = NULL;
}

// #############################################################################
//    Drupal Bootstrap
// #############################################################################
include 'includes/session.inc';
include 'modules/node/node.module';
include 'modules/user/user.module';

require_once('includes/bootstrap.inc');
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

// #############################################################################
//    Functions
// #############################################################################
/**
 * Moves a PDF file to the appropriate location
 *
 * @param string $filename
 */
function move_pdf($filename)
{
	global $mniblogpub_props;

	// Get all our names and directories
	$full_src = $mniblogpub_props["mniblogpub.shared"]["bloghome"] . "/pdfs/".
		$filename;
	$orig_src = $full_src;
	$dst_dir = file_directory_path() . "/" .
		$mniblogpub_props["mniblogpub.php"]["dir.pdf.drupal"];
	$full_dst = $dst_dir . "/" . $filename;

	$dir_perms = !is_dir($dst_dir);

	// Check our path
	$p = file_create_path($dst_dir);
	if(!file_check_directory($p, FILE_CREATE_DIRECTORY)) {
		if(!file_check_directory($p, FILE_MODIFY_PERMISSIONS)) {
			print("ERROR: Could create pdfs directory at: ". $dst_dir."\n");
			exit(5);
		}
	}

	if($dir_perms) {
		if(!chgrp($dst_dir, "www-data"))
			print "WARN: Could not change dir to www-data group. " .
				$dst_dir . "\n";
		if(!chmod($dst_dir, 0775))
			print "WARN: Could not change permissions for dir. " .
				$dst_dir . "\n";
	}

	// Error Checking
	if(!file_copy($full_src, $full_dst, FILE_EXISTS_REPLACE)) {
		print "ERROR: Could not move file " . $full_src."\n";
		exit(5);
	}

	if(!file_exists($full_dst)) {
		print "ERROR: File not actually moved. " . $full_src."\n";
		exit(5);
	}

	if(!chgrp($full_dst, "www-data"))
		print "WARN: Could not change file to www-data group. ".$full_dst."\n";
	if(!chmod($full_dst, 0664))
		print "WARN: Could not change permissions for file. " . $full_dst."\n";

	$details = stat($full_dst);

	$file = new stdClass();
	$file->filename   = basename($full_dst);
	$file->filepath   = $full_dst;
	$file->filemime   = file_get_mimetype($full_dst);
	$file->filesize   = $details['size'];
	$file->filesource = basename($full_dst);
	$file->uid        = ($mniblogpub_props["mniblogpub.php"]["user.use"] == 1 ?
		$mniblogpub_props["mniblogpub.php"]["user.id"] : 1);
	$file->status	  = FILE_STATUS_PERMANENT;
	$file->timestamp  = time();
	$file->list       = 1;
	$file->new        = true;

	drupal_write_record('files', $file);

	if($file != null && $file) {
		if(!unlink($orig_src)) {
				// !!! NOTE:
				// I don't think it's necessary to exit out here. I'm
				// commenting this out for now. If it causes errors later,
				// come back here. -Gerg
				#print "ERROR: Could not remove src file at: " . $orig_src;
				#exit(5);
				print "WARN: Could not remove src file at: " . $orig_src."\n";
		}
	} else {
		print "ERROR: Error saving file object in Drupal. " . $full_src."\n";
		exit(5);
	}

	file_set_status($file, 1);

	return $file;
}

/**
 * Gets rich content body for marketnews site
 *
 * @param string $file - filename to use in body
 */
function richbody($file)
{
	return  '
	<?php
		$node = node_load(arg(1));
		if($node) {
	?>
		<iframe id="pdf"
		style="display:block; height:42em; width:90%;
		margin-left:20px; margin-right:20px;"
		src="<?php print url(end($node->files)->filepath); ?>">
			Your browser does not support &lt;iframe&gt;, or has been
			configured not to display inline frames. You can access the
			report via
			<a href="<?php print url(end($node->files)->filepath); ?>">
			this link</a> instead.
		</iframe>

		<script type="text/javascript">
			function resizeIframe() {
				var height = document.documentElement.clientHeight;
				height -= document.getElementById("pdf").offsetTop*1.2;
				document.getElementById("pdf").style.height = height +"px";
			};
			document.getElementById("pdf").onload = resizeIframe;
			window.onresize = resizeIframe;
		</script>
	<?php } else { ?>

	<?php } ?>';
}

/**
 * Load the author declared in the config file
 */
function loadAuthor()
{
	global $mniblogpub_props;

	$author = null;
	if($mniblogpub_props["mniblogpub.php"]["user.use"] == 1)
		if ($mniblogpub_props["mniblogpub.php"]["user.id"])
			$author = user_load($mniblogpub_props["mniblogpub.php"]["user.id"]);
		else if ($mniblogpub_props["mniblogpub.php"]["user.name"])
			$author = user_load(array("name" =>
				$mniblogpub_props["mniblogpub.php"]["user.name"]));

	return $author;
}

/**
 * Loads the format declared in the config file
 */
function loadFormat()
{
	global $mniblogpub_props;

	$format = null;
	if($mniblogpub_props["mniblogpub.php"]["format.name"]) {
		$formats = filter_formats();
		foreach ($formats as $f) {
			if($f->name == $mniblogpub_props["mniblogpub.php"]["format.name"]) {
				$format = $f->format;
				break;
			}
		}
	}

	return $format;
}

/**
 * Finds human name by given machine name for taxonomy term
 *
 * @param string $machineName - Machine readable name for term
 */
function tax_getHumanName_sql($machineName) {
	$q = "SELECT t.name FROM {term_data} t " .
		"WHERE t.description = '%s'";
	$r = db_query($q, $machineName);
	if($d = db_fetch_array($r))
		return $d['name'];
	return false;
}

/**
 * Finds human name by given machine name for taxonomy term
 *
 * @param string $machineName - Machine readable name for term
 */
function tax_getHumanName($machineName) {
	static $map;

	if(!$map) {
		$q = "SELECT t.tid, t.name, t.description FROM {term_data} t ".
			"WHERE t.name != ''";
		$r = db_query($q);
		$map = array();
		while($d = db_fetch_array($r)){
        	$map[$d['description']] = $d['name'];
		}
	}

	return $map[$machineName];
}

/**
 * Finds machine name by given human name for taxonomy term
 *
 * @param string $humanName - Human readable name for term
 */
function tax_getMachineName_sql($humanName) {
	$q = "SELECT t.description FROM {term_data} t " .
		"WHERE t.name = '%s'";
	$r = db_query($q, $humanName);
	if($d = db_fetch_array($r))
		return $d['description'];
	return false;
}

/**
 * Finds machine name by given human name for taxonomy term
 *
 * @param string $humanName - Human readable name for term
 */
function tax_getMachineName($humanName) {
	static $map;

	if(!$map) {
		$q = "SELECT t.tid, t.name, t.description FROM {term_data} t ".
			"WHERE t.name != ''";
		$r = db_query($q);
		$map = array();
		while($d = db_fetch_array($r)){
        	$map[$d['name']] = $d['description'];
		}
	}

	return $map[$humanName];
}

//added jc
function get_first_paragraph($text){
	/*
	 * get first paragraph of body for an unpaid teaser - unless it's a byline
	 * in which case get paragraph after that as well swiped regex from
	 * mnifilter to find byline
	 */

	// first truncate at 400 chars in case it can't find breaks
	$text = substr($text, 0, 400);
	$text = preg_replace('/^--([^\n]*)/', "\n", $text);
	$text = preg_replace('/\\n--([^\n]*)/', "\n", $text);
	// i think this is always at end of stories so may not need?
	$text = preg_replace('/\\n\[TOPICS:[^\n]*/', "\n", $text);
	$t = explode("\n\n", ltrim($text));
	if(!$t[0]){
		//$text;
		// no paragraphs, return nothing - not much point in having it be
		// alacarte if it ever returns whole article
		return "";
	}

	// this is simplified from what they had in mnifilter but theirs didnt
	// work here.  not sure if this will miss some cases
	if($t[1] && preg_match('/^[Bb]y /',$t[0])){
		//byline
		//return "bylinefound:\n".$t[0]."\n\n".$t[1];
		return $t[0]."\n\n".$t[1];
	}else{
		//no byline
		//return "nobyline\n".$t[0];
		return $t[0];
	}
}

// added jc
function set_uc_node_access_feature($product_nid, $article_nid){
	// set ubercart node_access feature - ties the product to the article so
	// buying the product can give user access to the article via acl to avoid
	// this breaking on an update to either ubercart or uc_node_access that
	// could potentially change the schema, this should probably be changed to
	// call drupal_execute on uc_node_access_feature_form instead of going
	// straight to db but it looks like there is a lot of overhead in that
	// form so i'm going with this simple method uc doesn't seem to have any
	// public methods to get this other than the form

	db_query("INSERT INTO {uc_product_features} (nid, fid, description) " .
		"VALUES (%d, '%s', '%s')", $product_nid, 'node_access', '');

	$pfid=db_last_insert_id('uc_product_features', 'pfid');

	db_query("INSERT INTO {uc_node_access_products} (pfid, access_nid) " .
		"VALUES (%d, %d)", $pfid, $article_nid);
}

/**
 * Adds story as a drupal node to our site.
 */
function newstory($head, $body, $taxonomy, $date, $data)
{
	global $mniblogpub_props;
	$cfg = $mniblogpub_props["mniblogpub.php"];

	// Check ContentType
	$pdf_file = null;
	if($data['ContentType'] == "UUSTORY")
		$pdf_file = move_pdf($body);

	// Load data
	$author = loadAuthor();
	$format = loadFormat();
	$status = ($cfg["node.status_published"] == 1);

	$codenums = array();
	$txttbl=0;

	// Load taxonomy data
	foreach ($taxonomy as $key => $value)
	{
		$tt = $value;
		if($cfg["node.taxonomy.load_from"] == "description")
			$tt = tax_getHumanName_sql($value);
		$theterm = taxonomy_get_term_by_name($tt);

		//if($value = "txttbl")
		//	$txttbl = "Text Table";

		foreach ($theterm as $mkey => $mvalue)
		{
			$codenums[] = $mvalue->tid;
		}
	}

	// Basic Data
	$node = array(
		'type'    => $cfg["node.type"],
		'title'   => $head,
		'uid'     => ($cfg["user.use"] == 1 ? $author->uid:3),
		'name'    => ($cfg["user.use"] == 1 ? $author->name:'mnieditor'),
		'status'  => $status,
		'comment' => ($cfg["node.comments"] == 1 ?
			2 : 0),
		'promote' => 1,
		'taxonomy'=> $codenums,
		'revision'=> 1,
		'format'  => 1,
		'body'    => ($data['ContentType'] == "UUSTORY" ? richbody($pdf_file) : $body)
	);

	// Alacarte Specific
	if($cfg["node.type"] == "alacarte_article"){
		$product_nid = newproduct($node, $data);

		$node['body'] = get_first_paragraph($body);
		$node['field_full_body'] = array(0=> array(
			"value"  => $body,
			"format" => $format
		));
		$node['field_product_nid'] = array(0=> array("value" => $product_nid));
		//$node['field_txttbl'] = array(0=> array("value" => $txttbl));
	}

	// Embargo specific
	if($cfg["modules.mnembargo"] && module_exists('mnembargo')) {
		if ($data['mnembargo'] > 0) {
			$node['time_to_pub'] = $data['mnembargo'];
			$node['status'] = 0;
		}
	}

	// Expire Specific
	if($cfg["modules.mnexpire"] && module_exists('mnexpire'))
		$node['time_to_exp'] = $data['mnexpire'];

	if ($format)
		$node['format'] = $format;

	if ($data['ContentType'] == "UUSTORY") {
		if($cfg["rich.type"])
			$node['type'] = $cfg["rich.type"];
		$node['format'] = 3;
	}

	$node = node_submit($node);

	// Final Changes
	if($cfg["date.adjust"] == 1) {
		$node->created = intval($date);
		$node->changed = intval($date);
		if($data['ContentType'] == "UUSTORY")
			$node->files[$pdf_file->fid] = $pdf_file;
	}

	// SAVE!
	node_save($node);
	$article_nid = $node->nid;
	//unset($node);

	// Aftermath
	if($cfg["node.type"] == "alacarte_article")
		set_uc_node_access_feature($product_nid, $article_nid);

	return $node;
}

/**
 * Builds a new product node
 *
 * @param node $node - Starting node object to
 * @param array $data - Array of data to add to product
 * @return int - node id of new product node
 */
function newproduct($node, $data)
{
	global $mniblogpub_props;

	$pnode = $node;

	$pnode['type'] = 'product';
	$pnode['comment'] = 0;
	$pnode['sell_price'] = $data['ucprice'];
	$pnode['sku'] = "alacarte";
	$pnode['model'] = "alacarte";
	$pnode['shippable'] = 0;

	$pnode = node_submit($pnode);
	node_save($pnode);
	$pnid = $pnode->nid;
	unset($pnode);

	return $pnid;
}

/**
 * Parses file given by file parameter, and deposits variables found in the
 * file into the other parameters.
 */
function parsenewsmlfile($file, &$headline, &$body, &$codes, &$date, &$data)
{
	global $mniblogpub_props;

	$xml = simplexml_load_file($file);

	if (!isset($xml) || !$xml)
		return false;

	$headline = (string)$xml->nitf->head->title;

	$body = (string)$xml->nitf->body->{'body.content'}->pre;

	$xml->registerXPathNamespace('xn','http://www.xmlnews.org/namespaces/meta#');

	$result = $xml->xpath('//xn:vendorData');
	$special_codes = array();

	foreach ($result as $key => $value)
	{
		$regs = array();

		if (ereg("^MKTNEWS_:Blog Tag=(.*)",$value,$regs)) {
			$codes[] = $regs[1];
		} else if (ereg("^MKTNEWS_:(.*)",$value,$regs)) {
			$d = explode('=',$regs[1]);
			if($d[0] == "Special Code")
				$special_codes[] = $d[1];
			else
				$data[$d[0]] = $d[1];
		}
	}
	$data['Special Code'] = $special_codes;

	if($mniblogpub_props["mniblogpub.php"]["date.adjust"] == 1) {
		$t = $xml->xpath('//xn:publicationTime');
		$t = $t[0];
		$t = substr($t, 0, 4) . "-" . substr($t, 4, 2) . "-"
			. substr($t, 6, 2) . " " . substr($t, 9, 2) . ":"
			. substr($t, 11, 2) . ":" . substr($t, 13, 2);
		$t = strtotime($t);
		if(!$t > 0)
			$t = strtotime("now");

		$date = $t;
	}

	unset($xml);
	unset($result);
	unset($special_codes);

	return true;
}

/**
 * Appends SEO date (nid, link, etc.) to the newsml file specificed, for
 * later use in mniblog or other systems.
 *
 * @param drupal node object $node
 * @param string $filename
 */
function appendSEOData($node, $filename,
  $site_basepath="https://mnines.deutsche-boerse.com")
{
  $ns = "http://www.xmlnews.org/namespaces/meta#";

  try {
    $dom = new DOMDocument();
    $dom->load($filename);

    $root = $dom->documentElement;
    $resTag = $root->getElementsByTagnameNS($ns, "Resource")->item(0);

    $dNID  = "MKTNEWS_:nid=".$node->nid;
    $dLink = "MKTNEWS_:link=".$site_basepath."/".
      drupal_lookup_path("alias", "node/".$node->nid);

    $eNID  = $dom->createElementNS($ns, "vendorData", $dNID);
    $eLink = $dom->createElementNS($ns, "vendorData", $dLink);

    $resTag->appendChild($eNID);
    $resTag->appendChild($eLink);

    $dom->save($filename);
  } catch (Exception $e) {
    print("ERROR: Unable to writeback SEO data to " . $a_loc);
  }
}

/**
 * Provides a list of files to parse. List is compiled differently based
 * on configuration variables. (i.e. folders to check, etc.)
 *
 * @param string $cmdArgs - Arguments to be parsed into a file list
 */
function files_list($cmdArgs)
{
	global $mniblogpub_props;
	$bloghome = $mniblogpub_props["mniblogpub.shared"]["bloghome"];
	$load_setting = $mniblogpub_props["mniblogpub.php"]["load"];
	$files = array();

	$delivery_dir = $mniblogpub_props["mniblogpub.shared"]["delivery"];
	if(!$delivery_dir)
		$delivery_dir = "delivery";

	/*
	 * NOTE: Filenames from command line arguments are expected to NOT include
	 * paths. All files read are from [bloghome]/delivery (cron or py), so
	 * we do not need paths at all, simply names. This shorten-ed filename also
	 * (in theory) lets us do more files in a single run before we hit the max
	 * command length.
	 */

	// Read all Files from dir
	// Meant to be used as a Cron job
	if($load_setting == "file"){
		if($handle = opendir($bloghome."/".$delivery_dir)) {
			while(false !== ($file = readdir($handle)))
				if($file != '.' && $file != "..")
					if(is_file($bloghome."/".$delivery_dir."/".$file)) {
						$files[] = $file;
					} else {
						print("ERROR: Could not open file ".
							$bloghome."/".$delivery_dir."/".$file."\n");
						exit(3);
					}
		} else {
			print("ERROR: Could not open directory " .
				$bloghome."/".$delivery_dir."\n");
			exit(2);
		}

	// Command line args
	// Meant to be used w/ associated .py control file
	}else if($load_setting == "args") {
		if(is_dir($bloghome."/".$delivery_dir)) {
			for($i = 2; $i < count($cmdArgs); $i++) {
				if(is_file($bloghome."/".$delivery_dir."/".$cmdArgs[$i])) {
					$files[] = $cmdArgs[$i];
				} else {
					print("ERROR: Could not open file ".
						$bloghome."/".$delivery_dir."/".$cmdArgs[$i]."\n");
					exit(3);
				}
			}
		} else {
			print("ERROR: Could not open directory " .
				$bloghome."/".$delivery_dir."\n");
			exit(2);
		}
	} else {
		print("ERROR: Invalid load setting in config. " .
				"Please use args or file."."\n");
	}

	return $files;
}

// #############################################################################
//    Script
// #############################################################################
global $user;
$orig_user = $user;
$old_state = session_save_session();
session_save_session(false);
$user = user_load(1);

$bloghome = $mniblogpub_props["mniblogpub.shared"]["bloghome"];
$load_setting = $mniblogpub_props["mniblogpub.php"]["load"];
$delivery_dir = $mniblogpub_props["mniblogpub.shared"]["delivery"];
$archive_dir = $mniblogpub_props["mniblogpub.shared"]["archive"];
$failure_dir = $mniblogpub_props["mniblogpub.shared"]["failure"];
$seo_writeback = $mniblogpub_props["mniblogpub.php"]["seo.writeback"];
$site_basepath = $mniblogpub_props["mniblogpub.php"]["basepath"];

if(!isset($load_setting) || $load_setting == NULL || $load_setting == "")
{
	print("ERROR: No load property found in config. " .
			"Please set to args or file."."\n");
	print_r($load_setting);
	exit(4);
}

if(!isset($seo_writeback) || $seo_writeback == NULL || $seo_writeback == "" ||
  strtolower($seo_writeback) == "false")
{
    $seo_writeback = false;
} else {
    $seo_writeback = true;
}

$files = files_list($argv);

// #############################################################################
//    Primary Loop
// #############################################################################
for($i = 0; $i < count($files); $i++) {
	$file = $files[$i];

	$head = '';
	$body = '';
	$date = '';
	$data = array('ContentType' => 'STORY');
	$codes = array();

	$parse_result = parsenewsmlfile($bloghome."/".$delivery_dir."/".$file,
		&$head, &$body,	&$codes, &$date, &$data);

	$a_loc = $bloghome. "/".
	  ($parse_result ? $archive_dir : $failure_dir)."/".$file;

	rename($bloghome."/".$delivery_dir."/".$file, $a_loc);

	if($parse_result)
		$node = newstory($head, $body, $codes, $date, $data);

	if($seo_writeback)
	    appendSEOData($node, $a_loc, $site_basepath);

	unset($node);
	unset($file);
	unset($head);
	unset($body);
	unset($date);
	unset($date);
	unset($codes);
}

$user = $orig_user;
session_save_session($old_state);


?>
