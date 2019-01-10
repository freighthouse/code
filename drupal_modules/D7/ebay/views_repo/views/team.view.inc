<?php

$view = new view();
$view->name = 'team';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'Team';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Our Team';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'role';
$handler->display->display_options['access']['role'] = array(
    1 => '1',
    2 => '2',
);
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '20';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['style_plugin'] = 'list';
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['inline'] = array(
    'field_profile_first' => 'field_profile_first',
    'field_profile_last' => 'field_profile_last',
);
/* Field: Content: First */
$handler->display->display_options['fields']['field_profile_first']['id'] = 'field_profile_first';
$handler->display->display_options['fields']['field_profile_first']['table'] = 'field_data_field_profile_first';
$handler->display->display_options['fields']['field_profile_first']['field'] = 'field_profile_first';
$handler->display->display_options['fields']['field_profile_first']['label'] = '';
$handler->display->display_options['fields']['field_profile_first']['element_label_colon'] = FALSE;
/* Field: Content: Last */
$handler->display->display_options['fields']['field_profile_last']['id'] = 'field_profile_last';
$handler->display->display_options['fields']['field_profile_last']['table'] = 'field_data_field_profile_last';
$handler->display->display_options['fields']['field_profile_last']['field'] = 'field_profile_last';
$handler->display->display_options['fields']['field_profile_last']['label'] = '';
$handler->display->display_options['fields']['field_profile_last']['element_label_colon'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['field_profile_title']['id'] = 'field_profile_title';
$handler->display->display_options['fields']['field_profile_title']['table'] = 'field_data_field_profile_title';
$handler->display->display_options['fields']['field_profile_title']['field'] = 'field_profile_title';
$handler->display->display_options['fields']['field_profile_title']['label'] = '';
$handler->display->display_options['fields']['field_profile_title']['element_label_colon'] = FALSE;
/* Field: Content: Region */
$handler->display->display_options['fields']['field_taxonomy_region']['id'] = 'field_taxonomy_region';
$handler->display->display_options['fields']['field_taxonomy_region']['table'] = 'field_data_field_taxonomy_region';
$handler->display->display_options['fields']['field_taxonomy_region']['field'] = 'field_taxonomy_region';
$handler->display->display_options['fields']['field_taxonomy_region']['label'] = '';
$handler->display->display_options['fields']['field_taxonomy_region']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_taxonomy_region']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_taxonomy_region']['type'] = 'taxonomy_term_reference_plain';
$handler->display->display_options['fields']['field_taxonomy_region']['delta_offset'] = '0';
/* Sort criterion: Content: Sticky */
$handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
$handler->display->display_options['sorts']['sticky']['table'] = 'node';
$handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
$handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
/* Sort criterion: Content: Last (field_profile_last) */
$handler->display->display_options['sorts']['field_profile_last_value']['id'] = 'field_profile_last_value';
$handler->display->display_options['sorts']['field_profile_last_value']['table'] = 'field_data_field_profile_last';
$handler->display->display_options['sorts']['field_profile_last_value']['field'] = 'field_profile_last_value';
/* Contextual filter: Content: Region (field_taxonomy_region) */
$handler->display->display_options['arguments']['field_taxonomy_region_tid']['id'] = 'field_taxonomy_region_tid';
$handler->display->display_options['arguments']['field_taxonomy_region_tid']['table'] = 'field_data_field_taxonomy_region';
$handler->display->display_options['arguments']['field_taxonomy_region_tid']['field'] = 'field_taxonomy_region_tid';
$handler->display->display_options['arguments']['field_taxonomy_region_tid']['default_action'] = 'default';
$handler->display->display_options['arguments']['field_taxonomy_region_tid']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['field_taxonomy_region_tid']['default_argument_options']['argument'] = 'United-States';
$handler->display->display_options['arguments']['field_taxonomy_region_tid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['field_taxonomy_region_tid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['field_taxonomy_region_tid']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['field_taxonomy_region_tid']['specify_validation'] = TRUE;
$handler->display->display_options['arguments']['field_taxonomy_region_tid']['validate']['type'] = 'taxonomy_term';
$handler->display->display_options['arguments']['field_taxonomy_region_tid']['validate_options']['vocabularies'] = array(
    'region' => 'region',
);
$handler->display->display_options['arguments']['field_taxonomy_region_tid']['validate_options']['type'] = 'convert';
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
    'profile' => 'profile',
);
/* Filter criterion: Content: Region (field_taxonomy_region) */
$handler->display->display_options['filters']['field_taxonomy_region_tid']['id'] = 'field_taxonomy_region_tid';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['table'] = 'field_data_field_taxonomy_region';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['field'] = 'field_taxonomy_region_tid';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['group'] = '0';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_taxonomy_region_tid']['expose']['operator_id'] = 'field_taxonomy_region_tid_op';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['expose']['label'] = 'Region (field_taxonomy_region)';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['expose']['operator'] = 'field_taxonomy_region_tid_op';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['expose']['identifier'] = 'field_taxonomy_region_tid';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['type'] = 'select';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['vocabulary'] = 'region';

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
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
    'profile' => 'profile',
);
$handler->display->display_options['filters']['type']['group'] = 1;
$handler->display->display_options['path'] = 'team';
$handler->display->display_options['menu']['type'] = 'normal';
$handler->display->display_options['menu']['title'] = 'Our Team';
$handler->display->display_options['menu']['weight'] = '0';
$handler->display->display_options['menu']['name'] = 'main-menu';

