<?php
/**
 * Created by PhpStorm.
 * User: neemehta
 * Date: 4/6/14
 * Time: 4:43 PM
 */


/**
 * Admin form to configure opentoken module.
 */
function opentoken_settings_form() {
  $form = array();

  $form['opentoken_config_agent'] = array(
    '#title' => t('Agent Config'),
    '#description' => t('Copy and paste the content of agent-config.txt file here. Contact the SSO team to get this file.'),
    '#type' => 'textarea',
    '#default_value' => variable_get('opentoken_config_agent', ''),
    '#required' => TRUE,
  );

  $form['opentoken_sso_url'] = array(
    '#title' => t('SSO URL'),
    '#description' => t("Enter the SSO URL provided by the SSO team here. As an example, if the URL provided by SSO team is https://ssoqa.corp.ebay.com/sp/startSSO.ping?PartnerIdpId=PINGQA01&TargetResource={Enter_your_application_URL_encoded_here}, then enter https://ssoqa.corp.ebay.com/sp/startSSO.ping?PartnerIdpId=PINGQA01&TargetResource= in this field."),
    '#type' => 'textfield',
    '#default_value' => variable_get('opentoken_sso_url', ''),
    '#size' => 128,
    '#maxlength' => 512,
    '#required' => TRUE,
  );

  $form = system_settings_form($form);

  return $form;
}


/**
 * Validation handler for opentoken_settings_form().
 */
function opentoken_settings_form_validate($form, &$form_state) {
  $sso_url = $form_state['values']['opentoken_sso_url'];
  if (substr($sso_url, 0, 8) != 'https://') {
    form_set_error('opentoken_sso_url', t('Please provide a valid SSO URL. It should start with https://.'));
  }
}
