<?php

$view = new view();
$view->name = 'dans_les_media';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'DANS LES MEDIA';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'DANS LES MÉDIAS';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '6';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['row_plugin'] = 'fields';
/* Field: Content: Publication */
$handler->display->display_options['fields']['field_media_city']['id'] = 'field_media_city';
$handler->display->display_options['fields']['field_media_city']['table'] = 'field_data_field_media_city';
$handler->display->display_options['fields']['field_media_city']['field'] = 'field_media_city';
$handler->display->display_options['fields']['field_media_city']['label'] = '';
$handler->display->display_options['fields']['field_media_city']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['field_media_city']['element_label_colon'] = FALSE;
/* Field: Content: Date */
$handler->display->display_options['fields']['field_news_date']['id'] = 'field_news_date';
$handler->display->display_options['fields']['field_news_date']['table'] = 'field_data_field_news_date';
$handler->display->display_options['fields']['field_news_date']['field'] = 'field_news_date';
$handler->display->display_options['fields']['field_news_date']['label'] = '';
$handler->display->display_options['fields']['field_news_date']['element_type'] = 'p';
$handler->display->display_options['fields']['field_news_date']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_news_date']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_news_date']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_news_date']['settings'] = array(
'format_type' => 'french',
'fromto' => 'both',
'multiple_number' => '',
'multiple_from' => '',
'multiple_to' => '',
'show_remaining_days' => 0,
'show_repeat_rule' => 'show',
);
$handler->display->display_options['fields']['field_news_date']['field_api_classes'] = TRUE;
/* Field: Content: Link */
$handler->display->display_options['fields']['field_microsite_news_link_1']['id'] = 'field_microsite_news_link_1';
$handler->display->display_options['fields']['field_microsite_news_link_1']['table'] = 'field_data_field_microsite_news_link';
$handler->display->display_options['fields']['field_microsite_news_link_1']['field'] = 'field_microsite_news_link';
$handler->display->display_options['fields']['field_microsite_news_link_1']['label'] = '';
$handler->display->display_options['fields']['field_microsite_news_link_1']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_microsite_news_link_1']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_microsite_news_link_1']['click_sort_column'] = 'url';
/* Field: Content: Image */
$handler->display->display_options['fields']['field_media_image']['id'] = 'field_media_image';
$handler->display->display_options['fields']['field_media_image']['table'] = 'field_data_field_media_image';
$handler->display->display_options['fields']['field_media_image']['field'] = 'field_media_image';
$handler->display->display_options['fields']['field_media_image']['label'] = '';
$handler->display->display_options['fields']['field_media_image']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['field_media_image']['alter']['path'] = '[field_microsite_news_link_1]';
$handler->display->display_options['fields']['field_media_image']['alter']['target'] = '_blank';
$handler->display->display_options['fields']['field_media_image']['element_type'] = '0';
$handler->display->display_options['fields']['field_media_image']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_media_image']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_media_image']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_media_image']['hide_empty'] = TRUE;
$handler->display->display_options['fields']['field_media_image']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_media_image']['settings'] = array(
'image_style' => 'microsite_testimonials',
'image_link' => '',
);
$handler->display->display_options['fields']['field_media_image']['field_api_classes'] = TRUE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['path'] = '[field_microsite_news_link_1]';
$handler->display->display_options['fields']['title']['alter']['target'] = '_blank';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_type'] = '0';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Content: Body */
$handler->display->display_options['fields']['body']['id'] = 'body';
$handler->display->display_options['fields']['body']['table'] = 'field_data_body';
$handler->display->display_options['fields']['body']['field'] = 'body';
$handler->display->display_options['fields']['body']['label'] = '';
$handler->display->display_options['fields']['body']['exclude'] = TRUE;
$handler->display->display_options['fields']['body']['element_type'] = 'p';
$handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['body']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['body']['type'] = 'text_trimmed';
$handler->display->display_options['fields']['body']['settings'] = array(
'trim_length' => '300',
);
$handler->display->display_options['fields']['body']['field_api_classes'] = TRUE;
/* Field: Content: Link */
$handler->display->display_options['fields']['field_microsite_news_link']['id'] = 'field_microsite_news_link';
$handler->display->display_options['fields']['field_microsite_news_link']['table'] = 'field_data_field_microsite_news_link';
$handler->display->display_options['fields']['field_microsite_news_link']['field'] = 'field_microsite_news_link';
$handler->display->display_options['fields']['field_microsite_news_link']['label'] = '';
$handler->display->display_options['fields']['field_microsite_news_link']['element_type'] = '0';
$handler->display->display_options['fields']['field_microsite_news_link']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_microsite_news_link']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_microsite_news_link']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_microsite_news_link']['click_sort_column'] = 'url';
$handler->display->display_options['fields']['field_microsite_news_link']['field_api_classes'] = TRUE;
/* Sort criterion: Content: Date (field_news_date) */
$handler->display->display_options['sorts']['field_news_date_value']['id'] = 'field_news_date_value';
$handler->display->display_options['sorts']['field_news_date_value']['table'] = 'field_data_field_news_date';
$handler->display->display_options['sorts']['field_news_date_value']['field'] = 'field_news_date_value';
$handler->display->display_options['sorts']['field_news_date_value']['order'] = 'DESC';
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
'microsite_news' => 'microsite_news',
);

