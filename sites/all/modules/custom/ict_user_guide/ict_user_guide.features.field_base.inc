<?php
/**
 * @file
 * ict_user_guide.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function ict_user_guide_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_guide'.
  $field_bases['field_guide'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_guide',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_long',
  );

  return $field_bases;
}
