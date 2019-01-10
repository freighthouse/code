<?php

$view = new view();
$view->name = 'migrations';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'Migrations';
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
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '150';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '9';
$handler->display->display_options['style_plugin'] = 'views_json';
$handler->display->display_options['style_options']['plaintext_output'] = 0;
$handler->display->display_options['style_options']['remove_newlines'] = 0;
$handler->display->display_options['style_options']['jsonp_prefix'] = '';
$handler->display->display_options['style_options']['using_views_api_mode'] = 0;
$handler->display->display_options['style_options']['object_arrays'] = 0;
$handler->display->display_options['style_options']['numeric_strings'] = 0;
$handler->display->display_options['style_options']['bigint_string'] = 0;
$handler->display->display_options['style_options']['pretty_print'] = 0;
$handler->display->display_options['style_options']['unescaped_slashes'] = 0;
$handler->display->display_options['style_options']['unescaped_unicode'] = 0;
$handler->display->display_options['style_options']['char_encoding'] = array();
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Content: Body */
$handler->display->display_options['fields']['body']['id'] = 'body';
$handler->display->display_options['fields']['body']['table'] = 'field_data_body';
$handler->display->display_options['fields']['body']['field'] = 'body';
$handler->display->display_options['fields']['body']['label'] = '';
$handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
/* Field: Content: Post date */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'node';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['label'] = '';
$handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['created']['date_format'] = 'short';
$handler->display->display_options['fields']['created']['second_date_format'] = 'html5_tools_iso8601';
/* Field: Content: Published */
$handler->display->display_options['fields']['status']['id'] = 'status';
$handler->display->display_options['fields']['status']['table'] = 'node';
$handler->display->display_options['fields']['status']['field'] = 'status';
/* Field: Content: Nid */
$handler->display->display_options['fields']['nid']['id'] = 'nid';
$handler->display->display_options['fields']['nid']['table'] = 'node';
$handler->display->display_options['fields']['nid']['field'] = 'nid';
$handler->display->display_options['fields']['nid']['label'] = '';
$handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
/* Sort criterion: Content: Post date */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'node';
$handler->display->display_options['sorts']['created']['field'] = 'created';
$handler->display->display_options['sorts']['created']['order'] = 'DESC';
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
    'page' => 'page',
);

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page_1');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Page';
$handler->display->display_options['path'] = 'migration/page';

/* Display: News */
$handler = $view->new_display('page', 'News', 'page_2');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'News';
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '0';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '9';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Content: Body */
$handler->display->display_options['fields']['body']['id'] = 'body';
$handler->display->display_options['fields']['body']['table'] = 'field_data_body';
$handler->display->display_options['fields']['body']['field'] = 'body';
$handler->display->display_options['fields']['body']['label'] = '';
$handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
/* Field: Content: Post date */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'node';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['label'] = '';
$handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['created']['date_format'] = 'short';
$handler->display->display_options['fields']['created']['second_date_format'] = 'html5_tools_iso8601';
/* Field: Content: Published */
$handler->display->display_options['fields']['status']['id'] = 'status';
$handler->display->display_options['fields']['status']['table'] = 'node';
$handler->display->display_options['fields']['status']['field'] = 'status';
/* Field: Content: Nid */
$handler->display->display_options['fields']['nid']['id'] = 'nid';
$handler->display->display_options['fields']['nid']['table'] = 'node';
$handler->display->display_options['fields']['nid']['field'] = 'nid';
$handler->display->display_options['fields']['nid']['label'] = '';
$handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
/* Field: Content: Audio */
$handler->display->display_options['fields']['field_news_audio']['id'] = 'field_news_audio';
$handler->display->display_options['fields']['field_news_audio']['table'] = 'field_data_field_news_audio';
$handler->display->display_options['fields']['field_news_audio']['field'] = 'field_news_audio';
$handler->display->display_options['fields']['field_news_audio']['label'] = '';
$handler->display->display_options['fields']['field_news_audio']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_news_audio']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_news_audio']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_news_audio']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_news_audio']['type'] = 'file_url_plain';
$handler->display->display_options['fields']['field_news_audio']['field_api_classes'] = TRUE;
/* Field: Content: Featured Image */
$handler->display->display_options['fields']['field_news_featured_image']['id'] = 'field_news_featured_image';
$handler->display->display_options['fields']['field_news_featured_image']['table'] = 'field_data_field_news_featured_image';
$handler->display->display_options['fields']['field_news_featured_image']['field'] = 'field_news_featured_image';
$handler->display->display_options['fields']['field_news_featured_image']['label'] = '';
$handler->display->display_options['fields']['field_news_featured_image']['element_type'] = '0';
$handler->display->display_options['fields']['field_news_featured_image']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_news_featured_image']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_news_featured_image']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_news_featured_image']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_news_featured_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
);
$handler->display->display_options['fields']['field_news_featured_image']['field_api_classes'] = TRUE;
/* Field: Content: Media Embed Code (legacy) */
$handler->display->display_options['fields']['field_news_mediaembed']['id'] = 'field_news_mediaembed';
$handler->display->display_options['fields']['field_news_mediaembed']['table'] = 'field_data_field_news_mediaembed';
$handler->display->display_options['fields']['field_news_mediaembed']['field'] = 'field_news_mediaembed';
$handler->display->display_options['fields']['field_news_mediaembed']['label'] = '';
$handler->display->display_options['fields']['field_news_mediaembed']['element_type'] = '0';
$handler->display->display_options['fields']['field_news_mediaembed']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_news_mediaembed']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_news_mediaembed']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_news_mediaembed']['type'] = 'text_plain';
$handler->display->display_options['fields']['field_news_mediaembed']['field_api_classes'] = TRUE;
/* Field: Content: Related Issue(s) */
$handler->display->display_options['fields']['field_news_issue']['id'] = 'field_news_issue';
$handler->display->display_options['fields']['field_news_issue']['table'] = 'field_data_field_news_issue';
$handler->display->display_options['fields']['field_news_issue']['field'] = 'field_news_issue';
$handler->display->display_options['fields']['field_news_issue']['label'] = '';
$handler->display->display_options['fields']['field_news_issue']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_news_issue']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_news_issue']['type'] = 'node_reference_plain';
$handler->display->display_options['fields']['field_news_issue']['delta_offset'] = '0';
/* Field: Content: Thumbnail */
$handler->display->display_options['fields']['field_news_photo']['id'] = 'field_news_photo';
$handler->display->display_options['fields']['field_news_photo']['table'] = 'field_data_field_news_photo';
$handler->display->display_options['fields']['field_news_photo']['field'] = 'field_news_photo';
$handler->display->display_options['fields']['field_news_photo']['label'] = '';
$handler->display->display_options['fields']['field_news_photo']['element_type'] = '0';
$handler->display->display_options['fields']['field_news_photo']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_news_photo']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_news_photo']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_news_photo']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_news_photo']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
);
$handler->display->display_options['fields']['field_news_photo']['field_api_classes'] = TRUE;
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
    'news' => 'news',
);
$handler->display->display_options['path'] = 'migration/news';

