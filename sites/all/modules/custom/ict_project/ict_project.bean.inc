<?php
/**
 * @file
 * ict_project.bean.inc
 */

/**
 * Implements hook_bean_admin_ui_types().
 */
function ict_project_bean_admin_ui_types() {
  $export = array();

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'prject_list_description';
  $bean_type->label = 'Prject list description';
  $bean_type->options = '';
  $bean_type->description = '';
  $export['prject_list_description'] = $bean_type;

  return $export;
}
