<?php

$view = new view();
$view->name = 'microsite_articles';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'Microsite Articles';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Actualités';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '3';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['row_plugin'] = 'fields';
/* Field: Content: Image */
$handler->display->display_options['fields']['field_microsite_image']['id'] = 'field_microsite_image';
$handler->display->display_options['fields']['field_microsite_image']['table'] = 'field_data_field_microsite_image';
$handler->display->display_options['fields']['field_microsite_image']['field'] = 'field_microsite_image';
$handler->display->display_options['fields']['field_microsite_image']['label'] = '';
$handler->display->display_options['fields']['field_microsite_image']['element_type'] = '0';
$handler->display->display_options['fields']['field_microsite_image']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_microsite_image']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_microsite_image']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_microsite_image']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_microsite_image']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => '',
);
$handler->display->display_options['fields']['field_microsite_image']['field_api_classes'] = TRUE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_type'] = 'h2';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
/* Field: Content: Body */
$handler->display->display_options['fields']['body']['id'] = 'body';
$handler->display->display_options['fields']['body']['table'] = 'field_data_body';
$handler->display->display_options['fields']['body']['field'] = 'body';
$handler->display->display_options['fields']['body']['label'] = '';
$handler->display->display_options['fields']['body']['element_type'] = '0';
$handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['body']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['body']['type'] = 'text_trimmed';
$handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '800',
);
$handler->display->display_options['fields']['body']['field_api_classes'] = TRUE;
/* Field: Content: Link */
$handler->display->display_options['fields']['view_node']['id'] = 'view_node';
$handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
$handler->display->display_options['fields']['view_node']['field'] = 'view_node';
$handler->display->display_options['fields']['view_node']['label'] = '';
$handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
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
    'microsite_articles_' => 'microsite_articles_',
);

/* Display: Block */
$handler = $view->new_display('block', 'Block', 'block');
$handler->display->display_options['defaults']['footer'] = FALSE;
/* Footer: Global: Text area */
$handler->display->display_options['footer']['area']['id'] = 'area';
$handler->display->display_options['footer']['area']['table'] = 'views';
$handler->display->display_options['footer']['area']['field'] = 'area';
$handler->display->display_options['footer']['area']['content'] = '<a href="/fr/ebaysengage/en-savoir-plus/actualites">En savoir plus</a>';
$handler->display->display_options['footer']['area']['format'] = 'full_html';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Post date */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'node';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['label'] = '';
$handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['created']['date_format'] = 'custom';
$handler->display->display_options['fields']['created']['custom_date_format'] = 'd F Y';
$handler->display->display_options['fields']['created']['second_date_format'] = 'html5_tools_iso8601';
/* Field: Content: Image */
$handler->display->display_options['fields']['field_microsite_image']['id'] = 'field_microsite_image';
$handler->display->display_options['fields']['field_microsite_image']['table'] = 'field_data_field_microsite_image';
$handler->display->display_options['fields']['field_microsite_image']['field'] = 'field_microsite_image';
$handler->display->display_options['fields']['field_microsite_image']['label'] = '';
$handler->display->display_options['fields']['field_microsite_image']['element_type'] = '0';
$handler->display->display_options['fields']['field_microsite_image']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_microsite_image']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_microsite_image']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_microsite_image']['hide_empty'] = TRUE;
$handler->display->display_options['fields']['field_microsite_image']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_microsite_image']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => '',
);
$handler->display->display_options['fields']['field_microsite_image']['field_api_classes'] = TRUE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_type'] = 'h2';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
/* Field: Content: Body */
$handler->display->display_options['fields']['body']['id'] = 'body';
$handler->display->display_options['fields']['body']['table'] = 'field_data_body';
$handler->display->display_options['fields']['body']['field'] = 'body';
$handler->display->display_options['fields']['body']['label'] = '';
$handler->display->display_options['fields']['body']['element_type'] = '0';
$handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['body']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
$handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
);
$handler->display->display_options['fields']['body']['field_api_classes'] = TRUE;
/* Field: Content: Link */
$handler->display->display_options['fields']['view_node']['id'] = 'view_node';
$handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
$handler->display->display_options['fields']['view_node']['field'] = 'view_node';
$handler->display->display_options['fields']['view_node']['label'] = '';
$handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page_1');
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Image */
$handler->display->display_options['fields']['field_microsite_image']['id'] = 'field_microsite_image';
$handler->display->display_options['fields']['field_microsite_image']['table'] = 'field_data_field_microsite_image';
$handler->display->display_options['fields']['field_microsite_image']['field'] = 'field_microsite_image';
$handler->display->display_options['fields']['field_microsite_image']['label'] = '';
$handler->display->display_options['fields']['field_microsite_image']['element_type'] = '0';
$handler->display->display_options['fields']['field_microsite_image']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_microsite_image']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_microsite_image']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_microsite_image']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_microsite_image']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => '',
);
$handler->display->display_options['fields']['field_microsite_image']['field_api_classes'] = TRUE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_type'] = 'h2';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
/* Field: Content: Body */
$handler->display->display_options['fields']['body']['id'] = 'body';
$handler->display->display_options['fields']['body']['table'] = 'field_data_body';
$handler->display->display_options['fields']['body']['field'] = 'body';
$handler->display->display_options['fields']['body']['label'] = '';
$handler->display->display_options['fields']['body']['element_type'] = '0';
$handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['body']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
$handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
);
$handler->display->display_options['fields']['body']['field_api_classes'] = TRUE;
/* Field: Content: Link */
$handler->display->display_options['fields']['view_node']['id'] = 'view_node';
$handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
$handler->display->display_options['fields']['view_node']['field'] = 'view_node';
$handler->display->display_options['fields']['view_node']['label'] = '';
$handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
$handler->display->display_options['path'] = 'ebaysengage/en-savoir-plus/actualites';

