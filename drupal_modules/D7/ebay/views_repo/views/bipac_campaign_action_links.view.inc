<?php

$view = new view();
$view->name = 'bipac_campaign_action_links';
$view->description = 'A contextual block to go on a bipac campaign page that links to its social media page. ';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'BIPAC Campaign Action Links';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Take Action';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '1';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['style_options']['row_class'] = 'action-center-campaign';
$handler->display->display_options['row_plugin'] = 'fields';
/* Field: Write a Letter */
$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
$handler->display->display_options['fields']['nothing']['table'] = 'views';
$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing']['ui_name'] = 'Write a Letter';
$handler->display->display_options['fields']['nothing']['label'] = '';
$handler->display->display_options['fields']['nothing']['alter']['text'] = '<p class="campaign-petition-link"><a href="#block-bipac-campaigns-bipac-campaigns-bipac-block">Write a Letter to My Member of Congress</a></p>';
$handler->display->display_options['fields']['nothing']['element_type'] = '0';
$handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['nothing']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
/* Field: Tweet */
$handler->display->display_options['fields']['nid']['id'] = 'nid';
$handler->display->display_options['fields']['nid']['table'] = 'node';
$handler->display->display_options['fields']['nid']['field'] = 'nid';
$handler->display->display_options['fields']['nid']['ui_name'] = 'Tweet';
$handler->display->display_options['fields']['nid']['label'] = '';
$handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['nid']['alter']['text'] = 'Tweet Your Members of Congress';
$handler->display->display_options['fields']['nid']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['nid']['alter']['path'] = 'action-center/tweet?campaign_id=[nid]';
$handler->display->display_options['fields']['nid']['element_type'] = '0';
$handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
/* Sort criterion: Content: Post date */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'node';
$handler->display->display_options['sorts']['created']['field'] = 'created';
$handler->display->display_options['sorts']['created']['order'] = 'DESC';
/* Contextual filter: Content: Nid */
$handler->display->display_options['arguments']['nid']['id'] = 'nid';
$handler->display->display_options['arguments']['nid']['table'] = 'node';
$handler->display->display_options['arguments']['nid']['field'] = 'nid';
$handler->display->display_options['arguments']['nid']['default_action'] = 'default';
$handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
$handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
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
    'bipac_campaign' => 'bipac_campaign',
);

/* Display: Block - Congress */
$handler = $view->new_display('block', 'Block - Congress', 'block_1');
$handler->display->display_options['defaults']['cache'] = FALSE;
$handler->display->display_options['cache']['type'] = 'time';
$handler->display->display_options['cache']['results_lifespan'] = '3600';
$handler->display->display_options['cache']['results_lifespan_custom'] = '0';
$handler->display->display_options['cache']['output_lifespan'] = '3600';
$handler->display->display_options['cache']['output_lifespan_custom'] = '0';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Write a Letter */
$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
$handler->display->display_options['fields']['nothing']['table'] = 'views';
$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing']['ui_name'] = 'Write a Letter';
$handler->display->display_options['fields']['nothing']['label'] = '';
$handler->display->display_options['fields']['nothing']['alter']['text'] = '<div style="text-align:center" class="take-action-group-wrapper">
<a class="take-action-group-link" href="#block-bipac-campaigns-bipac-campaigns-bipac-block">
  <div class="take-action-write-icon"></div>
    <div class="take-action-group-title">
      Write a Letter to Congress
    </div>
</a>
</div>';
$handler->display->display_options['fields']['nothing']['element_type'] = '0';
$handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['nothing']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
/* Field: Tweet */
$handler->display->display_options['fields']['nid']['id'] = 'nid';
$handler->display->display_options['fields']['nid']['table'] = 'node';
$handler->display->display_options['fields']['nid']['field'] = 'nid';
$handler->display->display_options['fields']['nid']['ui_name'] = 'Tweet';
$handler->display->display_options['fields']['nid']['label'] = '';
$handler->display->display_options['fields']['nid']['exclude'] = TRUE;
$handler->display->display_options['fields']['nid']['alter']['text'] = 'Tweet your State\'s Elected Officials';
$handler->display->display_options['fields']['nid']['alter']['path'] = 'action-center/tweet?campaign_id=[nid]';
$handler->display->display_options['fields']['nid']['element_type'] = '0';
$handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['nid']['hide_empty'] = TRUE;
/* Field: Global: Custom text */
$handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
$handler->display->display_options['fields']['nothing_1']['table'] = 'views';
$handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing_1']['label'] = '';
$handler->display->display_options['fields']['nothing_1']['alter']['text'] = '<div class="take-action-group-wrapper"><a class="take-action-group-link" href="/action-center/tweet?campaign_id=[nid]">
  <div class="take-action-twitter-icon"></div>
    <div class="take-action-group-title">
      Tweet Your Members of Congress
    </div>
