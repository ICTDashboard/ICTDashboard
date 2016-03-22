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
  __ict_project_process_mails('ict_project', 'baseline_approve', $node, array('data_approvers', 'data_editors'), array('approver_name' => $approver_name));

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
  __ict_project_process_mails('ict_project', 'baseline_decline', $node, array('data_approvers', 'data_editors'), array('comment' => $comment, 'approver_name' => $approver_name));

  // redirect user to projects page
  $form_state['redirect'] = 'node/' . $nid;
}

function __ict_project_process_mails($module, $hook, $node, $acc_types, $params = array()) {
  global $user;

  $accs = __ict_project_prepare_mails($node);
  foreach($acc_types as $type) {
    foreach ($accs[$type] as $acc) {
      if ($user->mail == $acc['mail']) continue;
      drupal_mail($module, $hook . '_' . $type, $acc['mail'], LANGUAGE_NONE, array_merge(
        array(
          'name' => $acc['name'],
          'title' => $node->title,
          'dep_admins' => $accs['departmental_admins'],
        ),
        $params
      ));
    }
  }
}

function __ict_project_prepare_mails($node) {
  $emails = ict_project_baseline_get_admin_user_emails($node);
  $accs = array();

  // get only first departmental admin
  $creator = user_load($node->uid);
  if (in_array($creator->mail)) {
    $emails['departmental_admins'] = array($creator->mail);
  }
  else {
    $emails['departmental_admins'] = array(array_shift($emails['departmental_admins']));
  }

  foreach($emails as $type => $mails) {
    foreach ($mails as $mail) {
      $acc = user_load_by_mail($mail);
      $accs[$type][] = array(
        'mail' => $acc->mail,
        'name' => _ict_project_get_user_name($acc),
      );
    }
  }

  return $accs;
}

