<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Page title'),
  'description' => t('Page title.'),
  'category' => t('ICT'),
  'render callback' => 'ict_pages_page_title_render',
//  'admin info' => 'ict_pages_home_login_admin_info',
//  'defaults' => array()
);

function ict_pages_page_title_render ($subtype, $conf, $panel_args, $context = NULL) {
  $block = new stdClass;

  $title = drupal_get_title();

  $block->content = '<div class="page-title dotbg">
      <div class="inner-title-content wrap cf">
        <h1>' . $title . '</h1>
      </div>
    </div>';

  return $block;
}

