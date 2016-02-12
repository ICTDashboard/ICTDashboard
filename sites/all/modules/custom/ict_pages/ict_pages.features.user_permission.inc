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

  // Exported permission: 'add files to archive'.
  $permissions['add files to archive'] = array(
    'name' => 'add files to archive',
    'roles' => array(),
    'module' => 'elfinder',
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

  // Exported permission: 'administer file manager'.
  $permissions['administer file manager'] = array(
    'name' => 'administer file manager',
    'roles' => array(),
    'module' => 'elfinder',
  );

  // Exported permission: 'create any opt_out_policy bean'.
  $permissions['create any opt_out_policy bean'] = array(
    'name' => 'create any opt_out_policy bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'create new directories'.
  $permissions['create new directories'] = array(
    'name' => 'create new directories',
    'roles' => array(),
    'module' => 'elfinder',
  );

  // Exported permission: 'create new files'.
  $permissions['create new files'] = array(
    'name' => 'create new files',
    'roles' => array(),
    'module' => 'elfinder',
  );

  // Exported permission: 'delete any opt_out_policy bean'.
  $permissions['delete any opt_out_policy bean'] = array(
    'name' => 'delete any opt_out_policy bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'delete files and directories'.
  $permissions['delete files and directories'] = array(
    'name' => 'delete files and directories',
    'roles' => array(
      'Finance Admin' => 'Finance Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'elfinder',
  );

  // Exported permission: 'duplicate files'.
  $permissions['duplicate files'] = array(
    'name' => 'duplicate files',
    'roles' => array(),
    'module' => 'elfinder',
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

  // Exported permission: 'edit files'.
  $permissions['edit files'] = array(
    'name' => 'edit files',
    'roles' => array(),
    'module' => 'elfinder',
  );

  // Exported permission: 'extract files from archive'.
  $permissions['extract files from archive'] = array(
    'name' => 'extract files from archive',
    'roles' => array(
      'Finance Admin' => 'Finance Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'elfinder',
  );

  // Exported permission: 'file uploads'.
  $permissions['file uploads'] = array(
    'name' => 'file uploads',
    'roles' => array(
      'Finance Admin' => 'Finance Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'elfinder',
  );

  // Exported permission: 'paste from clipboard'.
  $permissions['paste from clipboard'] = array(
    'name' => 'paste from clipboard',
    'roles' => array(
      'Finance Admin' => 'Finance Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'elfinder',
  );

  // Exported permission: 'rename files and directories'.
  $permissions['rename files and directories'] = array(
    'name' => 'rename files and directories',
    'roles' => array(),
    'module' => 'elfinder',
  );

  // Exported permission: 'resize images'.
  $permissions['resize images'] = array(
    'name' => 'resize images',
    'roles' => array(
      'Finance Admin' => 'Finance Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'elfinder',
  );

  // Exported permission: 'use file manager'.
  $permissions['use file manager'] = array(
    'name' => 'use file manager',
    'roles' => array(
      'Finance Admin' => 'Finance Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'elfinder',
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
