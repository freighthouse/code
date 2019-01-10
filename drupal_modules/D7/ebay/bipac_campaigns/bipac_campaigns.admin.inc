<?php

/**
 * @file
 * Administrative page callbacks for BIPAC Campaigns
 */

/**
 * Implements hook_admin_settings() for module settings configuration.
 */
function bipac_campaigns_settings_form($form_state) {
  $form['bipac_campaigns_api_key'] = array(
    '#type' => 'textfield',
    '#title' => t('BIPAC API Key'),
    '#default_value' => variable_get('bipac_campaigns_api_key', NULL),
    '#description' => t('You must request this from BIPAC'),
  );
  $form['bipac_campaigns_parent'] = array(
    '#type' => 'textfield',
    '#title' => t('Organization'),
    '#default_value' => variable_get('bipac_campaigns_parent', NULL),
    '#description' => t('Parent organization value as defined by BIPAC.'),
  );
  $form['bipac_campaigns_production_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Production Endpoint'),
    '#default_value' => variable_get('bipac_campaigns_production_url', 'https://www.bipac.net/modules/directpost/letterpostfromwriterinfo.asp'),
  );
  $form['bipac_campaigns_test_url'] = array(
    '#type' => 'textfield',
    '#title' => t('URL for Test and Debug modes'),
    '#default_value' => variable_get('bipac_campaigns_test_url', 'https://www.bipac.net/modules/directpost/letterpostfromwriterinfo2.asp'),
  );
  $form['bipac_campaigns_generic_error'] = array(
    '#type' => 'textarea',
    '#title' => t('Generic BIPAC error'),
    '#description' => t('The error that will be presented whenever BIPAC returns anything other than a 200 code (success).  This can also be set for each campaign.'),
    '#default_value' => variable_get('bipac_generic_error', 'Oops.  Either your address didn\'t pass USPS validation or there are no active campaigns in your Congressional District.'),
  );
  $form['bipac_campaigns_generic_thank_you'] = array(
    '#type' => 'textfield',
    '#title' => t('Generic BIPAC Thank You'),
    '#description' => t('The page the user will be redirected to upon successful submission.  This can also be set for each campaign.'),
    '#default_value' => variable_get('bipac_campaigns_generic_thank_you', NULL),
  );
  return system_settings_form($form);
}
