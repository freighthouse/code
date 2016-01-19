<?php

$view = new view();
$view->name = 'resources';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'Resources';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['use_ajax'] = TRUE;
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
$handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = FALSE;
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
  'keys' => array(
    'bef_format' => 'default',
    'more_options' => array(
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
  'field_resource_type_tid' => array(
    'bef_format' => 'default',
    'more_options' => array(
      'bef_select_all_none' => FALSE,
      'bef_collapsible' => 0,
      'is_secondary' => 0,
      'any_label' => '',
      'bef_filter_description' => '',
      'tokens' => array(
        'available' => array(
          0 => 'global_types',
          1 => 'vocabulary',
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
  'field_resource_topic_tid' => array(
    'bef_format' => 'default',
    'more_options' => array(
      'bef_select_all_none' => FALSE,
      'bef_collapsible' => 0,
      'is_secondary' => 0,
      'any_label' => '',
      'bef_filter_description' => '',
      'tokens' => array(
        'available' => array(
          0 => 'global_types',
          1 => 'vocabulary',
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
$handler->display->display_options['style_plugin'] = 'views_bootstrap_table_plugin_style';
$handler->display->display_options['style_options']['row_class_special'] = FALSE;
$handler->display->display_options['style_options']['columns'] = array(
  'title_field' => 'title_field',
  'field_resource_type' => 'field_resource_type',
  'field_resource' => 'field_resource',
  'field_publish_date' => 'field_publish_date',
);
$handler->display->display_options['style_options']['default'] = 'field_publish_date';
$handler->display->display_options['style_options']['info'] = array(
  'title_field' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'field_resource_type' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => 'views-align-left',
    'separator' => '',
    'empty_column' => 0,
  ),
  'field_resource' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => 'views-align-left',
    'separator' => '',
    'empty_column' => 0,
  ),
  'field_publish_date' => array(
    'sortable' => 1,
    'default_sort_order' => 'desc',
    'align' => 'views-align-left',
    'separator' => '',
    'empty_column' => 0,
  ),
);
$handler->display->display_options['style_options']['bootstrap_styles'] = array(
  'striped' => 0,
  'bordered' => 0,
  'hover' => 0,
  'condensed' => 0,
);
/* Field: Field: Title */
$handler->display->display_options['fields']['title_field']['id'] = 'title_field';
$handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
$handler->display->display_options['fields']['title_field']['field'] = 'title_field';
$handler->display->display_options['fields']['title_field']['label'] = '';
$handler->display->display_options['fields']['title_field']['exclude'] = TRUE;
$handler->display->display_options['fields']['title_field']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title_field']['settings'] = array(
  'title_style' => '_none',
  'title_link' => '',
  'title_class' => '',
);
$handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
/* Field: Content: Type */
$handler->display->display_options['fields']['field_resource_type']['id'] = 'field_resource_type';
$handler->display->display_options['fields']['field_resource_type']['table'] = 'field_data_field_resource_type';
$handler->display->display_options['fields']['field_resource_type']['field'] = 'field_resource_type';
$handler->display->display_options['fields']['field_resource_type']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_resource_type']['type'] = 'taxonomy_term_reference_plain';
/* Field: Content: Resource */
$handler->display->display_options['fields']['field_resource']['id'] = 'field_resource';
$handler->display->display_options['fields']['field_resource']['table'] = 'field_data_field_resource';
$handler->display->display_options['fields']['field_resource']['field'] = 'field_resource';
$handler->display->display_options['fields']['field_resource']['label'] = 'Title';
$handler->display->display_options['fields']['field_resource']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['field_resource']['alter']['text'] = '[title_field]';
$handler->display->display_options['fields']['field_resource']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['field_resource']['alter']['path'] = '[field_resource]';
$handler->display->display_options['fields']['field_resource']['alter']['target'] = '_blank';
$handler->display->display_options['fields']['field_resource']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_resource']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_resource']['type'] = 'file_url_plain';
/* Field: Content: Publish date */
$handler->display->display_options['fields']['field_publish_date']['id'] = 'field_publish_date';
$handler->display->display_options['fields']['field_publish_date']['table'] = 'field_data_field_publish_date';
$handler->display->display_options['fields']['field_publish_date']['field'] = 'field_publish_date';
$handler->display->display_options['fields']['field_publish_date']['label'] = 'Date';
$handler->display->display_options['fields']['field_publish_date']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_publish_date']['settings'] = array(
  'format_type' => 'short',
  'fromto' => 'both',
  'multiple_number' => '',
  'multiple_from' => '',
  'multiple_to' => '',
  'show_remaining_days' => 0,
  'show_repeat_rule' => 'show',
);
/* Sort criterion: Content: Publish date (field_publish_date) */
$handler->display->display_options['sorts']['field_publish_date_value']['id'] = 'field_publish_date_value';
$handler->display->display_options['sorts']['field_publish_date_value']['table'] = 'field_data_field_publish_date';
$handler->display->display_options['sorts']['field_publish_date_value']['field'] = 'field_publish_date_value';
$handler->display->display_options['sorts']['field_publish_date_value']['order'] = 'DESC';
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
  'resource' => 'resource',
);
$handler->display->display_options['filters']['type']['group'] = 1;
/* Filter criterion: Search: Search Terms */
$handler->display->display_options['filters']['keys']['id'] = 'keys';
$handler->display->display_options['filters']['keys']['table'] = 'search_index';
$handler->display->display_options['filters']['keys']['field'] = 'keys';
$handler->display->display_options['filters']['keys']['group'] = 1;
$handler->display->display_options['filters']['keys']['exposed'] = TRUE;
$handler->display->display_options['filters']['keys']['expose']['operator_id'] = 'keys_op';
$handler->display->display_options['filters']['keys']['expose']['label'] = 'Keyword';
$handler->display->display_options['filters']['keys']['expose']['operator'] = 'keys_op';
$handler->display->display_options['filters']['keys']['expose']['identifier'] = 'keys';
$handler->display->display_options['filters']['keys']['expose']['remember_roles'] = array(
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
$handler->display->display_options['filters']['keys']['remove_score'] = TRUE;
/* Filter criterion: Content: Type (field_resource_type) */
$handler->display->display_options['filters']['field_resource_type_tid']['id'] = 'field_resource_type_tid';
$handler->display->display_options['filters']['field_resource_type_tid']['table'] = 'field_data_field_resource_type';
$handler->display->display_options['filters']['field_resource_type_tid']['field'] = 'field_resource_type_tid';
$handler->display->display_options['filters']['field_resource_type_tid']['group'] = 1;
$handler->display->display_options['filters']['field_resource_type_tid']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_resource_type_tid']['expose']['operator_id'] = 'field_resource_type_tid_op';
$handler->display->display_options['filters']['field_resource_type_tid']['expose']['label'] = 'Type';
$handler->display->display_options['filters']['field_resource_type_tid']['expose']['operator'] = 'field_resource_type_tid_op';
$handler->display->display_options['filters']['field_resource_type_tid']['expose']['identifier'] = 'field_resource_type_tid';
$handler->display->display_options['filters']['field_resource_type_tid']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  200153887 => 0,
  197637936 => 0,
  30037204 => 0,
  243470429 => 0,
  239385595 => 0,
  41309771 => 0,
  49424304 => 0,
  139655992 => 0,
  176364459 => 0,
  180672576 => 0,
  264258247 => 0,
  207301753 => 0,
  226481355 => 0,
  106126260 => 0,
  78081551 => 0,
);
$handler->display->display_options['filters']['field_resource_type_tid']['type'] = 'select';
$handler->display->display_options['filters']['field_resource_type_tid']['vocabulary'] = 'resources';
/* Filter criterion: Content: Topic (field_resource_topic) */
$handler->display->display_options['filters']['field_resource_topic_tid']['id'] = 'field_resource_topic_tid';
$handler->display->display_options['filters']['field_resource_topic_tid']['table'] = 'field_data_field_resource_topic';
$handler->display->display_options['filters']['field_resource_topic_tid']['field'] = 'field_resource_topic_tid';
$handler->display->display_options['filters']['field_resource_topic_tid']['group'] = 1;
$handler->display->display_options['filters']['field_resource_topic_tid']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_resource_topic_tid']['expose']['operator_id'] = 'field_resource_topic_tid_op';
$handler->display->display_options['filters']['field_resource_topic_tid']['expose']['label'] = 'Topic';
$handler->display->display_options['filters']['field_resource_topic_tid']['expose']['operator'] = 'field_resource_topic_tid_op';
$handler->display->display_options['filters']['field_resource_topic_tid']['expose']['identifier'] = 'field_resource_topic_tid';
$handler->display->display_options['filters']['field_resource_topic_tid']['expose']['remember_roles'] = array(
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
$handler->display->display_options['filters']['field_resource_topic_tid']['type'] = 'select';
$handler->display->display_options['filters']['field_resource_topic_tid']['vocabulary'] = 'topics';

/* Display: Resources */
$handler = $view->new_display('block', 'Resources', 'block');
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '9';
$handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '5, 10, 20, 40, 60, 100';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Field: Title */
$handler->display->display_options['fields']['title_field']['id'] = 'title_field';
$handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
$handler->display->display_options['fields']['title_field']['field'] = 'title_field';
$handler->display->display_options['fields']['title_field']['label'] = '';
$handler->display->display_options['fields']['title_field']['exclude'] = TRUE;
$handler->display->display_options['fields']['title_field']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title_field']['settings'] = array(
  'title_style' => '_none',
  'title_link' => '',
  'title_class' => '',
);
$handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
/* Field: Content: Link */
$handler->display->display_options['fields']['field_news_link']['id'] = 'field_news_link';
$handler->display->display_options['fields']['field_news_link']['table'] = 'field_data_field_news_link';
$handler->display->display_options['fields']['field_news_link']['field'] = 'field_news_link';
$handler->display->display_options['fields']['field_news_link']['label'] = '';
$handler->display->display_options['fields']['field_news_link']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_news_link']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_news_link']['click_sort_column'] = 'url';
/* Field: Content: Type */
$handler->display->display_options['fields']['field_resource_type']['id'] = 'field_resource_type';
$handler->display->display_options['fields']['field_resource_type']['table'] = 'field_data_field_resource_type';
$handler->display->display_options['fields']['field_resource_type']['field'] = 'field_resource_type';
$handler->display->display_options['fields']['field_resource_type']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_resource_type']['type'] = 'taxonomy_term_reference_plain';
/* Field: Content: Resource */
$handler->display->display_options['fields']['field_resource']['id'] = 'field_resource';
$handler->display->display_options['fields']['field_resource']['table'] = 'field_data_field_resource';
$handler->display->display_options['fields']['field_resource']['field'] = 'field_resource';
$handler->display->display_options['fields']['field_resource']['label'] = 'Title';
$handler->display->display_options['fields']['field_resource']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['field_resource']['alter']['text'] = '[title_field]';
$handler->display->display_options['fields']['field_resource']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['field_resource']['alter']['path'] = '[field_resource]';
$handler->display->display_options['fields']['field_resource']['alter']['target'] = '_blank';
$handler->display->display_options['fields']['field_resource']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_resource']['empty'] = '[field_news_link]';
$handler->display->display_options['fields']['field_resource']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_resource']['type'] = 'file_url_plain';
/* Field: Content: Publish date */
$handler->display->display_options['fields']['field_publish_date']['id'] = 'field_publish_date';
$handler->display->display_options['fields']['field_publish_date']['table'] = 'field_data_field_publish_date';
$handler->display->display_options['fields']['field_publish_date']['field'] = 'field_publish_date';
$handler->display->display_options['fields']['field_publish_date']['label'] = 'Date';
$handler->display->display_options['fields']['field_publish_date']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_publish_date']['settings'] = array(
  'format_type' => 'short',
  'fromto' => 'both',
  'multiple_number' => '',
  'multiple_from' => '',
  'multiple_to' => '',
  'show_remaining_days' => 0,
  'show_repeat_rule' => 'show',
);

/* Display: Member Resources */
$handler = $view->new_display('block', 'Member Resources', 'member_resources');
$handler->display->display_options['defaults']['access'] = FALSE;
$handler->display->display_options['access']['type'] = 'role';
$handler->display->display_options['access']['role'] = array(
  30037204 => '30037204',
  2 => '2',
  200153887 => '200153887',
  239385595 => '239385595',
  49424304 => '49424304',
  139655992 => '139655992',
  176364459 => '176364459',
  41309771 => '41309771',
  180672576 => '180672576',
  243470429 => '243470429',
  197637936 => '197637936',
  226481355 => '226481355',
  207301753 => '207301753',
  264258247 => '264258247',
  106126260 => '106126260',
  122688387 => '122688387',
);
$handler->display->display_options['defaults']['query'] = FALSE;
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['distinct'] = TRUE;
$handler->display->display_options['defaults']['exposed_form'] = FALSE;
$handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
$handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
$handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Clear';
$handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
$handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
$handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = FALSE;
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
  'keys' => array(
    'bef_format' => 'default',
    'more_options' => array(
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
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '9';
$handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '5, 10, 20, 40, 60, 100';
$handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = TRUE;
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'views_bootstrap_table_plugin_style';
$handler->display->display_options['style_options']['columns'] = array(
  'title_field_1' => 'title_field_1',
  'field_member_resource' => 'field_member_resource',
  'field_publish_date' => 'field_publish_date',
);
$handler->display->display_options['style_options']['default'] = 'field_publish_date';
$handler->display->display_options['style_options']['info'] = array(
  'title_field_1' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'field_member_resource' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'field_publish_date' => array(
    'sortable' => 1,
    'default_sort_order' => 'desc',
    'align' => 'views-align-left',
    'separator' => '',
    'empty_column' => 0,
  ),
);
$handler->display->display_options['style_options']['empty_table'] = TRUE;
$handler->display->display_options['style_options']['bootstrap_styles'] = array(
  'striped' => 0,
  'bordered' => 0,
  'hover' => 0,
  'condensed' => 0,
);
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Field: Title */
$handler->display->display_options['fields']['title_field_1']['id'] = 'title_field_1';
$handler->display->display_options['fields']['title_field_1']['table'] = 'field_data_title_field';
$handler->display->display_options['fields']['title_field_1']['field'] = 'title_field';
$handler->display->display_options['fields']['title_field_1']['label'] = '';
$handler->display->display_options['fields']['title_field_1']['exclude'] = TRUE;
$handler->display->display_options['fields']['title_field_1']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title_field_1']['link_to_entity'] = 0;
/* Field: Content: Resource */
$handler->display->display_options['fields']['field_member_resource']['id'] = 'field_member_resource';
$handler->display->display_options['fields']['field_member_resource']['table'] = 'field_data_field_member_resource';
$handler->display->display_options['fields']['field_member_resource']['field'] = 'field_member_resource';
$handler->display->display_options['fields']['field_member_resource']['label'] = 'Title';
$handler->display->display_options['fields']['field_member_resource']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['field_member_resource']['alter']['text'] = '[title_field_1]';
$handler->display->display_options['fields']['field_member_resource']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['field_member_resource']['alter']['path'] = '[field_member_resource]';
$handler->display->display_options['fields']['field_member_resource']['alter']['target'] = '_blank';
$handler->display->display_options['fields']['field_member_resource']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_member_resource']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_member_resource']['type'] = 'file_url_plain';
/* Field: Content: Publish date */
$handler->display->display_options['fields']['field_publish_date']['id'] = 'field_publish_date';
$handler->display->display_options['fields']['field_publish_date']['table'] = 'field_data_field_publish_date';
$handler->display->display_options['fields']['field_publish_date']['field'] = 'field_publish_date';
$handler->display->display_options['fields']['field_publish_date']['label'] = 'Date';
$handler->display->display_options['fields']['field_publish_date']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_publish_date']['settings'] = array(
  'format_type' => 'short',
  'fromto' => 'both',
  'multiple_number' => '',
  'multiple_from' => '',
  'multiple_to' => '',
  'show_remaining_days' => 0,
  'show_repeat_rule' => 'show',
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
  'member_resource' => 'member_resource',
);
$handler->display->display_options['filters']['type']['group'] = 1;
$handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
$handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
$handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
$handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
$handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  200153887 => 0,
  197637936 => 0,
  30037204 => 0,
  49424304 => 0,
  139655992 => 0,
  239385595 => 0,
  176364459 => 0,
  41309771 => 0,
  180672576 => 0,
  264258247 => 0,
  207301753 => 0,
  226481355 => 0,
  106126260 => 0,
  78081551 => 0,
  243470429 => 0,
);
/* Filter criterion: Search: Search Terms */
$handler->display->display_options['filters']['keys']['id'] = 'keys';
$handler->display->display_options['filters']['keys']['table'] = 'search_index';
$handler->display->display_options['filters']['keys']['field'] = 'keys';
$handler->display->display_options['filters']['keys']['group'] = 1;
$handler->display->display_options['filters']['keys']['exposed'] = TRUE;
$handler->display->display_options['filters']['keys']['expose']['operator_id'] = 'keys_op';
$handler->display->display_options['filters']['keys']['expose']['label'] = 'Keyword(s)';
$handler->display->display_options['filters']['keys']['expose']['operator'] = 'keys_op';
$handler->display->display_options['filters']['keys']['expose']['identifier'] = 'keys';
$handler->display->display_options['filters']['keys']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  200153887 => 0,
  197637936 => 0,
  30037204 => 0,
  49424304 => 0,
  139655992 => 0,
  239385595 => 0,
  176364459 => 0,
  41309771 => 0,
  180672576 => 0,
  264258247 => 0,
  207301753 => 0,
  226481355 => 0,
  106126260 => 0,
  78081551 => 0,
  243470429 => 0,
);
$handler->display->display_options['filters']['keys']['remove_score'] = TRUE;