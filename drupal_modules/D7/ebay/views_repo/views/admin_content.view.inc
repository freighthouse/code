<?php

$view = new view();
$view->name = 'admin_content';
$view->description = 'Emulates the Drupal content administration page.';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'Content';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Content';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'role';
$handler->display->display_options['access']['role'] = array(
    3 => '3',
    4 => '4',
    5 => '5',
);
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['query_comment'] = FALSE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '20';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '9';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'edit_node' => 'edit_node',
    'type' => 'type',
    'title' => 'title',
    'webform_submission_count_node' => 'webform_submission_count_node',
    'path' => 'path',
    'status' => 'status',
    'created' => 'created',
    'changed' => 'changed',
);
$handler->display->display_options['style_options']['default'] = 'created';
$handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
    ),
    'edit_node' => array(
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
    ),
    'type' => array(
        'sortable' => 1,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
    ),
    'title' => array(
        'sortable' => 1,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
    ),
    'webform_submission_count_node' => array(
        'align' => 'views-align-right',
        'separator' => '',
        'empty_column' => 0,
    ),
    'path' => array(
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
    ),
    'status' => array(
        'sortable' => 0,
        'default_sort_order' => 'desc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
    ),
    'created' => array(
        'sortable' => 1,
        'default_sort_order' => 'desc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
    ),
    'changed' => array(
        'sortable' => 1,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
    ),
);
$handler->display->display_options['style_options']['empty_table'] = TRUE;
/* No results behavior: Global: Text area */
$handler->display->display_options['empty']['area']['id'] = 'area';
$handler->display->display_options['empty']['area']['table'] = 'views';
$handler->display->display_options['empty']['area']['field'] = 'area';
$handler->display->display_options['empty']['area']['content'] = 'No content available.';
$handler->display->display_options['empty']['area']['format'] = 'filtered_html';
/* Relationship: Content: Author */
$handler->display->display_options['relationships']['uid']['id'] = 'uid';
$handler->display->display_options['relationships']['uid']['table'] = 'node';
$handler->display->display_options['relationships']['uid']['field'] = 'uid';
/* Field: Bulk operations: Content */
$handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
$handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_node';
$handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
$handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
$handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['views_bulk_operations']['hide_alter_empty'] = FALSE;
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
$handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::nodequeue_add_action' => array(
        'selected' => 1,
        'postpone_processing' => 0,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
    ),
    'action::node_assign_owner_action' => array(
        'selected' => 1,
        'postpone_processing' => 0,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
        'selected' => 1,
        'postpone_processing' => 0,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
        'selected' => 1,
        'postpone_processing' => 0,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
    ),
    'action::node_make_sticky_action' => array(
        'selected' => 1,
        'postpone_processing' => 0,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
    ),
    'action::node_make_unsticky_action' => array(
        'selected' => 1,
        'postpone_processing' => 0,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
        'selected' => 1,
        'postpone_processing' => 0,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
        'settings' => array(
            'show_all_tokens' => 1,
            'display_values' => array(
                '_all_' => '_all_',
            ),
        ),
    ),
    'action::node_promote_action' => array(
        'selected' => 1,
        'postpone_processing' => 0,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
    ),
    'action::node_publish_action' => array(
        'selected' => 1,
        'postpone_processing' => 0,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
    ),
    'action::node_unpromote_action' => array(
        'selected' => 1,
        'postpone_processing' => 0,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
    ),
    'action::nodequeue_remove_action' => array(
        'selected' => 1,
        'postpone_processing' => 0,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
    ),
    'action::node_unpublish_action' => array(
        'selected' => 1,
        'postpone_processing' => 0,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
    ),
    'action::node_unpublish_by_keyword_action' => array(
        'selected' => 1,
        'postpone_processing' => 0,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
    ),
    'action::pathauto_node_update_action' => array(
        'selected' => 1,
        'postpone_processing' => 0,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
    ),
);
/* Field: Content: Edit link */
$handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
$handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
$handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
$handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
/* Field: Content: Path */
$handler->display->display_options['fields']['path']['id'] = 'path';
$handler->display->display_options['fields']['path']['table'] = 'node';
$handler->display->display_options['fields']['path']['field'] = 'path';
$handler->display->display_options['fields']['path']['label'] = 'URL';
/* Field: Content: Has new content */
$handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
$handler->display->display_options['fields']['timestamp']['table'] = 'history';
$handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
$handler->display->display_options['fields']['timestamp']['label'] = 'New?';
/* Field: Content: Type */
$handler->display->display_options['fields']['type']['id'] = 'type';
$handler->display->display_options['fields']['type']['table'] = 'node';
$handler->display->display_options['fields']['type']['field'] = 'type';
/* Field: Content: Published */
$handler->display->display_options['fields']['status']['id'] = 'status';
$handler->display->display_options['fields']['status']['table'] = 'node';
$handler->display->display_options['fields']['status']['field'] = 'status';
$handler->display->display_options['fields']['status']['not'] = 0;
/* Field: Content: All taxonomy terms */
$handler->display->display_options['fields']['term_node_tid']['id'] = 'term_node_tid';
$handler->display->display_options['fields']['term_node_tid']['table'] = 'node';
$handler->display->display_options['fields']['term_node_tid']['field'] = 'term_node_tid';
$handler->display->display_options['fields']['term_node_tid']['label'] = 'Taxonomy terms';
$handler->display->display_options['fields']['term_node_tid']['exclude'] = TRUE;
$handler->display->display_options['fields']['term_node_tid']['link_to_taxonomy'] = FALSE;
$handler->display->display_options['fields']['term_node_tid']['vocabularies'] = array(
    'region' => 0,
    'tags' => 0,
);
/* Field: Content: Post date */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'node';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['date_format'] = 'short';
/* Field: Content: Updated date */
$handler->display->display_options['fields']['changed']['id'] = 'changed';
$handler->display->display_options['fields']['changed']['table'] = 'node';
$handler->display->display_options['fields']['changed']['field'] = 'changed';
$handler->display->display_options['fields']['changed']['date_format'] = 'short';
/* Sort criterion: Content: Updated date */
$handler->display->display_options['sorts']['changed']['id'] = 'changed';
$handler->display->display_options['sorts']['changed']['table'] = 'node';
$handler->display->display_options['sorts']['changed']['field'] = 'changed';
$handler->display->display_options['sorts']['changed']['order'] = 'DESC';
/* Filter criterion: Content: Title */
$handler->display->display_options['filters']['title']['id'] = 'title';
$handler->display->display_options['filters']['title']['table'] = 'node';
$handler->display->display_options['filters']['title']['field'] = 'title';
$handler->display->display_options['filters']['title']['operator'] = 'contains';
$handler->display->display_options['filters']['title']['group'] = 1;
$handler->display->display_options['filters']['title']['exposed'] = TRUE;
$handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['label'] = 'Title contains';
$handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['group'] = 1;
$handler->display->display_options['filters']['type']['exposed'] = TRUE;
$handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
$handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
$handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
$handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
$handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
);
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 'All';
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['exposed'] = TRUE;
$handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
$handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
$handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
$handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
/* Filter criterion: Content: Post date */
$handler->display->display_options['filters']['created']['id'] = 'created';
$handler->display->display_options['filters']['created']['table'] = 'node';
$handler->display->display_options['filters']['created']['field'] = 'created';
$handler->display->display_options['filters']['created']['operator'] = 'between';
$handler->display->display_options['filters']['created']['group'] = 1;
$handler->display->display_options['filters']['created']['exposed'] = TRUE;
$handler->display->display_options['filters']['created']['expose']['operator_id'] = 'created_op';
$handler->display->display_options['filters']['created']['expose']['label'] = 'Published between';
$handler->display->display_options['filters']['created']['expose']['description'] = 'Enter dates formatted as CCYY-MM-DD';
$handler->display->display_options['filters']['created']['expose']['operator'] = 'created_op';
$handler->display->display_options['filters']['created']['expose']['identifier'] = 'created';
$handler->display->display_options['filters']['created']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
);
/* Filter criterion: Content: Language */
$handler->display->display_options['filters']['language']['id'] = 'language';
$handler->display->display_options['filters']['language']['table'] = 'node';
$handler->display->display_options['filters']['language']['field'] = 'language';
$handler->display->display_options['filters']['language']['group'] = 1;
$handler->display->display_options['filters']['language']['exposed'] = TRUE;
$handler->display->display_options['filters']['language']['expose']['operator_id'] = 'language_op';
$handler->display->display_options['filters']['language']['expose']['label'] = 'Language';
$handler->display->display_options['filters']['language']['expose']['operator'] = 'language_op';
$handler->display->display_options['filters']['language']['expose']['identifier'] = 'language';
$handler->display->display_options['filters']['language']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
);

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Bulk operations: Content */
$handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
$handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_node';
$handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
$handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
$handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['views_bulk_operations']['hide_alter_empty'] = FALSE;
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
$handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::nodequeue_add_action' => array(
        'selected' => 1,
        'postpone_processing' => 0,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
    ),
    'action::node_assign_owner_action' => array(
        'selected' => 1,
        'postpone_processing' => 0,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
        'selected' => 1,
        'postpone_processing' => 0,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
        'selected' => 1,
        'postpone_processing' => 0,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
    ),
    'action::node_make_sticky_action' => array(
        'selected' => 1,
        'postpone_processing' => 0,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
    ),
    'action::node_make_unsticky_action' => array(
        'selected' => 1,
        'postpone_processing' => 0,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
        'selected' => 1,
        'postpone_processing' => 0,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
        'settings' => array(
            'show_all_tokens' => 1,
            'display_values' => array(
                '_all_' => '_all_',
            ),
        ),
    ),
    'action::node_promote_action' => array(
        'selected' => 1,
        'postpone_processing' => 0,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
    ),
    'action::node_publish_action' => array(
        'selected' => 1,
        'postpone_processing' => 0,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
    ),
    'action::node_unpromote_action' => array(
        'selected' => 1,
        'postpone_processing' => 0,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
    ),
    'action::nodequeue_remove_action' => array(
        'selected' => 1,
        'postpone_processing' => 0,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
    ),
    'action::node_unpublish_action' => array(
        'selected' => 1,
        'postpone_processing' => 0,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
    ),
    'action::node_unpublish_by_keyword_action' => array(
        'selected' => 1,
        'postpone_processing' => 0,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
    ),
    'action::pathauto_node_update_action' => array(
        'selected' => 1,
        'postpone_processing' => 0,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
    ),
);
/* Field: Content: Edit link */
$handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
$handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
$handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
$handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
/* Field: Content: Path */
$handler->display->display_options['fields']['path']['id'] = 'path';
$handler->display->display_options['fields']['path']['table'] = 'node';
$handler->display->display_options['fields']['path']['field'] = 'path';
$handler->display->display_options['fields']['path']['label'] = 'URL';
/* Field: Content: Has new content */
$handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
$handler->display->display_options['fields']['timestamp']['table'] = 'history';
$handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
$handler->display->display_options['fields']['timestamp']['label'] = 'New?';
/* Field: Content: Type */
$handler->display->display_options['fields']['type']['id'] = 'type';
$handler->display->display_options['fields']['type']['table'] = 'node';
$handler->display->display_options['fields']['type']['field'] = 'type';
/* Field: Content: Published */
$handler->display->display_options['fields']['status']['id'] = 'status';
$handler->display->display_options['fields']['status']['table'] = 'node';
$handler->display->display_options['fields']['status']['field'] = 'status';
$handler->display->display_options['fields']['status']['not'] = 0;
/* Field: Content: All taxonomy terms */
$handler->display->display_options['fields']['term_node_tid']['id'] = 'term_node_tid';
$handler->display->display_options['fields']['term_node_tid']['table'] = 'node';
$handler->display->display_options['fields']['term_node_tid']['field'] = 'term_node_tid';
$handler->display->display_options['fields']['term_node_tid']['label'] = 'Taxonomy terms';
$handler->display->display_options['fields']['term_node_tid']['exclude'] = TRUE;
$handler->display->display_options['fields']['term_node_tid']['link_to_taxonomy'] = FALSE;
$handler->display->display_options['fields']['term_node_tid']['vocabularies'] = array(
    'region' => 0,
    'tags' => 0,
);
/* Field: Content: Post date */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'node';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['date_format'] = 'short';
/* Field: Content: Updated date */
$handler->display->display_options['fields']['changed']['id'] = 'changed';
$handler->display->display_options['fields']['changed']['table'] = 'node';
$handler->display->display_options['fields']['changed']['field'] = 'changed';
$handler->display->display_options['fields']['changed']['date_format'] = 'short';
/* Field: Content: Related Issue */
$handler->display->display_options['fields']['field_mediaarticle_issue']['id'] = 'field_mediaarticle_issue';
$handler->display->display_options['fields']['field_mediaarticle_issue']['table'] = 'field_data_field_mediaarticle_issue';
$handler->display->display_options['fields']['field_mediaarticle_issue']['field'] = 'field_mediaarticle_issue';
$handler->display->display_options['fields']['field_mediaarticle_issue']['label'] = 'Related Issues - Media';
$handler->display->display_options['fields']['field_mediaarticle_issue']['element_type'] = '0';
$handler->display->display_options['fields']['field_mediaarticle_issue']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_mediaarticle_issue']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_mediaarticle_issue']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_mediaarticle_issue']['type'] = 'node_reference_plain';
$handler->display->display_options['fields']['field_mediaarticle_issue']['delta_offset'] = '0';
$handler->display->display_options['fields']['field_mediaarticle_issue']['field_api_classes'] = TRUE;
/* Field: Content: Related Issue(s) */
$handler->display->display_options['fields']['field_news_issue']['id'] = 'field_news_issue';
$handler->display->display_options['fields']['field_news_issue']['table'] = 'field_data_field_news_issue';
$handler->display->display_options['fields']['field_news_issue']['field'] = 'field_news_issue';
$handler->display->display_options['fields']['field_news_issue']['label'] = 'Related Issues - News';
$handler->display->display_options['fields']['field_news_issue']['element_type'] = '0';
$handler->display->display_options['fields']['field_news_issue']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_news_issue']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_news_issue']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_news_issue']['type'] = 'node_reference_plain';
$handler->display->display_options['fields']['field_news_issue']['delta_offset'] = '0';
$handler->display->display_options['fields']['field_news_issue']['field_api_classes'] = TRUE;
$handler->display->display_options['path'] = 'admin/content2';
$handler->display->display_options['menu']['type'] = 'default tab';
$handler->display->display_options['menu']['title'] = 'Content';
$handler->display->display_options['menu']['weight'] = '0';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;
$handler->display->display_options['tab_options']['weight'] = '0';

