<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Project History'),
  'description' => t('Baseline History for an individual project.'),
  'category' => t('ICT'),
  'render callback' => 'ict_project_project_history_render',
  'admin info' => 'ict_project_project_history_admin_info',
  'defaults' => array()
);

/**
 * return add project themed form
 */
function ict_project_project_history_render ($subtype, $conf, $panel_args, $context = NULL) {
  $block = new stdClass;
  $project = reset($panel_args);
  $block->content = ict_project_project_history($project);
  return $block;
}

/**
 * 'admin info' callback for panel pane.
 */
function ict_project_project_history_admin_info ($subtype, $conf, $contexts) {
  $block = new stdClass;
  $block->title = t('Baseline History block');
  $block->content = t('Baseline History block');

  return $block;
}
