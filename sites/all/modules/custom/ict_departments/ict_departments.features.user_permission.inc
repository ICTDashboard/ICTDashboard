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

  // Exported permission: 'create department content'.
  $permissions['create department content'] = array(
    'name' => 'create department content',
    'roles' => array(
      'Finance Admin' => 'Finance Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any department content'.
  $permissions['delete any department content'] = array(
    'name' => 'delete any department content',
    'roles' => array(
      'Finance Admin' => 'Finance Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own department content'.
  $permissions['delete own department content'] = array(
    'name' => 'delete own department content',
    'roles' => array(
      'Finance Admin' => 'Finance Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any department content'.
  $permissions['edit any department content'] = array(
    'name' => 'edit any department content',
    'roles' => array(
      'Finance Admin' => 'Finance Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own department content'.
  $permissions['edit own department content'] = array(
    'name' => 'edit own department content',
    'roles' => array(
      'Finance Admin' => 'Finance Admin',
    ),
    'module' => 'node',
  );

  return $permissions;
}
