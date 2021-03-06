<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Update Edit'),
  'description' => t('Update Edit page.'),
  'category' => t('ICT'),
  'render callback' => 'ict_update_edit_render',
  'required context' => array(
    new ctools_context_required(t('Node'), 'node'),
  ),
);

/**
 * return add project themed form
 */
function ict_update_edit_render($subtype, $conf, $panel_args, $context = NULL) {
  module_load_include('inc', 'node', 'node.pages');
  $form = drupal_get_form('update_node_form', $context[0]->data);

  $block = new stdClass;
  $block->content = drupal_render($form);
  return $block;
}
