<?php
/**
 * @file
 * ict_cron.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ict_cron_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer elysia_cron'.
  $permissions['administer elysia_cron'] = array(
    'name' => 'administer elysia_cron',
    'roles' => array(),
    'module' => 'elysia_cron',
  );

  return $permissions;
}
