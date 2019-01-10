<?php
  /**
   * Created by PhpStorm.
   * User: gshingler
   * Date: 5/23/18
   * Time: 1:02 PM
   */

  function literacy_tracker_password_config($form, &$form_state) {

    $temp_var = variable_get('literacy_tracker_password_list');
    if(empty($temp_var)) {
      $temp_var = array('format'=> 'plain_text', 'value' => 'piano');
    }

    $form['literacy_tracker_password_list'] = array(
      '#type' => 'text_format',
      '#description' => 'List of words that will be used when auto generating users passwords.<br />Spaces will turn into "-"<br />format: <em>[word], [word], [word], ... </em>',
      '#base_type' => 'textarea',
      '#title' => t('Password List'),
      '#rows' => '15',
      '#format' => 'plain_text',
      '#default_value' => $temp_var['value'],
    );

    return(system_settings_form($form));
  }