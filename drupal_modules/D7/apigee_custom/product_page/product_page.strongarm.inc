<?php
/**
 * @file
 * product_page.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function product_page_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__product_page';
  $strongarm->value = array(
    'view_modes' => array(
      'full' => array(
        'custom_settings' => TRUE,
      ),
      'teaser' => array(
        'custom_settings' => FALSE,
      ),
      'product_resources' => array(
        'custom_settings' => TRUE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'customers_cta' => array(
        'custom_settings' => FALSE,
      ),
      'customer_slider_a' => array(
        'custom_settings' => FALSE,
      ),
      'customer_slider_b' => array(
        'custom_settings' => FALSE,
      ),
      'customer_slider_intro' => array(
        'custom_settings' => FALSE,
      ),
      'linked_image' => array(
        'custom_settings' => FALSE,
      ),
      'live_thumbnail' => array(
        'custom_settings' => FALSE,
      ),
      'live_thumbnail_updated' => array(
        'custom_settings' => FALSE,
      ),
      'rss_text' => array(
        'custom_settings' => FALSE,
      ),
      'solutions_cs' => array(
        'custom_settings' => FALSE,
      ),
      'solutions' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '4',
        ),
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '1',
        ),
        'redirect' => array(
          'weight' => '2',
        ),
        'xmlsitemap' => array(
          'weight' => '3',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__product_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_product_page';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_product_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_product_page';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_product_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_product_page';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_product_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_product_page';
  $strongarm->value = '1';
  $export['node_preview_product_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_product_page';
  $strongarm->value = 0;
  $export['node_submitted_product_page'] = $strongarm;

  return $export;
}
