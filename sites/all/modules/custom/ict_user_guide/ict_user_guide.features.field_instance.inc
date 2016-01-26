<?php
/**
 * @file
 * ict_user_guide.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function ict_user_guide_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'bean-user_guide-field_guide'.
  $field_instances['bean-user_guide-field_guide'] = array(
    'bundle' => 'user_guide',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'bean',
    'field_name' => 'field_guide',
    'label' => 'Guide',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 11,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Guide');

  return $field_instances;
}