/* Display: Content View */
$handler = $view->new_display('block', 'Content View', 'block_1');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Site Content';
$handler->display->display_options['enabled'] = FALSE;
$handler->display->display_options['display_description'] = 'The content view as a block';
$handler->display->display_options['defaults']['use_ajax'] = FALSE;
$handler->display->display_options['use_ajax'] = TRUE;
$handler->display->display_options['defaults']['exposed_form'] = FALSE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['exposed_form']['options']['submit_button'] = 'Filter';
$handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'title' => 'title',
    'timestamp' => 'title',
    'type' => 'type',
    'changed' => 'changed',
    'created' => 'created',
    'status' => 'status',
    'field_taxonomy_region' => 'field_taxonomy_region',
    'field_profile_office' => 'field_profile_office',
    'term_node_tid' => 'term_node_tid',
    'edit_node' => 'edit_node',
);
$handler->display->display_options['style_options']['default'] = 'changed';
$handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
    ),
    'title' => array(
        'sortable' => 1,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
    ),
    'timestamp' => array(
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
    ),
    'type' => array(
        'sortable' => 1,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
    ),
    'changed' => array(
        'sortable' => 1,
        'default_sort_order' => 'desc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
    ),
    'created' => array(
        'sortable' => 1,
        'default_sort_order' => 'desc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
    ),
    'status' => array(
        'sortable' => 1,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
    ),
    'field_taxonomy_region' => array(
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
    ),
    'field_profile_office' => array(
        'sortable' => 1,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
    ),
    'term_node_tid' => array(
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
    ),
    'edit_node' => array(
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
    ),
);
$handler->display->display_options['style_options']['empty_table'] = TRUE;
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Bulk operations: Content */
$handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
$handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_node';
$handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
$handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
$handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['views_bulk_operations']['hide_alter_empty'] = FALSE;
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
$handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::nodequeue_add_action' => array(
        'selected' => 1,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
        'postpone_processing' => 0,
    ),
    'action::node_assign_owner_action' => array(
        'selected' => 1,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
        'postpone_processing' => 0,
    ),
    'action::views_bulk_operations_delete_item' => array(
        'selected' => 1,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
        'postpone_processing' => 0,
    ),
    'action::views_bulk_operations_script_action' => array(
        'selected' => 1,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
        'postpone_processing' => 0,
    ),
    'action::node_make_sticky_action' => array(
        'selected' => 1,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
        'postpone_processing' => 0,
    ),
    'action::node_make_unsticky_action' => array(
        'selected' => 1,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
        'postpone_processing' => 0,
    ),
    'action::node_promote_action' => array(
        'selected' => 1,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
        'postpone_processing' => 0,
    ),
    'action::node_publish_action' => array(
        'selected' => 1,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
        'postpone_processing' => 0,
    ),
    'action::node_unpromote_action' => array(
        'selected' => 1,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
        'postpone_processing' => 0,
    ),
    'action::nodequeue_remove_action' => array(
        'selected' => 1,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
        'postpone_processing' => 0,
    ),
    'action::node_unpublish_action' => array(
        'selected' => 1,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
        'postpone_processing' => 0,
    ),
    'action::node_unpublish_by_keyword_action' => array(
        'selected' => 1,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
        'postpone_processing' => 0,
    ),
);
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
/* Field: Content: Has new content */
$handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
$handler->display->display_options['fields']['timestamp']['table'] = 'history';
$handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
$handler->display->display_options['fields']['timestamp']['label'] = 'New?';
/* Field: Content: Type */
$handler->display->display_options['fields']['type']['id'] = 'type';
$handler->display->display_options['fields']['type']['table'] = 'node';
$handler->display->display_options['fields']['type']['field'] = 'type';
/* Field: Content: Updated date */
$handler->display->display_options['fields']['changed']['id'] = 'changed';
$handler->display->display_options['fields']['changed']['table'] = 'node';
$handler->display->display_options['fields']['changed']['field'] = 'changed';
$handler->display->display_options['fields']['changed']['date_format'] = 'short';
/* Field: Content: Post date */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'node';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['date_format'] = 'short';
$handler->display->display_options['fields']['created']['second_date_format'] = 'html5_tools_iso8601';
/* Field: Content: Published */
$handler->display->display_options['fields']['status']['id'] = 'status';
$handler->display->display_options['fields']['status']['table'] = 'node';
$handler->display->display_options['fields']['status']['field'] = 'status';
$handler->display->display_options['fields']['status']['not'] = 0;
/* Field: Content: Region */
$handler->display->display_options['fields']['field_taxonomy_region']['id'] = 'field_taxonomy_region';
$handler->display->display_options['fields']['field_taxonomy_region']['table'] = 'field_data_field_taxonomy_region';
$handler->display->display_options['fields']['field_taxonomy_region']['field'] = 'field_taxonomy_region';
$handler->display->display_options['fields']['field_taxonomy_region']['type'] = 'taxonomy_term_reference_plain';
$handler->display->display_options['fields']['field_taxonomy_region']['delta_offset'] = '0';
/* Field: Content: Office */
$handler->display->display_options['fields']['field_profile_office']['id'] = 'field_profile_office';
$handler->display->display_options['fields']['field_profile_office']['table'] = 'field_data_field_profile_office';
$handler->display->display_options['fields']['field_profile_office']['field'] = 'field_profile_office';
$handler->display->display_options['fields']['field_profile_office']['type'] = 'node_reference_plain';
/* Field: Content: All taxonomy terms */
$handler->display->display_options['fields']['term_node_tid']['id'] = 'term_node_tid';
$handler->display->display_options['fields']['term_node_tid']['table'] = 'node';
$handler->display->display_options['fields']['term_node_tid']['field'] = 'term_node_tid';
$handler->display->display_options['fields']['term_node_tid']['label'] = 'Taxonomy terms';
$handler->display->display_options['fields']['term_node_tid']['exclude'] = TRUE;
$handler->display->display_options['fields']['term_node_tid']['link_to_taxonomy'] = FALSE;
$handler->display->display_options['fields']['term_node_tid']['vocabularies'] = array(
    'region' => 0,
    'tags' => 0,
);
/* Field: Content: Edit link */
$handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
$handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
$handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
$handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type_1']['id'] = 'type_1';
$handler->display->display_options['filters']['type_1']['table'] = 'node';
$handler->display->display_options['filters']['type_1']['field'] = 'type';
$handler->display->display_options['filters']['type_1']['operator'] = 'not in';
$handler->display->display_options['filters']['type_1']['value'] = array(
    'blog' => 'blog',
    'feed' => 'feed',
    'feed_item_ebay_germany' => 'feed_item_ebay_germany',
    'feed_item' => 'feed_item',
    'feed_item_ebay_inc_news' => 'feed_item_ebay_inc_news',
    'flickr_image' => 'flickr_image',
    'video_submission' => 'video_submission',
    'webform' => 'webform',
);
$handler->display->display_options['filters']['type_1']['group'] = 1;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
    'campaign' => 'campaign',
    'seller' => 'seller',
    'issue' => 'issue',
    'media_article' => 'media_article',
    'news' => 'news',
    'office' => 'office',
    'page' => 'page',
    'policy_paper' => 'policy_paper',
    'profile' => 'profile',
    'resources' => 'resources',
    'spotlight' => 'spotlight',
);
$handler->display->display_options['filters']['type']['group'] = 1;
$handler->display->display_options['filters']['type']['exposed'] = TRUE;
$handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
$handler->display->display_options['filters']['type']['expose']['label'] = 'Node: Type';
$handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
$handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
$handler->display->display_options['filters']['type']['expose']['remember'] = TRUE;
$handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    3 => '3',
    4 => '4',
    1 => 0,
);
$handler->display->display_options['filters']['type']['expose']['reduce'] = TRUE;
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 'All';
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['exposed'] = TRUE;
$handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
$handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
$handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
$handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
/* Filter criterion: Content: Region (field_taxonomy_region) */
$handler->display->display_options['filters']['field_taxonomy_region_tid']['id'] = 'field_taxonomy_region_tid';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['table'] = 'field_data_field_taxonomy_region';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['field'] = 'field_taxonomy_region_tid';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['group'] = 1;
$handler->display->display_options['filters']['field_taxonomy_region_tid']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_taxonomy_region_tid']['expose']['operator_id'] = 'field_taxonomy_region_tid_op';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['expose']['label'] = 'Region';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['expose']['operator'] = 'field_taxonomy_region_tid_op';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['expose']['identifier'] = 'field_taxonomy_region_tid';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['expose']['remember'] = TRUE;
$handler->display->display_options['filters']['field_taxonomy_region_tid']['expose']['remember_roles'] = array(
    2 => '2',
    3 => '3',
    4 => '4',
    1 => 0,
);
$handler->display->display_options['filters']['field_taxonomy_region_tid']['type'] = 'select';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['vocabulary'] = 'region';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['error_message'] = FALSE;
/* Filter criterion: Content: Title */
$handler->display->display_options['filters']['title']['id'] = 'title';
$handler->display->display_options['filters']['title']['table'] = 'node';
$handler->display->display_options['filters']['title']['field'] = 'title';
$handler->display->display_options['filters']['title']['operator'] = 'contains';
$handler->display->display_options['filters']['title']['group'] = 1;
$handler->display->display_options['filters']['title']['exposed'] = TRUE;
$handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['label'] = 'Title contains';
$handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';

