<?php
/**
 * @file
 * ict_project.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function ict_project_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'project_list';
  $page->task = 'page';
  $page->admin_title = 'Project List';
  $page->admin_description = '';
  $page->path = 'projects';
  $page->access = array();
  $page->menu = array(
    'type' => 'none',
    'title' => '',
    'name' => 'navigation',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_project_list__panel';
  $handler->task = 'page';
  $handler->subtask = 'project_list';
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
  $display->title = '';
  $display->uuid = '9efda619-f317-4e06-9712-8a987b9f0b69';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-bc7f12f9-5a79-4a0a-9a35-b20600f5ee75';
    $pane->panel = 'middle';
    $pane->type = 'project_list';
    $pane->subtype = 'project_list';
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
    $pane->uuid = 'bc7f12f9-5a79-4a0a-9a35-b20600f5ee75';
    $display->content['new-bc7f12f9-5a79-4a0a-9a35-b20600f5ee75'] = $pane;
    $display->panels['middle'][0] = 'new-bc7f12f9-5a79-4a0a-9a35-b20600f5ee75';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-bc7f12f9-5a79-4a0a-9a35-b20600f5ee75';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['project_list'] = $page;

  return $pages;

}
