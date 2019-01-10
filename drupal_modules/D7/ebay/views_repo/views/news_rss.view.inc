<?php

$view = new view();
$view->name = 'news_rss';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'News RSS';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'eBay Mainstreet RSS Feed';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'time';
$handler->display->display_options['cache']['results_lifespan'] = '3600';
$handler->display->display_options['cache']['results_lifespan_custom'] = '0';
$handler->display->display_options['cache']['output_lifespan'] = '3600';
$handler->display->display_options['cache']['output_lifespan_custom'] = '0';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['style_plugin'] = 'views_xml_style';
$handler->display->display_options['style_options']['plaintext_output'] = 1;
$handler->display->display_options['style_options']['header'] = '';
$handler->display->display_options['style_options']['author'] = 'ebaymainstreet';
$handler->display->display_options['style_options']['using_views_api_mode'] = 0;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Content: Summary */
$handler->display->display_options['fields']['field_news_summary']['id'] = 'field_news_summary';
$handler->display->display_options['fields']['field_news_summary']['table'] = 'field_data_field_news_summary';
$handler->display->display_options['fields']['field_news_summary']['field'] = 'field_news_summary';
$handler->display->display_options['fields']['field_news_summary']['label'] = '';
$handler->display->display_options['fields']['field_news_summary']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_news_summary']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_news_summary']['type'] = 'text_plain';
/* Field: Content: Featured Image */
$handler->display->display_options['fields']['field_news_featured_image']['id'] = 'field_news_featured_image';
$handler->display->display_options['fields']['field_news_featured_image']['table'] = 'field_data_field_news_featured_image';
$handler->display->display_options['fields']['field_news_featured_image']['field'] = 'field_news_featured_image';
$handler->display->display_options['fields']['field_news_featured_image']['label'] = '';
$handler->display->display_options['fields']['field_news_featured_image']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_news_featured_image']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_news_featured_image']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_news_featured_image']['settings'] = array(
    'image_style' => '',
    'image_link' => 'file',
);
/* Field: Content: Related Issue(s) */
$handler->display->display_options['fields']['field_news_issue']['id'] = 'field_news_issue';
$handler->display->display_options['fields']['field_news_issue']['table'] = 'field_data_field_news_issue';
$handler->display->display_options['fields']['field_news_issue']['field'] = 'field_news_issue';
$handler->display->display_options['fields']['field_news_issue']['label'] = '';
$handler->display->display_options['fields']['field_news_issue']['element_type'] = '0';
$handler->display->display_options['fields']['field_news_issue']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_news_issue']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_news_issue']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_news_issue']['type'] = 'node_reference_plain';
$handler->display->display_options['fields']['field_news_issue']['delta_offset'] = '0';
$handler->display->display_options['fields']['field_news_issue']['field_api_classes'] = TRUE;
/* Field: Content: Path */
$handler->display->display_options['fields']['path']['id'] = 'path';
$handler->display->display_options['fields']['path']['table'] = 'node';
$handler->display->display_options['fields']['path']['field'] = 'path';
$handler->display->display_options['fields']['path']['label'] = '';
$handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['path']['element_default_classes'] = FALSE;
/* Field: Content: Post date */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'node';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['label'] = '';
$handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['created']['date_format'] = 'custom';
$handler->display->display_options['fields']['created']['custom_date_format'] = 'F j, Y';
$handler->display->display_options['fields']['created']['second_date_format'] = 'html5_tools_iso8601';
/* Field: Content: Author uid */
$handler->display->display_options['fields']['uid']['id'] = 'uid';
$handler->display->display_options['fields']['uid']['table'] = 'node';
$handler->display->display_options['fields']['uid']['field'] = 'uid';
$handler->display->display_options['fields']['uid']['label'] = '';
$handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
/* Field: Content: Nid */
$handler->display->display_options['fields']['nid']['id'] = 'nid';
$handler->display->display_options['fields']['nid']['table'] = 'node';
$handler->display->display_options['fields']['nid']['field'] = 'nid';
$handler->display->display_options['fields']['nid']['label'] = '';
$handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
/* Field: Global: Custom text */
$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
$handler->display->display_options['fields']['nothing']['table'] = 'views';
$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing']['label'] = '';
$handler->display->display_options['fields']['nothing']['alter']['text'] = 'eBay Main Street';
$handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
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
$handler->display->display_options['filters']['status']['group'] = 0;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
    'news' => 'news',
);
$handler->display->display_options['filters']['type']['group'] = '0';

/* Display: Feed */
$handler = $view->new_display('feed', 'Feed', 'feed');
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['style_plugin'] = 'rss';
$handler->display->display_options['style_options']['uses_fields'] = TRUE;
$handler->display->display_options['style_options']['description'] = 'eBay Main Street News';
$handler->display->display_options['row_plugin'] = 'rss_fields';
$handler->display->display_options['row_options']['title_field'] = 'title';
$handler->display->display_options['row_options']['link_field'] = 'path';
$handler->display->display_options['row_options']['description_field'] = 'field_news_summary';
$handler->display->display_options['row_options']['creator_field'] = 'nothing';
$handler->display->display_options['row_options']['date_field'] = 'created';
$handler->display->display_options['row_options']['guid_field_options'] = array(
    'guid_field' => 'nid',
    'guid_field_is_permalink' => 0,
);
$handler->display->display_options['path'] = 'news-rss.xml';
$handler->display->display_options['displays'] = array(
    'default' => 'default',
    'page' => 'page',
);
$handler->display->display_options['sitename_title'] = 0;

