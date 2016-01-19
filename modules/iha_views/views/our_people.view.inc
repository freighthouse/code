<?php

$view = new view();
$view->name = 'our_people';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'profile';
$view->human_name = 'Our People';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'none';
$handler->display->display_options['cache']['type'] = 'time';
$handler->display->display_options['cache']['results_lifespan'] = '300';
$handler->display->display_options['cache']['results_lifespan_custom'] = '0';
$handler->display->display_options['cache']['output_lifespan'] = '300';
$handler->display->display_options['cache']['output_lifespan_custom'] = '0';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '15';
$handler->display->display_options['style_plugin'] = 'grid';
$handler->display->display_options['style_options']['columns'] = '2';
$handler->display->display_options['row_plugin'] = 'fields';
/* Field: Profile: Profile ID */
$handler->display->display_options['fields']['pid']['id'] = 'pid';
$handler->display->display_options['fields']['pid']['table'] = 'profile';
$handler->display->display_options['fields']['pid']['field'] = 'pid';
/* Field: Profile: User uid */
$handler->display->display_options['fields']['user']['id'] = 'user';
$handler->display->display_options['fields']['user']['table'] = 'profile';
$handler->display->display_options['fields']['user']['field'] = 'user';
$handler->display->display_options['fields']['user']['label'] = '';
$handler->display->display_options['fields']['user']['exclude'] = TRUE;
$handler->display->display_options['fields']['user']['element_label_colon'] = FALSE;
/* Filter criterion: Profile: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'profile';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'staff_member' => 'staff_member',
);

/* Display: Staff */
$handler = $view->new_display('block', 'Staff', 'staff');
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '15';
$handler->display->display_options['pager']['options']['offset'] = '';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['style_options']['row_class'] = 'col-sm-6 col-xs-12';
$handler->display->display_options['style_options']['row_class_special'] = FALSE;
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Profile: User uid */
$handler->display->display_options['fields']['user']['id'] = 'user';
$handler->display->display_options['fields']['user']['table'] = 'profile';
$handler->display->display_options['fields']['user']['field'] = 'user';
$handler->display->display_options['fields']['user']['label'] = '';
$handler->display->display_options['fields']['user']['exclude'] = TRUE;
$handler->display->display_options['fields']['user']['element_label_colon'] = FALSE;
/* Field: Profile: Profile ID */
$handler->display->display_options['fields']['pid']['id'] = 'pid';
$handler->display->display_options['fields']['pid']['table'] = 'profile';
$handler->display->display_options['fields']['pid']['field'] = 'pid';
$handler->display->display_options['fields']['pid']['label'] = '';
$handler->display->display_options['fields']['pid']['exclude'] = TRUE;
$handler->display->display_options['fields']['pid']['element_label_colon'] = FALSE;
/* Field: Profile: Picture */
$handler->display->display_options['fields']['field_profile_picture']['id'] = 'field_profile_picture';
$handler->display->display_options['fields']['field_profile_picture']['table'] = 'field_data_field_profile_picture';
$handler->display->display_options['fields']['field_profile_picture']['field'] = 'field_profile_picture';
$handler->display->display_options['fields']['field_profile_picture']['label'] = '';
$handler->display->display_options['fields']['field_profile_picture']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_profile_picture']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_profile_picture']['type'] = 'picture';
$handler->display->display_options['fields']['field_profile_picture']['settings'] = array(
  'picture_mapping' => 'staff',
  'fallback_image_style' => '',
  'lazyload' => 1,
  'lazyload_aspect_ratio' => 1,
  'image_link' => '',
);
/* Field: Profile: Name */
$handler->display->display_options['fields']['field_name']['id'] = 'field_name';
$handler->display->display_options['fields']['field_name']['table'] = 'field_data_field_name';
$handler->display->display_options['fields']['field_name']['field'] = 'field_name';
$handler->display->display_options['fields']['field_name']['label'] = '';
$handler->display->display_options['fields']['field_name']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['field_name']['alter']['path'] = 'about-us/our-people/staff/[user]';
$handler->display->display_options['fields']['field_name']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_name']['click_sort_column'] = 'title';
$handler->display->display_options['fields']['field_name']['settings'] = array(
  'format' => 'default',
  'markup' => 1,
  'output' => 'default',
  'multiple' => 'default',
  'multiple_delimiter' => ', ',
  'multiple_and' => 'text',
  'multiple_delimiter_precedes_last' => 'never',
  'multiple_el_al_min' => '3',
  'multiple_el_al_first' => '1',
);
/* Field: Profile: Title */
$handler->display->display_options['fields']['field_user_title']['id'] = 'field_user_title';
$handler->display->display_options['fields']['field_user_title']['table'] = 'field_data_field_user_title';
$handler->display->display_options['fields']['field_user_title']['field'] = 'field_user_title';
$handler->display->display_options['fields']['field_user_title']['label'] = '';
$handler->display->display_options['fields']['field_user_title']['element_label_colon'] = FALSE;
/* Field: Profile: Twitter ID */
$handler->display->display_options['fields']['field_twitter_id']['id'] = 'field_twitter_id';
$handler->display->display_options['fields']['field_twitter_id']['table'] = 'field_data_field_twitter_id';
$handler->display->display_options['fields']['field_twitter_id']['field'] = 'field_twitter_id';
$handler->display->display_options['fields']['field_twitter_id']['label'] = '';
$handler->display->display_options['fields']['field_twitter_id']['element_label_colon'] = FALSE;
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Profile: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'profile';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'staff_member' => 'staff_member',
);

