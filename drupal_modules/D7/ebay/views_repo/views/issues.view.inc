<?php

$view = new view();
$view->name = 'issues';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'issues';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Issues';
$handler->display->display_options['use_more_always'] = TRUE;
$handler->display->display_options['use_more_text'] = 'Read more';
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['style_plugin'] = 'list';
$handler->display->display_options['row_plugin'] = 'fields';
/* Header: Global: Text area */
$handler->display->display_options['header']['area']['id'] = 'area';
$handler->display->display_options['header']['area']['table'] = 'views';
$handler->display->display_options['header']['area']['field'] = 'area';
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
/* Field: Content: Body */
$handler->display->display_options['fields']['body']['id'] = 'body';
$handler->display->display_options['fields']['body']['table'] = 'field_data_body';
$handler->display->display_options['fields']['body']['field'] = 'body';
/* Field: Content: Photo */
$handler->display->display_options['fields']['field_issue_photo']['id'] = 'field_issue_photo';
$handler->display->display_options['fields']['field_issue_photo']['table'] = 'field_data_field_issue_photo';
$handler->display->display_options['fields']['field_issue_photo']['field'] = 'field_issue_photo';
/* Field: Content: Summary */
$handler->display->display_options['fields']['field_news_summary']['id'] = 'field_news_summary';
$handler->display->display_options['fields']['field_news_summary']['table'] = 'field_data_field_news_summary';
$handler->display->display_options['fields']['field_news_summary']['field'] = 'field_news_summary';
/* Sort criterion: Content: Post date */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'node';
$handler->display->display_options['sorts']['created']['field'] = 'created';
$handler->display->display_options['sorts']['created']['order'] = 'DESC';
/* Sort criterion: Content: Title */
$handler->display->display_options['sorts']['title']['id'] = 'title';
$handler->display->display_options['sorts']['title']['table'] = 'node';
$handler->display->display_options['sorts']['title']['field'] = 'title';
/* Contextual filter: Content: Region (field_taxonomy_region) */
$handler->display->display_options['arguments']['field_taxonomy_region_tid']['id'] = 'field_taxonomy_region_tid';
$handler->display->display_options['arguments']['field_taxonomy_region_tid']['table'] = 'field_data_field_taxonomy_region';
$handler->display->display_options['arguments']['field_taxonomy_region_tid']['field'] = 'field_taxonomy_region_tid';
$handler->display->display_options['arguments']['field_taxonomy_region_tid']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['field_taxonomy_region_tid']['summary']['format'] = 'default_summary';
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
    'issue' => 'issue',
);
/* Filter criterion: Content: Sticky */
$handler->display->display_options['filters']['sticky']['id'] = 'sticky';
$handler->display->display_options['filters']['sticky']['table'] = 'node';
$handler->display->display_options['filters']['sticky']['field'] = 'sticky';
/* Filter criterion: Content: Language */
$handler->display->display_options['filters']['language']['id'] = 'language';
$handler->display->display_options['filters']['language']['table'] = 'node';
$handler->display->display_options['filters']['language']['field'] = 'language';
$handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
    'und' => 'und',
);
$handler->display->display_options['filters']['language']['group'] = '0';

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Featured Issue';
$handler->display->display_options['defaults']['use_more'] = FALSE;
$handler->display->display_options['defaults']['use_more_always'] = FALSE;
$handler->display->display_options['defaults']['use_more_always'] = FALSE;
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['defaults']['use_more_text'] = FALSE;
$handler->display->display_options['use_more_text'] = 'Read more';
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '1';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['style_options']['default_row_class'] = FALSE;
$handler->display->display_options['style_options']['row_class_special'] = FALSE;
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['hide_empty'] = TRUE;
$handler->display->display_options['row_options']['default_field_elements'] = FALSE;
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
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
/* Field: Content: Photo */
$handler->display->display_options['fields']['field_issue_photo']['id'] = 'field_issue_photo';
$handler->display->display_options['fields']['field_issue_photo']['table'] = 'field_data_field_issue_photo';
$handler->display->display_options['fields']['field_issue_photo']['field'] = 'field_issue_photo';
$handler->display->display_options['fields']['field_issue_photo']['label'] = '';
$handler->display->display_options['fields']['field_issue_photo']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_issue_photo']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_issue_photo']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
);
/* Field: Content: Body */
$handler->display->display_options['fields']['body']['id'] = 'body';
$handler->display->display_options['fields']['body']['table'] = 'field_data_body';
$handler->display->display_options['fields']['body']['field'] = 'body';
$handler->display->display_options['fields']['body']['label'] = '';
$handler->display->display_options['fields']['body']['element_type'] = '0';
$handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['body']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
$handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
);
/* Field: Content: Body */
$handler->display->display_options['fields']['body_1']['id'] = 'body_1';
$handler->display->display_options['fields']['body_1']['table'] = 'field_data_body';
$handler->display->display_options['fields']['body_1']['field'] = 'body';
$handler->display->display_options['fields']['body_1']['label'] = '';
$handler->display->display_options['fields']['body_1']['element_type'] = '0';
$handler->display->display_options['fields']['body_1']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['body_1']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['body_1']['element_default_classes'] = FALSE;
/* Field: Content: Region */
$handler->display->display_options['fields']['field_taxonomy_region']['id'] = 'field_taxonomy_region';
$handler->display->display_options['fields']['field_taxonomy_region']['table'] = 'field_data_field_taxonomy_region';
$handler->display->display_options['fields']['field_taxonomy_region']['field'] = 'field_taxonomy_region';
$handler->display->display_options['fields']['field_taxonomy_region']['label'] = '';
$handler->display->display_options['fields']['field_taxonomy_region']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_taxonomy_region']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_taxonomy_region']['delta_offset'] = '0';
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Contextual filter: Content: Region (field_taxonomy_region) */
$handler->display->display_options['arguments']['field_taxonomy_region_tid']['id'] = 'field_taxonomy_region_tid';
$handler->display->display_options['arguments']['field_taxonomy_region_tid']['table'] = 'field_data_field_taxonomy_region';
$handler->display->display_options['arguments']['field_taxonomy_region_tid']['field'] = 'field_taxonomy_region_tid';
$handler->display->display_options['arguments']['field_taxonomy_region_tid']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['field_taxonomy_region_tid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['field_taxonomy_region_tid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['field_taxonomy_region_tid']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['field_taxonomy_region_tid']['specify_validation'] = TRUE;
$handler->display->display_options['arguments']['field_taxonomy_region_tid']['validate']['type'] = 'taxonomy_term';
$handler->display->display_options['arguments']['field_taxonomy_region_tid']['validate_options']['vocabularies'] = array(
    'region' => 'region',
);
$handler->display->display_options['arguments']['field_taxonomy_region_tid']['validate_options']['type'] = 'convert';
$handler->display->display_options['arguments']['field_taxonomy_region_tid']['validate_options']['transform'] = TRUE;
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
);
$handler->display->display_options['defaults']['filters'] = FALSE;
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
    'issue' => 'issue',
);
$handler->display->display_options['filters']['type']['group'] = 1;
/* Filter criterion: Content: Sticky */
$handler->display->display_options['filters']['sticky']['id'] = 'sticky';
$handler->display->display_options['filters']['sticky']['table'] = 'node';
$handler->display->display_options['filters']['sticky']['field'] = 'sticky';
$handler->display->display_options['filters']['sticky']['value'] = '1';
$handler->display->display_options['filters']['sticky']['group'] = 1;
$handler->display->display_options['path'] = 'issues-old';

