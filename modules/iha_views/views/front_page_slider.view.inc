<?php

$view = new view();
$view->name = 'front_page_slider';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'bean';
$view->human_name = 'Front page slider';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Front page slider';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'none';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '4';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'views_bootstrap_carousel_plugin_style';
$handler->display->display_options['style_options']['interval'] = '5000';
$handler->display->display_options['style_options']['navigation'] = 1;
$handler->display->display_options['style_options']['indicators'] = 1;
$handler->display->display_options['style_options']['pause'] = 1;
$handler->display->display_options['row_plugin'] = 'views_bootstrap_carousel_plugin_rows';
$handler->display->display_options['row_options']['image'] = 'field_hero_image';
$handler->display->display_options['row_options']['title'] = 'title_field';
$handler->display->display_options['row_options']['description'] = 'field_hero_slide_description';
$handler->display->display_options['row_options']['buttontext'] = 'field_hero_slide_link';
/* Field: Block: Internal, numeric block ID */
$handler->display->display_options['fields']['bid']['id'] = 'bid';
$handler->display->display_options['fields']['bid']['table'] = 'bean';
$handler->display->display_options['fields']['bid']['field'] = 'bid';
$handler->display->display_options['fields']['bid']['label'] = '';
$handler->display->display_options['fields']['bid']['exclude'] = TRUE;
$handler->display->display_options['fields']['bid']['element_label_colon'] = FALSE;
/* Field: Block: Image */
$handler->display->display_options['fields']['field_hero_image']['id'] = 'field_hero_image';
$handler->display->display_options['fields']['field_hero_image']['table'] = 'field_data_field_hero_image';
$handler->display->display_options['fields']['field_hero_image']['field'] = 'field_hero_image';
$handler->display->display_options['fields']['field_hero_image']['label'] = '';
$handler->display->display_options['fields']['field_hero_image']['element_class'] = 'hero_image_front_page';
$handler->display->display_options['fields']['field_hero_image']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_hero_image']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_hero_image']['type'] = 'picture';
$handler->display->display_options['fields']['field_hero_image']['settings'] = array(
  'picture_mapping' => 'home_hero',
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
$handler->display->display_options['fields']['title_field']['element_type'] = 'h4';
$handler->display->display_options['fields']['title_field']['element_class'] = 'hero_title';
$handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title_field']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
/* Field: Block: Description */
$handler->display->display_options['fields']['field_hero_slide_description']['id'] = 'field_hero_slide_description';
$handler->display->display_options['fields']['field_hero_slide_description']['table'] = 'field_data_field_hero_slide_description';
$handler->display->display_options['fields']['field_hero_slide_description']['field'] = 'field_hero_slide_description';
$handler->display->display_options['fields']['field_hero_slide_description']['label'] = '';
$handler->display->display_options['fields']['field_hero_slide_description']['element_label_colon'] = FALSE;
/* Field: Block: Link */
$handler->display->display_options['fields']['field_hero_slide_link']['id'] = 'field_hero_slide_link';
$handler->display->display_options['fields']['field_hero_slide_link']['table'] = 'field_data_field_hero_slide_link';
$handler->display->display_options['fields']['field_hero_slide_link']['field'] = 'field_hero_slide_link';
$handler->display->display_options['fields']['field_hero_slide_link']['label'] = '';
$handler->display->display_options['fields']['field_hero_slide_link']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_hero_slide_link']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_hero_slide_link']['click_sort_column'] = 'url';
/* Filter criterion: Block: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'bean';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'hero_slide' => 'hero_slide',
);

/* Display: Block */
$handler = $view->new_display('block', 'Block', 'block');