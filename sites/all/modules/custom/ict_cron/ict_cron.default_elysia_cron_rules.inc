<?php
/**
 * @file
 * ict_cron.default_elysia_cron_rules.inc
 */

/**
 * Implements hook_default_elysia_cron_rules().
 */
function ict_cron_default_elysia_cron_rules() {
  $cron_rules = array();

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'ict_project_cron';
  $cron_rule->disable = NULL;
  $cron_rule->rule = '* * */2 * *';
  $cron_rule->weight = NULL;
  $cron_rule->context = NULL;
  $cron_rules['ict_project_cron'] = $cron_rule;

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'ict_update_cron';
  $cron_rule->disable = NULL;
  $cron_rule->rule = '* * */2 * *';
  $cron_rule->weight = NULL;
  $cron_rule->context = NULL;
  $cron_rules['ict_update_cron'] = $cron_rule;

  return $cron_rules;

}
