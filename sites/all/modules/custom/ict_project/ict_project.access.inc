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

  return $query;
}

function ict_project_access_project($op, $account = NULL, $nid = NULL) {
  if (!$account) {
    global $user;
    $account = $user;
  }
  if ($account->uid == 1) {
    return TRUE;
  }

  if ($op == 'view' && $nid) {
    $state = ict_project_get_workflow_state($nid);
    if (in_array($state, array('predraft', 'draft', 'waiting_approval'))) {
      if (TRUE) {
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

  if ($op == 'create') {
    if (user_has_role(ICT_DEPARTMENT_ADMIN_ROLE, $account)) {
      return TRUE;
    }
    return FALSE;
  }

  if ($op == 'edit' && $nid) {
    if (in_array(ict_project_get_workflow_state($nid), array('predraft', 'draft')) && in_array($account->uid, ict_project_get_users($nid, ICT_PROJECT_EDITOR_ACCESS))) {
      return TRUE;
    }
    return FALSE;
  }

  if ($op == 'approve' && $nid) {
    dvm(in_array($account->uid, ict_project_get_users($nid, ICT_PROJECT_APPROVER_ACCESS)));
    if (in_array(ict_project_get_workflow_state($nid), array('waiting_approval')) && in_array($account->uid, ict_project_get_users($nid, ICT_PROJECT_APPROVER_ACCESS))) {
      return TRUE;
    }
    return FALSE;
  }

  if ($op == 'delete' && $nid) {
    if (user_has_role(ICT_DEPARTMENT_ADMIN_ROLE, $account) &&
      ict_project_check_if_baseline_ever_approved($nid)) {
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
    return TRUE;
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
    $state = ict_project_get_workflow_state($project_id);
    $approved_vid = ict_project_get_last_transaction_by_state($project_id, 'approved');
    if ($approved_vid->vid && in_array($account->uid, ict_project_get_users($project_id, ICT_PROJECT_EDITOR_ACCESS))) {
      return TRUE;
    }
    return FALSE;
  }

  if ($op == 'edit' && $nid && $project_id) {
    if (in_array(ict_project_get_workflow_state($nid), array('draft')) && in_array($account->uid, ict_project_get_users($project_id, ICT_PROJECT_EDITOR_ACCESS))) {
      return TRUE;
    }
    return FALSE;
  }

  if ($op == 'approve' && $nid && $project_id) {
    if (in_array(ict_project_get_workflow_state($nid), array('waiting_approval')) && in_array($account->uid, ict_project_get_users($project_id, ICT_PROJECT_APPROVER_ACCESS))) {
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

  return $query;
}
