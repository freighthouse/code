<?php

$view = new view();
$view->name = 'news';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'News';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'News';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'time';
$handler->display->display_options['cache']['results_lifespan'] = '300';
$handler->display->display_options['cache']['results_lifespan_custom'] = '0';
$handler->display->display_options['cache']['output_lifespan'] = '300';
$handler->display->display_options['cache']['output_lifespan_custom'] = '0';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['row_plugin'] = 'node';
$handler->display->display_options['row_options']['links'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
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
  'blog' => 'blog',
  'press_release' => 'press_release',
);

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['style_options']['grouping'] = array(
  0 => array(
    'field' => 'nid',
    'rendered' => 0,
    'rendered_strip' => 0,
  ),
);
$handler->display->display_options['style_options']['row_class_special'] = FALSE;
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['inline'] = array(
  'type' => 'type',
  'field_news_date' => 'field_news_date',
  'field_pr_date' => 'field_pr_date',
  'field_blog_publish_date' => 'field_blog_publish_date',
);
$handler->display->display_options['row_options']['separator'] = '  |  ';
$handler->display->display_options['row_options']['hide_empty'] = TRUE;
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Type */
$handler->display->display_options['fields']['type']['id'] = 'type';
$handler->display->display_options['fields']['type']['table'] = 'node';
$handler->display->display_options['fields']['type']['field'] = 'type';
$handler->display->display_options['fields']['type']['label'] = '';
$handler->display->display_options['fields']['type']['element_class'] = 'news_all_type_date';
$handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
/* Field: Content: Date */
$handler->display->display_options['fields']['field_news_date']['id'] = 'field_news_date';
$handler->display->display_options['fields']['field_news_date']['table'] = 'field_data_field_news_date';
$handler->display->display_options['fields']['field_news_date']['field'] = 'field_news_date';
$handler->display->display_options['fields']['field_news_date']['label'] = '';
$handler->display->display_options['fields']['field_news_date']['element_class'] = 'news_all_type_date';
$handler->display->display_options['fields']['field_news_date']['element_label_colon'] = FALSE;
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
$handler->display->display_options['fields']['title']['element_class'] = 'news_all_title';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
/* Field: Content: Body */
$handler->display->display_options['fields']['field_news_body']['id'] = 'field_news_body';
$handler->display->display_options['fields']['field_news_body']['table'] = 'field_data_field_news_body';
$handler->display->display_options['fields']['field_news_body']['field'] = 'field_news_body';
$handler->display->display_options['fields']['field_news_body']['label'] = '';
$handler->display->display_options['fields']['field_news_body']['element_label_class'] = 'news_all_body';
$handler->display->display_options['fields']['field_news_body']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_news_body']['type'] = 'text_summary_or_trimmed';
$handler->display->display_options['fields']['field_news_body']['settings'] = array(
  'trim_length' => '500',
);
/* Field: Content: Body */
$handler->display->display_options['fields']['field_blog_body']['id'] = 'field_blog_body';
$handler->display->display_options['fields']['field_blog_body']['table'] = 'field_data_field_blog_body';
$handler->display->display_options['fields']['field_blog_body']['field'] = 'field_blog_body';
$handler->display->display_options['fields']['field_blog_body']['label'] = '';
$handler->display->display_options['fields']['field_blog_body']['element_class'] = 'news_all_body';
$handler->display->display_options['fields']['field_blog_body']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_blog_body']['type'] = 'text_summary_or_trimmed';
$handler->display->display_options['fields']['field_blog_body']['settings'] = array(
  'trim_length' => '500',
);
/* Field: Content: Body */
$handler->display->display_options['fields']['field_pr_body']['id'] = 'field_pr_body';
$handler->display->display_options['fields']['field_pr_body']['table'] = 'field_data_field_pr_body';
$handler->display->display_options['fields']['field_pr_body']['field'] = 'field_pr_body';
$handler->display->display_options['fields']['field_pr_body']['label'] = '';
$handler->display->display_options['fields']['field_pr_body']['element_class'] = 'news_all_body';
$handler->display->display_options['fields']['field_pr_body']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_pr_body']['type'] = 'text_summary_or_trimmed';
$handler->display->display_options['fields']['field_pr_body']['settings'] = array(
  'trim_length' => '500',
);
$handler->display->display_options['path'] = 'news';

/* Display: News/Events */
$handler = $view->new_display('page', 'News/Events', 'page_1');
$handler->display->display_options['defaults']['use_more'] = FALSE;
$handler->display->display_options['defaults']['use_more_always'] = FALSE;
$handler->display->display_options['defaults']['use_more_always'] = FALSE;
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['defaults']['use_more_text'] = FALSE;
$handler->display->display_options['use_more_text'] = '...';
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '6';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['style_options']['grouping'] = array(
  0 => array(
    'field' => 'nid',
    'rendered' => 0,
    'rendered_strip' => 0,
  ),
);
$handler->display->display_options['style_options']['row_class_special'] = FALSE;
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['inline'] = array(
  'type' => 'type',
  'field_publish_date' => 'field_publish_date',
);
$handler->display->display_options['row_options']['separator'] = '  |  ';
$handler->display->display_options['row_options']['hide_empty'] = TRUE;
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Type */
$handler->display->display_options['fields']['type']['id'] = 'type';
$handler->display->display_options['fields']['type']['table'] = 'node';
$handler->display->display_options['fields']['type']['field'] = 'type';
$handler->display->display_options['fields']['type']['label'] = '';
$handler->display->display_options['fields']['type']['element_class'] = 'news_all_type_date';
$handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
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
$handler->display->display_options['fields']['title']['element_class'] = 'news_all_title';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
/* Field: Content: Body */
$handler->display->display_options['fields']['field_news_body']['id'] = 'field_news_body';
$handler->display->display_options['fields']['field_news_body']['table'] = 'field_data_field_news_body';
$handler->display->display_options['fields']['field_news_body']['field'] = 'field_news_body';
$handler->display->display_options['fields']['field_news_body']['label'] = '';
$handler->display->display_options['fields']['field_news_body']['alter']['max_length'] = '200';
$handler->display->display_options['fields']['field_news_body']['alter']['trim'] = TRUE;
$handler->display->display_options['fields']['field_news_body']['element_label_class'] = 'news_all_body';
$handler->display->display_options['fields']['field_news_body']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_news_body']['type'] = 'text_summary_or_trimmed';
$handler->display->display_options['fields']['field_news_body']['settings'] = array(
  'trim_length' => '201',
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
  'trim_length' => '201',
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
  'trim_length' => '201',
);
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
  'blog' => 'blog',
  'news' => 'news',
  'press_release' => 'press_release',
);
$handler->display->display_options['path'] = 'news-front';