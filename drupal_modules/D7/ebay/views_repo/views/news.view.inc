<?php

$view = new view();
$view->name = 'news';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'news';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Blog';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['distinct'] = TRUE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['style_plugin'] = 'list';
$handler->display->display_options['style_options']['row_class'] = 'news-item';
$handler->display->display_options['style_options']['default_row_class'] = FALSE;
$handler->display->display_options['style_options']['row_class_special'] = FALSE;
$handler->display->display_options['style_options']['class'] = 'news-items';
$handler->display->display_options['style_options']['wrapper_class'] = 'news-items-wrapper';
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['default_field_elements'] = FALSE;
/* Footer: Global: Text area */
$handler->display->display_options['footer']['area']['id'] = 'area';
$handler->display->display_options['footer']['area']['table'] = 'views';
$handler->display->display_options['footer']['area']['field'] = 'area';
$handler->display->display_options['footer']['area']['format'] = 'filtered_html';
/* Field: Content: Post date */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'node';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['label'] = '';
$handler->display->display_options['fields']['created']['element_type'] = 'p';
$handler->display->display_options['fields']['created']['element_class'] = 'views-field-created';
$handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['created']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['created']['date_format'] = 'custom';
$handler->display->display_options['fields']['created']['custom_date_format'] = 'F j, Y';
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_type'] = 'h3';
$handler->display->display_options['fields']['title']['element_class'] = 'views-field-title';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
/* Field: Content: Thumbnail */
$handler->display->display_options['fields']['field_news_photo']['id'] = 'field_news_photo';
$handler->display->display_options['fields']['field_news_photo']['table'] = 'field_data_field_news_photo';
$handler->display->display_options['fields']['field_news_photo']['field'] = 'field_news_photo';
$handler->display->display_options['fields']['field_news_photo']['label'] = '';
$handler->display->display_options['fields']['field_news_photo']['element_type'] = 'div';
$handler->display->display_options['fields']['field_news_photo']['element_class'] = 'news-image';
$handler->display->display_options['fields']['field_news_photo']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_news_photo']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_news_photo']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_news_photo']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_news_photo']['settings'] = array(
    'image_style' => 'news_thumbnail',
    'image_link' => 'content',
);
$handler->display->display_options['fields']['field_news_photo']['delta_limit'] = '1';
$handler->display->display_options['fields']['field_news_photo']['delta_offset'] = '0';
$handler->display->display_options['fields']['field_news_photo']['separator'] = '';
/* Field: Content: Summary */
$handler->display->display_options['fields']['field_news_summary']['id'] = 'field_news_summary';
$handler->display->display_options['fields']['field_news_summary']['table'] = 'field_data_field_news_summary';
$handler->display->display_options['fields']['field_news_summary']['field'] = 'field_news_summary';
$handler->display->display_options['fields']['field_news_summary']['label'] = '';
$handler->display->display_options['fields']['field_news_summary']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_news_summary']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_news_summary']['element_wrapper_class'] = 'news-summary';
$handler->display->display_options['fields']['field_news_summary']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_news_summary']['settings'] = array(
    'trim_length' => '255',
);
/* Field: Content: All taxonomy terms */
$handler->display->display_options['fields']['term_node_tid']['id'] = 'term_node_tid';
$handler->display->display_options['fields']['term_node_tid']['table'] = 'node';
$handler->display->display_options['fields']['term_node_tid']['field'] = 'term_node_tid';
$handler->display->display_options['fields']['term_node_tid']['label'] = 'Regions';
$handler->display->display_options['fields']['term_node_tid']['element_type'] = '0';
$handler->display->display_options['fields']['term_node_tid']['element_label_type'] = '0';
$handler->display->display_options['fields']['term_node_tid']['element_wrapper_type'] = 'p';
$handler->display->display_options['fields']['term_node_tid']['element_wrapper_class'] = 'news-tags';
$handler->display->display_options['fields']['term_node_tid']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['term_node_tid']['link_to_taxonomy'] = FALSE;
$handler->display->display_options['fields']['term_node_tid']['vocabularies'] = array(
    'region' => 0,
    'tags' => 0,
);
/* Field: Content: Link */
$handler->display->display_options['fields']['view_node']['id'] = 'view_node';
$handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
$handler->display->display_options['fields']['view_node']['field'] = 'view_node';
$handler->display->display_options['fields']['view_node']['label'] = '';
$handler->display->display_options['fields']['view_node']['element_type'] = 'p';
$handler->display->display_options['fields']['view_node']['element_class'] = 'more-link';
$handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['view_node']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['view_node']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['view_node']['text'] = 'continue';
/* Sort criterion: Content: Post date */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'node';
$handler->display->display_options['sorts']['created']['field'] = 'created';
$handler->display->display_options['sorts']['created']['order'] = 'DESC';
/* Contextual filter: Content: Region (field_taxonomy_region) */
$handler->display->display_options['arguments']['field_taxonomy_region_tid']['id'] = 'field_taxonomy_region_tid';
$handler->display->display_options['arguments']['field_taxonomy_region_tid']['table'] = 'field_data_field_taxonomy_region';
$handler->display->display_options['arguments']['field_taxonomy_region_tid']['field'] = 'field_taxonomy_region_tid';
$handler->display->display_options['arguments']['field_taxonomy_region_tid']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['field_taxonomy_region_tid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['field_taxonomy_region_tid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['field_taxonomy_region_tid']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['field_taxonomy_region_tid']['specify_validation'] = TRUE;
$handler->display->display_options['arguments']['field_taxonomy_region_tid']['validate']['type'] = 'taxonomy_term';
$handler->display->display_options['arguments']['field_taxonomy_region_tid']['validate_options']['vocabularies'] = array(
    'region' => 'region',
);
$handler->display->display_options['arguments']['field_taxonomy_region_tid']['validate_options']['type'] = 'convert';
$handler->display->display_options['arguments']['field_taxonomy_region_tid']['validate_options']['transform'] = TRUE;
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 1;
$handler->display->display_options['filters']['status']['group'] = 0;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
    'news' => 'news',
);
/* Filter criterion: Content: Language */
$handler->display->display_options['filters']['language']['id'] = 'language';
$handler->display->display_options['filters']['language']['table'] = 'node';
$handler->display->display_options['filters']['language']['field'] = 'language';
$handler->display->display_options['filters']['language']['operator'] = 'not in';
$handler->display->display_options['filters']['language']['value'] = array(
    'fr' => 'fr',
    'de' => 'de',
);
/* Filter criterion: Content: Hide from Views (field_news_hide_views) */
$handler->display->display_options['filters']['field_news_hide_views_value_1']['id'] = 'field_news_hide_views_value_1';
$handler->display->display_options['filters']['field_news_hide_views_value_1']['table'] = 'field_data_field_news_hide_views';
$handler->display->display_options['filters']['field_news_hide_views_value_1']['field'] = 'field_news_hide_views_value';
$handler->display->display_options['filters']['field_news_hide_views_value_1']['operator'] = 'not';
$handler->display->display_options['filters']['field_news_hide_views_value_1']['value'] = array(
    1 => '1',
);

