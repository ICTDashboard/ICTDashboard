<?php

$plugin = array(
  'title' => t('Home Projects Table'),
  'description' => t('Home Projects Table'),
  'category' => t('ICT'),
  'render callback' => 'ict_viz_home_projects_render',
);

/**
 * return add project themed form
 */
function ict_viz_home_projects_render($subtype, $conf, $panel_args, $context = NULL) {
  module_load_include('inc', 'node', 'node.pages');
  $form = drupal_get_form('update_node_form', $context[0]->data);

  $block = new stdClass;
  $block->content = drupal_render($form);
  return $block;
}
