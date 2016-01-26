<?php
/**
 * @file
 * ict_footer_menu.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ict_footer_menu_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer menu-footer-menu menu items'.
  $permissions['administer menu-footer-menu menu items'] = array(
    'name' => 'administer menu-footer-menu menu items',
    'roles' => array(
      'Finance Admin' => 'Finance Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'menu_admin_per_menu',
  );

  return $permissions;
}