/* Display: EMS2015 - News Page */
$handler = $view->new_display('page', 'EMS2015 - News Page', 'page');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Blog';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['default_field_elements'] = FALSE;
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Path */
$handler->display->display_options['fields']['path']['id'] = 'path';
$handler->display->display_options['fields']['path']['table'] = 'node';
$handler->display->display_options['fields']['path']['field'] = 'path';
$handler->display->display_options['fields']['path']['label'] = '';
$handler->display->display_options['fields']['path']['element_type'] = '0';
$handler->display->display_options['fields']['path']['element_label_type'] = '0';
$handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['path']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['path']['element_default_classes'] = FALSE;
/* Field: Content: Post date */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'node';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['label'] = '';
$handler->display->display_options['fields']['created']['element_type'] = 'p';
$handler->display->display_options['fields']['created']['element_class'] = 'views-field-created';
$handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['created']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['created']['date_format'] = 'custom';
$handler->display->display_options['fields']['created']['custom_date_format'] = 'F j, Y';
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_type'] = 'h3';
$handler->display->display_options['fields']['title']['element_class'] = 'views-field-title';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Content: Thumbnail */
$handler->display->display_options['fields']['field_news_photo']['id'] = 'field_news_photo';
$handler->display->display_options['fields']['field_news_photo']['table'] = 'field_data_field_news_photo';
$handler->display->display_options['fields']['field_news_photo']['field'] = 'field_news_photo';
$handler->display->display_options['fields']['field_news_photo']['label'] = '';
$handler->display->display_options['fields']['field_news_photo']['element_type'] = 'div';
$handler->display->display_options['fields']['field_news_photo']['element_class'] = 'news-image';
$handler->display->display_options['fields']['field_news_photo']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_news_photo']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_news_photo']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_news_photo']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_news_photo']['settings'] = array(
    'image_style' => 'news_thumbnail',
    'image_link' => '',
);
$handler->display->display_options['fields']['field_news_photo']['delta_limit'] = '1';
$handler->display->display_options['fields']['field_news_photo']['delta_offset'] = '0';
$handler->display->display_options['fields']['field_news_photo']['separator'] = '';
/* Field: Content: Summary */
$handler->display->display_options['fields']['field_news_summary']['id'] = 'field_news_summary';
$handler->display->display_options['fields']['field_news_summary']['table'] = 'field_data_field_news_summary';
$handler->display->display_options['fields']['field_news_summary']['field'] = 'field_news_summary';
$handler->display->display_options['fields']['field_news_summary']['label'] = '';
$handler->display->display_options['fields']['field_news_summary']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_news_summary']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_news_summary']['element_wrapper_class'] = 'news-summary';
$handler->display->display_options['fields']['field_news_summary']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_news_summary']['settings'] = array(
    'trim_length' => '255',
);
/* Field: Content: All taxonomy terms */
$handler->display->display_options['fields']['term_node_tid']['id'] = 'term_node_tid';
$handler->display->display_options['fields']['term_node_tid']['table'] = 'node';
$handler->display->display_options['fields']['term_node_tid']['field'] = 'term_node_tid';
$handler->display->display_options['fields']['term_node_tid']['label'] = 'Regions';
$handler->display->display_options['fields']['term_node_tid']['element_type'] = '0';
$handler->display->display_options['fields']['term_node_tid']['element_label_type'] = '0';
$handler->display->display_options['fields']['term_node_tid']['element_wrapper_type'] = 'p';
$handler->display->display_options['fields']['term_node_tid']['element_wrapper_class'] = 'news-tags';
$handler->display->display_options['fields']['term_node_tid']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['term_node_tid']['link_to_taxonomy'] = FALSE;
$handler->display->display_options['fields']['term_node_tid']['vocabularies'] = array(
    'region' => 0,
    'tags' => 0,
);
/* Field: Content: Link */
$handler->display->display_options['fields']['view_node']['id'] = 'view_node';
$handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
$handler->display->display_options['fields']['view_node']['field'] = 'view_node';
$handler->display->display_options['fields']['view_node']['label'] = '';
$handler->display->display_options['fields']['view_node']['element_type'] = 'p';
$handler->display->display_options['fields']['view_node']['element_class'] = 'more-link';
$handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['view_node']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['view_node']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['view_node']['text'] = 'continue';
$handler->display->display_options['defaults']['arguments'] = FALSE;
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 1;
$handler->display->display_options['filters']['status']['group'] = 0;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
    'news' => 'news',
);
/* Filter criterion: Content: Hide from Views (field_news_hide_views) */
$handler->display->display_options['filters']['field_news_hide_views_value']['id'] = 'field_news_hide_views_value';
$handler->display->display_options['filters']['field_news_hide_views_value']['table'] = 'field_data_field_news_hide_views';
$handler->display->display_options['filters']['field_news_hide_views_value']['field'] = 'field_news_hide_views_value';
$handler->display->display_options['filters']['field_news_hide_views_value']['operator'] = 'not';
$handler->display->display_options['filters']['field_news_hide_views_value']['value'] = array(
    1 => '1',
);
/* Filter criterion: Content: Language */
$handler->display->display_options['filters']['language']['id'] = 'language';
$handler->display->display_options['filters']['language']['table'] = 'node';
$handler->display->display_options['filters']['language']['field'] = 'language';
$handler->display->display_options['filters']['language']['operator'] = 'not in';
$handler->display->display_options['filters']['language']['value'] = array(
    'de' => 'de',
);
/* Filter criterion: Content: Hide from Views (field_news_hide_views) */
$handler->display->display_options['filters']['field_news_hide_views_value_1']['id'] = 'field_news_hide_views_value_1';
$handler->display->display_options['filters']['field_news_hide_views_value_1']['table'] = 'field_data_field_news_hide_views';
$handler->display->display_options['filters']['field_news_hide_views_value_1']['field'] = 'field_news_hide_views_value';
$handler->display->display_options['filters']['field_news_hide_views_value_1']['operator'] = 'not';
$handler->display->display_options['filters']['field_news_hide_views_value_1']['value'] = array(
    1 => '1',
);
$handler->display->display_options['path'] = 'blog';

