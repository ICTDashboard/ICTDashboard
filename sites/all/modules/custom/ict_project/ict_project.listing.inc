<?php

/**
 * @file
 * Code for the ICT Project edit functions.
 */

/**
 * Project List
 */
function ict_project_project_list_block() {
  global $user;
  $user = user_load($user->uid);
  $results = array();


  $query = db_select('node', 'n')
    ->fields('n', array('nid', 'title', 'changed'))
    ->condition('n.type', 'project');

  // unpublished project should be excluded
  $query->join('project_workflow', 'workflow', 'n.nid = workflow.nid');
  $query->condition('workflow.state', 'unpublished', '<>');

  $tid = !empty($user->field_department[LANGUAGE_NONE][0]['tid']) ?
    $user->field_department[LANGUAGE_NONE][0]['tid'] :
    NULL;

  if (!array_intersect($user->roles, array('administrator', 'Finance Admin')) &&
    $tid) {

    $query->join(
      'field_data_field_department',
      'd',
      'd.bundle = n.type AND n.nid = d.entity_id'
    );

    $query->condition(
      'd.field_department_tid',
      $user->field_department[LANGUAGE_NONE][0]['tid']
    );

  }

  $query->groupBy('n.nid');

  $results = $query
    ->orderBy('n.title', 'ASC')
    ->execute()
    ->fetchAll();

  foreach($results as $key => $project) {
    if (!ict_project_access_project('view', NULL, $project->nid)) {
      unset($results[$key]);
    }
  }

  return theme('ict_project_listing_block', array(
    'rows' => $results
  ));
}
