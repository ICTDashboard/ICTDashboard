<?php

function ict_viz_prepare_detailed_project_expenditure_data($all_projects = array()) {

  drupal_add_js(drupal_get_path('module', 'ict_viz') . '/js/detailed_overview.js');

  $year_budget = array();
  $year_expenditure = array();
  if ($all_projects) {
    $current_fin_year = __ict_project_get_current_fin_year();

    // current year budget
    $query = db_select('field_data_field_original_total_budget', 'budget_entity');
    $query->join('field_data_field_year', 'year', 'year.entity_id = budget_entity.field_original_total_budget_value AND year.revision_id = budget_entity.field_original_total_budget_revision_id');
    $query->join('field_data_field_total', 'total', 'total.entity_id = budget_entity.field_original_total_budget_value AND total.revision_id = budget_entity.field_original_total_budget_revision_id');
    $query->join('project_workflow', 'workflow', 'budget_entity.entity_id = workflow.nid AND budget_entity.revision_id = workflow.vid');
    $query->condition('workflow.state', 'approved');
    $query->condition('budget_entity.entity_id', $all_projects, 'IN');
    $query->fields('total', array('field_total_value'));
    $query->fields('year', array('field_year_value'));
    $year_budget_items = $query->execute()
      ->fetchAll();

    foreach($year_budget_items as $budget) {
      if (!isset($year_budget[$budget->field_year_value])) {
        $year_budget[$budget->field_year_value] = 0;
      }

      $year_budget[$budget->field_year_value] += (float)$budget->field_total_value;
    }

    // current year expenditure
    $subquery = db_select('field_data_field_project', 'update_entity');
    $subquery->condition('update_entity.bundle', 'update');
    $subquery->join('project_workflow', 'workflow', 'update_entity.entity_id = workflow.nid AND update_entity.revision_id = workflow.vid');
    $subquery->condition('workflow.state', 'approved');
    $subquery->fields('update_entity', array('field_project_target_id'));
    $subquery->condition('update_entity.field_project_target_id', $all_projects, 'IN');
    $subquery->addExpression('MAX(update_entity.revision_id)', 'max_revision');
    $subquery->addExpression('MAX(update_entity.entity_id)', 'max_entity');
    $subquery->groupBy('update_entity.field_project_target_id');

    $query = db_select('field_data_field_original_total_budget', 'budget_entity');
    $query->join($subquery, 'update_entity', 'update_entity.max_entity = budget_entity.entity_id AND update_entity.max_revision = budget_entity.revision_id');
    $query->join('field_data_field_year', 'year', 'year.entity_id = budget_entity.field_original_total_budget_value AND year.revision_id = budget_entity.field_original_total_budget_revision_id');
    $query->join('field_data_field_total', 'total', 'total.entity_id = budget_entity.field_original_total_budget_value AND total.revision_id = budget_entity.field_original_total_budget_revision_id');
    $query->condition('update_entity.field_project_target_id', $all_projects, 'IN');
    $query->fields('total', array('field_total_value'));
    $query->fields('year', array('field_year_value'));
    $year_expenditure_items = $query->execute()
      ->fetchAll();

    foreach($year_expenditure_items as $budget) {
      if (!isset($year_expenditure[$budget->field_year_value])) {
        $year_expenditure[$budget->field_year_value] = 0;
      }

      $year_expenditure[$budget->field_year_value] += (float)$budget->field_total_value;
    }
  }

  // adds required years to expenditure
  $add_expenditure_years = array_diff_key($year_budget, $year_expenditure);
  foreach($add_expenditure_years as $year => $total) {
    $year_expenditure[$year] = 0;
  }

  // adds required years to budget
  $add_budget_years = array_diff_key($year_expenditure, $year_budget);
  foreach($add_budget_years as $year => $total) {
    $year_budget[$year] = 0;
  }

  // sort values by year
  ksort($year_expenditure);
  ksort($year_budget);

  // chart labels
  $labels = array();
  foreach ($year_expenditure as $year => &$total) {
    $fin_year = explode('/', $year);
    $label = '20' . reset($fin_year) . '-' . end($fin_year);
    $label = $current_fin_year == $year ? $label . '*' : $label;
    $labels[] = $label;
  }

  $chart_options = array(
    'responsive' => TRUE,
    'scaleLabel' => "$<%=value%>m",
    'scaleBeginAtZero' => TRUE,
    'scaleLineColor' => "#1e2635",
    'scaleFontFamily' => "'Open Sans', sans-serif",
    'scaleFontSize' => 13,
    'scaleFontStyle' =>  "normal",
    'scaleFontColor' => "#202b3d",
    'scaleShowGridLines' => TRUE,
    'scaleGridLineColor' => "#f0f4fa",
    'scaleGridLineWidth' => 1,
    'scaleShowHorizontalLines' => TRUE,
    'scaleShowVerticalLines' => FALSE,
    'barShowStroke' => FALSE,
    'barStrokeWidth' => 1,
    'barValueSpacing' => 20,
    'barDatasetSpacing' => 1,
    'legendTemplate' => "<ul class=\"<%=name.toLowerCase()%>-legend\"><% for (var i=0; i<datasets.length; i++){%><li><span style=\"background-color:<%=datasets[i].fillColor%>\"></span><%if(datasets[i].label){%><%=datasets[i].label%><%}%></li><%}%></ul>",
    'tooltipFillColor' => "#f9fbfe",
    'tooltipFontFamily' => "'Open Sans', sans-serif",
    'tooltipFontSize' =>  13,
    'tooltipFontStyle' => "Bold",
    'tooltipFontColor' => "#202b3d",
    'tooltipTitleFontFamily' => "'Open Sans', sans-serif",
    'tooltipTitleFontSize' => 14,
    'tooltipTitleFontStyle' => "normal",
    'tooltipTitleFontColor' => "#202b3d",
    'tooltipYPadding' => 6,
    'tooltipXPadding' => 6,
    'tooltipCaretSize' => 8,
    'tooltipCornerRadius' => 6,
    'tooltipXOffset' => 1,
    'multiTooltipTemplate' => "$<%= value %>m",
  );

  $datasets = array(
    array(
      'label' => 'Expenditure to Date ($m)',
      'fillColor' => "#ff6161",
      'strokeColor' => "#ff6161",
      'highlightFill' => "#ff6161",
      'highlightStroke' => "#ff6161",
      'data' => array_values($year_expenditure)
    ),
    array(
      'label' => 'Total Budget ($m)',
      'fillColor' => "#5c46a4",
      'strokeColor' => "#5c46a4",
      'highlightFill' => "#5c46a4",
      'highlightStroke' => "#5c46a4",
      'data' => array_values($year_budget)
    ),
  );

  drupal_add_js(
    array(
      'detailed_budget_chart' => array(
        'options' => $chart_options,
        'data' => array(
          'labels' => $labels,
          'datasets' => $datasets,
          'current_year' => $current_fin_year
        ),
      )
    ),
    'setting'
  );

  drupal_add_js(
    'https://cdnjs.cloudflare.com/ajax/libs/Chart.js/1.0.2/Chart.min.js',
    'external'
  );
}

