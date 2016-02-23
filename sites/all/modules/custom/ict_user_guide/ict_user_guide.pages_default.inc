<?php
/**
 * @file
 * ict_user_guide.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function ict_user_guide_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'feedback';
  $page->task = 'page';
  $page->admin_title = 'Feedback';
  $page->admin_description = '';
  $page->path = 'feedback';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 2,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Feedback',
    'name' => 'menu-header-menu',
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
  $handler->name = 'page_feedback__panel';
  $handler->task = 'page';
  $handler->subtask = 'feedback';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'ict-basic-page',
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
  $display->uuid = 'a89d801b-8eb3-4a90-80b0-ee5fc0b3c4ee';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-e5a0782c-a0cd-4267-9f83-d9a916e824e8';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'bean-feedback';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'e5a0782c-a0cd-4267-9f83-d9a916e824e8';
    $display->content['new-e5a0782c-a0cd-4267-9f83-d9a916e824e8'] = $pane;
    $display->panels['middle'][0] = 'new-e5a0782c-a0cd-4267-9f83-d9a916e824e8';
    $pane = new stdClass();
    $pane->pid = 'new-36565bdf-ed7d-4a53-87c9-6722a7c0c162';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'entityform_block-feedback';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'wrap project-update-submission',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '36565bdf-ed7d-4a53-87c9-6722a7c0c162';
    $display->content['new-36565bdf-ed7d-4a53-87c9-6722a7c0c162'] = $pane;
    $display->panels['middle'][1] = 'new-36565bdf-ed7d-4a53-87c9-6722a7c0c162';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-e5a0782c-a0cd-4267-9f83-d9a916e824e8';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['feedback'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'user_guide';
  $page->task = 'page';
  $page->admin_title = 'User Guide';
  $page->admin_description = '';
  $page->path = 'user-guide';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 1,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => TRUE,
      ),
    ),
    'logic' => 'and',
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'User Guide',
    'name' => 'menu-header-menu',
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
  $handler->name = 'page_user_guide__panel';
  $handler->task = 'page';
  $handler->subtask = 'user_guide';
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
      'content' => NULL,
      'middle' => NULL,
    ),
    'content' => array(
      'style' => '-1',
    ),
  );
  $display->cache = array();
  $display->title = 'User Guide';
  $display->uuid = 'f4cc9b8e-f997-4b86-9429-b05e5a4847b1';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-03bd5ff5-31c7-4807-8e88-e7a1394f370e';
    $pane->panel = 'middle';
    $pane->type = 'page_title';
    $pane->subtype = 'page_title';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'user-guide-title',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '03bd5ff5-31c7-4807-8e88-e7a1394f370e';
    $display->content['new-03bd5ff5-31c7-4807-8e88-e7a1394f370e'] = $pane;
    $display->panels['middle'][0] = 'new-03bd5ff5-31c7-4807-8e88-e7a1394f370e';
    $pane = new stdClass();
    $pane->pid = 'new-36af2554-52c6-48a2-964c-6c32a0f9779a';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'bean-user-guide';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '36af2554-52c6-48a2-964c-6c32a0f9779a';
    $display->content['new-36af2554-52c6-48a2-964c-6c32a0f9779a'] = $pane;
    $display->panels['middle'][1] = 'new-36af2554-52c6-48a2-964c-6c32a0f9779a';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['user_guide'] = $page;

  return $pages;

}
