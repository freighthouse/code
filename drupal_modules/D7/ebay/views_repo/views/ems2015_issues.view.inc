<?php

$view = new view();
$view->name = 'ems2015_issues';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'EMS2015 Issues';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Featured Issue';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '3';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['row_plugin'] = 'fields';
/* Relationship: Nodequeue: Queue */
$handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
$handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
$handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
$handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
$handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
$handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'ems2015_featured_issues_queue' => 'ems2015_featured_issues_queue',
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
$handler->display->display_options['fields']['title']['element_label_type'] = '0';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Content: Body */
$handler->display->display_options['fields']['body']['id'] = 'body';
$handler->display->display_options['fields']['body']['table'] = 'field_data_body';
$handler->display->display_options['fields']['body']['field'] = 'body';
$handler->display->display_options['fields']['body']['label'] = '';
$handler->display->display_options['fields']['body']['exclude'] = TRUE;
$handler->display->display_options['fields']['body']['alter']['max_length'] = '140';
$handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
$handler->display->display_options['fields']['body']['element_type'] = '0';
$handler->display->display_options['fields']['body']['element_label_type'] = '0';
$handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['body']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['body']['type'] = 'text_plain';
$handler->display->display_options['fields']['body']['field_api_classes'] = TRUE;
/* Field: Content: Region */
$handler->display->display_options['fields']['field_taxonomy_region']['id'] = 'field_taxonomy_region';
$handler->display->display_options['fields']['field_taxonomy_region']['table'] = 'field_data_field_taxonomy_region';
$handler->display->display_options['fields']['field_taxonomy_region']['field'] = 'field_taxonomy_region';
$handler->display->display_options['fields']['field_taxonomy_region']['label'] = '';
$handler->display->display_options['fields']['field_taxonomy_region']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_taxonomy_region']['element_type'] = '0';
$handler->display->display_options['fields']['field_taxonomy_region']['element_label_type'] = '0';
$handler->display->display_options['fields']['field_taxonomy_region']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_taxonomy_region']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_taxonomy_region']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_taxonomy_region']['type'] = 'taxonomy_term_reference_plain';
$handler->display->display_options['fields']['field_taxonomy_region']['delta_offset'] = '0';
$handler->display->display_options['fields']['field_taxonomy_region']['field_api_classes'] = TRUE;
/* Field: Content: Path */
$handler->display->display_options['fields']['path']['id'] = 'path';
$handler->display->display_options['fields']['path']['table'] = 'node';
$handler->display->display_options['fields']['path']['field'] = 'path';
$handler->display->display_options['fields']['path']['label'] = '';
$handler->display->display_options['fields']['path']['exclude'] = TRUE;
$handler->display->display_options['fields']['path']['element_type'] = '0';
$handler->display->display_options['fields']['path']['element_label_type'] = '0';
$handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['path']['element_wrapper_type'] = '0';
/* Field: Global: Custom text */
$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
$handler->display->display_options['fields']['nothing']['table'] = 'views';
$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing']['label'] = '';
$handler->display->display_options['fields']['nothing']['alter']['text'] = '[title]
[body]
[field_taxonomy_region]
[path]';
$handler->display->display_options['fields']['nothing']['element_type'] = '0';
$handler->display->display_options['fields']['nothing']['element_label_type'] = '0';
$handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['nothing']['element_wrapper_type'] = '0';
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
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
    'issue' => 'issue',
);

