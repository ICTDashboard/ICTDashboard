<?php
/**
 * @file
 * Code for the ICT Project create functions.
 */

/**
 * Baseline Create Draft block
 * @param $nid
 * @return string
 */
function ict_project_baseline_create_draft_block ($nid) {
  $node = node_load($nid);

  if (!$node) {
    drupal_not_found();
  }

  if (!ict_project_access_project('edit', NULL, $node->nid)) {
    drupal_access_denied();
  }

  $state = ict_project_get_workflow_state($node->nid);
  if ($state != 'predraft') {
    drupal_set_message(t('Baseline draft cannot be created.'), 'error');
    drupal_goto('projects');
  }

  // update workflow state
  ict_project_set_workflow_state('draft', $node->nid, $node->vid);
  drupal_set_message(t('Draft has been created, now you can edit it.'));

  drupal_goto('baseline/' . $nid . '/edit-draft');
}
/**
 * Baseline Edit Draft block
 * @param $nid
 * @return string
 */
function ict_project_baseline_edit_draft_block ($nid) {
  $node = node_load($nid);

  if (!$node) {
    drupal_not_found();
  }

  if (!ict_project_access_project('edit', NULL, $node->nid)) {
    drupal_access_denied();
  }

  $state = ict_project_get_workflow_state($node->nid);
  if ($state != 'draft') {
    drupal_set_message(t('There is no draft.'), 'error');
    drupal_goto('projects');
  }

  module_load_include('inc', 'node', 'node.pages');
  $form = drupal_get_form('project_node_form', $node);

  // makes form elements titles
  function prepare_for_display(&$elem, &$form) {
    foreach (element_children($elem) as $element) {
      $elem[$element]['#title_display'] = 'invisible';
      $parent_element = &$form[reset($elem[$element]['#array_parents'])];
      if (!empty($elem[$element]['#description'])) {
        $parent_element['#description'] = $elem[$element]['#description'];
        $elem[$element]['#description'] = NULL;
      }
      if (!empty($elem[$element]['#title'])) {
        $parent_element['#title'] = $elem[$element]['#title'];
      }
      prepare_for_display($elem[$element], $form);
    }
  }

  foreach (element_children($form) as $element) {
    $element_name = explode('_', $element);
    if (reset($element_name) == 'field' || $element == 'title') {
      $form[$element]['#title_display'] = 'invisible';
      prepare_for_display($form[$element], $form);
    }
  }

  $form['#attached']['js'] = array(
    drupal_get_path('module', 'ict_project') . '/js/ict_project.js',
  );

  // PROJECT ADMIN USERS
  $project_admins = ict_project_baseline_get_admin_user_emails($node);
  $form['admin_user_details'] = array(
    '#type' => 'markup',
    '#markup' => theme('ict_project_baseline_admin_user_details', array(
      'departmental_admins' => $project_admins['departmental_admins'],
      'data_editors' => $project_admins['data_editors'],
      'data_approvers' => $project_admins['data_approvers']
    ))
  );

  $form['actions']['submit']['#attributes']['class'][] = 'submit-button';
  $form['actions']['submit_request']['#attributes']['class'][] = 'submit-button';
  $form['#theme'] = 'ict_project_baseline_edit_draft';

  return drupal_render($form);
}

/**
 * Baseline Edit Draft block
 * @param $nid
 * @return string
 */