/* Display: Sidebar Navigation (All) */
$handler = $view->new_display('block', 'Sidebar Navigation (All)', 'block_6');
$handler->display->display_options['defaults']['use_more'] = FALSE;
$handler->display->display_options['defaults']['use_more_always'] = FALSE;
$handler->display->display_options['defaults']['use_more_always'] = FALSE;
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['defaults']['use_more_text'] = FALSE;
$handler->display->display_options['use_more_text'] = 'Read more';
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '0';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'views_accordion';
$handler->display->display_options['style_options']['default_row_class'] = FALSE;
$handler->display->display_options['style_options']['row_class_special'] = FALSE;
$handler->display->display_options['style_options']['collapsible'] = 1;
$handler->display->display_options['style_options']['row-start-open'] = 'none';
$handler->display->display_options['style_options']['autoheight'] = 0;
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['header'] = FALSE;
/* Header: Global: Text area */
$handler->display->display_options['header']['area']['id'] = 'area';
$handler->display->display_options['header']['area']['table'] = 'views';
$handler->display->display_options['header']['area']['field'] = 'area';
$handler->display->display_options['header']['area']['content'] = 'eBay Inc. Government Relations monitors and is involved with issues affecting the eBay marketplace, PayPal merchants, StubHub users and more.';
$handler->display->display_options['header']['area']['format'] = 'filtered_html';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
/* Field: Content: Body */
$handler->display->display_options['fields']['body']['id'] = 'body';
$handler->display->display_options['fields']['body']['table'] = 'field_data_body';
$handler->display->display_options['fields']['body']['field'] = 'body';
$handler->display->display_options['fields']['body']['label'] = '';
$handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
$handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '250',
);
/* Field: Content: Region */
$handler->display->display_options['fields']['field_taxonomy_region']['id'] = 'field_taxonomy_region';
$handler->display->display_options['fields']['field_taxonomy_region']['table'] = 'field_data_field_taxonomy_region';
$handler->display->display_options['fields']['field_taxonomy_region']['field'] = 'field_taxonomy_region';
$handler->display->display_options['fields']['field_taxonomy_region']['label'] = '';
$handler->display->display_options['fields']['field_taxonomy_region']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_taxonomy_region']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_taxonomy_region']['delta_offset'] = '0';
/* Field: Content: Link */
$handler->display->display_options['fields']['view_node']['id'] = 'view_node';
$handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
$handler->display->display_options['fields']['view_node']['field'] = 'view_node';
$handler->display->display_options['fields']['view_node']['label'] = '';
$handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['view_node']['text'] = 'continue';
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: Content: Title */
$handler->display->display_options['sorts']['title']['id'] = 'title';
$handler->display->display_options['sorts']['title']['table'] = 'node';
$handler->display->display_options['sorts']['title']['field'] = 'title';
$handler->display->display_options['defaults']['arguments'] = FALSE;
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
);
$handler->display->display_options['defaults']['filters'] = FALSE;
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
    'issue' => 'issue',
);
$handler->display->display_options['filters']['type']['group'] = 1;
/* Filter criterion: Content: Region (field_taxonomy_region) */
$handler->display->display_options['filters']['field_taxonomy_region_tid']['id'] = 'field_taxonomy_region_tid';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['table'] = 'field_data_field_taxonomy_region';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['field'] = 'field_taxonomy_region_tid';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['value'] = array(
    1 => '1',
    2 => '2',
    4 => '4',
    3 => '3',
);
$handler->display->display_options['filters']['field_taxonomy_region_tid']['group'] = 1;
$handler->display->display_options['filters']['field_taxonomy_region_tid']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_taxonomy_region_tid']['expose']['operator_id'] = 'field_taxonomy_region_tid_op';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['expose']['label'] = 'Region';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['expose']['operator'] = 'field_taxonomy_region_tid_op';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['expose']['identifier'] = 'field_taxonomy_region_tid';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['expose']['required'] = TRUE;
$handler->display->display_options['filters']['field_taxonomy_region_tid']['reduce_duplicates'] = TRUE;
$handler->display->display_options['filters']['field_taxonomy_region_tid']['type'] = 'select';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['vocabulary'] = 'region';
/* Filter criterion: Content: Language */
$handler->display->display_options['filters']['language']['id'] = 'language';
$handler->display->display_options['filters']['language']['table'] = 'node';
$handler->display->display_options['filters']['language']['field'] = 'language';
$handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
    'und' => 'und',
    'en' => 'en',
);
$handler->display->display_options['filters']['language']['group'] = 1;

