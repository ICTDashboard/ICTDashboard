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

  drupal_add_js('http://d3js.org/d3.v3.min.js', 'external');

  // all active projects
  $all_projects = ict_project_get_all_active_projects();

  $benefits = array();
  if ($all_projects) {
    // get the number of benefits
    $query = db_select('field_data_field_number_of_benefits_calc', 'benefit');
    $query->join('project_workflow', 'workflow', 'benefit.entity_id = workflow.nid AND benefit.revision_id = workflow.vid');
    $query->condition('workflow.state', 'approved');
    $query->condition('benefit.entity_id', $all_projects, 'IN');
    $query->fields('benefit', array('field_number_of_benefits_calc_value'));
    $benefits = $query->execute()
      ->fetchCol();
  }

  $block->content = theme('ict_viz_number_indicators', array(
    'number_of_projects' => count($all_projects),
    'total_number_of_benefits' => array_sum($benefits),
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
