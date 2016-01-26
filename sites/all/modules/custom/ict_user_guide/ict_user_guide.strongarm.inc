<?php
/**
 * @file
 * ict_user_guide.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function ict_user_guide_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_bean__user_guide';
  $strongarm->value = array(
    'view_modes' => array(
      'default' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'label' => array(
          'weight' => '-10',
        ),
        'title' => array(
          'weight' => '-9',
        ),
        'revision' => array(
          'weight' => '10',
        ),
        'view_mode' => array(
          'weight' => '10',
        ),
      ),
      'display' => array(
        'title' => array(
          'default' => array(
            'weight' => '-9',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_bean__user_guide'] = $strongarm;

  return $export;
}
