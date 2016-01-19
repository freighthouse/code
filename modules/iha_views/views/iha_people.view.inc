<?php

$view = new view();
$view->name = 'iha_people';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'users';
$view->human_name = 'IHA People';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'access user profiles';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['row_plugin'] = 'fields';
/* Field: User: Name */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'users';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['label'] = '';
$handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
/* Filter criterion: User: Active */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'users';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = '1';

/* Display: Staff */
$handler = $view->new_display('block', 'Staff', 'staff');
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['style_options']['row_class'] = 'col-sm-6 col-xs-12 people-ht';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['relationships'] = FALSE;
/* Relationship: Entityqueue: User Queue */
$handler->display->display_options['relationships']['entityqueue_relationship']['id'] = 'entityqueue_relationship';
$handler->display->display_options['relationships']['entityqueue_relationship']['table'] = 'users';
$handler->display->display_options['relationships']['entityqueue_relationship']['field'] = 'entityqueue_relationship';
$handler->display->display_options['relationships']['entityqueue_relationship']['required'] = TRUE;
$handler->display->display_options['relationships']['entityqueue_relationship']['limit'] = 1;
$handler->display->display_options['relationships']['entityqueue_relationship']['queues'] = array(
  'staff' => 'staff',
  'iha_staff' => 0,
  'executive_committee' => 0,
  'affiliates' => 0,
);
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: User: Name */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'users';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['label'] = '';
$handler->display->display_options['fields']['name']['exclude'] = TRUE;
$handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
/* Field: User: Uid */
$handler->display->display_options['fields']['uid']['id'] = 'uid';
$handler->display->display_options['fields']['uid']['table'] = 'users';
$handler->display->display_options['fields']['uid']['field'] = 'uid';
$handler->display->display_options['fields']['uid']['label'] = '';
$handler->display->display_options['fields']['uid']['exclude'] = TRUE;
$handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
/* Field: User: Picture */
$handler->display->display_options['fields']['field_profile_picture']['id'] = 'field_profile_picture';
$handler->display->display_options['fields']['field_profile_picture']['table'] = 'field_data_field_profile_picture';
$handler->display->display_options['fields']['field_profile_picture']['field'] = 'field_profile_picture';
$handler->display->display_options['fields']['field_profile_picture']['label'] = '';
$handler->display->display_options['fields']['field_profile_picture']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_profile_picture']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_profile_picture']['settings'] = array(
  'image_style' => 'profile_picture',
  'image_link' => '',
);
/* Field: User: Name */
$handler->display->display_options['fields']['field_name']['id'] = 'field_name';
$handler->display->display_options['fields']['field_name']['table'] = 'field_data_field_name';
$handler->display->display_options['fields']['field_name']['field'] = 'field_name';
$handler->display->display_options['fields']['field_name']['label'] = '';
$handler->display->display_options['fields']['field_name']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['field_name']['alter']['path'] = 'users/[name]';
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
/* Field: User: Title */
$handler->display->display_options['fields']['field_user_title']['id'] = 'field_user_title';
$handler->display->display_options['fields']['field_user_title']['table'] = 'field_data_field_user_title';
$handler->display->display_options['fields']['field_user_title']['field'] = 'field_user_title';
$handler->display->display_options['fields']['field_user_title']['label'] = '';
$handler->display->display_options['fields']['field_user_title']['element_label_colon'] = FALSE;
/* Field: Field: Twitter ID */
$handler->display->display_options['fields']['field_twitter_id']['id'] = 'field_twitter_id';
$handler->display->display_options['fields']['field_twitter_id']['table'] = 'field_data_field_twitter_id';
$handler->display->display_options['fields']['field_twitter_id']['field'] = 'field_twitter_id';
$handler->display->display_options['fields']['field_twitter_id']['label'] = '';
$handler->display->display_options['fields']['field_twitter_id']['element_label_colon'] = FALSE;
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: Entityqueue: User Queue Position */
$handler->display->display_options['sorts']['entityqueue_relationship']['id'] = 'entityqueue_relationship';
$handler->display->display_options['sorts']['entityqueue_relationship']['table'] = 'users';
$handler->display->display_options['sorts']['entityqueue_relationship']['field'] = 'entityqueue_relationship';
/* Sort criterion: Subqueue: Queue Name */
$handler->display->display_options['sorts']['queue']['id'] = 'queue';
$handler->display->display_options['sorts']['queue']['table'] = 'entityqueue_subqueue';
$handler->display->display_options['sorts']['queue']['field'] = 'queue';
$handler->display->display_options['sorts']['queue']['relationship'] = 'entityqueue_relationship';
$handler->display->display_options['sorts']['queue']['order'] = 'DESC';

