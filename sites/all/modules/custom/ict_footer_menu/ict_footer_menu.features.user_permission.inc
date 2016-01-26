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
