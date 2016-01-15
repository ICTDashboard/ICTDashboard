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
  global $user;

  if ($user->uid == 1 || in_array($user->uid, ict_project_get_users($context->argument, ICT_PROJECT_EDITOR_ACCESS))) {
    return TRUE;
  }

  return FALSE;
}
