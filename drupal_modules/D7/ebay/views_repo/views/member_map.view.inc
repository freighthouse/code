<?php

$view = new view();
$view->name = 'member_map';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'Member Map';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Member Map';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['style_plugin'] = 'openlayers_map';
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
/* Field: Location: City */
$handler->display->display_options['fields']['city']['id'] = 'city';
$handler->display->display_options['fields']['city']['table'] = 'location';
$handler->display->display_options['fields']['city']['field'] = 'city';
/* Field: Location: Coordinates */
$handler->display->display_options['fields']['coordinates']['id'] = 'coordinates';
$handler->display->display_options['fields']['coordinates']['table'] = 'location';
$handler->display->display_options['fields']['coordinates']['field'] = 'coordinates';
/* Field: Location: Latitude */
$handler->display->display_options['fields']['latitude']['id'] = 'latitude';
$handler->display->display_options['fields']['latitude']['table'] = 'location';
$handler->display->display_options['fields']['latitude']['field'] = 'latitude';
/* Field: Location: Longitude */
$handler->display->display_options['fields']['longitude']['id'] = 'longitude';
$handler->display->display_options['fields']['longitude']['table'] = 'location';
$handler->display->display_options['fields']['longitude']['field'] = 'longitude';
/* Sort criterion: Content: Post date */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'node';
$handler->display->display_options['sorts']['created']['field'] = 'created';
$handler->display->display_options['sorts']['created']['order'] = 'DESC';
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 1;
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
    'member' => 'member',
);

/* Display: NSBW Page */
$handler = $view->new_display('page', 'NSBW Page', 'page');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = '<none>';
$handler->display->display_options['defaults']['header'] = FALSE;
/* Header: Map Header */
$handler->display->display_options['header']['area']['id'] = 'area';
$handler->display->display_options['header']['area']['table'] = 'views';
$handler->display->display_options['header']['area']['field'] = 'area';
$handler->display->display_options['header']['area']['ui_name'] = 'Map Header';
$handler->display->display_options['header']['area']['content'] = '<div class="map-header">
<div class="secondary">
<p>
<!--[if lt IE 9 ]>
  <img class="ebay-brand-rev" alt="eBay Inc" src="/sites/default/files/ebay_inc_rev.png" />
<![endif]-->
<!--[if gte IE 9]><!-->
  <img class="ebay-brand-rev" alt="eBay Inc" src="/sites/default/files/ebay_inc_rev.svg" />
<!--<![endif]-->
</p>

<p>Celebrates</p>
<p class="remains-visible">
<!--[if lt IE 9 ]>
  <img class="nsbw-logo" alt="National Small Business Week" class="remains-visible" src="/sites/default/files/small-biz-week-logo.png" />
<![endif]-->
<!--[if gte IE 9]><!-->
  <img class="nsbw-logo" alt="National Small Business Week" class="remains-visible" src="/sites/default/files/small-biz-week-logo.svg" />
<!--<![endif]-->
</p>

<p class="dates">May 12-16 2014</p>
</div>

<div class="primary">
<h1 class="map-title">See the Faces Behind America’s Tech-Enabled Small Businesses</h1>

