<?php

$view = new view();
$view->name = 'brand_items';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'bean';
$view->human_name = 'Brand Items';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = '<none>';
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
$handler->display->display_options['pager']['options']['items_per_page'] = '3';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'views_bootstrap_grid_plugin_style';
$handler->display->display_options['row_plugin'] = 'fields';
/* Field: Block: Internal, numeric block ID */
$handler->display->display_options['fields']['bid']['id'] = 'bid';
$handler->display->display_options['fields']['bid']['table'] = 'bean';
$handler->display->display_options['fields']['bid']['field'] = 'bid';
$handler->display->display_options['fields']['bid']['label'] = '';
$handler->display->display_options['fields']['bid']['exclude'] = TRUE;
$handler->display->display_options['fields']['bid']['element_label_colon'] = FALSE;
/* Field: Block: Image */
$handler->display->display_options['fields']['field_brand_icon']['id'] = 'field_brand_icon';
$handler->display->display_options['fields']['field_brand_icon']['table'] = 'field_data_field_brand_icon';
$handler->display->display_options['fields']['field_brand_icon']['field'] = 'field_brand_icon';
$handler->display->display_options['fields']['field_brand_icon']['label'] = '';
$handler->display->display_options['fields']['field_brand_icon']['element_class'] = 'brand_icon_front';
$handler->display->display_options['fields']['field_brand_icon']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_brand_icon']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_brand_icon']['type'] = 'picture';
$handler->display->display_options['fields']['field_brand_icon']['settings'] = array(
  'picture_mapping' => 'brand_item',
  'fallback_image_style' => '',
  'lazyload' => 1,
  'lazyload_aspect_ratio' => 1,
  'image_link' => '',
);
/* Field: Field: Title */
$handler->display->display_options['fields']['title_field']['id'] = 'title_field';
$handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
$handler->display->display_options['fields']['title_field']['field'] = 'title_field';
$handler->display->display_options['fields']['title_field']['label'] = '';
$handler->display->display_options['fields']['title_field']['element_label_class'] = 'brand_title_front';
$handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
/* Field: Block: Short text / URL */
$handler->display->display_options['fields']['field_brand_teaser']['id'] = 'field_brand_teaser';
$handler->display->display_options['fields']['field_brand_teaser']['table'] = 'field_data_field_brand_teaser';
$handler->display->display_options['fields']['field_brand_teaser']['field'] = 'field_brand_teaser';
$handler->display->display_options['fields']['field_brand_teaser']['label'] = '';
$handler->display->display_options['fields']['field_brand_teaser']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_brand_teaser']['click_sort_column'] = 'url';
/* Filter criterion: Block: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'bean';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'brand_item' => 'brand_item',
);

/* Display: Front Page */
$handler = $view->new_display('block', 'Front Page', 'brand_items_front');
$handler->display->display_options['display_description'] = 'Front page brand items';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['style_options']['row_class_special'] = FALSE;
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Block: Internal, numeric block ID */
$handler->display->display_options['fields']['bid']['id'] = 'bid';
$handler->display->display_options['fields']['bid']['table'] = 'bean';
$handler->display->display_options['fields']['bid']['field'] = 'bid';
$handler->display->display_options['fields']['bid']['label'] = '';
$handler->display->display_options['fields']['bid']['exclude'] = TRUE;
$handler->display->display_options['fields']['bid']['element_label_colon'] = FALSE;
/* Field: Block: Icon */
$handler->display->display_options['fields']['field_icon']['id'] = 'field_icon';
$handler->display->display_options['fields']['field_icon']['table'] = 'field_data_field_icon';
$handler->display->display_options['fields']['field_icon']['field'] = 'field_icon';
$handler->display->display_options['fields']['field_icon']['label'] = '';
$handler->display->display_options['fields']['field_icon']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_icon']['click_sort_column'] = 'bundle';
$handler->display->display_options['fields']['field_icon']['settings'] = array(
  'link_to_content' => 0,
);
/* Field: Field: Title */
$handler->display->display_options['fields']['title_field']['id'] = 'title_field';
$handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
$handler->display->display_options['fields']['title_field']['field'] = 'title_field';
$handler->display->display_options['fields']['title_field']['label'] = '';
$handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title_field']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
/* Field: Block: Short text / URL */
$handler->display->display_options['fields']['field_brand_teaser']['id'] = 'field_brand_teaser';
$handler->display->display_options['fields']['field_brand_teaser']['table'] = 'field_data_field_brand_teaser';
$handler->display->display_options['fields']['field_brand_teaser']['field'] = 'field_brand_teaser';
$handler->display->display_options['fields']['field_brand_teaser']['label'] = '';
$handler->display->display_options['fields']['field_brand_teaser']['element_type'] = 'div';
$handler->display->display_options['fields']['field_brand_teaser']['element_class'] = 'brand_link_front';
$handler->display->display_options['fields']['field_brand_teaser']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_brand_teaser']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_brand_teaser']['click_sort_column'] = 'url';
$handler->display->display_options['fields']['field_brand_teaser']['type'] = 'link_title_plain';