/* Display: Webforms */
$handler = $view->new_display('page', 'Webforms', 'page_1');
$handler->display->display_options['defaults']['query'] = FALSE;
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['distinct'] = TRUE;
$handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
$handler->display->display_options['defaults']['relationships'] = FALSE;
/* Relationship: Content: Webform submission */
$handler->display->display_options['relationships']['webform_submission']['id'] = 'webform_submission';
$handler->display->display_options['relationships']['webform_submission']['table'] = 'node';
$handler->display->display_options['relationships']['webform_submission']['field'] = 'webform_submission';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Bulk operations: Content */
$handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
$handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_node';
$handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
$handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
$handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['views_bulk_operations']['hide_alter_empty'] = FALSE;
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
$handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::nodequeue_add_action' => array(
        'selected' => 1,
        'postpone_processing' => 0,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
    ),
    'action::node_assign_owner_action' => array(
        'selected' => 1,
        'postpone_processing' => 0,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
        'selected' => 1,
        'postpone_processing' => 0,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
        'selected' => 1,
        'postpone_processing' => 0,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
    ),
    'action::node_make_sticky_action' => array(
        'selected' => 1,
        'postpone_processing' => 0,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
    ),
    'action::node_make_unsticky_action' => array(
        'selected' => 1,
        'postpone_processing' => 0,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
        'selected' => 1,
        'postpone_processing' => 0,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
        'settings' => array(
            'show_all_tokens' => 1,
            'display_values' => array(
                '_all_' => '_all_',
            ),
        ),
    ),
    'action::node_promote_action' => array(
        'selected' => 1,
        'postpone_processing' => 0,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
    ),
    'action::node_publish_action' => array(
        'selected' => 1,
        'postpone_processing' => 0,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
    ),
    'action::node_unpromote_action' => array(
        'selected' => 1,
        'postpone_processing' => 0,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
    ),
    'action::nodequeue_remove_action' => array(
        'selected' => 1,
        'postpone_processing' => 0,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
    ),
    'action::node_unpublish_action' => array(
        'selected' => 1,
        'postpone_processing' => 0,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
    ),
    'action::node_unpublish_by_keyword_action' => array(
        'selected' => 1,
        'postpone_processing' => 0,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
    ),
    'action::pathauto_node_update_action' => array(
        'selected' => 1,
        'postpone_processing' => 0,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
    ),
);
/* Field: Content: Edit link */
$handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
$handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
$handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
$handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
/* Field: Content: Type */
$handler->display->display_options['fields']['type']['id'] = 'type';
$handler->display->display_options['fields']['type']['table'] = 'node';
$handler->display->display_options['fields']['type']['field'] = 'type';
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
/* Field: Webform: Webform submission count */
$handler->display->display_options['fields']['webform_submission_count_node']['id'] = 'webform_submission_count_node';
$handler->display->display_options['fields']['webform_submission_count_node']['table'] = 'node';
$handler->display->display_options['fields']['webform_submission_count_node']['field'] = 'webform_submission_count_node';
$handler->display->display_options['fields']['webform_submission_count_node']['label'] = 'Submissions';
/* Field: Content: Path */
$handler->display->display_options['fields']['path']['id'] = 'path';
$handler->display->display_options['fields']['path']['table'] = 'node';
$handler->display->display_options['fields']['path']['field'] = 'path';
$handler->display->display_options['fields']['path']['label'] = 'URL';
/* Field: Content: Published */
$handler->display->display_options['fields']['status']['id'] = 'status';
$handler->display->display_options['fields']['status']['table'] = 'node';
$handler->display->display_options['fields']['status']['field'] = 'status';
$handler->display->display_options['fields']['status']['not'] = 0;
/* Field: Content: Post date */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'node';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['date_format'] = 'short';
/* Field: Content: Updated date */
$handler->display->display_options['fields']['changed']['id'] = 'changed';
$handler->display->display_options['fields']['changed']['table'] = 'node';
$handler->display->display_options['fields']['changed']['field'] = 'changed';
$handler->display->display_options['fields']['changed']['date_format'] = 'short';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Content: Title */
$handler->display->display_options['filters']['title']['id'] = 'title';
$handler->display->display_options['filters']['title']['table'] = 'node';
$handler->display->display_options['filters']['title']['field'] = 'title';
$handler->display->display_options['filters']['title']['operator'] = 'contains';
$handler->display->display_options['filters']['title']['group'] = 1;
$handler->display->display_options['filters']['title']['exposed'] = TRUE;
$handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['label'] = 'Title contains';
$handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
    'petition' => 'petition',
    'webform' => 'webform',
);
$handler->display->display_options['filters']['type']['group'] = 1;
$handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
$handler->display->display_options['filters']['type']['expose']['label'] = 'Node: Type';
$handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
$handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = '1';
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['exposed'] = TRUE;
$handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
$handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
$handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
$handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
$handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
);
/* Filter criterion: Content: Language */
$handler->display->display_options['filters']['language']['id'] = 'language';
$handler->display->display_options['filters']['language']['table'] = 'node';
$handler->display->display_options['filters']['language']['field'] = 'language';
$handler->display->display_options['filters']['language']['group'] = 1;
$handler->display->display_options['filters']['language']['exposed'] = TRUE;
$handler->display->display_options['filters']['language']['expose']['operator_id'] = 'language_op';
$handler->display->display_options['filters']['language']['expose']['label'] = 'Language';
$handler->display->display_options['filters']['language']['expose']['operator'] = 'language_op';
$handler->display->display_options['filters']['language']['expose']['identifier'] = 'language';
$handler->display->display_options['filters']['language']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
);
$handler->display->display_options['path'] = 'admin/webforms';
$handler->display->display_options['menu']['title'] = 'Content';
$handler->display->display_options['menu']['weight'] = '0';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;
$handler->display->display_options['tab_options']['weight'] = '0';
$translatables['admin_content'] = array(
    t('Master'),
    t('Content'),
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
    t('No content available.'),
    t('author'),
    t('- Choose an operation -'),
    t('Edit'),
    t('Title'),
    t('URL'),
    t('New?'),
    t('Type'),
    t('Published'),
    t('Taxonomy terms'),
    t('Post date'),
    t('Updated date'),
    t('Title contains'),
    t('Published between'),
    t('Enter dates formatted as CCYY-MM-DD'),
    t('Language'),
    t('Page'),
    t('Related Issues - Media'),
    t('Related Issues - News'),
    t('Content View'),
    t('Site Content'),
    t('The content view as a block'),
    t('Filter'),
    t('Region'),
    t('Office'),
    t('Node: Type'),
    t('Webforms'),
    t('Webform Submission'),
    t('Submissions'),
);