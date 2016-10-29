<?php

 /**
 *
 * Implements hook_views_default_views().
 *
 */

// function apiviews_views_default_views() {
//   $path = __DIR__ . '/views/*.view.inc';
//   $views = array();
//   foreach (glob($path) as $views_filename) {
//     $view = FALSE;
//     require_once($views_filename);
//     $views[$view->name] = $view; // $view exists in the included file.
//     unset($view);
//   }
//   return $views;
// }

function apiviews_views_default_views() {
  //Finds all files that match a given mask in a given directory
  //In our case, looks for any files named *.view in the /views directory
  $files = file_scan_directory(drupal_get_path('module', 'apiviews'). '/views', '/.view.inc/');
  foreach ($files as $filepath => $file) {
    require $filepath;
    if (isset($view)) {
      $views[$view->name] = $view;
    }
  }
  //Check that there are views in the directory
  //This keeps the site from throwing errors if there are no views to return
  if ($views) {
    return $views;
  }
}