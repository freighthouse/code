<?php

/**
 * @file
 * Plugin to handle the "Type" list for about/api-best-practices.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('Type list'),
  'single' => TRUE,
  // 'icon' => 'icon_page.png',
  'description' => t('Add type list.'),
  'category' => t('Apigee custom'),
  // 'render last' => TRUE,
  'defaults' => array(
    'content_types' => array(),
  ),
  'required context' => new ctools_context_optional(t('Taxonomy term'), 'taxonomy_term'),
);

/**
 * Output function for the 'type_list' content type.
 */
function apigee_mktg_custom_type_list_content_type_render($subtype, $conf, $panel_args, $context) {

  $term = !empty($context->data) ? $context->data : NULL;

  $block = new stdClass();

  $args = arg();

  $args[0] = 'api-best-practices';

  if (empty($args[1]) || is_numeric($args[1])) {
    $args[1] = 'all';
  }

  $types = array('all' => t('All')) + $conf['content_types'];

  $list = array();

  foreach ($types as $type => $label) {

    if ($term && $type != 'all') {
      $efq = new EntityFieldQuery();
      $nodes = $efq
      ->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', $type)
      ->propertyCondition('status', 1)
      ->fieldCondition('field_topic', 'target_id', $term->tid)
      ->range(0, 1)
      ->execute();
      if (empty($nodes['node'])) {
        continue;
      }
    }

    $arg_copy = $args;
    if ($type === 'all' && $args[1] === 'all') {
      unset($arg_copy[2]);
    }
    else {
      $arg_copy[2] = $type;
    }
    $type = str_replace('_', '-', $type);
    $list[] = l(t($label), implode('/', $arg_copy), array('attributes' => array('class' => array("type-$type"))));
  }

  $variables = array(
    'items' => $list,
    'title' => '',
    'type' => 'ul',
    'attributes' => array('class' => array('type-list')),
  );

  $block->title = t('Type');

  $block->content = theme_item_list($variables);

  return $block;
}

function apigee_mktg_custom_type_list_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $types = node_type_get_types();
  $options = array();
  foreach ($types as $key => $type) {
    $options[$key] = $type->name;
  }

  $form['content_types'] = array(
    '#type' => 'checkboxes',
    '#options' => $options,
    '#default_value' => array_keys($conf['content_types']),
    '#title' => t('Content types to use for the type list'),
  );

  return $form;
}

/**
 * The submit form stores the data in $conf.
 */
function apigee_mktg_custom_type_list_content_type_edit_form_submit($form, &$form_state) {
  $types = node_type_get_types();
  $form_state['conf']['content_types'] = array();
  $form_state['values']['content_types'] = array_filter($form_state['values']['content_types']);
  foreach ($form_state['values']['content_types'] as $type) {
    $form_state['conf']['content_types'][$type] = $types[$type]->name;
  }
}