function ict_project_rebaseline_create_block ($parent_project) {
  global $user;

  $parent_project = node_load($parent_project);
  $node = clone $parent_project;

  if (!$parent_project) {
    drupal_not_found();
  }

  if (!ict_project_access_project('rebaseline', NULL, $parent_project->nid)) {
    drupal_access_denied();
  }

  // main IDs
  $node->nid = NULL;
  $node->vid = NULL;
  $node->tnid = NULL;
  $node->log = NULL;

  // Also handle modules that attach a UUID to the node.
  $node->uuid = NULL;
  $node->vuuid = NULL;

  // user
  $node->name = $user->name;
  $node->uid = $user->uid;

  // other stuff
  $node->created = NULL;
  if (isset($node->book['mlid'])) {
    $node->book['mlid'] = NULL;
    $node->book['has_children'] = 0;
  }
  $node->path = NULL;
  $node->files = array();

  // calc fields removed
  $node->field_expenditure_budget_calc = NULL;
  $node->field_expenditure_to_date_calc = NULL;
  $node->field_number_of_benefits_calc = NULL;
  $node->field_schedule_status_calc = NULL;

  // field collections should be cloned
  foreach (field_info_fields() as $field_name => $field) {
    if ($field['type'] == 'field_collection' && isset($node->$field_name)) {
      foreach ($node->$field_name as $language => $values) {
        ict_project_field_collection_clone_items('node', $node, $field_name, $language);
      }
    }
  }

  // assign parent project
  $node->field_project[LANGUAGE_NONE][0]['target_id'] = $parent_project->nid;

  // get form
  module_load_include('inc', 'node', 'node.pages');
  $form = drupal_get_form('project_node_form', $node);

  // makes form elements titles
  function prepare_for_display(&$elem, &$form) {
    foreach (element_children($elem) as $element) {
      $elem[$element]['#title_display'] = 'invisible';
      $parent_element = &$form[reset($elem[$element]['#array_parents'])];
      if (!empty($elem[$element]['#description'])) {
        $parent_element['#description'] = $elem[$element]['#description'];
        $elem[$element]['#description'] = NULL;
      }
      if (!empty($elem[$element]['#title'])) {
        $parent_element['#title'] = $elem[$element]['#title'];
      }
      prepare_for_display($elem[$element], $form);
    }
  }

  foreach (element_children($form) as $element) {
    $element_name = explode('_', $element);
    if (reset($element_name) == 'field' || $element == 'title') {
      $form[$element]['#title_display'] = 'invisible';
      prepare_for_display($form[$element], $form);
    }
  }

  $form['#attached']['js'] = array(
    drupal_get_path('module', 'ict_project') . '/js/ict_project.js',
  );

  // PROJECT ADMIN USERS
  $project_admins = ict_project_baseline_get_admin_user_emails($parent_project);
  $form['admin_user_details'] = array(
    '#type' => 'markup',
    '#markup' => theme('ict_project_baseline_admin_user_details', array(
      'departmental_admins' => $project_admins['departmental_admins'],
      'data_editors' => $project_admins['data_editors'],
      'data_approvers' => $project_admins['data_approvers']
    ))
  );

  $form['actions']['submit']['#attributes']['class'][] = 'submit-button';
  $form['actions']['submit']['#value'] = t('Create re-baseline');
  $form['actions']['submit_request']['#attributes']['class'][] = 'submit-button';
  $form['#theme'] = 'ict_project_baseline_edit_draft';
  $form['#page_title'] = t('ICT Project Re-baseline Submission Form');

  return drupal_render($form);
}

/**
 * Copy editors and approvers from parent project
 * @param $node
 */
function ict_project_copy_editors_and_approvers($node) {
  $parent_project = ict_project_get_parent_project($node);
  $project_users = ict_project_baseline_get_admin_user_emails($parent_project);
  foreach ($project_users['data_approvers'] as $approver_email) {
    ict_project_access_add_approver($approver_email, $node->nid);
  }
  foreach ($project_users['data_editors'] as $editor_email) {
    ict_project_access_add_editor($editor_email, $node->nid);
  }
}

/**
 * Baseline Approve block
 * @param $nid
 * @return string
 */
function ict_project_baseline_approve_block($nid) {
  $node = node_load($nid);

  if (!$node) {
    drupal_not_found();
  }

  if (!ict_project_access_project('approve', NULL, $node->nid)) {
    drupal_access_denied();
  }

  $form = drupal_get_form('ict_project_baseline_approve_form', $nid);
  $approve_form = render($form);

  return theme('ict_project_baseline_approve_block', array(
    'approve_form' => $approve_form,
    'node' => $node
  ));
}

/**
 *
 * @param $form
 * @param $form_state
 */
function ict_project_baseline_approve_form($form, &$form_state, $nid) {
  $form['#theme'] = 'ict_project_baseline_approve_form';

  $form['nid'] = array(
    '#value' => $nid,
    '#type' => 'values'
  );

  $form['approve'] = array(
    '#type' => 'submit',
    '#value' => t('Approve'),
    '#attributes' => array('class' => array('submit-button')),
    '#submit' => array('ict_project_baseline_approve_form_submit_approve'),
    '#validate' => array('ict_project_baseline_approve_form_validate')
  );

  $form['decline'] = array(
    '#type' => 'submit',
    '#value' => t('Reject and Notify Editors'),
    '#attributes' => array('class' => array('submit-button')),
    '#submit' => array('ict_project_baseline_approve_form_submit_decline'),
    '#validate' => array('ict_project_baseline_approve_form_validate')
  );

  $form['comment'] = array(
    '#type' => 'textarea',
  );

  return $form;
}

