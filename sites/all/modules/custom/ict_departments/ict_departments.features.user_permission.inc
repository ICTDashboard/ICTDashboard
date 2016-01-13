<?php
/**
 * @file
 * ict_departments.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ict_departments_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer department vocabulary terms'.
  $permissions['administer department vocabulary terms'] = array(
    'name' => 'administer department vocabulary terms',
    'roles' => array(
      'Finance Admin' => 'Finance Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'vppr',
  );

  // Exported permission: 'delete terms in department'.
  $permissions['delete terms in department'] = array(
    'name' => 'delete terms in department',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in department'.
  $permissions['edit terms in department'] = array(
    'name' => 'edit terms in department',
    'roles' => array(
      'Finance Admin' => 'Finance Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  return $permissions;
}
