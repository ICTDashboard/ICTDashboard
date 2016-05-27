<?php
/**
 * @file
 * ict_pages.bean.inc
 */

/**
 * Implements hook_bean_admin_ui_types().
 */
function ict_pages_bean_admin_ui_types() {
  $export = array();

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'home_page_main_copy';
  $bean_type->label = 'Home Page Main copy';
  $bean_type->options = '';
  $bean_type->description = '';
  $export['home_page_main_copy'] = $bean_type;

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'opt_out_policy';
  $bean_type->label = 'Opt-Out Policy';
  $bean_type->options = '';
  $bean_type->description = '';
  $export['opt_out_policy'] = $bean_type;

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'sign_in_helptext';
  $bean_type->label = 'Sign-in helptext';
  $bean_type->options = '';
  $bean_type->description = '';
  $export['sign_in_helptext'] = $bean_type;

  return $export;
}
