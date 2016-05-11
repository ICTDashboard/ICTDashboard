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
  $page->name = 'baseline_create_draft';
  $page->task = 'page';
  $page->admin_title = 'Baseline Create Draft';
  $page->admin_description = 'Baseline Create Draft page';
  $page->path = 'baseline/%node/create-draft';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'node' => array(
      'id' => 1,
      'identifier' => 'Node: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_baseline_create_draft__panel';
  $handler->task = 'page';
  $handler->subtask = 'baseline_create_draft';
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
  $display->uuid = 'd71261f4-77c9-4963-a4d2-a1ade979ae59';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-bd654e28-f6d0-45ce-a7b4-463ef6a76d3a';
    $pane->panel = 'middle';
    $pane->type = 'baseline_create_draft';
    $pane->subtype = 'baseline_create_draft';
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
    $pane->uuid = 'bd654e28-f6d0-45ce-a7b4-463ef6a76d3a';
    $display->content['new-bd654e28-f6d0-45ce-a7b4-463ef6a76d3a'] = $pane;
    $display->panels['middle'][0] = 'new-bd654e28-f6d0-45ce-a7b4-463ef6a76d3a';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-bd654e28-f6d0-45ce-a7b4-463ef6a76d3a';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['baseline_create_draft'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'baseline_edit';
  $page->task = 'page';
  $page->admin_title = 'Baseline Edit Draft';
  $page->admin_description = 'Baseline or re-baseline edit page';
  $page->path = 'baseline/%node/edit-draft';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'node' => array(
      'id' => 1,
      'identifier' => 'Node: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_baseline_edit__panel';
  $handler->task = 'page';
  $handler->subtask = 'baseline_edit';
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
  $display->uuid = '8db5449b-6292-4073-b8b6-44ee083e3317';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-0363f0cc-b2d0-491f-993b-d283d057ebeb';
    $pane->panel = 'middle';
    $pane->type = 'baseline_edit_draft';
    $pane->subtype = 'baseline_edit_draft';
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
    $pane->uuid = '0363f0cc-b2d0-491f-993b-d283d057ebeb';
    $display->content['new-0363f0cc-b2d0-491f-993b-d283d057ebeb'] = $pane;
    $display->panels['middle'][0] = 'new-0363f0cc-b2d0-491f-993b-d283d057ebeb';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['baseline_edit'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'create_re_baseline';
  $page->task = 'page';
  $page->admin_title = 'Create re-baseline';
  $page->admin_description = '';
  $page->path = 'project/%nid/rebaseline';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'nid' => array(
      'id' => 1,
      'identifier' => 'Node: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_create_re_baseline__panel';
  $handler->task = 'page';
  $handler->subtask = 'create_re_baseline';
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
  $display->uuid = 'cbf4b931-0281-4fef-be24-b2dcdc318bd2';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-5a0c9282-e55f-4990-b37d-f03ee13037b7';
    $pane->panel = 'middle';
    $pane->type = 'rebaseline_create';
    $pane->subtype = 'rebaseline_create';
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
    $pane->uuid = '5a0c9282-e55f-4990-b37d-f03ee13037b7';
    $display->content['new-5a0c9282-e55f-4990-b37d-f03ee13037b7'] = $pane;
    $display->panels['middle'][0] = 'new-5a0c9282-e55f-4990-b37d-f03ee13037b7';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['create_re_baseline'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'project_history';
  $page->task = 'page';
  $page->admin_title = 'Project History';
  $page->admin_description = 'Baseline History for an individual project';
  $page->path = 'project/%node/history';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'node' => array(
      'id' => 1,
      'identifier' => 'Node: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_project_history__panel';
  $handler->task = 'page';
  $handler->subtask = 'project_history';
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
  $display->uuid = '39054008-8e4d-46a9-9f3a-a78266178eda';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-bc590aea-b54a-4b04-a6ee-dc8c95e53aa4';
    $pane->panel = 'middle';
    $pane->type = 'project_history';
    $pane->subtype = 'project_history';
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
    $pane->uuid = 'bc590aea-b54a-4b04-a6ee-dc8c95e53aa4';
    $display->content['new-bc590aea-b54a-4b04-a6ee-dc8c95e53aa4'] = $pane;
    $display->panels['middle'][0] = 'new-bc590aea-b54a-4b04-a6ee-dc8c95e53aa4';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['project_history'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'project_list';
  $page->task = 'page';
  $page->admin_title = 'Project List';
  $page->admin_description = '';
  $page->path = 'projects';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 2,
            1 => 3,
            2 => 41888116,
            3 => 153917155,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
      1 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 2,
            1 => 3,
            2 => 41888116,
            3 => 153917155,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
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

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'project_manage_users';
  $page->task = 'page';
  $page->admin_title = 'Project - Manage Users';
  $page->admin_description = '';
  $page->path = 'project/%nid/manage-users';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array(
    'nid' => array(
      'id' => 1,
      'identifier' => 'Node: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_project_manage_users__panel_context_045cc4e9-e2bc-4e71-a112-c9c5d99bee5e';
  $handler->task = 'page';
  $handler->subtask = 'project_manage_users';
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
    'name' => '',
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
    $pane->pid = 'new-0a8f4835-02c8-427b-b402-40637af98edb';
    $pane->panel = 'middle';
    $pane->type = 'project_manage_users';
    $pane->subtype = 'project_manage_users';
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
    $pane->uuid = '0a8f4835-02c8-427b-b402-40637af98edb';
    $display->content['new-0a8f4835-02c8-427b-b402-40637af98edb'] = $pane;
    $display->panels['middle'][0] = 'new-0a8f4835-02c8-427b-b402-40637af98edb';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['project_manage_users'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'review_baseline';
  $page->task = 'page';
  $page->admin_title = 'Review Baseline';
  $page->admin_description = '';
  $page->path = 'baseline/%node/review';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'node' => array(
      'id' => 1,
      'identifier' => 'Node: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_review_baseline__panel';
  $handler->task = 'page';
  $handler->subtask = 'review_baseline';
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
  $display->uuid = '85b58dd9-73d7-467e-b366-1f6c52d07532';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-37f18c81-f219-4d87-8326-430e20fd63f7';
    $pane->panel = 'middle';
    $pane->type = 'baseline_approve';
    $pane->subtype = 'baseline_approve';
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
    $pane->uuid = '37f18c81-f219-4d87-8326-430e20fd63f7';
    $display->content['new-37f18c81-f219-4d87-8326-430e20fd63f7'] = $pane;
    $display->panels['middle'][0] = 'new-37f18c81-f219-4d87-8326-430e20fd63f7';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-37f18c81-f219-4d87-8326-430e20fd63f7';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['review_baseline'] = $page;

  return $pages;

}
