<?php

$view = new view();
$view->name = 'policy_papers';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'Policy Papers';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Policy Papers';
$handler->display->display_options['use_more'] = TRUE;
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['use_more_text'] = 'View all';
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'mini';
$handler->display->display_options['pager']['options']['items_per_page'] = '20';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'list';
$handler->display->display_options['row_plugin'] = 'fields';
/* Field: Content: File */
$handler->display->display_options['fields']['field_policy_file']['id'] = 'field_policy_file';
$handler->display->display_options['fields']['field_policy_file']['table'] = 'field_data_field_policy_file';
$handler->display->display_options['fields']['field_policy_file']['field'] = 'field_policy_file';
$handler->display->display_options['fields']['field_policy_file']['label'] = '';
$handler->display->display_options['fields']['field_policy_file']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_policy_file']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_policy_file']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_policy_file']['delta_offset'] = '0';
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['path'] = '[field_policy_file]';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
/* Field: Content: Post date */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'node';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['label'] = '';
$handler->display->display_options['fields']['created']['exclude'] = TRUE;
$handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['created']['date_format'] = 'custom';
$handler->display->display_options['fields']['created']['custom_date_format'] = 'F j, Y';
/* Sort criterion: Content: Updated date */
$handler->display->display_options['sorts']['changed']['id'] = 'changed';
$handler->display->display_options['sorts']['changed']['table'] = 'node';
$handler->display->display_options['sorts']['changed']['field'] = 'changed';
$handler->display->display_options['sorts']['changed']['order'] = 'DESC';
$handler->display->display_options['sorts']['changed']['granularity'] = 'minute';
/* Sort criterion: Content: Post date */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'node';
$handler->display->display_options['sorts']['created']['field'] = 'created';
$handler->display->display_options['sorts']['created']['order'] = 'DESC';
$handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
);
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
    'policy_paper' => 'policy_paper',
);
$handler->display->display_options['filters']['type']['group'] = 1;
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 1;
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

/* Display: Block */
$handler = $view->new_display('block', 'Block', 'block_1');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Recent Policy Papers';
$handler->display->display_options['defaults']['use_more'] = FALSE;
$handler->display->display_options['defaults']['use_more_always'] = FALSE;
$handler->display->display_options['defaults']['use_more_always'] = FALSE;
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['defaults']['use_more_text'] = FALSE;
$handler->display->display_options['use_more_text'] = 'View all';
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '5';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['footer'] = FALSE;
/* Footer: Global: Text area */
$handler->display->display_options['footer']['area']['id'] = 'area';
$handler->display->display_options['footer']['area']['table'] = 'views';
$handler->display->display_options['footer']['area']['field'] = 'area';
$handler->display->display_options['footer']['area']['content'] = '<a href="/policy-papers/europe">View All</a>';
$handler->display->display_options['footer']['area']['format'] = 'filtered_html';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: File */
$handler->display->display_options['fields']['field_policy_file']['id'] = 'field_policy_file';
$handler->display->display_options['fields']['field_policy_file']['table'] = 'field_data_field_policy_file';
$handler->display->display_options['fields']['field_policy_file']['field'] = 'field_policy_file';
$handler->display->display_options['fields']['field_policy_file']['label'] = '';
$handler->display->display_options['fields']['field_policy_file']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_policy_file']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_policy_file']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_policy_file']['delta_offset'] = '0';
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['path'] = '[field_policy_file]';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
/* Field: Content: Post date */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'node';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['label'] = '';
$handler->display->display_options['fields']['created']['exclude'] = TRUE;
$handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['created']['date_format'] = 'custom';
$handler->display->display_options['fields']['created']['custom_date_format'] = 'F j, Y';
/* Field: Content: Published Date */
$handler->display->display_options['fields']['field_policy_published_date']['id'] = 'field_policy_published_date';
$handler->display->display_options['fields']['field_policy_published_date']['table'] = 'field_data_field_policy_published_date';
$handler->display->display_options['fields']['field_policy_published_date']['field'] = 'field_policy_published_date';
$handler->display->display_options['fields']['field_policy_published_date']['label'] = '';
$handler->display->display_options['fields']['field_policy_published_date']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['field_policy_published_date']['alter']['text'] = 'Published Date: [field_policy_published_date] ';
$handler->display->display_options['fields']['field_policy_published_date']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_policy_published_date']['hide_empty'] = TRUE;
$handler->display->display_options['fields']['field_policy_published_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => '',
);

