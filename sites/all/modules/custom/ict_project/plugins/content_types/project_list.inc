<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Project List'),
  'description' => t('Project List'),
  'category' => t('ICT'),
  'render callback' => 'ict_project_project_list_render',
  'admin info' => 'ict_project_project_list_admin_info',
  'defaults' => array()
);

/**
 * return add project themed form
 */
function ict_project_project_list_render ($subtype, $conf, $panel_args, $context = NULL) {
  $block = new stdClass;
  $block->content = ict_project_project_list_block();
  return $block;
}

/**
 * 'admin info' callback for panel pane.
 */
function ict_project_project_list_admin_info ($subtype, $conf, $contexts) {
  $block = new stdClass;
  $block->title = t('Project List Block');
  $block->content = t('Project List Block');

  return $block;
}
