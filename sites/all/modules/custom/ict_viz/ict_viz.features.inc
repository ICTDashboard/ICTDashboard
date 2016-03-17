<?php
/**
 * @file
 * ict_viz.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ict_viz_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}