/* Display: Block */
$handler = $view->new_display('block', 'Block', 'block');
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '3';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['footer'] = FALSE;
/* Footer: Global: Text area */
$handler->display->display_options['footer']['area']['id'] = 'area';
$handler->display->display_options['footer']['area']['table'] = 'views';
$handler->display->display_options['footer']['area']['field'] = 'area';
$handler->display->display_options['footer']['area']['content'] = '<a href="/fr/ebaysengage/en-savoir-plus/dans-les-medias">En savoir plus</a>';
$handler->display->display_options['footer']['area']['format'] = 'plain_html';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Publication */
$handler->display->display_options['fields']['field_media_city']['id'] = 'field_media_city';
$handler->display->display_options['fields']['field_media_city']['table'] = 'field_data_field_media_city';
$handler->display->display_options['fields']['field_media_city']['field'] = 'field_media_city';
$handler->display->display_options['fields']['field_media_city']['label'] = '';
$handler->display->display_options['fields']['field_media_city']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['field_media_city']['element_label_colon'] = FALSE;
/* Field: Content: Date */
$handler->display->display_options['fields']['field_news_date']['id'] = 'field_news_date';
$handler->display->display_options['fields']['field_news_date']['table'] = 'field_data_field_news_date';
$handler->display->display_options['fields']['field_news_date']['field'] = 'field_news_date';
$handler->display->display_options['fields']['field_news_date']['label'] = '';
$handler->display->display_options['fields']['field_news_date']['element_type'] = 'p';
$handler->display->display_options['fields']['field_news_date']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_news_date']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_news_date']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_news_date']['settings'] = array(
'format_type' => 'french',
'fromto' => 'both',
'multiple_number' => '',
'multiple_from' => '',
'multiple_to' => '',
'show_remaining_days' => 0,
'show_repeat_rule' => 'show',
);
$handler->display->display_options['fields']['field_news_date']['field_api_classes'] = TRUE;
/* Field: Content: Link */
$handler->display->display_options['fields']['field_microsite_news_link_1']['id'] = 'field_microsite_news_link_1';
$handler->display->display_options['fields']['field_microsite_news_link_1']['table'] = 'field_data_field_microsite_news_link';
$handler->display->display_options['fields']['field_microsite_news_link_1']['field'] = 'field_microsite_news_link';
$handler->display->display_options['fields']['field_microsite_news_link_1']['label'] = '';
$handler->display->display_options['fields']['field_microsite_news_link_1']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_microsite_news_link_1']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_microsite_news_link_1']['click_sort_column'] = 'url';
/* Field: Content: Image */
$handler->display->display_options['fields']['field_media_image']['id'] = 'field_media_image';
$handler->display->display_options['fields']['field_media_image']['table'] = 'field_data_field_media_image';
$handler->display->display_options['fields']['field_media_image']['field'] = 'field_media_image';
$handler->display->display_options['fields']['field_media_image']['label'] = '';
$handler->display->display_options['fields']['field_media_image']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['field_media_image']['alter']['path'] = '[field_microsite_news_link_1]';
$handler->display->display_options['fields']['field_media_image']['alter']['target'] = '_blank';
$handler->display->display_options['fields']['field_media_image']['element_type'] = '0';
$handler->display->display_options['fields']['field_media_image']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_media_image']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_media_image']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_media_image']['hide_empty'] = TRUE;
$handler->display->display_options['fields']['field_media_image']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_media_image']['settings'] = array(
'image_style' => 'microsite_testimonials',
'image_link' => '',
);
$handler->display->display_options['fields']['field_media_image']['field_api_classes'] = TRUE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['path'] = '[field_microsite_news_link_1]';
$handler->display->display_options['fields']['title']['alter']['target'] = '_blank';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_type'] = '0';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Content: Body */
$handler->display->display_options['fields']['body']['id'] = 'body';
$handler->display->display_options['fields']['body']['table'] = 'field_data_body';
$handler->display->display_options['fields']['body']['field'] = 'body';
$handler->display->display_options['fields']['body']['label'] = '';
$handler->display->display_options['fields']['body']['exclude'] = TRUE;
$handler->display->display_options['fields']['body']['element_type'] = 'p';
$handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['body']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['body']['type'] = 'text_trimmed';
$handler->display->display_options['fields']['body']['settings'] = array(
'trim_length' => '300',
);
$handler->display->display_options['fields']['body']['field_api_classes'] = TRUE;
/* Field: Content: Link */
$handler->display->display_options['fields']['field_microsite_news_link']['id'] = 'field_microsite_news_link';
$handler->display->display_options['fields']['field_microsite_news_link']['table'] = 'field_data_field_microsite_news_link';
$handler->display->display_options['fields']['field_microsite_news_link']['field'] = 'field_microsite_news_link';
$handler->display->display_options['fields']['field_microsite_news_link']['label'] = '';
$handler->display->display_options['fields']['field_microsite_news_link']['element_type'] = '0';
$handler->display->display_options['fields']['field_microsite_news_link']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_microsite_news_link']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_microsite_news_link']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_microsite_news_link']['click_sort_column'] = 'url';
$handler->display->display_options['fields']['field_microsite_news_link']['field_api_classes'] = TRUE;

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page_1');
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['path'] = 'ebaysengage/en-savoir-plus/dans-les-medias';
$translatables['dans_les_media'] = array(
t('Master'),
t('DANS LES MÉDIAS'),
t('more'),
t('Apply'),
t('Reset'),
t('Sort by'),
t('Asc'),
t('Desc'),
t('Block'),
t('<a href="/fr/ebaysengage/en-savoir-plus/dans-les-medias">En savoir plus</a>'),
t('Page'),
);