</a></div>';
$handler->display->display_options['fields']['nothing_1']['element_type'] = '0';
$handler->display->display_options['fields']['nothing_1']['element_label_type'] = '0';
$handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['nothing_1']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['nothing_1']['element_default_classes'] = FALSE;
$handler->display->display_options['block_caching'] = '4';

/* Display: Block - ST Senator Letter Only */
$handler = $view->new_display('block', 'Block - ST Senator Letter Only', 'block_2');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Write a Letter */
$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
$handler->display->display_options['fields']['nothing']['table'] = 'views';
$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing']['ui_name'] = 'Write a Letter';
$handler->display->display_options['fields']['nothing']['label'] = '';
$handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="take-action-group-wrapper single-item">
<a class="take-action-group-link" href="#block-bipac-campaigns-bipac-campaigns-bipac-block">
  <div class="take-action-write-icon"></div>
    <div class="take-action-group-title">
      Write a Letter to My State Senator
    </div>
</a>
</div>';
$handler->display->display_options['fields']['nothing']['element_type'] = '0';
$handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['nothing']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
/* Field: Tweet */
$handler->display->display_options['fields']['nid']['id'] = 'nid';
$handler->display->display_options['fields']['nid']['table'] = 'node';
$handler->display->display_options['fields']['nid']['field'] = 'nid';
$handler->display->display_options['fields']['nid']['ui_name'] = 'Tweet';
$handler->display->display_options['fields']['nid']['label'] = '';
$handler->display->display_options['fields']['nid']['exclude'] = TRUE;
$handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['nid']['alter']['text'] = 'Tweet Your Members of Congress';
$handler->display->display_options['fields']['nid']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['nid']['alter']['path'] = 'action-center/tweet?campaign_id=[nid]';
$handler->display->display_options['fields']['nid']['element_type'] = '0';
$handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
$handler->display->display_options['block_description'] = 'Take Action - Letter Only';

/* Display: Block - State Officials */
$handler = $view->new_display('block', 'Block - State Officials', 'letter_tweet_stateonly');
$handler->display->display_options['defaults']['cache'] = FALSE;
$handler->display->display_options['cache']['type'] = 'time';
$handler->display->display_options['cache']['results_lifespan'] = '3600';
$handler->display->display_options['cache']['results_lifespan_custom'] = '0';
$handler->display->display_options['cache']['output_lifespan'] = '3600';
$handler->display->display_options['cache']['output_lifespan_custom'] = '0';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Tweet */
$handler->display->display_options['fields']['nid']['id'] = 'nid';
$handler->display->display_options['fields']['nid']['table'] = 'node';
$handler->display->display_options['fields']['nid']['field'] = 'nid';
$handler->display->display_options['fields']['nid']['ui_name'] = 'Tweet';
$handler->display->display_options['fields']['nid']['label'] = '';
$handler->display->display_options['fields']['nid']['exclude'] = TRUE;
$handler->display->display_options['fields']['nid']['alter']['text'] = 'Tweet your State\'s Elected Officials';
$handler->display->display_options['fields']['nid']['alter']['path'] = 'action-center/tweet?campaign_id=[nid]';
$handler->display->display_options['fields']['nid']['element_type'] = '0';
$handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['nid']['hide_empty'] = TRUE;
/* Field: Global: Custom text */
$handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
$handler->display->display_options['fields']['nothing_1']['table'] = 'views';
$handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing_1']['label'] = '';
$handler->display->display_options['fields']['nothing_1']['alter']['text'] = '<div class="take-action-group-wrapper blue-background tweet-officials">
    <a class="take-action-group-link" href="/action-center/tweet?campaign_id=[nid]">
        <div class="take-action-twitter-icon"></div>
        <div class="take-action-group-title">
            Tweet Your State Officials
        </div>
        <div class="take-action-chevron chevron-right"></div>
    </a>
