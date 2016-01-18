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
  'title' => t("ICT: Create update"),
  'description' => t('ICT: Create update'),
  'callback' => 'ict_update_creation_access',
  'required context' => new ctools_context_required(t('Node'), 'node'),
);


/**
 * Check for access.
 */
function ict_update_creation_access($conf, $context) {

  if (ict_project_access_update('create', $context->argument)) {
    return TRUE;
  }

  return FALSE;
}
