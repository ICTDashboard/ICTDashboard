<?php
/**
 * @file
 * ict_departments.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function ict_departments_user_default_roles() {
  $roles = array();

  // Exported role: Departmental Admin.
  $roles['Departmental Admin'] = array(
    'name' => 'Departmental Admin',
    'weight' => 4,
    'machine_name' => 'departmental_admin',
  );

  return $roles;
}
