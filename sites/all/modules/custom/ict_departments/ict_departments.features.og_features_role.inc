<?php
/**
 * @file
 * ict_departments.features.og_features_role.inc
 */

/**
 * Implements hook_og_features_default_roles().
 */
function ict_departments_og_features_default_roles() {
  $roles = array();

  // Exported OG Role: 'node:department:Departmental Admin'.
  $roles['node:department:Departmental Admin'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'department',
    'name' => 'Departmental Admin',
  );

  return $roles;
}
