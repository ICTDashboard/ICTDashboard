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

  // Exported permission: 'access administration menu'.
  $permissions['access administration menu'] = array(
    'name' => 'access administration menu',
    'roles' => array(
      'Finance Admin' => 'Finance Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'access administration pages'.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      'Finance Admin' => 'Finance Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access content overview'.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      'Finance Admin' => 'Finance Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access dashboard'.
  $permissions['access dashboard'] = array(
    'name' => 'access dashboard',
    'roles' => array(
      'Finance Admin' => 'Finance Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'dashboard',
  );

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

  // Exported permission: 'administer autologout'.
  $permissions['administer autologout'] = array(
    'name' => 'administer autologout',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'autologout',
  );

  // Exported permission: 'administer filters'.
  $permissions['administer filters'] = array(
    'name' => 'administer filters',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
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
      'Finance Admin' => 'Finance Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'assign roles'.
  $permissions['assign roles'] = array(
    'name' => 'assign roles',
    'roles' => array(
      'Finance Admin' => 'Finance Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'roleassign',
  );

  // Exported permission: 'cancel account'.
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'cancel users with role 153917155'.
  $permissions['cancel users with role 153917155'] = array(
    'name' => 'cancel users with role 153917155',
    'roles' => array(
      'Finance Admin' => 'Finance Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'administerusersbyrole',
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

  // Exported permission: 'change own logout threshold'.
  $permissions['change own logout threshold'] = array(
    'name' => 'change own logout threshold',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'autologout',
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

  // Exported permission: 'create page content'.
  $permissions['create page content'] = array(
    'name' => 'create page content',
    'roles' => array(
      'Finance Admin' => 'Finance Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
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

  // Exported permission: 'delete any page content'.
  $permissions['delete any page content'] = array(
    'name' => 'delete any page content',
    'roles' => array(
      'Finance Admin' => 'Finance Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own page content'.
  $permissions['delete own page content'] = array(
    'name' => 'delete own page content',
    'roles' => array(
      'Finance Admin' => 'Finance Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'display drupal links'.
  $permissions['display drupal links'] = array(
    'name' => 'display drupal links',
    'roles' => array(
      'Finance Admin' => 'Finance Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'edit any page content'.
  $permissions['edit any page content'] = array(
    'name' => 'edit any page content',
    'roles' => array(
      'Finance Admin' => 'Finance Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own page content'.
  $permissions['edit own page content'] = array(
    'name' => 'edit own page content',
    'roles' => array(
      'Finance Admin' => 'Finance Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit users with role 153917155'.
  $permissions['edit users with role 153917155'] = array(
    'name' => 'edit users with role 153917155',
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

  // Exported permission: 'flush caches'.
  $permissions['flush caches'] = array(
    'name' => 'flush caches',
    'roles' => array(
      'Finance Admin' => 'Finance Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'select account cancellation method'.
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'use text format ds_code'.
  $permissions['use text format ds_code'] = array(
    'name' => 'use text format ds_code',
    'roles' => array(),
    'module' => 'filter',
  );

  // Exported permission: 'use text format filtered_html'.
  $permissions['use text format filtered_html'] = array(
    'name' => 'use text format filtered_html',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format full_html'.
  $permissions['use text format full_html'] = array(
    'name' => 'use text format full_html',
    'roles' => array(
      'Finance Admin' => 'Finance Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'view the administration theme'.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(
      'Finance Admin' => 'Finance Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  return $permissions;
}
