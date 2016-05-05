<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Re-baseline Create'),
  'description' => t('Re-baseline create draft page.'),
  'category' => t('ICT'),
  'render callback' => 'ict_project_rebaseline_create_render',
  'admin info' => 'ict_project_rebaseline_create_admin_info',
  'defaults' => array()
);

/**
 * return add project themed form
 */
function ict_project_rebaseline_create_render ($subtype, $conf, $panel_args, $context = NULL) {
  $block = new stdClass;
  $parent_project = reset($panel_args);
  $block->content = ict_project_rebaseline_create_block($parent_project);
  return $block;
}

/**
 * 'admin info' callback for panel pane.
 */
function ict_project_rebaseline_create_admin_info ($subtype, $conf, $contexts) {
  $block = new stdClass;
  $block->title = t('Re-baseline Create Block');
  $block->content = t('Re-baseline Create Block');

  return $block;
}
