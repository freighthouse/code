<?php

$view = new view();
$view->name = 'mediaarticles';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'Media Articles';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'In the Press';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '5';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'list';
$handler->display->display_options['style_options']['row_class'] = 'media-item';
$handler->display->display_options['style_options']['default_row_class'] = FALSE;
$handler->display->display_options['style_options']['row_class_special'] = FALSE;
$handler->display->display_options['style_options']['class'] = 'media-items';
$handler->display->display_options['style_options']['wrapper_class'] = 'media-items-wrapper';
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['inline'] = array(
    'field_mediaarticle_publisher' => 'field_mediaarticle_publisher',
    'field_mediaarticle_date' => 'field_mediaarticle_date',
);
/* Field: Content: Link */
$handler->display->display_options['fields']['field_mediaarticle_link']['id'] = 'field_mediaarticle_link';
$handler->display->display_options['fields']['field_mediaarticle_link']['table'] = 'field_data_field_mediaarticle_link';
$handler->display->display_options['fields']['field_mediaarticle_link']['field'] = 'field_mediaarticle_link';
$handler->display->display_options['fields']['field_mediaarticle_link']['label'] = '';
$handler->display->display_options['fields']['field_mediaarticle_link']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_mediaarticle_link']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_mediaarticle_link']['click_sort_column'] = 'url';
$handler->display->display_options['fields']['field_mediaarticle_link']['type'] = 'link_plain';
/* Field: Content: Headline */
$handler->display->display_options['fields']['field_mediaarticle_headline']['id'] = 'field_mediaarticle_headline';
$handler->display->display_options['fields']['field_mediaarticle_headline']['table'] = 'field_data_field_mediaarticle_headline';
$handler->display->display_options['fields']['field_mediaarticle_headline']['field'] = 'field_mediaarticle_headline';
$handler->display->display_options['fields']['field_mediaarticle_headline']['label'] = '';
$handler->display->display_options['fields']['field_mediaarticle_headline']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['field_mediaarticle_headline']['alter']['text'] = '<a href="[field_mediaarticle_link]" target="_blank">[field_mediaarticle_headline]</a>';
$handler->display->display_options['fields']['field_mediaarticle_headline']['alter']['path'] = '[link]';
$handler->display->display_options['fields']['field_mediaarticle_headline']['element_type'] = 'h3';
$handler->display->display_options['fields']['field_mediaarticle_headline']['element_class'] = 'media-headline';
$handler->display->display_options['fields']['field_mediaarticle_headline']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_mediaarticle_headline']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_mediaarticle_headline']['element_default_classes'] = FALSE;
/* Field: Content: Publisher */
$handler->display->display_options['fields']['field_mediaarticle_publisher']['id'] = 'field_mediaarticle_publisher';
$handler->display->display_options['fields']['field_mediaarticle_publisher']['table'] = 'field_data_field_mediaarticle_publisher';
$handler->display->display_options['fields']['field_mediaarticle_publisher']['field'] = 'field_mediaarticle_publisher';
$handler->display->display_options['fields']['field_mediaarticle_publisher']['label'] = '';
$handler->display->display_options['fields']['field_mediaarticle_publisher']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_mediaarticle_publisher']['element_type'] = '0';
$handler->display->display_options['fields']['field_mediaarticle_publisher']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_mediaarticle_publisher']['element_wrapper_type'] = 'p';
$handler->display->display_options['fields']['field_mediaarticle_publisher']['element_wrapper_class'] = 'media-publisher';
$handler->display->display_options['fields']['field_mediaarticle_publisher']['element_default_classes'] = FALSE;
/* Field: Content: Date */
$handler->display->display_options['fields']['field_mediaarticle_date']['id'] = 'field_mediaarticle_date';
$handler->display->display_options['fields']['field_mediaarticle_date']['table'] = 'field_data_field_mediaarticle_date';
$handler->display->display_options['fields']['field_mediaarticle_date']['field'] = 'field_mediaarticle_date';
$handler->display->display_options['fields']['field_mediaarticle_date']['label'] = '';
$handler->display->display_options['fields']['field_mediaarticle_date']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['field_mediaarticle_date']['alter']['text'] = '<p class="media-publisher-date">[field_mediaarticle_publisher] | [field_mediaarticle_date]</p>';
$handler->display->display_options['fields']['field_mediaarticle_date']['element_type'] = '0';
$handler->display->display_options['fields']['field_mediaarticle_date']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_mediaarticle_date']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_mediaarticle_date']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_mediaarticle_date']['settings'] = array(
    'format_type' => 'custom',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => '',
);
/* Sort criterion: Content: Date (field_mediaarticle_date) */
$handler->display->display_options['sorts']['field_mediaarticle_date_value']['id'] = 'field_mediaarticle_date_value';
$handler->display->display_options['sorts']['field_mediaarticle_date_value']['table'] = 'field_data_field_mediaarticle_date';
$handler->display->display_options['sorts']['field_mediaarticle_date_value']['field'] = 'field_mediaarticle_date_value';
$handler->display->display_options['sorts']['field_mediaarticle_date_value']['order'] = 'DESC';
/* Sort criterion: Content: Sticky */
$handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
$handler->display->display_options['sorts']['sticky']['table'] = 'node';
$handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
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
    'media_article' => 'media_article',
);
/* Filter criterion: Content: Region (field_taxonomy_region) */
$handler->display->display_options['filters']['field_taxonomy_region_tid']['id'] = 'field_taxonomy_region_tid';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['table'] = 'field_data_field_taxonomy_region';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['field'] = 'field_taxonomy_region_tid';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['group'] = '0';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['type'] = 'select';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['vocabulary'] = 'region';

