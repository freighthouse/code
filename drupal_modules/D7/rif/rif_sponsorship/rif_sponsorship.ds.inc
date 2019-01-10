<?php

/**
 * @file
 * rif_sponsorship.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function rif_sponsorship_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|sponsor|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'sponsor';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_logo',
      ),
    ),
    'fields' => array(
      'field_logo' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|sponsor|default'] = $ds_layout;

  return $export;
}
