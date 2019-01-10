<?php

/**
 * @file
 * rif_sponsorship.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function rif_sponsorship_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access sponsor node view'.
  $permissions['access sponsor node view'] = array(
    'name' => 'access sponsor node view',
    'roles' => array(),
    'module' => 'internal_nodes',
  );

  // Exported permission: 'create any sponsorship_footer bean'.
  $permissions['create any sponsorship_footer bean'] = array(
    'name' => 'create any sponsorship_footer bean',
    'roles' => array(
      'Content Manager' => 'Content Manager',
      'Dvinci Content Mangaer' => 'Dvinci Content Mangaer',
      'LC Content Manager' => 'LC Content Manager',
      'RIF Admin Modules' => 'RIF Admin Modules',
      'Rif Admin' => 'Rif Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'create sponsor content'.
  $permissions['create sponsor content'] = array(
    'name' => 'create sponsor content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any sponsor content'.
  $permissions['delete any sponsor content'] = array(
    'name' => 'delete any sponsor content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any sponsorship_footer bean'.
  $permissions['delete any sponsorship_footer bean'] = array(
    'name' => 'delete any sponsorship_footer bean',
    'roles' => array(
      'Content Manager' => 'Content Manager',
      'Dvinci Content Mangaer' => 'Dvinci Content Mangaer',
      'LC Content Manager' => 'LC Content Manager',
      'RIF Admin Modules' => 'RIF Admin Modules',
      'Rif Admin' => 'Rif Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'delete own sponsor content'.
  $permissions['delete own sponsor content'] = array(
    'name' => 'delete own sponsor content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any sponsor content'.
  $permissions['edit any sponsor content'] = array(
    'name' => 'edit any sponsor content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any sponsorship_footer bean'.
  $permissions['edit any sponsorship_footer bean'] = array(
    'name' => 'edit any sponsorship_footer bean',
    'roles' => array(
      'Content Manager' => 'Content Manager',
      'Dvinci Content Mangaer' => 'Dvinci Content Mangaer',
      'LC Content Manager' => 'LC Content Manager',
      'RIF Admin Modules' => 'RIF Admin Modules',
      'Rif Admin' => 'Rif Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'edit own sponsor content'.
  $permissions['edit own sponsor content'] = array(
    'name' => 'edit own sponsor content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'view any sponsorship_footer bean'.
  $permissions['view any sponsorship_footer bean'] = array(
    'name' => 'view any sponsorship_footer bean',
    'roles' => array(
      'Content Manager' => 'Content Manager',
      'Dvinci Content Mangaer' => 'Dvinci Content Mangaer',
      'LC Content Manager' => 'LC Content Manager',
      'RIF Admin Modules' => 'RIF Admin Modules',
      'Rif Admin' => 'Rif Admin',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bean',
  );

  return $permissions;
}
