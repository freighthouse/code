<?php

$view = new view();
$view->name = 'new_lp';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'New LP';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['row_plugin'] = 'fields';
/* Field: Content: Image */
$handler->display->display_options['fields']['field_landing_page_image']['id'] = 'field_landing_page_image';
$handler->display->display_options['fields']['field_landing_page_image']['table'] = 'field_data_field_landing_page_image';
$handler->display->display_options['fields']['field_landing_page_image']['field'] = 'field_landing_page_image';
$handler->display->display_options['fields']['field_landing_page_image']['label'] = '';
$handler->display->display_options['fields']['field_landing_page_image']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_landing_page_image']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_landing_page_image']['settings'] = array(
    'image_style' => '',
    'image_link' => 'file',
);
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Content: Body */
$handler->display->display_options['fields']['body']['id'] = 'body';
$handler->display->display_options['fields']['body']['table'] = 'field_data_body';
$handler->display->display_options['fields']['body']['field'] = 'body';
$handler->display->display_options['fields']['body']['label'] = '';
$handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
/* Field: Content: Image and Text */
$handler->display->display_options['fields']['field_image_and_text']['id'] = 'field_image_and_text';
$handler->display->display_options['fields']['field_image_and_text']['table'] = 'field_data_field_image_and_text';
$handler->display->display_options['fields']['field_image_and_text']['field'] = 'field_image_and_text';
$handler->display->display_options['fields']['field_image_and_text']['label'] = '';
$handler->display->display_options['fields']['field_image_and_text']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_image_and_text']['hide_empty'] = TRUE;
$handler->display->display_options['fields']['field_image_and_text']['hide_alter_empty'] = FALSE;
$handler->display->display_options['fields']['field_image_and_text']['settings'] = array(
    'view_mode' => 'full',
);
$handler->display->display_options['fields']['field_image_and_text']['delta_offset'] = '0';
$handler->display->display_options['fields']['field_image_and_text']['multi_type'] = 'ul';
$handler->display->display_options['fields']['field_image_and_text']['separator'] = '';
/* Field: Field: Link */
$handler->display->display_options['fields']['field_link']['id'] = 'field_link';
$handler->display->display_options['fields']['field_link']['table'] = 'field_data_field_link';
$handler->display->display_options['fields']['field_link']['field'] = 'field_link';
$handler->display->display_options['fields']['field_link']['label'] = '';
$handler->display->display_options['fields']['field_link']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_link']['click_sort_column'] = 'url';
/* Field: Content: Jump Link */
$handler->display->display_options['fields']['field_jump_link']['id'] = 'field_jump_link';
$handler->display->display_options['fields']['field_jump_link']['table'] = 'field_data_field_jump_link';
$handler->display->display_options['fields']['field_jump_link']['field'] = 'field_jump_link';
$handler->display->display_options['fields']['field_jump_link']['label'] = '';
$handler->display->display_options['fields']['field_jump_link']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_jump_link']['hide_empty'] = TRUE;
$handler->display->display_options['fields']['field_jump_link']['click_sort_column'] = 'url';
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
    'lp_section' => 'lp_section',
);

/* Display: Block */
$handler = $view->new_display('block', 'Block', 'block');
$translatables['new_lp'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Block'),
);