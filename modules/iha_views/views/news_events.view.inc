<?php

$view = new view();
$view->name = 'news_events';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'News & Events';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'News & Events';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'time';
$handler->display->display_options['cache']['results_lifespan'] = '300';
$handler->display->display_options['cache']['results_lifespan_custom'] = '0';
$handler->display->display_options['cache']['output_lifespan'] = '300';
$handler->display->display_options['cache']['output_lifespan_custom'] = '0';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
$handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
$handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
$handler->display->display_options['exposed_form']['options']['bef'] = array(
  'general' => array(
    'allow_secondary' => 0,
    'secondary_label' => 'Advanced options',
    'collapsible_label' => NULL,
    'combine_rewrite' => NULL,
    'reset_label' => NULL,
    'bef_filter_description' => NULL,
    'any_label' => NULL,
    'filter_rewrite_values' => NULL,
  ),
  'type_1' => array(
    'bef_format' => 'bef_links',
    'more_options' => array(
      'bef_select_all_none' => FALSE,
      'bef_collapsible' => 0,
      'is_secondary' => 0,
      'any_label' => '',
      'bef_filter_description' => '',
      'tokens' => array(
        'available' => array(
          0 => 'global_types',
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
          'filter_rewrite_values' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'bef_filter_description' => NULL,
        'any_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'rewrite' => array(
        'filter_rewrite_values' => '',
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'bef_filter_description' => NULL,
        'any_label' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'secondary_label' => NULL,
    'collapsible_label' => NULL,
    'combine_rewrite' => NULL,
    'reset_label' => NULL,
    'bef_filter_description' => NULL,
    'any_label' => NULL,
    'filter_rewrite_values' => NULL,
  ),
  'secondary_label' => NULL,
  'collapsible_label' => NULL,
  'combine_rewrite' => NULL,
  'reset_label' => NULL,
  'bef_filter_description' => NULL,
  'any_label' => NULL,
  'filter_rewrite_values' => NULL,
);
$handler->display->display_options['exposed_form']['options']['input_required'] = 0;
$handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'full_html';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['row_plugin'] = 'fields';
/* Header: Global: Text area */
$handler->display->display_options['header']['area']['id'] = 'area';
$handler->display->display_options['header']['area']['table'] = 'views';
$handler->display->display_options['header']['area']['field'] = 'area';
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
/* Field: Content: Body */
$handler->display->display_options['fields']['field_pr_body']['id'] = 'field_pr_body';
$handler->display->display_options['fields']['field_pr_body']['table'] = 'field_data_field_pr_body';
$handler->display->display_options['fields']['field_pr_body']['field'] = 'field_pr_body';
/* Field: Broken/missing handler */
$handler->display->display_options['fields']['field_pr_date']['id'] = 'field_pr_date';
$handler->display->display_options['fields']['field_pr_date']['table'] = 'field_data_field_pr_date';
$handler->display->display_options['fields']['field_pr_date']['field'] = 'field_pr_date';
/* Field: Content: Location */
$handler->display->display_options['fields']['field_pr_location']['id'] = 'field_pr_location';
$handler->display->display_options['fields']['field_pr_location']['table'] = 'field_data_field_pr_location';
$handler->display->display_options['fields']['field_pr_location']['field'] = 'field_pr_location';
/* Field: Field: Title */
$handler->display->display_options['fields']['title_field']['id'] = 'title_field';
$handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
$handler->display->display_options['fields']['title_field']['field'] = 'title_field';
/* Sort criterion: Content: Post date */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'node';
$handler->display->display_options['sorts']['created']['field'] = 'created';
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
  'blog' => 'blog',
  'conference' => 'conference',
  'event' => 'event',
  'news' => 'news',
  'press_release' => 'press_release',
  'webinar' => 'webinar',
);
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type_1']['id'] = 'type_1';
$handler->display->display_options['filters']['type_1']['table'] = 'node';
$handler->display->display_options['filters']['type_1']['field'] = 'type';
$handler->display->display_options['filters']['type_1']['value'] = array(
  'blog' => 'blog',
  'conference' => 'conference',
  'event' => 'event',
  'news' => 'news',
  'press_release' => 'press_release',
  'webinar' => 'webinar',
);
$handler->display->display_options['filters']['type_1']['exposed'] = TRUE;
$handler->display->display_options['filters']['type_1']['expose']['operator_id'] = 'type_1_op';
$handler->display->display_options['filters']['type_1']['expose']['operator'] = 'type_1_op';
$handler->display->display_options['filters']['type_1']['expose']['identifier'] = 'type_1';
$handler->display->display_options['filters']['type_1']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  4 => 0,
  5 => 0,
  3 => 0,
  6 => 0,
  7 => 0,
  8 => 0,
  9 => 0,
  10 => 0,
  11 => 0,
  12 => 0,
  13 => 0,
  14 => 0,
  15 => 0,
  16 => 0,
  17 => 0,
);
$handler->display->display_options['filters']['type_1']['expose']['reduce'] = TRUE;
$handler->display->display_options['filters']['type_1']['group_info']['label'] = 'Type';
$handler->display->display_options['filters']['type_1']['group_info']['identifier'] = 'type_1';
$handler->display->display_options['filters']['type_1']['group_info']['remember'] = FALSE;
$handler->display->display_options['filters']['type_1']['group_info']['group_items'] = array(
  1 => array(),
  2 => array(),
  3 => array(),
);

/* Display: Events Block */
$handler = $view->new_display('block', 'Events Block', 'events');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Events';
$handler->display->display_options['defaults']['exposed_form'] = FALSE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '4';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['inline'] = array(
  'type' => 'type',
  'field_webinar_date' => 'field_webinar_date',
  'field_event_date' => 'field_event_date',
  'field_conference_date' => 'field_conference_date',
);
$handler->display->display_options['row_options']['separator'] = ' | ';
$handler->display->display_options['row_options']['hide_empty'] = TRUE;
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['header'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Type */
$handler->display->display_options['fields']['type']['id'] = 'type';
$handler->display->display_options['fields']['type']['table'] = 'node';
$handler->display->display_options['fields']['type']['field'] = 'type';
$handler->display->display_options['fields']['type']['label'] = '';
$handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
/* Field: Content: Date */
$handler->display->display_options['fields']['field_webinar_date']['id'] = 'field_webinar_date';
$handler->display->display_options['fields']['field_webinar_date']['table'] = 'field_data_field_webinar_date';
$handler->display->display_options['fields']['field_webinar_date']['field'] = 'field_webinar_date';
$handler->display->display_options['fields']['field_webinar_date']['label'] = '';
$handler->display->display_options['fields']['field_webinar_date']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_webinar_date']['settings'] = array(
  'format_type' => 'medium',
  'fromto' => 'value',
  'multiple_number' => '',
  'multiple_from' => '',
  'multiple_to' => '',
  'show_remaining_days' => 0,
  'show_repeat_rule' => 'hide',
);
$handler->display->display_options['fields']['field_webinar_date']['delta_offset'] = '0';
$handler->display->display_options['fields']['field_webinar_date']['separator'] = ' | ';
/* Field: Content: Date */
$handler->display->display_options['fields']['field_event_date']['id'] = 'field_event_date';
$handler->display->display_options['fields']['field_event_date']['table'] = 'field_data_field_event_date';
$handler->display->display_options['fields']['field_event_date']['field'] = 'field_event_date';
$handler->display->display_options['fields']['field_event_date']['label'] = '';
$handler->display->display_options['fields']['field_event_date']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_event_date']['settings'] = array(
  'format_type' => 'medium',
  'fromto' => 'value',
  'multiple_number' => '',
  'multiple_from' => '',
  'multiple_to' => '',
  'show_remaining_days' => 0,
  'show_repeat_rule' => 'hide',
);
$handler->display->display_options['fields']['field_event_date']['delta_offset'] = '0';
$handler->display->display_options['fields']['field_event_date']['separator'] = ' | ';
/* Field: Content: Date */
$handler->display->display_options['fields']['field_conference_date']['id'] = 'field_conference_date';
$handler->display->display_options['fields']['field_conference_date']['table'] = 'field_data_field_conference_date';
$handler->display->display_options['fields']['field_conference_date']['field'] = 'field_conference_date';
$handler->display->display_options['fields']['field_conference_date']['label'] = '';
$handler->display->display_options['fields']['field_conference_date']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_conference_date']['settings'] = array(
  'format_type' => 'medium',
  'fromto' => 'value',
  'multiple_number' => '',
  'multiple_from' => '',
  'multiple_to' => '',
  'show_remaining_days' => 0,
  'show_repeat_rule' => 'show',
);
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_class'] = 'events_title';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
/* Field: Content: Location */
$handler->display->display_options['fields']['field_conference_location']['id'] = 'field_conference_location';
$handler->display->display_options['fields']['field_conference_location']['table'] = 'field_data_field_conference_location';
$handler->display->display_options['fields']['field_conference_location']['field'] = 'field_conference_location';
$handler->display->display_options['fields']['field_conference_location']['label'] = '';
$handler->display->display_options['fields']['field_conference_location']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_conference_location']['element_label_colon'] = FALSE;
/* Field: Content: Location */
$handler->display->display_options['fields']['field_event_location']['id'] = 'field_event_location';
$handler->display->display_options['fields']['field_event_location']['table'] = 'field_data_field_event_location';
$handler->display->display_options['fields']['field_event_location']['field'] = 'field_event_location';
$handler->display->display_options['fields']['field_event_location']['label'] = '';
$handler->display->display_options['fields']['field_event_location']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_event_location']['element_label_colon'] = FALSE;
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
  'conference' => 'conference',
  'event' => 'event',
  'webinar' => 'webinar',
);
$handler->display->display_options['block_description'] = 'Events';

