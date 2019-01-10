<?php

$view = new view();
$view->name = 'action_center_spotlight';
$view->description = 'A list of three campaigns to be spotlighted on the Action Center page';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'Action Center Spotlight';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Action Center Spotlight';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '3';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['style_options']['row_class'] = 'action-center-campaign';
$handler->display->display_options['row_plugin'] = 'fields';
/* Relationship: Nodequeue: Queue */
$handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
$handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
$handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
$handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
$handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'action_center_spotlight' => 'action_center_spotlight',
    'spotlights' => 0,
    'team_profiles' => 0,
    'resources' => 0,
    'spotlights_australia' => 0,
    'spotlights_asia_pacific' => 0,
    'spotlights_europe' => 0,
    'spotlights_global' => 0,
    'photo_gallery_2012_dc_fly_in' => 0,
    'featured_member' => 0,
    'photo_gallery_2012_think_3_0_sto' => 0,
    'photo_gallery_commerce_3_0_us_ev' => 0,
    'photo_gallery_germany_pop_up_sto' => 0,
    'featured_member_eu' => 0,
    'featured_member_au' => 0,
    'featured_member_apac' => 0,
    'photo_gallery_paypal_thought_lea' => 0,
    'features_extra_test_nodequeue' => 0,
    'policy_labs_team' => 0,
);
/* Field: Content: Path */
$handler->display->display_options['fields']['path']['id'] = 'path';
$handler->display->display_options['fields']['path']['table'] = 'node';
$handler->display->display_options['fields']['path']['field'] = 'path';
$handler->display->display_options['fields']['path']['label'] = '';
$handler->display->display_options['fields']['path']['exclude'] = TRUE;
$handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_type'] = 'h2';
$handler->display->display_options['fields']['title']['element_class'] = 'campaign-title';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
/* Field: Content: Related Issue */
$handler->display->display_options['fields']['field_bipac_camp_learn_more']['id'] = 'field_bipac_camp_learn_more';
$handler->display->display_options['fields']['field_bipac_camp_learn_more']['table'] = 'field_data_field_bipac_camp_learn_more';
$handler->display->display_options['fields']['field_bipac_camp_learn_more']['field'] = 'field_bipac_camp_learn_more';
$handler->display->display_options['fields']['field_bipac_camp_learn_more']['label'] = 'Issue';
$handler->display->display_options['fields']['field_bipac_camp_learn_more']['element_type'] = 'strong';
$handler->display->display_options['fields']['field_bipac_camp_learn_more']['element_label_type'] = '0';
$handler->display->display_options['fields']['field_bipac_camp_learn_more']['element_wrapper_type'] = 'p';
$handler->display->display_options['fields']['field_bipac_camp_learn_more']['element_wrapper_class'] = 'campaign-issue';
$handler->display->display_options['fields']['field_bipac_camp_learn_more']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_bipac_camp_learn_more']['hide_empty'] = TRUE;
/* Field: Content: Body */
$handler->display->display_options['fields']['body']['id'] = 'body';
$handler->display->display_options['fields']['body']['table'] = 'field_data_body';
$handler->display->display_options['fields']['body']['field'] = 'body';
$handler->display->display_options['fields']['body']['label'] = '';
$handler->display->display_options['fields']['body']['alter']['max_length'] = '300';
$handler->display->display_options['fields']['body']['alter']['more_link'] = TRUE;
$handler->display->display_options['fields']['body']['alter']['more_link_text'] = 'Learn More ›';
$handler->display->display_options['fields']['body']['alter']['more_link_path'] = '[path]';
$handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
$handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
$handler->display->display_options['fields']['body']['element_type'] = 'p';
$handler->display->display_options['fields']['body']['element_class'] = 'campaign-description';
$handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['body']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
);
/* Field: Take Action */
$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
$handler->display->display_options['fields']['nothing']['table'] = 'views';
$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing']['ui_name'] = 'Take Action';
$handler->display->display_options['fields']['nothing']['label'] = '';
$handler->display->display_options['fields']['nothing']['alter']['text'] = '<h3 class="campaign-cta-header">Take Action</h3>';
$handler->display->display_options['fields']['nothing']['element_type'] = '0';
$handler->display->display_options['fields']['nothing']['element_class'] = 'campaign-title';
$handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['nothing']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
/* Field: Content: Link */
$handler->display->display_options['fields']['view_node']['id'] = 'view_node';
$handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
$handler->display->display_options['fields']['view_node']['field'] = 'view_node';
$handler->display->display_options['fields']['view_node']['label'] = '';
$handler->display->display_options['fields']['view_node']['element_type'] = 'p';
$handler->display->display_options['fields']['view_node']['element_class'] = 'campaign-petition-link';
$handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['view_node']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['view_node']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['view_node']['text'] = 'Write a Letter to My Member of Congress';
/* Field: Content: Tweet Title */
$handler->display->display_options['fields']['field_bipac_camp_tweet_title']['id'] = 'field_bipac_camp_tweet_title';
$handler->display->display_options['fields']['field_bipac_camp_tweet_title']['table'] = 'field_data_field_bipac_camp_tweet_title';
$handler->display->display_options['fields']['field_bipac_camp_tweet_title']['field'] = 'field_bipac_camp_tweet_title';
$handler->display->display_options['fields']['field_bipac_camp_tweet_title']['label'] = '';
$handler->display->display_options['fields']['field_bipac_camp_tweet_title']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_bipac_camp_tweet_title']['element_type'] = '0';
$handler->display->display_options['fields']['field_bipac_camp_tweet_title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_bipac_camp_tweet_title']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_bipac_camp_tweet_title']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_bipac_camp_tweet_title']['field_api_classes'] = TRUE;
/* Field: Content: Nid */
$handler->display->display_options['fields']['nid']['id'] = 'nid';
$handler->display->display_options['fields']['nid']['table'] = 'node';
$handler->display->display_options['fields']['nid']['field'] = 'nid';
$handler->display->display_options['fields']['nid']['label'] = '';
$handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['nid']['alter']['text'] = '[field_bipac_camp_tweet_title]';
$handler->display->display_options['fields']['nid']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['nid']['alter']['path'] = 'action-center/tweet?campaign_id=[nid]';
$handler->display->display_options['fields']['nid']['element_type'] = '0';
$handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
/* Field: Broken/missing handler */
$handler->display->display_options['fields']['field_campaign_date']['id'] = 'field_campaign_date';
$handler->display->display_options['fields']['field_campaign_date']['table'] = 'field_data_field_campaign_date';
$handler->display->display_options['fields']['field_campaign_date']['field'] = 'field_campaign_date';
$handler->display->display_options['fields']['field_campaign_date']['label'] = '';
$handler->display->display_options['fields']['field_campaign_date']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_campaign_date']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['field_campaign_date']['alter']['text'] = '<p class="campaign--post-date">Since [field_campaign_date]</p>';
$handler->display->display_options['fields']['field_campaign_date']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_campaign_date']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_campaign_date']['hide_empty'] = TRUE;
/* Field: Petition Signatures */
$handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
$handler->display->display_options['fields']['nothing_1']['table'] = 'views';
$handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Petition Signatures';
$handler->display->display_options['fields']['nothing_1']['label'] = '';
$handler->display->display_options['fields']['nothing_1']['exclude'] = TRUE;
$handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'Petition Signatures';
$handler->display->display_options['fields']['nothing_1']['element_type'] = 'p';
$handler->display->display_options['fields']['nothing_1']['element_class'] = 'campaign--count-label';
$handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
/* Field: Content: Post date */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'node';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['label'] = '';
$handler->display->display_options['fields']['created']['exclude'] = TRUE;
$handler->display->display_options['fields']['created']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['created']['alter']['text'] = 'Since [created]';
$handler->display->display_options['fields']['created']['element_type'] = 'p';
$handler->display->display_options['fields']['created']['element_class'] = 'campaign--posted-date';
$handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['created']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['created']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['created']['date_format'] = 'custom';
$handler->display->display_options['fields']['created']['custom_date_format'] = 'M jS, Y';
/* Field: Broken/missing handler */
$handler->display->display_options['fields']['field_bipac_camp_submissions']['id'] = 'field_bipac_camp_submissions';
$handler->display->display_options['fields']['field_bipac_camp_submissions']['table'] = 'field_data_field_bipac_camp_submissions';
$handler->display->display_options['fields']['field_bipac_camp_submissions']['field'] = 'field_bipac_camp_submissions';
$handler->display->display_options['fields']['field_bipac_camp_submissions']['label'] = '';
$handler->display->display_options['fields']['field_bipac_camp_submissions']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['field_bipac_camp_submissions']['alter']['text'] = '<h3 class="campaign--count">[field_bipac_camp_submissions]</h3>
<p class="campaign--count-label">Petition Signatures</p>
[field_campaign_date]';
$handler->display->display_options['fields']['field_bipac_camp_submissions']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_bipac_camp_submissions']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['field_bipac_camp_submissions']['element_wrapper_class'] = 'campaign--signatures';
$handler->display->display_options['fields']['field_bipac_camp_submissions']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_bipac_camp_submissions']['hide_empty'] = TRUE;
$handler->display->display_options['fields']['field_bipac_camp_submissions']['empty_zero'] = TRUE;
/* Sort criterion: Nodequeue: Position */
$handler->display->display_options['sorts']['position']['id'] = 'position';
$handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
$handler->display->display_options['sorts']['position']['field'] = 'position';
$handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
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
    'bipac_campaign' => 'bipac_campaign',
);
/* Filter criterion: Nodequeue: In queue */
$handler->display->display_options['filters']['in_queue']['id'] = 'in_queue';
$handler->display->display_options['filters']['in_queue']['table'] = 'nodequeue_nodes';
$handler->display->display_options['filters']['in_queue']['field'] = 'in_queue';
$handler->display->display_options['filters']['in_queue']['relationship'] = 'nodequeue_rel';
$handler->display->display_options['filters']['in_queue']['value'] = '1';

