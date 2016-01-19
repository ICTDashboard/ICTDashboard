<?php
/**
 * @file
 * ict_pages.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function ict_pages_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'site_template_panel_context';
  $handler->task = 'site_template';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Main Template',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'login',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'itdash_main';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'content' => NULL,
      'footer' => NULL,
    ),
    'style' => 'naked',
    'header' => array(
      'style' => 'naked',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '1cc73eb4-5b20-4677-9959-d1b7cad8f0fb';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-958281cd-8c50-4f06-aa35-1fe50b5da524';
    $pane->panel = 'content';
    $pane->type = 'page_title';
    $pane->subtype = 'page_title';
    $pane->shown = TRUE;
    $pane->access = array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'faq
dashboard
project/*/update
update/*',
          ),
          'context' => 'argument_string_1',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'naked',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '958281cd-8c50-4f06-aa35-1fe50b5da524';
    $display->content['new-958281cd-8c50-4f06-aa35-1fe50b5da524'] = $pane;
    $display->panels['content'][0] = 'new-958281cd-8c50-4f06-aa35-1fe50b5da524';
    $pane = new stdClass();
    $pane->pid = 'new-5299535b-5c91-48d5-91f9-e44ac84535ca';
    $pane->panel = 'content';
    $pane->type = 'pane_messages';
    $pane->subtype = 'pane_messages';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'naked',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '5299535b-5c91-48d5-91f9-e44ac84535ca';
    $display->content['new-5299535b-5c91-48d5-91f9-e44ac84535ca'] = $pane;
    $display->panels['content'][1] = 'new-5299535b-5c91-48d5-91f9-e44ac84535ca';
    $pane = new stdClass();
    $pane->pid = 'new-459b4dca-0c70-43c6-810d-2fba68be2949';
    $pane->panel = 'content';
    $pane->type = 'page_content';
    $pane->subtype = 'page_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_page_content_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'naked',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '459b4dca-0c70-43c6-810d-2fba68be2949';
    $display->content['new-459b4dca-0c70-43c6-810d-2fba68be2949'] = $pane;
    $display->panels['content'][2] = 'new-459b4dca-0c70-43c6-810d-2fba68be2949';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-459b4dca-0c70-43c6-810d-2fba68be2949';
  $handler->conf['display'] = $display;
  $export['site_template_panel_context'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function ict_pages_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'dashboard';
  $page->task = 'page';
  $page->admin_title = 'Dashboard';
  $page->admin_description = '';
  $page->path = 'dashboard';
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
  $handler->name = 'page_dashboard_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'dashboard';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'itdash_dashboard';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left' => NULL,
      'right' => NULL,
      'bottom' => NULL,
      'middle' => NULL,
    ),
    'style' => 'naked',
    'middle' => array(
      'style' => 'naked',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '58f1f91d-d70a-4bcf-ab28-eb5486856b45';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-96cedb04-1287-4239-9ebd-579149d14178';
    $pane->panel = 'content';
    $pane->type = 'node';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'nid' => '1675',
      'links' => 1,
      'leave_node_title' => 0,
      'identifier' => '',
      'build_mode' => 'full',
      'link_node_title' => 0,
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'default',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '96cedb04-1287-4239-9ebd-579149d14178';
    $display->content['new-96cedb04-1287-4239-9ebd-579149d14178'] = $pane;
    $display->panels['content'][0] = 'new-96cedb04-1287-4239-9ebd-579149d14178';
    $pane = new stdClass();
    $pane->pid = 'new-fa509617-5c9e-40d1-a2f8-d2849d885c00';
    $pane->panel = 'content';
    $pane->type = 'node';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'nid' => '1674',
      'links' => 1,
      'leave_node_title' => 0,
      'identifier' => '',
      'build_mode' => 'full',
      'link_node_title' => 0,
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'fa509617-5c9e-40d1-a2f8-d2849d885c00';
    $display->content['new-fa509617-5c9e-40d1-a2f8-d2849d885c00'] = $pane;
    $display->panels['content'][1] = 'new-fa509617-5c9e-40d1-a2f8-d2849d885c00';
    $pane = new stdClass();
    $pane->pid = 'new-d6fda037-a6a0-4201-bf21-54bfde3cda7b';
    $pane->panel = 'content';
    $pane->type = 'node';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'nid' => '1673',
      'links' => 1,
      'leave_node_title' => 0,
      'identifier' => '',
      'build_mode' => 'full',
      'link_node_title' => 0,
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'd6fda037-a6a0-4201-bf21-54bfde3cda7b';
    $display->content['new-d6fda037-a6a0-4201-bf21-54bfde3cda7b'] = $pane;
    $display->panels['content'][2] = 'new-d6fda037-a6a0-4201-bf21-54bfde3cda7b';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['dashboard'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'home_page';
  $page->task = 'page';
  $page->admin_title = 'Home Page';
  $page->admin_description = '';
  $page->path = 'home';
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
  $handler->name = 'page_home_page_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'home_page';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'home',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
    'style' => 'naked',
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '209adf75-e423-4b9e-baa9-448194aeb246';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-e7723f9c-65e9-4882-b8e2-f67e5af656d2';
    $pane->panel = 'middle';
    $pane->type = 'home_login';
    $pane->subtype = 'home_login';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'naked',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'e7723f9c-65e9-4882-b8e2-f67e5af656d2';
    $display->content['new-e7723f9c-65e9-4882-b8e2-f67e5af656d2'] = $pane;
    $display->panels['middle'][0] = 'new-e7723f9c-65e9-4882-b8e2-f67e5af656d2';
    $pane = new stdClass();
    $pane->pid = 'new-06e6e0f1-dd79-45bd-a627-eecb9f5ba2e2';
    $pane->panel = 'middle';
    $pane->type = 'home_bottom';
    $pane->subtype = 'home_bottom';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'naked',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '06e6e0f1-dd79-45bd-a627-eecb9f5ba2e2';
    $display->content['new-06e6e0f1-dd79-45bd-a627-eecb9f5ba2e2'] = $pane;
    $display->panels['middle'][1] = 'new-06e6e0f1-dd79-45bd-a627-eecb9f5ba2e2';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-e7723f9c-65e9-4882-b8e2-f67e5af656d2';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['home_page'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'project_add';
  $page->task = 'page';
  $page->admin_title = 'Project Add';
  $page->admin_description = '';
  $page->path = 'project/add';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
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
  $handler->name = 'page_project_add_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'project_add';
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
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
    'style' => 'naked',
    'middle' => array(
      'style' => 'naked',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '93aaa52e-ee71-4b8b-99fa-09a4ca52faa1';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-44f12728-52c8-47d4-bb96-f24de96c7796';
    $pane->panel = 'middle';
    $pane->type = 'project_add';
    $pane->subtype = 'project_add';
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
    $pane->uuid = '44f12728-52c8-47d4-bb96-f24de96c7796';
    $display->content['new-44f12728-52c8-47d4-bb96-f24de96c7796'] = $pane;
    $display->panels['middle'][0] = 'new-44f12728-52c8-47d4-bb96-f24de96c7796';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['project_add'] = $page;

  return $pages;

}