<p>Every day, eBay Inc. provides a platform for American entrepreneurs to connect with customers around the world while supporting themselves and their local communities. That’s what the American spirit is all about, and that’s why we’re excited to celebrate National Small Business Week. Join us in honoring the men and women who comprise the backbone of our economy. Take a week to celebrate small businesses around the country and give them your support.</p>
</div>
</div>
';
$handler->display->display_options['header']['area']['format'] = 'full_html';
/* Header: Map Instructions */
$handler->display->display_options['header']['area_1']['id'] = 'area_1';
$handler->display->display_options['header']['area_1']['table'] = 'views';
$handler->display->display_options['header']['area_1']['field'] = 'area';
$handler->display->display_options['header']['area_1']['ui_name'] = 'Map Instructions';
$handler->display->display_options['header']['area_1']['content'] = '<div class="map-instructions">
<h2>Click on the map to read their stories</h2>
<p>Read Small Business Success Stories and \'Like\' Your Favorites on Facebook</p>
<div id="fb-root"></div>
<script>(function(d, s, id) {
  var js, fjs = d.getElementsByTagName(s)[0];
  if (d.getElementById(id)) return;
  js = d.createElement(s); js.id = id;
  js.src = "//connect.facebook.net/en_US/sdk.js#xfbml=1&appId=750325064997358&version=v2.0";
  fjs.parentNode.insertBefore(js, fjs);
}(document, \'script\', \'facebook-jssdk\'));</script>
<div class="fb-like" data-width="300" data-layout="button_count" data-action="like" data-show-faces="false" data-share="false"></div>
</div>';
$handler->display->display_options['header']['area_1']['format'] = 'full_html';
$handler->display->display_options['metatags'] = array(
    'title' => array(
        'value' => 'See the Faces Behind America’s Small Online Businesses | [site:name]',
    ),
    'robots' => array(
        'value' => array(
            'index' => 0,
            'follow' => 0,
            'noindex' => 0,
            'nofollow' => 0,
            'noarchive' => 0,
            'nosnippet' => 0,
            'noodp' => 0,
            'noydir' => 0,
            'noimageindex' => 0,
            'notranslate' => 0,
        ),
    ),
);
$handler->display->display_options['path'] = 'nsbw';

/* Display: Block */
$handler = $view->new_display('block', 'Block', 'block');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Read More Small Business Success Stories';
$handler->display->display_options['block_description'] = 'Member Map Block';

/* Display: OpenLayers Data Overlay */
$handler = $view->new_display('openlayers', 'OpenLayers Data Overlay', 'openlayers_1');
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'openlayers_data';
$handler->display->display_options['style_options']['data_source'] = array(
    'value' => 'wkt',
    'other_lat' => 'title',
    'other_lon' => 'title',
    'wkt' => 'field_member_geofield',
    'other_top' => 'title',
    'other_right' => 'title',
    'other_bottom' => 'title',
    'other_left' => 'title',
    'name_field' => '',
    'description_field' => '#row',
    'style_field' => '',
);
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Path */
$handler->display->display_options['fields']['path']['id'] = 'path';
$handler->display->display_options['fields']['path']['table'] = 'node';
$handler->display->display_options['fields']['path']['field'] = 'path';
$handler->display->display_options['fields']['path']['label'] = '';
$handler->display->display_options['fields']['path']['exclude'] = TRUE;
$handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
/* Field: Content: Photo */
$handler->display->display_options['fields']['field_member_photo']['id'] = 'field_member_photo';
$handler->display->display_options['fields']['field_member_photo']['table'] = 'field_data_field_member_photo';
$handler->display->display_options['fields']['field_member_photo']['field'] = 'field_member_photo';
$handler->display->display_options['fields']['field_member_photo']['label'] = '';
$handler->display->display_options['fields']['field_member_photo']['element_type'] = '0';
$handler->display->display_options['fields']['field_member_photo']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_member_photo']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_member_photo']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_member_photo']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_member_photo']['settings'] = array(
    'image_style' => '50x50',
    'image_link' => 'content',
);
$handler->display->display_options['fields']['field_member_photo']['field_api_classes'] = TRUE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_type'] = 'p';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
/* Field: Content: Geofield */
$handler->display->display_options['fields']['field_member_geofield']['id'] = 'field_member_geofield';
$handler->display->display_options['fields']['field_member_geofield']['table'] = 'field_data_field_member_geofield';
$handler->display->display_options['fields']['field_member_geofield']['field'] = 'field_member_geofield';
$handler->display->display_options['fields']['field_member_geofield']['label'] = '';
$handler->display->display_options['fields']['field_member_geofield']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_member_geofield']['element_type'] = '0';
$handler->display->display_options['fields']['field_member_geofield']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_member_geofield']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_member_geofield']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_member_geofield']['click_sort_column'] = 'geom';
$handler->display->display_options['fields']['field_member_geofield']['settings'] = array(
    'data' => 'centroid',
);
/* Field: Content: Address */
$handler->display->display_options['fields']['field_member_address']['id'] = 'field_member_address';
$handler->display->display_options['fields']['field_member_address']['table'] = 'field_data_field_member_address';
$handler->display->display_options['fields']['field_member_address']['field'] = 'field_member_address';
$handler->display->display_options['fields']['field_member_address']['label'] = '';
$handler->display->display_options['fields']['field_member_address']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_member_address']['alter']['text'] = '[field_member_photo]
[field_member_address]';
$handler->display->display_options['fields']['field_member_address']['element_type'] = '0';
$handler->display->display_options['fields']['field_member_address']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_member_address']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_member_address']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_member_address']['click_sort_column'] = 'country';
$handler->display->display_options['fields']['field_member_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
        'address' => 'address',
    ),
);
$handler->display->display_options['fields']['field_member_address']['field_api_classes'] = TRUE;
/* Field: Content: Business Name */
$handler->display->display_options['fields']['field_member_business_name']['id'] = 'field_member_business_name';
$handler->display->display_options['fields']['field_member_business_name']['table'] = 'field_data_field_member_business_name';
$handler->display->display_options['fields']['field_member_business_name']['field'] = 'field_member_business_name';
$handler->display->display_options['fields']['field_member_business_name']['label'] = '';
$handler->display->display_options['fields']['field_member_business_name']['element_type'] = '0';
$handler->display->display_options['fields']['field_member_business_name']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_member_business_name']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_member_business_name']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_member_business_name']['field_api_classes'] = TRUE;

