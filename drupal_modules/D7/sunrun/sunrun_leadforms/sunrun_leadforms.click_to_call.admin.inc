<?php
/**
 * @file
 * Main file for the Take the Pledge module.
 */

/**
 * Callback function creating a form used for configuring the Take the Pledge module.
 *
 * @return array Form structure
 */
function sunrun_leadforms_click_to_call_settings_admin() {

  drupal_add_css(drupal_get_path('module', 'sunrun_leadforms') . '/assets/css/admin.css');

  $form = array();

  $form['sunrun_leadforms_click_to_call_configuration'] = array(
    '#type' => 'fieldset',
    '#title' => 'Sunrun Click-to-Call Form Configuration',
    '#description' => '',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['sunrun_leadforms_click_to_call_configuration']['ctc_form_action'] = array(
    '#type' => 'textfield',
    '#title' => 'Salesforce Form URL',
    '#default_value' => variable_get('ctc_form_action', ''),
  );

  $form['sunrun_leadforms_click_to_call_configuration']['ctc_form_oid'] = array(
    '#type' => 'textfield',
    '#title' => 'Form OID',
    '#default_value' => variable_get('ctc_form_oid', ''),
  );

  $form['sunrun_leadforms_click_to_call_configuration']['ctc_form_return_url'] = array(
    '#type' => 'textfield',
    '#title' => 'Form Return URL (thank you page)',
    '#description' => 'Please enter the full url, e.g. http://www.sunrun.com/ty/thank-you',
    '#default_value' => variable_get('ctc_form_return_url', ''),
  );

  $form['sunrun_leadforms_click_to_call_configuration']['ctc_form_button_text'] = array(
    '#type' => 'textfield',
    '#title' => 'Form Button Text',
    '#default_value' => variable_get('ctc_form_button_text', 'Call me now'),
  );

  $form['sunrun_leadforms_click_to_call_kill_switch'] = array(
    '#type' => 'fieldset',
    '#title' => 'Sunrun Click-to-Call Kill Switch',
    '#description' => 'This option can override the hours set below to turn off the click-to-call forms. The forms will remain off until this option is unchecked.',
    '#collapsible' => TRUE,
  );

  $form['sunrun_leadforms_click_to_call_kill_switch']['ctc_kill_switch'] = array(
    '#type' => 'checkbox',
    '#title' => 'Turn off click-to-call',
    '#default_value' => variable_get('ctc_kill_switch', 0),
  );

  $form['sunrun_leadforms_click_to_call_hours'] = array(
    '#type' => 'fieldset',
    '#title' => 'Sunrun Click-to-Call Hours',
    '#description' => 'Time must be entered in using the 24-hour format without a colon, e.g. 1100 for 11:00am',
    '#collapsible' => TRUE,
    '#attributes' => array('class' => array('click-to-call-hours-form')),
  );

  $form['sunrun_leadforms_click_to_call_hours']['ctc_monday_open'] = array(
    '#type' => 'textfield',
    '#title' => t('Monday Open'),
    '#default_value' => variable_get('ctc_monday_open', '900'),
  );

  $form['sunrun_leadforms_click_to_call_hours']['ctc_monday_close'] = array(
    '#type' => 'textfield',
    '#title' => t('Monday Close'),
    '#default_value' => variable_get('ctc_monday_close', '2100'),
  );

  $form['sunrun_leadforms_click_to_call_hours']['ctc_tuesday_open'] = array(
    '#type' => 'textfield',
    '#title' => t('Tuesday Open'),
    '#default_value' => variable_get('ctc_tuesday_open', '900'),
  );

  $form['sunrun_leadforms_click_to_call_hours']['ctc_tuesday_close'] = array(
    '#type' => 'textfield',
    '#title' => t('Tuesday Close'),
    '#default_value' => variable_get('ctc_tuesday_close', '2100'),
  );

  $form['sunrun_leadforms_click_to_call_hours']['ctc_wednesday_open'] = array(
    '#type' => 'textfield',
    '#title' => t('Wednesday Open'),
    '#default_value' => variable_get('ctc_wednesday_open', '900'),
  );

  $form['sunrun_leadforms_click_to_call_hours']['ctc_wednesday_close'] = array(
    '#type' => 'textfield',
    '#title' => t('Wednesday Close'),
    '#default_value' => variable_get('ctc_wednesday_close', '2100'),
  );

  $form['sunrun_leadforms_click_to_call_hours']['ctc_thursday_open'] = array(
    '#type' => 'textfield',
    '#title' => t('Thursday Open'),
    '#default_value' => variable_get('ctc_thursday_open', '900'),
  );

  $form['sunrun_leadforms_click_to_call_hours']['ctc_thursday_close'] = array(
    '#type' => 'textfield',
    '#title' => t('Thursday Close'),
    '#default_value' => variable_get('ctc_thursday_close', '2100'),
  );

  $form['sunrun_leadforms_click_to_call_hours']['ctc_friday_open'] = array(
    '#type' => 'textfield',
    '#title' => t('Friday Open'),
    '#default_value' => variable_get('ctc_friday_open', '900'),
  );

  $form['sunrun_leadforms_click_to_call_hours']['ctc_friday_close'] = array(
    '#type' => 'textfield',
    '#title' => t('Friday Close'),
    '#default_value' => variable_get('ctc_friday_close', '2100'),
  );

  $form['sunrun_leadforms_click_to_call_hours']['ctc_saturday_open'] = array(
    '#type' => 'textfield',
    '#title' => t('Saturday Open'),
    '#default_value' => variable_get('ctc_saturday_open', '900'),
  );

  $form['sunrun_leadforms_click_to_call_hours']['ctc_saturday_close'] = array(
    '#type' => 'textfield',
    '#title' => t('Saturday Close'),
    '#default_value' => variable_get('ctc_saturday_close', '1730'),
  );

  $form['sunrun_leadforms_click_to_call_hours']['ctc_sunday_open'] = array(
    '#type' => 'textfield',
    '#title' => t('Sunday Open'),
    '#default_value' => variable_get('ctc_sunday_open', '1000'),
  );

  $form['sunrun_leadforms_click_to_call_hours']['ctc_sunday_close'] = array(
    '#type' => 'textfield',
    '#title' => t('Sunday Close'),
    '#default_value' => variable_get('ctc_sunday_close', '1830'),
  );

  return system_settings_form($form);
}
