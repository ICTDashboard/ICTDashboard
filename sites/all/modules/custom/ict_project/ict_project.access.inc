<?php
/**
 * @file
 * Code for the ICT Project edit functions.
 */

define ('ICT_PROJECT_APPROVER_ACCESS', 'approve');
define ('ICT_PROJECT_EDITOR_ACCESS', 'edit');
define ('ICT_DEPARTMENT_ADMIN_ROLE', '153917155');
define ('ICT_FINANCE_ADMIN_ROLE', '41888116');

/**
 * Adds approver to project
 *
 * @param $email
 * @param $nid
 */
function ict_project_access_add_approver($email, $nid) {
  $user = user_load_by_mail($email);

  $query = db_insert('project_access')
    ->fields(array(
      'uid' => $user->uid,
      'nid' => $nid,
      'access_type' => ICT_PROJECT_APPROVER_ACCESS,
      'created' => time()
    ))
    ->execute();

  $node_wrapper = entity_metadata_wrapper('node', $nid);
  drupal_mail('ict_mail', 'approver_add', $email, LANGUAGE_NONE, array(
    'title' => $node_wrapper->title->value(),
    'name' => _ict_project_get_user_name($user),
    'admin_name' => _ict_project_get_user_name(),
  ));

  return $query;
}

/**
 * Removes approver to project
 *
 * @param $email
 * @param $nid
 */
function ict_project_access_remove_approver($email, $nid) {
  $user = user_load_by_mail($email);

  $query = db_delete('project_access')
    ->condition('uid', $user->uid)
    ->condition('nid', $nid)
    ->condition('access_type', ICT_PROJECT_APPROVER_ACCESS)
    ->execute();

  $node_wrapper = entity_metadata_wrapper('node', $nid);
  drupal_mail('ict_mail', 'approver_remove', $email, LANGUAGE_NONE, array(
    'title' => $node_wrapper->title->value(),
    'name' => _ict_project_get_user_name($user),
    'admin_name' => _ict_project_get_user_name(),
  ));

  return $query;
}

function ict_project_access_project($op, $account = NULL, $nid = NULL) {
  if (!$account) {
    global $user;
    $account = $user;
  }

  if ($account->uid == 1) {
//  FOR DEVELOPMENT PURPOSES ONLY!!!
//    return TRUE;
  }

  if ($op == 'view' && $nid) {
    $state = ict_project_get_workflow_state($nid);
    if (empty($account->uid)) {
     return ict_project_is_published_project($nid);
    }
    if (in_array($state, array('draft', 'waiting_approval'))) {
      return __ict_project_user_is_dep_member_for_project($nid, $account);
    }
    if (in_array($state, array('approved'))) {
      return TRUE;
    }
    return FALSE;
  }

  if ($op == 'create') {
    if (user_has_role(ICT_DEPARTMENT_ADMIN_ROLE, $account)) {
      return TRUE;
    }
    return FALSE;
  }

  if ($op == 'edit' && $nid) {
    if (in_array(ict_project_get_workflow_state($nid), array('draft')) &&
      in_array($account->uid, ict_project_get_users($nid, ICT_PROJECT_EDITOR_ACCESS))) {
      return TRUE;
    }
    return FALSE;
  }

  if ($op == 'approve' && $nid) {
    if (in_array(ict_project_get_workflow_state($nid), array('waiting_approval')) &&
      in_array($account->uid, ict_project_get_users($nid, ICT_PROJECT_APPROVER_ACCESS))) {
      return TRUE;
    }
    return FALSE;
  }

  if ($op == 'delete' && $nid) {
    if (__ict_project_user_is_dep_admin_for_project($nid, $account) &&
      ict_project_check_if_baseline_ever_approved($nid) &&
      !ict_project_get_project_rebaseline($nid)) {
      return TRUE;
    }
    return FALSE;
  }

  if ($op == 'manage_users' && $nid) {
    if (!ict_project_get_project_rebaseline($nid) &&
      __ict_project_user_is_dep_admin_for_project($nid, $account)) {
      return TRUE;
    }
    return FALSE;
  }

  if ($op == 'rebaseline' && $nid) {
    if (__ict_project_user_is_dep_admin_for_project($nid, $account) &&
      ict_project_is_published_project($nid) &&
      !ict_project_get_project_rebaseline($nid)) {
      return TRUE;
    }
    return FALSE;
  }

  return FALSE;
}


