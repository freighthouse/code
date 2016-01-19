<?php
# @author: Jeremy Cerda
# @version: $Id: mncoremetrics.util.inc 2598 2011-09-12 20:29:04Z jcerda $

function mncoremetrics_load_cfg($filename = "mncoremetrics.cfg") {
	variable_set('mncoremetrics_setup_cfg', 1);

	$mp = drupal_get_path('module', 'mncoremetrics');
	$cfg = parse_ini_file($mp.'/'.$filename, true);

	variable_set('mncoremetrics_src',
		$cfg['mncoremetrics.module']['mncoremetrics_src']);
	variable_set('mncoremetrics_clientid',
		$cfg['mncoremetrics.module']['mncoremetrics_clientid']);
	variable_set('mncoremetrics_clientid.test',
		"6".substr($cfg['mncoremetrics.module']['mncoremetrics_clientid'], 1));
	variable_set('mncoremetrics_testing',
		$cfg['mncoremetrics.module']['mncoremetrics_testing']);

	variable_set('mncoremetrics_domains.test',
		$cfg['mncoremetrics.module']['mncoremetrics_domains.test']);
	variable_set('mncoremetrics_domains.prod',
		$cfg['mncoremetrics.module']['mncoremetrics_domains.prod']);
	variable_set('mncoremetrics_domains.cookie',
		$cfg['mncoremetrics.module']['mncoremetrics_domains.cookie']);

	variable_set('mncoremetrics_setup', 1);
}

function mncoremetrics_load_cdf($filename = "doc/mni_cdf.csv") {
	$ret = cache_get("mncoremetrics_cdf");
	if($ret)
		return $ret->data;

	// Load file
	$mp = drupal_get_path('module', 'mncoremetrics');
	$cat_lines = file($mp."/".$filename);

	// Clean headers
	if(preg_match("/^\"Client_ID\",.*/", $cat_lines[0]))
		array_shift($cat_lines);

	$ret = array();
	//for($i = 0; $i < count($cat_lines); $i++)
	foreach($cat_lines as $line)
	{
		$cols = explode(",", $line);
		if($cols[4] && trim($cols[4]))
			$ret[$cols[1]] = str_replace("\"", "", trim($cols[4]));
	}

	cache_set("mncoremetrics_cdf", $ret, 'cache', CACHE_TEMPORARY);
	$ret = cache_get("mncoremetrics_cdf");
	return $ret->data;
}
