<?php
/**
 * @file
 * ict_departments.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function ict_departments_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Department of Finance',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '1229567e-ed14-4d9f-bcd9-9e750896c9aa',
    'vocabulary_machine_name' => 'department',
    'field_acceptable_email_domains' => array(),
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Department of Environment',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '8e383ae1-d23b-4fde-81c4-bf6848d8b76f',
    'vocabulary_machine_name' => 'department',
    'field_acceptable_email_domains' => array(),
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Department of Health',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'd45f4346-bac8-40ab-a3fc-754130a7acde',
    'vocabulary_machine_name' => 'department',
    'field_acceptable_email_domains' => array(),
    'path' => array(
      'pathauto' => 1,
    ),
  );
  return $terms;
}
