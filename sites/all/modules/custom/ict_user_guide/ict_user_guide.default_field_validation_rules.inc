<?php
/**
 * @file
 * ict_user_guide.default_field_validation_rules.inc
 */

/**
 * Implements hook_default_field_validation_rule().
 */
function ict_user_guide_default_field_validation_rule() {
  $export = array();

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'Valid email';
  $rule->name = 'valid_email';
  $rule->field_name = 'field_feedback_email';
  $rule->col = 'value';
  $rule->entity_type = 'entityform';
  $rule->bundle = 'feedback';
  $rule->validator = 'field_validation_email_validator';
  $rule->settings = array(
    'bypass' => 0,
    'roles' => array(
      1 => 0,
      2 => 0,
      30037204 => 0,
      41888116 => 0,
      153917155 => 0,
    ),
    'errors' => 0,
    'condition' => 0,
    'condition_wrapper' => array(
      'condition_field' => '',
      'condition_operator' => 'equals',
      'condition_value' => '',
    ),
  );
  $rule->error_message = 'Please enter valid E-mail';
  $export['valid_email'] = $rule;

  return $export;
}