/* Display: News Block Front */
$handler = $view->new_display('block', 'News Block Front', 'block_1');
$handler->display->display_options['defaults']['use_more'] = FALSE;
$handler->display->display_options['use_more'] = TRUE;
$handler->display->display_options['defaults']['use_more_always'] = FALSE;
$handler->display->display_options['defaults']['use_more_always'] = FALSE;
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['defaults']['use_more_text'] = FALSE;
$handler->display->display_options['use_more_text'] = 'read more';
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '5';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'list';
$handler->display->display_options['style_options']['row_class'] = 'news-item';
$handler->display->display_options['style_options']['default_row_class'] = FALSE;
$handler->display->display_options['style_options']['row_class_special'] = FALSE;
$handler->display->display_options['style_options']['class'] = 'news-items';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Contextual filter: Content: Region (field_taxonomy_region) */
$handler->display->display_options['arguments']['field_taxonomy_region_tid']['id'] = 'field_taxonomy_region_tid';
$handler->display->display_options['arguments']['field_taxonomy_region_tid']['table'] = 'field_data_field_taxonomy_region';
$handler->display->display_options['arguments']['field_taxonomy_region_tid']['field'] = 'field_taxonomy_region_tid';
$handler->display->display_options['arguments']['field_taxonomy_region_tid']['default_action'] = 'default';
$handler->display->display_options['arguments']['field_taxonomy_region_tid']['default_argument_type'] = 'php';
$handler->display->display_options['arguments']['field_taxonomy_region_tid']['default_argument_options']['code'] = '  $region = arg(1, drupal_get_path_alias());
  if (!($region)) {
    $region = \'all\';  
  }
