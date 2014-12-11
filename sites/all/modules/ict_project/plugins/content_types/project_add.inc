<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Project Add'),
  'description' => t('Project Add page.'),
  'category' => t('ICT'),
  'render callback' => 'ict_project_project_add_render',
  'admin info' => 'ict_project_project_add_admin_info',
  'defaults' => array()
);

/**
 * return add project themed form
 */
function ict_project_project_add_render ($subtype, $conf, $panel_args, $context = NULL) {
  $block = new stdClass;
  $block->content = ict_project_project_add_block();
  return $block;
}

/**
 * 'admin info' callback for panel pane.
 */
function ict_project_project_add_admin_info ($subtype, $conf, $contexts) {
  $block = new stdClass;
  $block->title = t('Project Add Block');
  $block->content = t('Project Add Block');

  return $block;
}
