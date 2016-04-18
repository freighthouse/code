<?php

/**
 * @file
 *
 * Plugin to provide an argument handler for a raw string
 */
/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t("Conent type"),
  // keyword to use for %substitution
  'keyword' => 'content_type',
  'description' => t('Get information about a given content type.'),
  // 'settings form' => 'ctools_string_settings_form',
  'context' => 'apigee_mktg_custom_content_type_context',
  'placeholder form' => array(
    '#type' => 'textfield',
    '#description' => t('Enter a value for this content type.'),
  ),
  // 'path placeholder' => 'ctools_string_path_placeholder', // This is in pagemanager.
);

/**
 * Discover if this argument gives us the term we crave.
 */
function apigee_mktg_custom_content_type_context($arg = null, $conf = null, $empty = false) 
{
    // If unset it wants a generic, unfilled context.
    if ($empty) {
        return ctools_context_create_empty('content_type');
    }

    return ctools_context_create('content_type', $arg);
}

/**
 * Settings form for the argument
 */
// function ctools_string_settings_form(&$form, &$form_state, $conf) {
//   $form['settings']['use_tail'] = array(
//     '#title' => t('Get all arguments after this one'),
//     '#type' => 'checkbox',
//     '#default_value' => !empty($conf['use_tail']),
//     '#description' => t('If checked, this string will include all arguments. For example, if the path is "path/%" and the user visits "path/foo/bar", if this is not checked the string will be "foo". If it is checked the string will be "foo/bar".'),
//   );
// //  return $form;
// }

/**
 * Switch the placeholder based upon user settings.
 */
// function ctools_string_path_placeholder($argument) {
//   if (empty($argument['settings']['use_tail'])) {
//     return '%pm_arg';
//   }
//   else {
//     return '%pm_arg_tail';
//   }
// }
