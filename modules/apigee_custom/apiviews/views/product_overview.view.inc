<?php

$view = new view();
$view->name = 'product_overview';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'bean';
$view->human_name = 'Product Overview';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'none';
$handler->display->display_options['cache']['type'] = 'time';
$handler->display->display_options['cache']['results_lifespan'] = '60';
$handler->display->display_options['cache']['results_lifespan_custom'] = '0';
$handler->display->display_options['cache']['output_lifespan'] = '60';
$handler->display->display_options['cache']['output_lifespan_custom'] = '0';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '3';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['row_plugin'] = 'entity';
$handler->display->display_options['row_options']['view_mode'] = 'front_page_products';
/* Header: Global: PHP */
$handler->display->display_options['header']['php']['id'] = 'php';
$handler->display->display_options['header']['php']['table'] = 'views';
$handler->display->display_options['header']['php']['field'] = 'php';
/* Field: Block: Internal, numeric block ID */
$handler->display->display_options['fields']['bid']['id'] = 'bid';
$handler->display->display_options['fields']['bid']['table'] = 'bean';
$handler->display->display_options['fields']['bid']['field'] = 'bid';
/* Contextual filter: Block: View Mode */
$handler->display->display_options['arguments']['view_mode']['id'] = 'view_mode';
$handler->display->display_options['arguments']['view_mode']['table'] = 'bean';
$handler->display->display_options['arguments']['view_mode']['field'] = 'view_mode';
$handler->display->display_options['arguments']['view_mode']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['view_mode']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['view_mode']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['view_mode']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['view_mode']['limit'] = '0';
/* Filter criterion: Block: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'bean';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'product_overview' => 'product_overview',
);
/* Filter criterion: Block: View Mode */
$handler->display->display_options['filters']['view_mode']['id'] = 'view_mode';
$handler->display->display_options['filters']['view_mode']['table'] = 'bean';
$handler->display->display_options['filters']['view_mode']['field'] = 'view_mode';
$handler->display->display_options['filters']['view_mode']['expose']['operator_id'] = 'view_mode_op';
$handler->display->display_options['filters']['view_mode']['expose']['label'] = 'View Mode';
$handler->display->display_options['filters']['view_mode']['expose']['operator'] = 'view_mode_op';
$handler->display->display_options['filters']['view_mode']['expose']['identifier'] = 'view_mode';

/* Display: Product Overview A */
$handler = $view->new_display('block', 'Product Overview A', 'block');
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'entity';
$handler->display->display_options['row_options']['view_mode'] = 'product_overview_a';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['header'] = FALSE;
/* Header: Global: PHP */
$handler->display->display_options['header']['php']['id'] = 'php';
$handler->display->display_options['header']['php']['table'] = 'views';
$handler->display->display_options['header']['php']['field'] = 'php';
$handler->display->display_options['header']['php']['php_output'] = '<!-- <h1 class="text-center homepage">The Digital Business Platform</h1> -->
<h2 class="text-center"><strong>The Intelligent API Platform</strong></h2>
<h3 class="text-center" style="margin-top: -10px;">For digital business acceleration</h3>
<p></p>';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Block: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'bean';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'product_overview' => 'product_overview',
);
/* Filter criterion: Block: View Mode */
$handler->display->display_options['filters']['view_mode']['id'] = 'view_mode';
$handler->display->display_options['filters']['view_mode']['table'] = 'bean';
$handler->display->display_options['filters']['view_mode']['field'] = 'view_mode';
$handler->display->display_options['filters']['view_mode']['value'] = 'product_overview_a';
$handler->display->display_options['filters']['view_mode']['expose']['operator_id'] = 'view_mode_op';
$handler->display->display_options['filters']['view_mode']['expose']['label'] = 'View Mode';
$handler->display->display_options['filters']['view_mode']['expose']['operator'] = 'view_mode_op';
$handler->display->display_options['filters']['view_mode']['expose']['identifier'] = 'view_mode';

/* Display: Product Overview B */
$handler = $view->new_display('block', 'Product Overview B', 'block_1');
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'entity';
$handler->display->display_options['row_options']['view_mode'] = 'product_overview_b';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['footer'] = FALSE;
/* Footer: Global: PHP */
$handler->display->display_options['footer']['php']['id'] = 'php';
$handler->display->display_options['footer']['php']['table'] = 'views';
$handler->display->display_options['footer']['php']['field'] = 'php';
$handler->display->display_options['footer']['php']['php_output'] = '<a href="https://accounts.apigee.com/accounts/sign_up?int_source=start-here&int_medium=website&int_campaign=signup&int_content=edge" class="btn">Sign up</a>
';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Block: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'bean';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'product_overview' => 'product_overview',
);
/* Filter criterion: Block: View Mode */
$handler->display->display_options['filters']['view_mode']['id'] = 'view_mode';
$handler->display->display_options['filters']['view_mode']['table'] = 'bean';
$handler->display->display_options['filters']['view_mode']['field'] = 'view_mode';
$handler->display->display_options['filters']['view_mode']['value'] = 'product_overview_b';

