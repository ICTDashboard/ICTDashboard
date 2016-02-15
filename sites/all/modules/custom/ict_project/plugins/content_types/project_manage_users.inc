<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Project Manage Users'),
  'description' => t('Project Manage Users page.'),
  'category' => t('ICT'),
  'render callback' => 'ict_project_project_manage_users_render',
  'admin info' => 'ict_project_project_manage_users_admin_info',
  'defaults' => array()
);

/**
 * return add project themed form
 */
function ict_project_project_manage_users_render ($subtype, $conf, $panel_args, $context = NULL) {
  global $user;

  $block = new stdClass;
  $project_id = reset($panel_args);
  $project = node_load($project_id);

  if (!$project || $project->type != 'project') {
    drupal_not_found();
  }

  if (!ict_project_access_project('manage_users', $user, $project_id)) {
    drupal_access_denied();
  }

  $form = drupal_get_form('ict_project_manage_project_users_form', $project);
  $block->content = drupal_render($form);
  return $block;
}

/**
 * 'admin info' callback for panel pane.
 */
function ict_project_project_manage_users_admin_info ($subtype, $conf, $contexts) {
  $block = new stdClass;
  $block->title = t('Project Manage Users');
  $block->content = t('Project Manage Users');

  return $block;
}