/* Display: XML Feed */
$handler = $view->new_display('page', 'XML Feed', 'page_1');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = '<none>';
$handler->display->display_options['defaults']['cache'] = FALSE;
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'views_xml_style';
$handler->display->display_options['style_options']['plaintext_output'] = 1;
$handler->display->display_options['style_options']['header'] = '';
$handler->display->display_options['style_options']['author'] = 'ebaymainstreet';
$handler->display->display_options['style_options']['using_views_api_mode'] = 0;
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['defaults']['row_options'] = FALSE;
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
/* Field: Content: Summary */
$handler->display->display_options['fields']['field_news_summary']['id'] = 'field_news_summary';
$handler->display->display_options['fields']['field_news_summary']['table'] = 'field_data_field_news_summary';
$handler->display->display_options['fields']['field_news_summary']['field'] = 'field_news_summary';
$handler->display->display_options['fields']['field_news_summary']['label'] = '';
$handler->display->display_options['fields']['field_news_summary']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_news_summary']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_news_summary']['type'] = 'text_plain';
/* Field: Content: Featured Image */
$handler->display->display_options['fields']['field_news_featured_image']['id'] = 'field_news_featured_image';
$handler->display->display_options['fields']['field_news_featured_image']['table'] = 'field_data_field_news_featured_image';
$handler->display->display_options['fields']['field_news_featured_image']['field'] = 'field_news_featured_image';
$handler->display->display_options['fields']['field_news_featured_image']['label'] = '';
$handler->display->display_options['fields']['field_news_featured_image']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_news_featured_image']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_news_featured_image']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_news_featured_image']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_news_featured_image']['settings'] = array(
    'image_style' => '',
    'image_link' => 'file',
);
/* Field: Content: Thumbnail */
$handler->display->display_options['fields']['field_news_photo']['id'] = 'field_news_photo';
$handler->display->display_options['fields']['field_news_photo']['table'] = 'field_data_field_news_photo';
$handler->display->display_options['fields']['field_news_photo']['field'] = 'field_news_photo';
$handler->display->display_options['fields']['field_news_photo']['label'] = '';
$handler->display->display_options['fields']['field_news_photo']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_news_photo']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_news_photo']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_news_photo']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_news_photo']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
);
/* Field: Content: Related Issue(s) */
$handler->display->display_options['fields']['field_news_issue']['id'] = 'field_news_issue';
$handler->display->display_options['fields']['field_news_issue']['table'] = 'field_data_field_news_issue';
$handler->display->display_options['fields']['field_news_issue']['field'] = 'field_news_issue';
$handler->display->display_options['fields']['field_news_issue']['label'] = '';
$handler->display->display_options['fields']['field_news_issue']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_news_issue']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_news_issue']['type'] = 'node_reference_plain';
$handler->display->display_options['fields']['field_news_issue']['delta_offset'] = '0';
/* Field: Content: Path */
$handler->display->display_options['fields']['path']['id'] = 'path';
$handler->display->display_options['fields']['path']['table'] = 'node';
$handler->display->display_options['fields']['path']['field'] = 'path';
$handler->display->display_options['fields']['path']['label'] = '';
$handler->display->display_options['fields']['path']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['path']['alter']['text'] = 'https://www.ebaymainstreet.com[path]';
$handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['path']['element_default_classes'] = FALSE;
/* Field: Content: Post date */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'node';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['label'] = '';
$handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['created']['date_format'] = 'custom';
$handler->display->display_options['fields']['created']['custom_date_format'] = 'F j, Y';
$handler->display->display_options['fields']['created']['second_date_format'] = 'html5_tools_iso8601';
/* Field: Global: Custom text */
$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
$handler->display->display_options['fields']['nothing']['table'] = 'views';
$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing']['label'] = 'image';
$handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_news_featured_image]';
/* Field: Global: Custom text */
$handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
$handler->display->display_options['fields']['nothing_1']['table'] = 'views';
$handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing_1']['label'] = 'thumbnail';
$handler->display->display_options['fields']['nothing_1']['alter']['text'] = '[field_news_photo]';
$handler->display->display_options['path'] = 'news-feed.xml';
$translatables['news_rss'] = array(
    t('Master'),
    t('eBay Mainstreet RSS Feed'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('eBay Main Street'),
    t('Feed'),
    t('XML Feed'),
    t('<none>'),
    t('https://www.ebaymainstreet.com[path]'),
    t('image'),
    t('[field_news_featured_image]'),
    t('thumbnail'),
    t('[field_news_photo]'),
);