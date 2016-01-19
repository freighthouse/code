<?php

$view = new view();
$view->name = 'blog';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'Blog';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Blog';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'time';
$handler->display->display_options['cache']['results_lifespan'] = '300';
$handler->display->display_options['cache']['results_lifespan_custom'] = '0';
$handler->display->display_options['cache']['output_lifespan'] = '300';
$handler->display->display_options['cache']['output_lifespan_custom'] = '0';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '5';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['row_plugin'] = 'fields';
/* Field: Content: Image */
$handler->display->display_options['fields']['field_blog_image']['id'] = 'field_blog_image';
$handler->display->display_options['fields']['field_blog_image']['table'] = 'field_data_field_blog_image';
$handler->display->display_options['fields']['field_blog_image']['field'] = 'field_blog_image';
$handler->display->display_options['fields']['field_blog_image']['label'] = '';
$handler->display->display_options['fields']['field_blog_image']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_blog_image']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_blog_image']['type'] = 'picture';
$handler->display->display_options['fields']['field_blog_image']['settings'] = array(
  'picture_mapping' => 'blog',
  'fallback_image_style' => '',
  'lazyload' => 1,
  'lazyload_aspect_ratio' => 1,
  'image_link' => '',
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
  'conference' => 'conference',
  'event' => 'event',
  'news' => 'news',
  'webinar' => 'webinar',
);

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['style_options']['row_class'] = 'news_group';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['defaults']['row_options'] = FALSE;
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
$handler->display->display_options['path'] = 'blog';
$handler->display->display_options['menu']['type'] = 'normal';
$handler->display->display_options['menu']['title'] = 'Blog';
$handler->display->display_options['menu']['description'] = 'IHA Blog';
$handler->display->display_options['menu']['weight'] = '0';
$handler->display->display_options['menu']['name'] = 'menu-meta-navigation';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;