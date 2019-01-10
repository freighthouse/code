<?php

$view = new view();
$view->name = 'pac_homepage_gallery';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'PAC Homepage Gallery';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'PAC Homepage Gallery';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '1';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['row_plugin'] = 'fields';
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_type'] = 'h2';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Content: Body */
$handler->display->display_options['fields']['body']['id'] = 'body';
$handler->display->display_options['fields']['body']['table'] = 'field_data_body';
$handler->display->display_options['fields']['body']['field'] = 'body';
$handler->display->display_options['fields']['body']['label'] = '';
$handler->display->display_options['fields']['body']['element_type'] = 'div';
$handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '240',
);
/* Field: Content: Image */
$handler->display->display_options['fields']['field_pac_event_image']['id'] = 'field_pac_event_image';
$handler->display->display_options['fields']['field_pac_event_image']['table'] = 'field_data_field_pac_event_image';
$handler->display->display_options['fields']['field_pac_event_image']['field'] = 'field_pac_event_image';
$handler->display->display_options['fields']['field_pac_event_image']['label'] = '';
$handler->display->display_options['fields']['field_pac_event_image']['element_type'] = '0';
$handler->display->display_options['fields']['field_pac_event_image']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_pac_event_image']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_pac_event_image']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_pac_event_image']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_pac_event_image']['type'] = 'colorbox';
$handler->display->display_options['fields']['field_pac_event_image']['settings'] = array(
    'colorbox_node_style' => 'headshot__200x200_',
    'colorbox_node_style_first' => '',
    'colorbox_image_style' => 'colorbox_large_800x800_max',
    'colorbox_gallery' => 'post',
    'colorbox_gallery_custom' => '',
    'colorbox_caption' => 'auto',
    'colorbox_caption_custom' => '',
);
$handler->display->display_options['fields']['field_pac_event_image']['delta_offset'] = '0';
$handler->display->display_options['fields']['field_pac_event_image']['field_api_classes'] = TRUE;
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
    'pac_event_highlights' => 'pac_event_highlights',
);

/* Display: PAC Event Highlights - Homepage ANON */
$handler = $view->new_display('block', 'PAC Event Highlights - Homepage ANON', 'block');
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Body */
$handler->display->display_options['fields']['body']['id'] = 'body';
$handler->display->display_options['fields']['body']['table'] = 'field_data_body';
$handler->display->display_options['fields']['body']['field'] = 'body';
$handler->display->display_options['fields']['body']['label'] = '';
$handler->display->display_options['fields']['body']['exclude'] = TRUE;
$handler->display->display_options['fields']['body']['element_type'] = 'div';
$handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '240',
);
/* Field: Content: Image */
$handler->display->display_options['fields']['field_pac_event_image']['id'] = 'field_pac_event_image';
$handler->display->display_options['fields']['field_pac_event_image']['table'] = 'field_data_field_pac_event_image';
$handler->display->display_options['fields']['field_pac_event_image']['field'] = 'field_pac_event_image';
$handler->display->display_options['fields']['field_pac_event_image']['label'] = '';
$handler->display->display_options['fields']['field_pac_event_image']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_pac_event_image']['element_type'] = '0';
$handler->display->display_options['fields']['field_pac_event_image']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_pac_event_image']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_pac_event_image']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_pac_event_image']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_pac_event_image']['type'] = 'colorbox';
$handler->display->display_options['fields']['field_pac_event_image']['settings'] = array(
    'colorbox_node_style' => 'headshot__200x200_',
    'colorbox_node_style_first' => '',
    'colorbox_image_style' => 'colorbox_large_800x800_max',
    'colorbox_gallery' => 'post',
    'colorbox_gallery_custom' => '',
    'colorbox_caption' => 'auto',
    'colorbox_caption_custom' => '',
);
$handler->display->display_options['fields']['field_pac_event_image']['delta_offset'] = '0';
$handler->display->display_options['fields']['field_pac_event_image']['field_api_classes'] = TRUE;
/* Field: Global: Custom text */
$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
$handler->display->display_options['fields']['nothing']['table'] = 'views';
$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing']['label'] = '';
$handler->display->display_options['fields']['nothing']['alter']['text'] = '<h2 class="pac-event-title">PAC Event Highlights</h2>
[body]
<hr class="block-divider" />
[field_pac_event_image] ';
$handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;

/* Display: PAC Event Highlights */
$handler = $view->new_display('block', 'PAC Event Highlights', 'block_1');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'PAC Event Highlights';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Body */
$handler->display->display_options['fields']['body']['id'] = 'body';
$handler->display->display_options['fields']['body']['table'] = 'field_data_body';
$handler->display->display_options['fields']['body']['field'] = 'body';
$handler->display->display_options['fields']['body']['label'] = '';
$handler->display->display_options['fields']['body']['exclude'] = TRUE;
$handler->display->display_options['fields']['body']['element_type'] = 'div';
$handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '240',
);
/* Field: Content: Image */
$handler->display->display_options['fields']['field_pac_event_image']['id'] = 'field_pac_event_image';
$handler->display->display_options['fields']['field_pac_event_image']['table'] = 'field_data_field_pac_event_image';
$handler->display->display_options['fields']['field_pac_event_image']['field'] = 'field_pac_event_image';
$handler->display->display_options['fields']['field_pac_event_image']['label'] = '';
$handler->display->display_options['fields']['field_pac_event_image']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_pac_event_image']['element_type'] = '0';
$handler->display->display_options['fields']['field_pac_event_image']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_pac_event_image']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_pac_event_image']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_pac_event_image']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_pac_event_image']['type'] = 'colorbox';
$handler->display->display_options['fields']['field_pac_event_image']['settings'] = array(
    'colorbox_node_style' => 'headshot__200x200_',
    'colorbox_node_style_first' => '',
    'colorbox_image_style' => 'colorbox_large_800x800_max',
    'colorbox_gallery' => 'post',
    'colorbox_gallery_custom' => '',
    'colorbox_caption' => 'auto',
    'colorbox_caption_custom' => '',
);
$handler->display->display_options['fields']['field_pac_event_image']['delta_offset'] = '0';
$handler->display->display_options['fields']['field_pac_event_image']['field_api_classes'] = TRUE;
/* Field: Global: Custom text */
$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
$handler->display->display_options['fields']['nothing']['table'] = 'views';
$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing']['label'] = '';
$handler->display->display_options['fields']['nothing']['alter']['text'] = '<h2 class="pac-event-title">PAC Event Highlights</h2>
[body]
<hr class="block-divider" />
[field_pac_event_image] ';
$handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
$translatables['pac_homepage_gallery'] = array(
    t('Master'),
    t('PAC Homepage Gallery'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('PAC Event Highlights - Homepage ANON'),
    t('<h2 class="pac-event-title">PAC Event Highlights</h2>
[body]
<hr class="block-divider" />
[field_pac_event_image] '),
    t('PAC Event Highlights'),
);