/* Display: Block */
$handler = $view->new_display('block', 'Block', 'block_1');
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '1';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['footer'] = FALSE;
/* Footer: Global: Text area */
$handler->display->display_options['footer']['area']['id'] = 'area';
$handler->display->display_options['footer']['area']['table'] = 'views';
$handler->display->display_options['footer']['area']['field'] = 'area';
$handler->display->display_options['footer']['area']['content'] = '<a href="/fr/ebaysengage/en-savoir-plus">Consulter plus d’actualités</a>';
$handler->display->display_options['footer']['area']['format'] = 'full_html';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Post date */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'node';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['label'] = '';
$handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['created']['date_format'] = 'custom';
$handler->display->display_options['fields']['created']['custom_date_format'] = 'd F Y';
$handler->display->display_options['fields']['created']['second_date_format'] = 'html5_tools_iso8601';
/* Field: Content: Image */
$handler->display->display_options['fields']['field_microsite_image']['id'] = 'field_microsite_image';
$handler->display->display_options['fields']['field_microsite_image']['table'] = 'field_data_field_microsite_image';
$handler->display->display_options['fields']['field_microsite_image']['field'] = 'field_microsite_image';
$handler->display->display_options['fields']['field_microsite_image']['label'] = '';
$handler->display->display_options['fields']['field_microsite_image']['element_type'] = '0';
$handler->display->display_options['fields']['field_microsite_image']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_microsite_image']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_microsite_image']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_microsite_image']['hide_empty'] = TRUE;
$handler->display->display_options['fields']['field_microsite_image']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_microsite_image']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => '',
);
$handler->display->display_options['fields']['field_microsite_image']['field_api_classes'] = TRUE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_type'] = 'h2';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
/* Field: Content: Body */
$handler->display->display_options['fields']['body']['id'] = 'body';
$handler->display->display_options['fields']['body']['table'] = 'field_data_body';
$handler->display->display_options['fields']['body']['field'] = 'body';
$handler->display->display_options['fields']['body']['label'] = '';
$handler->display->display_options['fields']['body']['element_type'] = '0';
$handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['body']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
$handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
);
$handler->display->display_options['fields']['body']['field_api_classes'] = TRUE;
/* Field: Content: Link */
$handler->display->display_options['fields']['view_node']['id'] = 'view_node';
$handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
$handler->display->display_options['fields']['view_node']['field'] = 'view_node';
$handler->display->display_options['fields']['view_node']['label'] = '';
$handler->display->display_options['fields']['view_node']['exclude'] = TRUE;
$handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
$handler->display->display_options['block_description'] = 'Actualites - homepage';
$translatables['microsite_articles'] = array(
    t('Master'),
    t('Actualités'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Block'),
    t('<a href="/fr/ebaysengage/en-savoir-plus/actualites">En savoir plus</a>'),
    t('Page'),
    t('<a href="/fr/ebaysengage/en-savoir-plus">Consulter plus d’actualités</a>'),
    t('Actualites - homepage'),
);