/* Display: Policy Papers Page */
$handler = $view->new_display('page', 'Policy Papers Page', 'page_2');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Policy Papers';
$handler->display->display_options['defaults']['css_class'] = FALSE;
$handler->display->display_options['css_class'] = 'bottom-block';
$handler->display->display_options['defaults']['use_ajax'] = FALSE;
$handler->display->display_options['use_ajax'] = TRUE;
$handler->display->display_options['defaults']['query'] = FALSE;
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['distinct'] = TRUE;
$handler->display->display_options['defaults']['exposed_form'] = FALSE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
$handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'mini';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['header'] = FALSE;
/* Header: Global: Block area */
$handler->display->display_options['header']['block']['id'] = 'block';
$handler->display->display_options['header']['block']['table'] = 'views';
$handler->display->display_options['header']['block']['field'] = 'block';
$handler->display->display_options['header']['block']['block_to_insert'] = 'views:mapsslider-block_1';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: File */
$handler->display->display_options['fields']['field_policy_file']['id'] = 'field_policy_file';
$handler->display->display_options['fields']['field_policy_file']['table'] = 'field_data_field_policy_file';
$handler->display->display_options['fields']['field_policy_file']['field'] = 'field_policy_file';
$handler->display->display_options['fields']['field_policy_file']['label'] = '';
$handler->display->display_options['fields']['field_policy_file']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_policy_file']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_policy_file']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_policy_file']['delta_offset'] = '0';
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['path'] = '[field_policy_file]';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
/* Field: Content: Post date */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'node';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['label'] = '';
$handler->display->display_options['fields']['created']['exclude'] = TRUE;
$handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['created']['date_format'] = 'custom';
$handler->display->display_options['fields']['created']['custom_date_format'] = 'F j, Y';
/* Field: Content: Region */
$handler->display->display_options['fields']['field_policy_region']['id'] = 'field_policy_region';
$handler->display->display_options['fields']['field_policy_region']['table'] = 'field_data_field_policy_region';
$handler->display->display_options['fields']['field_policy_region']['field'] = 'field_policy_region';
$handler->display->display_options['fields']['field_policy_region']['label'] = '';
$handler->display->display_options['fields']['field_policy_region']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['field_policy_region']['alter']['text'] = '<h2>EXPLORE OUR POLICY PAPERS </h2>
[field_policy_region]';
$handler->display->display_options['fields']['field_policy_region']['alter']['strip_tags'] = TRUE;
$handler->display->display_options['fields']['field_policy_region']['alter']['preserve_tags'] = '<h2></h2>';
$handler->display->display_options['fields']['field_policy_region']['element_type'] = '0';
$handler->display->display_options['fields']['field_policy_region']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_policy_region']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_policy_region']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_policy_region']['type'] = 'taxonomy_term_reference_plain';
$handler->display->display_options['fields']['field_policy_region']['delta_offset'] = '0';
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: Content: Published Date (field_policy_published_date) */
$handler->display->display_options['sorts']['field_policy_published_date_value']['id'] = 'field_policy_published_date_value';
$handler->display->display_options['sorts']['field_policy_published_date_value']['table'] = 'field_data_field_policy_published_date';
$handler->display->display_options['sorts']['field_policy_published_date_value']['field'] = 'field_policy_published_date_value';
$handler->display->display_options['sorts']['field_policy_published_date_value']['order'] = 'DESC';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
);
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
    'policy_paper' => 'policy_paper',
);
$handler->display->display_options['filters']['type']['group'] = 1;
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 1;
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: Content: Region (field_policy_region) */
$handler->display->display_options['filters']['field_policy_region_tid']['id'] = 'field_policy_region_tid';
$handler->display->display_options['filters']['field_policy_region_tid']['table'] = 'field_data_field_policy_region';
$handler->display->display_options['filters']['field_policy_region_tid']['field'] = 'field_policy_region_tid';
$handler->display->display_options['filters']['field_policy_region_tid']['value'] = array(
    6 => '6',
    9 => '9',
    2 => '2',
    4 => '4',
    3 => '3',
    7 => '7',
    8 => '8',
);
$handler->display->display_options['filters']['field_policy_region_tid']['expose']['operator_id'] = 'field_policy_region_tid_op';
$handler->display->display_options['filters']['field_policy_region_tid']['expose']['label'] = 'Region';
$handler->display->display_options['filters']['field_policy_region_tid']['expose']['operator'] = 'field_policy_region_tid_op';
$handler->display->display_options['filters']['field_policy_region_tid']['expose']['identifier'] = 'field_policy_region_tid';
$handler->display->display_options['filters']['field_policy_region_tid']['expose']['remember_roles'] = array(
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
$handler->display->display_options['filters']['field_policy_region_tid']['type'] = 'select';
$handler->display->display_options['filters']['field_policy_region_tid']['vocabulary'] = 'region';
/* Filter criterion: Region (field_policy_region) (selective) */
$handler->display->display_options['filters']['field_policy_region_tid_selective']['id'] = 'field_policy_region_tid_selective';
$handler->display->display_options['filters']['field_policy_region_tid_selective']['table'] = 'field_data_field_policy_region';
$handler->display->display_options['filters']['field_policy_region_tid_selective']['field'] = 'field_policy_region_tid_selective';
$handler->display->display_options['filters']['field_policy_region_tid_selective']['ui_name'] = 'Region (field_policy_region) (selective)';
$handler->display->display_options['filters']['field_policy_region_tid_selective']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_policy_region_tid_selective']['expose']['operator_id'] = '';
$handler->display->display_options['filters']['field_policy_region_tid_selective']['expose']['label'] = 'Region';
$handler->display->display_options['filters']['field_policy_region_tid_selective']['expose']['use_operator'] = TRUE;
$handler->display->display_options['filters']['field_policy_region_tid_selective']['expose']['operator_label'] = 'Region';
$handler->display->display_options['filters']['field_policy_region_tid_selective']['expose']['identifier'] = 'field_policy_region_tid_selective';
$handler->display->display_options['filters']['field_policy_region_tid_selective']['expose']['remember_roles'] = array(
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
$handler->display->display_options['filters']['field_policy_region_tid_selective']['selective_display_field'] = 'field_policy_region';
$handler->display->display_options['filters']['field_policy_region_tid_selective']['selective_items_limit'] = '100';
$handler->display->display_options['metatags'] = array(
    'und' => array(
        'title' => array(
            'value' => '[view:title] | [current-page:pager][site:name]',
            'default' => '[view:title] | [current-page:pager][site:name]',
        ),
        'description' => array(
            'value' => '[view:description]',
            'default' => '[view:description]',
        ),
        'abstract' => array(
            'value' => '',
            'default' => '',
        ),
        'keywords' => array(
            'value' => '',
            'default' => '',
        ),
        'robots' => array(
            'value' => array(
                'index' => 0,
                'follow' => 0,
                'noindex' => 0,
                'nofollow' => 0,
                'noarchive' => 0,
                'nosnippet' => 0,
                'noodp' => 0,
                'noydir' => 0,
                'noimageindex' => 0,
                'notranslate' => 0,
            ),
            'default' => array(
                'index' => 0,
                'follow' => 0,
                'noindex' => 0,
                'nofollow' => 0,
                'noarchive' => 0,
                'nosnippet' => 0,
                'noodp' => 0,
                'noydir' => 0,
                'noimageindex' => 0,
                'notranslate' => 0,
            ),
        ),
        'news_keywords' => array(
            'value' => '',
            'default' => '',
        ),
        'standout' => array(
            'value' => '',
            'default' => '',
        ),
        'rating' => array(
            'value' => '',
        ),
        'referrer' => array(
            'value' => '',
        ),
        'rights' => array(
            'value' => '',
            'default' => '',
        ),
        'image_src' => array(
            'value' => '',
            'default' => '',
        ),
        'canonical' => array(
            'value' => '[view:url]',
            'default' => '[view:url]',
        ),
        'shortlink' => array(
            'value' => '[current-page:url:unaliased]',
            'default' => '[current-page:url:unaliased]',
        ),
        'original-source' => array(
            'value' => '',
            'default' => '',
        ),
        'prev' => array(
            'value' => '',
        ),
        'next' => array(
            'value' => '',
        ),
        'content-language' => array(
            'value' => '',
        ),
        'geo.position' => array(
            'value' => '',
        ),
        'geo.placename' => array(
            'value' => '',
        ),
        'geo.region' => array(
            'value' => '',
        ),
        'icbm' => array(
            'value' => '',
        ),
        'refresh' => array(
            'value' => '',
        ),
        'revisit-after' => array(
            'value' => '',
            'period' => '',
            'default' => '',
        ),
        'pragma' => array(
            'value' => '',
        ),
        'cache-control' => array(
            'value' => '',
        ),
        'expires' => array(
            'value' => '',
        ),
        'fb:admins' => array(
            'value' => '',
            'default' => '',
        ),
        'fb:app_id' => array(
            'value' => '',
            'default' => '',
        ),
        'fb:pages' => array(
            'value' => '',
        ),
        'og:type' => array(
            'value' => 'article',
            'default' => 'article',
        ),
        'og:url' => array(
            'value' => '[current-page:url:absolute]',
            'default' => '[current-page:url:absolute]',
        ),
        'og:title' => array(
            'value' => '[current-page:title]',
            'default' => '[current-page:title]',
        ),
        'og:determiner' => array(
            'value' => '',
        ),
        'og:description' => array(
            'value' => '',
            'default' => '',
        ),
        'og:updated_time' => array(
            'value' => '',
        ),
        'og:see_also' => array(
            'value' => '',
        ),
        'og:image' => array(
            'value' => '',
            'default' => '',
        ),
        'og:image:url' => array(
            'value' => '',
        ),
        'og:image:secure_url' => array(
            'value' => 'http://ebaymainstreet.com/sites/all/themes/mainstreet2013/images/ebay_ms_logo.png',
            'default' => 'http://ebaymainstreet.com/sites/all/themes/mainstreet2013/images/ebay_ms_logo.png',
        ),
        'og:image:type' => array(
            'value' => '',
        ),
        'og:image:width' => array(
            'value' => '',
        ),
        'og:image:height' => array(
            'value' => '',
        ),
        'og:latitude' => array(
            'value' => '',
            'default' => '',
        ),
        'og:longitude' => array(
            'value' => '',
            'default' => '',
        ),
        'og:street_address' => array(
            'value' => '',
            'default' => '',
        ),
        'og:locality' => array(
            'value' => '',
            'default' => '',
        ),
        'og:region' => array(
            'value' => '',
            'default' => '',
        ),
        'og:postal_code' => array(
            'value' => '',
            'default' => '',
        ),
        'og:country_name' => array(
            'value' => '',
            'default' => '',
        ),
        'og:email' => array(
            'value' => '',
            'default' => '',
        ),
        'og:phone_number' => array(
            'value' => '',
            'default' => '',
        ),
        'og:fax_number' => array(
            'value' => '',
            'default' => '',
        ),
        'og:locale' => array(
            'value' => '',
            'default' => '',
        ),
        'og:locale:alternate' => array(
            'value' => '',
        ),
        'article:author' => array(
            'value' => '',
        ),
        'article:publisher' => array(
            'value' => '',
        ),
        'article:section' => array(
            'value' => '',
        ),
        'article:tag' => array(
            'value' => '',
        ),
        'article:published_time' => array(
            'value' => '',
        ),
        'article:modified_time' => array(
            'value' => '',
        ),
        'article:expiration_time' => array(
            'value' => '',
        ),
        'profile:first_name' => array(
            'value' => '',
        ),
        'profile:last_name' => array(
            'value' => '',
        ),
        'profile:username' => array(
            'value' => '',
        ),
        'profile:gender' => array(
            'value' => '',
        ),
        'og:audio' => array(
            'value' => '',
        ),
        'og:audio:secure_url' => array(
            'value' => '',
        ),
        'og:audio:type' => array(
            'value' => '',
        ),
        'book:author' => array(
            'value' => '',
        ),
        'book:isbn' => array(
            'value' => '',
        ),
        'book:release_date' => array(
            'value' => '',
        ),
        'book:tag' => array(
            'value' => '',
        ),
        'og:video:url' => array(
            'value' => '',
            'default' => '',
        ),
        'og:video:secure_url' => array(
            'value' => '',
            'default' => '',
        ),
        'og:video:width' => array(
            'value' => '',
            'default' => '',
        ),
        'og:video:height' => array(
            'value' => '',
            'default' => '',
        ),
        'og:video:type' => array(
            'value' => '',
            'default' => '',
        ),
        'video:actor' => array(
            'value' => '',
        ),
        'video:actor:role' => array(
            'value' => '',
        ),
        'video:director' => array(
            'value' => '',
        ),
        'video:writer' => array(
            'value' => '',
        ),
        'video:duration' => array(
            'value' => '',
        ),
        'video:release_date' => array(
            'value' => '',
        ),
        'video:tag' => array(
            'value' => '',
        ),
        'video:series' => array(
            'value' => '',
        ),
        'twitter:card' => array(
            'value' => 'summary',
            'default' => 'summary',
        ),
        'twitter:creator' => array(
            'value' => '@ebaygr',
            'default' => '@ebaygr',
        ),
        'twitter:creator:id' => array(
            'value' => '49969221',
            'default' => '49969221',
        ),
        'twitter:url' => array(
            'value' => '[current-page:url:absolute]',
            'default' => '[current-page:url:absolute]',
        ),
        'twitter:title' => array(
            'value' => '[site:name]',
            'default' => '[site:name]',
        ),
        'twitter:description' => array(
            'value' => '[site:slogan]',
            'default' => '[site:slogan]',
        ),
        'twitter:image' => array(
            'value' => 'https://pbs.twimg.com/profile_images/622819274147659776/CFP-PVz5.png',
            'default' => '',
        ),
        'twitter:image:width' => array(
            'value' => '',
            'default' => '',
        ),
        'twitter:image:height' => array(
            'value' => '',
            'default' => '',
        ),
        'twitter:image:alt' => array(
            'value' => '',
        ),
        'twitter:image0' => array(
            'value' => '',
            'default' => '',
        ),
        'twitter:image1' => array(
            'value' => '',
            'default' => '',
        ),
        'twitter:image2' => array(
            'value' => '',
            'default' => '',
        ),
        'twitter:image3' => array(
            'value' => '',
            'default' => '',
        ),
        'twitter:player' => array(
            'value' => '',
            'default' => '',
        ),
        'twitter:player:width' => array(
            'value' => '',
            'default' => '',
        ),
        'twitter:player:height' => array(
            'value' => '',
            'default' => '',
        ),
        'twitter:player:stream' => array(
            'value' => '',
            'default' => '',
        ),
        'twitter:player:stream:content_type' => array(
            'value' => '',
            'default' => '',
        ),
        'twitter:app:country' => array(
            'value' => '',
            'default' => '',
        ),
        'twitter:app:name:iphone' => array(
            'value' => '',
        ),
        'twitter:app:id:iphone' => array(
            'value' => '',
            'default' => '',
        ),
        'twitter:app:url:iphone' => array(
            'value' => '',
            'default' => '',
        ),
        'twitter:app:name:ipad' => array(
            'value' => '',
        ),
        'twitter:app:id:ipad' => array(
            'value' => '',
            'default' => '',
        ),
        'twitter:app:url:ipad' => array(
            'value' => '',
            'default' => '',
        ),
        'twitter:app:name:googleplay' => array(
            'value' => '',
        ),
        'twitter:app:id:googleplay' => array(
            'value' => '',
            'default' => '',
        ),
        'twitter:app:url:googleplay' => array(
            'value' => '',
            'default' => '',
        ),
        'twitter:label1' => array(
            'value' => '',
            'default' => '',
        ),
        'twitter:data1' => array(
            'value' => '',
            'default' => '',
        ),
        'twitter:label2' => array(
            'value' => '',
            'default' => '',
        ),
        'twitter:data2' => array(
            'value' => '',
            'default' => '',
        ),
    ),
);
$handler->display->display_options['path'] = 'policy-papers';
$translatables['policy_papers'] = array(
    t('Master'),
    t('Policy Papers'),
    t('View all'),
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
    t('Block'),
    t('Recent Policy Papers'),
    t('<a href="/policy-papers/europe">View All</a>'),
    t('Published Date: [field_policy_published_date] '),
    t('Policy Papers Page'),
    t('more'),
    t('<h2>EXPLORE OUR POLICY PAPERS </h2>
[field_policy_region]'),
    t('Region'),
);