/* Display: About Us */
$handler = $view->new_display('block', 'About Us', 'brand_items_about_us');
$handler->display->display_options['display_description'] = 'Brand items displayed on the about us page';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['style_options']['default_row_class'] = FALSE;
$handler->display->display_options['style_options']['row_class_special'] = FALSE;
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Block: Internal, numeric block ID */
$handler->display->display_options['fields']['bid']['id'] = 'bid';
$handler->display->display_options['fields']['bid']['table'] = 'bean';
$handler->display->display_options['fields']['bid']['field'] = 'bid';
$handler->display->display_options['fields']['bid']['label'] = '';
$handler->display->display_options['fields']['bid']['exclude'] = TRUE;
$handler->display->display_options['fields']['bid']['element_label_colon'] = FALSE;
/* Field: Block: Icon */
$handler->display->display_options['fields']['field_icon']['id'] = 'field_icon';
$handler->display->display_options['fields']['field_icon']['table'] = 'field_data_field_icon';
$handler->display->display_options['fields']['field_icon']['field'] = 'field_icon';
$handler->display->display_options['fields']['field_icon']['label'] = '';
$handler->display->display_options['fields']['field_icon']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_icon']['click_sort_column'] = 'bundle';
$handler->display->display_options['fields']['field_icon']['settings'] = array(
  'link_to_content' => 0,
);
/* Field: Field: Title */
$handler->display->display_options['fields']['title_field']['id'] = 'title_field';
$handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
$handler->display->display_options['fields']['title_field']['field'] = 'title_field';
$handler->display->display_options['fields']['title_field']['label'] = '';
$handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title_field']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
/* Field: Block: Body */
$handler->display->display_options['fields']['field_brand_body']['id'] = 'field_brand_body';
$handler->display->display_options['fields']['field_brand_body']['table'] = 'field_data_field_brand_body';
$handler->display->display_options['fields']['field_brand_body']['field'] = 'field_brand_body';
$handler->display->display_options['fields']['field_brand_body']['label'] = '';
$handler->display->display_options['fields']['field_brand_body']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_brand_body']['element_default_classes'] = FALSE;

/* Display: Our Work - Insights */
$handler = $view->new_display('block', 'Our Work - Insights', 'insights');
$handler->display->display_options['defaults']['css_class'] = FALSE;
$handler->display->display_options['display_description'] = 'Brand items displayed on the \'our work\' page';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['style_options']['default_row_class'] = FALSE;
$handler->display->display_options['style_options']['row_class_special'] = FALSE;
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Block: Internal, numeric block ID */
$handler->display->display_options['fields']['bid']['id'] = 'bid';
$handler->display->display_options['fields']['bid']['table'] = 'bean';
$handler->display->display_options['fields']['bid']['field'] = 'bid';
$handler->display->display_options['fields']['bid']['label'] = '';
$handler->display->display_options['fields']['bid']['exclude'] = TRUE;
$handler->display->display_options['fields']['bid']['element_label_colon'] = FALSE;
/* Field: Block: Icon */
$handler->display->display_options['fields']['field_icon']['id'] = 'field_icon';
$handler->display->display_options['fields']['field_icon']['table'] = 'field_data_field_icon';
$handler->display->display_options['fields']['field_icon']['field'] = 'field_icon';
$handler->display->display_options['fields']['field_icon']['label'] = '';
$handler->display->display_options['fields']['field_icon']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_icon']['click_sort_column'] = 'bundle';
$handler->display->display_options['fields']['field_icon']['settings'] = array(
  'link_to_content' => 0,
);
/* Field: Field: Title */
$handler->display->display_options['fields']['title_field']['id'] = 'title_field';
$handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
$handler->display->display_options['fields']['title_field']['field'] = 'title_field';
$handler->display->display_options['fields']['title_field']['label'] = '';
$handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title_field']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
/* Field: Block: Short text / URL */
$handler->display->display_options['fields']['field_brand_teaser']['id'] = 'field_brand_teaser';
$handler->display->display_options['fields']['field_brand_teaser']['table'] = 'field_data_field_brand_teaser';
$handler->display->display_options['fields']['field_brand_teaser']['field'] = 'field_brand_teaser';
$handler->display->display_options['fields']['field_brand_teaser']['label'] = '';
$handler->display->display_options['fields']['field_brand_teaser']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_brand_teaser']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_brand_teaser']['click_sort_column'] = 'url';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Block: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'bean';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'brand_item' => 'brand_item',
);
/* Filter criterion: Block: Internal, numeric block ID */
$handler->display->display_options['filters']['bid']['id'] = 'bid';
$handler->display->display_options['filters']['bid']['table'] = 'bean';
$handler->display->display_options['filters']['bid']['field'] = 'bid';
$handler->display->display_options['filters']['bid']['value']['value'] = '2';