/* Display: Front Page Products */
$handler = $view->new_display('block', 'Front Page Products', 'front_page_products');
$handler->display->display_options['display_description'] = 'Per DeckHand design';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'views_bootstrap_grid_plugin_style';
$handler->display->display_options['style_options']['columns'] = '3';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['hide_empty'] = TRUE;
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['header'] = FALSE;
/* Header: Global: Text area */
$handler->display->display_options['header']['area']['id'] = 'area';
$handler->display->display_options['header']['area']['table'] = 'views';
$handler->display->display_options['header']['area']['field'] = 'area';
$handler->display->display_options['header']['area']['content'] = '<div class="product_head">
  <div class="row">
  <div class="product_img_left col-lg-4">Highly Scalable</div>
  <div class="col-lg-4">
    <div class="product_logo"></div>
    <h3 class="text-center">The Intelligent API Platform</h3>
  </div>
  <div class="product_img_right col-lg-4">Cloud / On Prem</div>
</div>
</div>';
$handler->display->display_options['header']['area']['format'] = 'full_html';
$handler->display->display_options['defaults']['footer'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Block: Internal, numeric block ID */
$handler->display->display_options['fields']['bid']['id'] = 'bid';
$handler->display->display_options['fields']['bid']['table'] = 'bean';
$handler->display->display_options['fields']['bid']['field'] = 'bid';
$handler->display->display_options['fields']['bid']['label'] = '';
$handler->display->display_options['fields']['bid']['exclude'] = TRUE;
$handler->display->display_options['fields']['bid']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['bid']['element_default_classes'] = FALSE;
/* Field: Block: Icon */
$handler->display->display_options['fields']['field_productoffering_icon']['id'] = 'field_productoffering_icon';
$handler->display->display_options['fields']['field_productoffering_icon']['table'] = 'field_data_field_productoffering_icon';
$handler->display->display_options['fields']['field_productoffering_icon']['field'] = 'field_productoffering_icon';
$handler->display->display_options['fields']['field_productoffering_icon']['label'] = '';
$handler->display->display_options['fields']['field_productoffering_icon']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_productoffering_icon']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_productoffering_icon']['settings'] = array(
  'image_style' => '',
  'image_link' => 'content',
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
/* Field: Block: Image */
$handler->display->display_options['fields']['field__productoffering_image']['id'] = 'field__productoffering_image';
$handler->display->display_options['fields']['field__productoffering_image']['table'] = 'field_data_field__productoffering_image';
$handler->display->display_options['fields']['field__productoffering_image']['field'] = 'field__productoffering_image';
$handler->display->display_options['fields']['field__productoffering_image']['label'] = '';
$handler->display->display_options['fields']['field__productoffering_image']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field__productoffering_image']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field__productoffering_image']['settings'] = array(
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
/* Field: Block: Link */
$handler->display->display_options['fields']['field__productoffering_link']['id'] = 'field__productoffering_link';
$handler->display->display_options['fields']['field__productoffering_link']['table'] = 'field_data_field__productoffering_link';
$handler->display->display_options['fields']['field__productoffering_link']['field'] = 'field__productoffering_link';
$handler->display->display_options['fields']['field__productoffering_link']['label'] = '';
$handler->display->display_options['fields']['field__productoffering_link']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field__productoffering_link']['click_sort_column'] = 'url';
$handler->display->display_options['fields']['field__productoffering_link']['settings'] = array(
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
/* Filter criterion: Block: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'bean';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'product_overview' => 'product_overview',
);
/* Filter criterion: Block: View Mode */
$handler->display->display_options['filters']['view_mode']['id'] = 'view_mode';
$handler->display->display_options['filters']['view_mode']['table'] = 'bean';
$handler->display->display_options['filters']['view_mode']['field'] = 'view_mode';
$handler->display->display_options['filters']['view_mode']['value'] = 'front_page_products';
$translatables['product_overview'] = array(
  t('Master'),
  t('more'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('Internal, numeric block ID'),
  t('.'),
  t(','),
  t('All'),
  t('View Mode'),
  t('Product Overview A'),
  t('Product Overview B'),
  t('Front Page Products'),
  t('Per DeckHand design'),
  t('<div class="product_head">
  <div class="row">
  <div class="product_img_left col-lg-4">Highly Scalable</div>
  <div class="col-lg-4">
    <div class="product_logo"></div>
    <h3 class="text-center">The Intelligent API Platform</h3>
  </div>
  <div class="product_img_right col-lg-4">Cloud / On Prem</div>
</div>
</div>'),
);