/* Display: EMS2015 - Primary Featured Issue */
$handler = $view->new_display('block', 'EMS2015 - Primary Featured Issue', 'primary_feature');
$handler->display->display_options['defaults']['css_class'] = FALSE;
$handler->display->display_options['css_class'] = 'featured-issue';
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '8';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['relationships'] = FALSE;
/* Relationship: Nodequeue: Queue */
$handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
$handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
$handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
$handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
$handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
$handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'ems2015_featured_issues_queue_pr' => 'ems2015_featured_issues_queue_pr',
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
);
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_type'] = '0';
$handler->display->display_options['fields']['title']['element_label_type'] = '0';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Content: Region */
$handler->display->display_options['fields']['field_taxonomy_region']['id'] = 'field_taxonomy_region';
$handler->display->display_options['fields']['field_taxonomy_region']['table'] = 'field_data_field_taxonomy_region';
$handler->display->display_options['fields']['field_taxonomy_region']['field'] = 'field_taxonomy_region';
$handler->display->display_options['fields']['field_taxonomy_region']['label'] = '';
$handler->display->display_options['fields']['field_taxonomy_region']['element_type'] = '0';
$handler->display->display_options['fields']['field_taxonomy_region']['element_label_type'] = '0';
$handler->display->display_options['fields']['field_taxonomy_region']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_taxonomy_region']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_taxonomy_region']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_taxonomy_region']['type'] = 'taxonomy_term_reference_plain';
$handler->display->display_options['fields']['field_taxonomy_region']['delta_offset'] = '0';
$handler->display->display_options['fields']['field_taxonomy_region']['field_api_classes'] = TRUE;
/* Field: Content: Path */
$handler->display->display_options['fields']['path']['id'] = 'path';
$handler->display->display_options['fields']['path']['table'] = 'node';
$handler->display->display_options['fields']['path']['field'] = 'path';
$handler->display->display_options['fields']['path']['label'] = '';
$handler->display->display_options['fields']['path']['element_type'] = '0';
$handler->display->display_options['fields']['path']['element_label_type'] = '0';
$handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['path']['element_wrapper_type'] = '0';
/* Field: Content: Summary */
$handler->display->display_options['fields']['field_issue_summary']['id'] = 'field_issue_summary';
$handler->display->display_options['fields']['field_issue_summary']['table'] = 'field_data_field_issue_summary';
$handler->display->display_options['fields']['field_issue_summary']['field'] = 'field_issue_summary';
$handler->display->display_options['fields']['field_issue_summary']['label'] = '';
$handler->display->display_options['fields']['field_issue_summary']['alter']['max_length'] = '140';
$handler->display->display_options['fields']['field_issue_summary']['alter']['trim'] = TRUE;
$handler->display->display_options['fields']['field_issue_summary']['element_type'] = '0';
$handler->display->display_options['fields']['field_issue_summary']['element_label_type'] = '0';
$handler->display->display_options['fields']['field_issue_summary']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_issue_summary']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_issue_summary']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_issue_summary']['type'] = 'text_plain';
/* Field: Field: Take Action Group */
$handler->display->display_options['fields']['field_take_action_group']['id'] = 'field_take_action_group';
$handler->display->display_options['fields']['field_take_action_group']['table'] = 'field_data_field_take_action_group';
$handler->display->display_options['fields']['field_take_action_group']['field'] = 'field_take_action_group';
$handler->display->display_options['fields']['field_take_action_group']['label'] = '';
$handler->display->display_options['fields']['field_take_action_group']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_take_action_group']['element_type'] = '0';
$handler->display->display_options['fields']['field_take_action_group']['element_label_type'] = '0';
$handler->display->display_options['fields']['field_take_action_group']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_take_action_group']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_take_action_group']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_take_action_group']['settings'] = array(
    'view_mode' => 'full',
);
$handler->display->display_options['fields']['field_take_action_group']['delta_offset'] = '0';
$handler->display->display_options['fields']['field_take_action_group']['field_api_classes'] = TRUE;

/* Display: EMS2015 - Seconday Featured Issues */
$handler = $view->new_display('block', 'EMS2015 - Seconday Featured Issues', 'secondary_features');
$handler->display->display_options['defaults']['css_class'] = FALSE;
$handler->display->display_options['css_class'] = 'secondary-issues';
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '3';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_type'] = '0';
$handler->display->display_options['fields']['title']['element_label_type'] = '0';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Content: Region */
$handler->display->display_options['fields']['field_taxonomy_region']['id'] = 'field_taxonomy_region';
$handler->display->display_options['fields']['field_taxonomy_region']['table'] = 'field_data_field_taxonomy_region';
$handler->display->display_options['fields']['field_taxonomy_region']['field'] = 'field_taxonomy_region';
$handler->display->display_options['fields']['field_taxonomy_region']['label'] = '';
$handler->display->display_options['fields']['field_taxonomy_region']['element_type'] = '0';
$handler->display->display_options['fields']['field_taxonomy_region']['element_label_type'] = '0';
$handler->display->display_options['fields']['field_taxonomy_region']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_taxonomy_region']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_taxonomy_region']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_taxonomy_region']['type'] = 'taxonomy_term_reference_plain';
$handler->display->display_options['fields']['field_taxonomy_region']['delta_offset'] = '0';
$handler->display->display_options['fields']['field_taxonomy_region']['field_api_classes'] = TRUE;
/* Field: Content: Path */
$handler->display->display_options['fields']['path']['id'] = 'path';
$handler->display->display_options['fields']['path']['table'] = 'node';
$handler->display->display_options['fields']['path']['field'] = 'path';
$handler->display->display_options['fields']['path']['label'] = '';
$handler->display->display_options['fields']['path']['element_type'] = '0';
$handler->display->display_options['fields']['path']['element_label_type'] = '0';
$handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['path']['element_wrapper_type'] = '0';
/* Field: Content: Summary */
$handler->display->display_options['fields']['field_issue_summary']['id'] = 'field_issue_summary';
$handler->display->display_options['fields']['field_issue_summary']['table'] = 'field_data_field_issue_summary';
$handler->display->display_options['fields']['field_issue_summary']['field'] = 'field_issue_summary';
$handler->display->display_options['fields']['field_issue_summary']['label'] = '';
$handler->display->display_options['fields']['field_issue_summary']['alter']['max_length'] = '140';
$handler->display->display_options['fields']['field_issue_summary']['alter']['trim'] = TRUE;
$handler->display->display_options['fields']['field_issue_summary']['element_type'] = '0';
$handler->display->display_options['fields']['field_issue_summary']['element_label_type'] = '0';
$handler->display->display_options['fields']['field_issue_summary']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_issue_summary']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_issue_summary']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_issue_summary']['type'] = 'text_plain';