/* Display: All */
$handler = $view->new_display('block', 'All', 'news_events_all');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['defaults']['exposed_form'] = FALSE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '6';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['header'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Type */
$handler->display->display_options['fields']['type']['id'] = 'type';
$handler->display->display_options['fields']['type']['table'] = 'node';
$handler->display->display_options['fields']['type']['field'] = 'type';
$handler->display->display_options['fields']['type']['label'] = '';
$handler->display->display_options['fields']['type']['element_type'] = 'span';
$handler->display->display_options['fields']['type']['element_class'] = 'news_all_type';
$handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['type']['element_default_classes'] = FALSE;
/* Field: Content: Date */
$handler->display->display_options['fields']['field_news_date']['id'] = 'field_news_date';
$handler->display->display_options['fields']['field_news_date']['table'] = 'field_data_field_news_date';
$handler->display->display_options['fields']['field_news_date']['field'] = 'field_news_date';
$handler->display->display_options['fields']['field_news_date']['label'] = '';
$handler->display->display_options['fields']['field_news_date']['element_type'] = 'span';
$handler->display->display_options['fields']['field_news_date']['element_class'] = 'news_all_date';
$handler->display->display_options['fields']['field_news_date']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_news_date']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_news_date']['settings'] = array(
  'format_type' => 'medium',
  'fromto' => 'both',
  'multiple_number' => '',
  'multiple_from' => '',
  'multiple_to' => '',
  'show_remaining_days' => 0,
  'show_repeat_rule' => 'show',
);
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_class'] = 'news_all_title, row';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
/* Field: Content: Body */
$handler->display->display_options['fields']['field_news_body']['id'] = 'field_news_body';
$handler->display->display_options['fields']['field_news_body']['table'] = 'field_data_field_news_body';
$handler->display->display_options['fields']['field_news_body']['field'] = 'field_news_body';
$handler->display->display_options['fields']['field_news_body']['label'] = '';
$handler->display->display_options['fields']['field_news_body']['alter']['max_length'] = '200';
$handler->display->display_options['fields']['field_news_body']['alter']['trim'] = TRUE;
$handler->display->display_options['fields']['field_news_body']['element_class'] = 'news_all_body';
$handler->display->display_options['fields']['field_news_body']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_news_body']['type'] = 'text_summary_or_trimmed';
$handler->display->display_options['fields']['field_news_body']['settings'] = array(
  'trim_length' => '200',
);
/* Field: Content: Body */
$handler->display->display_options['fields']['field_pr_body']['id'] = 'field_pr_body';
$handler->display->display_options['fields']['field_pr_body']['table'] = 'field_data_field_pr_body';
$handler->display->display_options['fields']['field_pr_body']['field'] = 'field_pr_body';
$handler->display->display_options['fields']['field_pr_body']['label'] = '';
$handler->display->display_options['fields']['field_pr_body']['alter']['max_length'] = '200';
$handler->display->display_options['fields']['field_pr_body']['alter']['trim'] = TRUE;
$handler->display->display_options['fields']['field_pr_body']['element_class'] = 'news_all_body';
$handler->display->display_options['fields']['field_pr_body']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_pr_body']['type'] = 'text_summary_or_trimmed';
$handler->display->display_options['fields']['field_pr_body']['settings'] = array(
  'trim_length' => '200',
);
/* Field: Content: Body */
$handler->display->display_options['fields']['field_blog_body']['id'] = 'field_blog_body';
$handler->display->display_options['fields']['field_blog_body']['table'] = 'field_data_field_blog_body';
$handler->display->display_options['fields']['field_blog_body']['field'] = 'field_blog_body';
$handler->display->display_options['fields']['field_blog_body']['label'] = '';
$handler->display->display_options['fields']['field_blog_body']['alter']['max_length'] = '200';
$handler->display->display_options['fields']['field_blog_body']['alter']['trim'] = TRUE;
$handler->display->display_options['fields']['field_blog_body']['element_class'] = 'news_all_body';
$handler->display->display_options['fields']['field_blog_body']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_blog_body']['type'] = 'text_summary_or_trimmed';
$handler->display->display_options['fields']['field_blog_body']['settings'] = array(
  'trim_length' => '200',
);
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
  'blog' => 'blog',
  'news' => 'news',
  'press_release' => 'press_release',
);

