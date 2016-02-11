<?php
/**
 * @file
 * ict_update.field_diff.inc
 */


function ict_field_diff_list_latest($project_id) {
  $diff = &drupal_static(__FUNCTION__.$project_id);
  if (isset($diff)) {
    return $diff;
  }
  $history = ict_update_get_allowed_entity_list($project_id);
  $last_vid_updates = end($history);
  $last_vid = key($history);
  $prev_vid_updates = prev($history);
  $prev_vid = key($history);

  if (empty($last_vid_updates)) {
    if (empty($prev_vid_updates)) {
      //compare rebasline && baseline
    }
    else {
      // compare rebaseline && baseline ($latest_vid && $prev_vid)
      // compare rebaseline && update ($latest_vid && $prev_update)
    }
  }
  elseif (count($last_vid_updates) == 1) {
    $last_update = end($last_vid_updates);
    // compare update && rebaseline ($latest_update && $latest_vid)
    $diff = ict_field_diff_compare_update_rebaseline($project_id, $last_vid, $last_update);
  }
  elseif (count($last_vid_updates) > 1) {
    // compare update && update ($latest_update && $prev_update)
    $last_update = end($last_vid_updates);
    $prev_update = prev($last_vid_updates);
    $diff = ict_field_diff_compare_update_update($project_id, $prev_update, $last_update);
  }

  return $diff;
}

function ict_field_diff_compare_rebaseline_baseline($project_id, $prev_vid, $last_vid) {

}

function ict_field_diff_compare_rebaseline_update($project_id, $prev_vid, $last_vid, $update_id) {

}

function ict_field_diff_compare_update_rebaseline($project_id, $prev_vid, $update_id) {
  $field_list = array(
    'field_project_stage' => 'tid',
  );

  $project = node_load($project_id, $prev_vid);
  $project_wrap = entity_metadata_wrapper('node', $project);
  $update = node_load($update_id);
  $update_wrap = entity_metadata_wrapper('node', $update);

  $diff = array();
  foreach($field_list as $key => $val) {
    if ($update->{$key}['und'][0][$val] != $project->{$key}['und'][0][$val]) {
      $diff[$key] = $project_wrap->{$key}->value();
    }
  }

  $prev_financial = $project_wrap->field_original_total_budget->value();
  $last_financial = $update_wrap->field_original_total_budget->value();
  $diff_financial = ict_field_diff_compare_financial_year($prev_financial, $last_financial);
  if (!empty($diff_financial)) {
    $diff['field_original_total_budget'] = $diff_financial;
  }

  $prev_benefit = $project_wrap->field_benefits_realised->value();
  $last_benefit = $update_wrap->field_benefits_realised->value();
  $diff_benefits = ict_field_diff_compare_benefits($prev_benefit, $last_benefit);
  if (!empty($diff_benefits)) {
    $diff['field_benefits_realised'] = $diff_benefits;
  }

  return $diff;
}

function ict_field_diff_compare_update_update($project_id, $prev_update_id, $last_update_id) {
  $field_list = array(
    'field_project_stage' => 'tid',
    'field_expected_completion_date' => 'value',
    'field_forecast_level_of_project_' => 'value',
    'field_actual_level_of_project_co' => 'value',
    'field_current_financial_benefits' => 'value',
    'field_estimated_value_of_benefit' => 'value',
    'field_entity_comments' => 'value',
  );

  $prev_update = node_load($prev_update_id);
  $prev_update_wrapper = entity_metadata_wrapper('node', $prev_update);
  $last_update = node_load($last_update_id);
  $last_update_wrapper = entity_metadata_wrapper('node', $last_update);

  $diff = array();
  foreach($field_list as $key => $val) {
    if ($prev_update->{$key}['und'][0][$val] != $last_update->{$key}['und'][0][$val]) {
      $diff[$key] = $prev_update_wrapper->{$key}->value();
    }
  }

  $prev_financial = $prev_update_wrapper->field_original_total_budget->value();
  $last_financial = $last_update_wrapper->field_original_total_budget->value();
  $diff_financial = ict_field_diff_compare_financial_year($prev_financial, $last_financial);
  if (!empty($diff_financial)) {
    $diff['field_original_total_budget'] = $diff_financial;
  }

  $prev_benefit = $prev_update_wrapper->field_benefits_realised->value();
  $last_benefit = $last_update_wrapper->field_benefits_realised->value();
  $diff_benefits = ict_field_diff_compare_benefits($prev_benefit, $last_benefit);
  if (!empty($diff_benefits)) {
    $diff['field_benefits_realised'] = $diff_benefits;
  }

  return $diff;
}

function ict_field_diff_compare_financial_year($prev, $last) {
  $diff_year = array();

  for ($i = 0; max(count($prev), count($last)) > $i; $i++) {
    if (!empty($prev[$i]->field_year['und'][0]['value']) && !empty($last[$i]->field_year['und'][0]['value'])
        && $prev[$i]->field_year['und'][0]['value'] != $last[$i]->field_year['und'][0]['value']) {
      $diff_year[$last[$i]->field_year['und'][0]['value']] = $prev[$i]->field_total['und'][0]['value'];
    }
    if (!empty($prev[$i]->field_total['und'][0]['value']) && !empty($last[$i]->field_total['und'][0]['value'])
      && $prev[$i]->field_total['und'][0]['value'] != $last[$i]->field_total['und'][0]['value']) {
      $diff_year[$last[$i]->field_year['und'][0]['value']] = $prev[$i]->field_total['und'][0]['value'];
    }
  }

  return $diff_year;
}

function ict_field_diff_compare_benefits($prev, $last) {
  $field_list = array(
    'field_status' => 'value',
    'field_benefit_start_date' => 'value',
    'field_end_date' => 'value',
    'field_financial' => 'value',
    'field_benefit' => 'value',
    'field_commentary' => 'value',
  );
  $diff = array();

  foreach($last as $last_benefit) {
    if (empty($last_benefit->field_previous_collection['und'][0]['target_id'])) continue;
    if ($last_benefit->field_removed['und'][0]['value'] == 'removed') continue;
    $diff[$last_benefit->item_id] = array();
    foreach($prev as $key => $prev_benefit) {
      if ($last_benefit->field_previous_collection['und'][0]['target_id'] == $prev_benefit->field_previous_collection['und'][0]['target_id']
       || $last_benefit->field_previous_collection['und'][0]['target_id'] == $prev_benefit->item_id) {
        unset($prev[$key]);
        $prev_benefit_wrap = entity_metadata_wrapper('field_collection_item', $prev_benefit);
        foreach($field_list as $field_key => $field_val) {
          if ($prev_benefit->{$field_key}['und'][0][$field_val] != $last_benefit->{$field_key}['und'][0][$field_val]) {
            $diff[$last_benefit->item_id][$field_key] = $prev_benefit_wrap->{$field_key}->label() ? $prev_benefit_wrap->{$field_key}->label() : $prev_benefit_wrap->{$field_key}->value();
          }
        }
        break;
      }
    }
  }

  return $diff;
}
