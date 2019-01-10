<?php

$view = new view();
$view->name = 'ems2015_members';
$view->description = 'View for Featured Seller block and Sellers list';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'EMS2015 - Members';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Featured Member';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['query_comment'] = FALSE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '1';
$handler->display->display_options['style_plugin'] = 'list';
$handler->display->display_options['row_plugin'] = 'fields';
/* Field: Content: Photo */
$handler->display->display_options['fields']['field_member_photo']['id'] = 'field_member_photo';
$handler->display->display_options['fields']['field_member_photo']['table'] = 'field_data_field_member_photo';
$handler->display->display_options['fields']['field_member_photo']['field'] = 'field_member_photo';
$handler->display->display_options['fields']['field_member_photo']['label'] = '';
$handler->display->display_options['fields']['field_member_photo']['element_type'] = '0';
$handler->display->display_options['fields']['field_member_photo']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_member_photo']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_member_photo']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_member_photo']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_member_photo']['settings'] = array(
    'image_style' => 'featured_member_thumb',
    'image_link' => 'content',
);
$handler->display->display_options['fields']['field_member_photo']['field_api_classes'] = TRUE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
/* Field: Content: Business Name */
$handler->display->display_options['fields']['field_member_business_name']['id'] = 'field_member_business_name';
$handler->display->display_options['fields']['field_member_business_name']['table'] = 'field_data_field_member_business_name';
$handler->display->display_options['fields']['field_member_business_name']['field'] = 'field_member_business_name';
$handler->display->display_options['fields']['field_member_business_name']['label'] = '';
$handler->display->display_options['fields']['field_member_business_name']['element_type'] = 'h3';
$handler->display->display_options['fields']['field_member_business_name']['element_class'] = 'member-business-name';
$handler->display->display_options['fields']['field_member_business_name']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_member_business_name']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_member_business_name']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_member_business_name']['field_api_classes'] = TRUE;
/* Field: Content: Business Location */
$handler->display->display_options['fields']['field_member_business_location']['id'] = 'field_member_business_location';
$handler->display->display_options['fields']['field_member_business_location']['table'] = 'field_data_field_member_business_location';
$handler->display->display_options['fields']['field_member_business_location']['field'] = 'field_member_business_location';
$handler->display->display_options['fields']['field_member_business_location']['label'] = '';
$handler->display->display_options['fields']['field_member_business_location']['element_type'] = '0';
$handler->display->display_options['fields']['field_member_business_location']['element_label_type'] = '0';
$handler->display->display_options['fields']['field_member_business_location']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_member_business_location']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_member_business_location']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_member_business_location']['type'] = 'text_plain';
/* Field: Content: Body */
$handler->display->display_options['fields']['body']['id'] = 'body';
$handler->display->display_options['fields']['body']['table'] = 'field_data_body';
$handler->display->display_options['fields']['body']['field'] = 'body';
$handler->display->display_options['fields']['body']['label'] = '';
$handler->display->display_options['fields']['body']['element_type'] = '0';
$handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['body']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
$handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '300',
);
$handler->display->display_options['fields']['body']['field_api_classes'] = TRUE;
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
    'member' => 'member',
);
$handler->display->display_options['filters']['type']['group'] = 1;
/* Filter criterion: Content: Region (field_seller_region) */
$handler->display->display_options['filters']['field_seller_region_tid_1']['id'] = 'field_seller_region_tid_1';
$handler->display->display_options['filters']['field_seller_region_tid_1']['table'] = 'field_data_field_seller_region';
$handler->display->display_options['filters']['field_seller_region_tid_1']['field'] = 'field_seller_region_tid';
$handler->display->display_options['filters']['field_seller_region_tid_1']['value'] = array(
    1 => '1',
);
$handler->display->display_options['filters']['field_seller_region_tid_1']['group'] = 1;
$handler->display->display_options['filters']['field_seller_region_tid_1']['type'] = 'select';
$handler->display->display_options['filters']['field_seller_region_tid_1']['vocabulary'] = 'region';

