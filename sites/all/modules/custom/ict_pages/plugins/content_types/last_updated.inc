<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Last updated'),
  'description' => t('Last Updated'),
  'category' => t('ICT'),
  'render callback' => 'ict_pages_last_updated_render',
//  'admin info' => 'ict_pages_home_login_admin_info',
//  'defaults' => array()
);

function ict_pages_last_updated_render ($subtype, $conf, $panel_args, $context = NULL) {
  $block = new stdClass;

  $query = db_select('project_workflow', 'wf');
  $query->addField('wf', 'created');
  $query->condition('wf.state', 'approved');
  $query->orderBy('created', 'DESC');
  $query->range(0, 1);
  $result = $query->execute()->fetchField();

  $block->content = '<div class="last-updated-on wrap cf">
    <p><strong>' . t('Information Last Updated on') . '</strong></p>
    <p><span>' . format_date($result, 'medium', 'd F Y') . '</span></p>
  </div>';

  return $block;
}