/* Display: Featured Issue */
$handler = $view->new_display('block', 'Featured Issue', 'block_2');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Featured Issue';
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '1';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['style_options']['grouping'] = '';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['inline'] = array(
    'body' => 'body',
    'path' => 'path',
);
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['exclude'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
/* Field: Content: Homepage Image */
$handler->display->display_options['fields']['field_issue_homeimage']['id'] = 'field_issue_homeimage';
$handler->display->display_options['fields']['field_issue_homeimage']['table'] = 'field_data_field_issue_homeimage';
$handler->display->display_options['fields']['field_issue_homeimage']['field'] = 'field_issue_homeimage';
$handler->display->display_options['fields']['field_issue_homeimage']['label'] = '';
$handler->display->display_options['fields']['field_issue_homeimage']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_issue_homeimage']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_issue_homeimage']['settings'] = array(
    'image_style' => '',
    'image_link' => 'content',
);
/* Field: Content: Body */
$handler->display->display_options['fields']['body']['id'] = 'body';
$handler->display->display_options['fields']['body']['table'] = 'field_data_body';
$handler->display->display_options['fields']['body']['field'] = 'body';
$handler->display->display_options['fields']['body']['label'] = '';
$handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
$handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
);
/* Field: Content: Path */
$handler->display->display_options['fields']['path']['id'] = 'path';
$handler->display->display_options['fields']['path']['table'] = 'node';
$handler->display->display_options['fields']['path']['field'] = 'path';
$handler->display->display_options['fields']['path']['label'] = '';
$handler->display->display_options['fields']['path']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['path']['alter']['text'] = '<a href="[path]">Read more</a>';
$handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: Content: Post date */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'node';
$handler->display->display_options['sorts']['created']['field'] = 'created';
$handler->display->display_options['sorts']['created']['order'] = 'DESC';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
);
$handler->display->display_options['defaults']['filters'] = FALSE;
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
    'issue' => 'issue',
);
$handler->display->display_options['filters']['type']['group'] = 1;
/* Filter criterion: Content: Sticky */
$handler->display->display_options['filters']['sticky']['id'] = 'sticky';
$handler->display->display_options['filters']['sticky']['table'] = 'node';
$handler->display->display_options['filters']['sticky']['field'] = 'sticky';
$handler->display->display_options['filters']['sticky']['value'] = '1';
$handler->display->display_options['filters']['sticky']['group'] = 1;

/* Display: Featured Issue - (Asia Pacific) */
$handler = $view->new_display('block', 'Featured Issue - (Asia Pacific)', 'block_3');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Featured Issue';
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '1';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['style_options']['grouping'] = '';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['inline'] = array(
    'body' => 'body',
    'path' => 'path',
);
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['exclude'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
/* Field: Content: Homepage Image */
$handler->display->display_options['fields']['field_issue_homeimage']['id'] = 'field_issue_homeimage';
$handler->display->display_options['fields']['field_issue_homeimage']['table'] = 'field_data_field_issue_homeimage';
$handler->display->display_options['fields']['field_issue_homeimage']['field'] = 'field_issue_homeimage';
$handler->display->display_options['fields']['field_issue_homeimage']['label'] = '';
$handler->display->display_options['fields']['field_issue_homeimage']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_issue_homeimage']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_issue_homeimage']['settings'] = array(
    'image_style' => '',
    'image_link' => 'content',
);
/* Field: Content: Body */
$handler->display->display_options['fields']['body']['id'] = 'body';
$handler->display->display_options['fields']['body']['table'] = 'field_data_body';
$handler->display->display_options['fields']['body']['field'] = 'body';
$handler->display->display_options['fields']['body']['label'] = '';
$handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
$handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
);
/* Field: Content: Path */
$handler->display->display_options['fields']['path']['id'] = 'path';
$handler->display->display_options['fields']['path']['table'] = 'node';
$handler->display->display_options['fields']['path']['field'] = 'path';
$handler->display->display_options['fields']['path']['label'] = '';
$handler->display->display_options['fields']['path']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['path']['alter']['text'] = '<a href="[path]">Read more</a>';
$handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: Content: Post date */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'node';
$handler->display->display_options['sorts']['created']['field'] = 'created';
$handler->display->display_options['sorts']['created']['order'] = 'DESC';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
);
$handler->display->display_options['defaults']['filters'] = FALSE;
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
    'issue' => 'issue',
);
$handler->display->display_options['filters']['type']['group'] = 1;
/* Filter criterion: Content: Sticky */
$handler->display->display_options['filters']['sticky']['id'] = 'sticky';
$handler->display->display_options['filters']['sticky']['table'] = 'node';
$handler->display->display_options['filters']['sticky']['field'] = 'sticky';
$handler->display->display_options['filters']['sticky']['value'] = '1';
$handler->display->display_options['filters']['sticky']['group'] = 1;
/* Filter criterion: Content: Region (field_taxonomy_region) */
$handler->display->display_options['filters']['field_taxonomy_region_tid']['id'] = 'field_taxonomy_region_tid';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['table'] = 'field_data_field_taxonomy_region';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['field'] = 'field_taxonomy_region_tid';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['value'] = array(
    2 => '2',
);
$handler->display->display_options['filters']['field_taxonomy_region_tid']['group'] = 1;
$handler->display->display_options['filters']['field_taxonomy_region_tid']['type'] = 'select';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['vocabulary'] = 'region';