function ict_project_baseline_edit_form($form, &$form_state, $nid) {
  $form['#theme'] = 'ict_project_baseline_edit_form';

  $form['nid'] = array(
    '#value' => $nid,
    '#type' => 'values'
  );

  $form['edit'] = array(
    '#markup' => l(
      t('Edit Baseline Draft'),
      "baseline/$nid/edit-draft",
      array('attributes' => array('class' => array(
        'submit-button'
      )))
    ),
  );

  $node = node_load($nid);
  $errs = ict_project_baseline_preview_page_validate_required_fields($node);

  if (empty($errs) && ict_project_access_project('edit', NULL, $nid)) {
    $form['request_approve'] = array(
      '#type' => 'submit',
      '#value' => t('Save and request approval'),
      '#attributes' => array('class' => array('submit-button')),
      '#submit' => array('ict_project_workflow_set_wait_approve_preview_page'),
      '#validate' => array('ict_project_baseline_request_approve_form_validate')
    );
  }

  return $form;
}

/**
 * Validate Vaseline approval
 *
 * @param $form
 * @param $form_state
 */
function ict_project_baseline_approve_form_validate ($form, &$form_state) {
  // make sure that other approver hasn't approved the project
  $nid = $form['nid']['#value'];
  if (!ict_project_access_project('approve', NULL, $nid)) {
    form_set_error('nid', t('Sorry but the Baseline Data cannot be approved. Make sure that you have correct access rights and that it has not been approved or declined by another Data Approver'));
  }
}

function ict_project_baseline_request_approve_form_validate($form, &$form_state) {
  $nid = $form['nid']['#value'];
  $node = node_load($nid);

  $errs = ict_project_baseline_preview_page_validate_required_fields($node);
  if (!empty($errs) || !ict_project_access_project('edit', NULL, $nid)) {
    form_set_error('nid', t('Sorry but the Baseline Data cannot be requested for approve. Make sure that you have correct access rights and all data entered valid'));
  }
}

/**
 * Submit Vaseline approval - APPROVED
 *
 * @param $form
 * @param $form_state
 */
function ict_project_baseline_approve_form_submit_approve ($form, &$form_state) {
  $nid = $form['nid']['#value'];
  // need to create new revision
  $node = node_load($nid);
  $node_wrapper = entity_metadata_wrapper('node', $node);
  $node->revision = TRUE;
  node_save($node);
  // update workflow state
  ict_project_set_workflow_state('approved', $node->nid, $node->vid);
  drupal_set_message(t('Baseline Data has been approved.'));

  $approver_name = _ict_project_get_user_name();
  __ict_mail_process_mails('ict_mail', 'baseline_approve', $node, array('data_approvers', 'data_editors'), array('approver_name' => $approver_name));

  $benefits_wrapper = $node_wrapper->field_benefits_realised;
  foreach($benefits_wrapper as $key => $val) {
    if ($val->field_status->raw() == 'removed') {
      $val->field_removed = REQUEST_TIME;
      $val->save();
    }
  }

  // redirect user to projects page
  $form_state['redirect'] = 'node/' . $nid;
}

/**
 * Submit Vaseline approval - DECLINED
 *
 * @param $form
 * @param $form_state
 */
function ict_project_baseline_approve_form_submit_decline ($form, &$form_state) {
  $nid = $form['nid']['#value'];
  // need to create new revision
  $node = node_load($nid);
  $node->revision = TRUE;
  node_save($node);

  $comment = $form_state['values']['comment'];
  // update workflow state
  ict_project_set_workflow_state('draft', $node->nid, $node->vid, $comment);
  drupal_set_message(t('Baseline Data has been declined.'));

  $approver_name = _ict_project_get_user_name();
  __ict_mail_process_mails('ict_mail', 'baseline_decline', $node, array('data_approvers', 'data_editors'), array('comment' => $comment, 'approver_name' => $approver_name));

  // redirect user to projects page
  $form_state['redirect'] = 'node/' . $nid;
}

/**
 * Project admin emails by role
 *
 * @param $node
 * @return array
 */
