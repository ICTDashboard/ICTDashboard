<?php
/**
 * @file
 * ict_user_guide.bean.inc
 */

/**
 * Implements hook_bean_admin_ui_types().
 */
function ict_user_guide_bean_admin_ui_types() {
  $export = array();

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'user_guide';
  $bean_type->label = 'Block with edit button';
  $bean_type->options = '';
  $bean_type->description = 'Block containing user guide, feedback, etc. Editable by drupal and finance admins, viewable by authorized users.';
  $export['user_guide'] = $bean_type;

  return $export;
}