/* Display: Featured Issue - (Australia) */
$handler = $view->new_display('block', 'Featured Issue - (Australia)', 'block_4');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Featured Issue';
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '1';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['style_options']['grouping'] = '';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['inline'] = array(
    'body' => 'body',
    'path' => 'path',
);
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['exclude'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
/* Field: Content: Homepage Image */
$handler->display->display_options['fields']['field_issue_homeimage']['id'] = 'field_issue_homeimage';
$handler->display->display_options['fields']['field_issue_homeimage']['table'] = 'field_data_field_issue_homeimage';
$handler->display->display_options['fields']['field_issue_homeimage']['field'] = 'field_issue_homeimage';
$handler->display->display_options['fields']['field_issue_homeimage']['label'] = '';
$handler->display->display_options['fields']['field_issue_homeimage']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_issue_homeimage']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_issue_homeimage']['settings'] = array(
    'image_style' => '',
    'image_link' => 'content',
);
/* Field: Content: Body */
$handler->display->display_options['fields']['body']['id'] = 'body';
$handler->display->display_options['fields']['body']['table'] = 'field_data_body';
$handler->display->display_options['fields']['body']['field'] = 'body';
$handler->display->display_options['fields']['body']['label'] = '';
$handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
$handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
);
/* Field: Content: Path */
$handler->display->display_options['fields']['path']['id'] = 'path';
$handler->display->display_options['fields']['path']['table'] = 'node';
$handler->display->display_options['fields']['path']['field'] = 'path';
$handler->display->display_options['fields']['path']['label'] = '';
$handler->display->display_options['fields']['path']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['path']['alter']['text'] = '<a href="[path]">Read more</a>';
$handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: Content: Post date */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'node';
$handler->display->display_options['sorts']['created']['field'] = 'created';
$handler->display->display_options['sorts']['created']['order'] = 'DESC';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
);
$handler->display->display_options['defaults']['filters'] = FALSE;
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
    'issue' => 'issue',
);
$handler->display->display_options['filters']['type']['group'] = 1;
/* Filter criterion: Content: Sticky */
$handler->display->display_options['filters']['sticky']['id'] = 'sticky';
$handler->display->display_options['filters']['sticky']['table'] = 'node';
$handler->display->display_options['filters']['sticky']['field'] = 'sticky';
$handler->display->display_options['filters']['sticky']['value'] = '1';
$handler->display->display_options['filters']['sticky']['group'] = 1;
/* Filter criterion: Content: Region (field_taxonomy_region) */
$handler->display->display_options['filters']['field_taxonomy_region_tid']['id'] = 'field_taxonomy_region_tid';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['table'] = 'field_data_field_taxonomy_region';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['field'] = 'field_taxonomy_region_tid';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['value'] = array(
    4 => '4',
);
$handler->display->display_options['filters']['field_taxonomy_region_tid']['group'] = 1;
$handler->display->display_options['filters']['field_taxonomy_region_tid']['type'] = 'select';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['vocabulary'] = 'region';

/* Display: Featured Issue - (Europe) */
$handler = $view->new_display('block', 'Featured Issue - (Europe)', 'block_5');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Featured Issue';
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '1';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['style_options']['grouping'] = '';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['inline'] = array(
    'body' => 'body',
    'path' => 'path',
);
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['exclude'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
/* Field: Content: Homepage Image */
$handler->display->display_options['fields']['field_issue_homeimage']['id'] = 'field_issue_homeimage';
$handler->display->display_options['fields']['field_issue_homeimage']['table'] = 'field_data_field_issue_homeimage';
$handler->display->display_options['fields']['field_issue_homeimage']['field'] = 'field_issue_homeimage';
$handler->display->display_options['fields']['field_issue_homeimage']['label'] = '';
$handler->display->display_options['fields']['field_issue_homeimage']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_issue_homeimage']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_issue_homeimage']['settings'] = array(
    'image_style' => '',
    'image_link' => 'content',
);
/* Field: Content: Body */
$handler->display->display_options['fields']['body']['id'] = 'body';
$handler->display->display_options['fields']['body']['table'] = 'field_data_body';
$handler->display->display_options['fields']['body']['field'] = 'body';
$handler->display->display_options['fields']['body']['label'] = '';
$handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
$handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
);
/* Field: Content: Path */
$handler->display->display_options['fields']['path']['id'] = 'path';
$handler->display->display_options['fields']['path']['table'] = 'node';
$handler->display->display_options['fields']['path']['field'] = 'path';
$handler->display->display_options['fields']['path']['label'] = '';
$handler->display->display_options['fields']['path']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['path']['alter']['text'] = '<a href="[path]">Read more</a>';
$handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: Content: Post date */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'node';
$handler->display->display_options['sorts']['created']['field'] = 'created';
$handler->display->display_options['sorts']['created']['order'] = 'DESC';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
);
$handler->display->display_options['defaults']['filters'] = FALSE;
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
    'issue' => 'issue',
);
$handler->display->display_options['filters']['type']['group'] = 1;
/* Filter criterion: Content: Sticky */
$handler->display->display_options['filters']['sticky']['id'] = 'sticky';
$handler->display->display_options['filters']['sticky']['table'] = 'node';
$handler->display->display_options['filters']['sticky']['field'] = 'sticky';
$handler->display->display_options['filters']['sticky']['value'] = '1';
$handler->display->display_options['filters']['sticky']['group'] = 1;
/* Filter criterion: Content: Region (field_taxonomy_region) */
$handler->display->display_options['filters']['field_taxonomy_region_tid']['id'] = 'field_taxonomy_region_tid';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['table'] = 'field_data_field_taxonomy_region';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['field'] = 'field_taxonomy_region_tid';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['value'] = array(
    3 => '3',
);
$handler->display->display_options['filters']['field_taxonomy_region_tid']['group'] = 1;
$handler->display->display_options['filters']['field_taxonomy_region_tid']['type'] = 'select';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['vocabulary'] = 'region';