/* Display: Executive Committee */
$handler = $view->new_display('block', 'Executive Committee', 'ec');
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['style_options']['row_class'] = 'col-sm-6 col-xs-12 people-ht';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['inline'] = array(
  'field_user_title' => 'field_user_title',
  'field_organization_name' => 'field_organization_name',
);
$handler->display->display_options['row_options']['separator'] = ' | ';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['relationships'] = FALSE;
/* Relationship: Entityqueue: User Queue */
$handler->display->display_options['relationships']['entityqueue_relationship']['id'] = 'entityqueue_relationship';
$handler->display->display_options['relationships']['entityqueue_relationship']['table'] = 'users';
$handler->display->display_options['relationships']['entityqueue_relationship']['field'] = 'entityqueue_relationship';
$handler->display->display_options['relationships']['entityqueue_relationship']['required'] = TRUE;
$handler->display->display_options['relationships']['entityqueue_relationship']['limit'] = 1;
$handler->display->display_options['relationships']['entityqueue_relationship']['queues'] = array(
  'executive_committee' => 'executive_committee',
  'iha_staff' => 0,
  'staff' => 0,
);
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: User: Uid */
$handler->display->display_options['fields']['uid']['id'] = 'uid';
$handler->display->display_options['fields']['uid']['table'] = 'users';
$handler->display->display_options['fields']['uid']['field'] = 'uid';
$handler->display->display_options['fields']['uid']['label'] = '';
$handler->display->display_options['fields']['uid']['exclude'] = TRUE;
$handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
/* Field: User: Picture */
$handler->display->display_options['fields']['field_profile_picture']['id'] = 'field_profile_picture';
$handler->display->display_options['fields']['field_profile_picture']['table'] = 'field_data_field_profile_picture';
$handler->display->display_options['fields']['field_profile_picture']['field'] = 'field_profile_picture';
$handler->display->display_options['fields']['field_profile_picture']['label'] = '';
$handler->display->display_options['fields']['field_profile_picture']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_profile_picture']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_profile_picture']['settings'] = array(
  'image_style' => 'profile_picture',
  'image_link' => '',
);
/* Field: User: Name */
$handler->display->display_options['fields']['field_name']['id'] = 'field_name';
$handler->display->display_options['fields']['field_name']['table'] = 'field_data_field_name';
$handler->display->display_options['fields']['field_name']['field'] = 'field_name';
$handler->display->display_options['fields']['field_name']['label'] = '';
$handler->display->display_options['fields']['field_name']['alter']['path'] = 'about-us/our-people/staff/[uid]';
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
/* Field: User: Title */
$handler->display->display_options['fields']['field_user_title']['id'] = 'field_user_title';
$handler->display->display_options['fields']['field_user_title']['table'] = 'field_data_field_user_title';
$handler->display->display_options['fields']['field_user_title']['field'] = 'field_user_title';
$handler->display->display_options['fields']['field_user_title']['label'] = '';
$handler->display->display_options['fields']['field_user_title']['element_label_colon'] = FALSE;
/* Field: Field: Organization Name */
$handler->display->display_options['fields']['field_organization_name']['id'] = 'field_organization_name';
$handler->display->display_options['fields']['field_organization_name']['table'] = 'field_data_field_organization_name';
$handler->display->display_options['fields']['field_organization_name']['field'] = 'field_organization_name';
$handler->display->display_options['fields']['field_organization_name']['label'] = '';
$handler->display->display_options['fields']['field_organization_name']['element_label_colon'] = FALSE;
/* Field: Field: Committee Role */
$handler->display->display_options['fields']['field_committee_role']['id'] = 'field_committee_role';
$handler->display->display_options['fields']['field_committee_role']['table'] = 'field_data_field_committee_role';
$handler->display->display_options['fields']['field_committee_role']['field'] = 'field_committee_role';
$handler->display->display_options['fields']['field_committee_role']['label'] = '';
$handler->display->display_options['fields']['field_committee_role']['element_label_colon'] = FALSE;
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: Entityqueue: User Queue Position */
$handler->display->display_options['sorts']['entityqueue_relationship']['id'] = 'entityqueue_relationship';
$handler->display->display_options['sorts']['entityqueue_relationship']['table'] = 'users';
$handler->display->display_options['sorts']['entityqueue_relationship']['field'] = 'entityqueue_relationship';
/* Sort criterion: Subqueue: Queue Name */
$handler->display->display_options['sorts']['queue']['id'] = 'queue';
$handler->display->display_options['sorts']['queue']['table'] = 'entityqueue_subqueue';
$handler->display->display_options['sorts']['queue']['field'] = 'queue';
$handler->display->display_options['sorts']['queue']['relationship'] = 'entityqueue_relationship';
$handler->display->display_options['sorts']['queue']['order'] = 'DESC';