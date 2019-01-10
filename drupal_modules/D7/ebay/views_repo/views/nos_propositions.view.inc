<?php

$view = new view();
$view->name = 'nos_propositions';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'Nos propositions';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Nos propositions';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
        'field' => 'title',
        'rendered' => 1,
        'rendered_strip' => 0,
    ),
);
$handler->display->display_options['row_plugin'] = 'fields';
/* Relationship: Nodequeue: Queue */
$handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
$handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
$handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
$handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
$handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'nos_propositions' => 'nos_propositions',
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
    'pac_employee_spotlight' => 0,
);
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['text'] = '<a name="[title]"></a>[title]';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
/* Field: Content: Image */
$handler->display->display_options['fields']['field_nos_image']['id'] = 'field_nos_image';
$handler->display->display_options['fields']['field_nos_image']['table'] = 'field_data_field_nos_image';
$handler->display->display_options['fields']['field_nos_image']['field'] = 'field_nos_image';
$handler->display->display_options['fields']['field_nos_image']['label'] = '';
$handler->display->display_options['fields']['field_nos_image']['element_type'] = '0';
$handler->display->display_options['fields']['field_nos_image']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_nos_image']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_nos_image']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_nos_image']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_nos_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
);
$handler->display->display_options['fields']['field_nos_image']['field_api_classes'] = TRUE;
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
    'nos_propositions' => 'nos_propositions',
);

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['enabled'] = FALSE;
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
/* Field: Content: Body */
$handler->display->display_options['fields']['body']['id'] = 'body';
$handler->display->display_options['fields']['body']['table'] = 'field_data_body';
$handler->display->display_options['fields']['body']['field'] = 'body';
$handler->display->display_options['fields']['body']['label'] = '';
$handler->display->display_options['fields']['body']['exclude'] = TRUE;
$handler->display->display_options['fields']['body']['element_type'] = '0';
$handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['body']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['body']['field_api_classes'] = TRUE;
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: Content: Post date */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'node';
$handler->display->display_options['sorts']['created']['field'] = 'created';
$handler->display->display_options['path'] = 'ebaysengage/nos-propositions';

/* Display: Block */
$handler = $view->new_display('block', 'Block', 'block');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'NOS PROPOSITIONS';
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '5';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['header'] = FALSE;
/* Header: Global: Text area */
$handler->display->display_options['header']['area']['id'] = 'area';
$handler->display->display_options['header']['area']['table'] = 'views';
$handler->display->display_options['header']['area']['field'] = 'area';
$handler->display->display_options['header']['area']['content'] = 'Pour relever ce défi, eBay formule 3 pistes d’action pour booster la numérisation et l’internationalisation des entreprises françaises :';
$handler->display->display_options['header']['area']['format'] = 'full_html';
$handler->display->display_options['defaults']['footer'] = FALSE;
/* Footer: Global: Text area */
$handler->display->display_options['footer']['area']['id'] = 'area';
$handler->display->display_options['footer']['area']['table'] = 'views';
$handler->display->display_options['footer']['area']['field'] = 'area';
$handler->display->display_options['footer']['area']['content'] = '<a style="text-align:center" href="/fr/ebaysengage/nos-propositions">Soutenez nos propositions</a>';
$handler->display->display_options['footer']['area']['format'] = 'full_html';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Image */
$handler->display->display_options['fields']['field_nos_image']['id'] = 'field_nos_image';
$handler->display->display_options['fields']['field_nos_image']['table'] = 'field_data_field_nos_image';
$handler->display->display_options['fields']['field_nos_image']['field'] = 'field_nos_image';
$handler->display->display_options['fields']['field_nos_image']['label'] = '';
$handler->display->display_options['fields']['field_nos_image']['element_type'] = '0';
$handler->display->display_options['fields']['field_nos_image']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_nos_image']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_nos_image']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_nos_image']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_nos_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
);
$handler->display->display_options['fields']['field_nos_image']['field_api_classes'] = TRUE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['path'] = 'ebaysengage/nos-propositions#[title]';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_type'] = 'h2';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Content: Body */
$handler->display->display_options['fields']['body']['id'] = 'body';
$handler->display->display_options['fields']['body']['table'] = 'field_data_body';
$handler->display->display_options['fields']['body']['field'] = 'body';
$handler->display->display_options['fields']['body']['label'] = '';
$handler->display->display_options['fields']['body']['element_type'] = 'p';
$handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['body']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
$handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '360',
);
$handler->display->display_options['fields']['body']['field_api_classes'] = TRUE;

/* Display: Block */
$handler = $view->new_display('block', 'Block', 'block_1');
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['relationships'] = FALSE;
/* Relationship: Nodequeue: Queue */
$handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
$handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
$handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
$handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
$handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'nos_propositions' => 'nos_propositions',
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
    'pac_employee_spotlight' => 0,
);
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Hero Image */
$handler->display->display_options['fields']['field_hero_image_small']['id'] = 'field_hero_image_small';
$handler->display->display_options['fields']['field_hero_image_small']['table'] = 'field_data_field_hero_image_small';
$handler->display->display_options['fields']['field_hero_image_small']['field'] = 'field_hero_image_small';
$handler->display->display_options['fields']['field_hero_image_small']['label'] = '';
$handler->display->display_options['fields']['field_hero_image_small']['element_type'] = '0';
$handler->display->display_options['fields']['field_hero_image_small']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_hero_image_small']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_hero_image_small']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_hero_image_small']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_hero_image_small']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
);
$handler->display->display_options['fields']['field_hero_image_small']['field_api_classes'] = TRUE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['text'] = '<a name="[title]"></a>[title]';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_type'] = 'h2';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
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
/* Field: Content: Body3 */
$handler->display->display_options['fields']['field_body3']['id'] = 'field_body3';
$handler->display->display_options['fields']['field_body3']['table'] = 'field_data_field_body3';
$handler->display->display_options['fields']['field_body3']['field'] = 'field_body3';
$handler->display->display_options['fields']['field_body3']['label'] = '';
$handler->display->display_options['fields']['field_body3']['element_type'] = '0';
$handler->display->display_options['fields']['field_body3']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_body3']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_body3']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_body3']['settings'] = array(
    'view_mode' => 'full',
);
$handler->display->display_options['fields']['field_body3']['delta_offset'] = '0';
$handler->display->display_options['fields']['field_body3']['field_api_classes'] = TRUE;
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: Nodequeue: Position */
$handler->display->display_options['sorts']['position']['id'] = 'position';
$handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
$handler->display->display_options['sorts']['position']['field'] = 'position';
$handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
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
    'nos_propositions' => 'nos_propositions',
);
$handler->display->display_options['block_description'] = 'NoS Propositions Page';
$translatables['nos_propositions'] = array(
    t('Master'),
    t('Nos propositions'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('queue'),
    t('<a name="[title]"></a>[title]'),
    t('Page'),
    t('Block'),
    t('NOS PROPOSITIONS'),
    t('Pour relever ce défi, eBay formule 3 pistes d’action pour booster la numérisation et l’internationalisation des entreprises françaises :'),
    t('<a style="text-align:center" href="/fr/ebaysengage/nos-propositions">Soutenez nos propositions</a>'),
    t('NoS Propositions Page'),
);