function ict_project_mail($key, &$message, $params) {
  global $base_url;

  if (!empty($params['dep_admins'])) {
    $dep_name = implode(', ', array_map(function($val){ return $val['name']; }, $params['dep_admins']));
  }
  $message['body'] = array(t("Dear @NAME,", array('@NAME' => $params['name'])));
  switch($key) {
    case 'approver_add':
      $message['subject'] = t('ICT Projects Dashboard - Assigned as Project Approver');
      $message['body'][] = t("You have been assigned to the project @PROJ_TITLE as the Project Approver.", array('@PROJ_TITLE' => $params['title']));
      $message['body'][] = t("You will receive an e-mail notification when the baseline is ready for your approval. To view who is the assigned Project Editor please log into your ICT Projects Dashboard account. !URL", array('!URL' => $base_url));
      $message['body'][] = t("Please contact your Departmental Administrator @ADMIN_NAME if you have any queries.", array('@ADMIN_NAME' => $params['admin_name']));
      break;

    case 'approver_remove':
      $message['subject'] = t('ICT Projects Dashboard - Remove as Project Approver');
      $message['body'][] = t("You have been removed from the project @PROJ_TITLE as the Project Approver.", array('@PROJ_TITLE' => $params['title']));
      $message['body'][] = t("Please contact your Departmental Administrator @ADMIN_NAME if you have any queries.", array('@ADMIN_NAME' => $params['admin_name']));
      break;

    case 'editor_add':
      $message['subject'] = t('ICT Projects Dashboard - Assigned as Project Editor');
      $message['body'][] = t("You have been assigned to the project @TITLE as the Project Editor. Please log into your ICT Projects Dashboard account to enter the project baseline data. !URL", array('@TITLE' => $params['title'], '!URL' => $base_url));
      $message['body'][] = t("It is highly recommended that you enter and submit the baseline for approval as soon as possible after receiving this e-mail.");
      $message['body'][] = t("Please contact your Departmental Administrator @ADMIN_NAME if you have any queries.", array('@ADMIN_NAME' => $params['admin_name']));
      break;

    case 'editor_remove':
      $message['subject'] = t('ICT Projects Dashboard - Remove as Project Editor');
      $message['body'][] = t("You have been removed from the project @PROJ_TITLE as the Project Editor.", array('@PROJ_TITLE' => $params['title']));
      $message['body'][] = t("Please contact your Departmental Administrator @ADMIN_NAME if you have any queries.", array('@ADMIN_NAME' => $params['admin_name']));
      break;

    case in_array($key, array('baseline_approve_data_approvers', 'baseline_approve_data_editors')):
      $message['subject'] = t('ICT Projects Dashboard - Project Baseline Approved');
      $message['body'][] = t('@APPROVER_NAME has <strong>approved</strong> the baseline submission for the project @TITLE.', array('@APPROVER_NAME' => $params['approver_name'], '@TITLE' => $params['title']));
      $message['body'][] = t('@TITLE is <strong>not publicly available</strong> on the dashboard until the project\'s first update is approved.', array('@TITLE' => $params['title']));
      if ($key == 'baseline_approve_data_editors') {
        $plus_three_month = format_date(strtotime('+3 month'), 'medium', 'd/m/Y');
        $message['body'][] = t('You will need to update project details and submit it for approval before @3_MONTH. An update project e-mail reminder will be sent to you 1 month prior to this date.', array('@3_MONTH' => $plus_three_month));
        $message['body'][] = t('Please log into your ICT Projects Dashboard account to update and submit the project data. !URL', array('!URL' => $base_url));
      }
      elseif ($key == 'baseline_approve_data_approvers') {
        $message['body'][] = t('Please log into your ICT Projects Dashboard account to review the project data. !URL', array('!URL' => $base_url));
      }
      $message['body'][] = t('Please contact @APPROVER_NAME or your Departmental Administrator @DEP_ADMIN if you have any queries.', array('@APPROVER_NAME' => $params['approver_name'], '@DEP_ADMIN' => $dep_name));
      break;

    case in_array($key, array('baseline_request_approve_data_approvers', 'baseline_request_approve_data_editors')):
      $message['subject'] = t('ICT Projects Dashboard - Project Baseline Waiting for Approval');
      if ($key == 'baseline_request_approve_data_approvers') {
        $message['body'][] = t('@EDITOR has requested your approval for the baseline submission for the project @TITLE.', array('@EDITOR' => $params['editor_name'], '@TITLE' => $params['title']));
        $message['body'][] = t('Please log into your ICT Projects Dashboard account to review and approve the submitted project. !URL', array('!URL' => $base_url));
        $message['body'][] = t('It is highly recommended that you review and approve or submit your feedback as soon as possible after receiving this e-mail. <strong>Please note that once approved, some baseline data such as budget and original dates, cannot be changed.</strong>');
      }
      elseif ($key == 'baseline_request_approve_data_editors') {
        $message['body'][] = t('@EDITOR has requested approval for the baseline submission for the project @TITLE.', array('@EDITOR' => $params['editor_name'], '@TITLE' => $params['title']));
        $message['body'][] = t('Please log into your ICT Projects Dashboard account to review the submitted project. !URL', array('!URL' => $base_url));
      }
      $message['body'][] = t('Please contact your @EDITOR or Departmental Administrator @DEP_ADMIN if you have any queries. ', array('@EDITOR' => $params['editor_name'], '@DEP_ADMIN' => $dep_name));
      break;

    case in_array($key, array('update_request_approve_data_approvers', 'update_request_approve_data_editors')):
      $message['subject'] = t('ICT Projects Dashboard - Project Update Waiting for Approval');
      if ($key == 'update_request_approve_data_approvers') {
        $message['body'][] = t('@EDITOR has requested your approval for the update submission for the project @TITLE.', array('@EDITOR' => $params['editor_name'], '@TITLE' => $params['title']));
        $message['body'][] = t('Please log into your ICT Projects Dashboard account to review and approve the submitted project. !URL', array('!URL' => $base_url));
        $message['body'][] = t('It is highly recommended that you review and approve or submit your feedback as soon as possible after receiving this e-mail. <strong>Please note that once approved, this update data will be published on the Dashboard.</strong>');
      }
      elseif ($key == 'update_request_approve_data_editors') {
        $message['body'][] = t('@EDITOR has requested approval for the update submission for the project @TITLE.', array('@EDITOR' => $params['editor_name'], '@TITLE' => $params['title']));
        $message['body'][] = t('Please log into your ICT Projects Dashboard account to review the submitted project. !URL', array('!URL' => $base_url));
      }
      $message['body'][] = t('Please contact your @EDITOR or Departmental Administrator @DEP_ADMIN if you have any queries. ', array('@EDITOR' => $params['editor_name'], '@DEP_ADMIN' => $dep_name));
      break;

    case in_array($key, array('baseline_decline_data_editors', 'baseline_decline_data_approvers')):
      $message['subject'] = t('ICT Projects Dashboard - Project Baseline Not Approved');
      $msg = t('@APPROVER_NAME has <strong>not approved</strong> the baseline submission for the project @TITLE', array('@APPROVER_NAME' => $params['approver_name'], '@TITLE' => $params['title']));
      $msg .= !empty($params['comment']) ? t(' for the following reasons') : '.';
      $message['body'][] = $msg;
      if (!empty($params['comment'])) {
        $message['body'][] = nl2br($params['comment']);
      }
      if ($key == 'baseline_decline_data_editors') {
        $message['body'][] = t('Please log into your ICT Projects Dashboard account to edit and resubmit the project baseline. !URL', array('!URL' => $base_url));
        $message['body'][] = t('It is highly recommended that you enter and re-submit the project updates for approval as soon as possible after receiving this e-mail.');
      }
      elseif ($key == 'baseline_decline_data_approvers') {
        $message['body'][] = t('Please log into your ICT Projects Dashboard account to review the project baseline. !URL', array('!URL' => $base_url));
      }
      $message['body'][] = t('Please contact @APPROVER_NAME or your Departmental Administrator @DEP_ADMIN if you have any queries.', array('@APPROVER_NAME' => $params['approver_name'], '@DEP_ADMIN' => $dep_name));
      break;

    case in_array($key, array('update_approve_data_approvers', 'update_approve_data_editors')):
      $message['subject'] = t('ICT Projects Dashboard - Project Update Approved');
      $message['body'][] = t('@APPROVER_NAME has <strong>approved</strong> the recent update submission for the project @TITLE.', array('@APPROVER_NAME' => $params['approver_name'], '@TITLE' => $params['title']));
      if ($key == 'update_approve_data_editors') {
        $plus_three_month = format_date(strtotime('+3 month'), 'medium', 'd/m/Y');
        $message['body'][] = t('@TITLE is <strong>publicly available</strong> on the dashboard. No further action is require until your next scheduled update @3_MONTH. An update project e-mail reminder will be sent to you 1 month prior this date.', array('@3_MONTH' => $plus_three_month, '@TITLE' => $params['title']));
        $message['body'][] = t('Please log into your ICT Projects Dashboard account to update and submit the project data. !URL', array('!URL' => $base_url));
      }
      elseif ($key == 'update_approve_data_approvers') {
        $message['body'][] = t('@TITLE is <strong>publicly available</strong> on the dashboard.', array('@TITLE' => $params['title']));
      }
      $message['body'][] = t('Please contact @APPROVER_NAME or your Departmental Administrator @DEP_ADMIN if you have any queries.', array('@APPROVER_NAME' => $params['approver_name'], '@DEP_ADMIN' => $dep_name));
      break;

    case in_array($key, array('update_decline_data_approvers', 'update_decline_data_editors')):
      $message['subject'] = t('ICT Projects Dashboard - Project Update Not Approved');
      $msg = t('@APPROVER_NAME has <strong>not approved</strong> the recent update submission for the project @TITLE', array('@APPROVER_NAME' => $params['approver_name'], '@TITLE' => $params['title']));
      $msg .= !empty($params['comment']) ? t(' for the following reasons') : '.';
      $message['body'][] = $msg;
      if (!empty($params['comment'])) {
        $message['body'][] = nl2br($params['comment']);
      }
      if ($key == 'update_decline_data_editors') {
        $message['body'][] = t('Please log into your ICT Projects Dashboard account to edit and resubmit the project. !URL', array('!URL' => $base_url));
        $message['body'][] = t('Please note that once approved, this update data will be published on the Dashboard.');
      }
      elseif ($key == 'update_decline_data_approvers') {
        $message['body'][] = t('Please log into your ICT Projects Dashboard account to review the project. !URL', array('!URL' => $base_url));
      }
      $message['body'][] = t('Please contact @APPROVER_NAME or your Departmental Administrator @DEP_ADMIN if you have any queries.', array('@APPROVER_NAME' => $params['approver_name'], '@DEP_ADMIN' => $dep_name));
      break;
  }
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
