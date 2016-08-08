<?php
/**
 * @file
 * ict_cron.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function ict_cron_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'elysia_cron_script';
  $strongarm->value = '15 9 * * * ict_project_node_waiting_approval_reminder();
30 9 * * * ict_update_node_waiting_approval_reminder();
15 10 * * * ict_update_node_update_reminders();';
  $export['elysia_cron_script'] = $strongarm;

  return $export;
}
