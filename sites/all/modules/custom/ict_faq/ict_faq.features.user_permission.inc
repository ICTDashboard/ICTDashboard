<?php
/**
 * @file
 * ict_faq.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ict_faq_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create faq_item content'.
  $permissions['create faq_item content'] = array(
    'name' => 'create faq_item content',
    'roles' => array(
      'Finance Admin' => 'Finance Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any faq_item content'.
  $permissions['delete any faq_item content'] = array(
    'name' => 'delete any faq_item content',
    'roles' => array(
      'Finance Admin' => 'Finance Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own faq_item content'.
  $permissions['delete own faq_item content'] = array(
    'name' => 'delete own faq_item content',
    'roles' => array(
      'Finance Admin' => 'Finance Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any faq_item content'.
  $permissions['edit any faq_item content'] = array(
    'name' => 'edit any faq_item content',
    'roles' => array(
      'Finance Admin' => 'Finance Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own faq_item content'.
  $permissions['edit own faq_item content'] = array(
    'name' => 'edit own faq_item content',
    'roles' => array(
      'Finance Admin' => 'Finance Admin',
    ),
    'module' => 'node',
  );

  return $permissions;
}
