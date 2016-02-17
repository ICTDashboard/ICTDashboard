<?php
/**
 * @file
 * ict_update.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ict_update_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create update content'.
  $permissions['create update content'] = array(
    'name' => 'create update content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any update content'.
  $permissions['delete any update content'] = array(
    'name' => 'delete any update content',
    'roles' => array(
      'Departmental Admin' => 'Departmental Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own update content'.
  $permissions['delete own update content'] = array(
    'name' => 'delete own update content',
    'roles' => array(
      'Departmental Admin' => 'Departmental Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any update content'.
  $permissions['edit any update content'] = array(
    'name' => 'edit any update content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own update content'.
  $permissions['edit own update content'] = array(
    'name' => 'edit own update content',
    'roles' => array(),
    'module' => 'node',
  );

  return $permissions;
}
