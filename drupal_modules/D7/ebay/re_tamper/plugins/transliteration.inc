<?php

/**
 * @file
 * Transliterate.
 */

$plugin = array(
  'form' => 're_tamper_trans_form',
  'callback' => 're_tamper_trans_callback',
  'validate' => 're_tamper_trans_validate',
  'name' => 'Transliterate',
  'multi' => 'loop',
  'category' => 'HTML',
);

function re_tamper_trans_form($importer, $element_key, $settings) {
  $form = array();
  $form['info'] = array(
    '#type' => 'item',
    '#markup' => t('This has no options.  It will simply attempt to run the field through Transliterate prior to saving'),
  );
  return $form;
}

function re_tamper_trans_validate(&$settings) {
}

function re_tamper_trans_callback($result, $item_key, $element_key, &$field, $settings, $source) {
  $field = transliteration_get($field);
}