return $region;';
$handler->display->display_options['arguments']['field_taxonomy_region_tid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['field_taxonomy_region_tid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['field_taxonomy_region_tid']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['field_taxonomy_region_tid']['specify_validation'] = TRUE;
$handler->display->display_options['arguments']['field_taxonomy_region_tid']['validate']['type'] = 'taxonomy_term';
$handler->display->display_options['arguments']['field_taxonomy_region_tid']['validate_options']['vocabularies'] = array(
    'region' => 'region',
);
$handler->display->display_options['arguments']['field_taxonomy_region_tid']['validate_options']['type'] = 'convert';
$handler->display->display_options['arguments']['field_taxonomy_region_tid']['validate_options']['transform'] = TRUE;

/* Display: Other Blog Posts */
$handler = $view->new_display('block', 'Other Blog Posts', 'block_2');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Other News';
$handler->display->display_options['display_description'] = 'Right sidebar for individual News article pages';
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '5';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['footer'] = FALSE;
/* Footer: Global: Text area */
$handler->display->display_options['footer']['area']['id'] = 'area';
$handler->display->display_options['footer']['area']['table'] = 'views';
$handler->display->display_options['footer']['area']['field'] = 'area';
$handler->display->display_options['footer']['area']['label'] = 'view all news';
$handler->display->display_options['footer']['area']['content'] = '<p class="more-link"><a href="/news">view all news</a></p>';
$handler->display->display_options['footer']['area']['format'] = 'full_html';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Path */
$handler->display->display_options['fields']['path']['id'] = 'path';
$handler->display->display_options['fields']['path']['table'] = 'node';
$handler->display->display_options['fields']['path']['field'] = 'path';
$handler->display->display_options['fields']['path']['label'] = '';
$handler->display->display_options['fields']['path']['element_type'] = '0';
$handler->display->display_options['fields']['path']['element_label_type'] = '0';
$handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['path']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['path']['element_default_classes'] = FALSE;
/* Field: Content: Post date */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'node';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['label'] = '';
$handler->display->display_options['fields']['created']['element_type'] = '0';
$handler->display->display_options['fields']['created']['element_label_type'] = '0';
$handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['created']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['created']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['created']['date_format'] = 'custom';
$handler->display->display_options['fields']['created']['custom_date_format'] = 'F j, Y';
$handler->display->display_options['fields']['created']['second_date_format'] = 'html5_tools_iso8601';
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
$handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Content: Summary */
$handler->display->display_options['fields']['field_news_summary']['id'] = 'field_news_summary';
$handler->display->display_options['fields']['field_news_summary']['table'] = 'field_data_field_news_summary';
$handler->display->display_options['fields']['field_news_summary']['field'] = 'field_news_summary';
$handler->display->display_options['fields']['field_news_summary']['label'] = '';
$handler->display->display_options['fields']['field_news_summary']['element_type'] = '0';
$handler->display->display_options['fields']['field_news_summary']['element_label_type'] = '0';
$handler->display->display_options['fields']['field_news_summary']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_news_summary']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_news_summary']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_news_summary']['type'] = 'text_trimmed';
$handler->display->display_options['fields']['field_news_summary']['settings'] = array(
    'trim_length' => '255',
);
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Contextual filter: Content: Nid */
$handler->display->display_options['arguments']['nid']['id'] = 'nid';
$handler->display->display_options['arguments']['nid']['table'] = 'node';
$handler->display->display_options['arguments']['nid']['field'] = 'nid';
$handler->display->display_options['arguments']['nid']['default_action'] = 'default';
$handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
$handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['nid']['not'] = TRUE;

/* Display: Related News - Issues */
$handler = $view->new_display('block', 'Related News - Issues', 'block_3');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Related News';
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '4';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['style_options']['row_class'] = 'related-news-item';
$handler->display->display_options['style_options']['default_row_class'] = FALSE;
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['footer'] = FALSE;
$handler->display->display_options['defaults']['relationships'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Thumbnail */
$handler->display->display_options['fields']['field_news_photo']['id'] = 'field_news_photo';
$handler->display->display_options['fields']['field_news_photo']['table'] = 'field_data_field_news_photo';
$handler->display->display_options['fields']['field_news_photo']['field'] = 'field_news_photo';
$handler->display->display_options['fields']['field_news_photo']['label'] = '';
$handler->display->display_options['fields']['field_news_photo']['element_type'] = 'div';
$handler->display->display_options['fields']['field_news_photo']['element_class'] = 'news-image';
$handler->display->display_options['fields']['field_news_photo']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_news_photo']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_news_photo']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_news_photo']['hide_empty'] = TRUE;
$handler->display->display_options['fields']['field_news_photo']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_news_photo']['settings'] = array(
    'image_style' => '150x120',
    'image_link' => '',
);
$handler->display->display_options['fields']['field_news_photo']['delta_limit'] = '1';
$handler->display->display_options['fields']['field_news_photo']['delta_offset'] = '0';
$handler->display->display_options['fields']['field_news_photo']['separator'] = '';
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_type'] = 'h3';
$handler->display->display_options['fields']['title']['element_class'] = 'views-field-title';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
/* Field: Content: Post date */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'node';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['label'] = '';
$handler->display->display_options['fields']['created']['exclude'] = TRUE;
$handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['created']['date_format'] = 'custom';
$handler->display->display_options['fields']['created']['custom_date_format'] = 'F j, Y';
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Contextual filter: Content: Related Issue(s) (field_news_issue) */
$handler->display->display_options['arguments']['field_news_issue_nid']['id'] = 'field_news_issue_nid';
$handler->display->display_options['arguments']['field_news_issue_nid']['table'] = 'field_data_field_news_issue';
$handler->display->display_options['arguments']['field_news_issue_nid']['field'] = 'field_news_issue_nid';
$handler->display->display_options['arguments']['field_news_issue_nid']['default_action'] = 'default';
$handler->display->display_options['arguments']['field_news_issue_nid']['default_argument_type'] = 'node';
$handler->display->display_options['arguments']['field_news_issue_nid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['field_news_issue_nid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['field_news_issue_nid']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
);
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
$handler->display->display_options['filters']['type']['group'] = 1;
/* Filter criterion: Content: Hide from Views (field_news_hide_views) */
$handler->display->display_options['filters']['field_news_hide_views_value']['id'] = 'field_news_hide_views_value';
$handler->display->display_options['filters']['field_news_hide_views_value']['table'] = 'field_data_field_news_hide_views';
$handler->display->display_options['filters']['field_news_hide_views_value']['field'] = 'field_news_hide_views_value';
$handler->display->display_options['filters']['field_news_hide_views_value']['operator'] = 'not';
$handler->display->display_options['filters']['field_news_hide_views_value']['value'] = array(
    1 => '1',
);

