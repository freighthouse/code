<?php

$view = new view();
$view->name = 'microsite_testimonials';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'Microsite Testimonials';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Microsite Testimonials';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '9';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['style_options']['row_class'] = '[field_video_embed]';
$handler->display->display_options['row_plugin'] = 'fields';
/* Field: Content: Photo */
$handler->display->display_options['fields']['field_testi_photo']['id'] = 'field_testi_photo';
$handler->display->display_options['fields']['field_testi_photo']['table'] = 'field_data_field_testi_photo';
$handler->display->display_options['fields']['field_testi_photo']['field'] = 'field_testi_photo';
$handler->display->display_options['fields']['field_testi_photo']['label'] = '';
$handler->display->display_options['fields']['field_testi_photo']['element_type'] = '0';
$handler->display->display_options['fields']['field_testi_photo']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_testi_photo']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_testi_photo']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_testi_photo']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_testi_photo']['settings'] = array(
    'image_style' => 'microsite_testimonials',
    'image_link' => 'content',
);
$handler->display->display_options['fields']['field_testi_photo']['field_api_classes'] = TRUE;
/* Field: Content: Path */
$handler->display->display_options['fields']['path']['id'] = 'path';
$handler->display->display_options['fields']['path']['table'] = 'node';
$handler->display->display_options['fields']['path']['field'] = 'path';
$handler->display->display_options['fields']['path']['label'] = '';
$handler->display->display_options['fields']['path']['exclude'] = TRUE;
$handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['path']['hide_empty'] = TRUE;
$handler->display->display_options['fields']['path']['absolute'] = TRUE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_type'] = 'h2';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
/* Field: Content: Business Name */
$handler->display->display_options['fields']['field_business_name']['id'] = 'field_business_name';
$handler->display->display_options['fields']['field_business_name']['table'] = 'field_data_field_business_name';
$handler->display->display_options['fields']['field_business_name']['field'] = 'field_business_name';
$handler->display->display_options['fields']['field_business_name']['label'] = '';
$handler->display->display_options['fields']['field_business_name']['alter']['path'] = '[path]';
$handler->display->display_options['fields']['field_business_name']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_business_name']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_business_name']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_business_name']['field_api_classes'] = TRUE;
/* Field: Content: Video Embed */
$handler->display->display_options['fields']['field_video_embed']['id'] = 'field_video_embed';
$handler->display->display_options['fields']['field_video_embed']['table'] = 'field_data_field_video_embed';
$handler->display->display_options['fields']['field_video_embed']['field'] = 'field_video_embed';
$handler->display->display_options['fields']['field_video_embed']['label'] = '';
$handler->display->display_options['fields']['field_video_embed']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_video_embed']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['field_video_embed']['alter']['text'] = 'has-video';
$handler->display->display_options['fields']['field_video_embed']['element_type'] = '0';
$handler->display->display_options['fields']['field_video_embed']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_video_embed']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_video_embed']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_video_embed']['empty'] = 'no-video';
$handler->display->display_options['fields']['field_video_embed']['click_sort_column'] = 'video_url';
$handler->display->display_options['fields']['field_video_embed']['settings'] = array(
    'video_style' => 'normal',
);
$handler->display->display_options['fields']['field_video_embed']['field_api_classes'] = TRUE;
/* Field: Content: Market or Industry */
$handler->display->display_options['fields']['field_testimonial_market']['id'] = 'field_testimonial_market';
$handler->display->display_options['fields']['field_testimonial_market']['table'] = 'field_data_field_testimonial_market';
$handler->display->display_options['fields']['field_testimonial_market']['field'] = 'field_testimonial_market';
$handler->display->display_options['fields']['field_testimonial_market']['label'] = '';
$handler->display->display_options['fields']['field_testimonial_market']['element_type'] = '0';
$handler->display->display_options['fields']['field_testimonial_market']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_testimonial_market']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_testimonial_market']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_testimonial_market']['empty'] = '<br>';
$handler->display->display_options['fields']['field_testimonial_market']['type'] = 'text_plain';
$handler->display->display_options['fields']['field_testimonial_market']['field_api_classes'] = TRUE;
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
    'trim_length' => '140',
);
$handler->display->display_options['fields']['body']['field_api_classes'] = TRUE;
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
    'microsite_testimonials' => 'microsite_testimonials',
);

/* Display: Block */
$handler = $view->new_display('block', 'Block', 'block');

/* Display: Block */
$handler = $view->new_display('block', 'Block', 'block_1');
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '3';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['header'] = FALSE;
/* Header: Global: Text area */
$handler->display->display_options['header']['area']['id'] = 'area';
$handler->display->display_options['header']['area']['table'] = 'views';
$handler->display->display_options['header']['area']['field'] = 'area';
$handler->display->display_options['header']['area']['content'] = 'Des entrepreneurs du e-commerce partagent leur expérience: découvrez leur histoire.';
$handler->display->display_options['header']['area']['format'] = 'full_html';
$handler->display->display_options['defaults']['footer'] = FALSE;
/* Footer: Global: Text area */
$handler->display->display_options['footer']['area']['id'] = 'area';
$handler->display->display_options['footer']['area']['table'] = 'views';
$handler->display->display_options['footer']['area']['field'] = 'area';
$handler->display->display_options['footer']['area']['content'] = '<p><a href="/fr/ebaysengage/temoignages">Lire plus de témoignages</a></p>';
$handler->display->display_options['footer']['area']['format'] = 'full_html';
$handler->display->display_options['defaults']['relationships'] = FALSE;
$handler->display->display_options['block_description'] = 'Testimonials - Nos propositions';
$translatables['microsite_testimonials'] = array(
    t('Master'),
    t('Microsite Testimonials'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('has-video'),
    t('no-video'),
    t('<br>'),
    t('Block'),
    t('Des entrepreneurs du e-commerce partagent leur expérience: découvrez leur histoire.'),
    t('<p><a href="/fr/ebaysengage/temoignages">Lire plus de témoignages</a></p>'),
    t('Testimonials - Nos propositions'),
);