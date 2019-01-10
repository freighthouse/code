<?php

$view = new view();
$view->name = 'mapsslider';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'Maps Slider';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '5';
$handler->display->display_options['style_plugin'] = 'slideshow';
$handler->display->display_options['style_options']['default_row_class'] = FALSE;
$handler->display->display_options['style_options']['row_class_special'] = FALSE;
$handler->display->display_options['style_options']['slideshow_type'] = 'views_slideshow_cycle';
$handler->display->display_options['style_options']['slideshow_skin'] = 'default';
$handler->display->display_options['style_options']['skin_info'] = array(
    'class' => 'default',
    'name' => 'Default',
    'module' => 'views_slideshow',
    'path' => '',
    'stylesheets' => array(),
);
$handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['weight'] = '1';
$handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
$handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'title' => 0,
    'field_left_image' => 0,
    'field_right_image' => 0,
);
$handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['weight'] = '1';
$handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
$handler->display->display_options['style_options']['widgets']['top']['views_slideshow_slide_counter']['weight'] = '1';
$handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['weight'] = '1';
$handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
$handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'title' => 0,
    'field_left_image' => 0,
    'field_right_image' => 0,
);
$handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['weight'] = '1';
$handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
$handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_slide_counter']['weight'] = '1';
$handler->display->display_options['style_options']['views_slideshow_cycle']['timeout'] = '5000';
$handler->display->display_options['style_options']['views_slideshow_cycle']['speed'] = '700';
$handler->display->display_options['style_options']['views_slideshow_cycle']['delay'] = '0';
$handler->display->display_options['style_options']['views_slideshow_cycle']['remember_slide_days'] = '1';
$handler->display->display_options['style_options']['views_slideshow_cycle']['items_per_slide'] = '1';
$handler->display->display_options['style_options']['views_slideshow_cycle']['wait_for_image_load_timeout'] = '3000';
$handler->display->display_options['style_options']['views_slideshow_cycle']['cleartype'] = 0;
$handler->display->display_options['style_options']['views_slideshow_cycle']['cleartypenobg'] = 0;
$handler->display->display_options['row_plugin'] = 'fields';
/* Footer: Global: Text area */
$handler->display->display_options['footer']['area']['id'] = 'area';
$handler->display->display_options['footer']['area']['table'] = 'views';
$handler->display->display_options['footer']['area']['field'] = 'area';
$handler->display->display_options['footer']['area']['content'] = '*Economic Innovation Group (May 2016) “The New Map of Economic Growth and Recovery”, (Reproduction of Maps, pg. 11) Available at: <a href="http://eig.org/recoverymap">http://eig.org/recoverymap</a>.';
$handler->display->display_options['footer']['area']['format'] = 'full_html';
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['text'] = '<h2">[title]</h2>';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_type'] = 'h2';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Content: Left Image */
$handler->display->display_options['fields']['field_left_image']['id'] = 'field_left_image';
$handler->display->display_options['fields']['field_left_image']['table'] = 'field_data_field_left_image';
$handler->display->display_options['fields']['field_left_image']['field'] = 'field_left_image';
$handler->display->display_options['fields']['field_left_image']['label'] = '';
$handler->display->display_options['fields']['field_left_image']['element_type'] = '0';
$handler->display->display_options['fields']['field_left_image']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_left_image']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_left_image']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_left_image']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_left_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
);
$handler->display->display_options['fields']['field_left_image']['delta_offset'] = '0';
$handler->display->display_options['fields']['field_left_image']['field_api_classes'] = TRUE;
/* Field: Content: Right Image */
$handler->display->display_options['fields']['field_right_image']['id'] = 'field_right_image';
$handler->display->display_options['fields']['field_right_image']['table'] = 'field_data_field_right_image';
$handler->display->display_options['fields']['field_right_image']['field'] = 'field_right_image';
$handler->display->display_options['fields']['field_right_image']['label'] = '';
$handler->display->display_options['fields']['field_right_image']['element_type'] = '0';
$handler->display->display_options['fields']['field_right_image']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_right_image']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_right_image']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_right_image']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_right_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
);
$handler->display->display_options['fields']['field_right_image']['field_api_classes'] = TRUE;
/* Sort criterion: Content: Left Image (field_left_image:title) */
$handler->display->display_options['sorts']['field_left_image_title']['id'] = 'field_left_image_title';
$handler->display->display_options['sorts']['field_left_image_title']['table'] = 'field_data_field_left_image';
$handler->display->display_options['sorts']['field_left_image_title']['field'] = 'field_left_image_title';
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
    'landing_page_slider' => 'landing_page_slider',
);

/* Display: Block */
$handler = $view->new_display('block', 'Block', 'block');

/* Display: Block */
$handler = $view->new_display('block', 'Block', 'block_1');
$handler->display->display_options['defaults']['footer'] = FALSE;
/* Footer: Global: Text area */
$handler->display->display_options['footer']['area']['id'] = 'area';
$handler->display->display_options['footer']['area']['table'] = 'views';
$handler->display->display_options['footer']['area']['field'] = 'area';
$handler->display->display_options['footer']['area']['content'] = '*Economic Innovation Group (May 2016) “The New Map of Economic Growth and Recovery”, (Reproduction of Maps, pg. 11) Available at: <a href="http://eig.org/recoverymap">http://eig.org/recoverymap</a>.

<h2> EXPLORE OUR POLICY PAPERS </h2>';
$handler->display->display_options['footer']['area']['format'] = 'full_html';
$translatables['mapsslider'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('*Economic Innovation Group (May 2016) “The New Map of Economic Growth and Recovery”, (Reproduction of Maps, pg. 11) Available at: <a href="http://eig.org/recoverymap">http://eig.org/recoverymap</a>.'),
    t('<h2">[title]</h2>'),
    t('Block'),
    t('*Economic Innovation Group (May 2016) “The New Map of Economic Growth and Recovery”, (Reproduction of Maps, pg. 11) Available at: <a href="http://eig.org/recoverymap">http://eig.org/recoverymap</a>.

<h2> EXPLORE OUR POLICY PAPERS </h2>'),
);