/* Display: Media */
$handler = $view->new_display('page', 'Media', 'page_3');
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '0';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '9';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Content: Body */
$handler->display->display_options['fields']['body']['id'] = 'body';
$handler->display->display_options['fields']['body']['table'] = 'field_data_body';
$handler->display->display_options['fields']['body']['field'] = 'body';
$handler->display->display_options['fields']['body']['label'] = '';
$handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
/* Field: Content: Post date */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'node';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['label'] = '';
$handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['created']['date_format'] = 'short';
$handler->display->display_options['fields']['created']['second_date_format'] = 'html5_tools_iso8601';
/* Field: Content: Published */
$handler->display->display_options['fields']['status']['id'] = 'status';
$handler->display->display_options['fields']['status']['table'] = 'node';
$handler->display->display_options['fields']['status']['field'] = 'status';
/* Field: Content: Nid */
$handler->display->display_options['fields']['nid']['id'] = 'nid';
$handler->display->display_options['fields']['nid']['table'] = 'node';
$handler->display->display_options['fields']['nid']['field'] = 'nid';
$handler->display->display_options['fields']['nid']['label'] = '';
$handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
/* Field: Content: Date */
$handler->display->display_options['fields']['field_mediaarticle_date']['id'] = 'field_mediaarticle_date';
$handler->display->display_options['fields']['field_mediaarticle_date']['table'] = 'field_data_field_mediaarticle_date';
$handler->display->display_options['fields']['field_mediaarticle_date']['field'] = 'field_mediaarticle_date';
$handler->display->display_options['fields']['field_mediaarticle_date']['label'] = '';
$handler->display->display_options['fields']['field_mediaarticle_date']['alter']['strip_tags'] = TRUE;
$handler->display->display_options['fields']['field_mediaarticle_date']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_mediaarticle_date']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_mediaarticle_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
);
/* Field: Content: Headline */
$handler->display->display_options['fields']['field_mediaarticle_headline']['id'] = 'field_mediaarticle_headline';
$handler->display->display_options['fields']['field_mediaarticle_headline']['table'] = 'field_data_field_mediaarticle_headline';
$handler->display->display_options['fields']['field_mediaarticle_headline']['field'] = 'field_mediaarticle_headline';
$handler->display->display_options['fields']['field_mediaarticle_headline']['label'] = '';
$handler->display->display_options['fields']['field_mediaarticle_headline']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_mediaarticle_headline']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_mediaarticle_headline']['type'] = 'text_plain';
/* Field: Content: Labs */
$handler->display->display_options['fields']['field_mediaarticle_labs']['id'] = 'field_mediaarticle_labs';
$handler->display->display_options['fields']['field_mediaarticle_labs']['table'] = 'field_data_field_mediaarticle_labs';
$handler->display->display_options['fields']['field_mediaarticle_labs']['field'] = 'field_mediaarticle_labs';
$handler->display->display_options['fields']['field_mediaarticle_labs']['label'] = '';
$handler->display->display_options['fields']['field_mediaarticle_labs']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_mediaarticle_labs']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_mediaarticle_labs']['delta_offset'] = '0';
/* Field: Content: Link */
$handler->display->display_options['fields']['field_mediaarticle_link']['id'] = 'field_mediaarticle_link';
$handler->display->display_options['fields']['field_mediaarticle_link']['table'] = 'field_data_field_mediaarticle_link';
$handler->display->display_options['fields']['field_mediaarticle_link']['field'] = 'field_mediaarticle_link';
$handler->display->display_options['fields']['field_mediaarticle_link']['label'] = '';
$handler->display->display_options['fields']['field_mediaarticle_link']['element_type'] = '0';
$handler->display->display_options['fields']['field_mediaarticle_link']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_mediaarticle_link']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_mediaarticle_link']['click_sort_column'] = 'url';
$handler->display->display_options['fields']['field_mediaarticle_link']['type'] = 'link_plain';
/* Field: Broken/missing handler */
$handler->display->display_options['fields']['field_mediaarticle_logo']['id'] = 'field_mediaarticle_logo';
$handler->display->display_options['fields']['field_mediaarticle_logo']['table'] = 'field_data_field_mediaarticle_logo';
$handler->display->display_options['fields']['field_mediaarticle_logo']['field'] = 'field_mediaarticle_logo';
$handler->display->display_options['fields']['field_mediaarticle_logo']['label'] = '';
$handler->display->display_options['fields']['field_mediaarticle_logo']['element_type'] = '0';
$handler->display->display_options['fields']['field_mediaarticle_logo']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_mediaarticle_logo']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_mediaarticle_logo']['element_default_classes'] = FALSE;
/* Field: Content: Publisher */
$handler->display->display_options['fields']['field_mediaarticle_publisher']['id'] = 'field_mediaarticle_publisher';
$handler->display->display_options['fields']['field_mediaarticle_publisher']['table'] = 'field_data_field_mediaarticle_publisher';
$handler->display->display_options['fields']['field_mediaarticle_publisher']['field'] = 'field_mediaarticle_publisher';
$handler->display->display_options['fields']['field_mediaarticle_publisher']['label'] = '';
$handler->display->display_options['fields']['field_mediaarticle_publisher']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_mediaarticle_publisher']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_mediaarticle_publisher']['type'] = 'text_plain';
/* Field: Content: Related Issue */
$handler->display->display_options['fields']['field_mediaarticle_issue']['id'] = 'field_mediaarticle_issue';
$handler->display->display_options['fields']['field_mediaarticle_issue']['table'] = 'field_data_field_mediaarticle_issue';
$handler->display->display_options['fields']['field_mediaarticle_issue']['field'] = 'field_mediaarticle_issue';
$handler->display->display_options['fields']['field_mediaarticle_issue']['label'] = '';
$handler->display->display_options['fields']['field_mediaarticle_issue']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_mediaarticle_issue']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_mediaarticle_issue']['type'] = 'node_reference_plain';
$handler->display->display_options['fields']['field_mediaarticle_issue']['delta_offset'] = '0';
/* Field: Content: Link */
$handler->display->display_options['fields']['field_mediaarticle_link_1']['id'] = 'field_mediaarticle_link_1';
$handler->display->display_options['fields']['field_mediaarticle_link_1']['table'] = 'field_data_field_mediaarticle_link';
$handler->display->display_options['fields']['field_mediaarticle_link_1']['field'] = 'field_mediaarticle_link';
$handler->display->display_options['fields']['field_mediaarticle_link_1']['label'] = '';
$handler->display->display_options['fields']['field_mediaarticle_link_1']['alter']['strip_tags'] = TRUE;
$handler->display->display_options['fields']['field_mediaarticle_link_1']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_mediaarticle_link_1']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_mediaarticle_link_1']['click_sort_column'] = 'url';
$handler->display->display_options['fields']['field_mediaarticle_link_1']['type'] = 'link_title_plain';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
    'media_article' => 'media_article',
);
$handler->display->display_options['path'] = 'migration/media';
$translatables['migrations'] = array(
    t('Master'),
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
    t('Published'),
    t('Page'),
    t('News'),
    t('Media'),
);