/* Display: EMS2015 - Featured Members Page */
$handler = $view->new_display('page', 'EMS2015 - Featured Members Page', 'page_1');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Featured Members';
$handler->display->display_options['defaults']['css_class'] = FALSE;
$handler->display->display_options['css_class'] = 'featured-members-page';
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['header'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Photo */
$handler->display->display_options['fields']['field_member_photo']['id'] = 'field_member_photo';
$handler->display->display_options['fields']['field_member_photo']['table'] = 'field_data_field_member_photo';
$handler->display->display_options['fields']['field_member_photo']['field'] = 'field_member_photo';
$handler->display->display_options['fields']['field_member_photo']['label'] = '';
$handler->display->display_options['fields']['field_member_photo']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_member_photo']['element_type'] = '0';
$handler->display->display_options['fields']['field_member_photo']['element_label_type'] = '0';
$handler->display->display_options['fields']['field_member_photo']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_member_photo']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_member_photo']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_member_photo']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_member_photo']['settings'] = array(
    'image_style' => 'ems2015_-_featured_member_thumbnail__200x200_',
    'image_link' => '',
);
$handler->display->display_options['fields']['field_member_photo']['field_api_classes'] = TRUE;
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
/* Field: Content: Business Name */
$handler->display->display_options['fields']['field_member_business_name']['id'] = 'field_member_business_name';
$handler->display->display_options['fields']['field_member_business_name']['table'] = 'field_data_field_member_business_name';
$handler->display->display_options['fields']['field_member_business_name']['field'] = 'field_member_business_name';
$handler->display->display_options['fields']['field_member_business_name']['label'] = '';
$handler->display->display_options['fields']['field_member_business_name']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_member_business_name']['element_type'] = '0';
$handler->display->display_options['fields']['field_member_business_name']['element_label_type'] = '0';
$handler->display->display_options['fields']['field_member_business_name']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_member_business_name']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_member_business_name']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_member_business_name']['type'] = 'text_plain';
$handler->display->display_options['fields']['field_member_business_name']['field_api_classes'] = TRUE;
/* Field: Content: Business Location */
$handler->display->display_options['fields']['field_member_business_location']['id'] = 'field_member_business_location';
$handler->display->display_options['fields']['field_member_business_location']['table'] = 'field_data_field_member_business_location';
$handler->display->display_options['fields']['field_member_business_location']['field'] = 'field_member_business_location';
$handler->display->display_options['fields']['field_member_business_location']['label'] = '';
$handler->display->display_options['fields']['field_member_business_location']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_member_business_location']['element_type'] = '0';
$handler->display->display_options['fields']['field_member_business_location']['element_label_type'] = '0';
$handler->display->display_options['fields']['field_member_business_location']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_member_business_location']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_member_business_location']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_member_business_location']['type'] = 'text_plain';
/* Field: Content: Body */
$handler->display->display_options['fields']['body']['id'] = 'body';
$handler->display->display_options['fields']['body']['table'] = 'field_data_body';
$handler->display->display_options['fields']['body']['field'] = 'body';
$handler->display->display_options['fields']['body']['label'] = '';
$handler->display->display_options['fields']['body']['exclude'] = TRUE;
$handler->display->display_options['fields']['body']['element_type'] = '0';
$handler->display->display_options['fields']['body']['element_label_type'] = '0';
$handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['body']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
$handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '300',
);
$handler->display->display_options['fields']['body']['field_api_classes'] = TRUE;
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
$handler->display->display_options['fields']['path']['element_default_classes'] = FALSE;
/* Field: Global: Custom text */
$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
$handler->display->display_options['fields']['nothing']['table'] = 'views';
$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing']['label'] = '';
$handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="featured-member-listing-wrapper">
<a class="featured-member-link" href="[path]">
<div class="featured-member-photo">[field_member_photo]</div>
<div class="featured-member-title">[title]</div>
<div class="featured-member-business">[field_member_business_name]<br /><div class="featured-member-business-location">[field_member_business_location]</div></div>
<div class="featured-member-location">[body]</div>
</a>
</div>';
$handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: Content: Title */
$handler->display->display_options['sorts']['title']['id'] = 'title';
$handler->display->display_options['sorts']['title']['table'] = 'node';
$handler->display->display_options['sorts']['title']['field'] = 'title';
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
    'member' => 'member',
);
$handler->display->display_options['filters']['type']['group'] = 1;
$handler->display->display_options['path'] = 'featured-members';