/* Display: Sidebar Navigation Region-Specific fixed */
$handler = $view->new_display('block', 'Sidebar Navigation Region-Specific fixed', 'block_7');
$handler->display->display_options['defaults']['use_more'] = FALSE;
$handler->display->display_options['defaults']['use_more_always'] = FALSE;
$handler->display->display_options['defaults']['use_more_always'] = FALSE;
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['defaults']['use_more_text'] = FALSE;
$handler->display->display_options['use_more_text'] = 'Read more';
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'views_accordion';
$handler->display->display_options['style_options']['grouping'] = '';
$handler->display->display_options['style_options']['collapsible'] = 1;
$handler->display->display_options['style_options']['row-start-open'] = 'none';
$handler->display->display_options['style_options']['autoheight'] = 0;
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['header'] = FALSE;
/* Header: Global: Text area */
$handler->display->display_options['header']['area']['id'] = 'area';
$handler->display->display_options['header']['area']['table'] = 'views';
$handler->display->display_options['header']['area']['field'] = 'area';
$handler->display->display_options['header']['area']['content'] = 'eBay Inc. Government Relations monitors and is involved with issues affecting the eBay marketplace, PayPal merchants, StubHub users and more.';
$handler->display->display_options['header']['area']['format'] = 'filtered_html';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
/* Field: Content: Body */
$handler->display->display_options['fields']['body']['id'] = 'body';
$handler->display->display_options['fields']['body']['table'] = 'field_data_body';
$handler->display->display_options['fields']['body']['field'] = 'body';
$handler->display->display_options['fields']['body']['label'] = '';
$handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
$handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '250',
);
/* Field: Content: Region */
$handler->display->display_options['fields']['field_taxonomy_region']['id'] = 'field_taxonomy_region';
$handler->display->display_options['fields']['field_taxonomy_region']['table'] = 'field_data_field_taxonomy_region';
$handler->display->display_options['fields']['field_taxonomy_region']['field'] = 'field_taxonomy_region';
$handler->display->display_options['fields']['field_taxonomy_region']['label'] = '';
$handler->display->display_options['fields']['field_taxonomy_region']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_taxonomy_region']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_taxonomy_region']['delta_offset'] = '0';
/* Field: Content: Link */
$handler->display->display_options['fields']['view_node']['id'] = 'view_node';
$handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
$handler->display->display_options['fields']['view_node']['field'] = 'view_node';
$handler->display->display_options['fields']['view_node']['label'] = '';
$handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['view_node']['text'] = 'continue';
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: Content: Title */
$handler->display->display_options['sorts']['title']['id'] = 'title';
$handler->display->display_options['sorts']['title']['table'] = 'node';
$handler->display->display_options['sorts']['title']['field'] = 'title';
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Contextual filter: Content: Has taxonomy term ID */
$handler->display->display_options['arguments']['tid']['id'] = 'tid';
$handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
$handler->display->display_options['arguments']['tid']['field'] = 'tid';
$handler->display->display_options['arguments']['tid']['default_action'] = 'default';
$handler->display->display_options['arguments']['tid']['default_argument_type'] = 'taxonomy_tid';
$handler->display->display_options['arguments']['tid']['default_argument_options']['term_page'] = FALSE;
$handler->display->display_options['arguments']['tid']['default_argument_options']['node'] = TRUE;
$handler->display->display_options['arguments']['tid']['default_argument_options']['anyall'] = '+';
$handler->display->display_options['arguments']['tid']['default_argument_options']['limit'] = TRUE;
$handler->display->display_options['arguments']['tid']['default_argument_options']['vocabularies'] = array(
    'region' => 'region',
);
$handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
/* Contextual filter: Content: Nid */
$handler->display->display_options['arguments']['nid']['id'] = 'nid';
$handler->display->display_options['arguments']['nid']['table'] = 'node';
$handler->display->display_options['arguments']['nid']['field'] = 'nid';
$handler->display->display_options['arguments']['nid']['default_action'] = 'default';
$handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
$handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['nid']['not'] = TRUE;
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
);
$handler->display->display_options['defaults']['filters'] = FALSE;
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
    'issue' => 'issue',
);
$handler->display->display_options['filters']['type']['group'] = 1;
/* Filter criterion: Content: Language */
$handler->display->display_options['filters']['language']['id'] = 'language';
$handler->display->display_options['filters']['language']['table'] = 'node';
$handler->display->display_options['filters']['language']['field'] = 'language';
$handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
    'und' => 'und',
);
$handler->display->display_options['filters']['language']['group'] = 1;

