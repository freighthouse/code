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
function sunrun_leadforms_settings_admin() {
  $form = array();

  $form['sunrun_leadforms_settings'] = array(
    '#type' => 'fieldset',
    '#title' => 'Sunrun Leadform Settings',
    '#description' => '',
    '#collapsible' => TRUE,
  );

  $form['sunrun_leadforms_settings']['marketo_environment'] = array(
    '#type' => 'textfield',
    '#title' => t('Marketo Environment'),
    '#default_value' => variable_get('marketo_environment', '//app-ab02.marketo.com'),
    '#description' => t('The environment url for your Marketo account.'),
  );

  $form['sunrun_leadforms_settings']['tcpa_disclosure'] = array(
   '#type' => 'textarea',
   '#title' => t('TCPA Disclosure'),
   '#default_value' => variable_get('tcpa_disclosure', 'By clicking above, I authorize Sunrun to call me and send pre-recorded messages and text messages to me about Sunrun products and services at the telephone number I entered above, using an autodialer, even if I am on a national or state "Do Not Call" list. Message and data rates may apply. I understand that consent here is not a condition of purchase.'),
   '#description' => t('The Telephone Consumer Protection Act (TCPA) disclosure'),
 );

    $form['sunrun_leadforms_settings']['tcpa_disclosure_spanish'] = array(
        '#type' => 'textarea',
        '#title' => t('TCPA Disclosure - Spanish'),
        '#default_value' => variable_get('tcpa_disclosure_spanish', 'Enter Spanish TCPA version'),
        '#description' => t('The Telephone Consumer Protection Act (TCPA) disclosure'),
    );


  $form['sunrun_leadforms_settings']['oot_msg'] = array(
    '#type' => 'textfield',
    '#title' => t('Out of territory message'),
    '#default_value' => variable_get('oot_msg', 'Sorry, we are not taking new customers in your area yet.'),
);

  $form['sunrun_leadforms_settings']['munchkin_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Marketo Munchkin ID'),
    '#default_value' => variable_get('munchkin_id', '831-VJO-525'),
    '#description' => t('The Munchkin ID for your Marketo account.'),
  );

  $form['sunrun_marketo_settings_forms'] = array(
    '#type' => 'fieldset',
    '#title' => 'Sunrun Marketo Form Settings',
    '#description' => '',
    '#collapsible' => TRUE,
  );

  $form['sunrun_marketo_settings_forms']['get_quote_form_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Get Quote Form ID'),
    '#default_value' => variable_get('get_quote_form_id', '1239'),
    '#description' => t('The Form ID for the Get Quote form.'),
  );

  $form['sunrun_marketo_settings_forms']['get_quote_form_step_two_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Get Quote Form Step 2 ID'),
    '#default_value' => variable_get('get_quote_form_step_two_id', '1398'),
    '#description' => t('The Form ID for the Get Quote form second step.'),
  );

  $form['sunrun_marketo_settings_forms']['standard_lead_form_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Standard Leadform ID'),
    '#default_value' => variable_get('standard_lead_form_id', '1351'),
    '#description' => t('The Form ID for the Standard Leadform.'),
  );

  $form['sunrun_marketo_settings_forms']['standard_lead_form_step_two_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Standard Leadform Step 2 ID'),
    '#default_value' => variable_get('standard_lead_form_step_two_id', '1357'),
    '#description' => t('The Form ID for the Standard Leadform Second Step.'),
  );

  $form['sunrun_marketo_settings_forms']['standard_costco_lead_form_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Standard Costco Leadform ID'),
    '#default_value' => variable_get('standard_costco_lead_form_id', '1404'),
    '#description' => t('The Form ID for the Standard Costco Leadform.'),
  );

  $form['sunrun_marketo_settings_forms']['standard_bestbuy_lead_form_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Standard Best Buy Leadform ID'),
    '#default_value' => variable_get('standard_bestbuy_lead_form_id', '1406'),
    '#description' => t('The Form ID for the Standard Best Buy Leadform.'),
  );

  $form['sunrun_marketo_settings_forms']['purls_form_id'] = array(
    '#type' => 'textfield',
    '#title' => t('PURLs Form ID'),
    '#default_value' => variable_get('purls_form_id', '1064'),
    '#description' => t('The Form ID for the PURLs form.'),
  );

  $form['sunrun_marketo_settings_forms']['softsignup_form_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Soft Signup Form ID'),
    '#default_value' => variable_get('softsignup_form_id', '1352'),
    '#description' => t('The Form ID for the Soft Signup form.'),
  );

  $form['sunrun_marketo_settings_forms']['solar_calculator_form_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Solar Calculator Form ID'),
    '#default_value' => variable_get('solar_calculator_form_id', '1303'),
    '#description' => t('The Form ID for the Solar Calculator form.'),
  );

  $form['sunrun_marketo_settings_forms']['referral_form_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Referral Form ID'),
    '#default_value' => variable_get('referral_form_id', '1187'),
    '#description' => t('The Form ID for the Solar Calculator form.'),
  );

  $form['sunrun_homepage_form_settings'] = array(
    '#type' => 'fieldset',
    '#title' => 'Homepage Leadform Settings',
    '#description' => '',
    '#collapsible' => TRUE,
  );

  $form['sunrun_homepage_form_settings']['homepage_leadform_headline'] = array(
    '#type' => 'textfield',
    '#title' => t('Homepage Leadform Headline'),
    '#default_value' => variable_get('homepage_leadform_headline', ''),
    '#description' => t('The headline text for the homepage leadform.'),
  );

  $form['sunrun_homepage_form_settings']['homepage_leadform_blurb'] = array(
    '#type' => 'textarea',
    '#title' => t('Homepage Leadform Blurb'),
    '#default_value' => variable_get('homepage_leadform_blurb', ''),
    '#description' => t('The blurb text for the homepage leadform.'),
  );

  $form['sunrun_rating_solar_star_slider_txt_settings_forms'] = array(
    '#type' => 'fieldset',
    '#title' => t('PURLs Star Rating Text'),
    '#description' => '',
    '#collapsible' => TRUE,
    '#weight' => 3,
  );

  $form['sunrun_rating_solar_star_slider_txt_settings_forms']['sunrun_3_stars_or_less'] = array(
    '#type' => 'fieldset',
    '#title' => '3 stars or less',
    '#description' => '',
    '#collapsible' => TRUE,
    '#weight' => 1,
  );
  $form['sunrun_rating_solar_star_slider_txt_settings_forms']['sunrun_3_stars_or_less']['3_stars_or_less_headline_txt'] = array(
    '#type' => 'textfield',
    '#title' => t('Headline Text'),
    '#default_value' => variable_get('3_stars_or_less_headline_txt'),
  );
  $form['sunrun_rating_solar_star_slider_txt_settings_forms']['sunrun_3_stars_or_less']['3_stars_or_less_body_text'] = array(
    '#type' => 'textarea',
    '#title' => t('Body Text'),
    '#default_value' => variable_get('3_stars_or_less_body_text'),
  );

  $form['sunrun_rating_solar_star_slider_txt_settings_forms']['sunrun_equal_4_stars'] = array(
    '#type' => 'fieldset',
    '#title' => '4 stars',
    '#description' => '',
    '#collapsible' => TRUE,
    '#weight' => 2,
  );

  $form['sunrun_rating_solar_star_slider_txt_settings_forms']['sunrun_equal_4_stars']['equal_4_stars_headline_txt'] = array(
    '#type' => 'textfield',
    '#title' => t('Headline Text'),
    '#default_value' => variable_get('equal_4_stars_headline_txt'),
  );

  $form['sunrun_rating_solar_star_slider_txt_settings_forms']['sunrun_equal_4_stars']['equal_4_stars_body_text'] = array(
    '#type' => 'textarea',
    '#title' => t('Body Text'),
    '#default_value' => variable_get('equal_4_stars_body_text'),
  );

  return system_settings_form($form);
}
