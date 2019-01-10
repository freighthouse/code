<?php

/**
 * @file
 * Strip HTML tags.
 */

$plugin = array(
  'form' => 're_tamper_msft_fix_form',
  'callback' => 're_tamper_msft_fix_callback',
  'validate' => 're_tamper_msft_fix_validate',
  'name' => 'Strip Microsoft Chars',
  'multi' => 'loop',
  'category' => 'HTML',
);

function re_tamper_msft_fix_form($importer, $element_key, $settings) {
  $form = array();
  $form['charset'] = array(
    '#type' => 'select',
    '#title' => t('Decode From'),
    '#default_value' => isset($settings['charset']) ? $settings['charset'] : NULL,
    '#options' => array(
      'ISO-8859-1'    => 'ISO-8859-1',
      'ISO-8859-2'    => 'ISO-8859-2',
      'Windows-1250'  => 'Windows-1250',
      'Windows-1252'  => 'Windows-1252',
    ),
  );
  return $form;
}

function re_tamper_msft_fix_validate(&$settings) {
  $settings['charset'] = trim($settings['charset']);
}

function re_tamper_msft_fix_callback($result, $item_key, $element_key, &$field, $settings, $source) {
  $field = iconv('Windows-1250', 'UTF-8//IGNORE', $field);	// This should do most of the work
  $field = transliteration_get($field);
}
