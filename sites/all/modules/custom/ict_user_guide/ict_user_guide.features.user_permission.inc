<?php
/**
 * @file
 * ict_user_guide.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ict_user_guide_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create any user_guide bean'.
  $permissions['create any user_guide bean'] = array(
    'name' => 'create any user_guide bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'delete any entityform'.
  $permissions['delete any entityform'] = array(
    'name' => 'delete any entityform',
    'roles' => array(
      'Finance Admin' => 'Finance Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'entityform',
  );

  // Exported permission: 'delete any user_guide bean'.
  $permissions['delete any user_guide bean'] = array(
    'name' => 'delete any user_guide bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'edit any entityform'.
  $permissions['edit any entityform'] = array(
    'name' => 'edit any entityform',
    'roles' => array(
      'Finance Admin' => 'Finance Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'entityform',
  );

  // Exported permission: 'edit any user_guide bean'.
  $permissions['edit any user_guide bean'] = array(
    'name' => 'edit any user_guide bean',
    'roles' => array(
      'Finance Admin' => 'Finance Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any entityform'.
  $permissions['view any entityform'] = array(
    'name' => 'view any entityform',
    'roles' => array(
      'Finance Admin' => 'Finance Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'entityform',
  );

  // Exported permission: 'view any user_guide bean'.
  $permissions['view any user_guide bean'] = array(
    'name' => 'view any user_guide bean',
    'roles' => array(
      'Finance Admin' => 'Finance Admin',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bean',
  );

  return $permissions;
}
