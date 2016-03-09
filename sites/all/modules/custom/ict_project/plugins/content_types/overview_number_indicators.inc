<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Overview Description and Number Indicators'),
  'description' => t('Overview Description and Number Indicators.'),
  'category' => t('ICT'),
  'render callback' => 'ict_projects_overview_number_indicators_render',
  'admin info' => 'ict_projects_overview_number_indicators_admin_info',
  'defaults' => array()
);

function ict_projects_overview_number_indicators_render ($subtype, $conf, $panel_args, $context = NULL) {
  $block = new stdClass;

  $block->content = theme('ict_projects_dashboard_overview_number_indicators');

  return $block;
}


/**
 * 'admin info' callback for panel pane.
 */
function ict_projects_overview_number_indicators_admin_info ($subtype, $conf, $contexts) {
  $block = new stdClass;
  $block->title = t('Overview Description and Number Indicators');
  $block->content = t('Overview Description and Number Indicators');

  return $block;
}
