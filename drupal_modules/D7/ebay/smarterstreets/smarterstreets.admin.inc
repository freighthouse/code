<?php

/**
 * @file
 * Administrative page callbacks for Smarterstreets 
 */

/**
 * Implements hook_settings_form
 */
function smarterstreets_admin_settings_form($form) {
  $form['sstreets_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Smartystreets Key'),
    '#default_value' => variable_get('sstreets_key', NULL),
    '#required' => TRUE,
  );
  $form['sstreets_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Smartystreets ID'),
    '#default_value' => variable_get('sstreets_id', NULL),
  );
  return system_settings_form($form);
}
