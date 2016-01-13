<?php
/**
 * @file
 * ict_users.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function ict_users_user_default_roles() {
  $roles = array();

  // Exported role: Finance Admin.
  $roles['Finance Admin'] = array(
    'name' => 'Finance Admin',
    'weight' => 3,
    'machine_name' => 'finance_admin',
  );

  return $roles;
}