/* Display: Global Trade Page */
$handler = $view->new_display('page', 'Global Trade Page', 'page_1');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = '<none>';
$handler->display->display_options['defaults']['header'] = FALSE;
/* Header: Map Header */
$handler->display->display_options['header']['area']['id'] = 'area';
$handler->display->display_options['header']['area']['table'] = 'views';
$handler->display->display_options['header']['area']['field'] = 'area';
$handler->display->display_options['header']['area']['ui_name'] = 'Map Header';
$handler->display->display_options['header']['area']['content'] = '<div class="map-header">
<div class="secondary">
<p>
<!--[if lt IE 9 ]>
  <img class="ebay-brand-rev" alt="eBay Inc" src="/sites/default/files/ebay_inc_rev.png" />
<![endif]-->
<!--[if gte IE 9]><!-->
  <img class="ebay-brand-rev" alt="eBay Inc" src="/sites/default/files/ebay_inc_rev.svg" />
<!--<![endif]-->
</p>

<p>Celebrates</p>
<p class="remains-visible">
<!--[if lt IE 9 ]>
  <img class="nsbw-logo" alt="World Trade" class="remains-visible" src="/sites/default/files/world-trade-logo.png" />
<![endif]-->
<!--[if gte IE 9]><!-->
  <img class="nsbw-logo" alt="World Trade" class="remains-visible" src="/sites/default/files/world-trade-logo.svg" />
<!--<![endif]-->
</p>

</div>
<div class="primary">
<h1 class="map-title">Tech-enabled Businesses Play a Key Role in Global Commerce </h1>

