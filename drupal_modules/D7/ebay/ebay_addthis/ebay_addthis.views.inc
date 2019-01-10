<?php

/**
 * @file
 * Views definitions for mymodule module.
 */
 
/**
 * Implements hook_views_data().
 */
function ebay_addthis_views_data() {
  // We're registering the 'custom_teasers' table.
  $data['node']['ebay_addthis'] = array(
    'title' => t('eBay AddThis Links'),
    'help' => t('Display links to social sharing websites like Facebook, Twitter, Google+...'),
    'field' => array(
      'handler' => 'ebay_addthis_handler_field_ebay_addthis',
    ),
  );
  return $data;
}

/**
 * Implements hook_views_handlers().
 */
function ebay_addthis_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'ebay_addthis'),
    ),
    'handlers' => array(
      'ebay_addthis_handler_field_ebay_addthis' => array(
        'parent' => 'views_handler_field',
      ),
    ),
  );
}
