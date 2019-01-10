<?php

/**
 * General settings form
 */
function sunrun_calculator_settings_form() {
  $form['sunrun_calculator']['sunrun_calculator_enable_caching'] = [
    '#title' => t('Enable Caching'),
    '#type' => 'checkbox',
    '#default_value' => variable_get('sunrun_calculator_enable_caching'),
    '#description' => t('When caching is enabled, requests are cached and matched based on a combination of the zipcode and monthy payment estimate.'),
  ];

  $form['sunrun_calculator']['sunrun_calculator_enable_logging'] = [
    '#title' => t('Enable Database Logging'),
    '#type' => 'checkbox',
    '#default_value' => variable_get('sunrun_calculator_enable_logging'),
    '#description' => t('When database logging is enabled, all requests and responses are logged to the <i>sunrun_calculator_logging</i> table.')
  ];
  
  // Zillow API
  $form['zillow'] = [
    '#title' => t('Zillow Settings'),
    '#type' => 'fieldset'
  ];
  
  $form['zillow']['zillow_api_url'] = [
    '#title' => t('Host'),
    '#type' => 'textfield',
    '#default_value' => variable_get('zillow_api_url')
  ];
  
  $form['zillow']['zillow_api_zwsid'] = [
    '#title' => t('ZWS-ID'),
    '#type' => 'textfield',
    '#default_value' => variable_get('zillow_api_zwsid')
  ];
  
  // Genability API
  $form['genability'] = [
    '#title' => t('Genability Settings'),
    '#type' => 'fieldset',
  ];

  $form['genability']['sunrun_genability_host'] = [
    '#title' => t('Host'),
    '#type' => 'textfield',
    '#default_value' => variable_get('sunrun_genability_host'),
  ];

  $form['genability']['sunrun_genability_username'] = [
    '#title' => t('Username'),
    '#type' => 'textfield',
    '#default_value' => variable_get('sunrun_genability_username'),
  ];

  $form['genability']['sunrun_genability_password'] = [
    '#title' => t('Password'),
    '#type' => 'textfield',
    '#default_value' => variable_get('sunrun_genability_password'),
  ];

  $form['genability']['sunrun_genability_error_redirect_url'] = [
    '#title' => t('API Error Redirect URL'),
    '#description' => t('The user will be redirected to this url if there is an issue with the genability api'),
    '#type' => 'textfield',
    '#default_value' => variable_get('sunrun_genability_error_redirect_url', 'ty/thank-you-savings-estimate-not-available'),
    '#required' => TRUE
  ];
  
  return system_settings_form($form);
}
