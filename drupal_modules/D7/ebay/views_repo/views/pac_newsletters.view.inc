<?php

$view = new view();
$view->name = 'pac_newsletters';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'PAC Newsletters';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'PAC Newsletters';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'list';
$handler->display->display_options['row_plugin'] = 'fields';
/* Field: Content: PDF */
$handler->display->display_options['fields']['field_pac_newsletter_pdf']['id'] = 'field_pac_newsletter_pdf';
$handler->display->display_options['fields']['field_pac_newsletter_pdf']['table'] = 'field_data_field_pac_newsletter_pdf';
$handler->display->display_options['fields']['field_pac_newsletter_pdf']['field'] = 'field_pac_newsletter_pdf';
$handler->display->display_options['fields']['field_pac_newsletter_pdf']['label'] = '';
$handler->display->display_options['fields']['field_pac_newsletter_pdf']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_pac_newsletter_pdf']['element_type'] = '0';
$handler->display->display_options['fields']['field_pac_newsletter_pdf']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_pac_newsletter_pdf']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_pac_newsletter_pdf']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_pac_newsletter_pdf']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_pac_newsletter_pdf']['type'] = 'file_url_plain';
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['text'] = '<a href="[field_pac_newsletter_pdf]" target="_blank">[title]</a>';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_type'] = '0';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
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
    'pac_newsletter' => 'pac_newsletter',
);

/* Display: Block */
$handler = $view->new_display('block', 'Block', 'block');

/* Display: Block */
$handler = $view->new_display('block', 'Block', 'block_1');
$translatables['pac_newsletters'] = array(
    t('Master'),
    t('PAC Newsletters'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('<a href="[field_pac_newsletter_pdf]" target="_blank">[title]</a>'),
    t('Block'),
);