function ict_project_baseline_get_admin_user_emails ($node) {
  $node = !empty($node->nid) ? $node : node_load($node);

  $project_department = ict_department_get_department_tid_of_entity('project', $node);
  $query = db_select('users', 'u');
  $query->join('field_data_field_department', 'd', 'd.entity_id = u.uid');
  $query->join('users_roles', 'ur', 'u.uid = ur.uid');
  $query->condition('d.bundle', 'user');
  $query->condition('d.field_department_tid', $project_department);
  $query->condition('ur.rid', ICT_DEPARTMENT_ADMIN_ROLE);
  $query->fields('u', array('uid'));
  $results = $query->execute()->fetchCol();

  $departmental_admins = array();
  foreach ($results as $uid) {
    $departmental_admins[] = user_load($uid)->mail;
  }

  $approvers = array();
  foreach (ict_project_get_users($node->nid, ICT_PROJECT_APPROVER_ACCESS) as $uid) {
    $approvers[] = user_load($uid)->mail;
  }

  $editors = array();
  foreach (ict_project_get_users($node->nid, ICT_PROJECT_EDITOR_ACCESS) as $uid) {
    $user = user_load($uid);
    $editors[] = $user->mail;
  }

  return array(
    'departmental_admins' => $departmental_admins,
    'data_approvers' => $approvers,
    'data_editors' => $editors
  );
}

function _ict_project_baseline_get_simple_values ($items, $not_applicable = FALSE, $prefix = '', $suffix = '', $finance = FALSE) {
  $values = array();
  foreach ($items as $key => $item) {
    // exclude field meta data from the display
    if ($key === 'meta') continue;

    if (isset($item['safe_value'])) {
      // text fields
      $val = $item['safe_value'];
    }
    elseif (isset($item['taxonomy_term'])) {
      // term reference fields
      $val = $item['taxonomy_term']->name;
    }
    elseif (!isset($item['taxonomy_term']) && isset($item['tid'])) {
      // term reference fields
      $term = taxonomy_term_load($item['tid']);
      $val = $term->name;
    }
    elseif (isset($item['timezone'])) {
      // date fields
      $date = strtotime($item['value']);
      $val = format_date($date, 'medium', 'j F Y');
    }
    elseif (isset($item['value'])) {
      // number fields
      $val = $item['value'];
    }

    if ($finance) {
      $val = number_format($val, 2, '.', '');
    }
    $values[] = $val ? $prefix . $val . $suffix : '';
  }
  $default_value = $not_applicable ? t('Not Applicable') : '-';

  return $values ? $values : array($default_value);
}

function ict_project_baseline_approve_form_validate_required_fields($form, &$form_state) {
  $text = array(
    'field_program_name',
    'field_brief_project_summary',
    'field_responsible_officer_name',
    'field_resp_officer_position',
    'field_predicted_project_benefit',
  );
  $term = array(
    'field_government_entity_name',
    'field_portfolio_name',
    'field_project_stage',
  );
  $dates = array(
    'field_start_date',
    'field_original_completion_date',
  );
  foreach($term as $field) {
    if (empty($form_state['values'][$field]['und'][0]['tid'])) {
      form_set_error($field . '][und][0][value', 'Field <em>' . $form[$field]['und']['#title'] . '</em> is required.');
    }
  }
  foreach($text as $field) {
    if (empty($form_state['values'][$field]['und'][0]['value'])) {
      form_set_error($field . '][und][0][value', 'Field <em>' . $form[$field]['und'][0]['value']['#title'] . '</em> is required.');
    }
  }
  foreach($dates as $field) {
    if (empty($form_state['values'][$field]['und'][0]['value'])) {
      form_set_error($field . '][und][0', 'Field <em>' . $form[$field]['und'][0]['#title'] . '</em> is required.');
    }
  }

  // date validation
  if (!empty($form_state['values']['field_start_date']['und'][0]['value']) &&
    !empty($form_state['values']['field_original_completion_date']['und'][0]['value'])) {
    if ($form_state['values']['field_start_date']['und'][0]['value'] >= $form_state['values']['field_original_completion_date']['und'][0]['value']) {
      form_set_error('field_start_date][und][0', t('<em>Original Approved Start Date</em> cannot be later than <em>Original Approved Completion Date </em>'));
    }
  }

  ict_update_benefits_realised_validate($form, $form_state);
  ict_project_budget_by_year_validate($form, $form_state);
}

