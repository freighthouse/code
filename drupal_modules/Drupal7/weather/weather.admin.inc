<?php

// function weather_admin_display_form($form, &$form_state, $blocks, $theme, $block_regions = NULL) {

//   $form['#attached']['css'] = array(drupal_get_path('module', 'block') . '/block.css');

//   // Get a list of block regions if one was not provided.
//   if (!isset($block_regions)) {
//     $block_regions = system_region_list($theme, REGIONS_VISIBLE);
//   }
// }

/**
 * Page callback: Weather block settings
 *
 * @see weather_menu()
 */
function weather_admin_form()
{
    $form = array();

    $form['weather'] = array(
    '#type' => 'fieldset',
    '#title' => t('Block Message Settings'),
    );

    $form['weather']['Message']['weather_message'] = array(
    '#type' => 'textfield',
    '#title' => t('Block message'),
    '#description' => t('Customize your message here.'),
    '#default_value' => variable_get('weather_message', 'You last logged in at:'),
    );

    return system_settings_form($form);
}
