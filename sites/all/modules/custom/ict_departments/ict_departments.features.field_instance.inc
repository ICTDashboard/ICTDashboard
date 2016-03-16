<?php
/**
 * @file
 * ict_departments.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function ict_departments_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'taxonomy_term-department-field_acceptable_email_domains'.
  $field_instances['taxonomy_term-department-field_acceptable_email_domains'] = array(
    'bundle' => 'department',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Please enter a comma separated list of acceptable email domains such as <em>finance.gov.au</em>, <em>health.gov.au</em>.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_acceptable_email_domains',
    'label' => 'Acceptable email domains',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 31,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Acceptable email domains');
  t('Please enter a comma separated list of acceptable email domains such as <em>finance.gov.au</em>, <em>health.gov.au</em>.');

  return $field_instances;
}
