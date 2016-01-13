<?php
/**
 * @file
 * ict_users.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ict_users_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access user profiles'.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      'Finance Admin' => 'Finance Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'access users overview'.
  $permissions['access users overview'] = array(
    'name' => 'access users overview',
    'roles' => array(
      'Finance Admin' => 'Finance Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'administer funding_source vocabulary terms'.
  $permissions['administer funding_source vocabulary terms'] = array(
    'name' => 'administer funding_source vocabulary terms',
    'roles' => array(),
    'module' => 'vppr',
  );

  // Exported permission: 'administer permissions'.
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer project_category vocabulary terms'.
  $permissions['administer project_category vocabulary terms'] = array(
    'name' => 'administer project_category vocabulary terms',
    'roles' => array(),
    'module' => 'vppr',
  );

  // Exported permission: 'administer project_owner vocabulary terms'.
  $permissions['administer project_owner vocabulary terms'] = array(
    'name' => 'administer project_owner vocabulary terms',
    'roles' => array(),
    'module' => 'vppr',
  );

  // Exported permission: 'administer project_stage vocabulary terms'.
  $permissions['administer project_stage vocabulary terms'] = array(
    'name' => 'administer project_stage vocabulary terms',
    'roles' => array(),
    'module' => 'vppr',
  );

  // Exported permission: 'administer tags vocabulary terms'.
  $permissions['administer tags vocabulary terms'] = array(
    'name' => 'administer tags vocabulary terms',
    'roles' => array(),
    'module' => 'vppr',
  );

  // Exported permission: 'administer users'.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'cancel account'.
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'cancel users with role 2'.
  $permissions['cancel users with role 2'] = array(
    'name' => 'cancel users with role 2',
    'roles' => array(
      'Finance Admin' => 'Finance Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'change own username'.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(
      'Finance Admin' => 'Finance Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'create users'.
  $permissions['create users'] = array(
    'name' => 'create users',
    'roles' => array(
      'Finance Admin' => 'Finance Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'edit users with role 2'.
  $permissions['edit users with role 2'] = array(
    'name' => 'edit users with role 2',
    'roles' => array(
      'Finance Admin' => 'Finance Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'select account cancellation method'.
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  return $permissions;
}