/* Display: Affiliate Members */
$handler = $view->new_display('block', 'Affiliate Members', 'affiliates');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Affiliate Members';
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '15';
$handler->display->display_options['pager']['options']['offset'] = '';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Profile: User uid */
$handler->display->display_options['fields']['user']['id'] = 'user';
$handler->display->display_options['fields']['user']['table'] = 'profile';
$handler->display->display_options['fields']['user']['field'] = 'user';
$handler->display->display_options['fields']['user']['label'] = '';
$handler->display->display_options['fields']['user']['exclude'] = TRUE;
$handler->display->display_options['fields']['user']['element_label_colon'] = FALSE;
/* Field: Profile: Profile ID */
$handler->display->display_options['fields']['pid']['id'] = 'pid';
$handler->display->display_options['fields']['pid']['table'] = 'profile';
$handler->display->display_options['fields']['pid']['field'] = 'pid';
$handler->display->display_options['fields']['pid']['label'] = '';
$handler->display->display_options['fields']['pid']['exclude'] = TRUE;
$handler->display->display_options['fields']['pid']['element_label_colon'] = FALSE;
/* Field: Profile: Picture */
$handler->display->display_options['fields']['field_affiliate_picture']['id'] = 'field_affiliate_picture';
$handler->display->display_options['fields']['field_affiliate_picture']['table'] = 'field_data_field_affiliate_picture';
$handler->display->display_options['fields']['field_affiliate_picture']['field'] = 'field_affiliate_picture';
$handler->display->display_options['fields']['field_affiliate_picture']['label'] = '';
$handler->display->display_options['fields']['field_affiliate_picture']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_affiliate_picture']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_affiliate_picture']['type'] = 'picture';
$handler->display->display_options['fields']['field_affiliate_picture']['settings'] = array(
  'picture_mapping' => 'staff',
  'fallback_image_style' => '',
  'lazyload' => 1,
  'lazyload_aspect_ratio' => 1,
  'image_link' => '',
);
/* Field: Profile: Name */
$handler->display->display_options['fields']['field_affiliate_member_name']['id'] = 'field_affiliate_member_name';
$handler->display->display_options['fields']['field_affiliate_member_name']['table'] = 'field_data_field_affiliate_member_name';
$handler->display->display_options['fields']['field_affiliate_member_name']['field'] = 'field_affiliate_member_name';
$handler->display->display_options['fields']['field_affiliate_member_name']['label'] = '';
$handler->display->display_options['fields']['field_affiliate_member_name']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['field_affiliate_member_name']['alter']['path'] = 'about-us/our-members/affiliate/[user]';
$handler->display->display_options['fields']['field_affiliate_member_name']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_affiliate_member_name']['click_sort_column'] = 'title';
$handler->display->display_options['fields']['field_affiliate_member_name']['settings'] = array(
  'format' => 'default',
  'markup' => 1,
  'output' => 'default',
  'multiple' => 'default',
  'multiple_delimiter' => ', ',
  'multiple_and' => 'text',
  'multiple_delimiter_precedes_last' => 'never',
  'multiple_el_al_min' => '3',
  'multiple_el_al_first' => '1',
);
/* Field: Profile: Title */
$handler->display->display_options['fields']['field_organization_title']['id'] = 'field_organization_title';
$handler->display->display_options['fields']['field_organization_title']['table'] = 'field_data_field_organization_title';
$handler->display->display_options['fields']['field_organization_title']['field'] = 'field_organization_title';
$handler->display->display_options['fields']['field_organization_title']['label'] = '';
$handler->display->display_options['fields']['field_organization_title']['element_label_colon'] = FALSE;
/* Field: Profile: Committee Role */
$handler->display->display_options['fields']['field_committee_role']['id'] = 'field_committee_role';
$handler->display->display_options['fields']['field_committee_role']['table'] = 'field_data_field_committee_role';
$handler->display->display_options['fields']['field_committee_role']['field'] = 'field_committee_role';
$handler->display->display_options['fields']['field_committee_role']['label'] = '';
$handler->display->display_options['fields']['field_committee_role']['element_label_colon'] = FALSE;
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Profile: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'profile';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'affiliate_member' => 'affiliate_member',
);

