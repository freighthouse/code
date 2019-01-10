<?php

/**
 * Here we override the default HTML output of drupal.
 * refer to http://drupal.org/node/550722
 */

/**
 * Insert the ability to define a page.tpl.php based on node-types
 * Pre-process for page.tpl.php
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("region" in this case.)
 */

function ez_preprocess_page(&$variables, $hook) {
	if (!empty($variables['node'])) {
		$variables['theme_hook_suggestions'][] = 'page__node_' . $variables['node']->type;
  }
  if(arg(1) == 193) {
    $variables['theme_hook_suggestions'][] =  'page__404_error';
  }
  if (isset($variables['node']) && $variables['node']->type == 'signup_page') {
    drupal_add_js(drupal_get_path('theme', 'ez') . '/js/jquery.validate.min.js');
		drupal_add_js(drupal_get_path('theme', 'ez') . '/js/jquery.validate.additional-methods.min.js');
		drupal_add_js(drupal_get_path('theme', 'ez') . '/js/validate.js');
  }
}

function ez_username_alter(&$name, $account) {
  if (isset($account->uid)) {
    $this_user = user_load($account->uid);//loads the custom fields
    $name = $this_user->field_first_name['und'][0]['value'].' '.$this_user->field_last_name['und'][0]['value'];
  }
}

/**
 * Implements theme_menu_tree__menu_block().
 */
function ez_menu_tree__menu_block(&$variables) {
  return '<ul class="nav nav-pills nav-stacked">' . $variables['tree'] . '</ul>';
}

/**
 * Add some classes to submit buttons
 */

function ez_form_alter(&$form, &$form_state, $form_id) {
  if (!empty($form['actions']) && $form['actions']['submit']) {
    $form['actions']['submit']['#attributes'] = array('class' => array('btn', 'btn-lg', 'btn-rounded', 'btn-orange'));
  }
}


/**
 * Remove unneccessary CSS
 */
function ez_css_alter(&$css,&$variables) {
  $exclude = array(
    'misc/vertical-tabs.css' => FALSE,
    'modules/aggregator/aggregator.css' => FALSE,
    'modules/block/block.css' => FALSE,
    'modules/book/book.css' => FALSE,
    'modules/comment/comment.css' => FALSE,
    'modules/dblog/dblog.css' => FALSE,
    'modules/file/file.css' => FALSE,
    'modules/filter/filter.css' => FALSE,
    'modules/forum/forum.css' => FALSE,
    'modules/help/help.css' => FALSE,
    'modules/menu/menu.css' => FALSE,
    'modules/node/node.css' => FALSE,
    'modules/openid/openid.css' => FALSE,
    'modules/poll/poll.css' => FALSE,
    'modules/profile/profile.css' => FALSE,
    'modules/search/search.css' => FALSE,
    'modules/statistics/statistics.css' => FALSE,
    'modules/syslog/syslog.css' => FALSE,
    'modules/system/admin.css' => FALSE,
    'modules/system/maintenance.css' => FALSE,
    'modules/system/system.css' => FALSE,
    'modules/system/system.admin.css' => FALSE,
    'modules/system/system.base.css' => FALSE,
    'modules/system/system.maintenance.css' => FALSE,
    'modules/system/system.menus.css' => FALSE,
    'modules/system/system.messages.css' => FALSE,
    'modules/system/system.theme.css' => FALSE,
    'modules/taxonomy/taxonomy.css' => FALSE,
    'modules/tracker/tracker.css' => FALSE,
    'modules/update/update.css' => FALSE,
    'modules/user/user.css' => FALSE,
  );
  if (!(bool)$GLOBALS['user']->uid){
    $css = array_diff_key($css, $exclude);
  }
}

function ez_js_alter(&$js) {
  if (!(bool)$GLOBALS['user']->uid){
    unset($js['settings']);
  }

  foreach($js as $key => $value) {
    if(is_int($key) && strpos($value['data'], 'vwo_code') !== false) {
      unset($js[$key]);
    }
  }
}


function ez_html_head_alter(&$head_elements) {
  unset($head_elements['system_meta_generator']);
  foreach ($head_elements as $key => $element) {
    if (isset($element['#attributes']['rel']) && $element['#attributes']['rel'] == 'shortlink') {
      unset($head_elements[$key]);
    }

    if (isset($element['#attributes']['rel']) && $element['#attributes']['rel'] == 'canonical') {
      $head_elements[$key]['#attributes']['href'] = base_path();
    }
  }

  $js = drupal_add_js();
  foreach($js as $key => $value) {
    if(is_int($key) && strpos($value['data'], 'vwo_code') !== false) {
      $element = array(
        '#type' => 'markup',
        '#markup' => '<script type="text/javascript">' . $value['data'] . '</script>',
      );
      $head_elements['vwo'] = $element;
    }
  }
}
