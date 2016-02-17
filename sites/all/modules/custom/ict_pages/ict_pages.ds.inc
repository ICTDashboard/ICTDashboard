<?php
/**
 * @file
 * ict_pages.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function ict_pages_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'bean|opt_out_policy|default';
  $ds_layout->entity_type = 'bean';
  $ds_layout->bundle = 'opt_out_policy';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_description',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'field_description' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['bean|opt_out_policy|default'] = $ds_layout;

  return $export;
}
