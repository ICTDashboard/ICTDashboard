<?php
/**
 * @file
 * ict_project.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ict_project_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access PDF version'.
  $permissions['access PDF version'] = array(
    'name' => 'access PDF version',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'print_pdf',
  );

  // Exported permission: 'administer honeypot'.
  $permissions['administer honeypot'] = array(
    'name' => 'administer honeypot',
    'roles' => array(),
    'module' => 'honeypot',
  );

  // Exported permission: 'bypass honeypot protection'.
  $permissions['bypass honeypot protection'] = array(
    'name' => 'bypass honeypot protection',
    'roles' => array(),
    'module' => 'honeypot',
  );

  // Exported permission: 'create any prject_list_description bean'.
  $permissions['create any prject_list_description bean'] = array(
    'name' => 'create any prject_list_description bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'create project content'.
  $permissions['create project content'] = array(
    'name' => 'create project content',
    'roles' => array(
      'Departmental Admin' => 'Departmental Admin',
      'Finance Admin' => 'Finance Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any prject_list_description bean'.
  $permissions['delete any prject_list_description bean'] = array(
    'name' => 'delete any prject_list_description bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'delete any project content'.
  $permissions['delete any project content'] = array(
    'name' => 'delete any project content',
    'roles' => array(
      'Departmental Admin' => 'Departmental Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own project content'.
  $permissions['delete own project content'] = array(
    'name' => 'delete own project content',
    'roles' => array(
      'Departmental Admin' => 'Departmental Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any prject_list_description bean'.
  $permissions['edit any prject_list_description bean'] = array(
    'name' => 'edit any prject_list_description bean',
    'roles' => array(
      'Finance Admin' => 'Finance Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'edit any project content'.
  $permissions['edit any project content'] = array(
    'name' => 'edit any project content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own project content'.
  $permissions['edit own project content'] = array(
    'name' => 'edit own project content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view any prject_list_description bean'.
  $permissions['view any prject_list_description bean'] = array(
    'name' => 'view any prject_list_description bean',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bean',
  );

  return $permissions;
}
