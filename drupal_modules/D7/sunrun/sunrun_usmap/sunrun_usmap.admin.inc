<?php
/**
 * Callback function creating a form used for configuring the sunrun_usmap module.
 *
 * @return array Form structure
 */
function sunrun_usmap_settings_admin($form, &$form_state) {
  $form['sunrun_usmap_form_settings'] = array(
    '#type' => 'fieldset',
    '#title' => 'Sunrun US Map Settings',
    '#description' => '',
    '#collapsible' => TRUE,
  );
  $form['sunrun_usmap_form_settings']['sunrun_states'] = array(
    '#type' => 'textarea',
    '#title' => t('Where\'s Sunrun'),
    '#rows' => 1,
    '#default_value' => variable_get('sunrun_states', ''),
    '#description' => t('The states served by Sunrun.'),
  );


  return system_settings_form($form);
}
