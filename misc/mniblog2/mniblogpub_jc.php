<?php

// @version: $Id: mniblogpub_jc.php 2337 2011-07-08 15:25:32Z jcerda $

require 'includes/common.inc';
require 'includes/cache.inc';
require 'includes/database.inc';
require 'includes/unicode.inc';
require 'includes/module.inc';
require 'modules/node/node.module';
require 'modules/user/user.module';
require 'modules/filter/filter.module';
//added jc
require 'sites/all/modules/acl/acl.module';
require 'sites/all/modules/cck/content.module';


require_once 'includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

/* unused jc
function newstory($head, $body, $taxonomy)
{
	global $user;

	$codenums = array();

	foreach ($taxonomy as $key => $value)
	{
		$theterm = taxonomy_get_term_by_name($value);
		foreach ($theterm as $mkey => $mvalue)
		{
			$codenums[] = $mvalue->tid;
		}
	}

	$node = array(
		'type'    => 'story',
		'title'   => $head,
		'uid'     => 3,
		'name'    => $user->name,
		'status'  => 1,
		'comment' => 0,
		'promote' => 1,
		'taxonomy'=> $codenums,
		'revision'=> 1,
		'format'  => 1,
		'body'    => $body
	);


	$node = node_submit($node);
	node_save($node);
	unset($node);
}
*/

function parsenewsmlfile($file, &$headline, &$body, &$codes)
{
    $xml = simplexml_load_file($file);

    if (!isset($xml)) {
        return;
    }

    $headline = $xml->nitf->head->title;

    $body = $xml->nitf->body->{'body.content'}->pre;


    $xml->registerXPathNamespace('xn', 'http://www.xmlnews.org/namespaces/meta#');

    $result = $xml->xpath('//xn:vendorData');

    foreach ($result as $key => $value)
    {
        $regs = array();

        if (ereg("^MKTNEWS_:Blog Tag=(.*)", $value, $regs)) {
            $codes[] = $regs[1];
        }
    }

}

//added jc
function get_first_paragraph($text)
{
    /*
    get first paragraph of body for an unpaid teaser - unless it's a byline in which case get paragraph after that as well
    swiped regex from mnifilter to find byline
    */
    $text = substr($text, 0, 400); //first truncate at 400 chars in case it can't find breaks
    $text = preg_replace('/^--([^\n]*)/', "\n", $text);
    $text = preg_replace('/\\n--([^\n]*)/', "\n", $text);
    $text = preg_replace('/\\n\[TOPICS:[^\n]*/', "\n", $text); //i think this is always at end of stories so may not need?
    $t = explode("\n\n", ltrim($text));
    if(!$t[0]) {
        return ""; //$text; //no paragraphs, return nothing - not much point in having it be alacarte if it ever returns whole article
    }
    if($t[1] && preg_match('/^[Bb]y /', $t[0])) {  //this is simplified from what they had in mnifilter but theirs didnt work here.  not sure if this will miss some cases
        //byline
        //return "bylinefound:\n".$t[0]."\n\n".$t[1];
        return $t[0]."\n\n".$t[1];
    }else{
        //no byline
        //return "nobyline\n".$t[0];
        return $t[0];
    }
}

//added jc
function set_uc_node_access_feature($product_nid, $article_nid)
{
    //set ubercart node_access feature - ties the product to the article so buying the product can give user access to the article via acl
    //to avoid this breaking on an update to either ubercart or uc_node_access that could potentially change the schema,
    //this should probably be changed to call drupal_execute on uc_node_access_feature_form instead of going straight to db
    //but it looks like there is a lot of overhead in that form so i'm going with this simple method
    //uc doesn't seem to have any public methods to get this other than the form

    db_query(
        "INSERT INTO {uc_product_features} (nid, fid, description) VALUES (%d, '%s', '%s')",
        $product_nid, 'node_access', ''
    );

    $pfid=db_last_insert_id('uc_product_features', 'pfid');

    db_query(
        "INSERT INTO {uc_node_access_products} (pfid, access_nid) VALUES (%d, %d)",
        $pfid, $article_nid
    );

}

//added jc
function get_type($taxonomy)
{
    /*
    if it has 'alacarte' then its alacarte_article
    if it has any of mainwire,fibullets,fxbullets,credit,cobullets,eqbullets,fxpackage,fipackage then its subscription_article
    otherwise free_article

    note that this version only returns first match, assuming multiple passes of this script (or different versions of it) on multiple time delayed versions of stories.  rewrite if this script needs to process articles into all matching types
    */
    if(in_array('alacarte', $taxonomy)) {
        return 'alacarte_article';
    }
    if(array_intersect(array('mainwire','fibullets','fxbullets','credit','cobullets','eqbullets','fxpackage','fipackage'), $taxonomy)) {
        return 'subscription_article';
    }
    return 'free_article';
}

