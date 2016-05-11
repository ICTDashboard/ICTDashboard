<?php

/**
 * @file
 * Code for the ICT Project edit functions.
 */

/**
 * Project List
 */
function ict_project_project_list_block() {
  global $user;
  $user = user_load($user->uid);
  $results = array();
  $get = $_GET;

  drupal_add_js(drupal_get_path('module', 'ict_project') . '/js/project-listing.js');

  $query = db_select('node', 'n')
    ->fields('n', array('nid', 'title', 'changed'))
    ->condition('n.type', 'project');

  // unpublished project should be excluded
  $unpublished_projects = ict_project_get_all_unpublished_projects();
  if ($unpublished_projects) {
    $query->condition('n.nid', $unpublished_projects, 'NOT IN');
  }

  $tid = !empty($user->field_department[LANGUAGE_NONE][0]['tid']) ?
    $user->field_department[LANGUAGE_NONE][0]['tid'] :
    NULL;
  $roles = array(ICT_ADMINISTRATOR_ROLE, ICT_FINANCE_ADMIN_ROLE);

  if (!array_intersect_key($user->roles, array_flip($roles)) &&
    $tid) {

    $query->join(
      'field_data_field_department',
      'd',
      'd.bundle = n.type AND n.nid = d.entity_id'
    );

    $query->condition(
      'd.field_department_tid',
      $user->field_department[LANGUAGE_NONE][0]['tid']
    );

  }

  // Pager configs
  $count = $query->execute()->rowCount();
  $pager_tags = array(
    t('First'),
    t('Previous'),
    t('...'),
    t('Next'),
    t('Last'),
  );
  $pager = array(
    '10' => '10',
    '25' => '25',
    '50' => '50',
    '0' => '0',
  );
  $per_page = isset($get['per_page']) && isset($pager[$get['per_page']]) ? $pager[$get['per_page']] : reset($pager);
  $page = pager_default_initialize($count, $per_page);
  $pager = array(
    '#title' => t('Display'),
    '#type' => 'select',
    '#options' => $pager,
    '#value' => $per_page,
    '#attributes' => array('class' => array('ict-projects-table-perpage')),
  );
  $pager['#options']['0'] = 'All';

  if ($per_page) {
    $query->range($page * $per_page, $per_page);
  }

  $query->groupBy('n.nid');

  $results = $query
    ->orderBy('n.changed', 'DESC')
    ->execute()
    ->fetchAll();

  $tmp_get = $get;
  unset($tmp_get['per_page']);
  if (empty($tmp_get)) {
    drupal_add_js(array('ict' => array('base_path' => url(current_path()) . '?')), 'setting');
  }
  else {
    drupal_add_js(array('ict' => array('base_path' => url(current_path(), array('query' => $tmp_get)))), 'setting');
  }

  return theme('ict_project_listing_block', array(
    'rows' => $results,
    'pager' => $pager,
    'pager_tags' => $pager_tags
  ));
}
