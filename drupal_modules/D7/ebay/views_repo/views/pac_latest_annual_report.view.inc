<?php

$view = new view();
$view->name = 'pac_latest_annual_report';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'PAC Latest Annual Report';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'PAC Annual Report';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '1';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['style_options']['default_row_class'] = FALSE;
$handler->display->display_options['style_options']['row_class_special'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['default_field_elements'] = FALSE;
/* Field: Content: Image */
$handler->display->display_options['fields']['field_pac_report_image']['id'] = 'field_pac_report_image';
$handler->display->display_options['fields']['field_pac_report_image']['table'] = 'field_data_field_pac_report_image';
$handler->display->display_options['fields']['field_pac_report_image']['field'] = 'field_pac_report_image';
$handler->display->display_options['fields']['field_pac_report_image']['label'] = '';
$handler->display->display_options['fields']['field_pac_report_image']['element_type'] = '0';
$handler->display->display_options['fields']['field_pac_report_image']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_pac_report_image']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_pac_report_image']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_pac_report_image']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_pac_report_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
);
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['exclude'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_type'] = '0';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Content: Description */
$handler->display->display_options['fields']['field_annual_report_description']['id'] = 'field_annual_report_description';
$handler->display->display_options['fields']['field_annual_report_description']['table'] = 'field_data_field_annual_report_description';
$handler->display->display_options['fields']['field_annual_report_description']['field'] = 'field_annual_report_description';
$handler->display->display_options['fields']['field_annual_report_description']['label'] = '';
$handler->display->display_options['fields']['field_annual_report_description']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_annual_report_description']['element_type'] = 'p';
$handler->display->display_options['fields']['field_annual_report_description']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_annual_report_description']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_annual_report_description']['element_default_classes'] = FALSE;
/* Field: Content: PDF Upload */
$handler->display->display_options['fields']['field_pac_report_file']['id'] = 'field_pac_report_file';
$handler->display->display_options['fields']['field_pac_report_file']['table'] = 'field_data_field_pac_report_file';
$handler->display->display_options['fields']['field_pac_report_file']['field'] = 'field_pac_report_file';
$handler->display->display_options['fields']['field_pac_report_file']['label'] = '';
$handler->display->display_options['fields']['field_pac_report_file']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['field_pac_report_file']['alter']['text'] = '<div class="text-wrapper">
<h2>[title]</h2>
<p>[field_annual_report_description]</p>
<a href="[field_pac_report_file]" class="btn" target="_blank">Download the [title]</a>
</div>';
$handler->display->display_options['fields']['field_pac_report_file']['element_type'] = '0';
$handler->display->display_options['fields']['field_pac_report_file']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_pac_report_file']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_pac_report_file']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_pac_report_file']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_pac_report_file']['type'] = 'file_url_plain';
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
    'pac_annual_report' => 'pac_annual_report',
);

/* Display: Annual Report - Block */
$handler = $view->new_display('block', 'Annual Report - Block', 'annual_report_block');
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Image */
$handler->display->display_options['fields']['field_pac_report_image']['id'] = 'field_pac_report_image';
$handler->display->display_options['fields']['field_pac_report_image']['table'] = 'field_data_field_pac_report_image';
$handler->display->display_options['fields']['field_pac_report_image']['field'] = 'field_pac_report_image';
$handler->display->display_options['fields']['field_pac_report_image']['label'] = '';
$handler->display->display_options['fields']['field_pac_report_image']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_pac_report_image']['element_type'] = '0';
$handler->display->display_options['fields']['field_pac_report_image']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_pac_report_image']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_pac_report_image']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_pac_report_image']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_pac_report_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
);
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['exclude'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_type'] = '0';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Content: Description */
$handler->display->display_options['fields']['field_annual_report_description']['id'] = 'field_annual_report_description';
$handler->display->display_options['fields']['field_annual_report_description']['table'] = 'field_data_field_annual_report_description';
$handler->display->display_options['fields']['field_annual_report_description']['field'] = 'field_annual_report_description';
$handler->display->display_options['fields']['field_annual_report_description']['label'] = '';
$handler->display->display_options['fields']['field_annual_report_description']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_annual_report_description']['element_type'] = 'p';
$handler->display->display_options['fields']['field_annual_report_description']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_annual_report_description']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_annual_report_description']['element_default_classes'] = FALSE;
/* Field: Content: PDF Upload */
$handler->display->display_options['fields']['field_pac_report_file']['id'] = 'field_pac_report_file';
$handler->display->display_options['fields']['field_pac_report_file']['table'] = 'field_data_field_pac_report_file';
$handler->display->display_options['fields']['field_pac_report_file']['field'] = 'field_pac_report_file';
$handler->display->display_options['fields']['field_pac_report_file']['label'] = '';
$handler->display->display_options['fields']['field_pac_report_file']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_pac_report_file']['element_type'] = '0';
$handler->display->display_options['fields']['field_pac_report_file']['element_label_type'] = '0';
$handler->display->display_options['fields']['field_pac_report_file']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_pac_report_file']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_pac_report_file']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_pac_report_file']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_pac_report_file']['type'] = 'file_url_plain';
/* Field: Global: Custom text */
$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
$handler->display->display_options['fields']['nothing']['table'] = 'views';
$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing']['label'] = '';
$handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="annual-report">
<a href="[field_pac_report_file]" title="Download the [title]" target="_blank">
<div class="annual-report-title">[title]</div>
<div class="annual-report-content">
<div class="annual-report-image">[field_pac_report_image]</div>
<div class="annual-report-description">[field_annual_report_description]</div>
</div>
<div class="annual-report-link">Download the [title]</div>
</a>
</div>';
$handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;

