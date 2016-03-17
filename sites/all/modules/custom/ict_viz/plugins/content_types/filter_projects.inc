<?php

$plugin = array(
  'title' => t('Filtered Projects Table'),
  'description' => t('Filtered Projects Table'),
  'category' => t('ICT'),
  'render callback' => 'ict_viz_filtered_projects_render',
);

/**
 * return add project themed form
 */
function ict_viz_filtered_projects_render($subtype, $conf, $panel_args, $context = NULL) {
  $block = new stdClass;

  $block->content = theme('ict_viz_filtered_projects');

  return $block;
}