/* Display: Policy Lab Team Block */
$handler = $view->new_display('block', 'Policy Lab Team Block', 'block_1');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Who We Are';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'list';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['relationships'] = FALSE;
/* Relationship: Nodequeue: Queue */
$handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
$handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
$handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
$handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
$handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
$handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'policy_labs_team' => 'policy_labs_team',
    'spotlights' => 0,
    'team_profiles' => 0,
    'resources' => 0,
    'spotlights_australia' => 0,
    'spotlights_asia_pacific' => 0,
    'spotlights_europe' => 0,
    'spotlights_global' => 0,
    'photo_gallery_2012_dc_fly_in' => 0,
    'featured_member' => 0,
    'photo_gallery_2012_think_3_0_sto' => 0,
    'photo_gallery_commerce_3_0_us_ev' => 0,
    'photo_gallery_germany_pop_up_sto' => 0,
    'featured_member_eu' => 0,
    'featured_member_au' => 0,
    'featured_member_apac' => 0,
    'photo_gallery_paypal_thought_lea' => 0,
    'features_extra_test_nodequeue' => 0,
);
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['exclude'] = TRUE;
$handler->display->display_options['fields']['title']['element_type'] = '0';
$handler->display->display_options['fields']['title']['element_label_type'] = '0';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
/* Field: Content: Title */
$handler->display->display_options['fields']['field_profile_title']['id'] = 'field_profile_title';
$handler->display->display_options['fields']['field_profile_title']['table'] = 'field_data_field_profile_title';
$handler->display->display_options['fields']['field_profile_title']['field'] = 'field_profile_title';
$handler->display->display_options['fields']['field_profile_title']['label'] = '';
$handler->display->display_options['fields']['field_profile_title']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_profile_title']['element_type'] = '0';
$handler->display->display_options['fields']['field_profile_title']['element_label_type'] = '0';
$handler->display->display_options['fields']['field_profile_title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_profile_title']['element_wrapper_type'] = '0';
/* Field: Content: Email */
$handler->display->display_options['fields']['field_profile_email']['id'] = 'field_profile_email';
$handler->display->display_options['fields']['field_profile_email']['table'] = 'field_data_field_profile_email';
$handler->display->display_options['fields']['field_profile_email']['field'] = 'field_profile_email';
$handler->display->display_options['fields']['field_profile_email']['label'] = '';
$handler->display->display_options['fields']['field_profile_email']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_profile_email']['alter']['text'] = '<a href="mailto:[field_profile_email]">[field_profile_email]</a>';
$handler->display->display_options['fields']['field_profile_email']['element_type'] = '0';
$handler->display->display_options['fields']['field_profile_email']['element_label_type'] = '0';
$handler->display->display_options['fields']['field_profile_email']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_profile_email']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_profile_email']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_profile_email']['type'] = 'text_plain';
/* Field: Global: Custom text */
$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
$handler->display->display_options['fields']['nothing']['table'] = 'views';
$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing']['label'] = '';
$handler->display->display_options['fields']['nothing']['alter']['text'] = '[title], [field_profile_title], <a href="mailto:[field_profile_email]">[field_profile_email]</a>';
$handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: Nodequeue: Position */
$handler->display->display_options['sorts']['position']['id'] = 'position';
$handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
$handler->display->display_options['sorts']['position']['field'] = 'position';
$handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
$handler->display->display_options['defaults']['arguments'] = FALSE;
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
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
    'profile' => 'profile',
);