/* Display: In The Press Block */
$handler = $view->new_display('block', 'In The Press Block', 'block');
$handler->display->display_options['defaults']['use_more'] = FALSE;
$handler->display->display_options['use_more'] = TRUE;
$handler->display->display_options['defaults']['use_more_always'] = FALSE;
$handler->display->display_options['defaults']['use_more_always'] = FALSE;
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['defaults']['use_more_text'] = FALSE;
$handler->display->display_options['use_more_text'] = 'Read more';
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: Content: Sticky */
$handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
$handler->display->display_options['sorts']['sticky']['table'] = 'node';
$handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
$handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
/* Sort criterion: Content: Date (field_mediaarticle_date) */
$handler->display->display_options['sorts']['field_mediaarticle_date_value']['id'] = 'field_mediaarticle_date_value';
$handler->display->display_options['sorts']['field_mediaarticle_date_value']['table'] = 'field_data_field_mediaarticle_date';
$handler->display->display_options['sorts']['field_mediaarticle_date_value']['field'] = 'field_mediaarticle_date_value';
$handler->display->display_options['sorts']['field_mediaarticle_date_value']['order'] = 'DESC';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
);
$handler->display->display_options['defaults']['filters'] = FALSE;
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
    'media_article' => 'media_article',
);
$handler->display->display_options['filters']['type']['group'] = 1;

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page_1');
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'list';
$handler->display->display_options['style_options']['row_class'] = 'media-item';
$handler->display->display_options['style_options']['default_row_class'] = FALSE;
$handler->display->display_options['style_options']['row_class_special'] = FALSE;
$handler->display->display_options['style_options']['class'] = 'media-items';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['inline'] = array(
    'field_mediaarticle_publisher' => 'field_mediaarticle_publisher',
    'field_mediaarticle_date' => 'field_mediaarticle_date',
);
$handler->display->display_options['row_options']['separator'] = '|';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
);
$handler->display->display_options['defaults']['filters'] = FALSE;
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
    'media_article' => 'media_article',
);
$handler->display->display_options['filters']['type']['group'] = 1;
$handler->display->display_options['path'] = 'media-articles';