/* Display: Related News */
$handler = $view->new_display('block', 'Related News', 'block_4');
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '6';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'grid';
$handler->display->display_options['style_options']['grouping'] = '';
$handler->display->display_options['style_options']['columns'] = '3';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['relationships'] = FALSE;
/* Relationship: Content: Taxonomy terms on node */
$handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
$handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
$handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
$handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'region' => 0,
    'tags' => 0,
);
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Contextual filter: Taxonomy term: Term ID */
$handler->display->display_options['arguments']['tid']['id'] = 'tid';
$handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
$handler->display->display_options['arguments']['tid']['field'] = 'tid';
$handler->display->display_options['arguments']['tid']['relationship'] = 'term_node_tid';
$handler->display->display_options['arguments']['tid']['default_action'] = 'not found';
$handler->display->display_options['arguments']['tid']['default_argument_type'] = 'node';
$handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['tid']['specify_validation'] = TRUE;
$handler->display->display_options['arguments']['tid']['validate']['type'] = 'taxonomy_term';
$handler->display->display_options['arguments']['tid']['validate_options']['vocabularies'] = array(
    'tags' => 'tags',
);
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
);
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
$handler->display->display_options['filters']['type']['group'] = 1;
/* Filter criterion: Content: Hide from Views (field_news_hide_views) */
$handler->display->display_options['filters']['field_news_hide_views_value']['id'] = 'field_news_hide_views_value';
$handler->display->display_options['filters']['field_news_hide_views_value']['table'] = 'field_data_field_news_hide_views';
$handler->display->display_options['filters']['field_news_hide_views_value']['field'] = 'field_news_hide_views_value';
$handler->display->display_options['filters']['field_news_hide_views_value']['operator'] = 'not';
$handler->display->display_options['filters']['field_news_hide_views_value']['value'] = array(
    1 => '1',
);

/* Display: Internet Sales Tax News */
$handler = $view->new_display('block', 'Internet Sales Tax News', 'block_5');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Internet Sales Tax News';
$handler->display->display_options['display_description'] = 'Left sidebar for /internet-sales-tax custom page';
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '3';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['footer'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_type'] = 'h4';
$handler->display->display_options['fields']['title']['element_class'] = 'views-field-title';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
/* Field: Content: Post date */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'node';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['label'] = '';
$handler->display->display_options['fields']['created']['element_type'] = 'p';
$handler->display->display_options['fields']['created']['element_class'] = 'views-field-created';
$handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['created']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['created']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['created']['date_format'] = 'custom';
$handler->display->display_options['fields']['created']['custom_date_format'] = 'F j, Y';
/* Field: Content: Summary */
$handler->display->display_options['fields']['field_news_summary']['id'] = 'field_news_summary';
$handler->display->display_options['fields']['field_news_summary']['table'] = 'field_data_field_news_summary';
$handler->display->display_options['fields']['field_news_summary']['field'] = 'field_news_summary';
$handler->display->display_options['fields']['field_news_summary']['label'] = '';
$handler->display->display_options['fields']['field_news_summary']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_news_summary']['type'] = 'text_trimmed';
$handler->display->display_options['fields']['field_news_summary']['settings'] = array(
    'trim_length' => '255',
);
$handler->display->display_options['defaults']['arguments'] = FALSE;
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
);
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
$handler->display->display_options['filters']['type']['group'] = 1;
/* Filter criterion: Content: Related Issue(s) (field_news_issue) */
$handler->display->display_options['filters']['field_news_issue_nid']['id'] = 'field_news_issue_nid';
$handler->display->display_options['filters']['field_news_issue_nid']['table'] = 'field_data_field_news_issue';
$handler->display->display_options['filters']['field_news_issue_nid']['field'] = 'field_news_issue_nid';
$handler->display->display_options['filters']['field_news_issue_nid']['value'] = array(
    968 => '968',
);
$handler->display->display_options['filters']['field_news_issue_nid']['group'] = 1;
/* Filter criterion: Content: Hide from Views (field_news_hide_views) */
$handler->display->display_options['filters']['field_news_hide_views_value']['id'] = 'field_news_hide_views_value';
$handler->display->display_options['filters']['field_news_hide_views_value']['table'] = 'field_data_field_news_hide_views';
$handler->display->display_options['filters']['field_news_hide_views_value']['field'] = 'field_news_hide_views_value';
$handler->display->display_options['filters']['field_news_hide_views_value']['operator'] = 'not';
$handler->display->display_options['filters']['field_news_hide_views_value']['value'] = array(
    1 => '1',
);