/* Display: EMS2015 - Issue Listing */
$handler = $view->new_display('block', 'EMS2015 - Issue Listing', 'issues_listing');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Issue Listing';
$handler->display->display_options['defaults']['css_class'] = FALSE;
$handler->display->display_options['css_class'] = 'issues-listing';
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '0';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['relationships'] = FALSE;
/* Relationship: Nodequeue: Queue */
$handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
$handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
$handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
$handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
$handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'ems2015_featured_issues_queue_pr' => 'ems2015_featured_issues_queue_pr',
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
    'pac_board_member_listing' => 0,
    'pac_employee_spotlight' => 0,
);
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_type'] = '0';
$handler->display->display_options['fields']['title']['element_label_type'] = '0';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Content: Region */
$handler->display->display_options['fields']['field_taxonomy_region']['id'] = 'field_taxonomy_region';
$handler->display->display_options['fields']['field_taxonomy_region']['table'] = 'field_data_field_taxonomy_region';
$handler->display->display_options['fields']['field_taxonomy_region']['field'] = 'field_taxonomy_region';
$handler->display->display_options['fields']['field_taxonomy_region']['label'] = '';
$handler->display->display_options['fields']['field_taxonomy_region']['element_type'] = '0';
$handler->display->display_options['fields']['field_taxonomy_region']['element_label_type'] = '0';
$handler->display->display_options['fields']['field_taxonomy_region']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_taxonomy_region']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_taxonomy_region']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_taxonomy_region']['type'] = 'taxonomy_term_reference_plain';
$handler->display->display_options['fields']['field_taxonomy_region']['delta_offset'] = '0';
$handler->display->display_options['fields']['field_taxonomy_region']['field_api_classes'] = TRUE;
/* Field: Content: Path */
$handler->display->display_options['fields']['path']['id'] = 'path';
$handler->display->display_options['fields']['path']['table'] = 'node';
$handler->display->display_options['fields']['path']['field'] = 'path';
$handler->display->display_options['fields']['path']['label'] = '';
$handler->display->display_options['fields']['path']['element_type'] = '0';
$handler->display->display_options['fields']['path']['element_label_type'] = '0';
$handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['path']['element_wrapper_type'] = '0';
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: Content: Title */
$handler->display->display_options['sorts']['title']['id'] = 'title';
$handler->display->display_options['sorts']['title']['table'] = 'node';
$handler->display->display_options['sorts']['title']['field'] = 'title';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['filter_groups']['operator'] = 'OR';
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
/* Filter criterion: Nodequeue: In queue */
$handler->display->display_options['filters']['in_queue']['id'] = 'in_queue';
$handler->display->display_options['filters']['in_queue']['table'] = 'nodequeue_nodes';
$handler->display->display_options['filters']['in_queue']['field'] = 'in_queue';
$handler->display->display_options['filters']['in_queue']['relationship'] = 'nodequeue_rel';
$handler->display->display_options['filters']['in_queue']['value'] = '0';