/* Display: Internet Sales Tax */
$handler = $view->new_display('block', 'Internet Sales Tax', 'block_4');
$handler->display->display_options['defaults']['use_more'] = FALSE;
$handler->display->display_options['defaults']['use_more_always'] = FALSE;
$handler->display->display_options['defaults']['use_more_always'] = FALSE;
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['defaults']['use_more_text'] = FALSE;
$handler->display->display_options['use_more_text'] = 'Read more';
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '5';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'list';
$handler->display->display_options['style_options']['row_class'] = 'media-item';
$handler->display->display_options['style_options']['default_row_class'] = FALSE;
$handler->display->display_options['style_options']['row_class_special'] = FALSE;
$handler->display->display_options['style_options']['class'] = 'media-items';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['inline'] = array(
    'field_mediaarticle_publisher' => 'field_mediaarticle_publisher',
    'field_mediaarticle_date' => 'field_mediaarticle_date',
);
$handler->display->display_options['row_options']['separator'] = '|';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: Content: Sticky */
$handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
$handler->display->display_options['sorts']['sticky']['table'] = 'node';
$handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
$handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
/* Sort criterion: Content: Date (field_mediaarticle_date) */
$handler->display->display_options['sorts']['field_mediaarticle_date_value']['id'] = 'field_mediaarticle_date_value';
$handler->display->display_options['sorts']['field_mediaarticle_date_value']['table'] = 'field_data_field_mediaarticle_date';
$handler->display->display_options['sorts']['field_mediaarticle_date_value']['field'] = 'field_mediaarticle_date_value';
$handler->display->display_options['sorts']['field_mediaarticle_date_value']['order'] = 'DESC';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
);
$handler->display->display_options['defaults']['filters'] = FALSE;
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
    'media_article' => 'media_article',
);
$handler->display->display_options['filters']['type']['group'] = 1;
/* Filter criterion: Content: Region (field_taxonomy_region) */
$handler->display->display_options['filters']['field_taxonomy_region_tid']['id'] = 'field_taxonomy_region_tid';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['table'] = 'field_data_field_taxonomy_region';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['field'] = 'field_taxonomy_region_tid';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['value'] = array(
    1 => '1',
);
$handler->display->display_options['filters']['field_taxonomy_region_tid']['group'] = 1;
$handler->display->display_options['filters']['field_taxonomy_region_tid']['type'] = 'select';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['vocabulary'] = 'region';
/* Filter criterion: Content: Related Issue (field_mediaarticle_issue) */
$handler->display->display_options['filters']['field_mediaarticle_issue_nid']['id'] = 'field_mediaarticle_issue_nid';
$handler->display->display_options['filters']['field_mediaarticle_issue_nid']['table'] = 'field_data_field_mediaarticle_issue';
$handler->display->display_options['filters']['field_mediaarticle_issue_nid']['field'] = 'field_mediaarticle_issue_nid';
$handler->display->display_options['filters']['field_mediaarticle_issue_nid']['value'] = array(
    968 => '968',
);
$handler->display->display_options['filters']['field_mediaarticle_issue_nid']['group'] = 1;

/* Display: SBAN in the Media */
$handler = $view->new_display('block', 'SBAN in the Media', 'block_1');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Members in the Media';
$handler->display->display_options['defaults']['use_more'] = FALSE;
$handler->display->display_options['defaults']['use_more_always'] = FALSE;
$handler->display->display_options['defaults']['use_more_always'] = FALSE;
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['defaults']['use_more_text'] = FALSE;
$handler->display->display_options['use_more_text'] = 'Read more';
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '5';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'list';
$handler->display->display_options['style_options']['row_class'] = 'media-item';
$handler->display->display_options['style_options']['default_row_class'] = FALSE;
$handler->display->display_options['style_options']['row_class_special'] = FALSE;
$handler->display->display_options['style_options']['class'] = 'media-items';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['inline'] = array(
    'field_mediaarticle_publisher' => 'field_mediaarticle_publisher',
    'field_mediaarticle_date' => 'field_mediaarticle_date',
);
$handler->display->display_options['row_options']['separator'] = '|';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['header'] = FALSE;
/* Header: Global: Text area */
$handler->display->display_options['header']['area']['id'] = 'area';
$handler->display->display_options['header']['area']['table'] = 'views';
$handler->display->display_options['header']['area']['field'] = 'area';
$handler->display->display_options['header']['area']['content'] = '<div class="head-section">
            <p>One of the many benefits of becoming a member of eBay’s Small Business Ambassador Network and working with eBay’s Government Relations team is the opportunity for your business to be featured in the media. Whether it’s on public policy issues or business issues, we’re always looking for opportunities to highlight our many Ambassadors in the media. Here are some recent examples:</p>
        </div>';
