<?php

$view = new view();
$view->name = 'ems2015_policy_papers';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'EMS2015 - Policy Papers';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Policy Papers';
$handler->display->display_options['use_ajax'] = TRUE;
$handler->display->display_options['use_more_always'] = TRUE;
$handler->display->display_options['use_more_text'] = 'View all';
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '5';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['style_options']['default_row_class'] = FALSE;
$handler->display->display_options['style_options']['row_class_special'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
/* Footer: Global: Text area */
$handler->display->display_options['footer']['area']['id'] = 'area';
$handler->display->display_options['footer']['area']['table'] = 'views';
$handler->display->display_options['footer']['area']['field'] = 'area';
$handler->display->display_options['footer']['area']['content'] = '<div class="more-link"><a href="/policy-papers">See All Papers</a></div>';
$handler->display->display_options['footer']['area']['format'] = 'filtered_html';
/* Field: Content: File */
$handler->display->display_options['fields']['field_policy_file']['id'] = 'field_policy_file';
$handler->display->display_options['fields']['field_policy_file']['table'] = 'field_data_field_policy_file';
$handler->display->display_options['fields']['field_policy_file']['field'] = 'field_policy_file';
$handler->display->display_options['fields']['field_policy_file']['label'] = '';
$handler->display->display_options['fields']['field_policy_file']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_policy_file']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_policy_file']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_policy_file']['delta_offset'] = '0';
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['path'] = '[field_policy_file]';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
/* Field: Content: Post date */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'node';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['label'] = '';
$handler->display->display_options['fields']['created']['exclude'] = TRUE;
$handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['created']['date_format'] = 'custom';
$handler->display->display_options['fields']['created']['custom_date_format'] = 'F j, Y';
/* Field: Content: Region */
$handler->display->display_options['fields']['field_policy_region']['id'] = 'field_policy_region';
$handler->display->display_options['fields']['field_policy_region']['table'] = 'field_data_field_policy_region';
$handler->display->display_options['fields']['field_policy_region']['field'] = 'field_policy_region';
$handler->display->display_options['fields']['field_policy_region']['label'] = '';
$handler->display->display_options['fields']['field_policy_region']['element_type'] = '0';
$handler->display->display_options['fields']['field_policy_region']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_policy_region']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_policy_region']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_policy_region']['type'] = 'taxonomy_term_reference_plain';
$handler->display->display_options['fields']['field_policy_region']['delta_offset'] = '0';
/* Sort criterion: Content: Updated date */
$handler->display->display_options['sorts']['changed']['id'] = 'changed';
$handler->display->display_options['sorts']['changed']['table'] = 'node';
$handler->display->display_options['sorts']['changed']['field'] = 'changed';
$handler->display->display_options['sorts']['changed']['order'] = 'DESC';
$handler->display->display_options['sorts']['changed']['granularity'] = 'minute';
/* Sort criterion: Content: Post date */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'node';
$handler->display->display_options['sorts']['created']['field'] = 'created';
$handler->display->display_options['sorts']['created']['order'] = 'DESC';
$handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
);
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
    'policy_paper' => 'policy_paper',
);
$handler->display->display_options['filters']['type']['group'] = 1;
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 1;
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: Region (field_policy_region) (selective) */
$handler->display->display_options['filters']['field_policy_region_tid_selective']['id'] = 'field_policy_region_tid_selective';
$handler->display->display_options['filters']['field_policy_region_tid_selective']['table'] = 'field_data_field_policy_region';
$handler->display->display_options['filters']['field_policy_region_tid_selective']['field'] = 'field_policy_region_tid_selective';
$handler->display->display_options['filters']['field_policy_region_tid_selective']['ui_name'] = 'Region (field_policy_region) (selective)';
$handler->display->display_options['filters']['field_policy_region_tid_selective']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_policy_region_tid_selective']['expose']['operator_id'] = '';
$handler->display->display_options['filters']['field_policy_region_tid_selective']['expose']['label'] = 'Region';
$handler->display->display_options['filters']['field_policy_region_tid_selective']['expose']['use_operator'] = TRUE;
$handler->display->display_options['filters']['field_policy_region_tid_selective']['expose']['operator_label'] = 'Region';
$handler->display->display_options['filters']['field_policy_region_tid_selective']['expose']['identifier'] = 'field_policy_region_tid_selective';
$handler->display->display_options['filters']['field_policy_region_tid_selective']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
);
$handler->display->display_options['filters']['field_policy_region_tid_selective']['selective_display_field'] = 'field_policy_region';
$handler->display->display_options['filters']['field_policy_region_tid_selective']['selective_items_limit'] = '100';
/* Filter criterion: Content: Region (field_policy_region) */
$handler->display->display_options['filters']['field_policy_region_tid']['id'] = 'field_policy_region_tid';
$handler->display->display_options['filters']['field_policy_region_tid']['table'] = 'field_data_field_policy_region';
$handler->display->display_options['filters']['field_policy_region_tid']['field'] = 'field_policy_region_tid';
$handler->display->display_options['filters']['field_policy_region_tid']['value'] = array(
    6 => '6',
    9 => '9',
    2 => '2',
    4 => '4',
    3 => '3',
    7 => '7',
    8 => '8',
);
$handler->display->display_options['filters']['field_policy_region_tid']['type'] = 'select';
$handler->display->display_options['filters']['field_policy_region_tid']['vocabulary'] = 'region';

