<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Detailed Overview Graphs'),
  'description' => t('Detailed Overview Graphs'),
  'category' => t('ICT'),
  'render callback' => 'ict_viz_detailed_overview_graphs_render',
  'admin info' => 'ict_viz_detailed_overview_graphs_render_admin_info',
  'defaults' => array()
);

function ict_viz_detailed_overview_graphs_render ($subtype, $conf, $panel_args, $context = NULL) {
  $block = new stdClass;

  // D3 js library
  drupal_add_js('https://d3js.org/d3.v3.min.js', 'external');

  // all active projects
  $all_projects = ict_project_get_all_active_projects();

  // detailed expenditure graph
  ict_viz_prepare_detailed_project_expenditure_data($all_projects);
  ict_viz_prepare_detailed_project_schedule_data($all_projects);

  // add required settings
  drupal_add_js(
    array(
      'detailed_overview' => array(

      )
    ),
    'setting'
  );

  $block->content = theme('ict_viz_detailed_overview', array(

  ));

  return $block;
}


/**
 * 'admin info' callback for panel pane.
 */
function ict_viz_detailed_overview_graphs_render_admin_info ($subtype, $conf, $contexts) {
  $block = new stdClass;
  $block->title = t('Detailed Overview Graphs');
  $block->content = t('Detailed Overview Graphs');

  return $block;
}