$handler->display->display_options['header']['area']['format'] = 'filtered_html';
$handler->display->display_options['defaults']['relationships'] = FALSE;
/* Relationship: Content: Related SBAN Member (field_mediaarticle_rel_member) */
$handler->display->display_options['relationships']['field_mediaarticle_rel_member_nid']['id'] = 'field_mediaarticle_rel_member_nid';
$handler->display->display_options['relationships']['field_mediaarticle_rel_member_nid']['table'] = 'field_data_field_mediaarticle_rel_member';
$handler->display->display_options['relationships']['field_mediaarticle_rel_member_nid']['field'] = 'field_mediaarticle_rel_member_nid';
$handler->display->display_options['relationships']['field_mediaarticle_rel_member_nid']['delta'] = '-1';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Link */
$handler->display->display_options['fields']['field_mediaarticle_link']['id'] = 'field_mediaarticle_link';
$handler->display->display_options['fields']['field_mediaarticle_link']['table'] = 'field_data_field_mediaarticle_link';
$handler->display->display_options['fields']['field_mediaarticle_link']['field'] = 'field_mediaarticle_link';
$handler->display->display_options['fields']['field_mediaarticle_link']['label'] = '';
$handler->display->display_options['fields']['field_mediaarticle_link']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_mediaarticle_link']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_mediaarticle_link']['click_sort_column'] = 'url';
$handler->display->display_options['fields']['field_mediaarticle_link']['type'] = 'link_plain';
/* Field: Content: Headline */
$handler->display->display_options['fields']['field_mediaarticle_headline']['id'] = 'field_mediaarticle_headline';
$handler->display->display_options['fields']['field_mediaarticle_headline']['table'] = 'field_data_field_mediaarticle_headline';
$handler->display->display_options['fields']['field_mediaarticle_headline']['field'] = 'field_mediaarticle_headline';
$handler->display->display_options['fields']['field_mediaarticle_headline']['label'] = '';
$handler->display->display_options['fields']['field_mediaarticle_headline']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_mediaarticle_headline']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['field_mediaarticle_headline']['alter']['text'] = '<a href="[field_mediaarticle_link]" target="_blank">[field_mediaarticle_headline]</a>';
$handler->display->display_options['fields']['field_mediaarticle_headline']['alter']['path'] = '[link]';
$handler->display->display_options['fields']['field_mediaarticle_headline']['element_type'] = 'h3';
$handler->display->display_options['fields']['field_mediaarticle_headline']['element_class'] = 'media-headline';
$handler->display->display_options['fields']['field_mediaarticle_headline']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_mediaarticle_headline']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_mediaarticle_headline']['element_default_classes'] = FALSE;
/* Field: Content: Publisher */
$handler->display->display_options['fields']['field_mediaarticle_publisher']['id'] = 'field_mediaarticle_publisher';
$handler->display->display_options['fields']['field_mediaarticle_publisher']['table'] = 'field_data_field_mediaarticle_publisher';
$handler->display->display_options['fields']['field_mediaarticle_publisher']['field'] = 'field_mediaarticle_publisher';
$handler->display->display_options['fields']['field_mediaarticle_publisher']['label'] = '';
$handler->display->display_options['fields']['field_mediaarticle_publisher']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_mediaarticle_publisher']['element_type'] = '0';
$handler->display->display_options['fields']['field_mediaarticle_publisher']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_mediaarticle_publisher']['element_wrapper_type'] = 'p';
$handler->display->display_options['fields']['field_mediaarticle_publisher']['element_wrapper_class'] = 'media-publisher';
$handler->display->display_options['fields']['field_mediaarticle_publisher']['element_default_classes'] = FALSE;
/* Field: Content: Date */
$handler->display->display_options['fields']['field_mediaarticle_date']['id'] = 'field_mediaarticle_date';
$handler->display->display_options['fields']['field_mediaarticle_date']['table'] = 'field_data_field_mediaarticle_date';
$handler->display->display_options['fields']['field_mediaarticle_date']['field'] = 'field_mediaarticle_date';
$handler->display->display_options['fields']['field_mediaarticle_date']['label'] = '';
$handler->display->display_options['fields']['field_mediaarticle_date']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_mediaarticle_date']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['field_mediaarticle_date']['alter']['text'] = '<p class="media-publisher-date">[field_mediaarticle_publisher] | [field_mediaarticle_date]</p>';
$handler->display->display_options['fields']['field_mediaarticle_date']['element_type'] = '0';
$handler->display->display_options['fields']['field_mediaarticle_date']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_mediaarticle_date']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_mediaarticle_date']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_mediaarticle_date']['settings'] = array(
    'format_type' => 'custom',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => '',
);
/* Field: Content: Photo */
$handler->display->display_options['fields']['field_member_photo']['id'] = 'field_member_photo';
$handler->display->display_options['fields']['field_member_photo']['table'] = 'field_data_field_member_photo';
$handler->display->display_options['fields']['field_member_photo']['field'] = 'field_member_photo';
$handler->display->display_options['fields']['field_member_photo']['relationship'] = 'field_mediaarticle_rel_member_nid';
$handler->display->display_options['fields']['field_member_photo']['label'] = '';
$handler->display->display_options['fields']['field_member_photo']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_member_photo']['element_type'] = '0';
$handler->display->display_options['fields']['field_member_photo']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_member_photo']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_member_photo']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_member_photo']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_member_photo']['settings'] = array(
    'image_style' => 'ems2015_-_featured_member_thumbnail__200x200_',
    'image_link' => '',
);
$handler->display->display_options['fields']['field_member_photo']['field_api_classes'] = TRUE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['relationship'] = 'field_mediaarticle_rel_member_nid';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['exclude'] = TRUE;
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Content: Business Name */
$handler->display->display_options['fields']['field_member_business_name']['id'] = 'field_member_business_name';
$handler->display->display_options['fields']['field_member_business_name']['table'] = 'field_data_field_member_business_name';
$handler->display->display_options['fields']['field_member_business_name']['field'] = 'field_member_business_name';
$handler->display->display_options['fields']['field_member_business_name']['relationship'] = 'field_mediaarticle_rel_member_nid';
$handler->display->display_options['fields']['field_member_business_name']['label'] = '';
$handler->display->display_options['fields']['field_member_business_name']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_member_business_name']['element_type'] = '0';
$handler->display->display_options['fields']['field_member_business_name']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_member_business_name']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_member_business_name']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_member_business_name']['field_api_classes'] = TRUE;
/* Field: Content: Business Location */
$handler->display->display_options['fields']['field_member_business_location']['id'] = 'field_member_business_location';
$handler->display->display_options['fields']['field_member_business_location']['table'] = 'field_data_field_member_business_location';
$handler->display->display_options['fields']['field_member_business_location']['field'] = 'field_member_business_location';
$handler->display->display_options['fields']['field_member_business_location']['relationship'] = 'field_mediaarticle_rel_member_nid';
$handler->display->display_options['fields']['field_member_business_location']['label'] = '';
$handler->display->display_options['fields']['field_member_business_location']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_member_business_location']['element_type'] = '0';
$handler->display->display_options['fields']['field_member_business_location']['element_label_type'] = '0';
$handler->display->display_options['fields']['field_member_business_location']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_member_business_location']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_member_business_location']['element_default_classes'] = FALSE;
/* Field: Global: Custom text */
$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
$handler->display->display_options['fields']['nothing']['table'] = 'views';
$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing']['label'] = '';
$handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="row sban-media-wrapper">
            <div class="sban-img">
                <div class="sban-media-photo">[field_member_photo]</div>
            </div>
            <div class="sban-content">
                <div class="sban-media-headline">[field_mediaarticle_headline]</div>
                <div class="sban-media-date">[field_mediaarticle_date]</div>
                <div class="sban-media-text">
                    <div class="sban-media-title">[title]</div>
                    <div class="sban-media-name">[field_member_business_name]</div>
                    <div class="sban-media-location">[field_member_business_location]</div>
                </div>
            </div>
        </div>';
