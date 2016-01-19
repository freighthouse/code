<?php

include 'includes/session.inc';
include 'modules/node/node.module';
include 'modules/user/user.module';

require_once('includes/bootstrap.inc');
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

$q = "	SELECT n.title, uo.order_total, uo.currency,
		uo.billing_last_name, uo.billing_first_name,
		uo.billing_company, uo.billing_country,
		uo.primary_email
	FROM {uc_order_products} uop
	LEFT JOIN {node} n ON n.nid = uop.nid
	LEFT JOIN {uc_orders} uo ON uo.order_id = uop.order_id
	WHERE uo.order_status = 'completed'
	AND uo.primary_email NOT IN ('markus@reutzel.de',
	'axelschorn@hotmail.com','jcerda@freighthousemedia.com',
	'lmh1023@gmail.com','jz@quietsites.com',
	'patrickmoroney17@yahoo.com','ggg1686@gmail.com',
	'greg.galante@gmail.com','crimp7@gmail.com')
	AND NOT uo.primary_email REGEXP '^.*@marketnews.com'
	AND NOT uo.primary_email REGEXP '^.*@test.com'";

$r = db_query($q);
print "'Story Title','Sale Total','Currency','Last Name','First Name',".
	"'Email','Company','Country'\n";
while($o = db_fetch_object($r)){
	print "'$o->title','$o->order_total','$o->currency',".
		"'$o->billing_last_name','$o->billing_first_name',".
		"'$o->primary_email','$o->billing_company',".
		"'$o->billing_country'\n";
}
?>
