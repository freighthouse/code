<?php

$view = new view();
$view->name = 'customers_video_slideshow';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'Customers Video Slideshow';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['css_class'] = 'well';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'time';
$handler->display->display_options['cache']['results_lifespan'] = '60';
$handler->display->display_options['cache']['results_lifespan_custom'] = '0';
$handler->display->display_options['cache']['output_lifespan'] = '60';
$handler->display->display_options['cache']['output_lifespan_custom'] = '0';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'slideshow';
$handler->display->display_options['style_options']['row_class'] = 'col-md-3';
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
  'field_video_1' => 0,
  'field_cv_text' => 0,
  'field_video' => 0,
  'field_video_2' => 0,
  'colorbox' => 0,
  'field_primary_topic' => 0,
  'field_topic' => 0,
  'title' => 0,
);
$handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['weight'] = '1';
$handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
$handler->display->display_options['style_options']['widgets']['top']['views_slideshow_slide_counter']['weight'] = '1';
$handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['weight'] = '1';
$handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
$handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
  'field_video_1' => 0,
  'field_cv_text' => 0,
  'field_video' => 0,
  'field_video_2' => 0,
  'colorbox' => 0,
  'field_primary_topic' => 0,
  'field_topic' => 0,
  'title' => 0,
);
$handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['weight'] = '1';
$handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
$handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_slide_counter']['weight'] = '1';
$handler->display->display_options['style_options']['views_slideshow_cycle']['effect'] = 'scrollHorz';
$handler->display->display_options['style_options']['views_slideshow_cycle']['transition_advanced'] = 1;
$handler->display->display_options['style_options']['views_slideshow_cycle']['timeout'] = '0';
$handler->display->display_options['style_options']['views_slideshow_cycle']['speed'] = '700';
$handler->display->display_options['style_options']['views_slideshow_cycle']['delay'] = '0';
$handler->display->display_options['style_options']['views_slideshow_cycle']['pause'] = 0;
$handler->display->display_options['style_options']['views_slideshow_cycle']['action_advanced'] = 1;
$handler->display->display_options['style_options']['views_slideshow_cycle']['start_paused'] = 0;
$handler->display->display_options['style_options']['views_slideshow_cycle']['remember_slide_days'] = '1';
$handler->display->display_options['style_options']['views_slideshow_cycle']['items_per_slide'] = '4';
$handler->display->display_options['style_options']['views_slideshow_cycle']['wait_for_image_load'] = 0;
$handler->display->display_options['style_options']['views_slideshow_cycle']['wait_for_image_load_timeout'] = '3000';
$handler->display->display_options['style_options']['views_slideshow_cycle']['cleartype'] = 0;
$handler->display->display_options['style_options']['views_slideshow_cycle']['cleartypenobg'] = 0;
$handler->display->display_options['row_plugin'] = 'fields';
/* Relationship: Nodequeue: Queue */
$handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
$handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
$handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
$handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
$handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
$handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
  'customer_vignette_slideshow' => 'customer_vignette_slideshow',
  'customers_page' => 0,
  'customer_slideshow' => 0,
  'customers_page_ctas' => 0,
  'webcast_cta' => 0,
  'product_feature_slideshow' => 0,
  'edge_developer_services' => 0,
  'edge_analytics_services' => 0,
  'edge_api_services' => 0,
  '0_team_leadership_team' => 0,
  '1_team_board_of_directors' => 0,
  '2_team_advisory_board' => 0,
  'partner_logos' => 0,
  'partners_vignette_slideshow' => 0,
  'about_apigee_investors' => 0,
  'about_apigee_page_ctas' => 0,
  'customer_front_block' => 0,
  'upcoming_events_page_ctas' => 0,
  'best_practices_ctas' => 0,
  'city_tour_ctas' => 0,
  'homepage_slider' => 0,
  'mini_ctas' => 0,
  'event_page_header' => 0,
  'customer_page_header' => 0,
  'why_page_header' => 0,
  'resources_slideshow' => 0,
  'datasheets' => 0,
  'resources' => 0,
  'resources_customer_stories' => 0,
  'resources_datasheets' => 0,
  'resources_institute_reports' => 0,
  'resources_videos' => 0,
  'resources_webcasts' => 0,
  'resources_articles' => 0,
  'resources_ebooks' => 0,
  'customer_page_top_stories' => 0,
  'webcast_page_header' => 0,
  'resources_innovator_spotlights' => 0,
  'press_page' => 0,
  'resources_product_videos' => 0,
  'featured_blog_posts' => 0,
  'blog_ctas' => 0,
);
/* Field: Video Link */
$handler->display->display_options['fields']['field_video_1']['id'] = 'field_video_1';
$handler->display->display_options['fields']['field_video_1']['table'] = 'field_data_field_video';
$handler->display->display_options['fields']['field_video_1']['field'] = 'field_video';
$handler->display->display_options['fields']['field_video_1']['ui_name'] = 'Video Link';
$handler->display->display_options['fields']['field_video_1']['label'] = '';
$handler->display->display_options['fields']['field_video_1']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_video_1']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_video_1']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_video_1']['type'] = 'file_url_plain';
/* Field: Content: Text */
$handler->display->display_options['fields']['field_cv_text']['id'] = 'field_cv_text';
$handler->display->display_options['fields']['field_cv_text']['table'] = 'field_data_field_cv_text';
$handler->display->display_options['fields']['field_cv_text']['field'] = 'field_cv_text';
$handler->display->display_options['fields']['field_cv_text']['label'] = '';
$handler->display->display_options['fields']['field_cv_text']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_cv_text']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_cv_text']['settings'] = array(
  'linked_field' => array(
    'linked' => 0,
    'destination' => '',
    'advanced' => array(
      'title' => '',
      'target' => '',
      'class' => '',
      'rel' => '',
      'text' => '',
    ),
  ),
);
/* Field: Video Thumbnail */
$handler->display->display_options['fields']['field_video']['id'] = 'field_video';
$handler->display->display_options['fields']['field_video']['table'] = 'field_data_field_video';
$handler->display->display_options['fields']['field_video']['field'] = 'field_video';
$handler->display->display_options['fields']['field_video']['ui_name'] = 'Video Thumbnail';
$handler->display->display_options['fields']['field_video']['label'] = '';
$handler->display->display_options['fields']['field_video']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_video']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['field_video']['alter']['text'] = '[field_video]
<img src="/sites/all/themes/apigee_themes/apigee_bootstrap/images/video-controls.svg" />';
$handler->display->display_options['fields']['field_video']['alter']['path'] = '[field_video_1]';
$handler->display->display_options['fields']['field_video']['alter']['link_class'] = 'colorbox-inline';
$handler->display->display_options['fields']['field_video']['alter']['preserve_tags'] = '<img> <h2> <p>';
$handler->display->display_options['fields']['field_video']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_video']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_video']['hide_empty'] = TRUE;
$handler->display->display_options['fields']['field_video']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_video']['type'] = 'file_rendered';
$handler->display->display_options['fields']['field_video']['settings'] = array(
  'file_view_mode' => 'slider_thumbnail',
  'linked_field' => array(
    'linked' => 0,
    'destination' => '',
    'advanced' => array(
      'title' => '',
      'target' => '',
      'class' => '',
      'rel' => '',
      'text' => '',
    ),
  ),
);
/* Field: Video Player */
$handler->display->display_options['fields']['field_video_2']['id'] = 'field_video_2';
$handler->display->display_options['fields']['field_video_2']['table'] = 'field_data_field_video';
$handler->display->display_options['fields']['field_video_2']['field'] = 'field_video';
$handler->display->display_options['fields']['field_video_2']['ui_name'] = 'Video Player';
$handler->display->display_options['fields']['field_video_2']['label'] = '';
$handler->display->display_options['fields']['field_video_2']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_video_2']['hide_empty'] = TRUE;
$handler->display->display_options['fields']['field_video_2']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_video_2']['type'] = 'file_rendered';
$handler->display->display_options['fields']['field_video_2']['settings'] = array(
  'file_view_mode' => 'live_thumbnail',
  'linked_field' => array(
    'linked' => 0,
    'destination' => '',
    'advanced' => array(
      'title' => '',
      'target' => '',
      'class' => '',
      'rel' => '',
      'text' => '',
    ),
  ),
);
/* Field: Colorbox: Colorbox trigger */
$handler->display->display_options['fields']['colorbox']['id'] = 'colorbox';
$handler->display->display_options['fields']['colorbox']['table'] = 'colorbox';
$handler->display->display_options['fields']['colorbox']['field'] = 'colorbox';
$handler->display->display_options['fields']['colorbox']['label'] = '';
$handler->display->display_options['fields']['colorbox']['exclude'] = TRUE;
$handler->display->display_options['fields']['colorbox']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['colorbox']['hide_empty'] = TRUE;
$handler->display->display_options['fields']['colorbox']['trigger_field'] = 'field_video';
$handler->display->display_options['fields']['colorbox']['popup'] = '[field_video_2]';
$handler->display->display_options['fields']['colorbox']['gid'] = 0;
$handler->display->display_options['fields']['colorbox']['width'] = '640px';
$handler->display->display_options['fields']['colorbox']['height'] = '410px';
/* Field: Content: Primary Topic */
$handler->display->display_options['fields']['field_primary_topic']['id'] = 'field_primary_topic';
$handler->display->display_options['fields']['field_primary_topic']['table'] = 'field_data_field_primary_topic';
$handler->display->display_options['fields']['field_primary_topic']['field'] = 'field_primary_topic';
$handler->display->display_options['fields']['field_primary_topic']['label'] = '';
$handler->display->display_options['fields']['field_primary_topic']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_primary_topic']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_primary_topic']['settings'] = array(
  'link' => 0,
  'linked_field' => array(
    'linked' => 0,
    'destination' => '',
    'advanced' => array(
      'title' => '',
      'target' => '',
      'class' => '',
      'rel' => '',
      'text' => '',
    ),
  ),
);
/* Field: Content: Topic */
$handler->display->display_options['fields']['field_topic']['id'] = 'field_topic';
$handler->display->display_options['fields']['field_topic']['table'] = 'field_data_field_topic';
$handler->display->display_options['fields']['field_topic']['field'] = 'field_topic';
$handler->display->display_options['fields']['field_topic']['label'] = '';
$handler->display->display_options['fields']['field_topic']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_topic']['alter']['text'] = '[field_topic-target_id]';
$handler->display->display_options['fields']['field_topic']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_topic']['settings'] = array(
  'link' => 0,
  'linked_field' => array(
    'linked' => 0,
    'destination' => '',
    'advanced' => array(
      'title' => '',
      'target' => '',
      'class' => '',
      'rel' => '',
      'text' => '',
    ),
  ),
);
$handler->display->display_options['fields']['field_topic']['delta_offset'] = '0';
/* Field: Field: Subtitle */
$handler->display->display_options['fields']['field_subtitle']['id'] = 'field_subtitle';
$handler->display->display_options['fields']['field_subtitle']['table'] = 'field_data_field_subtitle';
$handler->display->display_options['fields']['field_subtitle']['field'] = 'field_subtitle';
$handler->display->display_options['fields']['field_subtitle']['label'] = '';
$handler->display->display_options['fields']['field_subtitle']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_subtitle']['alter']['text'] = '<p>';
$handler->display->display_options['fields']['field_subtitle']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_subtitle']['element_wrapper_type'] = 'p';
$handler->display->display_options['fields']['field_subtitle']['element_wrapper_class'] = 'cv_subtitle';
$handler->display->display_options['fields']['field_subtitle']['hide_empty'] = TRUE;
$handler->display->display_options['fields']['field_subtitle']['settings'] = array(
  'linked_field' => array(
    'linked' => 0,
    'destination' => '',
    'advanced' => array(
      'title' => '',
      'target' => '',
      'class' => '',
      'rel' => '',
      'text' => '',
    ),
  ),
);
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['text'] = '<p>[field_cv_text]</p>
[field_subtitle]';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['title']['element_wrapper_class'] = 'sub-text-container';
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Sort criterion: Nodequeue: Position */
$handler->display->display_options['sorts']['position']['id'] = 'position';
$handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
$handler->display->display_options['sorts']['position']['field'] = 'position';
$handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'customer_vignette' => 'customer_vignette',
);
/* Filter criterion: Content: Video (field_video:fid) */
$handler->display->display_options['filters']['field_video_fid']['id'] = 'field_video_fid';
$handler->display->display_options['filters']['field_video_fid']['table'] = 'field_data_field_video';
$handler->display->display_options['filters']['field_video_fid']['field'] = 'field_video_fid';
$handler->display->display_options['filters']['field_video_fid']['operator'] = 'not empty';

