<?php
/**
 * @file
 * ict_users.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function ict_users_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Department of Finance',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '1229567e-ed14-4d9f-bcd9-9e750896c9aa',
    'vocabulary_machine_name' => 'department',
    'field_acceptable_email_domains' => array(
      'und' => array(
        0 => array(
          'value' => 'finance.gov.au,  fin.gov.au',
          'format' => NULL,
          'safe_value' => 'finance.gov.au,  fin.gov.au',
        ),
      ),
    ),
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Prime Minister and Cabinet',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '65991f21-77d1-4de0-9309-6e06a190e3ff',
    'vocabulary_machine_name' => 'department',
    'field_acceptable_email_domains' => array(
      'und' => array(
        0 => array(
          'value' => 'pmc.gov.au',
          'format' => NULL,
          'safe_value' => 'pmc.gov.au',
        ),
      ),
    ),
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
    'field_acceptable_email_domains' => array(
      'und' => array(
        0 => array(
          'value' => 'environment.gov.au, env.gov.au',
          'format' => NULL,
          'safe_value' => 'environment.gov.au, env.gov.au',
        ),
      ),
    ),
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
    'field_acceptable_email_domains' => array(
      'und' => array(
        0 => array(
          'value' => 'health.gov.au',
          'format' => NULL,
          'safe_value' => 'health.gov.au',
        ),
      ),
    ),
    'path' => array(
      'pathauto' => 1,
    ),
  );
  return $terms;
}