/* Display: Annual Report - Block (Page) */
$handler = $view->new_display('block', 'Annual Report - Block (Page)', 'annual_report_page_block');
$handler->display->display_options['defaults']['css_class'] = FALSE;
$handler->display->display_options['css_class'] = 'annual-report-page-block';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Image */
$handler->display->display_options['fields']['field_pac_report_image']['id'] = 'field_pac_report_image';
$handler->display->display_options['fields']['field_pac_report_image']['table'] = 'field_data_field_pac_report_image';
$handler->display->display_options['fields']['field_pac_report_image']['field'] = 'field_pac_report_image';
$handler->display->display_options['fields']['field_pac_report_image']['label'] = '';
$handler->display->display_options['fields']['field_pac_report_image']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_pac_report_image']['element_type'] = '0';
$handler->display->display_options['fields']['field_pac_report_image']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_pac_report_image']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_pac_report_image']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_pac_report_image']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_pac_report_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
);
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['exclude'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_type'] = '0';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Content: Description */
$handler->display->display_options['fields']['field_annual_report_description']['id'] = 'field_annual_report_description';
$handler->display->display_options['fields']['field_annual_report_description']['table'] = 'field_data_field_annual_report_description';
$handler->display->display_options['fields']['field_annual_report_description']['field'] = 'field_annual_report_description';
$handler->display->display_options['fields']['field_annual_report_description']['label'] = '';
$handler->display->display_options['fields']['field_annual_report_description']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_annual_report_description']['element_type'] = 'p';
$handler->display->display_options['fields']['field_annual_report_description']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_annual_report_description']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_annual_report_description']['element_default_classes'] = FALSE;
/* Field: Content: PDF Upload */
$handler->display->display_options['fields']['field_pac_report_file']['id'] = 'field_pac_report_file';
$handler->display->display_options['fields']['field_pac_report_file']['table'] = 'field_data_field_pac_report_file';
$handler->display->display_options['fields']['field_pac_report_file']['field'] = 'field_pac_report_file';
$handler->display->display_options['fields']['field_pac_report_file']['label'] = '';
$handler->display->display_options['fields']['field_pac_report_file']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_pac_report_file']['element_type'] = '0';
$handler->display->display_options['fields']['field_pac_report_file']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_pac_report_file']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_pac_report_file']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_pac_report_file']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_pac_report_file']['type'] = 'file_url_plain';
/* Field: Global: Custom text */
$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
$handler->display->display_options['fields']['nothing']['table'] = 'views';
$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing']['label'] = '';
$handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="annual-report">
<a href="[field_pac_report_file]" title="Download the [title]" target="_blank">
<div class="annual-report-content">
<h2 class="annual-report-title">[title]</h2>
<p class="annual-report-description">[field_annual_report_description]</p>
<div class="annual-report-link">Download the [title]</div>
</div>
<div class="annual-report-image">[field_pac_report_image]</div>
</a>
</div>';
$handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
$translatables['pac_latest_annual_report'] = array(
    t('Master'),
    t('PAC Annual Report'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('<div class="text-wrapper">
<h2>[title]</h2>
<p>[field_annual_report_description]</p>
<a href="[field_pac_report_file]" class="btn" target="_blank">Download the [title]</a>
</div>'),
    t('Annual Report - Block'),
    t('<div class="annual-report">
<a href="[field_pac_report_file]" title="Download the [title]" target="_blank">
<div class="annual-report-title">[title]</div>
<div class="annual-report-content">
<div class="annual-report-image">[field_pac_report_image]</div>
<div class="annual-report-description">[field_annual_report_description]</div>
</div>
<div class="annual-report-link">Download the [title]</div>
</a>
</div>'),
    t('Annual Report - Block (Page)'),
    t('<div class="annual-report">
<a href="[field_pac_report_file]" title="Download the [title]" target="_blank">
<div class="annual-report-content">
<h2 class="annual-report-title">[title]</h2>
<p class="annual-report-description">[field_annual_report_description]</p>
<div class="annual-report-link">Download the [title]</div>
</div>
<div class="annual-report-image">[field_pac_report_image]</div>
</a>
</div>'),
);