<?php

# @author: Jeremy Cerda
# @version: $Id: mndelete.php 2337 2011-07-08 15:25:32Z jcerda $

include 'includes/common.inc';
include 'includes/cache.inc';
include 'includes/database.inc';
include 'includes/unicode.inc';
include 'includes/module.inc';
include 'modules/node/node.module';
include 'modules/user/user.module';
include 'modules/filter/filter.module';

require_once('includes/bootstrap.inc');
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

$query = "SELECT nid FROM {node} WHERE type = 'news_item' AND created < 1293796799";
$results = db_query($query);

while($r = db_fetch_array($results)) {
	print $r['nid']."\n";
	node_delete($r['nid']);
}

?>