/* Display: Sidebar Navigation (US) */
$handler = $view->new_display('block', 'Sidebar Navigation (US)', 'block_8');
$handler->display->display_options['defaults']['use_more'] = FALSE;
$handler->display->display_options['defaults']['use_more_always'] = FALSE;
$handler->display->display_options['defaults']['use_more_always'] = FALSE;
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['defaults']['use_more_text'] = FALSE;
$handler->display->display_options['use_more_text'] = 'Read more';
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '0';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'views_accordion';
$handler->display->display_options['style_options']['default_row_class'] = FALSE;
$handler->display->display_options['style_options']['row_class_special'] = FALSE;
$handler->display->display_options['style_options']['collapsible'] = 1;
$handler->display->display_options['style_options']['row-start-open'] = 'none';
$handler->display->display_options['style_options']['autoheight'] = 0;
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['header'] = FALSE;
/* Header: Global: Text area */
$handler->display->display_options['header']['area']['id'] = 'area';
$handler->display->display_options['header']['area']['table'] = 'views';
$handler->display->display_options['header']['area']['field'] = 'area';
$handler->display->display_options['header']['area']['content'] = 'eBay Inc. Government Relations monitors and is involved with issues affecting the eBay marketplace, PayPal merchants, StubHub users and more.';
$handler->display->display_options['header']['area']['format'] = 'filtered_html';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
/* Field: Content: Body */
$handler->display->display_options['fields']['body']['id'] = 'body';
$handler->display->display_options['fields']['body']['table'] = 'field_data_body';
$handler->display->display_options['fields']['body']['field'] = 'body';
$handler->display->display_options['fields']['body']['label'] = '';
$handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
$handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '250',
);
/* Field: Content: Region */
$handler->display->display_options['fields']['field_taxonomy_region']['id'] = 'field_taxonomy_region';
$handler->display->display_options['fields']['field_taxonomy_region']['table'] = 'field_data_field_taxonomy_region';
$handler->display->display_options['fields']['field_taxonomy_region']['field'] = 'field_taxonomy_region';
$handler->display->display_options['fields']['field_taxonomy_region']['label'] = '';
$handler->display->display_options['fields']['field_taxonomy_region']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_taxonomy_region']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_taxonomy_region']['delta_offset'] = '0';
/* Field: Content: Link */
$handler->display->display_options['fields']['view_node']['id'] = 'view_node';
$handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
$handler->display->display_options['fields']['view_node']['field'] = 'view_node';
$handler->display->display_options['fields']['view_node']['label'] = '';
$handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['view_node']['text'] = 'continue';
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: Content: Title */
$handler->display->display_options['sorts']['title']['id'] = 'title';
$handler->display->display_options['sorts']['title']['table'] = 'node';
$handler->display->display_options['sorts']['title']['field'] = 'title';
$handler->display->display_options['defaults']['arguments'] = FALSE;
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
);
$handler->display->display_options['defaults']['filters'] = FALSE;
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
    'issue' => 'issue',
);
$handler->display->display_options['filters']['type']['group'] = 1;
/* Filter criterion: Content: Region (field_taxonomy_region) */
$handler->display->display_options['filters']['field_taxonomy_region_tid']['id'] = 'field_taxonomy_region_tid';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['table'] = 'field_data_field_taxonomy_region';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['field'] = 'field_taxonomy_region_tid';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['value'] = array(
    1 => '1',
);
$handler->display->display_options['filters']['field_taxonomy_region_tid']['group'] = 1;
$handler->display->display_options['filters']['field_taxonomy_region_tid']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_taxonomy_region_tid']['expose']['operator_id'] = 'field_taxonomy_region_tid_op';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['expose']['label'] = 'Region';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['expose']['operator'] = 'field_taxonomy_region_tid_op';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['expose']['identifier'] = 'field_taxonomy_region_tid';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['expose']['required'] = TRUE;
$handler->display->display_options['filters']['field_taxonomy_region_tid']['reduce_duplicates'] = TRUE;
$handler->display->display_options['filters']['field_taxonomy_region_tid']['type'] = 'select';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['vocabulary'] = 'region';
/* Filter criterion: Content: Language */
$handler->display->display_options['filters']['language']['id'] = 'language';
$handler->display->display_options['filters']['language']['table'] = 'node';
$handler->display->display_options['filters']['language']['field'] = 'language';
$handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
    'und' => 'und',
    'en' => 'en',
);
$handler->display->display_options['filters']['language']['group'] = 1;

/* Display: Sidebar Navigation (Europe) */
$handler = $view->new_display('block', 'Sidebar Navigation (Europe)', 'block_9');
$handler->display->display_options['defaults']['use_more'] = FALSE;
$handler->display->display_options['defaults']['use_more_always'] = FALSE;
$handler->display->display_options['defaults']['use_more_always'] = FALSE;
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['defaults']['use_more_text'] = FALSE;
$handler->display->display_options['use_more_text'] = 'Read more';
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '0';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'views_accordion';
$handler->display->display_options['style_options']['grouping'] = '';
$handler->display->display_options['style_options']['collapsible'] = 1;
$handler->display->display_options['style_options']['row-start-open'] = 'none';
$handler->display->display_options['style_options']['autoheight'] = 0;
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['header'] = FALSE;
/* Header: Global: Text area */
$handler->display->display_options['header']['area']['id'] = 'area';
$handler->display->display_options['header']['area']['table'] = 'views';
$handler->display->display_options['header']['area']['field'] = 'area';
$handler->display->display_options['header']['area']['content'] = 'eBay Inc. Government Relations monitors and is involved with issues affecting the eBay marketplace, PayPal merchants, StubHub users and more.';
$handler->display->display_options['header']['area']['format'] = 'filtered_html';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
/* Field: Content: Body */
$handler->display->display_options['fields']['body']['id'] = 'body';
$handler->display->display_options['fields']['body']['table'] = 'field_data_body';
$handler->display->display_options['fields']['body']['field'] = 'body';
$handler->display->display_options['fields']['body']['label'] = '';
$handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
$handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '250',
);
/* Field: Content: Region */
$handler->display->display_options['fields']['field_taxonomy_region']['id'] = 'field_taxonomy_region';
$handler->display->display_options['fields']['field_taxonomy_region']['table'] = 'field_data_field_taxonomy_region';
$handler->display->display_options['fields']['field_taxonomy_region']['field'] = 'field_taxonomy_region';
$handler->display->display_options['fields']['field_taxonomy_region']['label'] = '';
$handler->display->display_options['fields']['field_taxonomy_region']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_taxonomy_region']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_taxonomy_region']['delta_offset'] = '0';
/* Field: Content: Link */
$handler->display->display_options['fields']['view_node']['id'] = 'view_node';
$handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
$handler->display->display_options['fields']['view_node']['field'] = 'view_node';
$handler->display->display_options['fields']['view_node']['label'] = '';
$handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['view_node']['text'] = 'continue';
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: Content: Title */
$handler->display->display_options['sorts']['title']['id'] = 'title';
$handler->display->display_options['sorts']['title']['table'] = 'node';
$handler->display->display_options['sorts']['title']['field'] = 'title';
$handler->display->display_options['defaults']['arguments'] = FALSE;
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
);
$handler->display->display_options['defaults']['filters'] = FALSE;
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
    'issue' => 'issue',
);
$handler->display->display_options['filters']['type']['group'] = 1;
/* Filter criterion: Content: Region (field_taxonomy_region) */
$handler->display->display_options['filters']['field_taxonomy_region_tid']['id'] = 'field_taxonomy_region_tid';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['table'] = 'field_data_field_taxonomy_region';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['field'] = 'field_taxonomy_region_tid';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['value'] = array(
    3 => '3',
);
$handler->display->display_options['filters']['field_taxonomy_region_tid']['group'] = 1;
$handler->display->display_options['filters']['field_taxonomy_region_tid']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_taxonomy_region_tid']['expose']['operator_id'] = 'field_taxonomy_region_tid_op';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['expose']['label'] = 'Region';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['expose']['operator'] = 'field_taxonomy_region_tid_op';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['expose']['identifier'] = 'field_taxonomy_region_tid';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['expose']['required'] = TRUE;
$handler->display->display_options['filters']['field_taxonomy_region_tid']['reduce_duplicates'] = TRUE;
$handler->display->display_options['filters']['field_taxonomy_region_tid']['type'] = 'select';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['vocabulary'] = 'region';
/* Filter criterion: Content: Language */
$handler->display->display_options['filters']['language']['id'] = 'language';
$handler->display->display_options['filters']['language']['table'] = 'node';
$handler->display->display_options['filters']['language']['field'] = 'language';
$handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
    'und' => 'und',
    'en' => 'en',
);
$handler->display->display_options['filters']['language']['group'] = 1;

