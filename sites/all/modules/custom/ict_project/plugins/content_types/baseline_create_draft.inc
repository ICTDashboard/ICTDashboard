<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Baseline Create Draft'),
  'description' => t('Baseline or re-baseline create draft page.'),
  'category' => t('ICT'),
  'render callback' => 'ict_project_baseline_create_draft_render',
  'admin info' => 'ict_project_baseline_create_draft_admin_info',
  'defaults' => array()
);

/**
 * return add project themed form
 */
function ict_project_baseline_create_draft_render ($subtype, $conf, $panel_args, $context = NULL) {
  $block = new stdClass;
  $nid = reset($panel_args);
  $block->content = ict_project_baseline_create_draft_block($nid);
  return $block;
}

/**
 * 'admin info' callback for panel pane.
 */
function ict_project_baseline_create_draft_admin_info ($subtype, $conf, $contexts) {
  $block = new stdClass;
  $block->title = t('Baseline Create Draft Block');
  $block->content = t('Baseline Create Draft Block');

  return $block;
}
