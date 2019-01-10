<?php

$view = new view();
$view->name = 'ems2015_issue_share_block';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'EMS2015 - Issue Share Block';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'EMS2015 - Issue Share Block';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['row_plugin'] = 'fields';
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
/* Field: Content: Path */
$handler->display->display_options['fields']['path']['id'] = 'path';
$handler->display->display_options['fields']['path']['table'] = 'node';
$handler->display->display_options['fields']['path']['field'] = 'path';
$handler->display->display_options['fields']['path']['label'] = '';
$handler->display->display_options['fields']['path']['exclude'] = TRUE;
$handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
/* Field: Global: Custom text */
$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
$handler->display->display_options['fields']['nothing']['table'] = 'views';
$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing']['label'] = '';
$handler->display->display_options['fields']['nothing']['alter']['text'] = '<h2>Share</h2>
<ul class="issue-share menu">
<li class="first leaf"><a href="http://www.facebook.com/sharer.php?u=[path]" class="social-media-facebook-square"><span class="visuallyhidden">Facebook</span></a></li>
<li class="leaf"><a href="https://twitter.com/share?text=[title]&url=[path]" class="social-media-twitter"><span class="visuallyhidden">Twitter</span></a></li>
<li class="leaf"><a href="https://plus.google.com/share?url=[path]" class="social-media-googleplus"><span class="visuallyhidden">Google+</span></a></li>
<li class="leaf"><a href="https://www.linkedin.com/shareArticle?mini=true&url=[path]&title=[title]&summary=[title]&source=[path]" class="social-media-linkedin-square"><span class="visuallyhidden">LinkedIn</span></a></li>
</ul>';
$handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
/* Contextual filter: Content: Nid */
$handler->display->display_options['arguments']['nid']['id'] = 'nid';
$handler->display->display_options['arguments']['nid']['table'] = 'node';
$handler->display->display_options['arguments']['nid']['field'] = 'nid';
$handler->display->display_options['arguments']['nid']['default_action'] = 'default';
$handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
$handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
$handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
$handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'issue' => 'issue',
);
$handler->display->display_options['arguments']['nid']['validate_options']['access'] = TRUE;
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
    'issue' => 'issue',
);

/* Display: Block */
$handler = $view->new_display('block', 'Block', 'share_block');
$translatables['ems2015_issue_share_block'] = array(
    t('Master'),
    t('EMS2015 - Issue Share Block'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('<h2>Share</h2>
<ul class="issue-share menu">
<li class="first leaf"><a href="http://www.facebook.com/sharer.php?u=[path]" class="social-media-facebook-square"><span class="visuallyhidden">Facebook</span></a></li>
<li class="leaf"><a href="https://twitter.com/share?text=[title]&url=[path]" class="social-media-twitter"><span class="visuallyhidden">Twitter</span></a></li>
<li class="leaf"><a href="https://plus.google.com/share?url=[path]" class="social-media-googleplus"><span class="visuallyhidden">Google+</span></a></li>
<li class="leaf"><a href="https://www.linkedin.com/shareArticle?mini=true&url=[path]&title=[title]&summary=[title]&source=[path]" class="social-media-linkedin-square"><span class="visuallyhidden">LinkedIn</span></a></li>
</ul>'),
    t('All'),
    t('Block'),
);