/* Display: Block */
$handler = $view->new_display('block', 'Block', 'block');
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Path */
$handler->display->display_options['fields']['path']['id'] = 'path';
$handler->display->display_options['fields']['path']['table'] = 'node';
$handler->display->display_options['fields']['path']['field'] = 'path';
$handler->display->display_options['fields']['path']['label'] = '';
$handler->display->display_options['fields']['path']['exclude'] = TRUE;
$handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_type'] = 'h2';
$handler->display->display_options['fields']['title']['element_class'] = 'campaign-title';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
/* Field: Content: Related Issue */
$handler->display->display_options['fields']['field_bipac_camp_learn_more']['id'] = 'field_bipac_camp_learn_more';
$handler->display->display_options['fields']['field_bipac_camp_learn_more']['table'] = 'field_data_field_bipac_camp_learn_more';
$handler->display->display_options['fields']['field_bipac_camp_learn_more']['field'] = 'field_bipac_camp_learn_more';
$handler->display->display_options['fields']['field_bipac_camp_learn_more']['label'] = '';
$handler->display->display_options['fields']['field_bipac_camp_learn_more']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_bipac_camp_learn_more']['element_type'] = 'strong';
$handler->display->display_options['fields']['field_bipac_camp_learn_more']['element_label_type'] = '0';
$handler->display->display_options['fields']['field_bipac_camp_learn_more']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_bipac_camp_learn_more']['element_wrapper_type'] = 'p';
$handler->display->display_options['fields']['field_bipac_camp_learn_more']['element_wrapper_class'] = 'campaign-issue';
$handler->display->display_options['fields']['field_bipac_camp_learn_more']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_bipac_camp_learn_more']['hide_empty'] = TRUE;
/* Field: Content: Body */
$handler->display->display_options['fields']['body']['id'] = 'body';
$handler->display->display_options['fields']['body']['table'] = 'field_data_body';
$handler->display->display_options['fields']['body']['field'] = 'body';
$handler->display->display_options['fields']['body']['label'] = '';
$handler->display->display_options['fields']['body']['alter']['text'] = '[body-summary] <a href="[path]">Learn More &raquo;</a>';
$handler->display->display_options['fields']['body']['alter']['max_length'] = '300';
$handler->display->display_options['fields']['body']['alter']['more_link'] = TRUE;
$handler->display->display_options['fields']['body']['alter']['more_link_text'] = 'Learn More ›';
$handler->display->display_options['fields']['body']['alter']['more_link_path'] = '[path]';
$handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
$handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
$handler->display->display_options['fields']['body']['element_type'] = 'p';
$handler->display->display_options['fields']['body']['element_class'] = 'campaign-description';
$handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['body']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
$handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '300',
);
/* Field: Learn More Link */
$handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
$handler->display->display_options['fields']['nothing_2']['table'] = 'views';
$handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing_2']['ui_name'] = 'Learn More Link';
$handler->display->display_options['fields']['nothing_2']['label'] = '';
$handler->display->display_options['fields']['nothing_2']['exclude'] = TRUE;
$handler->display->display_options['fields']['nothing_2']['alter']['text'] = '<p><a href="[path]">Learn More ></a></p>';
$handler->display->display_options['fields']['nothing_2']['element_label_colon'] = FALSE;
/* Field: Take Action */
$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
$handler->display->display_options['fields']['nothing']['table'] = 'views';
$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing']['ui_name'] = 'Take Action';
$handler->display->display_options['fields']['nothing']['label'] = '';
$handler->display->display_options['fields']['nothing']['alter']['text'] = '<h3 class="campaign-cta-header">Take Action</h3>';
$handler->display->display_options['fields']['nothing']['element_type'] = '0';
$handler->display->display_options['fields']['nothing']['element_class'] = 'campaign-title';
$handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['nothing']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
/* Field: Content: Link */
$handler->display->display_options['fields']['view_node']['id'] = 'view_node';
$handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
$handler->display->display_options['fields']['view_node']['field'] = 'view_node';
$handler->display->display_options['fields']['view_node']['label'] = '';
$handler->display->display_options['fields']['view_node']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['view_node']['alter']['text'] = '<div style="text-align:center" class="take-action-group-wrapper-1">
<a class="take-action-group-link" href="http://www.ebaymainstreet.com/campaign/tell-our-new-congress-not-enact-new-internet-sales-tax" target="_blank">
  <div class="take-action-write-icon"></div>
    <div class="take-action-group-title">
      Write a Letter to Congress
    </div>
