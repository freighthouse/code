<?php

$view = new view();
$view->name = 'employee_spotlight';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'Employee Spotlight';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Employee Spotlight';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '1';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['default_field_elements'] = FALSE;
/* Field: Content: Photo */
$handler->display->display_options['fields']['field_employee_headshot']['id'] = 'field_employee_headshot';
$handler->display->display_options['fields']['field_employee_headshot']['table'] = 'field_data_field_employee_headshot';
$handler->display->display_options['fields']['field_employee_headshot']['field'] = 'field_employee_headshot';
$handler->display->display_options['fields']['field_employee_headshot']['label'] = '';
$handler->display->display_options['fields']['field_employee_headshot']['element_type'] = '0';
$handler->display->display_options['fields']['field_employee_headshot']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_employee_headshot']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_employee_headshot']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_employee_headshot']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_employee_headshot']['settings'] = array(
    'image_style' => 'headshot__200x200_',
    'image_link' => '',
);
/* Field: Content: Job Position */
$handler->display->display_options['fields']['field_employee_job_position']['id'] = 'field_employee_job_position';
$handler->display->display_options['fields']['field_employee_job_position']['table'] = 'field_data_field_employee_job_position';
$handler->display->display_options['fields']['field_employee_job_position']['field'] = 'field_employee_job_position';
$handler->display->display_options['fields']['field_employee_job_position']['label'] = '';
$handler->display->display_options['fields']['field_employee_job_position']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_employee_job_position']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['field_employee_job_position']['alter']['text'] = '<span class="job-title">[field_employee_job_position]</span>';
$handler->display->display_options['fields']['field_employee_job_position']['element_type'] = '0';
$handler->display->display_options['fields']['field_employee_job_position']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_employee_job_position']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_employee_job_position']['element_default_classes'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['text'] = '<div class="text-wrapper">
<h3><span class="name">[title]</span>
[field_employee_job_position]</h3>';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Content: Description/Quote */
$handler->display->display_options['fields']['field_employee_description_quote']['id'] = 'field_employee_description_quote';
$handler->display->display_options['fields']['field_employee_description_quote']['table'] = 'field_data_field_employee_description_quote';
$handler->display->display_options['fields']['field_employee_description_quote']['field'] = 'field_employee_description_quote';
$handler->display->display_options['fields']['field_employee_description_quote']['label'] = '';
$handler->display->display_options['fields']['field_employee_description_quote']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['field_employee_description_quote']['alter']['text'] = '[field_employee_description_quote]
</div>';
$handler->display->display_options['fields']['field_employee_description_quote']['alter']['preserve_tags'] = '<strong> <b> <i> <em>';
$handler->display->display_options['fields']['field_employee_description_quote']['element_type'] = '0';
$handler->display->display_options['fields']['field_employee_description_quote']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_employee_description_quote']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_employee_description_quote']['element_default_classes'] = FALSE;
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
    'pac_employee_spotlight' => 'pac_employee_spotlight',
);

/* Display: Block */
$handler = $view->new_display('block', 'Block', 'block');

/* Display: PAC2015 - Employee Spotlight */
$handler = $view->new_display('block', 'PAC2015 - Employee Spotlight', 'block_1');
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '2';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['relationships'] = FALSE;
/* Relationship: Nodequeue: Queue */
$handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
$handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
$handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
$handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
$handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
$handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'pac_employee_spotlight' => 'pac_employee_spotlight',
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
    'pac_board_member_listing' => 0,
);
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: Nodequeue: Position */
$handler->display->display_options['sorts']['position']['id'] = 'position';
$handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
$handler->display->display_options['sorts']['position']['field'] = 'position';
$handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
$translatables['employee_spotlight'] = array(
    t('Master'),
    t('Employee Spotlight'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('<span class="job-title">[field_employee_job_position]</span>'),
    t('<div class="text-wrapper">
<h3><span class="name">[title]</span>
[field_employee_job_position]</h3>'),
    t('[field_employee_description_quote]
</div>'),
    t('Block'),
    t('PAC2015 - Employee Spotlight'),
    t('queue'),
);