/* Display: Block */
$handler = $view->new_display('block', 'Block', 'block');

/* Display: Front Page Videos */
$handler = $view->new_display('block', 'Front Page Videos', 'front_page_videos');
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '3';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
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
  'field_video_1' => 0,
  'field_cv_text' => 0,
  'field_video' => 0,
  'field_video_2' => 0,
  'colorbox' => 0,
  'field_primary_topic' => 0,
  'field_topic' => 0,
  'field_subtitle' => 0,
  'title' => 0,
);
$handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['weight'] = '1';
$handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
$handler->display->display_options['style_options']['widgets']['top']['views_slideshow_slide_counter']['weight'] = '1';
$handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['weight'] = '1';
$handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
$handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
  'field_video_1' => 0,
  'field_cv_text' => 0,
  'field_video' => 0,
  'field_video_2' => 0,
  'colorbox' => 0,
  'field_primary_topic' => 0,
  'field_topic' => 0,
  'field_subtitle' => 0,
  'title' => 0,
);
$handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['weight'] = '1';
$handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
$handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_slide_counter']['weight'] = '1';
$handler->display->display_options['style_options']['views_slideshow_cycle']['effect'] = 'scrollHorz';
$handler->display->display_options['style_options']['views_slideshow_cycle']['transition_advanced'] = 1;
$handler->display->display_options['style_options']['views_slideshow_cycle']['timeout'] = '0';
$handler->display->display_options['style_options']['views_slideshow_cycle']['speed'] = '700';
$handler->display->display_options['style_options']['views_slideshow_cycle']['delay'] = '0';
$handler->display->display_options['style_options']['views_slideshow_cycle']['pause'] = 0;
$handler->display->display_options['style_options']['views_slideshow_cycle']['action_advanced'] = 1;
$handler->display->display_options['style_options']['views_slideshow_cycle']['start_paused'] = 0;
$handler->display->display_options['style_options']['views_slideshow_cycle']['remember_slide_days'] = '1';
$handler->display->display_options['style_options']['views_slideshow_cycle']['items_per_slide'] = '4';
$handler->display->display_options['style_options']['views_slideshow_cycle']['wait_for_image_load'] = 0;
$handler->display->display_options['style_options']['views_slideshow_cycle']['wait_for_image_load_timeout'] = '3000';
$handler->display->display_options['style_options']['views_slideshow_cycle']['cleartype'] = 0;
$handler->display->display_options['style_options']['views_slideshow_cycle']['cleartypenobg'] = 0;
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['relationships'] = FALSE;
/* Relationship: Nodequeue: Queue */
$handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
$handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
$handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
$handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
$handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
$handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
  'resources_innovator_spotlights' => 'resources_innovator_spotlights',
  'customers_page' => 0,
  'customer_slideshow' => 0,
  'customer_vignette_slideshow' => 0,
  'customers_page_ctas' => 0,
  'webcast_cta' => 0,
  'product_feature_slideshow' => 0,
  'edge_developer_services' => 0,
  'edge_analytics_services' => 0,
  'edge_api_services' => 0,
  '0_team_leadership_team' => 0,
  '1_team_board_of_directors' => 0,
  '2_team_advisory_board' => 0,
  'partner_logos' => 0,
  'partners_vignette_slideshow' => 0,
  'about_apigee_investors' => 0,
  'about_apigee_page_ctas' => 0,
  'customer_front_block' => 0,
  'upcoming_events_page_ctas' => 0,
  'best_practices_ctas' => 0,
  'city_tour_ctas' => 0,
  'homepage_slider' => 0,
  'mini_ctas' => 0,
  'event_page_header' => 0,
  'customer_page_header' => 0,
  'why_page_header' => 0,
  'resources_slideshow' => 0,
  'datasheets' => 0,
  'resources' => 0,
  'resources_customer_stories' => 0,
  'resources_datasheets' => 0,
  'resources_institute_reports' => 0,
  'resources_videos' => 0,
  'resources_webcasts' => 0,
  'resources_articles' => 0,
  'resources_ebooks' => 0,
  'customer_page_top_stories' => 0,
  'webcast_page_header' => 0,
  'press_page' => 0,
  'resources_product_videos' => 0,
  'featured_blog_posts' => 0,
  'blog_ctas' => 0,
);
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Colorbox: Colorbox trigger */
$handler->display->display_options['fields']['colorbox']['id'] = 'colorbox';
$handler->display->display_options['fields']['colorbox']['table'] = 'colorbox';
$handler->display->display_options['fields']['colorbox']['field'] = 'colorbox';
$handler->display->display_options['fields']['colorbox']['label'] = '';
$handler->display->display_options['fields']['colorbox']['exclude'] = TRUE;
$handler->display->display_options['fields']['colorbox']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['colorbox']['hide_empty'] = TRUE;
$handler->display->display_options['fields']['colorbox']['trigger_field'] = 'field_video';
$handler->display->display_options['fields']['colorbox']['popup'] = '[field_video_2]';
$handler->display->display_options['fields']['colorbox']['gid'] = 0;
$handler->display->display_options['fields']['colorbox']['width'] = '640px';
$handler->display->display_options['fields']['colorbox']['height'] = '410px';
/* Field: Video Link */
$handler->display->display_options['fields']['field_video_1']['id'] = 'field_video_1';
$handler->display->display_options['fields']['field_video_1']['table'] = 'field_data_field_video';
$handler->display->display_options['fields']['field_video_1']['field'] = 'field_video';
$handler->display->display_options['fields']['field_video_1']['ui_name'] = 'Video Link';
$handler->display->display_options['fields']['field_video_1']['label'] = '';
$handler->display->display_options['fields']['field_video_1']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_video_1']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_video_1']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_video_1']['type'] = 'file_url_plain';
/* Field: Content: Text */
$handler->display->display_options['fields']['field_cv_text']['id'] = 'field_cv_text';
$handler->display->display_options['fields']['field_cv_text']['table'] = 'field_data_field_cv_text';
$handler->display->display_options['fields']['field_cv_text']['field'] = 'field_cv_text';
$handler->display->display_options['fields']['field_cv_text']['label'] = '';
$handler->display->display_options['fields']['field_cv_text']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_cv_text']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_cv_text']['settings'] = array(
  'linked_field' => array(
    'linked' => 0,
    'destination' => '',
    'advanced' => array(
      'title' => '',
      'target' => '',
      'class' => '',
      'rel' => '',
      'text' => '',
    ),
  ),
);
/* Field: Video Thumbnail */
$handler->display->display_options['fields']['field_video']['id'] = 'field_video';
$handler->display->display_options['fields']['field_video']['table'] = 'field_data_field_video';
$handler->display->display_options['fields']['field_video']['field'] = 'field_video';
$handler->display->display_options['fields']['field_video']['ui_name'] = 'Video Thumbnail';
$handler->display->display_options['fields']['field_video']['label'] = '';
$handler->display->display_options['fields']['field_video']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_video']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['field_video']['alter']['text'] = '[field_video]
<img src="/sites/all/themes/apigee_themes/apigee_bootstrap/images/video-controls.svg" />';
$handler->display->display_options['fields']['field_video']['alter']['path'] = '[field_video_1]';
$handler->display->display_options['fields']['field_video']['alter']['link_class'] = 'colorbox-inline';
$handler->display->display_options['fields']['field_video']['alter']['preserve_tags'] = '<img> <h2> <p>';
$handler->display->display_options['fields']['field_video']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_video']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_video']['hide_empty'] = TRUE;
$handler->display->display_options['fields']['field_video']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_video']['type'] = 'file_rendered';
$handler->display->display_options['fields']['field_video']['settings'] = array(
  'file_view_mode' => 'slider_thumbnail',
  'linked_field' => array(
    'linked' => 0,
    'destination' => '',
    'advanced' => array(
      'title' => '',
      'target' => '',
      'class' => '',
      'rel' => '',
      'text' => '',
    ),
  ),
);
/* Field: Video Player */
$handler->display->display_options['fields']['field_video_2']['id'] = 'field_video_2';
$handler->display->display_options['fields']['field_video_2']['table'] = 'field_data_field_video';
$handler->display->display_options['fields']['field_video_2']['field'] = 'field_video';
$handler->display->display_options['fields']['field_video_2']['ui_name'] = 'Video Player';
$handler->display->display_options['fields']['field_video_2']['label'] = '';
$handler->display->display_options['fields']['field_video_2']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_video_2']['hide_empty'] = TRUE;
$handler->display->display_options['fields']['field_video_2']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_video_2']['type'] = 'file_rendered';
$handler->display->display_options['fields']['field_video_2']['settings'] = array(
  'file_view_mode' => 'live_thumbnail',
  'linked_field' => array(
    'linked' => 0,
    'destination' => '',
    'advanced' => array(
      'title' => '',
      'target' => '',
      'class' => '',
      'rel' => '',
      'text' => '',
    ),
  ),
);
/* Field: Content: Primary Topic */
$handler->display->display_options['fields']['field_primary_topic']['id'] = 'field_primary_topic';
$handler->display->display_options['fields']['field_primary_topic']['table'] = 'field_data_field_primary_topic';
$handler->display->display_options['fields']['field_primary_topic']['field'] = 'field_primary_topic';
$handler->display->display_options['fields']['field_primary_topic']['label'] = '';
$handler->display->display_options['fields']['field_primary_topic']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_primary_topic']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_primary_topic']['settings'] = array(
  'link' => 0,
  'linked_field' => array(
    'linked' => 0,
    'destination' => '',
    'advanced' => array(
      'title' => '',
      'target' => '',
      'class' => '',
      'rel' => '',
      'text' => '',
    ),
  ),
);
/* Field: Content: Topic */
$handler->display->display_options['fields']['field_topic']['id'] = 'field_topic';
$handler->display->display_options['fields']['field_topic']['table'] = 'field_data_field_topic';
$handler->display->display_options['fields']['field_topic']['field'] = 'field_topic';
$handler->display->display_options['fields']['field_topic']['label'] = '';
$handler->display->display_options['fields']['field_topic']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_topic']['alter']['text'] = '[field_topic-target_id]';
$handler->display->display_options['fields']['field_topic']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_topic']['settings'] = array(
  'link' => 0,
  'linked_field' => array(
    'linked' => 0,
    'destination' => '',
    'advanced' => array(
      'title' => '',
      'target' => '',
      'class' => '',
      'rel' => '',
      'text' => '',
    ),
  ),
);
$handler->display->display_options['fields']['field_topic']['delta_offset'] = '0';
/* Field: Field: Subtitle */
$handler->display->display_options['fields']['field_subtitle']['id'] = 'field_subtitle';
$handler->display->display_options['fields']['field_subtitle']['table'] = 'field_data_field_subtitle';
$handler->display->display_options['fields']['field_subtitle']['field'] = 'field_subtitle';
$handler->display->display_options['fields']['field_subtitle']['label'] = '';
$handler->display->display_options['fields']['field_subtitle']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_subtitle']['alter']['text'] = '<p>';
$handler->display->display_options['fields']['field_subtitle']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_subtitle']['element_wrapper_type'] = 'p';
$handler->display->display_options['fields']['field_subtitle']['element_wrapper_class'] = 'cv_subtitle';
$handler->display->display_options['fields']['field_subtitle']['hide_empty'] = TRUE;
$handler->display->display_options['fields']['field_subtitle']['settings'] = array(
  'linked_field' => array(
    'linked' => 0,
    'destination' => '',
    'advanced' => array(
      'title' => '',
      'target' => '',
      'class' => '',
      'rel' => '',
      'text' => '',
    ),
  ),
);
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'resource_archetype' => 'resource_archetype',
);
/* Filter criterion: Content: Video (field_video:fid) */
$handler->display->display_options['filters']['field_video_fid']['id'] = 'field_video_fid';
$handler->display->display_options['filters']['field_video_fid']['table'] = 'field_data_field_video';
$handler->display->display_options['filters']['field_video_fid']['field'] = 'field_video_fid';
$handler->display->display_options['filters']['field_video_fid']['operator'] = 'not empty';

