<?php
/**
 * @file
 * ict_users.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function ict_users_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'user';
  $page->task = 'page';
  $page->admin_title = 'Add user';
  $page->admin_description = '';
  $page->path = 'user/create';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'administer users',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_user__panel';
  $handler->task = 'page';
  $handler->subtask = 'user';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'ict-user-create',
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
  $display->title = 'Add user';
  $display->uuid = '093f74b8-a86d-436b-91cc-a123c9f00637';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-00a1de05-1f40-4b16-9982-a9d2c47b22d5';
    $pane->panel = 'middle';
    $pane->type = 'user_create';
    $pane->subtype = 'user_create';
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
    $pane->uuid = '00a1de05-1f40-4b16-9982-a9d2c47b22d5';
    $display->content['new-00a1de05-1f40-4b16-9982-a9d2c47b22d5'] = $pane;
    $display->panels['middle'][0] = 'new-00a1de05-1f40-4b16-9982-a9d2c47b22d5';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['user'] = $page;

  return $pages;

}