/* Display: Press Releases */
$handler = $view->new_display('block', 'Press Releases', 'press_releases');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['defaults']['css_class'] = FALSE;
$handler->display->display_options['css_class'] = 'col-xs-12';
$handler->display->display_options['defaults']['exposed_form'] = FALSE;
$handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
$handler->display->display_options['exposed_form']['options']['bef'] = array(
  'general' => array(
    'allow_secondary' => 0,
    'secondary_label' => 'Advanced options',
    'collapsible_label' => NULL,
    'combine_rewrite' => NULL,
    'reset_label' => NULL,
  ),
  'type_1' => array(
    'bef_format' => 'bef_links',
    'more_options' => array(
      'bef_select_all_none' => FALSE,
      'bef_collapsible' => 0,
      'is_secondary' => 0,
      'any_label' => '',
      'bef_filter_description' => '',
      'tokens' => array(
        'available' => array(
          0 => 'global_types',
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
      ),
      'rewrite' => array(
        'filter_rewrite_values' => '',
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
    ),
    'secondary_label' => NULL,
    'collapsible_label' => NULL,
    'combine_rewrite' => NULL,
    'reset_label' => NULL,
  ),
  'secondary_label' => NULL,
  'collapsible_label' => NULL,
  'combine_rewrite' => NULL,
  'reset_label' => NULL,
);
$handler->display->display_options['exposed_form']['options']['input_required'] = 0;
$handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'full_html';
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '4';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '9';
$handler->display->display_options['pager']['options']['tags']['first'] = 'first';
$handler->display->display_options['pager']['options']['tags']['previous'] = 'previous';
$handler->display->display_options['pager']['options']['tags']['next'] = 'next';
$handler->display->display_options['pager']['options']['tags']['last'] = 'last';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['style_options']['row_class'] = 'col-md-10';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['inline'] = array(
  'field_pr_location' => 'field_pr_location',
  'field_publish_date' => 'field_publish_date',
);
$handler->display->display_options['row_options']['separator'] = ' | ';
$handler->display->display_options['row_options']['hide_empty'] = TRUE;
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['header'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Location */
$handler->display->display_options['fields']['field_pr_location']['id'] = 'field_pr_location';
$handler->display->display_options['fields']['field_pr_location']['table'] = 'field_data_field_pr_location';
$handler->display->display_options['fields']['field_pr_location']['field'] = 'field_pr_location';
$handler->display->display_options['fields']['field_pr_location']['label'] = '';
$handler->display->display_options['fields']['field_pr_location']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['field_pr_location']['alter']['strip_tags'] = TRUE;
$handler->display->display_options['fields']['field_pr_location']['alter']['preserve_tags'] = '<a>';
$handler->display->display_options['fields']['field_pr_location']['element_label_colon'] = FALSE;
/* Field: Content: Publish date */
$handler->display->display_options['fields']['field_publish_date']['id'] = 'field_publish_date';
$handler->display->display_options['fields']['field_publish_date']['table'] = 'field_data_field_publish_date';
$handler->display->display_options['fields']['field_publish_date']['field'] = 'field_publish_date';
$handler->display->display_options['fields']['field_publish_date']['label'] = '';
$handler->display->display_options['fields']['field_publish_date']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_publish_date']['settings'] = array(
  'format_type' => 'medium',
  'fromto' => 'both',
  'multiple_number' => '',
  'multiple_from' => '',
  'multiple_to' => '',
  'show_remaining_days' => 0,
  'show_repeat_rule' => 'show',
);
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_class'] = 'pr_title';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
/* Field: Content: Body */
$handler->display->display_options['fields']['field_pr_body']['id'] = 'field_pr_body';
$handler->display->display_options['fields']['field_pr_body']['table'] = 'field_data_field_pr_body';
$handler->display->display_options['fields']['field_pr_body']['field'] = 'field_pr_body';
$handler->display->display_options['fields']['field_pr_body']['label'] = '';
$handler->display->display_options['fields']['field_pr_body']['alter']['max_length'] = '200';
$handler->display->display_options['fields']['field_pr_body']['alter']['trim'] = TRUE;
$handler->display->display_options['fields']['field_pr_body']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_pr_body']['type'] = 'text_summary_or_trimmed';
$handler->display->display_options['fields']['field_pr_body']['settings'] = array(
  'trim_length' => '200',
);
/* Field: Content: Post date */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'node';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['label'] = '';
$handler->display->display_options['fields']['created']['exclude'] = TRUE;
$handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['created']['date_format'] = 'html5_tools_iso8601';
$handler->display->display_options['fields']['created']['second_date_format'] = 'html5_tools_iso8601';
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: Content: Post date */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'node';
$handler->display->display_options['sorts']['created']['field'] = 'created';
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
  'press_release' => 'press_release',
);

/* Display: Conferences */
$handler = $view->new_display('block', 'Conferences', 'conferences');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['defaults']['css_class'] = FALSE;
$handler->display->display_options['defaults']['exposed_form'] = FALSE;
$handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
$handler->display->display_options['exposed_form']['options']['bef'] = array(
  'general' => array(
    'allow_secondary' => 0,
    'secondary_label' => 'Advanced options',
    'collapsible_label' => NULL,
    'combine_rewrite' => NULL,
    'reset_label' => NULL,
  ),
  'type_1' => array(
    'bef_format' => 'bef_links',
    'more_options' => array(
      'bef_select_all_none' => FALSE,
      'bef_collapsible' => 0,
      'is_secondary' => 0,
      'any_label' => '',
      'bef_filter_description' => '',
      'tokens' => array(
        'available' => array(
          0 => 'global_types',
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
      ),
      'rewrite' => array(
        'filter_rewrite_values' => '',
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
    ),
    'secondary_label' => NULL,
    'collapsible_label' => NULL,
    'combine_rewrite' => NULL,
    'reset_label' => NULL,
  ),
  'secondary_label' => NULL,
  'collapsible_label' => NULL,
  'combine_rewrite' => NULL,
  'reset_label' => NULL,
);
$handler->display->display_options['exposed_form']['options']['input_required'] = 0;
$handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'full_html';
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '4';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '9';
$handler->display->display_options['pager']['options']['tags']['first'] = 'first';
$handler->display->display_options['pager']['options']['tags']['previous'] = 'previous';
$handler->display->display_options['pager']['options']['tags']['next'] = 'next';
$handler->display->display_options['pager']['options']['tags']['last'] = 'last';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['style_options']['row_class'] = 'conf_group';
$handler->display->display_options['style_options']['row_class_special'] = FALSE;
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['hide_empty'] = TRUE;
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['header'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Date */
$handler->display->display_options['fields']['field_conference_date']['id'] = 'field_conference_date';
$handler->display->display_options['fields']['field_conference_date']['table'] = 'field_data_field_conference_date';
$handler->display->display_options['fields']['field_conference_date']['field'] = 'field_conference_date';
$handler->display->display_options['fields']['field_conference_date']['label'] = '';
$handler->display->display_options['fields']['field_conference_date']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_conference_date']['settings'] = array(
  'format_type' => 'short',
  'fromto' => 'both',
  'multiple_number' => '',
  'multiple_from' => '',
  'multiple_to' => '',
  'show_remaining_days' => 0,
  'show_repeat_rule' => 'show',
);
/* Field: Field: Title */
$handler->display->display_options['fields']['title_field']['id'] = 'title_field';
$handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
$handler->display->display_options['fields']['title_field']['field'] = 'title_field';
$handler->display->display_options['fields']['title_field']['label'] = '';
$handler->display->display_options['fields']['title_field']['element_class'] = 'conf_title';
$handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title_field']['link_to_entity'] = 1;
/* Field: Content: Location */
$handler->display->display_options['fields']['field_conference_location']['id'] = 'field_conference_location';
$handler->display->display_options['fields']['field_conference_location']['table'] = 'field_data_field_conference_location';
$handler->display->display_options['fields']['field_conference_location']['field'] = 'field_conference_location';
$handler->display->display_options['fields']['field_conference_location']['label'] = '';
$handler->display->display_options['fields']['field_conference_location']['element_label_colon'] = FALSE;
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
  'conference' => 'conference',
);

/* Display: Webinars */
$handler = $view->new_display('block', 'Webinars', 'webinars');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['defaults']['css_class'] = FALSE;
$handler->display->display_options['defaults']['exposed_form'] = FALSE;
$handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
$handler->display->display_options['exposed_form']['options']['bef'] = array(
  'general' => array(
    'allow_secondary' => 0,
    'secondary_label' => 'Advanced options',
    'collapsible_label' => NULL,
    'combine_rewrite' => NULL,
    'reset_label' => NULL,
  ),
  'type_1' => array(
    'bef_format' => 'bef_links',
    'more_options' => array(
      'bef_select_all_none' => FALSE,
      'bef_collapsible' => 0,
      'is_secondary' => 0,
      'any_label' => '',
      'bef_filter_description' => '',
      'tokens' => array(
        'available' => array(
          0 => 'global_types',
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
      ),
      'rewrite' => array(
        'filter_rewrite_values' => '',
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
    ),
    'secondary_label' => NULL,
    'collapsible_label' => NULL,
    'combine_rewrite' => NULL,
    'reset_label' => NULL,
  ),
  'secondary_label' => NULL,
  'collapsible_label' => NULL,
  'combine_rewrite' => NULL,
  'reset_label' => NULL,
);
$handler->display->display_options['exposed_form']['options']['input_required'] = 0;
$handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'full_html';
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '4';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '9';
$handler->display->display_options['pager']['options']['tags']['first'] = 'first';
$handler->display->display_options['pager']['options']['tags']['previous'] = 'previous';
$handler->display->display_options['pager']['options']['tags']['next'] = 'next';
$handler->display->display_options['pager']['options']['tags']['last'] = 'last';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['style_options']['row_class'] = 'webinar_group';
$handler->display->display_options['style_options']['row_class_special'] = FALSE;
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['hide_empty'] = TRUE;
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['header'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Date */
$handler->display->display_options['fields']['field_webinar_date']['id'] = 'field_webinar_date';
$handler->display->display_options['fields']['field_webinar_date']['table'] = 'field_data_field_webinar_date';
$handler->display->display_options['fields']['field_webinar_date']['field'] = 'field_webinar_date';
$handler->display->display_options['fields']['field_webinar_date']['label'] = '';
$handler->display->display_options['fields']['field_webinar_date']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_webinar_date']['settings'] = array(
  'format_type' => 'medium',
  'fromto' => 'value',
  'multiple_number' => '',
  'multiple_from' => '',
  'multiple_to' => '',
  'show_remaining_days' => 0,
  'show_repeat_rule' => 'show',
);
$handler->display->display_options['fields']['field_webinar_date']['delta_offset'] = '0';
/* Field: Field: Title */
$handler->display->display_options['fields']['title_field']['id'] = 'title_field';
$handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
$handler->display->display_options['fields']['title_field']['field'] = 'title_field';
$handler->display->display_options['fields']['title_field']['label'] = '';
$handler->display->display_options['fields']['title_field']['element_class'] = 'news_all_title';
$handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title_field']['link_to_entity'] = 1;
/* Field: Content: Description */
$handler->display->display_options['fields']['field_webinar_description']['id'] = 'field_webinar_description';
$handler->display->display_options['fields']['field_webinar_description']['table'] = 'field_data_field_webinar_description';
$handler->display->display_options['fields']['field_webinar_description']['field'] = 'field_webinar_description';
$handler->display->display_options['fields']['field_webinar_description']['label'] = '';
$handler->display->display_options['fields']['field_webinar_description']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_webinar_description']['type'] = 'text_summary_or_trimmed';
$handler->display->display_options['fields']['field_webinar_description']['settings'] = array(
  'trim_length' => '500',
);
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: Content: Date -  start date (field_webinar_date) */
$handler->display->display_options['sorts']['field_webinar_date_value']['id'] = 'field_webinar_date_value';
$handler->display->display_options['sorts']['field_webinar_date_value']['table'] = 'field_data_field_webinar_date';
$handler->display->display_options['sorts']['field_webinar_date_value']['field'] = 'field_webinar_date_value';
$handler->display->display_options['sorts']['field_webinar_date_value']['order'] = 'DESC';
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
  'webinar' => 'webinar',
);

/* Display: Blog */
$handler = $view->new_display('block', 'Blog', 'blog');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['defaults']['css_class'] = FALSE;
$handler->display->display_options['defaults']['exposed_form'] = FALSE;
$handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
$handler->display->display_options['exposed_form']['options']['bef'] = array(
  'general' => array(
    'allow_secondary' => 0,
    'secondary_label' => 'Advanced options',
    'collapsible_label' => NULL,
    'combine_rewrite' => NULL,
    'reset_label' => NULL,
  ),
  'type_1' => array(
    'bef_format' => 'bef_links',
    'more_options' => array(
      'bef_select_all_none' => FALSE,
      'bef_collapsible' => 0,
      'is_secondary' => 0,
      'any_label' => '',
      'bef_filter_description' => '',
      'tokens' => array(
        'available' => array(
          0 => 'global_types',
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
      ),
      'rewrite' => array(
        'filter_rewrite_values' => '',
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
    ),
    'secondary_label' => NULL,
    'collapsible_label' => NULL,
    'combine_rewrite' => NULL,
    'reset_label' => NULL,
  ),
  'secondary_label' => NULL,
  'collapsible_label' => NULL,
  'combine_rewrite' => NULL,
  'reset_label' => NULL,
);
$handler->display->display_options['exposed_form']['options']['input_required'] = 0;
$handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'full_html';
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '6';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '9';
$handler->display->display_options['pager']['options']['tags']['first'] = 'first';
$handler->display->display_options['pager']['options']['tags']['previous'] = 'previous';
$handler->display->display_options['pager']['options']['tags']['next'] = 'next';
$handler->display->display_options['pager']['options']['tags']['last'] = 'last';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['header'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Image */
$handler->display->display_options['fields']['field_blog_image']['id'] = 'field_blog_image';
$handler->display->display_options['fields']['field_blog_image']['table'] = 'field_data_field_blog_image';
$handler->display->display_options['fields']['field_blog_image']['field'] = 'field_blog_image';
$handler->display->display_options['fields']['field_blog_image']['label'] = '';
$handler->display->display_options['fields']['field_blog_image']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_blog_image']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_blog_image']['settings'] = array(
  'image_style' => 'blog_image_style',
  'image_link' => '',
);
/* Field: Field: Title */
$handler->display->display_options['fields']['title_field']['id'] = 'title_field';
$handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
$handler->display->display_options['fields']['title_field']['field'] = 'title_field';
$handler->display->display_options['fields']['title_field']['label'] = '';
$handler->display->display_options['fields']['title_field']['element_class'] = 'news_blog_title';
$handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title_field']['link_to_entity'] = 1;
/* Field: Content: Body */
$handler->display->display_options['fields']['field_blog_body']['id'] = 'field_blog_body';
$handler->display->display_options['fields']['field_blog_body']['table'] = 'field_data_field_blog_body';
$handler->display->display_options['fields']['field_blog_body']['field'] = 'field_blog_body';
$handler->display->display_options['fields']['field_blog_body']['label'] = '';
$handler->display->display_options['fields']['field_blog_body']['alter']['max_length'] = '200';
$handler->display->display_options['fields']['field_blog_body']['alter']['trim'] = TRUE;
$handler->display->display_options['fields']['field_blog_body']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_blog_body']['type'] = 'text_summary_or_trimmed';
$handler->display->display_options['fields']['field_blog_body']['settings'] = array(
  'trim_length' => '200',
);
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: Content: Post date */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'node';
$handler->display->display_options['sorts']['created']['field'] = 'created';
$handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
  'blog' => 'blog',
);

/* Display: Newsletters */
$handler = $view->new_display('block', 'Newsletters', 'newsletters');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['defaults']['css_class'] = FALSE;
$handler->display->display_options['defaults']['exposed_form'] = FALSE;
$handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
$handler->display->display_options['exposed_form']['options']['bef'] = array(
  'general' => array(
    'allow_secondary' => 0,
    'secondary_label' => 'Advanced options',
    'collapsible_label' => NULL,
    'combine_rewrite' => NULL,
    'reset_label' => NULL,
  ),
  'type_1' => array(
    'bef_format' => 'bef_links',
    'more_options' => array(
      'bef_select_all_none' => FALSE,
      'bef_collapsible' => 0,
      'is_secondary' => 0,
      'any_label' => '',
      'bef_filter_description' => '',
      'tokens' => array(
        'available' => array(
          0 => 'global_types',
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
      ),
      'rewrite' => array(
        'filter_rewrite_values' => '',
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
    ),
    'secondary_label' => NULL,
    'collapsible_label' => NULL,
    'combine_rewrite' => NULL,
    'reset_label' => NULL,
  ),
  'secondary_label' => NULL,
  'collapsible_label' => NULL,
  'combine_rewrite' => NULL,
  'reset_label' => NULL,
);
$handler->display->display_options['exposed_form']['options']['input_required'] = 0;
$handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'full_html';
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '5';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '9';
$handler->display->display_options['pager']['options']['tags']['first'] = 'first';
$handler->display->display_options['pager']['options']['tags']['previous'] = 'previous';
$handler->display->display_options['pager']['options']['tags']['next'] = 'next';
$handler->display->display_options['pager']['options']['tags']['last'] = 'last';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['header'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: URL */
$handler->display->display_options['fields']['field_news_url']['id'] = 'field_news_url';
$handler->display->display_options['fields']['field_news_url']['table'] = 'field_data_field_news_url';
$handler->display->display_options['fields']['field_news_url']['field'] = 'field_news_url';
$handler->display->display_options['fields']['field_news_url']['label'] = '';
$handler->display->display_options['fields']['field_news_url']['element_class'] = 'newsletter_titles';
$handler->display->display_options['fields']['field_news_url']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_news_url']['click_sort_column'] = 'url';
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: Content: Publish date (field_publish_date) */
$handler->display->display_options['sorts']['field_publish_date_value']['id'] = 'field_publish_date_value';
$handler->display->display_options['sorts']['field_publish_date_value']['table'] = 'field_data_field_publish_date';
$handler->display->display_options['sorts']['field_publish_date_value']['field'] = 'field_publish_date_value';
$handler->display->display_options['sorts']['field_publish_date_value']['order'] = 'DESC';
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
  'news' => 'news',
);