<?php
/**
 * @file
 * ict_project.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function ict_project_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Closing',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '138a4c12-af0a-48c3-af74-f36ebb928d46',
    'vocabulary_machine_name' => 'project_stage',
  );
  $terms[] = array(
    'name' => 'Initiation',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '188a9d4d-9f50-4c79-951d-c9e2ecdac5f7',
    'vocabulary_machine_name' => 'project_stage',
  );
  $terms[] = array(
    'name' => 'Funding source term 1',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '309d4767-fee6-4508-874b-408abec1a040',
    'vocabulary_machine_name' => 'funding_source',
  );
  $terms[] = array(
    'name' => 'Controlling',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '87cc2f05-50b4-466e-8989-34635eaaffca',
    'vocabulary_machine_name' => 'project_stage',
  );
  $terms[] = array(
    'name' => 'Start up',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'cbe76c93-a5d1-41ed-9408-d75995b37fb1',
    'vocabulary_machine_name' => 'project_stage',
  );
  $terms[] = array(
    'name' => 'Funding source term 2',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'e1f00bca-bb30-496f-ade7-452340e7f365',
    'vocabulary_machine_name' => 'funding_source',
  );
  return $terms;
}
