<?php

$view = new view();
$view->name = 'video_submissions';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'Video Submissions';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'List Video Submissions';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'edit any video_submission content';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['row_plugin'] = 'node';
/* Relationship: Content: Vote results */
$handler->display->display_options['relationships']['votingapi_cache']['id'] = 'votingapi_cache';
$handler->display->display_options['relationships']['votingapi_cache']['table'] = 'node';
$handler->display->display_options['relationships']['votingapi_cache']['field'] = 'votingapi_cache';
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
/* Sort criterion: Content: Post date */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'node';
$handler->display->display_options['sorts']['created']['field'] = 'created';
$handler->display->display_options['sorts']['created']['order'] = 'DESC';
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = '0';
$handler->display->display_options['filters']['status']['group'] = 0;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
    'video_submission' => 'video_submission',
);

/* Display: List Video Submissions */
$handler = $view->new_display('page', 'List Video Submissions', 'page_1');
$handler->display->display_options['defaults']['relationships'] = FALSE;
$handler->display->display_options['path'] = 'submissions/videos';

/* Display: List Video Submissions (results) */
$handler = $view->new_display('page', 'List Video Submissions (results)', 'page_2');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Video Submission Results';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['grouping'] = '';
$handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'value' => 'value',
    'value_1' => 'value_1',
    'value_2' => 'value_2',
    'value_3' => 'value_3',
    'field_submission_video_file' => 'field_submission_video_file',
);
$handler->display->display_options['style_options']['default'] = 'value';
$handler->display->display_options['style_options']['info'] = array(
    'title' => array(
        'sortable' => 0,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
    ),
    'value' => array(
        'sortable' => 1,
        'default_sort_order' => 'desc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
    ),
    'value_1' => array(
        'sortable' => 1,
        'default_sort_order' => 'desc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
    ),
    'value_2' => array(
        'sortable' => 1,
        'default_sort_order' => 'desc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
    ),
    'value_3' => array(
        'sortable' => 1,
        'default_sort_order' => 'desc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
    ),
    'field_submission_video_file' => array(
        'sortable' => 0,
        'default_sort_order' => 'desc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
    ),
);
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['relationships'] = FALSE;
/* Relationship: Content: Vote results */
$handler->display->display_options['relationships']['votingapi_cache']['id'] = 'votingapi_cache';
$handler->display->display_options['relationships']['votingapi_cache']['table'] = 'node';
$handler->display->display_options['relationships']['votingapi_cache']['field'] = 'votingapi_cache';
$handler->display->display_options['relationships']['votingapi_cache']['label'] = 'Vote results (Details)';
$handler->display->display_options['relationships']['votingapi_cache']['votingapi'] = array(
    'value_type' => 'points',
    'tag' => 'details_vote',
    'function' => 'sum',
);
/* Relationship: Content: Vote results */
$handler->display->display_options['relationships']['votingapi_cache_1']['id'] = 'votingapi_cache_1';
$handler->display->display_options['relationships']['votingapi_cache_1']['table'] = 'node';
$handler->display->display_options['relationships']['votingapi_cache_1']['field'] = 'votingapi_cache';
$handler->display->display_options['relationships']['votingapi_cache_1']['label'] = 'Vote results (creativity)';
$handler->display->display_options['relationships']['votingapi_cache_1']['votingapi'] = array(
    'value_type' => 'points',
    'tag' => 'creativity_vote',
    'function' => 'sum',
);
/* Relationship: Content: Vote results */
$handler->display->display_options['relationships']['votingapi_cache_2']['id'] = 'votingapi_cache_2';
$handler->display->display_options['relationships']['votingapi_cache_2']['table'] = 'node';
$handler->display->display_options['relationships']['votingapi_cache_2']['field'] = 'votingapi_cache';
$handler->display->display_options['relationships']['votingapi_cache_2']['label'] = 'Vote results (Coherence)';
$handler->display->display_options['relationships']['votingapi_cache_2']['votingapi'] = array(
    'value_type' => 'points',
    'tag' => 'coherence_vote',
    'function' => 'sum',
);
/* Relationship: Content: Vote results */
$handler->display->display_options['relationships']['votingapi_cache_3']['id'] = 'votingapi_cache_3';
$handler->display->display_options['relationships']['votingapi_cache_3']['table'] = 'node';
$handler->display->display_options['relationships']['votingapi_cache_3']['field'] = 'votingapi_cache';
$handler->display->display_options['relationships']['votingapi_cache_3']['label'] = 'Vote results (script)';
$handler->display->display_options['relationships']['votingapi_cache_3']['votingapi'] = array(
    'value_type' => 'points',
    'tag' => 'script_vote',
    'function' => 'sum',
);
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
/* Field: Vote results: Value */
$handler->display->display_options['fields']['value']['id'] = 'value';
$handler->display->display_options['fields']['value']['table'] = 'votingapi_cache';
$handler->display->display_options['fields']['value']['field'] = 'value';
$handler->display->display_options['fields']['value']['relationship'] = 'votingapi_cache';
$handler->display->display_options['fields']['value']['label'] = 'Details';
$handler->display->display_options['fields']['value']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['value']['precision'] = '0';
/* Field: Vote results: Value */
$handler->display->display_options['fields']['value_1']['id'] = 'value_1';
$handler->display->display_options['fields']['value_1']['table'] = 'votingapi_cache';
$handler->display->display_options['fields']['value_1']['field'] = 'value';
$handler->display->display_options['fields']['value_1']['relationship'] = 'votingapi_cache_1';
$handler->display->display_options['fields']['value_1']['label'] = 'Creativity';
$handler->display->display_options['fields']['value_1']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['value_1']['precision'] = '0';
/* Field: Vote results: Value */
$handler->display->display_options['fields']['value_2']['id'] = 'value_2';
$handler->display->display_options['fields']['value_2']['table'] = 'votingapi_cache';
$handler->display->display_options['fields']['value_2']['field'] = 'value';
$handler->display->display_options['fields']['value_2']['relationship'] = 'votingapi_cache_2';
$handler->display->display_options['fields']['value_2']['label'] = 'Coherence';
$handler->display->display_options['fields']['value_2']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['value_2']['precision'] = '0';
/* Field: Vote results: Value */
$handler->display->display_options['fields']['value_3']['id'] = 'value_3';
$handler->display->display_options['fields']['value_3']['table'] = 'votingapi_cache';
$handler->display->display_options['fields']['value_3']['field'] = 'value';
$handler->display->display_options['fields']['value_3']['relationship'] = 'votingapi_cache_3';
$handler->display->display_options['fields']['value_3']['label'] = 'Script';
$handler->display->display_options['fields']['value_3']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['value_3']['precision'] = '0';
/* Field: Content: Video File */
$handler->display->display_options['fields']['field_submission_video_file']['id'] = 'field_submission_video_file';
$handler->display->display_options['fields']['field_submission_video_file']['table'] = 'field_data_field_submission_video_file';
$handler->display->display_options['fields']['field_submission_video_file']['field'] = 'field_submission_video_file';
$handler->display->display_options['fields']['field_submission_video_file']['label'] = 'Video Submission';
$handler->display->display_options['fields']['field_submission_video_file']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_submission_video_file']['type'] = 'video_formatter_thumbnail';
$handler->display->display_options['fields']['field_submission_video_file']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
);
$handler->display->display_options['path'] = 'submissions/videos/results';
$translatables['video_submissions'] = array(
    t('Master'),
    t('List Video Submissions'),
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
    t('Vote results'),
    t('List Video Submissions (results)'),
    t('Video Submission Results'),
    t('Vote results (Details)'),
    t('Vote results (creativity)'),
    t('Vote results (Coherence)'),
    t('Vote results (script)'),
    t('Title'),
    t('Details'),
    t('.'),
    t(','),
    t('Creativity'),
    t('Coherence'),
    t('Script'),
    t('Video Submission'),
);