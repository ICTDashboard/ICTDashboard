<?php
/**
 * @file
 * ict_departments.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function ict_departments_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:department:add user'
  $permissions['node:department:add user'] = array(
    'roles' => array(
      'Departmental Admin' => 'Departmental Admin',
    ),
  );

  // Exported og permission: 'node:department:administer group'
  $permissions['node:department:administer group'] = array(
    'roles' => array(
      'Departmental Admin' => 'Departmental Admin',
    ),
  );

  // Exported og permission: 'node:department:approve and deny subscription'
  $permissions['node:department:approve and deny subscription'] = array(
    'roles' => array(
      'Departmental Admin' => 'Departmental Admin',
    ),
  );

  // Exported og permission: 'node:department:create project content'
  $permissions['node:department:create project content'] = array(
    'roles' => array(
      'Departmental Admin' => 'Departmental Admin',
    ),
  );

  // Exported og permission: 'node:department:delete any project content'
  $permissions['node:department:delete any project content'] = array(
    'roles' => array(
      'Departmental Admin' => 'Departmental Admin',
    ),
  );

  // Exported og permission: 'node:department:delete own project content'
  $permissions['node:department:delete own project content'] = array(
    'roles' => array(
      'Departmental Admin' => 'Departmental Admin',
    ),
  );

  // Exported og permission: 'node:department:manage members'
  $permissions['node:department:manage members'] = array(
    'roles' => array(
      'Departmental Admin' => 'Departmental Admin',
    ),
  );

  // Exported og permission: 'node:department:manage permissions'
  $permissions['node:department:manage permissions'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:department:manage roles'
  $permissions['node:department:manage roles'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:department:subscribe'
  $permissions['node:department:subscribe'] = array(
    'roles' => array(
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:department:subscribe without approval'
  $permissions['node:department:subscribe without approval'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:department:unsubscribe'
  $permissions['node:department:unsubscribe'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:department:update any project content'
  $permissions['node:department:update any project content'] = array(
    'roles' => array(
      'Departmental Admin' => 'Departmental Admin',
    ),
  );

  // Exported og permission: 'node:department:update group'
  $permissions['node:department:update group'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:department:update own project content'
  $permissions['node:department:update own project content'] = array(
    'roles' => array(
      'Departmental Admin' => 'Departmental Admin',
    ),
  );

  return $permissions;
}
