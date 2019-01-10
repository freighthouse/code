<?php

$view = new view();
$view->name = 'countable_campaign';
$view->description = 'Countable Campaign';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'Countable Campaign';
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
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['row_plugin'] = 'fields';
/* Field: Content: Video */
$handler->display->display_options['fields']['field_video']['id'] = 'field_video';
$handler->display->display_options['fields']['field_video']['table'] = 'field_data_field_video';
$handler->display->display_options['fields']['field_video']['field'] = 'field_video';
$handler->display->display_options['fields']['field_video']['label'] = '';
$handler->display->display_options['fields']['field_video']['element_type'] = '0';
$handler->display->display_options['fields']['field_video']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_video']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_video']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_video']['click_sort_column'] = 'video_url';
$handler->display->display_options['fields']['field_video']['settings'] = array(
    'video_style' => 'normal',
);
$handler->display->display_options['fields']['field_video']['field_api_classes'] = TRUE;
/* Field: Content: Name */
$handler->display->display_options['fields']['field_person_name']['id'] = 'field_person_name';
$handler->display->display_options['fields']['field_person_name']['table'] = 'field_data_field_person_name';
$handler->display->display_options['fields']['field_person_name']['field'] = 'field_person_name';
$handler->display->display_options['fields']['field_person_name']['label'] = '';
$handler->display->display_options['fields']['field_person_name']['element_type'] = '0';
$handler->display->display_options['fields']['field_person_name']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_person_name']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_person_name']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_person_name']['field_api_classes'] = TRUE;
/* Field: Content: Ebay Store Name */
$handler->display->display_options['fields']['field_ebay_store_name']['id'] = 'field_ebay_store_name';
$handler->display->display_options['fields']['field_ebay_store_name']['table'] = 'field_data_field_ebay_store_name';
$handler->display->display_options['fields']['field_ebay_store_name']['field'] = 'field_ebay_store_name';
$handler->display->display_options['fields']['field_ebay_store_name']['label'] = '';
$handler->display->display_options['fields']['field_ebay_store_name']['element_type'] = '0';
$handler->display->display_options['fields']['field_ebay_store_name']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_ebay_store_name']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_ebay_store_name']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_ebay_store_name']['field_api_classes'] = TRUE;
/* Field: Content: City */
$handler->display->display_options['fields']['field_city']['id'] = 'field_city';
$handler->display->display_options['fields']['field_city']['table'] = 'field_data_field_city';
$handler->display->display_options['fields']['field_city']['field'] = 'field_city';
$handler->display->display_options['fields']['field_city']['label'] = '';
$handler->display->display_options['fields']['field_city']['element_type'] = '0';
$handler->display->display_options['fields']['field_city']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_city']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_city']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_city']['field_api_classes'] = TRUE;
/* Field: Content: State */
$handler->display->display_options['fields']['field_state']['id'] = 'field_state';
$handler->display->display_options['fields']['field_state']['table'] = 'field_data_field_state';
$handler->display->display_options['fields']['field_state']['field'] = 'field_state';
$handler->display->display_options['fields']['field_state']['label'] = '';
$handler->display->display_options['fields']['field_state']['element_type'] = '0';
$handler->display->display_options['fields']['field_state']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_state']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_state']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_state']['field_api_classes'] = TRUE;
/* Sort criterion: Content: Post date */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'node';
$handler->display->display_options['sorts']['created']['field'] = 'created';
$handler->display->display_options['sorts']['created']['order'] = 'DESC';
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = '1';
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
    'countable_campaign' => 'countable_campaign',
);

/* Display: Block */
$handler = $view->new_display('block', 'Block', 'block');
$handler->display->display_options['block_description'] = 'Countable Video Block';
$translatables['countable_campaign'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Block'),
    t('Countable Video Block'),
);