/* Display: EMS2015 - News Block Front */
$handler = $view->new_display('block', 'EMS2015 - News Block Front', 'front_page_news');
$handler->display->display_options['defaults']['use_more'] = FALSE;
$handler->display->display_options['use_more'] = TRUE;
$handler->display->display_options['defaults']['use_more_always'] = FALSE;
$handler->display->display_options['defaults']['use_more_always'] = FALSE;
$handler->display->display_options['use_more_always'] = TRUE;
$handler->display->display_options['defaults']['use_more_text'] = FALSE;
$handler->display->display_options['use_more_text'] = 'Read our blog';
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '3';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['style_options']['default_row_class'] = FALSE;
$handler->display->display_options['style_options']['row_class_special'] = FALSE;
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Path */
$handler->display->display_options['fields']['path']['id'] = 'path';
$handler->display->display_options['fields']['path']['table'] = 'node';
$handler->display->display_options['fields']['path']['field'] = 'path';
$handler->display->display_options['fields']['path']['label'] = '';
$handler->display->display_options['fields']['path']['element_type'] = '0';
$handler->display->display_options['fields']['path']['element_label_type'] = '0';
$handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['path']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['path']['element_default_classes'] = FALSE;
/* Field: Content: Post date */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'node';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['label'] = '';
$handler->display->display_options['fields']['created']['element_type'] = 'p';
$handler->display->display_options['fields']['created']['element_class'] = 'views-field-created';
$handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['created']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['created']['date_format'] = 'custom';
$handler->display->display_options['fields']['created']['custom_date_format'] = 'F j, Y';
$handler->display->display_options['fields']['created']['second_date_format'] = 'html5_tools_iso8601';
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
$handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Content: Thumbnail */
$handler->display->display_options['fields']['field_news_photo']['id'] = 'field_news_photo';
$handler->display->display_options['fields']['field_news_photo']['table'] = 'field_data_field_news_photo';
$handler->display->display_options['fields']['field_news_photo']['field'] = 'field_news_photo';
$handler->display->display_options['fields']['field_news_photo']['label'] = '';
$handler->display->display_options['fields']['field_news_photo']['element_type'] = '0';
$handler->display->display_options['fields']['field_news_photo']['element_label_type'] = '0';
$handler->display->display_options['fields']['field_news_photo']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_news_photo']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_news_photo']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_news_photo']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_news_photo']['settings'] = array(
    'image_style' => 'news_thumbnail',
    'image_link' => '',
);
$handler->display->display_options['fields']['field_news_photo']['delta_limit'] = '1';
$handler->display->display_options['fields']['field_news_photo']['delta_offset'] = '0';
$handler->display->display_options['fields']['field_news_photo']['separator'] = '';
/* Field: Content: Summary */
$handler->display->display_options['fields']['field_news_summary']['id'] = 'field_news_summary';
$handler->display->display_options['fields']['field_news_summary']['table'] = 'field_data_field_news_summary';
$handler->display->display_options['fields']['field_news_summary']['field'] = 'field_news_summary';
$handler->display->display_options['fields']['field_news_summary']['label'] = '';
$handler->display->display_options['fields']['field_news_summary']['element_type'] = '0';
$handler->display->display_options['fields']['field_news_summary']['element_label_type'] = '0';
$handler->display->display_options['fields']['field_news_summary']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_news_summary']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_news_summary']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_news_summary']['settings'] = array(
    'trim_length' => '255',
);
/* Field: Content: All taxonomy terms */
$handler->display->display_options['fields']['term_node_tid']['id'] = 'term_node_tid';
$handler->display->display_options['fields']['term_node_tid']['table'] = 'node';
$handler->display->display_options['fields']['term_node_tid']['field'] = 'term_node_tid';
$handler->display->display_options['fields']['term_node_tid']['label'] = '';
$handler->display->display_options['fields']['term_node_tid']['element_type'] = '0';
$handler->display->display_options['fields']['term_node_tid']['element_label_type'] = '0';
$handler->display->display_options['fields']['term_node_tid']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['term_node_tid']['element_wrapper_type'] = 'p';
$handler->display->display_options['fields']['term_node_tid']['element_wrapper_class'] = 'news-tags';
$handler->display->display_options['fields']['term_node_tid']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['term_node_tid']['link_to_taxonomy'] = FALSE;
$handler->display->display_options['fields']['term_node_tid']['vocabularies'] = array(
    'region' => 0,
    'tags' => 0,
);
$handler->display->display_options['defaults']['arguments'] = FALSE;

