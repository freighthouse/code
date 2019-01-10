<?php

$view = new view();
$view->name = 'Timeline';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'Timeline';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Timeline';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '1';
$handler->display->display_options['style_plugin'] = 'views_json';
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
/* Field: Content: Summary */
$handler->display->display_options['fields']['field_timeline_summary']['id'] = 'field_timeline_summary';
$handler->display->display_options['fields']['field_timeline_summary']['table'] = 'field_data_field_timeline_summary';
$handler->display->display_options['fields']['field_timeline_summary']['field'] = 'field_timeline_summary';
$handler->display->display_options['fields']['field_timeline_summary']['label'] = '';
$handler->display->display_options['fields']['field_timeline_summary']['element_type'] = '0';
$handler->display->display_options['fields']['field_timeline_summary']['element_label_type'] = '0';
$handler->display->display_options['fields']['field_timeline_summary']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_timeline_summary']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_timeline_summary']['element_default_classes'] = FALSE;
/* Field: Content: Timeline Item */
$handler->display->display_options['fields']['field_timeline_item']['id'] = 'field_timeline_item';
$handler->display->display_options['fields']['field_timeline_item']['table'] = 'field_data_field_timeline_item';
$handler->display->display_options['fields']['field_timeline_item']['field'] = 'field_timeline_item';
$handler->display->display_options['fields']['field_timeline_item']['label'] = '';
$handler->display->display_options['fields']['field_timeline_item']['element_type'] = '0';
$handler->display->display_options['fields']['field_timeline_item']['element_label_type'] = '0';
$handler->display->display_options['fields']['field_timeline_item']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_timeline_item']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_timeline_item']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_timeline_item']['settings'] = array(
    'view_mode' => 'full',
);
$handler->display->display_options['fields']['field_timeline_item']['delta_offset'] = '0';
$handler->display->display_options['fields']['field_timeline_item']['field_api_classes'] = TRUE;
/* Field: Content: Start Date */
$handler->display->display_options['fields']['field_timeline_start_date']['id'] = 'field_timeline_start_date';
$handler->display->display_options['fields']['field_timeline_start_date']['table'] = 'field_data_field_timeline_start_date';
$handler->display->display_options['fields']['field_timeline_start_date']['field'] = 'field_timeline_start_date';
$handler->display->display_options['fields']['field_timeline_start_date']['label'] = '';
$handler->display->display_options['fields']['field_timeline_start_date']['element_type'] = '0';
$handler->display->display_options['fields']['field_timeline_start_date']['element_label_type'] = '0';
$handler->display->display_options['fields']['field_timeline_start_date']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_timeline_start_date']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_timeline_start_date']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_timeline_start_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
);
/* Sort criterion: Content: Post date */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'node';
$handler->display->display_options['sorts']['created']['field'] = 'created';
$handler->display->display_options['sorts']['created']['order'] = 'DESC';
/* Contextual filter: Content: Nid */
$handler->display->display_options['arguments']['nid']['id'] = 'nid';
$handler->display->display_options['arguments']['nid']['table'] = 'node';
$handler->display->display_options['arguments']['nid']['field'] = 'nid';
$handler->display->display_options['arguments']['nid']['default_action'] = 'default';
$handler->display->display_options['arguments']['nid']['default_argument_type'] = 'raw';
$handler->display->display_options['arguments']['nid']['default_argument_options']['index'] = '1';
$handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
$handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
$handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'timeline' => 'timeline',
);
$handler->display->display_options['arguments']['nid']['validate_options']['access'] = TRUE;
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
    'timeline' => 'timeline',
);

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'timelines/%/timeline.jsonp';
$translatables['Timeline'] = array(
    t('Master'),
    t('Timeline'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('All'),
    t('Page'),
);