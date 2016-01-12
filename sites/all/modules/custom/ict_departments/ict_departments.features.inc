<?php
/**
 * @file
 * ict_departments.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ict_departments_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function ict_departments_node_info() {
  $items = array(
    'department' => array(
      'name' => t('Department'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