</a>
</div>';
$handler->display->display_options['fields']['view_node']['element_type'] = 'p';
$handler->display->display_options['fields']['view_node']['element_class'] = 'campaign-petition-link';
$handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['view_node']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['view_node']['element_default_classes'] = FALSE;
/* Field: Content: Tweet Title */
$handler->display->display_options['fields']['field_bipac_camp_tweet_title']['id'] = 'field_bipac_camp_tweet_title';
$handler->display->display_options['fields']['field_bipac_camp_tweet_title']['table'] = 'field_data_field_bipac_camp_tweet_title';
$handler->display->display_options['fields']['field_bipac_camp_tweet_title']['field'] = 'field_bipac_camp_tweet_title';
$handler->display->display_options['fields']['field_bipac_camp_tweet_title']['label'] = '';
$handler->display->display_options['fields']['field_bipac_camp_tweet_title']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_bipac_camp_tweet_title']['element_type'] = '0';
$handler->display->display_options['fields']['field_bipac_camp_tweet_title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_bipac_camp_tweet_title']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_bipac_camp_tweet_title']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_bipac_camp_tweet_title']['field_api_classes'] = TRUE;
/* Field: Content: Nid */
$handler->display->display_options['fields']['nid']['id'] = 'nid';
$handler->display->display_options['fields']['nid']['table'] = 'node';
$handler->display->display_options['fields']['nid']['field'] = 'nid';
$handler->display->display_options['fields']['nid']['label'] = '';
$handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['nid']['alter']['text'] = '<div class="take-action-group-wrapper-2"><a class="take-action-group-link" href="/action-center/tweet?campaign_id=[nid]">
  <div class="take-action-twitter-icon"></div>
    <div class="take-action-group-title">
      Send a Tweet
    </div>
