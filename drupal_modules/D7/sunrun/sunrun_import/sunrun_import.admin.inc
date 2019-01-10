<?php

/**
 * Callback function sunrun_import settings
 */
function sunrun_import_settings_admin() {
  $form = array();

  $form['jobs'] = array(
    '#type' => 'fieldset',
    '#title' => 'Newton Jobs',
    '#description' => '',
    '#collapsible' => TRUE,
  );

  $form['jobs']['sunrun_newton_job_list_url'] = array(
    '#type' => 'textfield',
    '#title' => t('List URL'),
    '#default_value' => variable_get('sunrun_newton_job_list_url', 'http://newton.newtonsoftware.com/career/CareerAtomFeed.action?clientId=8aa0050631ec0ce2013207e9e8563dfe'),
    '#description' => t('The url for the Newton jobs list.'),
  );

  $form['releases'] = array(
    '#type' => 'fieldset',
    '#title' => 'Press Releases',
    '#description' => '',
    '#collapsible' => TRUE,
  );

  $form['releases']['sunrun_press_release_list_url'] = array(
    '#type' => 'textfield',
    '#title' => t('List URL'),
    '#default_value' => variable_get('sunrun_press_release_list_url', 'http://xml.corporate-ir.net/irxmlclient.asp?compid=245283&reqtype=NEWSRELEASES_2'),
    '#description' => t('The url for the press release list URL.'),
  );

  $form['releases']['sunrun_press_release_item_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Item URL'),
    '#default_value' => variable_get('sunrun_press_release_item_url', 'http://xml.corporate-ir.net/irxmlclient.asp?compid=245283&reqtype=releasetxt&reqid=:id'),
    '#description' => t('The url for the press release item URL.'),
  );

  return system_settings_form($form);
}
