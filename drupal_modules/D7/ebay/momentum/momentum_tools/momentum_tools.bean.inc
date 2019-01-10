<?php

/**
 * @file
 *   Handles bean block creation and type building
 *   Currently unused
 */

function _momentum_tools_bean_create($type, $delta, $title, $fields = array(), $label = NULL) {
  if ((empty($type)) || (empty($delta)) || (empty($title))) {
    return FALSE;
  }

  $bean = bean_create(array('type' => $type));
  $bean->delta = $delta;
  $bean->title = $title;
  $bean->label = $label;

  if (!empty($fields)) {
    foreach ($fields as $field) {
      switch ($field['type']) {
        case 'image':
          $path = $field['path'];
          $file = (object)array(
            'uid' => 1,
            'uri' => $path,
            'filemime' => file_get_mimetype($path),
            'status' => 1,
          );
          $file = file_copy($file, 'public://', FILE_EXISTS_REPLACE);
          $bean->{$field['name']}[LANGUAGE_NONE][0] = (array)$file;
          break;
        default:
          $bean->{$field['name']}[LANGUAGE_NONE][0]['value'] = $field['value'];
          break;
      }
    }
  }
  $bean->save();
}

function _momentum_tools_bean_type($type, $fields = array(), $label, $description = NULL) {
  if (empty($type)) {
    return FALSE;
  }

  /**
   * We start out by creating the bean type
   * $plugin_info = _bean_admin_default_plugin();
   * $plugin_info['name'] = filter_xss($type);
   * $bean_type = new BeanCustom($plugin_info);
   * $bean_type->type = filter_xss($type);
   * $bean_type->setLabel = filter_xss($label);
   * $bean_type->setDescription = filter_xss($description);
   * $bean_type->save(TRUE);
   */

  $plugin_info = _bean_admin_default_plugin();
  $plugin_info['name'] = $type;
  $plugin_info['description'] = $description;
  $plugin_info['label'] = $label;

  $bean_type = new BeanCustom($plugin_info);
  $bean_type->setType = filter_xss($type);
  $bean_type->setLabel = filter_xss($label);
  $bean_type->setDescription = filter_xss($description);
  $bean_type->save(TRUE);

  /**
   * Flush or we get notices
   */
  drupal_flush_all_caches();

  /**
   * And then we add instances/fields
   */
  if (!empty($fields)) {
    foreach ($fields as $field) {
      if ((!empty($field['name'])) && ($field['type'])) {

        switch($field['type']) {
          case 'image':
            _momentum_tools_create_image($field, $type);
            break;
          case 'text':
            _momentum_tools_create_textfield($field, $type);
            break;
        }
      }
    }
  }
}

/**
 * Create textfields and attach to bundle
 * @note
 *   Some dupe code here, but doing this for clarity
 */
function _momentum_tools_create_textfield($field, $bundle) {

  /**
   * We need to first create the field
   */
  field_create_field(array(
    'field_name' => $field['name'],
    'type' => $field['type'],
  ));

  /**
   * and then the field instance
   */
  $instance = array(
    'type' => $field['type'],
    'field_name' => $field['name'],
    'label' => $field['label'],
    'entity_type' => 'bean',
    'bundle' => $bundle,
    'description' => 'A field of name ' . $field['name'] . ' of type ' . $field['type'],
    'required' => !empty($field['required']) ? $field['required'] : FALSE,
    'display' => array(
      'default' => array(
        'label' => 'hidden',
      ),
    ),
  );
  /**
   * For text, we can pass:
   *  text_textfield, text_textarea
   */
  if (!empty($field['widget'])) {
    $instance['widget']['type'] = $field['widget'];
  }
  field_create_instance($instance);
}

function _momentum_tools_create_image($field, $bundle) {
  
  /**
   * Create the field
   */
  field_create_field(array(
    'field_name' => $field['name'],
    'type' => $field['type'],
    'settings' => array(
      'uri_scheme' => 'public',
    ),
  ));

  /**
   * And the instance
   */
  $instance = array(
    'bundle' => $bundle,
    'field_name' => $field['name'],
    'entity_type' => 'bean',
    'label' => $field['label'],
    'description' => 'A image of name ' . $field['name'] . ' of type ' . $field['type'],
    'required' => !empty($field['required']) ? $field['required'] : FALSE,
    'settings' => array(
      'file_extensions' => 'png jpg jpeg',
      'max_resolution' => !empty($field['max_resolution']) ? $field['max_resolution'] : NULL,
      'min_resolution' => !empty($field['min_resolution']) ? $field['min_resolution'] : NULL,
      'default_image' => !empty($field['default_image']) ? $field['default_image'] : NULL,
    ),
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'type' => $field['image_style']
      ),
    ),
  );
  field_create_instance($instance);
}

/**
        if (!empty($field['settings'])) {
          $instance['settings'] = array();
          $settings = $field['settings'];
          if (!empty($settings['file_extensions'])) {
            $instance['settings']['file_extensions'] = $settings['file_extensions']; 
          }
          if (!empty($settings['max_resolution'])) {
            $instance['settings']['max_resolution'] = $settings['max_resolution']; 
          }
          if (!empty($settings['min_resolution'])) {
            $instance['settings']['min_resolution'] = $settings['min_resolution']; 
          }
        }
        if (!empty($field['display'])) {
          $instance['display']['default'] = array(
            'label' => 'hidden',
          );
          $display = $field['display'];
          if (!empty($display['type'])) {
            $instance['display']['default']['type'] = $display['type'];
          }
        }
        field_create_instance($instance);
      }
*/

