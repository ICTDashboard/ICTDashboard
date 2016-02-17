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