<p>Technology and digital marketplaces have completely revolutionized commerce and created opportunities for businesses of all sizes – including small businesses – to access new consumers and new opportunities across the globe. Every day, eBay, PayPal, and the entire eBay Inc. family provide the tools for American entrepreneurs to reach new markets while supporting themselves and their local communities. We are proud that <strong>over 90% of U.S. businesses using eBay.com export to an average of 30 countries</strong> and that’s why we’re excited to celebrate small business exporters. Join us in celebrating the men and women who are changing the face of global commerce. </p>
</div>
</div>
';
$handler->display->display_options['header']['area']['format'] = 'full_html';
/* Header: Map Instructions */
$handler->display->display_options['header']['area_1']['id'] = 'area_1';
$handler->display->display_options['header']['area_1']['table'] = 'views';
$handler->display->display_options['header']['area_1']['field'] = 'area';
$handler->display->display_options['header']['area_1']['ui_name'] = 'Map Instructions';
$handler->display->display_options['header']['area_1']['content'] = '<div class="map-instructions">
<h2>Click on the map to read their stories</h2>
<p>Read Small Business Success Stories and \'Like\' Your Favorites on Facebook</p>
<div id="fb-root"></div>
<script>(function(d, s, id) {
  var js, fjs = d.getElementsByTagName(s)[0];
  if (d.getElementById(id)) return;
  js = d.createElement(s); js.id = id;
  js.src = "//connect.facebook.net/en_US/sdk.js#xfbml=1&appId=750325064997358&version=v2.0";
  fjs.parentNode.insertBefore(js, fjs);
}(document, \'script\', \'facebook-jssdk\'));</script>
<div class="fb-like" data-width="300" data-layout="button_count" data-action="like" data-show-faces="false" data-share="false"></div>
</div>';
$handler->display->display_options['header']['area_1']['format'] = 'full_html';
$handler->display->display_options['metatags'] = array(
    'title' => array(
        'value' => 'Tech-enabled Businesses Play a Key Role in Global Commerce',
    ),
);
$handler->display->display_options['path'] = 'global-trade';
$translatables['member_map'] = array(
    t('Master'),
    t('Member Map'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('City'),
    t('Coordinates'),
    t('Latitude'),
    t('Longitude'),
    t('NSBW Page'),
    t('<none>'),
    t('<div class="map-header">
<div class="secondary">
<p>
<!--[if lt IE 9 ]>
  <img class="ebay-brand-rev" alt="eBay Inc" src="/sites/default/files/ebay_inc_rev.png" />
<![endif]-->
<!--[if gte IE 9]><!-->
  <img class="ebay-brand-rev" alt="eBay Inc" src="/sites/default/files/ebay_inc_rev.svg" />
<!--<![endif]-->
</p>

<p>Celebrates</p>
<p class="remains-visible">
<!--[if lt IE 9 ]>
  <img class="nsbw-logo" alt="National Small Business Week" class="remains-visible" src="/sites/default/files/small-biz-week-logo.png" />
<![endif]-->
<!--[if gte IE 9]><!-->
  <img class="nsbw-logo" alt="National Small Business Week" class="remains-visible" src="/sites/default/files/small-biz-week-logo.svg" />
<!--<![endif]-->
</p>

<p class="dates">May 12-16 2014</p>
</div>

<div class="primary">
<h1 class="map-title">See the Faces Behind America’s Tech-Enabled Small Businesses</h1>

<p>Every day, eBay Inc. provides a platform for American entrepreneurs to connect with customers around the world while supporting themselves and their local communities. That’s what the American spirit is all about, and that’s why we’re excited to celebrate National Small Business Week. Join us in honoring the men and women who comprise the backbone of our economy. Take a week to celebrate small businesses around the country and give them your support.</p>
</div>
</div>
'),
    t('<div class="map-instructions">
<h2>Click on the map to read their stories</h2>
<p>Read Small Business Success Stories and \'Like\' Your Favorites on Facebook</p>
<div id="fb-root"></div>
<script>(function(d, s, id) {
  var js, fjs = d.getElementsByTagName(s)[0];
  if (d.getElementById(id)) return;
  js = d.createElement(s); js.id = id;
  js.src = "//connect.facebook.net/en_US/sdk.js#xfbml=1&appId=750325064997358&version=v2.0";
  fjs.parentNode.insertBefore(js, fjs);
}(document, \'script\', \'facebook-jssdk\'));</script>
<div class="fb-like" data-width="300" data-layout="button_count" data-action="like" data-show-faces="false" data-share="false"></div>
</div>'),
    t('Block'),
    t('Read More Small Business Success Stories'),
    t('Member Map Block'),
    t('OpenLayers Data Overlay'),
    t('[field_member_photo]
[field_member_address]'),
    t('Global Trade Page'),
    t('<div class="map-header">
<div class="secondary">
<p>
<!--[if lt IE 9 ]>
  <img class="ebay-brand-rev" alt="eBay Inc" src="/sites/default/files/ebay_inc_rev.png" />
<![endif]-->
<!--[if gte IE 9]><!-->
  <img class="ebay-brand-rev" alt="eBay Inc" src="/sites/default/files/ebay_inc_rev.svg" />
<!--<![endif]-->
</p>

<p>Celebrates</p>
<p class="remains-visible">
<!--[if lt IE 9 ]>
  <img class="nsbw-logo" alt="World Trade" class="remains-visible" src="/sites/default/files/world-trade-logo.png" />
<![endif]-->
<!--[if gte IE 9]><!-->
  <img class="nsbw-logo" alt="World Trade" class="remains-visible" src="/sites/default/files/world-trade-logo.svg" />
<!--<![endif]-->
</p>

</div>
<div class="primary">
<h1 class="map-title">Tech-enabled Businesses Play a Key Role in Global Commerce </h1>

<p>Technology and digital marketplaces have completely revolutionized commerce and created opportunities for businesses of all sizes – including small businesses – to access new consumers and new opportunities across the globe. Every day, eBay, PayPal, and the entire eBay Inc. family provide the tools for American entrepreneurs to reach new markets while supporting themselves and their local communities. We are proud that <strong>over 90% of U.S. businesses using eBay.com export to an average of 30 countries</strong> and that’s why we’re excited to celebrate small business exporters. Join us in celebrating the men and women who are changing the face of global commerce. </p>
</div>
</div>
'),
);