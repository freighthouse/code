<?php

/**
 * @file
 *
 * Plugin to provide a string context
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('Content type'),
  'description' => t('A context that is information about a content type.'),
  'context' => 'apigee_mktg_custom_context_create_content_type',
  'keyword' => 'content_type',
  'no ui' => TRUE,
  'context name' => 'content_type',
  'convert list' => array(
    'machine_name' => t('Machine name'),
    'label' => t('Label'),
    'label_plural' => t('Label plural'),
    'description' => t('Description'),
  ),
  'convert' => 'apigee_mktg_custom_context_content_type_convert',
  'placeholder form' => array(
    '#type' => 'textfield',
    '#description' => t('Enter the string for this context.'),
  ),
);

/**
 * It's important to remember that $conf is optional here, because contexts
 * are not always created from the UI.
 */
function apigee_mktg_custom_context_create_content_type($empty, $data = NULL, $conf = FALSE) {
  // The input is expected to be an object as created by ctools_break_phrase
  // which contains a group of string.

  $context = new ctools_context('content_type');
  $context->plugin = 'content_type';

  if ($empty) {
    return $context;
  }

  if (is_scalar($data)) {
    $type = db_query("SELECT * FROM {node_type} WHERE type = :type", array(':type' => $data))->fetchObject();
    if ($type === FALSE) {
      return;
    }
    else {
      $context->data = $type;
      $context->title = check_plain($context->data->name);
      return $context;
    }
  }
}

/**
 * Convert a context into a string.
 */
function apigee_mktg_custom_context_content_type_convert($context, $type) {
  switch ($type) {
    case 'machine_name':
      return $context->machine_name;
    case 'label':
      return $context->title;
    // I know this is wrong on many levels.
    case 'label_plural':
      return $context->title . 's';
    case 'description':
      return check_plain($context->data->description);
  }
}