function ict_viz_prepare_detailed_project_schedule_data($all_projects) {
  $years = array('current', 'previous');
  $years_to_process = explode('/', __ict_project_get_current_fin_year());
  $quarter_deadlines = array(
    1 => '09-30',
    2 => '12-31',
    3 => '03-31',
    4 => '06-30'
  );

  // data to collect
  $year_label = array();
  $data = array();
  $max_number = 0;

  if ($all_projects) {
    foreach ($years as $year) {
      // start year
      $start_year = $year == 'current' ?
        reset($years_to_process) :
        reset($years_to_process) - 1;

      // end year
      $end_year = $year == 'current' ?
        end($years_to_process) :
        end($years_to_process) - 1;

      // set year label
      $year_label[$year] = '20' . $start_year . '-' . $end_year;

      for ($quarter = 4; $quarter > 0; $quarter--) {
      
        $max_date = $quarter < 3 ?
          '20' . $start_year . '-' .$quarter_deadlines[$quarter] :
          '20' . $end_year . '-' .$quarter_deadlines[$quarter];

        // if deadline in future we need to request current snapshot
        $timestamp = strtotime($max_date);
        if ($timestamp > time()) {
          $prev_quarter = $quarter > 1 ? $quarter - 1 : 4;

          // next quarter cannot be found
          if (!isset($quarter_deadlines[$prev_quarter]))  continue;
          
          // next quarter hasn't started
          $prevmax_date = $prev_quarter < 3 || $prev_quarter == 4 ?
            '20' . $start_year . '-' .$quarter_deadlines[$prev_quarter] :
            '20' . $end_year . '-' .$quarter_deadlines[$prev_quarter];
            
          if (strtotime($prevmax_date) > time()) continue;

          // current snapshot will be requested
          $timestamp = time();
        }

        // quarter expenditure
        $subquery = db_select('field_data_field_project', 'update_entity');
        $subquery->condition('update_entity.bundle', 'update');
        $subquery->join('project_workflow', 'workflow', 'update_entity.entity_id = workflow.nid AND update_entity.revision_id = workflow.vid');
        $subquery->condition('workflow.state', 'approved');
        $subquery->fields('update_entity', array('field_project_target_id'));
        $subquery->condition('update_entity.field_project_target_id', $all_projects, 'IN');
        $subquery->condition('workflow.created', $timestamp, '<');
        $subquery->addExpression('MAX(update_entity.revision_id)', 'max_revision');
        $subquery->addExpression('MAX(update_entity.entity_id)', 'max_entity');
        $subquery->groupBy('update_entity.field_project_target_id');

        $query = db_select('field_data_field_actual_level_of_project_co', 'actual_comp');
        $query->join($subquery, 'update_entity', 'update_entity.max_entity = actual_comp.entity_id AND update_entity.max_revision = actual_comp.revision_id');
        $query->join('field_data_field_forecast_level_of_project_', 'forecast_comp', 'update_entity.max_entity = forecast_comp.entity_id AND update_entity.max_revision = forecast_comp.revision_id');
        $query->fields('actual_comp', array('field_actual_level_of_project_co_value'));
        $query->fields('forecast_comp', array('field_forecast_level_of_project__value'));
        $current_status_items = $query->execute()
          ->fetchAll();

        foreach ($current_status_items as $project) {
          if ($project->field_actual_level_of_project_co_value < $project->field_forecast_level_of_project__value) {
            if (!isset($data[$year][$quarter]['behind_schedule']['value'])) {
              $data[$year][$quarter]['behind_schedule']['value'] = 0;
            }

            $data[$year][$quarter]['behind_schedule']['value']++;
            $data[$year][$quarter]['behind_schedule']['color'] = '#f6d000';
          }
          elseif ($project->field_actual_level_of_project_co_value == $project->field_forecast_level_of_project__value) {
            if (!isset($data[$year][$quarter]['on_track']['value'])) {
              $data[$year][$quarter]['on_track']['value'] = 0;
            }

            $data[$year][$quarter]['on_track']['value']++;
            $data[$year][$quarter]['on_track']['color'] = '#1fd063';
          }
          else {
            if (!isset($data[$year][$quarter]['ahead_schedule']['value'])) {
              $data[$year][$quarter]['ahead_schedule']['value'] = 0;
            }

            $data[$year][$quarter]['ahead_schedule']['value']++;
            $data[$year][$quarter]['ahead_schedule']['color'] = '#75a2df';
          }
        }

        // update max_number
        $max_number = count($current_status_items) > $max_number ?
          count($current_status_items) :
          $max_number;
      }
    }
  }

  drupal_add_js(
    array(
      'detailed_schedule_chart' => array(
        'current' => $year_label['current'],
        'previous' => $year_label['previous'],
        'data' => $data,
        'max_number' => $max_number
      )
    ),
    'setting'
  );
}