</a></div>';
$handler->display->display_options['fields']['nid']['alter']['path'] = 'action-center/tweet?campaign_id=[nid]';
$handler->display->display_options['fields']['nid']['element_type'] = '0';
$handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
/* Field: Broken/missing handler */
$handler->display->display_options['fields']['field_campaign_date']['id'] = 'field_campaign_date';
$handler->display->display_options['fields']['field_campaign_date']['table'] = 'field_data_field_campaign_date';
$handler->display->display_options['fields']['field_campaign_date']['field'] = 'field_campaign_date';
$handler->display->display_options['fields']['field_campaign_date']['label'] = '';
$handler->display->display_options['fields']['field_campaign_date']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_campaign_date']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['field_campaign_date']['alter']['text'] = '<p class="campaign--post-date">Since [field_campaign_date]</p>';
$handler->display->display_options['fields']['field_campaign_date']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_campaign_date']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_campaign_date']['hide_empty'] = TRUE;
/* Field: Petition Signatures */
$handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
$handler->display->display_options['fields']['nothing_1']['table'] = 'views';
$handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Petition Signatures';
$handler->display->display_options['fields']['nothing_1']['label'] = '';
$handler->display->display_options['fields']['nothing_1']['exclude'] = TRUE;
$handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'Petition Signatures';
$handler->display->display_options['fields']['nothing_1']['element_type'] = 'p';
$handler->display->display_options['fields']['nothing_1']['element_class'] = 'campaign--count-label';
$handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
/* Field: Content: Post date */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'node';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['label'] = '';
$handler->display->display_options['fields']['created']['exclude'] = TRUE;
$handler->display->display_options['fields']['created']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['created']['alter']['text'] = 'Since [created]';
$handler->display->display_options['fields']['created']['element_type'] = 'p';
$handler->display->display_options['fields']['created']['element_class'] = 'campaign--posted-date';
$handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['created']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['created']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['created']['date_format'] = 'custom';
$handler->display->display_options['fields']['created']['custom_date_format'] = 'M jS, Y';
$handler->display->display_options['fields']['created']['second_date_format'] = 'html5_tools_iso8601';
/* Field: Broken/missing handler */
$handler->display->display_options['fields']['field_bipac_camp_submissions']['id'] = 'field_bipac_camp_submissions';
$handler->display->display_options['fields']['field_bipac_camp_submissions']['table'] = 'field_data_field_bipac_camp_submissions';
$handler->display->display_options['fields']['field_bipac_camp_submissions']['field'] = 'field_bipac_camp_submissions';
$handler->display->display_options['fields']['field_bipac_camp_submissions']['label'] = '';
$handler->display->display_options['fields']['field_bipac_camp_submissions']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_bipac_camp_submissions']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['field_bipac_camp_submissions']['alter']['text'] = '<h3 class="campaign--count">[field_bipac_camp_submissions]</h3>
<p class="campaign--count-label">Letters sent to Congress</p>
[field_campaign_date]';
$handler->display->display_options['fields']['field_bipac_camp_submissions']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_bipac_camp_submissions']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['field_bipac_camp_submissions']['element_wrapper_class'] = 'campaign--signatures';
$handler->display->display_options['fields']['field_bipac_camp_submissions']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_bipac_camp_submissions']['hide_empty'] = TRUE;
$handler->display->display_options['fields']['field_bipac_camp_submissions']['empty_zero'] = TRUE;
$translatables['action_center_spotlight'] = array(
    t('Master'),
    t('Action Center Spotlight'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('queue'),
    t('Issue'),
    t('Learn More ›'),
    t('<h3 class="campaign-cta-header">Take Action</h3>'),
    t('Write a Letter to My Member of Congress'),
    t('[field_bipac_camp_tweet_title]'),
    t('<p class="campaign--post-date">Since [field_campaign_date]</p>'),
    t('Petition Signatures'),
    t('Since [created]'),
    t('<h3 class="campaign--count">[field_bipac_camp_submissions]</h3>
<p class="campaign--count-label">Petition Signatures</p>
[field_campaign_date]'),
    t('Block'),
    t('[body-summary] <a href="[path]">Learn More &raquo;</a>'),
    t('<p><a href="[path]">Learn More ></a></p>'),
    t('<div style="text-align:center" class="take-action-group-wrapper-1">
<a class="take-action-group-link" href="http://www.ebaymainstreet.com/campaign/tell-our-new-congress-not-enact-new-internet-sales-tax" target="_blank">
  <div class="take-action-write-icon"></div>
    <div class="take-action-group-title">
      Write a Letter to Congress
    </div>
</a>
</div>'),
    t('<div class="take-action-group-wrapper-2"><a class="take-action-group-link" href="/action-center/tweet?campaign_id=[nid]">
  <div class="take-action-twitter-icon"></div>
    <div class="take-action-group-title">
      Send a Tweet
    </div>
</a></div>'),
    t('<h3 class="campaign--count">[field_bipac_camp_submissions]</h3>
<p class="campaign--count-label">Letters sent to Congress</p>
[field_campaign_date]'),
);