/* Display: Featured Video */
$handler = $view->new_display('block', 'Featured Video', 'featured_video');
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '1';
$handler->display->display_options['pager']['options']['offset'] = '9';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['style_options']['row_class'] = 'customers_left';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['inline'] = array(
  'field_customer_logo' => 'field_customer_logo',
  'field_cs_image' => 'field_cs_image',
);
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['relationships'] = FALSE;
/* Relationship: Nodequeue: Queue */
$handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
$handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
$handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
$handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
$handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
$handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
  'resources_customer_stories' => 'resources_customer_stories',
  'customers_page' => 0,
  'customer_slideshow' => 0,
  'customer_vignette_slideshow' => 0,
  'customers_page_ctas' => 0,
  'webcast_cta' => 0,
  'product_feature_slideshow' => 0,
  'edge_developer_services' => 0,
  'edge_analytics_services' => 0,
  'edge_api_services' => 0,
  '0_team_leadership_team' => 0,
  '1_team_board_of_directors' => 0,
  '2_team_advisory_board' => 0,
  'partner_logos' => 0,
  'partners_vignette_slideshow' => 0,
  'about_apigee_investors' => 0,
  'about_apigee_page_ctas' => 0,
  'customer_front_block' => 0,
  'upcoming_events_page_ctas' => 0,
  'best_practices_ctas' => 0,
  'city_tour_ctas' => 0,
  'homepage_slider' => 0,
  'mini_ctas' => 0,
  'event_page_header' => 0,
  'customer_page_header' => 0,
  'why_page_header' => 0,
  'resources_slideshow' => 0,
  'datasheets' => 0,
  'resources' => 0,
  'resources_datasheets' => 0,
  'resources_institute_reports' => 0,
  'resources_videos' => 0,
  'resources_webcasts' => 0,
  'resources_articles' => 0,
  'resources_ebooks' => 0,
  'customer_page_top_stories' => 0,
  'webcast_page_header' => 0,
  'resources_innovator_spotlights' => 0,
  'press_page' => 0,
  'resources_product_videos' => 0,
  'featured_blog_posts' => 0,
  'blog_ctas' => 0,
);
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Logo */
$handler->display->display_options['fields']['field_customer_logo']['id'] = 'field_customer_logo';
$handler->display->display_options['fields']['field_customer_logo']['table'] = 'field_data_field_customer_logo';
$handler->display->display_options['fields']['field_customer_logo']['field'] = 'field_customer_logo';
$handler->display->display_options['fields']['field_customer_logo']['label'] = '';
$handler->display->display_options['fields']['field_customer_logo']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_customer_logo']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_customer_logo']['settings'] = array(
  'image_style' => '',
  'image_link' => '',
  'linked_field' => array(
    'linked' => 0,
    'destination' => '',
    'advanced' => array(
      'title' => '',
      'target' => '',
      'class' => '',
      'rel' => '',
      'text' => '',
    ),
  ),
);
/* Field: Content: Image */
$handler->display->display_options['fields']['field_cs_image']['id'] = 'field_cs_image';
$handler->display->display_options['fields']['field_cs_image']['table'] = 'field_data_field_cs_image';
$handler->display->display_options['fields']['field_cs_image']['field'] = 'field_cs_image';
$handler->display->display_options['fields']['field_cs_image']['label'] = '';
$handler->display->display_options['fields']['field_cs_image']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_cs_image']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_cs_image']['settings'] = array(
  'image_style' => '',
  'image_link' => '',
  'linked_field' => array(
    'linked' => 1,
    'destination' => '',
    'advanced' => array(
      'title' => '',
      'target' => '',
      'class' => '',
      'rel' => '',
      'text' => '',
    ),
  ),
);
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
/* Field: Content: Summary */
$handler->display->display_options['fields']['field_summary']['id'] = 'field_summary';
$handler->display->display_options['fields']['field_summary']['table'] = 'field_data_field_summary';
$handler->display->display_options['fields']['field_summary']['field'] = 'field_summary';
$handler->display->display_options['fields']['field_summary']['label'] = '';
$handler->display->display_options['fields']['field_summary']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_summary']['settings'] = array(
  'linked_field' => array(
    'linked' => 0,
    'destination' => '',
    'advanced' => array(
      'title' => '',
      'target' => '',
      'class' => '',
      'rel' => '',
      'text' => '',
    ),
  ),
);
/* Field: Content: Video */
$handler->display->display_options['fields']['field_video']['id'] = 'field_video';
$handler->display->display_options['fields']['field_video']['table'] = 'field_data_field_video';
$handler->display->display_options['fields']['field_video']['field'] = 'field_video';
$handler->display->display_options['fields']['field_video']['label'] = '';
$handler->display->display_options['fields']['field_video']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_video']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_video']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_video']['settings'] = array(
  'linked_field' => array(
    'linked' => 0,
    'destination' => '',
    'advanced' => array(
      'title' => '',
      'target' => '',
      'class' => '',
      'rel' => '',
      'text' => '',
    ),
  ),
);
$handler->display->display_options['fields']['field_video']['delta_offset'] = '0';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'customer_story' => 'customer_story',
);
$translatables['customers_video_slideshow'] = array(
  t('Master'),
  t('more'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('queue'),
  t('[field_video]
<img src="/sites/all/themes/apigee_themes/apigee_bootstrap/images/video-controls.svg" />'),
  t('[field_topic-target_id]'),
  t('<p>'),
  t('<p>[field_cv_text]</p>
[field_subtitle]'),
  t('Block'),
  t('Front Page Videos'),
  t('Featured Video'),
);