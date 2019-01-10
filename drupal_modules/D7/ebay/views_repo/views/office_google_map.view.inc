<?php

$view = new view();
$view->name = 'office_google_map';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'Offices';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Global Offices';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '0';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['style_plugin'] = 'gmap';
$handler->display->display_options['style_options']['markertype'] = 'green';
$handler->display->display_options['style_options']['latfield'] = 'title';
$handler->display->display_options['style_options']['lonfield'] = 'title';
$handler->display->display_options['style_options']['markerfield'] = 'title';
$handler->display->display_options['style_options']['enablermt'] = 0;
$handler->display->display_options['style_options']['rmtfield'] = 'title';
$handler->display->display_options['style_options']['tooltipfield'] = 'title';
$handler->display->display_options['style_options']['bubbletextenabled'] = 1;
$handler->display->display_options['style_options']['bubbletextfield'] = 'title';
$handler->display->display_options['row_plugin'] = 'fields';
/* Header: Global: Text area */
$handler->display->display_options['header']['area']['id'] = 'area';
$handler->display->display_options['header']['area']['table'] = 'views';
$handler->display->display_options['header']['area']['field'] = 'area';
$handler->display->display_options['header']['area']['content'] = 'You can find eBay Inc. Government Relations staff in the following cities. Select a region at the top of the page to learn about eBay Inc.\'s international policy interests.';
$handler->display->display_options['header']['area']['format'] = 'filtered_html';
/* Field: Location: Address */
$handler->display->display_options['fields']['address']['id'] = 'address';
$handler->display->display_options['fields']['address']['table'] = 'location';
$handler->display->display_options['fields']['address']['field'] = 'address';
$handler->display->display_options['fields']['address']['label'] = '';
$handler->display->display_options['fields']['address']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['address']['hide'] = array(
    'locpick' => 'locpick',
    'map_link' => 'map_link',
    'coords' => 'coords',
    'name' => 0,
    'street' => 0,
    'additional' => 0,
    'city' => 0,
    'province' => 0,
    'postal_code' => 0,
    'country' => 0,
    'phone' => 0,
    'province_name' => 0,
    'country_name' => 0,
);
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
/* Sort criterion: Content: Post date */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'node';
$handler->display->display_options['sorts']['created']['field'] = 'created';
$handler->display->display_options['sorts']['created']['order'] = 'DESC';
/* Sort criterion: Content: Title */
$handler->display->display_options['sorts']['title']['id'] = 'title';
$handler->display->display_options['sorts']['title']['table'] = 'node';
$handler->display->display_options['sorts']['title']['field'] = 'title';
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 1;
$handler->display->display_options['filters']['status']['group'] = 0;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
    'office' => 'office',
);

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Location: Address */
$handler->display->display_options['fields']['address']['id'] = 'address';
$handler->display->display_options['fields']['address']['table'] = 'location';
$handler->display->display_options['fields']['address']['field'] = 'address';
$handler->display->display_options['fields']['address']['label'] = '';
$handler->display->display_options['fields']['address']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['address']['hide'] = array(
    'name' => 'name',
    'street' => 'street',
    'additional' => 'additional',
    'city' => 'city',
    'province' => 'province',
    'postal_code' => 'postal_code',
    'locpick' => 'locpick',
    'map_link' => 'map_link',
    'coords' => 'coords',
    'country' => 0,
    'phone' => 0,
    'province_name' => 0,
    'country_name' => 0,
);
$handler->display->display_options['path'] = 'offices';
$handler->display->display_options['menu']['type'] = 'normal';
$handler->display->display_options['menu']['title'] = 'Global Offices';
$handler->display->display_options['menu']['description'] = 'eBay Inc. Global Government Relations Offices';
$handler->display->display_options['menu']['weight'] = '0';
$handler->display->display_options['menu']['name'] = 'main-menu';

/* Display: Block */
$handler = $view->new_display('block', 'Block', 'block_1');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Government Relations Team Locations ';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['style_options']['row_class'] = 'office';
$handler->display->display_options['style_options']['default_row_class'] = FALSE;
$handler->display->display_options['style_options']['row_class_special'] = FALSE;
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['header'] = FALSE;
/* Header: Global: Text area */
$handler->display->display_options['header']['area']['id'] = 'area';
$handler->display->display_options['header']['area']['table'] = 'views';
$handler->display->display_options['header']['area']['field'] = 'area';
$handler->display->display_options['header']['area']['format'] = 'filtered_html';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['element_type'] = 'h4';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Location: Address */
$handler->display->display_options['fields']['address']['id'] = 'address';
$handler->display->display_options['fields']['address']['table'] = 'location';
$handler->display->display_options['fields']['address']['field'] = 'address';
$handler->display->display_options['fields']['address']['label'] = '';
$handler->display->display_options['fields']['address']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['address']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['address']['hide'] = array(
    'name' => 'name',
    'street' => 'street',
    'additional' => 'additional',
    'city' => 'city',
    'province' => 'province',
    'postal_code' => 'postal_code',
    'locpick' => 'locpick',
    'map_link' => 'map_link',
    'coords' => 'coords',
    'country' => 0,
    'phone' => 0,
    'province_name' => 0,
    'country_name' => 0,
);
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: Content: Title */
$handler->display->display_options['sorts']['title']['id'] = 'title';
$handler->display->display_options['sorts']['title']['table'] = 'node';
$handler->display->display_options['sorts']['title']['field'] = 'title';
$translatables['office_google_map'] = array(
    t('Master'),
    t('Global Offices'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('You can find eBay Inc. Government Relations staff in the following cities. Select a region at the top of the page to learn about eBay Inc.\'s international policy interests.'),
    t('Title'),
    t('Page'),
    t('Block'),
    t('Government Relations Team Locations '),
);