</div>';
$handler->display->display_options['fields']['nothing_1']['element_type'] = '0';
$handler->display->display_options['fields']['nothing_1']['element_label_type'] = '0';
$handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['nothing_1']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['nothing_1']['element_default_classes'] = FALSE;
/* Field: Write a Letter */
$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
$handler->display->display_options['fields']['nothing']['table'] = 'views';
$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing']['ui_name'] = 'Write a Letter';
$handler->display->display_options['fields']['nothing']['label'] = '';
$handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="take-action-group-wrapper pink-background write-letter">
    <a class="take-action-group-link" href="#block-bipac-campaigns-bipac-campaigns-bipac-block">
        <div class="take-action-write-icon"></div>
        <div class="take-action-group-title">
            Write a Letter to your State\'s Elected Officials
        </div>
    </a>
</div>';
$handler->display->display_options['fields']['nothing']['element_type'] = '0';
$handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['nothing']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
/* Field: Global: Custom text */
$handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
$handler->display->display_options['fields']['nothing_2']['table'] = 'views';
$handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing_2']['label'] = '';
$handler->display->display_options['fields']['nothing_2']['alter']['text'] = '<div class="take-action-group-wrapper pink-background call-officials">
    <a class="take-action-group-link" href="#block-bipac-campaigns-bipac-campaigns-bipac-block">
        <div class="take-action-phone icon icon-phone"></div>
        <div class="take-action-group-title">
            Call Your Members of Congress
        </div>
        <div class="take-action-chevron icon icon-chevron-right"></div>
    </a>
</div>';
$handler->display->display_options['fields']['nothing_2']['element_label_colon'] = FALSE;
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: Content: Post date */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'node';
$handler->display->display_options['sorts']['created']['field'] = 'created';
$handler->display->display_options['block_caching'] = '4';

/* Display: Block - State Rep */
$handler = $view->new_display('block', 'Block - State Rep', 'block_3');
$handler->display->display_options['defaults']['cache'] = FALSE;
$handler->display->display_options['cache']['type'] = 'time';
$handler->display->display_options['cache']['results_lifespan'] = '3600';
$handler->display->display_options['cache']['results_lifespan_custom'] = '0';
$handler->display->display_options['cache']['output_lifespan'] = '3600';
$handler->display->display_options['cache']['output_lifespan_custom'] = '0';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Write a Letter */
$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
$handler->display->display_options['fields']['nothing']['table'] = 'views';
$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing']['ui_name'] = 'Write a Letter';
$handler->display->display_options['fields']['nothing']['label'] = '';
$handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="take-action-group-wrapper single-item">
<a class="take-action-group-link" href="#block-bipac-campaigns-bipac-campaigns-bipac-block">
  <div class="take-action-write-icon"></div>
    <div class="take-action-group-title">
      Write a Letter to your State Representative
    </div>
</a>
</div>';
$handler->display->display_options['fields']['nothing']['element_type'] = '0';
$handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['nothing']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
/* Field: Tweet */
$handler->display->display_options['fields']['nid']['id'] = 'nid';
$handler->display->display_options['fields']['nid']['table'] = 'node';
$handler->display->display_options['fields']['nid']['field'] = 'nid';
$handler->display->display_options['fields']['nid']['ui_name'] = 'Tweet';
$handler->display->display_options['fields']['nid']['label'] = '';
$handler->display->display_options['fields']['nid']['exclude'] = TRUE;
$handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['nid']['alter']['text'] = 'Tweet your State\'s Elected Officials';
$handler->display->display_options['fields']['nid']['alter']['path'] = 'action-center/tweet?campaign_id=[nid]';
$handler->display->display_options['fields']['nid']['element_type'] = '0';
$handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['nid']['hide_empty'] = TRUE;
/* Field: Global: Custom text */
$handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
$handler->display->display_options['fields']['nothing_1']['table'] = 'views';
$handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing_1']['label'] = '';
$handler->display->display_options['fields']['nothing_1']['exclude'] = TRUE;
$handler->display->display_options['fields']['nothing_1']['alter']['text'] = '<div class="take-action-group-wrapper" style="float:none; width: auto"><a class="take-action-group-link" href="/action-center/tweet?campaign_id=!1">
  <div class="take-action-twitter-icon"></div>
    <div class="take-action-group-title">
      Tweet Your State Representative
    </div>