/* Display: Executive Committee */
$handler = $view->new_display('block', 'Executive Committee', 'executive_committee');
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '15';
$handler->display->display_options['pager']['options']['offset'] = '';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['style_options']['row_class'] = 'col-sm-6 col-xs-12';
$handler->display->display_options['style_options']['row_class_special'] = FALSE;
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['inline'] = array(
  'field_committee_title' => 'field_committee_title',
  'field_organization_name' => 'field_organization_name',
);
$handler->display->display_options['row_options']['separator'] = '|';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Profile: User uid */
$handler->display->display_options['fields']['user']['id'] = 'user';
$handler->display->display_options['fields']['user']['table'] = 'profile';
$handler->display->display_options['fields']['user']['field'] = 'user';
$handler->display->display_options['fields']['user']['label'] = '';
$handler->display->display_options['fields']['user']['exclude'] = TRUE;
$handler->display->display_options['fields']['user']['element_label_colon'] = FALSE;
/* Field: Profile: Profile ID */
$handler->display->display_options['fields']['pid']['id'] = 'pid';
$handler->display->display_options['fields']['pid']['table'] = 'profile';
$handler->display->display_options['fields']['pid']['field'] = 'pid';
$handler->display->display_options['fields']['pid']['label'] = '';
$handler->display->display_options['fields']['pid']['exclude'] = TRUE;
$handler->display->display_options['fields']['pid']['element_label_colon'] = FALSE;
/* Field: Profile: Picture */
$handler->display->display_options['fields']['field_committee_picture']['id'] = 'field_committee_picture';
$handler->display->display_options['fields']['field_committee_picture']['table'] = 'field_data_field_committee_picture';
$handler->display->display_options['fields']['field_committee_picture']['field'] = 'field_committee_picture';
$handler->display->display_options['fields']['field_committee_picture']['label'] = '';
$handler->display->display_options['fields']['field_committee_picture']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_committee_picture']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_committee_picture']['type'] = 'picture';
$handler->display->display_options['fields']['field_committee_picture']['settings'] = array(
  'picture_mapping' => 'staff',
  'fallback_image_style' => '',
  'lazyload' => 1,
  'lazyload_aspect_ratio' => 1,
  'image_link' => '',
);
/* Field: Profile: Name */
$handler->display->display_options['fields']['field_committee_member_name']['id'] = 'field_committee_member_name';
$handler->display->display_options['fields']['field_committee_member_name']['table'] = 'field_data_field_committee_member_name';
$handler->display->display_options['fields']['field_committee_member_name']['field'] = 'field_committee_member_name';
$handler->display->display_options['fields']['field_committee_member_name']['label'] = '';
$handler->display->display_options['fields']['field_committee_member_name']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['field_committee_member_name']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['field_committee_member_name']['alter']['path'] = 'about-us/our-members/committee/[user]';
$handler->display->display_options['fields']['field_committee_member_name']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_committee_member_name']['click_sort_column'] = 'title';
$handler->display->display_options['fields']['field_committee_member_name']['settings'] = array(
  'format' => 'default',
  'markup' => 0,
  'output' => 'default',
  'multiple' => 'default',
  'multiple_delimiter' => ', ',
  'multiple_and' => 'text',
  'multiple_delimiter_precedes_last' => 'never',
  'multiple_el_al_min' => '3',
  'multiple_el_al_first' => '1',
);
/* Field: Profile: Title */
$handler->display->display_options['fields']['field_committee_title']['id'] = 'field_committee_title';
$handler->display->display_options['fields']['field_committee_title']['table'] = 'field_data_field_committee_title';
$handler->display->display_options['fields']['field_committee_title']['field'] = 'field_committee_title';
$handler->display->display_options['fields']['field_committee_title']['label'] = '';
$handler->display->display_options['fields']['field_committee_title']['element_label_colon'] = FALSE;
/* Field: Profile: Organization Name */
$handler->display->display_options['fields']['field_organization_name']['id'] = 'field_organization_name';
$handler->display->display_options['fields']['field_organization_name']['table'] = 'field_data_field_organization_name';
$handler->display->display_options['fields']['field_organization_name']['field'] = 'field_organization_name';
$handler->display->display_options['fields']['field_organization_name']['label'] = '';
$handler->display->display_options['fields']['field_organization_name']['element_label_colon'] = FALSE;
/* Field: Profile: Committee Role */
$handler->display->display_options['fields']['field_committee_role']['id'] = 'field_committee_role';
$handler->display->display_options['fields']['field_committee_role']['table'] = 'field_data_field_committee_role';
$handler->display->display_options['fields']['field_committee_role']['field'] = 'field_committee_role';
$handler->display->display_options['fields']['field_committee_role']['label'] = '';
$handler->display->display_options['fields']['field_committee_role']['element_label_colon'] = FALSE;
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Profile: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'profile';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'committee_member' => 'committee_member',
);