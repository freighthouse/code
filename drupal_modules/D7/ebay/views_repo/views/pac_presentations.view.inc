<?php

$view = new view();
$view->name = 'pac_presentations';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'PAC Presentations';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'PAC Presentations';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'list';
$handler->display->display_options['row_plugin'] = 'fields';
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['exclude'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Content: File */
$handler->display->display_options['fields']['field_pac_presentation_file']['id'] = 'field_pac_presentation_file';
$handler->display->display_options['fields']['field_pac_presentation_file']['table'] = 'field_data_field_pac_presentation_file';
$handler->display->display_options['fields']['field_pac_presentation_file']['field'] = 'field_pac_presentation_file';
$handler->display->display_options['fields']['field_pac_presentation_file']['label'] = '';
$handler->display->display_options['fields']['field_pac_presentation_file']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['field_pac_presentation_file']['alter']['text'] = '<h3><a href="[field_pac_presentation_file]" target="_blank">[title]</a></h3>';
$handler->display->display_options['fields']['field_pac_presentation_file']['element_type'] = '0';
$handler->display->display_options['fields']['field_pac_presentation_file']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_pac_presentation_file']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_pac_presentation_file']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_pac_presentation_file']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_pac_presentation_file']['type'] = 'file_url_plain';
/* Field: Content: Description */
$handler->display->display_options['fields']['field_annual_report_description']['id'] = 'field_annual_report_description';
$handler->display->display_options['fields']['field_annual_report_description']['table'] = 'field_data_field_annual_report_description';
$handler->display->display_options['fields']['field_annual_report_description']['field'] = 'field_annual_report_description';
$handler->display->display_options['fields']['field_annual_report_description']['label'] = '';
$handler->display->display_options['fields']['field_annual_report_description']['element_type'] = 'p';
$handler->display->display_options['fields']['field_annual_report_description']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_annual_report_description']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_annual_report_description']['element_default_classes'] = FALSE;
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
    'pac_presentation' => 'pac_presentation',
);

/* Display: Block */
$handler = $view->new_display('block', 'Block', 'block');
$translatables['pac_presentations'] = array(
    t('Master'),
    t('PAC Presentations'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('<h3><a href="[field_pac_presentation_file]" target="_blank">[title]</a></h3>'),
    t('Block'),
);