<?php
/**
 * @file
 * ict_dashboard_data_push_rules.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ict_dashboard_data_push_rules_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'ckan_submission_result';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'ckan_remote_post_targets';
  $view->human_name = 'Ckan submission result';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Ckan submission result';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: CKAN: Unique identifier */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'ckan_remote_post_targets';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['label'] = 'ID';
  /* Field: CKAN: Date created */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'ckan_remote_post_targets';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['alter']['text'] = '<?php eco "asdasd"; ?>';
  /* Field: CKAN: Submission URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'ckan_remote_post_targets';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  /* Field: CKAN: Submission data */
  $handler->display->display_options['fields']['payload']['id'] = 'payload';
  $handler->display->display_options['fields']['payload']['table'] = 'ckan_remote_post_targets';
  $handler->display->display_options['fields']['payload']['field'] = 'payload';
  /* Field: CKAN: Submission Header */
  $handler->display->display_options['fields']['header']['id'] = 'header';
  $handler->display->display_options['fields']['header']['table'] = 'ckan_remote_post_targets';
  $handler->display->display_options['fields']['header']['field'] = 'header';
  /* Field: CKAN: Submission status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'ckan_remote_post_targets';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  /* Field: CKAN: Result */
  $handler->display->display_options['fields']['result']['id'] = 'result';
  $handler->display->display_options['fields']['result']['table'] = 'ckan_remote_post_targets';
  $handler->display->display_options['fields']['result']['field'] = 'result';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/ckan-submission-results';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'CKAN Submissions list';
  $handler->display->display_options['menu']['description'] = 'CKAN Submissions list';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'CKAN Submissions list';
  $handler->display->display_options['tab_options']['description'] = 'CKAN Submissions list';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $export['ckan_submission_result'] = $view;

  return $export;
}