/* Display: EMS2015 - Featured Member */
$handler = $view->new_display('block', 'EMS2015 - Featured Member', 'block');
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
$handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
$handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
$handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'featured_member' => 'featured_member',
    'spotlights' => 0,
    'team_profiles' => 0,
    'resources' => 0,
    'spotlights_australia' => 0,
    'spotlights_asia_pacific' => 0,
    'spotlights_europe' => 0,
    'spotlights_global' => 0,
    'photo_gallery_2012_dc_fly_in' => 0,
);
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Photo */
$handler->display->display_options['fields']['field_member_photo']['id'] = 'field_member_photo';
$handler->display->display_options['fields']['field_member_photo']['table'] = 'field_data_field_member_photo';
$handler->display->display_options['fields']['field_member_photo']['field'] = 'field_member_photo';
$handler->display->display_options['fields']['field_member_photo']['label'] = '';
$handler->display->display_options['fields']['field_member_photo']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_member_photo']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_member_photo']['settings'] = array(
    'image_style' => 'featured_member_background',
    'image_link' => '',
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
/* Field: Content: Business Name */
$handler->display->display_options['fields']['field_member_business_name']['id'] = 'field_member_business_name';
$handler->display->display_options['fields']['field_member_business_name']['table'] = 'field_data_field_member_business_name';
$handler->display->display_options['fields']['field_member_business_name']['field'] = 'field_member_business_name';
$handler->display->display_options['fields']['field_member_business_name']['label'] = '';
$handler->display->display_options['fields']['field_member_business_name']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_member_business_name']['type'] = 'text_plain';
/* Field: Content: Business Location */
$handler->display->display_options['fields']['field_member_business_location']['id'] = 'field_member_business_location';
$handler->display->display_options['fields']['field_member_business_location']['table'] = 'field_data_field_member_business_location';
$handler->display->display_options['fields']['field_member_business_location']['field'] = 'field_member_business_location';
$handler->display->display_options['fields']['field_member_business_location']['label'] = '';
$handler->display->display_options['fields']['field_member_business_location']['alter']['strip_tags'] = TRUE;
$handler->display->display_options['fields']['field_member_business_location']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_member_business_location']['type'] = 'text_plain';
/* Field: Global: Custom text */
$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
$handler->display->display_options['fields']['nothing']['table'] = 'views';
$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing']['label'] = '';
$handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="featured-member-view-more"><a href="/featured-members">Featured Members</a></div>';
$handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
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
    'member' => 'member',
);
/* Filter criterion: Content: Region (field_seller_region) */
$handler->display->display_options['filters']['field_seller_region_tid']['id'] = 'field_seller_region_tid';
$handler->display->display_options['filters']['field_seller_region_tid']['table'] = 'field_data_field_seller_region';
$handler->display->display_options['filters']['field_seller_region_tid']['field'] = 'field_seller_region_tid';
$handler->display->display_options['filters']['field_seller_region_tid']['value'] = array(
    6 => '6',
    9 => '9',
    2 => '2',
    4 => '4',
    3 => '3',
    7 => '7',
    8 => '8',
    1 => '1',
);
$handler->display->display_options['filters']['field_seller_region_tid']['group'] = '0';
$handler->display->display_options['filters']['field_seller_region_tid']['type'] = 'select';
$handler->display->display_options['filters']['field_seller_region_tid']['vocabulary'] = 'region';

