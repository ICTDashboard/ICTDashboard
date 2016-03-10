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
  $block = new stdClass;

  $block->content = theme('ict_viz_home_projects');

  return $block;
}