/* Display: EMS2015 - News Block Community */
$handler = $view->new_display('block', 'EMS2015 - News Block Community', 'block_6');
$handler->display->display_options['defaults']['use_more'] = FALSE;
$handler->display->display_options['use_more'] = TRUE;
$handler->display->display_options['defaults']['use_more_always'] = FALSE;
$handler->display->display_options['defaults']['use_more_always'] = FALSE;
$handler->display->display_options['use_more_always'] = TRUE;
$handler->display->display_options['defaults']['use_more_text'] = FALSE;
$handler->display->display_options['use_more_text'] = 'Visit Main Street Blog';
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '7';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['style_options']['default_row_class'] = FALSE;
$handler->display->display_options['style_options']['row_class_special'] = FALSE;
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Path */
$handler->display->display_options['fields']['path']['id'] = 'path';
$handler->display->display_options['fields']['path']['table'] = 'node';
$handler->display->display_options['fields']['path']['field'] = 'path';
$handler->display->display_options['fields']['path']['label'] = '';
$handler->display->display_options['fields']['path']['element_type'] = '0';
$handler->display->display_options['fields']['path']['element_label_type'] = '0';
$handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['path']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['path']['element_default_classes'] = FALSE;
/* Field: Content: Post date */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'node';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['label'] = '';
$handler->display->display_options['fields']['created']['element_type'] = 'p';
$handler->display->display_options['fields']['created']['element_class'] = 'views-field-created';
$handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['created']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['created']['date_format'] = 'custom';
$handler->display->display_options['fields']['created']['custom_date_format'] = 'F j, Y';
$handler->display->display_options['fields']['created']['second_date_format'] = 'html5_tools_iso8601';
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
$handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Content: Thumbnail */
$handler->display->display_options['fields']['field_news_photo']['id'] = 'field_news_photo';
$handler->display->display_options['fields']['field_news_photo']['table'] = 'field_data_field_news_photo';
$handler->display->display_options['fields']['field_news_photo']['field'] = 'field_news_photo';
$handler->display->display_options['fields']['field_news_photo']['label'] = '';
$handler->display->display_options['fields']['field_news_photo']['element_type'] = '0';
$handler->display->display_options['fields']['field_news_photo']['element_label_type'] = '0';
$handler->display->display_options['fields']['field_news_photo']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_news_photo']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_news_photo']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_news_photo']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_news_photo']['settings'] = array(
    'image_style' => 'news_thumbnail',
    'image_link' => '',
);
$handler->display->display_options['fields']['field_news_photo']['delta_limit'] = '1';
$handler->display->display_options['fields']['field_news_photo']['delta_offset'] = '0';
$handler->display->display_options['fields']['field_news_photo']['separator'] = '';
/* Field: Content: Summary */
$handler->display->display_options['fields']['field_news_summary']['id'] = 'field_news_summary';
$handler->display->display_options['fields']['field_news_summary']['table'] = 'field_data_field_news_summary';
$handler->display->display_options['fields']['field_news_summary']['field'] = 'field_news_summary';
$handler->display->display_options['fields']['field_news_summary']['label'] = '';
$handler->display->display_options['fields']['field_news_summary']['element_type'] = '0';
$handler->display->display_options['fields']['field_news_summary']['element_label_type'] = '0';
$handler->display->display_options['fields']['field_news_summary']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_news_summary']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_news_summary']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_news_summary']['settings'] = array(
    'trim_length' => '255',
);
/* Field: Content: All taxonomy terms */
$handler->display->display_options['fields']['term_node_tid']['id'] = 'term_node_tid';
$handler->display->display_options['fields']['term_node_tid']['table'] = 'node';
$handler->display->display_options['fields']['term_node_tid']['field'] = 'term_node_tid';
$handler->display->display_options['fields']['term_node_tid']['label'] = '';
$handler->display->display_options['fields']['term_node_tid']['element_type'] = '0';
$handler->display->display_options['fields']['term_node_tid']['element_label_type'] = '0';
$handler->display->display_options['fields']['term_node_tid']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['term_node_tid']['element_wrapper_type'] = 'p';
$handler->display->display_options['fields']['term_node_tid']['element_wrapper_class'] = 'news-tags';
$handler->display->display_options['fields']['term_node_tid']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['term_node_tid']['link_to_taxonomy'] = FALSE;
$handler->display->display_options['fields']['term_node_tid']['vocabularies'] = array(
    'region' => 0,
    'tags' => 0,
);
$handler->display->display_options['defaults']['arguments'] = FALSE;