function ict_project_baseline_preview_page_validate_required_fields($node) {
  if (empty($node)) {
    return array(t('Incorrect entity passed'));
  }
  $errors = &drupal_static(__FUNCTION__ . $node->nid . $node->vid);
  if (isset($errors)) {
    return $errors;
  }

  $fields = array(
    'text' => array(
      'field_program_name',
      'field_brief_project_summary',
      'field_responsible_officer_name',
      'field_resp_officer_position',
      'field_predicted_project_benefit',
    ),
    'term' => array(
      'field_government_entity_name',
      'field_portfolio_name',
      'field_project_stage',
    ),
    'dates' => array(
      'field_start_date',
      'field_original_completion_date',
    ),
  );
  foreach($fields as $type => $subfields) {
    foreach($subfields as $field) {
      if ((empty($node->{$field}['und'][0]['tid']) && $type == 'term')
        || (empty($node->{$field}['und'][0]['value']) && $type == 'text')
        || (empty($node->{$field}['und'][0]['value']) && $type == 'dates')) {
        $field_info = field_info_instance('node', $field, 'project');
        $errors[] = t('Field <em>' . $field_info['label'] . '</em> is required.');
      }
    }
  }

  // date validation
  if (!empty($node->field_start_date['und'][0]['value']) &&
    !empty($node->field_original_completion_date['und'][0]['value'])) {
    if ($node->field_start_date['und'][0]['value'] >= $node->field_original_completion_date['und'][0]['value']) {
      $errors[] = t('<em>Original Approved Start Date</em> cannot be later than <em>Original Approved Completion Date </em>');
    }
  }

  ict_update_benefits_realised_preview_page_validate($node, $errors);
  ict_project_budget_by_year_preview_page_validate($node, $errors);

  return $errors;
}



function ict_project_budget_by_year_validate($form, &$form_state) {
  $budget_values = $form_state['values']['field_original_total_budget'][LANGUAGE_NONE];
  $current_fin_year = __ict_project_get_current_fin_year();
  foreach ($budget_values as $key => $value) {
    if (!is_numeric($key)) continue;
      if (empty($value['field_total'][LANGUAGE_NONE][0]['value'])) {
        $year = $value['field_year'][LANGUAGE_NONE][0]['value'];
        if ($form['#node']->type == 'update' && $year != $current_fin_year) {
          continue;
        }
        form_set_error('field_original_total_budget][und]['.$key.'][field_total][und][0][value', t('Field <em>Budget Value</em> is required for !year Financial Year', array(
          '!year' => $year
        )));
      }
  }
}

function ict_project_budget_by_year_preview_page_validate($node, &$errors) {
  $node_wrapper = entity_metadata_wrapper('node', $node);
  $budget_values = $node_wrapper->field_original_total_budget->value();
  $current_fin_year = __ict_project_get_current_fin_year();
  foreach ($budget_values as $key => $value) {
    if (!is_numeric($key)) continue;
    if (empty($value->field_total[LANGUAGE_NONE][0]['value'])) {
      $year = $value->field_year[LANGUAGE_NONE][0]['value'];
      if ($node->type == 'update' && $year != $current_fin_year) {
        continue;
      }
      $errors[] = t(t('Field <em>Budget Value</em> is required for !year Financial Year', array(
        '!year' => $year
      )));
    }
  }
}

/**
 * Get current Financial Year
 * @return string
 */
function __ict_project_get_current_fin_year () {
  // current date
  $current_date = new DateTime();

  // get required current year values
  $current_year_short = $current_date->format('y');
  $current_year_long = $current_date->format('Y');

  return
    $current_date > new DateTime ($current_year_long . '-07-01 00:00:00') ?
      $current_year_short . '/' . ($current_year_short + 1) :
      ($current_year_short - 1) . '/' . $current_year_short;
}

/**
 * Checks if project is published
 * @param $nid
 * @return bool
 */
function ict_project_is_published_project($nid) {
  $updates = ict_update_project_get_list($nid);
  $project_state = ict_project_get_workflow_state($nid);
  $update_id = end($updates);

  if ($update_id) {
    $update_state = ict_project_get_workflow_state($update_id);
    if (in_array($update_state, array('approved')) && in_array($project_state, array('approved'))) {
      return TRUE;
    }
  }
  return FALSE;
}

