<?php

/**
 * @file
 * Drush support for the sunrun_import module
 */

/**
 * Implements hook_drush_command().
 */
function sunrun_import_drush_command() {

  $items['sunrun-import-jobs'] = array(
    'description' => 'Import Sunrun job listing from Newton software.',
    'aliases' => array('sij'),
    'callback' => 'sunrun_import_jobs'
  );

  return $items;
}

/**
 * Custom callback function used to import Sunrun job listings
 */
function sunrun_import_jobs() {
  $context  = stream_context_create(array('http' => array('header' => 'Accept: application/xml')));
  $url = variable_get('sunrun_newton_job_list_url', 'http://newton.newtonsoftware.com/career/CareerAtomFeed.action?clientId=8aa0050631ec0ce2013207e9e8563dfe');

  $xml = file_get_contents($url, false, $context);
  $jobs = simplexml_load_string($xml);

  db_set_active('srcustom');

  if(! db_table_exists('newton_jobs')) {
    drupal_set_message('The [newton_jobs] table doesn\'t exist', 'error');
    return;
  }

  // Delete old records
  db_delete('newton_jobs')->execute();
  drupal_set_message('Deleted old jobs');

  /* For each <jobs> node....process and store in database */
  foreach ($jobs->entry as $job) {
    $namespaces = $job->getNameSpaces(true);
    $newton = $job->children($namespaces['newton']);
    $tid = db_insert('newton_jobs')
      ->fields(array(
        'id' => $job->id,
        'title' => $job->title,
        'link' => $job->link->attributes()->{'href'},
        'category' => $job->category->attributes()->{'term'},
        'location' => $newton->location,
        'state' => $newton->state,
        'imported' => REQUEST_TIME
      ))
      ->execute();
  }

  db_set_active();

  drupal_set_message("Sunrun Import Jobs complete!");
}
