#!/usr/bin/php
<?php

# @version $Id: chartupdate.php 2337 2011-07-08 15:25:32Z jcerda $

include 'includes/common.inc';
include 'includes/cache.inc';
include 'includes/database.inc';
include 'includes/unicode.inc';
include 'includes/module.inc';
include 'includes/database.mysql-common.inc';
include 'includes/database.mysqli.inc';
include 'modules/node/node.module';
include 'modules/user/user.module';
include 'modules/block/block.module';
//include 'modules/filter/filter.module';

require_once('includes/bootstrap.inc');
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

#Config set up!
$local_image_directory = "/var/www/apache2-default/sites/all/themes/mni/images/cod/";
$image_directory = "/sites/all/themes/mni/images/cod/";
$thumb_bid = 6;
$fullimage_bid = 8;
$username = "clef";

if(count($argv) > 1) {
	if(!is_file($argv[1])) {
		print "WARN: Invalid config file. - ".$argv[1]."\n";
	} else {
		global $props;
		$props = parse_ini_file($argv[1], true);
		$local_image_directory = $props["chartupdate"]["dir.images.full"];
		$image_directory = $props["chartupdate"]["dir.images.drupal"];
		$thumb_bid = $props["chartupdate"]["bid.thumb"];
		$fullimage_bid = $props["chartupdate"]["bid.image"];
		$username = $props["chartupdate"]["user.name"];
	}
}

global $user;
$user = user_load(array('name' => $username));

try{
	//print "DEBUG--".$local_image_directory . "currentcharttype.txt"."--DEBUG";
	//print "DEBUG--".$local_image_directory .
	//	"current-". $ccidentifier . ".txt"."--DEBUG";
	$cct = file($local_image_directory . "currentcharttype.txt");
	$ccidentifier = trim($cct[0]);

	$chart_type_tid = trim($cct[2]); // 53;
	$chart_type = trim($cct[1]); //"EURO-DOLLAR";
	//print_r($cct);
	$im_locations = file($local_image_directory .
		"current-". $ccidentifier . ".txt");
	//print_r($im_locations);

	//"eurodollar-20090723160931thumb.gif";
	$thumblocation = $image_directory . trim($im_locations[1]);
	$fulllocation = $image_directory . trim($im_locations[0]);
} catch (Exception $e) {
  print "There was a problem in reading the files: " . $e.getMessage();
  exit(9);
}

$body1 = <<<EOT
<a href="?q=chartoftheday"><img src="$thumblocation" alt="Chart of the Day"></a>
<div id="chartcaption"><p><?php

\$chart_type = "$chart_type";
\$taxo_id = $chart_type_tid;
EOT;


$bodyphp = '
unset($output);
$output = "<b>" . $chart_type . "</b>: ";
$list_no = 1;
$sql = "SELECT DISTINCT(n.nid) FROM {node} n INNER JOIN {term_node} tn ON n.nid = tn.nid WHERE tn.tid = $taxo_id AND n.status = 1 ORDER BY n.created DESC ";
$result = db_query_range(db_rewrite_sql($sql), 0, $list_no);
$anode = db_fetch_object($result);
$nodey = node_load($anode->nid);
$body = $nodey->body;
$offs = strpos($body, "COMMENTARY:") + 11;
if ($offs <= 11) //Use first line
{
	$offs = strpos($body, ":");
	$endoffs = strpos($body, "\n");
	if ($offs > $endoffs)
	{
		$offs = 0;
	}
	$output .= trim(substr($body, $offs, $endoffs - $offs));
}
else
{
	$output .= substr($body, $offs);
}
print $output;';

$body2 = <<<EOT
?><a href="?q=chartoftheday">(more)</a></p></div>

<a href="?q=taxonomy/term/1/0/feed"><img alt="RSS" style="float: right; margin-top: -68px; display: inline;" src="/sites/all/themes/mni/images/icon_rss.gif"/></a>
EOT;


//Front-page Block with thumbnail
$fpblock = array(
		'info'    => "Chart of the Day: Thumbnail",
		'format'  => 3,
		'body'    => $body1 . $bodyphp . $body2
	);


block_box_save($fpblock, $thumb_bid);

// Full-size image
$imblock = array(
		'info'    => "Chart of the Day",
		'format'  => 2,
		'body'    => "<img src=\"$fulllocation\" alt=\"Chart of the Day\">"
	);

//print_r($imblock);

block_box_save($imblock, $fullimage_bid);
?>