//added jc
//processes subscription articles and free articles but not alacarte
function newstory_type($head, $body, $taxonomy,$type)
{
    global $user;

    $codenums = array();
    $txttbl=0;

    foreach ($taxonomy as $key => $value)
    {
        $theterm = taxonomy_get_term_by_name($value);
        if($theterm="txttbl") { //TODO confirm this term name
            $txttbl="Text Table";
        }
        foreach ($theterm as $mkey => $mvalue)
        {
            $codenums[] = $mvalue->tid;
        }
    }

    $node = array(
    'type'    => $type,
    'title'   => $head,
    'uid'     => $user->uid,
    'name'    => $user->name,
    'status'  => 1,
    'comment' => 2,
    'promote' => 1,
    'taxonomy'=> $codenums,
    'revision'=> 1,
    'format'  => 1,
    'body'    => $body
    'field_txttbl'   => array(0=> array("value" => $txttbl)),
    );


    $node = node_submit($node);
    node_save($node);
    unset($node);
}

//added jc
//creates ubercart product node, then corresponding article
//article has a limited teaser in body and full body text in a cck field
//article contains an id for the related product
function newstory_alacarte($head, $body, $taxonomy)
{
    global $user;

    $codenums = array();
    $txttbl=0;
    foreach ($taxonomy as $key => $value)
    {
        $theterm = taxonomy_get_term_by_name($value);
        if($theterm="txttbl") { //TODO confirm this term name
            $txttbl="Text Table";
        }
        foreach ($theterm as $mkey => $mvalue)
        {
            $codenums[] = $mvalue->tid;
        }
    }

    //create product node first
    $pnode = array(
    'type'    => 'product',
    'title'   => $head,
    'uid'     => $user->uid,
    'name'    => $user->name,
    'status'  => 1,
    'comment' => 0,
    'promote' => 0,
    'revision'=> 1,
    'format'  => 1,
    'body'    => "",
    'sell_price' => 5, //TODO set price in price handler or a setting that can be edited administratively
    'sku'    => "alacarte",
    'model'    => "alacarte",
    'shippable'    => 0,

    );
    $pnode = node_submit($pnode);
    node_save($pnode);
    $product_nid=$pnode->nid;
    unset($pnode);

    //now create article node
    $node = array(
    'type'    => 'alacarte_article',
    'title'   => $head,
    'uid'     => $user->uid,
    'name'    => $user->name,
    'status'  => 1,
    'comment' => 2,//read / write
    'promote' => 1,
    'taxonomy'=> $codenums,
    'revision'=> 1,
    'format'  => 1,
    'body'    => get_first_paragraph($body),
    'field_full_body'   => array(0=> array("value" => $body)),
    'field_product_nid'   => array(0=> array("value" => $product_nid)) ,
    'field_txttbl'   => array(0=> array("value" => $txttbl)),
    );
    $node = node_submit($node);
    node_save($node);
    $article_nid=$node->nid;
    unset($node);

    set_uc_node_access_feature($product_nid, $article_nid); //associate product with article in ubercart

}


function process_files()
{
    global $user;
    //TODO MNI set to production directories
    //$path_from_root="/usr/local/mniblog/";
    //$path_to_xml_dirs="";
    $path_from_root="/var/www/mninews/";
    $path_to_xml_dirs="test/";

    if ($handle = opendir($path_to_xml_dirs."delivery")) {
        while (false !== ($file = readdir($handle)))
        {
            if ($file == '.') {
                continue;
            }

            if ($file == '..') {
                continue;
            }

            $head = '';
            $body = '';
            $codes = array();

            parsenewsmlfile($path_to_xml_dirs."delivery/".$file, &$head, &$body, &$codes);
            rename($path_to_xml_dirs."delivery/".$file, $path_to_xml_dirs."archive/".$file);

            //edit jc:newstory($head, $body, $codes);
            //added jc
            //TODO MNI please note - i don't know how you want to do this - if there will be multiple copies of this script,
            //or one copy running against multiple time delayed copies of the articles...
            //this is set up to work on a test directory so please edit appropriately
            $type=get_type($codes);
            if($type=='alacarte_article') {
                newstory_alacarte($head, $body, $codes);
            } else {
                newstory_type($head, $body, $codes, $type);
            }
        }
        closedir($handle);
    }
}

//TODO this can be deleted
/*
function process_one_file($file){
	global $user;
	$dirpath="/home/content/q/u/i/quietsites/html/d/archive/"; //test server

		$head = '';
		$body = '';
		$codes = array();

		parsenewsmlfile("archive/".$file, &$head, &$body, &$codes);

		//edit jc:newstory($head, $body, $codes);
		//added jc
		//please note - i don't know how you want to do this - if there will be multiple copies of this script,
		//or one copy running against multiple time delayed copies of the articles...
		//this assumes that there are multiple copies of the script running and doesn't address the delivery and archive directories above
		if(get_type($codes)=='alacarte_article'){
			newstory_alacarte($head, $body, $codes);
		} else {
			newstory_type($head, $body, $codes, $type);
		}


}
*/

global $user;

session_save_session(false);

$user = user_load(array('name' => 'feed'));

process_files();


?>