/* Display: EMS2015 - News Block Issue Page */
$handler = $view->new_display('block', 'EMS2015 - News Block Issue Page', 'issue_related_news');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Related News';
$handler->display->display_options['defaults']['use_more'] = FALSE;
$handler->display->display_options['defaults']['use_more_always'] = FALSE;
$handler->display->display_options['defaults']['use_more_always'] = FALSE;
$handler->display->display_options['use_more_always'] = TRUE;
$handler->display->display_options['defaults']['use_more_text'] = FALSE;
$handler->display->display_options['use_more_text'] = 'Read our blog';
$handler->display->display_options['defaults']['group_by'] = FALSE;
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '3';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['style_options']['default_row_class'] = FALSE;
$handler->display->display_options['style_options']['row_class_special'] = FALSE;
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['footer'] = FALSE;
/* Footer: Global: Text area */
$handler->display->display_options['footer']['area']['id'] = 'area';
$handler->display->display_options['footer']['area']['table'] = 'views';
$handler->display->display_options['footer']['area']['field'] = 'area';
$handler->display->display_options['footer']['area']['content'] = '<a href="/news">Read more</a>';
$handler->display->display_options['footer']['area']['format'] = 'filtered_html';
$handler->display->display_options['defaults']['relationships'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Path */
$handler->display->display_options['fields']['path']['id'] = 'path';
$handler->display->display_options['fields']['path']['table'] = 'node';
$handler->display->display_options['fields']['path']['field'] = 'path';
$handler->display->display_options['fields']['path']['label'] = '';
$handler->display->display_options['fields']['path']['element_type'] = '0';
$handler->display->display_options['fields']['path']['element_label_type'] = '0';
$handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['path']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['path']['element_default_classes'] = FALSE;
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
$handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Content: Thumbnail */
$handler->display->display_options['fields']['field_news_photo']['id'] = 'field_news_photo';
$handler->display->display_options['fields']['field_news_photo']['table'] = 'field_data_field_news_photo';
$handler->display->display_options['fields']['field_news_photo']['field'] = 'field_news_photo';
$handler->display->display_options['fields']['field_news_photo']['label'] = '';
$handler->display->display_options['fields']['field_news_photo']['element_type'] = '0';
$handler->display->display_options['fields']['field_news_photo']['element_label_type'] = '0';
$handler->display->display_options['fields']['field_news_photo']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_news_photo']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_news_photo']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_news_photo']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_news_photo']['settings'] = array(
    'image_style' => 'news_thumbnail',
    'image_link' => '',
);
$handler->display->display_options['fields']['field_news_photo']['delta_limit'] = '1';
$handler->display->display_options['fields']['field_news_photo']['delta_offset'] = '0';
$handler->display->display_options['fields']['field_news_photo']['separator'] = '';
/* Field: Content: Post date */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'node';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['label'] = '';
$handler->display->display_options['fields']['created']['element_type'] = 'p';
$handler->display->display_options['fields']['created']['element_class'] = 'views-field-created';
$handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['created']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['created']['date_format'] = 'custom';
$handler->display->display_options['fields']['created']['custom_date_format'] = 'F j, Y';
$handler->display->display_options['fields']['created']['second_date_format'] = 'html5_tools_iso8601';
/* Field: Content: Summary */
$handler->display->display_options['fields']['field_news_summary']['id'] = 'field_news_summary';
$handler->display->display_options['fields']['field_news_summary']['table'] = 'field_data_field_news_summary';
$handler->display->display_options['fields']['field_news_summary']['field'] = 'field_news_summary';
$handler->display->display_options['fields']['field_news_summary']['label'] = '';
$handler->display->display_options['fields']['field_news_summary']['alter']['max_length'] = '240';
$handler->display->display_options['fields']['field_news_summary']['alter']['trim'] = TRUE;
$handler->display->display_options['fields']['field_news_summary']['element_type'] = '0';
$handler->display->display_options['fields']['field_news_summary']['element_label_type'] = '0';
$handler->display->display_options['fields']['field_news_summary']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_news_summary']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_news_summary']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_news_summary']['settings'] = array(
    'trim_length' => '255',
);
/* Field: Content: All taxonomy terms */
$handler->display->display_options['fields']['term_node_tid']['id'] = 'term_node_tid';
$handler->display->display_options['fields']['term_node_tid']['table'] = 'node';
$handler->display->display_options['fields']['term_node_tid']['field'] = 'term_node_tid';
$handler->display->display_options['fields']['term_node_tid']['label'] = '';
$handler->display->display_options['fields']['term_node_tid']['element_type'] = '0';
$handler->display->display_options['fields']['term_node_tid']['element_label_type'] = '0';
$handler->display->display_options['fields']['term_node_tid']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['term_node_tid']['element_wrapper_type'] = 'p';
$handler->display->display_options['fields']['term_node_tid']['element_wrapper_class'] = 'news-tags';
$handler->display->display_options['fields']['term_node_tid']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['term_node_tid']['link_to_taxonomy'] = FALSE;
$handler->display->display_options['fields']['term_node_tid']['vocabularies'] = array(
    'region' => 0,
    'tags' => 0,
);
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Contextual filter: Content: Related Issue(s) (field_news_issue) */
$handler->display->display_options['arguments']['field_news_issue_nid']['id'] = 'field_news_issue_nid';
$handler->display->display_options['arguments']['field_news_issue_nid']['table'] = 'field_data_field_news_issue';
$handler->display->display_options['arguments']['field_news_issue_nid']['field'] = 'field_news_issue_nid';
$handler->display->display_options['arguments']['field_news_issue_nid']['default_action'] = 'default';
$handler->display->display_options['arguments']['field_news_issue_nid']['default_argument_type'] = 'node';
$handler->display->display_options['arguments']['field_news_issue_nid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['field_news_issue_nid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['field_news_issue_nid']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 1;
$handler->display->display_options['filters']['status']['group'] = 0;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
    'news' => 'news',
);
/* Filter criterion: Content: Hide from Views (field_news_hide_views) */
$handler->display->display_options['filters']['field_news_hide_views_value']['id'] = 'field_news_hide_views_value';
$handler->display->display_options['filters']['field_news_hide_views_value']['table'] = 'field_data_field_news_hide_views';
$handler->display->display_options['filters']['field_news_hide_views_value']['field'] = 'field_news_hide_views_value';
$handler->display->display_options['filters']['field_news_hide_views_value']['operator'] = 'not';
$handler->display->display_options['filters']['field_news_hide_views_value']['value'] = array(
    1 => '1',
);
/* Filter criterion: Content: Language */
$handler->display->display_options['filters']['language']['id'] = 'language';
$handler->display->display_options['filters']['language']['table'] = 'node';
$handler->display->display_options['filters']['language']['field'] = 'language';
$handler->display->display_options['filters']['language']['operator'] = 'not in';
$handler->display->display_options['filters']['language']['value'] = array(
    'de' => 'de',
);
$translatables['news'] = array(
    t('Master'),
    t('Blog'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Regions'),
    t('continue'),
    t('All'),
    t('EMS2015 - News Page'),
    t('News Block Front'),
    t('read more'),
    t('Other Blog Posts'),
    t('Other News'),
    t('Right sidebar for individual News article pages'),
    t('view all news'),
    t('<p class="more-link"><a href="/news">view all news</a></p>'),
    t('Related News - Issues'),
    t('Related News'),
    t('term'),
    t('Internet Sales Tax News'),
    t('Left sidebar for /internet-sales-tax custom page'),
    t('EMS2015 - News Block Front'),
    t('Read our blog'),
    t('EMS2015 - News Block Community'),
    t('Visit Main Street Blog'),
    t('EMS2015 - News Block Issue Page'),
    t('<a href="/news">Read more</a>'),
);