/* Display: EMS2015 - SBAN Featured Member */
$handler = $view->new_display('block', 'EMS2015 - SBAN Featured Member', 'block_1');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Small Business Spotlight';
$handler->display->display_options['defaults']['css_class'] = FALSE;
$handler->display->display_options['css_class'] = 'featured-members-page';
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '2';
$handler->display->display_options['pager']['options']['offset'] = '0';
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
$handler->display->display_options['header']['area']['content'] = '<p>We have SBAN members all over the world.  Here are their SBAN involvement stories:</p>';
$handler->display->display_options['header']['area']['format'] = 'filtered_html';
$handler->display->display_options['defaults']['relationships'] = FALSE;
/* Relationship: Nodequeue: Queue */
$handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
$handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
$handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
$handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
$handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
$handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'sban_featured_members' => 'sban_featured_members',
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
);
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Photo */
$handler->display->display_options['fields']['field_member_photo']['id'] = 'field_member_photo';
$handler->display->display_options['fields']['field_member_photo']['table'] = 'field_data_field_member_photo';
$handler->display->display_options['fields']['field_member_photo']['field'] = 'field_member_photo';
$handler->display->display_options['fields']['field_member_photo']['label'] = '';
$handler->display->display_options['fields']['field_member_photo']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_member_photo']['element_type'] = '0';
$handler->display->display_options['fields']['field_member_photo']['element_label_type'] = '0';
$handler->display->display_options['fields']['field_member_photo']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_member_photo']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_member_photo']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_member_photo']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_member_photo']['settings'] = array(
    'image_style' => 'ems2015_-_featured_member_thumbnail__200x200_',
    'image_link' => '',
);
$handler->display->display_options['fields']['field_member_photo']['field_api_classes'] = TRUE;
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
/* Field: Content: Business Name */
$handler->display->display_options['fields']['field_member_business_name']['id'] = 'field_member_business_name';
$handler->display->display_options['fields']['field_member_business_name']['table'] = 'field_data_field_member_business_name';
$handler->display->display_options['fields']['field_member_business_name']['field'] = 'field_member_business_name';
$handler->display->display_options['fields']['field_member_business_name']['label'] = '';
$handler->display->display_options['fields']['field_member_business_name']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_member_business_name']['element_type'] = '0';
$handler->display->display_options['fields']['field_member_business_name']['element_label_type'] = '0';
$handler->display->display_options['fields']['field_member_business_name']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_member_business_name']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_member_business_name']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_member_business_name']['type'] = 'text_plain';
$handler->display->display_options['fields']['field_member_business_name']['field_api_classes'] = TRUE;
/* Field: Content: Business Location */
$handler->display->display_options['fields']['field_member_business_location']['id'] = 'field_member_business_location';
$handler->display->display_options['fields']['field_member_business_location']['table'] = 'field_data_field_member_business_location';
$handler->display->display_options['fields']['field_member_business_location']['field'] = 'field_member_business_location';
$handler->display->display_options['fields']['field_member_business_location']['label'] = '';
$handler->display->display_options['fields']['field_member_business_location']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_member_business_location']['alter']['strip_tags'] = TRUE;
$handler->display->display_options['fields']['field_member_business_location']['element_type'] = '0';
$handler->display->display_options['fields']['field_member_business_location']['element_label_type'] = '0';
$handler->display->display_options['fields']['field_member_business_location']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_member_business_location']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_member_business_location']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_member_business_location']['type'] = 'text_plain';
$handler->display->display_options['fields']['field_member_business_location']['field_api_classes'] = TRUE;
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
/* Field: Content: Body */
$handler->display->display_options['fields']['body']['id'] = 'body';
$handler->display->display_options['fields']['body']['table'] = 'field_data_body';
$handler->display->display_options['fields']['body']['field'] = 'body';
$handler->display->display_options['fields']['body']['label'] = '';
$handler->display->display_options['fields']['body']['exclude'] = TRUE;
$handler->display->display_options['fields']['body']['element_type'] = '0';
$handler->display->display_options['fields']['body']['element_label_type'] = '0';
$handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['body']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['body']['field_api_classes'] = TRUE;
/* Field: Content: SBAN Involvement (optional) */
$handler->display->display_options['fields']['field_member_sban_involvement']['id'] = 'field_member_sban_involvement';
$handler->display->display_options['fields']['field_member_sban_involvement']['table'] = 'field_data_field_member_sban_involvement';
$handler->display->display_options['fields']['field_member_sban_involvement']['field'] = 'field_member_sban_involvement';
$handler->display->display_options['fields']['field_member_sban_involvement']['label'] = '';
$handler->display->display_options['fields']['field_member_sban_involvement']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_member_sban_involvement']['element_type'] = '0';
$handler->display->display_options['fields']['field_member_sban_involvement']['element_label_type'] = '0';
$handler->display->display_options['fields']['field_member_sban_involvement']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_member_sban_involvement']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_member_sban_involvement']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_member_sban_involvement']['field_api_classes'] = TRUE;
/* Field: Global: Custom text */
$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
$handler->display->display_options['fields']['nothing']['table'] = 'views';
$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing']['label'] = '';
$handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="featured-member-listing-wrapper">
<a class="featured-member-link" href="[path]">
<div class="featured-member-photo">[field_member_photo]</div>
<div class="featured-member-title">[title]</div>
<div class="featured-member-business">[field_member_business_name]<br /><div class="featured-member-business-location">[field_member_business_location]</div></div>
<div class="featured-member-location">
<div class="featured-member-description">[body]</div>
<div class="featured-member-sban-involvement">[field_member_sban_involvement]</div>
</div>
</a>
</div>';
$handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
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
    'member' => 'member',
);
$translatables['ems2015_members'] = array(
    t('Master'),
    t('Featured Member'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('EMS2015 - Featured Members Page'),
    t('Featured Members'),
    t('<div class="featured-member-listing-wrapper">
<a class="featured-member-link" href="[path]">
<div class="featured-member-photo">[field_member_photo]</div>
<div class="featured-member-title">[title]</div>
<div class="featured-member-business">[field_member_business_name]<br /><div class="featured-member-business-location">[field_member_business_location]</div></div>
<div class="featured-member-location">[body]</div>
</a>
</div>'),
    t('EMS2015 - Featured Member'),
    t('queue'),
    t('<div class="featured-member-view-more"><a href="/featured-members">Featured Members</a></div>'),
    t('EMS2015 - SBAN Featured Member'),
    t('Small Business Spotlight'),
    t('<p>We have SBAN members all over the world.  Here are their SBAN involvement stories:</p>'),
    t('<div class="featured-member-listing-wrapper">
<a class="featured-member-link" href="[path]">
<div class="featured-member-photo">[field_member_photo]</div>
<div class="featured-member-title">[title]</div>
<div class="featured-member-business">[field_member_business_name]<br /><div class="featured-member-business-location">[field_member_business_location]</div></div>
<div class="featured-member-location">
<div class="featured-member-description">[body]</div>
<div class="featured-member-sban-involvement">[field_member_sban_involvement]</div>
</div>
</a>
</div>'),
);