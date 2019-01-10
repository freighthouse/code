<?php
/**
 * @file
 * apigee_account_feature.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function apigee_account_feature_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'apigee_account';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'user/*' => 'user/*',
      ),
    ),
    'user' => array(
      'values' => array(
        'anonymous user' => 'anonymous user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'apigee_sso_ui-0' => array(
          'module' => 'apigee_sso_ui',
          'delta' => '0',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;
  $export['apigee_account'] = $context;

  return $export;
}