/**
 * Clone a Field Collection. Helper function for hook_node_clone_alter().
 * Taken from field_collection_clone_items() - https://www.drupal.org/project/field_collection_node_clone
 */
function ict_project_field_collection_clone_items($entity_type, &$entity, $fc_field, $language = LANGUAGE_NONE) {
  $entity_wrapper = entity_metadata_wrapper($entity_type, $entity);
  $old_items = $entity_wrapper->{$fc_field}->value();
  if (!is_array($old_items)) {
    $old_items = array($old_items);
  }

  $field_info_instances = field_info_instances();
  $field_names = element_children($field_info_instances['field_collection_item'][$fc_field]);

  unset($entity->{$fc_field}[$language]);

  foreach ($old_items as $old_item) {
    $new_item = entity_create('field_collection_item', array('field_name' => $fc_field));
    $new_item->setHostEntity($entity_type, $entity);

    foreach ($field_names as $field_name) {
      if (!empty($old_item->{$field_name})) {
        $new_item->{$field_name} = $old_item->{$field_name};
      }
    }

    // Now check if any of the fields in the newly cloned fc item is a field
    // collection and recursively call this function to properly clone it.
    foreach ($field_names as $field_name) {
      if (!empty($new_item->{$field_name})) {
        $field_info = field_info_field($field_name);
        if ($field_info['type'] == 'field_collection') {
          field_collection_clone_items('field_collection_item', $new_item, $field_name, $language);
        }
      }
    }
  }
}

/**
 * Gets re-baseline of the project
 * @param $nid
 * @return array
 */
function ict_project_get_project_rebaseline ($project_id) {
  $query = db_select('node', 'n');
  $query->fields('n', array('nid', 'title'));
  $query->join('field_data_field_project', 'baseline', 'baseline.entity_id = n.nid');
  $query->condition('n.type', 'project');
  $query->condition('baseline.field_project_target_id', $project_id);
  return $query->execute()->fetchAssoc();
}

/**
 * Checks if project is a re-baseline
 * @param $node|$nid
 * @return bool
 */
function ict_project_is_rebaseline ($node) {
  $node = !empty($node->nid) ? $node : node_load($node);

  if ($node->type != 'project') {
    return FALSE;
  }

  if (!empty($node->field_project[LANGUAGE_NONE][0]['target_id'])) {
    return TRUE;
  }

  return FALSE;
}

/**
 * Gets parent project
 * @param $node|$nid
 * @return int
 */
function ict_project_get_parent_project ($node) {
  $node = !empty($node->nid) ? $node : node_load($node);

  if ($node->type != 'project') {
    return FALSE;
  }

  if (!empty($node->field_project[LANGUAGE_NONE][0]['target_id'])) {
    return $node->field_project[LANGUAGE_NONE][0]['target_id'];
  }

  return FALSE;
}

/**
 * Gets last rebaseline project
 * @param $node|$nid
 * @return int
 */
function ict_project_get_last_rebaseline_project($nid) {
  $rebaseline = '';
  $parent = ict_project_get_project_rebaseline ($nid);
  $last_baseline = FALSE;

  if(!empty($parent['nid']) && ict_project_access_project('view', NULL, $parent['nid'])) {
    do {
      $last_nid = $parent['nid'];
      $parent = ict_project_get_project_rebaseline($last_nid);
      if (!isset($parent['nid'])) {
        $last_baseline = TRUE;
        $rebaseline = $last_nid;
      }
    } while(!$last_baseline);
  }
  return $rebaseline;
}

/**
 * Gets all rebaseline projects
 * @param $node|$nid
 * @return int
 */
 function ict_project_get_all_rebaselines($nid) {
  $rebaseline = ict_project_get_last_rebaseline_project($nid);
  $check_rebaseline = ict_project_is_rebaseline ($rebaseline);

  if(!empty($check_rebaseline) && $check_rebaseline == TRUE) {
    $rebaselines = ict_project_get_all_parents_project($rebaseline);
  }
  return $rebaselines;
 }

/**
 * Get project first approve date
 * @param $nid
 * @return int
 */
function ict_project_get_approve_date($nid) {
  $query = db_select('project_workflow', 'pw');
  $query->fields('pw', array('created'));
  $query->condition('pw.nid', $nid, '=');
  $query->condition('state', 'approved');

  return $query->execute()->fetchField();
}

