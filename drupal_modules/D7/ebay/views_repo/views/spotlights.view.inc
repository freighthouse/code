<?php

$view = new view();
$view->name = 'spotlights';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'Spotlights';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = '<none>';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'list';
$handler->display->display_options['style_options']['default_row_class'] = FALSE;
$handler->display->display_options['style_options']['row_class_special'] = FALSE;
$handler->display->display_options['style_options']['class'] = 'spotlight-list';
$handler->display->display_options['style_options']['wrapper_class'] = '';
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['default_field_elements'] = FALSE;
/* Relationship: Nodequeue: Queue */
$handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
$handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
$handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
$handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
$handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
$handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'spotlights' => 'spotlights',
);
/* Field: Content: Slide Pre-Title */
$handler->display->display_options['fields']['field_spotlight_pre_title']['id'] = 'field_spotlight_pre_title';
$handler->display->display_options['fields']['field_spotlight_pre_title']['table'] = 'field_data_field_spotlight_pre_title';
$handler->display->display_options['fields']['field_spotlight_pre_title']['field'] = 'field_spotlight_pre_title';
$handler->display->display_options['fields']['field_spotlight_pre_title']['label'] = '';
$handler->display->display_options['fields']['field_spotlight_pre_title']['element_type'] = '0';
$handler->display->display_options['fields']['field_spotlight_pre_title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_spotlight_pre_title']['element_default_classes'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['text'] = '
';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Content: Link */
$handler->display->display_options['fields']['field_spotlight_link']['id'] = 'field_spotlight_link';
$handler->display->display_options['fields']['field_spotlight_link']['table'] = 'field_data_field_spotlight_link';
$handler->display->display_options['fields']['field_spotlight_link']['field'] = 'field_spotlight_link';
$handler->display->display_options['fields']['field_spotlight_link']['label'] = '';
$handler->display->display_options['fields']['field_spotlight_link']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_spotlight_link']['click_sort_column'] = 'url';
$handler->display->display_options['fields']['field_spotlight_link']['type'] = 'link_plain';
/* Field: Content: Image */
$handler->display->display_options['fields']['field_spotlight_image']['id'] = 'field_spotlight_image';
$handler->display->display_options['fields']['field_spotlight_image']['table'] = 'field_data_field_spotlight_image';
$handler->display->display_options['fields']['field_spotlight_image']['field'] = 'field_spotlight_image';
$handler->display->display_options['fields']['field_spotlight_image']['label'] = '';
$handler->display->display_options['fields']['field_spotlight_image']['alter']['path'] = '[field_spotlight_link]';
$handler->display->display_options['fields']['field_spotlight_image']['element_type'] = '0';
$handler->display->display_options['fields']['field_spotlight_image']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_spotlight_image']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_spotlight_image']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_spotlight_image']['type'] = 'picture';
$handler->display->display_options['fields']['field_spotlight_image']['settings'] = array(
    'picture_group' => 'spotlight_breakpoints',
    'fallback_image_style' => 'thumbnail',
    'image_link' => '',
);
/* Field: Content: Background Color */
$handler->display->display_options['fields']['field_spotlight_bgcolor']['id'] = 'field_spotlight_bgcolor';
$handler->display->display_options['fields']['field_spotlight_bgcolor']['table'] = 'field_data_field_spotlight_bgcolor';
$handler->display->display_options['fields']['field_spotlight_bgcolor']['field'] = 'field_spotlight_bgcolor';
$handler->display->display_options['fields']['field_spotlight_bgcolor']['label'] = '';
$handler->display->display_options['fields']['field_spotlight_bgcolor']['element_label_colon'] = FALSE;
/* Field: Content: Slide Text */
$handler->display->display_options['fields']['field_spotlight_text']['id'] = 'field_spotlight_text';
$handler->display->display_options['fields']['field_spotlight_text']['table'] = 'field_data_field_spotlight_text';
$handler->display->display_options['fields']['field_spotlight_text']['field'] = 'field_spotlight_text';
$handler->display->display_options['fields']['field_spotlight_text']['label'] = '';
$handler->display->display_options['fields']['field_spotlight_text']['element_label_colon'] = FALSE;
/* Field: Content: Call To Action Text */
$handler->display->display_options['fields']['field_spotlight_cta']['id'] = 'field_spotlight_cta';
$handler->display->display_options['fields']['field_spotlight_cta']['table'] = 'field_data_field_spotlight_cta';
$handler->display->display_options['fields']['field_spotlight_cta']['field'] = 'field_spotlight_cta';
$handler->display->display_options['fields']['field_spotlight_cta']['label'] = '';
$handler->display->display_options['fields']['field_spotlight_cta']['element_type'] = '0';
$handler->display->display_options['fields']['field_spotlight_cta']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_spotlight_cta']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_spotlight_cta']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_spotlight_cta']['field_api_classes'] = TRUE;
/* Field: Content: Slide Title */
$handler->display->display_options['fields']['field_spotlight_slide_title']['id'] = 'field_spotlight_slide_title';
$handler->display->display_options['fields']['field_spotlight_slide_title']['table'] = 'field_data_field_spotlight_slide_title';
$handler->display->display_options['fields']['field_spotlight_slide_title']['field'] = 'field_spotlight_slide_title';
$handler->display->display_options['fields']['field_spotlight_slide_title']['label'] = '';
$handler->display->display_options['fields']['field_spotlight_slide_title']['element_type'] = '0';
$handler->display->display_options['fields']['field_spotlight_slide_title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_spotlight_slide_title']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_spotlight_slide_title']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_spotlight_slide_title']['field_api_classes'] = TRUE;
/* Sort criterion: Nodequeue: Position */
$handler->display->display_options['sorts']['position']['id'] = 'position';
$handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
$handler->display->display_options['sorts']['position']['field'] = 'position';
$handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
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
    'spotlight' => 'spotlight',
);

