<?php

$view = new view();
$view->name = 'webform_views';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'webform_submissions';
$view->human_name = 'Webform Views';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Webform Views';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'none';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '50';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '9';
$handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
$handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '50, 100, 200';
$handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = TRUE;
$handler->display->display_options['style_plugin'] = 'table';
/* Field: Webform submissions: Sid */
$handler->display->display_options['fields']['sid']['id'] = 'sid';
$handler->display->display_options['fields']['sid']['table'] = 'webform_submissions';
$handler->display->display_options['fields']['sid']['field'] = 'sid';
/* Field: Content: Nid */
$handler->display->display_options['fields']['nid']['id'] = 'nid';
$handler->display->display_options['fields']['nid']['table'] = 'node';
$handler->display->display_options['fields']['nid']['field'] = 'nid';
/* Filter criterion: Content: Nid */
$handler->display->display_options['filters']['nid']['id'] = 'nid';
$handler->display->display_options['filters']['nid']['table'] = 'node';
$handler->display->display_options['filters']['nid']['field'] = 'nid';
$handler->display->display_options['filters']['nid']['value']['value'] = '129026';

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'webform-views';

/* Display: Contribution Submissions */
$handler = $view->new_display('page', 'Contribution Submissions', 'page_1');
$handler->display->display_options['defaults']['access'] = FALSE;
$handler->display->display_options['access']['type'] = 'role';
$handler->display->display_options['access']['role'] = array(
    3 => '3',
);
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Bulk operations: Content */
$handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
$handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_node';
$handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
$handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
        'selected' => 1,
        'postpone_processing' => 0,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
    ),
    'action::33' => array(
        'selected' => 1,
        'postpone_processing' => 0,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
    ),
    'action::35' => array(
        'selected' => 1,
        'postpone_processing' => 0,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
    ),
);
/* Field: Webform submissions: Sid */
$handler->display->display_options['fields']['sid']['id'] = 'sid';
$handler->display->display_options['fields']['sid']['table'] = 'webform_submissions';
$handler->display->display_options['fields']['sid']['field'] = 'sid';
/* Field: Webform submissions: Remote address */
$handler->display->display_options['fields']['remote_addr']['id'] = 'remote_addr';
$handler->display->display_options['fields']['remote_addr']['table'] = 'webform_submissions';
$handler->display->display_options['fields']['remote_addr']['field'] = 'remote_addr';
/* Field: Webform submissions: View link */
$handler->display->display_options['fields']['view_submission']['id'] = 'view_submission';
$handler->display->display_options['fields']['view_submission']['table'] = 'webform_submissions';
$handler->display->display_options['fields']['view_submission']['field'] = 'view_submission';
$handler->display->display_options['fields']['view_submission']['element_label_colon'] = FALSE;
$handler->display->display_options['path'] = 'admin/webform-submissions';
$translatables['webform_views'] = array(
    t('Master'),
    t('Webform Views'),
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
    t('Sid'),
    t('.'),
    t(','),
    t('Nid'),
    t('Page'),
    t('Contribution Submissions'),
    t('Content'),
    t('- Choose an operation -'),
    t('Remote address'),
    t('view'),
);