$handler->display->display_options['fields']['nothing']['element_type'] = '0';
$handler->display->display_options['fields']['nothing']['element_label_type'] = '0';
$handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['nothing']['element_wrapper_type'] = '0';
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: Content: Date (field_mediaarticle_date) */
$handler->display->display_options['sorts']['field_mediaarticle_date_value']['id'] = 'field_mediaarticle_date_value';
$handler->display->display_options['sorts']['field_mediaarticle_date_value']['table'] = 'field_data_field_mediaarticle_date';
$handler->display->display_options['sorts']['field_mediaarticle_date_value']['field'] = 'field_mediaarticle_date_value';
$handler->display->display_options['sorts']['field_mediaarticle_date_value']['order'] = 'DESC';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
);
$handler->display->display_options['defaults']['filters'] = FALSE;
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
    'media_article' => 'media_article',
);
$handler->display->display_options['filters']['type']['group'] = 1;
/* Filter criterion: Content: Related SBAN Member (field_mediaarticle_rel_member) */
$handler->display->display_options['filters']['field_mediaarticle_rel_member_nid']['id'] = 'field_mediaarticle_rel_member_nid';
$handler->display->display_options['filters']['field_mediaarticle_rel_member_nid']['table'] = 'field_data_field_mediaarticle_rel_member';
$handler->display->display_options['filters']['field_mediaarticle_rel_member_nid']['field'] = 'field_mediaarticle_rel_member_nid';
$handler->display->display_options['filters']['field_mediaarticle_rel_member_nid']['operator'] = 'not empty';

