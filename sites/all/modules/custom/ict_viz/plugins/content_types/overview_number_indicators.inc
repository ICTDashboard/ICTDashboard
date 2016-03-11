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

  // D3 js library
  drupal_add_js('http://d3js.org/d3.v3.min.js', 'external');

  // all active projects
  $all_projects = ict_project_get_all_active_projects();

  $benefits = 0;
  $total_expenditure = 0;
  $total_budget = 0;
  $current_year_budget = 0;
  $current_year_expenditure = 0;
  if ($all_projects) {
    // get all required data
    $query = db_select('field_data_field_number_of_benefits_calc', 'benefits');
    $query->join('field_data_field_expenditure_budget_calc', 'budget', 'budget.entity_id = benefits.entity_id AND budget.revision_id = benefits.revision_id');
    $query->join('field_data_field_expenditure_to_date_calc', 'expenditure', 'expenditure.entity_id = benefits.entity_id AND expenditure.revision_id = benefits.revision_id');
    $query->join('project_workflow', 'workflow', 'benefits.entity_id = workflow.nid AND benefits.revision_id = workflow.vid');
    $query->condition('workflow.state', 'approved');
    $query->condition('benefits.entity_id', $all_projects, 'IN');
    $query->fields('benefits', array('field_number_of_benefits_calc_value'));
    $query->fields('budget', array('field_expenditure_budget_calc_value'));
    $query->fields('expenditure', array('field_expenditure_to_date_calc_value'));
    $projects = $query->execute()
      ->fetchAll();

    foreach($projects as $project) {
      $benefits += (int)$project->field_number_of_benefits_calc_value;
      $total_expenditure += (float)$project->field_expenditure_to_date_calc_value;
      $total_budget += (float)$project->field_expenditure_budget_calc_value;
    }

    $current_fin_year = __ict_project_get_current_fin_year();

    // current year budget
    $query = db_select('field_data_field_original_total_budget', 'budget_entity');
    $query->join('field_data_field_year', 'year', 'year.entity_id = budget_entity.field_original_total_budget_value AND year.revision_id = budget_entity.field_original_total_budget_revision_id');
    $query->join('field_data_field_total', 'total', 'total.entity_id = budget_entity.field_original_total_budget_value AND total.revision_id = budget_entity.field_original_total_budget_revision_id');
    $query->join('project_workflow', 'workflow', 'budget_entity.entity_id = workflow.nid AND budget_entity.revision_id = workflow.vid');
    $query->condition('workflow.state', 'approved');
    $query->condition('budget_entity.entity_id', $all_projects, 'IN');
    $query->condition('year.field_year_value', $current_fin_year);
    $query->fields('total', array('field_total_value'));
    $current_year_budget_items = $query->execute()
      ->fetchCol();

    foreach($current_year_budget_items as $budget) {
      $current_year_budget += (float)$budget;
    }

    // current year expenditure
    $subquery = db_select('field_data_field_project', 'update_entity');
    $query->join('project_workflow', 'workflow', 'update_entity.entity_id = workflow.nid AND update_entity.revision_id = workflow.vid');
    $query->condition('workflow.state', 'approved');
    $subquery->fields('update_entity', array('field_project_target_id'));
    $subquery->condition('update_entity.field_project_target_id', $all_projects, 'IN');
    $subquery->addExpression('MAX(update_entity.revision_id)', 'max_revision');
    $subquery->addExpression('MAX(update_entity.entity_id)', 'max_entity');
    $subquery->groupBy('update_entity.field_project_target_id');

    $query = db_select('field_data_field_original_total_budget', 'budget_entity');
    $query->join($subquery, 'update_entity', 'update_entity.max_entity = budget_entity.entity_id AND update_entity.max_revision = budget_entity.revision_id');
    $query->join('field_data_field_year', 'year', 'year.entity_id = budget_entity.field_original_total_budget_value AND year.revision_id = budget_entity.field_original_total_budget_revision_id');
    $query->join('field_data_field_total', 'total', 'total.entity_id = budget_entity.field_original_total_budget_value AND total.revision_id = budget_entity.field_original_total_budget_revision_id');
    $query->condition('year.field_year_value', $current_fin_year);
    $query->condition('update_entity.field_project_target_id', $all_projects, 'IN');
    $query->fields('total', array('field_total_value'));
    $current_year_expenditure_items = $query->execute()
      ->fetchCol();

    foreach($current_year_expenditure_items as $budget) {
      $current_year_expenditure += (float)$budget;
    }
  }

  // add required settings for expenditure graphs
  drupal_add_js(
    array(
      'budget_expenditure_settings' => array(
        'total_expenditure' => $total_expenditure,
        'total_budget' => $total_budget,
        'current_year_expenditure' => $current_year_expenditure,
        'current_year_budget' => $current_year_budget
      )
    ),
    'setting'
  );

  $block->content = theme('ict_viz_number_indicators', array(
    'number_of_projects' => count($all_projects),
    'total_number_of_benefits' => $benefits,
    'total_expenditure' => $total_expenditure,
    'total_budget' => $total_budget,
    'current_year_expenditure' => $current_year_expenditure,
    'current_year_budget' => $current_year_budget
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