function ict_project_access_update($op, $project_id, $account = NULL, $nid = NULL) {
  if (!$account) {
    global $user;
    $account = $user;
  }
  if ($account->uid == 1) {
//  FOR DEVELOPMENT PURPOSES ONLY!!!
//    return TRUE;
  }

  if ($op == 'view' && $nid) {
    $state = ict_project_get_workflow_state($nid);
    if (in_array($state, array('draft', 'waiting_approval'))) {
      if (in_array($account->uid, ict_project_get_users($nid, ICT_PROJECT_EDITOR_ACCESS))
        || in_array($account->uid, ict_project_get_users($nid, ICT_PROJECT_APPROVER_ACCESS))) {
        return TRUE;
      }
    }
    if (in_array($state, array('approved'))) {
      return TRUE;
    }
    if (user_has_role(ICT_DEPARTMENT_ADMIN_ROLE, $account)) {
      return TRUE;
    }
    return FALSE;
  }

  if ($op == 'create' && $project_id) {
    if (ict_project_get_project_rebaseline($project_id)) {
      return FALSE;
    }
    $approved_vid = ict_project_get_last_transaction_by_state($project_id, 'approved');
    if ($approved_vid->vid &&
      in_array($account->uid, ict_project_get_users($project_id, ICT_PROJECT_EDITOR_ACCESS))) {
      return TRUE;
    }
    return FALSE;
  }

  if ($op == 'edit' && $nid && $project_id) {
    if (ict_project_get_project_rebaseline($project_id)) {
      return FALSE;
    }
    if (in_array(ict_project_get_workflow_state($nid), array('draft')) &&
      in_array($account->uid, ict_project_get_users($project_id, ICT_PROJECT_EDITOR_ACCESS))) {
      return TRUE;
    }
    return FALSE;
  }

  if ($op == 'approve' && $nid && $project_id) {
    if (ict_project_get_project_rebaseline($project_id)) {
      return FALSE;
    }
    if (in_array(ict_project_get_workflow_state($nid), array('waiting_approval')) &&
      in_array($account->uid, ict_project_get_users($project_id, ICT_PROJECT_APPROVER_ACCESS))) {
      return TRUE;
    }
    return FALSE;
  }

  if ($op == 'delete' && $nid) {
    if (ict_project_get_project_rebaseline($project_id)) {
      return FALSE;
    }
    if (__ict_project_user_is_dep_admin_for_project($nid, $account) &&
      in_array(ict_project_get_workflow_state($nid), array('draft', 'waiting_approval'))) {
      return TRUE;
    }
    return FALSE;
  }

  return FALSE;
}

function ict_project_get_users($nid, $access_type) {
  $query = db_select('project_access', 'pa');
  $query->addField('pa', 'uid');
  $query->condition('nid', $nid);
  $query->condition('access_type', $access_type);
  $or = db_or();
  $or->condition('expires', 0);
  $or->condition('expires', REQUEST_TIME, '<');
  $query->condition($or);
  $res = $query->execute()->fetchAllAssoc('uid');

  return array_keys($res);
}

/**
 * Adds editor to project
 *
 * @param $email
 * @param $nid
 */
function ict_project_access_add_editor($email, $nid) {
  $user = user_load_by_mail($email);

  $query = db_insert('project_access')
    ->fields(array(
      'uid' => $user->uid,
      'nid' => $nid,
      'access_type' => ICT_PROJECT_EDITOR_ACCESS,
      'created' => time()
    ))
    ->execute();

  $node_wrapper = entity_metadata_wrapper('node', $nid);
  drupal_mail('ict_mail', 'editor_add', $email, LANGUAGE_NONE, array(
    'title' => $node_wrapper->title->value(),
    'name' => _ict_project_get_user_name($user),
    'admin_name' => _ict_project_get_user_name(),
  ));

  return $query;
}

function _ict_project_get_user_name($acc = NULL) {
  if (is_null($acc)) {
    global $user;
    $acc = user_load($user->uid);
  }

  $name_p = array();
  if (!empty($acc->field_first_name['und'][0]['value'])) {
    $name_p[] = $acc->field_first_name['und'][0]['value'];
  }
  if (!empty($acc->field_last_name['und'][0]['value'])) {
    $name_p[] = $acc->field_last_name['und'][0]['value'];
  }
  $name = implode(' ', $name_p);

  return !empty($name) ? $name : $acc->name;
}

/**
 * Removes editor from project
 *
 * @param $email
 * @param $nid
 */
function ict_project_access_remove_editor($email, $nid) {
  $user = user_load_by_mail($email);

  $query = db_delete('project_access')
    ->condition('uid', $user->uid)
    ->condition('nid', $nid)
    ->condition('access_type', ICT_PROJECT_EDITOR_ACCESS)
    ->execute();

  $node_wrapper = entity_metadata_wrapper('node', $nid);
  drupal_mail('ict_mail', 'editor_remove', $email, LANGUAGE_NONE, array(
    'title' => $node_wrapper->title->value(),
    'name' => _ict_project_get_user_name($user),
    'admin_name' => _ict_project_get_user_name(),
  ));

  return $query;
}

function ict_project_allowed_view_states($project_id, $account = NULL) {
  $states = array(
    'approved',
  );

  if (!$account) {
    global $user;
    $account = $user;
  }
  if ($account->uid == 1) {
    //  FOR DEVELOPMENT PURPOSES ONLY!!!
//    return TRUE;
  }

  if (in_array($account->uid, ict_project_get_users($project_id, ICT_PROJECT_EDITOR_ACCESS))) {
    $states = array(
      'draft',
      'waiting_approval',
      'approved',
    );
  }
  if (in_array($account->uid, ict_project_get_users($project_id, ICT_PROJECT_APPROVER_ACCESS))) {
    $states = array(
      'draft',
      'waiting_approval',
      'approved',
    );
  }
  if (user_has_role(ICT_DEPARTMENT_ADMIN_ROLE, $account)) {
    $states = array(
      'draft',
      'waiting_approval',
      'approved',
    );
  }

  return $states;
}

/**
 * Checks if user is Departmental Admin for the project
 *
 * @param $node
 * @param $account
 * @return bool
 */
function __ict_project_user_is_dep_admin_for_project($node, $account) {
  // user should have Departmental Admin role
  if (!user_has_role(ICT_DEPARTMENT_ADMIN_ROLE, $account)) {
    return FALSE;
  }

  return __ict_project_user_is_dep_member_for_project($node, $account);
}

/**
 * Checks if user is Department member for the project
 *
 * @param $node
 * @param $account
 * @return bool
 */
function __ict_project_user_is_dep_member_for_project($node, $account) {
  $node = !empty($node->nid) ? $node : node_load($node);
  $project_department = ict_department_get_department_tid_of_entity('project', $node);
  $user_department = ict_department_get_department_tid_of_entity('user', $account);
  if ($user_department == $project_department) {
    return TRUE;
  }
  return FALSE;
}
