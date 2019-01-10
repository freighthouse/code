<?php

$view = new view();
$view->name = 'latest_tweets';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'twitter';
$view->human_name = 'Latest Tweets';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Latest Tweets';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'none';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '3';
$handler->display->display_options['style_plugin'] = 'list';
$handler->display->display_options['style_options']['grouping'] = '';
$handler->display->display_options['row_plugin'] = 'fields';
/* Header: Global: Text area */
$handler->display->display_options['header']['area']['id'] = 'area';
$handler->display->display_options['header']['area']['table'] = 'views';
$handler->display->display_options['header']['area']['field'] = 'area';
$handler->display->display_options['header']['area']['empty'] = TRUE;
$handler->display->display_options['header']['area']['content'] = '<a href="https://twitter.com/ebaygr" class="btn follow-us">Follow Us</a>';
$handler->display->display_options['header']['area']['format'] = 'full_html';
/* Field: Twitter: Twitter status message ID */
$handler->display->display_options['fields']['twitter_id']['id'] = 'twitter_id';
$handler->display->display_options['fields']['twitter_id']['table'] = 'twitter';
$handler->display->display_options['fields']['twitter_id']['field'] = 'twitter_id';
$handler->display->display_options['fields']['twitter_id']['exclude'] = TRUE;
/* Field: Twitter: Message text */
$handler->display->display_options['fields']['text']['id'] = 'text';
$handler->display->display_options['fields']['text']['table'] = 'twitter';
$handler->display->display_options['fields']['text']['field'] = 'text';
$handler->display->display_options['fields']['text']['label'] = '';
$handler->display->display_options['fields']['text']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['text']['link_urls'] = 1;
$handler->display->display_options['fields']['text']['link_usernames'] = 1;
$handler->display->display_options['fields']['text']['link_hashtags'] = 0;
/* Field: Twitter: Created time */
$handler->display->display_options['fields']['created_time']['id'] = 'created_time';
$handler->display->display_options['fields']['created_time']['table'] = 'twitter';
$handler->display->display_options['fields']['created_time']['field'] = 'created_time';
$handler->display->display_options['fields']['created_time']['label'] = '';
$handler->display->display_options['fields']['created_time']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['created_time']['date_format'] = 'time ago';
/* Sort criterion: Twitter: Created time */
$handler->display->display_options['sorts']['created_time']['id'] = 'created_time';
$handler->display->display_options['sorts']['created_time']['table'] = 'twitter';
$handler->display->display_options['sorts']['created_time']['field'] = 'created_time';
$handler->display->display_options['sorts']['created_time']['order'] = 'DESC';
/* Filter criterion: Twitter Account: Login name */
$handler->display->display_options['filters']['screen_name']['id'] = 'screen_name';
$handler->display->display_options['filters']['screen_name']['table'] = 'twitter_account';
$handler->display->display_options['filters']['screen_name']['field'] = 'screen_name';
$handler->display->display_options['filters']['screen_name']['value'] = 'ebaygr';
$handler->display->display_options['filters']['screen_name']['group'] = '0';

/* Display: Block */
$handler = $view->new_display('block', 'Block', 'block');
$handler->display->display_options['block_description'] = 'Latest Tweets';

/* Display: Block - News page */
$handler = $view->new_display('block', 'Block - News page', 'block_1');
$handler->display->display_options['block_description'] = 'Latest Tweets';
$translatables['latest_tweets'] = array(
    t('Master'),
    t('Latest Tweets'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('<a href="https://twitter.com/ebaygr" class="btn follow-us">Follow Us</a>'),
    t('Twitter status message ID'),
    t('Block'),
    t('Block - News page'),
);