/* Display: Our Work - Accountability */
$handler = $view->new_display('block', 'Our Work - Accountability', 'accountability');
$handler->display->display_options['defaults']['css_class'] = FALSE;
$handler->display->display_options['display_description'] = 'Brand items displayed on the \'our work\' page';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['style_options']['default_row_class'] = FALSE;
$handler->display->display_options['style_options']['row_class_special'] = FALSE;
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Block: Internal, numeric block ID */
$handler->display->display_options['fields']['bid']['id'] = 'bid';
$handler->display->display_options['fields']['bid']['table'] = 'bean';
$handler->display->display_options['fields']['bid']['field'] = 'bid';
$handler->display->display_options['fields']['bid']['label'] = '';
$handler->display->display_options['fields']['bid']['exclude'] = TRUE;
$handler->display->display_options['fields']['bid']['element_label_colon'] = FALSE;
/* Field: Block: Icon */
$handler->display->display_options['fields']['field_icon']['id'] = 'field_icon';
$handler->display->display_options['fields']['field_icon']['table'] = 'field_data_field_icon';
$handler->display->display_options['fields']['field_icon']['field'] = 'field_icon';
$handler->display->display_options['fields']['field_icon']['label'] = '';
$handler->display->display_options['fields']['field_icon']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_icon']['click_sort_column'] = 'bundle';
$handler->display->display_options['fields']['field_icon']['settings'] = array(
  'link_to_content' => 0,
);
/* Field: Field: Title */
$handler->display->display_options['fields']['title_field']['id'] = 'title_field';
$handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
$handler->display->display_options['fields']['title_field']['field'] = 'title_field';
$handler->display->display_options['fields']['title_field']['label'] = '';
$handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title_field']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
/* Field: Block: Short text / URL */
$handler->display->display_options['fields']['field_brand_teaser']['id'] = 'field_brand_teaser';
$handler->display->display_options['fields']['field_brand_teaser']['table'] = 'field_data_field_brand_teaser';
$handler->display->display_options['fields']['field_brand_teaser']['field'] = 'field_brand_teaser';
$handler->display->display_options['fields']['field_brand_teaser']['label'] = '';
$handler->display->display_options['fields']['field_brand_teaser']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_brand_teaser']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_brand_teaser']['click_sort_column'] = 'url';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Block: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'bean';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'brand_item' => 'brand_item',
);
/* Filter criterion: Block: Internal, numeric block ID */
$handler->display->display_options['filters']['bid']['id'] = 'bid';
$handler->display->display_options['filters']['bid']['table'] = 'bean';
$handler->display->display_options['filters']['bid']['field'] = 'bid';
$handler->display->display_options['filters']['bid']['value']['value'] = '3';

/* Display: Our Work - Acceleration */
$handler = $view->new_display('block', 'Our Work - Acceleration', 'acceleration');
$handler->display->display_options['defaults']['css_class'] = FALSE;
$handler->display->display_options['display_description'] = 'Brand items displayed on the \'our work\' page';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['style_options']['default_row_class'] = FALSE;
$handler->display->display_options['style_options']['row_class_special'] = FALSE;
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Block: Internal, numeric block ID */
$handler->display->display_options['fields']['bid']['id'] = 'bid';
$handler->display->display_options['fields']['bid']['table'] = 'bean';
$handler->display->display_options['fields']['bid']['field'] = 'bid';
$handler->display->display_options['fields']['bid']['label'] = '';
$handler->display->display_options['fields']['bid']['exclude'] = TRUE;
$handler->display->display_options['fields']['bid']['element_label_colon'] = FALSE;
/* Field: Block: Icon */
$handler->display->display_options['fields']['field_icon']['id'] = 'field_icon';
$handler->display->display_options['fields']['field_icon']['table'] = 'field_data_field_icon';
$handler->display->display_options['fields']['field_icon']['field'] = 'field_icon';
$handler->display->display_options['fields']['field_icon']['label'] = '';
$handler->display->display_options['fields']['field_icon']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_icon']['click_sort_column'] = 'bundle';
$handler->display->display_options['fields']['field_icon']['settings'] = array(
  'link_to_content' => 0,
);
/* Field: Field: Title */
$handler->display->display_options['fields']['title_field']['id'] = 'title_field';
$handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
$handler->display->display_options['fields']['title_field']['field'] = 'title_field';
$handler->display->display_options['fields']['title_field']['label'] = '';
$handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title_field']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
/* Field: Block: Short text / URL */
$handler->display->display_options['fields']['field_brand_teaser']['id'] = 'field_brand_teaser';
$handler->display->display_options['fields']['field_brand_teaser']['table'] = 'field_data_field_brand_teaser';
$handler->display->display_options['fields']['field_brand_teaser']['field'] = 'field_brand_teaser';
$handler->display->display_options['fields']['field_brand_teaser']['label'] = '';
$handler->display->display_options['fields']['field_brand_teaser']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_brand_teaser']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_brand_teaser']['click_sort_column'] = 'url';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Block: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'bean';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'brand_item' => 'brand_item',
);
/* Filter criterion: Block: Internal, numeric block ID */
$handler->display->display_options['filters']['bid']['id'] = 'bid';
$handler->display->display_options['filters']['bid']['table'] = 'bean';
$handler->display->display_options['filters']['bid']['field'] = 'bid';
$handler->display->display_options['filters']['bid']['value']['value'] = '4';