<?php

/**
 * @file
 * rif_sponsorship.captcha.inc
 */

/**
 * Implements hook_captcha_default_points().
 */
function rif_sponsorship_captcha_default_points() {
  $export = array();

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'comment_node_sponsor_form';
  $captcha->module = '';
  $captcha->captcha_type = 'default';
  $export['comment_node_sponsor_form'] = $captcha;

  return $export;
}
