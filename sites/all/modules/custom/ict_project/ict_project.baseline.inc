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
    '#value' => t('Decline'),
    '#attributes' => array('class' => array('submit-button')),
    '#submit' => array('ict_project_baseline_approve_form_submit_decline'),
    '#validate' => array('ict_project_baseline_approve_form_validate')
  );

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
  $node->revision = TRUE;
  node_save($node);
  // update workflow state
  ict_project_set_workflow_state('approved', $node->nid, $node->vid);
  drupal_set_message(t('Baseline Data has been approved.'));

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
  // update workflow state
  ict_project_set_workflow_state('draft', $node->nid, $node->vid);
  drupal_set_message(t('Baseline Data has been declined.'));

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

function _ict_project_baseline_get_simple_values ($items) {
  $values = array();
  foreach ($items as $key => $item) {
    // exclude field meta data from the display
    if ($key === 'meta') continue;

    if (isset($item['safe_value'])) {
      // text fields
      $values[] = $item['safe_value'];
    }
    elseif (isset($item['taxonomy_term'])) {
      // term reference fields
      $values[] = $item['taxonomy_term']->name;
    }
    elseif (isset($item['timezone'])) {
      // date fields
      $date = strtotime($item['value']);
      $values[] = date('d/m/Y', $date);
    }
    elseif (isset($item['value'])) {
      // number fields
      $values[] = $item['value'];
    }
  }

  return $values ? $values : array('-');
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
    'field_implementation_partners',
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
      form_set_error('field_start_date][und][0', t('<em>Original approved start date</em> cannot be later than <em>Original approved completion date </em>'));
    }
  }

  ict_update_benefits_realised_validate($form, $form_state);
  ict_project_budget_by_year_validate($form, $form_state);
}

function ict_project_budget_by_year_validate($form, &$form_state) {
  $budget_values = $form_state['values']['field_original_total_budget'][LANGUAGE_NONE];
  foreach ($budget_values as $key => $value) {
    if (!is_numeric($key)) continue;
      if (empty($value['field_total'][LANGUAGE_NONE][0]['value'])) {
        $year = $value['field_year'][LANGUAGE_NONE][0]['value'];
        form_set_error('field_original_total_budget][und]['.$key.'][field_total][und][0][value', t('Field <em>Budget Value</em> is required for !year Financial Year', array(
          '!year' => $year
        )));
      }
  }
}