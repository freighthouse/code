<?php

/**
 * @file
 * Include all migration code
 */

/**
 * Implements hook_migrate_api().
 */
function sunrun_import_migrate_api() {
  return array(
    'api' => 2,
    'groups' => array(
      'sunrun' => array(
        'title' => t('Sunrun'),
      ),
    ),    
    'migrations' => array(
      'SunrunCities' => array('class_name' => 'SunrunCitiesMigration', 'group_name' => 'sunrun'),
      'SunrunPressReleases' => array('class_name' => 'SunrunPressReleasesMigration', 'group_name' => 'sunrun'),
    ),
  );
}