/* Display: Sidebar Navigation (Asia) */
$handler = $view->new_display('block', 'Sidebar Navigation (Asia)', 'block_11');
$handler->display->display_options['defaults']['use_more'] = FALSE;
$handler->display->display_options['defaults']['use_more_always'] = FALSE;
$handler->display->display_options['defaults']['use_more_always'] = FALSE;
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['defaults']['use_more_text'] = FALSE;
$handler->display->display_options['use_more_text'] = 'Read more';
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '0';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'views_accordion';
$handler->display->display_options['style_options']['grouping'] = '';
$handler->display->display_options['style_options']['collapsible'] = 1;
$handler->display->display_options['style_options']['row-start-open'] = 'none';
$handler->display->display_options['style_options']['autoheight'] = 0;
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['header'] = FALSE;
/* Header: Global: Text area */
$handler->display->display_options['header']['area']['id'] = 'area';
$handler->display->display_options['header']['area']['table'] = 'views';
$handler->display->display_options['header']['area']['field'] = 'area';
$handler->display->display_options['header']['area']['content'] = 'eBay Inc. Government Relations monitors and is involved with issues affecting the eBay marketplace, PayPal merchants, StubHub users and more.';
$handler->display->display_options['header']['area']['format'] = 'filtered_html';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
/* Field: Content: Body */
$handler->display->display_options['fields']['body']['id'] = 'body';
$handler->display->display_options['fields']['body']['table'] = 'field_data_body';
$handler->display->display_options['fields']['body']['field'] = 'body';
$handler->display->display_options['fields']['body']['label'] = '';
$handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
$handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '250',
);
/* Field: Content: Region */
$handler->display->display_options['fields']['field_taxonomy_region']['id'] = 'field_taxonomy_region';
$handler->display->display_options['fields']['field_taxonomy_region']['table'] = 'field_data_field_taxonomy_region';
$handler->display->display_options['fields']['field_taxonomy_region']['field'] = 'field_taxonomy_region';
$handler->display->display_options['fields']['field_taxonomy_region']['label'] = '';
$handler->display->display_options['fields']['field_taxonomy_region']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_taxonomy_region']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_taxonomy_region']['delta_offset'] = '0';
/* Field: Content: Link */
$handler->display->display_options['fields']['view_node']['id'] = 'view_node';
$handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
$handler->display->display_options['fields']['view_node']['field'] = 'view_node';
$handler->display->display_options['fields']['view_node']['label'] = '';
$handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['view_node']['text'] = 'continue';
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: Content: Title */
$handler->display->display_options['sorts']['title']['id'] = 'title';
$handler->display->display_options['sorts']['title']['table'] = 'node';
$handler->display->display_options['sorts']['title']['field'] = 'title';
$handler->display->display_options['defaults']['arguments'] = FALSE;
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
);
$handler->display->display_options['defaults']['filters'] = FALSE;
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
    'issue' => 'issue',
);
$handler->display->display_options['filters']['type']['group'] = 1;
/* Filter criterion: Content: Region (field_taxonomy_region) */
$handler->display->display_options['filters']['field_taxonomy_region_tid']['id'] = 'field_taxonomy_region_tid';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['table'] = 'field_data_field_taxonomy_region';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['field'] = 'field_taxonomy_region_tid';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['value'] = array(
    2 => '2',
);
$handler->display->display_options['filters']['field_taxonomy_region_tid']['group'] = 1;
$handler->display->display_options['filters']['field_taxonomy_region_tid']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_taxonomy_region_tid']['expose']['operator_id'] = 'field_taxonomy_region_tid_op';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['expose']['label'] = 'Region';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['expose']['operator'] = 'field_taxonomy_region_tid_op';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['expose']['identifier'] = 'field_taxonomy_region_tid';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['expose']['required'] = TRUE;
$handler->display->display_options['filters']['field_taxonomy_region_tid']['reduce_duplicates'] = TRUE;
$handler->display->display_options['filters']['field_taxonomy_region_tid']['type'] = 'select';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['vocabulary'] = 'region';
/* Filter criterion: Content: Language */
$handler->display->display_options['filters']['language']['id'] = 'language';
$handler->display->display_options['filters']['language']['table'] = 'node';
$handler->display->display_options['filters']['language']['field'] = 'language';
$handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
    'und' => 'und',
    'en' => 'en',
);
$handler->display->display_options['filters']['language']['group'] = 1;