/**
 * Get project unpublished date
 * @param $nid
 * @return int
 */
function ict_project_get_unpublished_date($nid) {
  $query = db_select('project_workflow', 'pw');
  $query->fields('pw', array('created'));
  $query->condition('pw.nid', $nid, '=');
  $query->condition('state', 'unpublished');

  return $query->execute()->fetchField();
}


/**
 * Gets all project relatives
 * @param $node|$nid
 * @return int
 */
function ict_project_get_all_parents_project($node) {
  $relatives = array();
  $parent = ict_project_get_parent_project ($node);

  if ($parent) {
    array_push($relatives, $parent);
    do {
      $nid = $parent;
      $parent = ict_project_get_parent_project ($nid);
      if ($parent) {
        array_push($relatives, $parent);
      }
    } while($parent);
  }

  return $relatives;
}

/**
 * Gets total budget
 * @param $nid
 * @return int
 */
function ict_project_get_total_budget($nid) {
  if ($nid) {
    $budget_items = _ict_project_prepare_budget_history($nid, 'view');
  }

  // should show previous approved values OR current pendong values only
  $baseline_row = reset($budget_items);
  $last_update = end($budget_items);

  if ($last_update['entity_type'] == 'update') {
    $budget_items = array($baseline_row, $last_update);
  }
  else {
    $budget_items = array($baseline_row);
  }

  // total budget and expenditure values
  $total_budget = 0;
  foreach ($budget_items[0]['budget_items'] as $budget_value) {
    $total_budget += (float)$budget_value->field_total[LANGUAGE_NONE][0]['value'];
  }

  return $total_budget;
}

/**
 * Get project first update
 * @param $nid
 * @return int
 */
function ict_project_get_first_update($nid) {
  $update_nids = array();
  $updates = ict_update_get_allowed_entity_list($nid);

  foreach ($updates as $update) {
    $update_nids = $update;
  }

  if (!empty($update_nids)) {
    $query = db_select('project_workflow', 'pw');
    $query->fields('pw', array('created'));
    $query->condition('pw.nid', $update_nids, 'IN');
    $query->condition('state', 'approved');
    $query->orderBy('pw.created', 'ASC');
    $query->range(0 ,1);

    return $query->execute()->fetchField();
  }

  return '';
}

/**
 * Get project baseline history block
 * @param $nid
 * @return theme
 */
function ict_project_project_history ($nid) {

  if (!ict_project_access_project('view', NULL, $nid)) {
    drupal_access_denied();
  }

  $current_baseline = node_load($nid);

  if ($current_baseline->type != 'project') {
    drupal_not_found();
  }
  $old_baselines = array();
  $projects = ict_project_get_all_parents_project($nid);
  $budget_items = array();
  $current_baseline->approved_on = ict_project_get_approve_date($nid);
  $current_baseline->field_original_total_budget = number_format(ict_project_get_total_budget($nid), 2, '.', ' ');
  $current_baseline->first_update = ict_project_get_first_update($nid);

  if (is_array($projects) && !empty($projects)) {
    $old_baselines = node_load_multiple($projects);
    foreach ($projects as $project_id) {
      $old_baselines[$project_id]->approved_on = ict_project_get_approve_date($project_id);
      $old_baselines[$project_id]->unpublished_on = ict_project_get_unpublished_date($project_id);
      $old_baselines[$project_id]->field_original_total_budget = number_format(ict_project_get_total_budget($project_id), 2, '.', ' ');
      $old_baselines[$project_id]->first_update = ict_project_get_first_update($project_id);
    }
  }

  return theme('project_baseline_history', array('current_baseline' => $current_baseline, 'old_baselines' => $old_baselines, 'count_baslines' => count($old_baselines)));
}

/**
 * Gets all unpublished projects
 * @return mixed
 */
function ict_project_get_all_unpublished_projects() {

  $unpublished = &drupal_static(__FUNCTION__);

  if (isset($unpublished)) {
    return $unpublished;
  }

  $query = db_select('node', 'project');
  $query->condition('project.type', 'project');
  $query->join('project_workflow', 'wf', 'wf.nid = project.nid AND state = :state', array(':state' => 'unpublished'));
  $query->addField('project', 'nid');
  $query->groupBy('project.nid');
  $unpublished = $query->execute()->fetchAllKeyed(0, 0);
  
  return $unpublished;
}