/* Display: Policy Lab Team Page */
$handler = $view->new_display('page', 'Policy Lab Team Page', 'page_1');
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '0';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '9';
$handler->display->display_options['defaults']['relationships'] = FALSE;
/* Relationship: Nodequeue: Queue */
$handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
$handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
$handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
$handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
$handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
$handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'policy_labs_team' => 'policy_labs_team',
    'spotlights' => 0,
    'team_profiles' => 0,
    'resources' => 0,
    'spotlights_australia' => 0,
    'spotlights_asia_pacific' => 0,
    'spotlights_europe' => 0,
    'spotlights_global' => 0,
    'photo_gallery_2012_dc_fly_in' => 0,
    'featured_member' => 0,
    'photo_gallery_2012_think_3_0_sto' => 0,
    'photo_gallery_commerce_3_0_us_ev' => 0,
    'photo_gallery_germany_pop_up_sto' => 0,
    'featured_member_eu' => 0,
    'featured_member_au' => 0,
    'featured_member_apac' => 0,
    'photo_gallery_paypal_thought_lea' => 0,
    'features_extra_test_nodequeue' => 0,
);
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['element_type'] = 'h2';
$handler->display->display_options['fields']['title']['element_class'] = 'team-name';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['field_profile_title']['id'] = 'field_profile_title';
$handler->display->display_options['fields']['field_profile_title']['table'] = 'field_data_field_profile_title';
$handler->display->display_options['fields']['field_profile_title']['field'] = 'field_profile_title';
$handler->display->display_options['fields']['field_profile_title']['label'] = '';
$handler->display->display_options['fields']['field_profile_title']['element_type'] = 'h3';
$handler->display->display_options['fields']['field_profile_title']['element_class'] = 'team-title';
$handler->display->display_options['fields']['field_profile_title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_profile_title']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_profile_title']['element_default_classes'] = FALSE;
/* Field: Content: Email */
$handler->display->display_options['fields']['field_profile_email']['id'] = 'field_profile_email';
$handler->display->display_options['fields']['field_profile_email']['table'] = 'field_data_field_profile_email';
$handler->display->display_options['fields']['field_profile_email']['field'] = 'field_profile_email';
$handler->display->display_options['fields']['field_profile_email']['label'] = '';
$handler->display->display_options['fields']['field_profile_email']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['field_profile_email']['alter']['text'] = '<a href="mailto:[field_profile_email]">[field_profile_email-value]</a>';
$handler->display->display_options['fields']['field_profile_email']['element_type'] = 'p';
$handler->display->display_options['fields']['field_profile_email']['element_class'] = 'team-email';
$handler->display->display_options['fields']['field_profile_email']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_profile_email']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_profile_email']['element_default_classes'] = FALSE;
/* Field: Content: Photo */
$handler->display->display_options['fields']['field_profile_photo']['id'] = 'field_profile_photo';
$handler->display->display_options['fields']['field_profile_photo']['table'] = 'field_data_field_profile_photo';
$handler->display->display_options['fields']['field_profile_photo']['field'] = 'field_profile_photo';
$handler->display->display_options['fields']['field_profile_photo']['label'] = '';
$handler->display->display_options['fields']['field_profile_photo']['element_type'] = '0';
$handler->display->display_options['fields']['field_profile_photo']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_profile_photo']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['field_profile_photo']['element_wrapper_class'] = 'team-img';
$handler->display->display_options['fields']['field_profile_photo']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_profile_photo']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_profile_photo']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
);
$handler->display->display_options['fields']['field_profile_photo']['field_api_classes'] = TRUE;
/* Field: Content: Body */
$handler->display->display_options['fields']['body']['id'] = 'body';
$handler->display->display_options['fields']['body']['table'] = 'field_data_body';
$handler->display->display_options['fields']['body']['field'] = 'body';
$handler->display->display_options['fields']['body']['label'] = '';
$handler->display->display_options['fields']['body']['element_type'] = '0';
$handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['body']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['body']['field_api_classes'] = TRUE;
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: Nodequeue: Position */
$handler->display->display_options['sorts']['position']['id'] = 'position';
$handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
$handler->display->display_options['sorts']['position']['field'] = 'position';
$handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
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
    'profile' => 'profile',
);
$handler->display->display_options['filters']['type']['group'] = 1;
$handler->display->display_options['path'] = 'lab/team';
$handler->display->display_options['menu']['title'] = 'Our Team';
$handler->display->display_options['menu']['weight'] = '0';
$handler->display->display_options['menu']['name'] = 'main-menu';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;
$translatables['team'] = array(
    t('Master'),
    t('Our Team'),
    t('more'),
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
    t('All'),
    t('Region (field_taxonomy_region)'),
    t('Page'),
    t('Policy Lab Team Block'),
    t('Who We Are'),
    t('queue'),
    t('<a href="mailto:[field_profile_email]">[field_profile_email]</a>'),
    t('[title], [field_profile_title], <a href="mailto:[field_profile_email]">[field_profile_email]</a>'),
    t('Policy Lab Team Page'),
    t('<a href="mailto:[field_profile_email]">[field_profile_email-value]</a>'),
);