/* Display: Trade */
$handler = $view->new_display('block', 'Trade', 'block_2');
$handler->display->display_options['defaults']['use_more'] = FALSE;
$handler->display->display_options['defaults']['use_more_always'] = FALSE;
$handler->display->display_options['defaults']['use_more_always'] = FALSE;
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['defaults']['use_more_text'] = FALSE;
$handler->display->display_options['use_more_text'] = 'Read more';
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '5';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'list';
$handler->display->display_options['style_options']['row_class'] = 'media-item';
$handler->display->display_options['style_options']['default_row_class'] = FALSE;
$handler->display->display_options['style_options']['row_class_special'] = FALSE;
$handler->display->display_options['style_options']['class'] = 'media-items';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['inline'] = array(
    'field_mediaarticle_publisher' => 'field_mediaarticle_publisher',
    'field_mediaarticle_date' => 'field_mediaarticle_date',
);
$handler->display->display_options['row_options']['separator'] = '|';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: Content: Sticky */
$handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
$handler->display->display_options['sorts']['sticky']['table'] = 'node';
$handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
$handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
/* Sort criterion: Content: Date (field_mediaarticle_date) */
$handler->display->display_options['sorts']['field_mediaarticle_date_value']['id'] = 'field_mediaarticle_date_value';
$handler->display->display_options['sorts']['field_mediaarticle_date_value']['table'] = 'field_data_field_mediaarticle_date';
$handler->display->display_options['sorts']['field_mediaarticle_date_value']['field'] = 'field_mediaarticle_date_value';
$handler->display->display_options['sorts']['field_mediaarticle_date_value']['order'] = 'DESC';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
);
$handler->display->display_options['defaults']['filters'] = FALSE;
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
    'media_article' => 'media_article',
);
$handler->display->display_options['filters']['type']['group'] = 1;
/* Filter criterion: Content: Region (field_taxonomy_region) */
$handler->display->display_options['filters']['field_taxonomy_region_tid']['id'] = 'field_taxonomy_region_tid';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['table'] = 'field_data_field_taxonomy_region';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['field'] = 'field_taxonomy_region_tid';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['value'] = array(
    1 => '1',
);
$handler->display->display_options['filters']['field_taxonomy_region_tid']['group'] = 1;
$handler->display->display_options['filters']['field_taxonomy_region_tid']['type'] = 'select';
$handler->display->display_options['filters']['field_taxonomy_region_tid']['vocabulary'] = 'region';
/* Filter criterion: Content: Related Issue (field_mediaarticle_issue) */
$handler->display->display_options['filters']['field_mediaarticle_issue_nid']['id'] = 'field_mediaarticle_issue_nid';
$handler->display->display_options['filters']['field_mediaarticle_issue_nid']['table'] = 'field_data_field_mediaarticle_issue';
$handler->display->display_options['filters']['field_mediaarticle_issue_nid']['field'] = 'field_mediaarticle_issue_nid';
$handler->display->display_options['filters']['field_mediaarticle_issue_nid']['value'] = array(
    982 => '982',
);
$handler->display->display_options['filters']['field_mediaarticle_issue_nid']['group'] = 1;
$translatables['mediaarticles'] = array(
    t('Master'),
    t('In the Press'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('<a href="[field_mediaarticle_link]" target="_blank">[field_mediaarticle_headline]</a>'),
    t('<p class="media-publisher-date">[field_mediaarticle_publisher] | [field_mediaarticle_date]</p>'),
    t('In The Press Block'),
    t('Read more'),
    t('Page'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Internet Sales Tax'),
    t('SBAN in the Media'),
    t('Members in the Media'),
    t('<div class="head-section">
            <p>One of the many benefits of becoming a member of eBay’s Small Business Ambassador Network and working with eBay’s Government Relations team is the opportunity for your business to be featured in the media. Whether it’s on public policy issues or business issues, we’re always looking for opportunities to highlight our many Ambassadors in the media. Here are some recent examples:</p>
        </div>'),
    t('field_mediaarticle_rel_member'),
    t('<div class="row sban-media-wrapper">
            <div class="sban-img">
                <div class="sban-media-photo">[field_member_photo]</div>
            </div>
            <div class="sban-content">
                <div class="sban-media-headline">[field_mediaarticle_headline]</div>
                <div class="sban-media-date">[field_mediaarticle_date]</div>
                <div class="sban-media-text">
                    <div class="sban-media-title">[title]</div>
                    <div class="sban-media-name">[field_member_business_name]</div>
                    <div class="sban-media-location">[field_member_business_location]</div>
                </div>
            </div>
        </div>'),
    t('Trade'),
);