</a></div>';
$handler->display->display_options['fields']['nothing_1']['element_type'] = '0';
$handler->display->display_options['fields']['nothing_1']['element_label_type'] = '0';
$handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['nothing_1']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['nothing_1']['element_default_classes'] = FALSE;
$handler->display->display_options['block_caching'] = '4';
$translatables['bipac_campaign_action_links'] = array(
    t('Master'),
    t('Take Action'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('<p class="campaign-petition-link"><a href="#block-bipac-campaigns-bipac-campaigns-bipac-block">Write a Letter to My Member of Congress</a></p>'),
    t('Tweet Your Members of Congress'),
    t('All'),
    t('Block - Congress'),
    t('<div style="text-align:center" class="take-action-group-wrapper">
<a class="take-action-group-link" href="#block-bipac-campaigns-bipac-campaigns-bipac-block">
  <div class="take-action-write-icon"></div>
    <div class="take-action-group-title">
      Write a Letter to Congress
    </div>
</a>
</div>'),
    t('Tweet your State\'s Elected Officials'),
    t('<div class="take-action-group-wrapper"><a class="take-action-group-link" href="/action-center/tweet?campaign_id=[nid]">
  <div class="take-action-twitter-icon"></div>
    <div class="take-action-group-title">
      Tweet Your Members of Congress
    </div>
</a></div>'),
    t('Block - ST Senator Letter Only'),
    t('<div class="take-action-group-wrapper single-item">
<a class="take-action-group-link" href="#block-bipac-campaigns-bipac-campaigns-bipac-block">
  <div class="take-action-write-icon"></div>
    <div class="take-action-group-title">
      Write a Letter to My State Senator
    </div>
</a>
</div>'),
    t('Take Action - Letter Only'),
    t('Block - State Officials'),
    t('<div class="take-action-group-wrapper blue-background tweet-officials">
    <a class="take-action-group-link" href="/action-center/tweet?campaign_id=[nid]">
        <div class="take-action-twitter-icon"></div>
        <div class="take-action-group-title">
            Tweet Your State Officials
        </div>
        <div class="take-action-chevron chevron-right"></div>
    </a>
</div>'),
    t('<div class="take-action-group-wrapper pink-background write-letter">
    <a class="take-action-group-link" href="#block-bipac-campaigns-bipac-campaigns-bipac-block">
        <div class="take-action-write-icon"></div>
        <div class="take-action-group-title">
            Write a Letter to your State\'s Elected Officials
        </div>
    </a>
</div>'),
    t('<div class="take-action-group-wrapper pink-background call-officials">
    <a class="take-action-group-link" href="#block-bipac-campaigns-bipac-campaigns-bipac-block">
        <div class="take-action-phone icon icon-phone"></div>
        <div class="take-action-group-title">
            Call Your Members of Congress
        </div>
        <div class="take-action-chevron icon icon-chevron-right"></div>
    </a>
</div>'),
    t('Block - State Rep'),
    t('<div class="take-action-group-wrapper single-item">
<a class="take-action-group-link" href="#block-bipac-campaigns-bipac-campaigns-bipac-block">
  <div class="take-action-write-icon"></div>
    <div class="take-action-group-title">
      Write a Letter to your State Representative
    </div>
</a>
</div>'),
    t('<div class="take-action-group-wrapper" style="float:none; width: auto"><a class="take-action-group-link" href="/action-center/tweet?campaign_id=!1">
  <div class="take-action-twitter-icon"></div>
    <div class="take-action-group-title">
      Tweet Your State Representative
    </div>
</a></div>'),
);