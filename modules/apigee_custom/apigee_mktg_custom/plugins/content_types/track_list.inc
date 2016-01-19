<?php

/**
 * @file
 * Plugin to handle the "Track" list for about/api-best-practices.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('Track list'),
  'single' => TRUE,
  // 'icon' => 'icon_page.png',
  'description' => t('Add track list.'),
  'category' => t('Apigee custom'),
  // 'render last' => TRUE,
  'defaults' => array(
    'vocabulary' => NULL,
  ),
);

/**
 * Output function for the 'type_list' content type.
 */
function apigee_mktg_custom_track_list_content_type_render($subtype, $conf, $panel_args) {
  $block = new stdClass();

  $query = new EntityFieldQuery();

  $entities = $query->entityCondition('entity_type', 'taxonomy_term')
                    ->propertyCondition('vid', $conf['vocabulary'])
                    // ->propertyCondition('status', 1)
                    ->execute();

  $terms = array(t('All'));
  $list = array();

  foreach ($entities['taxonomy_term'] as $term) {
    $terms[] = taxonomy_term_load($term->tid)->name;
  }
  $args = arg();
  $args[0] = 'iloveapis-conference';

  foreach ($terms as $term) {
    if ($term === 'All') {
      unset($args[2]);
      $args[1] = 'all';
    }
    else {
      $lower = str_replace(' ', '-', drupal_strtolower($term));
      $args[1] = $lower;
    }
    $list[] = l(t($term), implode('/', $args), array('attributes' => array('class' => array("track-$lower"))));
  }

  $variables = array(
    'items' => $list,
    'title' => '',
    'type' => 'ul',
    'attributes' => array('class' => array('track-list')),
  );

  $block->content = theme_item_list($variables);

  $block->title = t('Track');

  return $block;
}

function apigee_mktg_custom_track_list_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $vocabs = taxonomy_get_vocabularies();
  $options = array();
  foreach ($vocabs as $key => $vocab) {
    $options[$key] = $vocab->name;
  }

  $form['vocabulary'] = array(
    '#type' => 'radios',
    '#options' => $options,
    '#default_value' => $conf['vocabulary'],
    '#title' => t('Vocabulary to use for the track list'),
  );

  return $form;
}

/**
 * The submit form stores the data in $conf.
 */
function apigee_mktg_custom_track_list_content_type_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (array_key_exists($key, $form_state['values'])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}
