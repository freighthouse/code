<?php

$view = new view();
$view->name = 'customers_front';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'Customers Front Block';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
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
$handler->display->display_options['pager']['options']['items_per_page'] = '16';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'list';
$handler->display->display_options['style_options']['class'] = 'list-unstyled';
$handler->display->display_options['row_plugin'] = 'fields';
/* Header: Global: PHP */
$handler->display->display_options['header']['php']['id'] = 'php';
$handler->display->display_options['header']['php']['table'] = 'views';
$handler->display->display_options['header']['php']['field'] = 'php';
$handler->display->display_options['header']['php']['php_output'] = '<h2 style="text-align: center; font-size: 54px; line-height: 56px; color: #4a494a; margin-bottom: 40px;">Apigee powers the most API programs</h2>
';
/* Relationship: Nodequeue: Queue */
$handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
$handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
$handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
$handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
$handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
$handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
  'customer_front_block' => 'customer_front_block',
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
  'about_apigee_investors' => 0,
  'partner_logos' => 0,
  'partners_vignette_slideshow' => 0,
  'about_apigee_page_ctas' => 0,
);
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['exclude'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Content: Logo */
$handler->display->display_options['fields']['field_customer_logo']['id'] = 'field_customer_logo';
$handler->display->display_options['fields']['field_customer_logo']['table'] = 'field_data_field_customer_logo';
$handler->display->display_options['fields']['field_customer_logo']['field'] = 'field_customer_logo';
$handler->display->display_options['fields']['field_customer_logo']['label'] = '';
$handler->display->display_options['fields']['field_customer_logo']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['field_customer_logo']['alter']['text'] = '<span style="vertical-align: middle; height: 100%; display: inline-block;"></span>[field_customer_logo]';
$handler->display->display_options['fields']['field_customer_logo']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['field_customer_logo']['alter']['path'] = 'customers';
$handler->display->display_options['fields']['field_customer_logo']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_customer_logo']['element_wrapper_type'] = 'span';
$handler->display->display_options['fields']['field_customer_logo']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_customer_logo']['settings'] = array(
  'image_style' => 'front_page_customers',
  'image_link' => '',
  'linked_field' => array(
    'linked' => 0,
    'destination' => 'customers',
    'advanced' => array(
      'title' => '',
      'target' => '',
      'class' => '',
      'rel' => '',
      'text' => '',
    ),
  ),
);
/* Field: Content: Featured */
$handler->display->display_options['fields']['field_customer_featured']['id'] = 'field_customer_featured';
$handler->display->display_options['fields']['field_customer_featured']['table'] = 'field_data_field_customer_featured';
$handler->display->display_options['fields']['field_customer_featured']['field'] = 'field_customer_featured';
$handler->display->display_options['fields']['field_customer_featured']['label'] = '';
$handler->display->display_options['fields']['field_customer_featured']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_customer_featured']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_customer_featured']['settings'] = array(
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
$handler->display->display_options['fields']['field_video']['delta_limit'] = 'all';
/* Field: Content: Statement */
$handler->display->display_options['fields']['field_customer_statement']['id'] = 'field_customer_statement';
$handler->display->display_options['fields']['field_customer_statement']['table'] = 'field_data_field_customer_statement';
$handler->display->display_options['fields']['field_customer_statement']['field'] = 'field_customer_statement';
$handler->display->display_options['fields']['field_customer_statement']['label'] = '';
$handler->display->display_options['fields']['field_customer_statement']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_customer_statement']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_customer_statement']['settings'] = array(
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
/* Sort criterion: Nodequeue: Position */
$handler->display->display_options['sorts']['position']['id'] = 'position';
$handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
$handler->display->display_options['sorts']['position']['field'] = 'position';
$handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
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
  'customer' => 'customer',
);

/* Display: Block */
$handler = $view->new_display('block', 'Block', 'block');
$handler->display->display_options['defaults']['header'] = FALSE;
/* Header: Global: PHP */
$handler->display->display_options['header']['php']['id'] = 'php';
$handler->display->display_options['header']['php']['table'] = 'views';
$handler->display->display_options['header']['php']['field'] = 'php';
$handler->display->display_options['header']['php']['php_output'] = '
';
$handler->display->display_options['defaults']['footer'] = FALSE;
/* Footer: Global: Text area */
$handler->display->display_options['footer']['area']['id'] = 'area';
$handler->display->display_options['footer']['area']['table'] = 'views';
$handler->display->display_options['footer']['area']['field'] = 'area';
$handler->display->display_options['footer']['area']['format'] = 'wysiwyg';
$translatables['customers_front'] = array(
  t('Master'),
  t('more'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('queue'),
  t('<span style="vertical-align: middle; height: 100%; display: inline-block;"></span>[field_customer_logo]'),
  t('Block'),
);