/* Display: Policy Papers */
$handler = $view->new_display('block', 'Policy Papers', 'policy_papers');
$handler->display->display_options['defaults']['query'] = FALSE;
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['distinct'] = TRUE;
$handler->display->display_options['defaults']['exposed_form'] = FALSE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
$handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
);
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
    'policy_paper' => 'policy_paper',
);
$handler->display->display_options['filters']['type']['group'] = 1;
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 1;
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: Region (field_policy_region) (selective) */
$handler->display->display_options['filters']['field_policy_region_tid_selective']['id'] = 'field_policy_region_tid_selective';
$handler->display->display_options['filters']['field_policy_region_tid_selective']['table'] = 'field_data_field_policy_region';
$handler->display->display_options['filters']['field_policy_region_tid_selective']['field'] = 'field_policy_region_tid_selective';
$handler->display->display_options['filters']['field_policy_region_tid_selective']['ui_name'] = 'Region (field_policy_region) (selective)';
$handler->display->display_options['filters']['field_policy_region_tid_selective']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_policy_region_tid_selective']['expose']['operator_id'] = '';
$handler->display->display_options['filters']['field_policy_region_tid_selective']['expose']['label'] = 'Region';
$handler->display->display_options['filters']['field_policy_region_tid_selective']['expose']['use_operator'] = TRUE;
$handler->display->display_options['filters']['field_policy_region_tid_selective']['expose']['operator_label'] = 'Region';
$handler->display->display_options['filters']['field_policy_region_tid_selective']['expose']['identifier'] = 'field_policy_region_tid_selective';
$handler->display->display_options['filters']['field_policy_region_tid_selective']['expose']['remember_roles'] = array(
    2 => '2',
    3 => '3',
    1 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
);
$handler->display->display_options['filters']['field_policy_region_tid_selective']['selective_display_field'] = 'field_policy_region';
$handler->display->display_options['filters']['field_policy_region_tid_selective']['selective_items_limit'] = '100';
/* Filter criterion: Content: Region (field_policy_region) */
$handler->display->display_options['filters']['field_policy_region_tid']['id'] = 'field_policy_region_tid';
$handler->display->display_options['filters']['field_policy_region_tid']['table'] = 'field_data_field_policy_region';
$handler->display->display_options['filters']['field_policy_region_tid']['field'] = 'field_policy_region_tid';
$handler->display->display_options['filters']['field_policy_region_tid']['value'] = array(
    6 => '6',
    9 => '9',
    2 => '2',
    4 => '4',
    3 => '3',
    7 => '7',
    8 => '8',
);
$handler->display->display_options['filters']['field_policy_region_tid']['type'] = 'select';
$handler->display->display_options['filters']['field_policy_region_tid']['vocabulary'] = 'region';
$handler->display->display_options['block_description'] = 'EMS2015 - Policy Papers';
$translatables['ems2015_policy_papers'] = array(
    t('Master'),
    t('Policy Papers'),
    t('View all'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('<div class="more-link"><a href="/policy-papers">See All Papers</a></div>'),
    t('Region'),
    t('more'),
    t('EMS2015 - Policy Papers'),
);