/* Display: EMS2015 - Primary Featured Homepage */
$handler = $view->new_display('block', 'EMS2015 - Primary Featured Homepage', 'block_1');
$handler->display->display_options['defaults']['css_class'] = FALSE;
$handler->display->display_options['css_class'] = 'featured-issue';
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '1';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['relationships'] = FALSE;
/* Relationship: Nodequeue: Queue */
$handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
$handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
$handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
$handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
$handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
$handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'ems2015_featured_issues_queue_pr' => 'ems2015_featured_issues_queue_pr',
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
);
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_type'] = '0';
$handler->display->display_options['fields']['title']['element_label_type'] = '0';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Content: Region */
$handler->display->display_options['fields']['field_taxonomy_region']['id'] = 'field_taxonomy_region';
$handler->display->display_options['fields']['field_taxonomy_region']['table'] = 'field_data_field_taxonomy_region';
$handler->display->display_options['fields']['field_taxonomy_region']['field'] = 'field_taxonomy_region';
$handler->display->display_options['fields']['field_taxonomy_region']['label'] = '';
$handler->display->display_options['fields']['field_taxonomy_region']['element_type'] = '0';
$handler->display->display_options['fields']['field_taxonomy_region']['element_label_type'] = '0';
$handler->display->display_options['fields']['field_taxonomy_region']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_taxonomy_region']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_taxonomy_region']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_taxonomy_region']['type'] = 'taxonomy_term_reference_plain';
$handler->display->display_options['fields']['field_taxonomy_region']['group_rows'] = FALSE;
$handler->display->display_options['fields']['field_taxonomy_region']['delta_offset'] = '0';
$handler->display->display_options['fields']['field_taxonomy_region']['field_api_classes'] = TRUE;
/* Field: Content: Path */
$handler->display->display_options['fields']['path']['id'] = 'path';
$handler->display->display_options['fields']['path']['table'] = 'node';
$handler->display->display_options['fields']['path']['field'] = 'path';
$handler->display->display_options['fields']['path']['label'] = '';
$handler->display->display_options['fields']['path']['element_type'] = '0';
$handler->display->display_options['fields']['path']['element_label_type'] = '0';
$handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['path']['element_wrapper_type'] = '0';
/* Field: Content: Summary */
$handler->display->display_options['fields']['field_issue_summary']['id'] = 'field_issue_summary';
$handler->display->display_options['fields']['field_issue_summary']['table'] = 'field_data_field_issue_summary';
$handler->display->display_options['fields']['field_issue_summary']['field'] = 'field_issue_summary';
$handler->display->display_options['fields']['field_issue_summary']['label'] = '';
$handler->display->display_options['fields']['field_issue_summary']['alter']['max_length'] = '140';
$handler->display->display_options['fields']['field_issue_summary']['alter']['trim'] = TRUE;
$handler->display->display_options['fields']['field_issue_summary']['element_type'] = '0';
$handler->display->display_options['fields']['field_issue_summary']['element_label_type'] = '0';
$handler->display->display_options['fields']['field_issue_summary']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_issue_summary']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_issue_summary']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_issue_summary']['type'] = 'text_plain';
/* Field: Field: Take Action Group */
$handler->display->display_options['fields']['field_take_action_group']['id'] = 'field_take_action_group';
$handler->display->display_options['fields']['field_take_action_group']['table'] = 'field_data_field_take_action_group';
$handler->display->display_options['fields']['field_take_action_group']['field'] = 'field_take_action_group';
$handler->display->display_options['fields']['field_take_action_group']['label'] = '';
$handler->display->display_options['fields']['field_take_action_group']['element_type'] = '0';
$handler->display->display_options['fields']['field_take_action_group']['element_label_type'] = '0';
$handler->display->display_options['fields']['field_take_action_group']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_take_action_group']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_take_action_group']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_take_action_group']['settings'] = array(
    'view_mode' => 'full',
);
$handler->display->display_options['fields']['field_take_action_group']['delta_offset'] = '0';
$handler->display->display_options['fields']['field_take_action_group']['field_api_classes'] = TRUE;
$translatables['ems2015_issues'] = array(
    t('Master'),
    t('Featured Issue'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('queue'),
    t('[title]
[body]
[field_taxonomy_region]
[path]'),
    t('EMS2015 - Primary Featured Issue'),
    t('EMS2015 - Seconday Featured Issues'),
    t('EMS2015 - Issue Listing'),
    t('Issue Listing'),
    t('EMS2015 - Primary Featured Homepage'),
);