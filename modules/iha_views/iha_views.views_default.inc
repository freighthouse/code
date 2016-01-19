<?php
 /**
 * IHA views - JCerda for Project6
 *
 * Implements hook_views_default_views().
 *
 * Imports views from the /views directory.
 */

function iha_views_views_default_views() {
  $files = file_scan_directory(drupal_get_path('module', 'iha_views'). '/views', '/.view/');
  foreach ($files as $filepath => $file) {
    require $filepath;
    if (isset($view)) {
      $views[$view->name] = $view;
    }
  }
  if ($views) {
    return $views;
  }
}
