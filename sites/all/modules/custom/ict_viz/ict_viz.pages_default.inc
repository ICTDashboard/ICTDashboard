<?php
/**
 * @file
 * ict_viz.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function ict_viz_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'dashboard_detailed_overview';
  $page->task = 'page';
  $page->admin_title = 'Dashboard Detailed Overview';
  $page->admin_description = '';
  $page->path = 'detailed-overview';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_dashboard_detailed_overview__panel';
  $handler->task = 'page';
  $handler->subtask = 'dashboard_detailed_overview';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panel',
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'ICT Projects Detailed Overview';
  $display->uuid = '2bddd750-88f9-496a-94a7-6d386ee5806b';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-16e29786-9ec9-4c32-818f-692e3232093c';
    $pane->panel = 'middle';
    $pane->type = 'detailed_overview';
    $pane->subtype = 'detailed_overview';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '16e29786-9ec9-4c32-818f-692e3232093c';
    $display->content['new-16e29786-9ec9-4c32-818f-692e3232093c'] = $pane;
    $display->panels['middle'][0] = 'new-16e29786-9ec9-4c32-818f-692e3232093c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['dashboard_detailed_overview'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'filtered_projects';
  $page->task = 'page';
  $page->admin_title = 'Filtered Projects';
  $page->admin_description = '';
  $page->path = 'dashboard-projects';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_filtered_projects__panel';
  $handler->task = 'page';
  $handler->subtask = 'filtered_projects';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'ict-filtered-projects',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panel',
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '8872e11f-6e7d-43c8-a9f5-0d1f056cc3f9';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-f2022727-949c-4898-aa76-3c0791068c01';
    $pane->panel = 'middle';
    $pane->type = 'filter_projects';
    $pane->subtype = 'filter_projects';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'f2022727-949c-4898-aa76-3c0791068c01';
    $display->content['new-f2022727-949c-4898-aa76-3c0791068c01'] = $pane;
    $display->panels['middle'][0] = 'new-f2022727-949c-4898-aa76-3c0791068c01';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-f2022727-949c-4898-aa76-3c0791068c01';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['filtered_projects'] = $page;

  return $pages;

}
