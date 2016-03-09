<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Overview Description and Number Indicators'),
  'description' => t('Overview Description and Number Indicators.'),
  'category' => t('ICT'),
  'render callback' => 'ict_viz_overview_number_indicators_render',
  'admin info' => 'ict_viz_overview_number_indicators_admin_info',
  'defaults' => array()
);

function ict_viz_overview_number_indicators_render ($subtype, $conf, $panel_args, $context = NULL) {
  $block = new stdClass;

  $all_projects = ict_project_get_all_active_projects();

  $block->content = theme('ict_viz_number_indicators', array(
    'number_of_projects' => count($all_projects),
    'total_number_of_benefits' => 66
  ));

  return $block;
}


/**
 * 'admin info' callback for panel pane.
 */
function ict_viz_overview_number_indicators_admin_info ($subtype, $conf, $contexts) {
  $block = new stdClass;
  $block->title = t('Overview Description and Number Indicators');
  $block->content = t('Overview Description and Number Indicators');

  return $block;
}
