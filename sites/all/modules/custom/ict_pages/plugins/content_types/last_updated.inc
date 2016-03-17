<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Last updated'),
  'description' => t('Last Updated'),
  'category' => t('ICT'),
  'render callback' => 'ict_pages_last_updated_render',
);

function ict_pages_last_updated_render ($subtype, $conf, $panel_args, $context = NULL) {
  $block = new stdClass;

  $block->content = theme('ict_pages_last_update');

  return $block;
}