/* Display: Block */
$handler = $view->new_display('block', 'Block', 'block');
$handler->display->display_options['defaults']['relationships'] = FALSE;
/* Relationship: Nodequeue: Queue */
$handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
$handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
$handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
$handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
$handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
$handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'spotlights_global' => 'spotlights_global',
    'spotlights' => 0,
    'team_profiles' => 0,
    'resources' => 0,
    'spotlights_australia' => 0,
    'spotlights_asia_pacific' => 0,
    'spotlights_europe' => 0,
);

/* Display: Block - Asia Pacific */
$handler = $view->new_display('block', 'Block - Asia Pacific', 'block_1');
$handler->display->display_options['defaults']['relationships'] = FALSE;
/* Relationship: Nodequeue: Queue */
$handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
$handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
$handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
$handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
$handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
$handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'spotlights_asia_pacific' => 'spotlights_asia_pacific',
    'spotlights' => 0,
    'team_profiles' => 0,
    'resources' => 0,
    'spotlights_australia' => 0,
    'spotlights_europe' => 0,
);

/* Display: Block - Europe */
$handler = $view->new_display('block', 'Block - Europe', 'block_2');
$handler->display->display_options['defaults']['relationships'] = FALSE;
/* Relationship: Nodequeue: Queue */
$handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
$handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
$handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
$handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
$handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
$handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'spotlights_europe' => 'spotlights_europe',
    'spotlights' => 0,
    'team_profiles' => 0,
    'resources' => 0,
    'spotlights_australia' => 0,
    'spotlights_asia_pacific' => 0,
);

/* Display: Block - Australia */
$handler = $view->new_display('block', 'Block - Australia', 'block_3');
$handler->display->display_options['defaults']['relationships'] = FALSE;
/* Relationship: Nodequeue: Queue */
$handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
$handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
$handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
$handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
$handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
$handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'spotlights_australia' => 'spotlights_australia',
    'spotlights' => 0,
    'team_profiles' => 0,
    'resources' => 0,
    'spotlights_asia_pacific' => 0,
    'spotlights_europe' => 0,
);

/* Display: Block - USA */
$handler = $view->new_display('block', 'Block - USA', 'block_4');
$handler->display->display_options['defaults']['relationships'] = FALSE;
/* Relationship: Nodequeue: Queue */
$handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
$handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
$handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
$handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
$handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
$handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'spotlights' => 'spotlights',
    'team_profiles' => 0,
    'resources' => 0,
    'spotlights_australia' => 0,
    'spotlights_asia_pacific' => 0,
    'spotlights_europe' => 0,
    'spotlights_global' => 0,
);
$translatables['spotlights'] = array(
    t('Master'),
    t('<none>'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('queue'),
    t('
'),
    t('Block'),
    t('Block - Asia Pacific'),
    t('Block - Europe'),
    t('Block - Australia'),
    t('Block - USA'),
);