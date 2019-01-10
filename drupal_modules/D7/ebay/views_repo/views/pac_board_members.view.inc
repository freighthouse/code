<?php

$view = new view();
$view->name = 'pac_board_members';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'PAC Board Members';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'PAC Board Members';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'list';
$handler->display->display_options['row_plugin'] = 'fields';
/* Field: Content: Image */
$handler->display->display_options['fields']['field_pac_board_member_headshot']['id'] = 'field_pac_board_member_headshot';
$handler->display->display_options['fields']['field_pac_board_member_headshot']['table'] = 'field_data_field_pac_board_member_headshot';
$handler->display->display_options['fields']['field_pac_board_member_headshot']['field'] = 'field_pac_board_member_headshot';
$handler->display->display_options['fields']['field_pac_board_member_headshot']['label'] = '';
$handler->display->display_options['fields']['field_pac_board_member_headshot']['element_type'] = '0';
$handler->display->display_options['fields']['field_pac_board_member_headshot']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_pac_board_member_headshot']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_pac_board_member_headshot']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_pac_board_member_headshot']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_pac_board_member_headshot']['settings'] = array(
    'image_style' => 'ems2015_-_featured_member_thumbnail__200x200_',
    'image_link' => '',
);
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_type'] = 'h3';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['field_pac_board_member_title']['id'] = 'field_pac_board_member_title';
$handler->display->display_options['fields']['field_pac_board_member_title']['table'] = 'field_data_field_pac_board_member_title';
$handler->display->display_options['fields']['field_pac_board_member_title']['field'] = 'field_pac_board_member_title';
$handler->display->display_options['fields']['field_pac_board_member_title']['label'] = '';
$handler->display->display_options['fields']['field_pac_board_member_title']['element_type'] = 'p';
$handler->display->display_options['fields']['field_pac_board_member_title']['element_class'] = 'board-title';
$handler->display->display_options['fields']['field_pac_board_member_title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_pac_board_member_title']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_pac_board_member_title']['element_default_classes'] = FALSE;
/* Field: Content: Location */
$handler->display->display_options['fields']['field_pac_board_member_company']['id'] = 'field_pac_board_member_company';
$handler->display->display_options['fields']['field_pac_board_member_company']['table'] = 'field_data_field_pac_board_member_company';
$handler->display->display_options['fields']['field_pac_board_member_company']['field'] = 'field_pac_board_member_company';
$handler->display->display_options['fields']['field_pac_board_member_company']['label'] = '';
$handler->display->display_options['fields']['field_pac_board_member_company']['element_type'] = 'p';
$handler->display->display_options['fields']['field_pac_board_member_company']['element_class'] = 'function';
$handler->display->display_options['fields']['field_pac_board_member_company']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_pac_board_member_company']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_pac_board_member_company']['element_default_classes'] = FALSE;
/* Sort criterion: Content: Title */
$handler->display->display_options['sorts']['title']['id'] = 'title';
$handler->display->display_options['sorts']['title']['table'] = 'node';
$handler->display->display_options['sorts']['title']['field'] = 'title';
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
    'pac_board_member' => 'pac_board_member',
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
    'pac_board_member_listing' => 'pac_board_member_listing',
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
    'policy_labs_team' => 0,
    'action_center_spotlight' => 0,
    'ems2015_featured_issues_queue' => 0,
    'policy_papers_mega_menu' => 0,
    'sban_featured_members' => 0,
    'issues_main_navigation' => 0,
    'ems2015_featured_issues_queue_pr' => 0,
);
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: Nodequeue: Position */
$handler->display->display_options['sorts']['position']['id'] = 'position';
$handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
$handler->display->display_options['sorts']['position']['field'] = 'position';
$handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
$translatables['pac_board_members'] = array(
    t('Master'),
    t('PAC Board Members'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Block'),
    t('queue'),
);