/* Display: Sidebar Navigation (Australia) */
$handler = $view->new_display('block', 'Sidebar Navigation (Australia)', 'block_12');
$handler->display->display_options['defaults']['use_more'] = FALSE;
$handler->display->display_options['defaults']['use_more_always'] = FALSE;
$handler->display->display_options['defaults']['use_more_always'] = FALSE;
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['defaults']['use_more_text'] = FALSE;
$handler->display->display_options['use_more_text'] = 'Read more';
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '0';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'views_accordion';
$handler->display->display_options['style_options']['grouping'] = '';
$handler->display->display_options['style_options']['collapsible'] = 1;
$handler->display->display_options['style_options']['row-start-open'] = 'none';
$handler->display->display_options['style_options']['autoheight'] = 0;
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['header'] = FALSE;
/* Header: Global: Text area */
$handler->display->display_options['header']['area']['id'] = 'area';
$handler->display->display_options['header']['area']['table'] = 'views';
$handler->display->display_options['header']['area']['field'] = 'area';
$handler->display->display_options['header']['area']['content'] = 'eBay Inc. Government Relations monitors and is involved with issues affecting the eBay marketplace, PayPal merchants, StubHub users and more.';
$handler->display->display_options['header']['area']['format'] = 'filtered_html';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
/* Field: Content: Body */
$handler->display->display_options['fields']['body']['id'] = 'body';
$handler->display->display_options['fields']['body']['table'] = 'field_data_body';
$handler->display->display_options['fields']['body']['field'] = 'body';
$handler->display->display_options['fields']['body']['label'] = '';
$handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
$handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '250',
);
/* Field: Content: Region */
$handler->display->display_options['fields']['field_taxonomy_region']['id'] = 'field_taxonomy_region';
$handler->display->display_options['fields']['field_taxonomy_region']['table'] = 'field_data_field_taxonomy_region';
$handler->display->display_options['fields']['field_taxonomy_region']['field'] = 'field_taxonomy_region';
$handler->display->display_options['fields']['field_taxonomy_region']['label'] = '';
$handler->display->display_options['fields']['field_taxonomy_region']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_taxonomy_region']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_taxonomy_region']['delta_offset'] = '0';
/* Field: Content: Link */
$handler->display->display_options['fields']['view_node']['id'] = 'view_node';
$handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
$handler->display->display_options['fields']['view_node']['field'] = 'view_node';
$handler->display->display_options['fields']['view_node']['label'] = '';
$handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['view_node']['text'] = 'continue';
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: Content: Title */
$handler->display->display_options['sorts']['title']['id'] = 'title';
$handler->display->display_options['sorts']['title']['table'] = 'node';
$handler->display->display_options['sorts']['title']['field'] = 'title';
$handler->display->display_options['defaults']['arguments'] = FALSE;
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
);
$handler->display->display_options['defaults']['filters'] = FALSE;
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
    'issue' => 'issue',
);
$handler->display->display_options['filters']['type']['group'] = 1;
/* Filter criterion: Content: Region (field_taxonomy_region) */
$handler->display->display_options['filters']['field_taxonomy_region_tid']['id'] = 'field_taxonomy_region_tid';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['table'] = 'field_data_field_taxonomy_region';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['field'] = 'field_taxonomy_region_tid';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['value'] = array(
    4 => '4',
);
$handler->display->display_options['filters']['field_taxonomy_region_tid']['group'] = 1;
$handler->display->display_options['filters']['field_taxonomy_region_tid']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_taxonomy_region_tid']['expose']['operator_id'] = 'field_taxonomy_region_tid_op';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['expose']['label'] = 'Region';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['expose']['operator'] = 'field_taxonomy_region_tid_op';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['expose']['identifier'] = 'field_taxonomy_region_tid';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['expose']['required'] = TRUE;
$handler->display->display_options['filters']['field_taxonomy_region_tid']['reduce_duplicates'] = TRUE;
$handler->display->display_options['filters']['field_taxonomy_region_tid']['type'] = 'select';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['vocabulary'] = 'region';
/* Filter criterion: Content: Language */
$handler->display->display_options['filters']['language']['id'] = 'language';
$handler->display->display_options['filters']['language']['table'] = 'node';
$handler->display->display_options['filters']['language']['field'] = 'language';
$handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
    'und' => 'und',
    'en' => 'en',
);
$handler->display->display_options['filters']['language']['group'] = 1;
$translatables['issues'] = array(
    t('Master'),
    t('Issues'),
    t('Read more'),
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
    t('Body'),
    t('Photo'),
    t('Summary'),
    t('All'),
    t('Page'),
    t('Featured Issue'),
    t('Sidebar Navigation (All)'),
    t('eBay Inc. Government Relations monitors and is involved with issues affecting the eBay marketplace, PayPal merchants, StubHub users and more.'),
    t('continue'),
    t('Region'),
    t('more'),
    t('<a href="[path]">Read more</a>'),
    t('Featured Issue - (Asia Pacific)'),
    t('Featured Issue - (Australia)'),
    t('Featured Issue - (Europe)'),
    t('Sidebar Navigation Region-Specific fixed'),
    t('Sidebar Navigation (US)'),
    t('Sidebar Navigation (Europe)'),
    t('Sidebar Navigation (Asia)'),
    t('Sidebar Navigation (Australia)'),
);