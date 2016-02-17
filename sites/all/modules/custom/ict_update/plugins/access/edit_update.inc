<?php

/**
 * @file
 * Plugin to provide access control based on whether a node belongs to a book.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */

$plugin = array(
  'title' => t("ICT: Edit update"),
  'description' => t('ICT: Edit update'),
  'callback' => 'ict_update_edit_access',
  'required context' => new ctools_context_required(t('Node'), 'node'),
);


/**
 * Check for access.
 */
function ict_update_edit_access($conf, $context) {
  $update_id = $context->argument;
  $update = $context->data;
  $project_id = $update->field_project['und'][0]['target_id'];
  if (ict_update_edit_allowed($project_id, $update_id)) {
    return TRUE;
  }

  return FALSE;
}
