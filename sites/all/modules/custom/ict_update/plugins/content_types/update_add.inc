<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Update Add'),
  'description' => t('Update Add page.'),
  'category' => t('ICT'),
  'render callback' => 'ict_update_add_render',
  'required context' => array(
    new ctools_context_required(t('Node'), 'node'),
  ),
);

/**
 * return add project themed form
 */
function ict_update_add_render($subtype, $conf, $panel_args, $context = NULL) {
  $form = node_add('update');

  $block = new stdClass;
  $block->content = drupal_render($form);
  return $block;
}
