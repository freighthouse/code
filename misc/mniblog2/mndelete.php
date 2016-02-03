<?php

// @author: Jeremy Cerda
// @version: $Id: mndelete.php 2337 2011-07-08 15:25:32Z jcerda $

require 'includes/common.inc';
require 'includes/cache.inc';
require 'includes/database.inc';
require 'includes/unicode.inc';
require 'includes/module.inc';
require 'modules/node/node.module';
require 'modules/user/user.module';
require 'modules/filter/filter.module';

require_once 'includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

$query = "SELECT nid FROM {node} WHERE type = 'news_item' AND created < 1293796799";
$results = db_query($query);

while($r = db_fetch_array($results)) {
    print $r['nid']."\n";
    node_delete($r['nid']);
}

?>
