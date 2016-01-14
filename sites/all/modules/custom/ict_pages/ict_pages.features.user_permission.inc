<?php
/**
 * @file
 * ict_pages.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ict_pages_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access bean overview'.
  $permissions['access bean overview'] = array(
    'name' => 'access bean overview',
    'roles' => array(
      'Finance Admin' => 'Finance Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'administer bean settings'.
  $permissions['administer bean settings'] = array(
    'name' => 'administer bean settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'administer bean types'.
  $permissions['administer bean types'] = array(
    'name' => 'administer bean types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'administer beans'.
  $permissions['administer beans'] = array(
    'name' => 'administer beans',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'create any opt_out_policy bean'.
  $permissions['create any opt_out_policy bean'] = array(
    'name' => 'create any opt_out_policy bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'delete any opt_out_policy bean'.
  $permissions['delete any opt_out_policy bean'] = array(
    'name' => 'delete any opt_out_policy bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'edit any opt_out_policy bean'.
  $permissions['edit any opt_out_policy bean'] = array(
    'name' => 'edit any opt_out_policy bean',
    'roles' => array(
      'Finance Admin' => 'Finance Admin',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'edit bean view mode'.
  $permissions['edit bean view mode'] = array(
    'name' => 'edit bean view mode',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any opt_out_policy bean'.
  $permissions['view any opt_out_policy bean'] = array(
    'name' => 'view any opt_out_policy bean',
    'roles' => array(
      'Departmental Admin' => 'Departmental Admin',
      'Finance Admin' => 'Finance Admin',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view bean page'.
  $permissions['view bean page'] = array(
    'name' => 'view bean page',
    'roles' => array(
      'Finance Admin' => 'Finance Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view bean revisions'.
  $permissions['view bean revisions'] = array(
    'name' => 'view bean revisions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  return $permissions;
}
