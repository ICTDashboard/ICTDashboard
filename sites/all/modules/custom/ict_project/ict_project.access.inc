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
//  FOR DEVELOPMENT PURPOSES ONLY!!!
//    return TRUE;
  }

  if ($op == 'view' && $nid) {
    $state = ict_project_get_workflow_state($nid);
    if (in_array($state, array('predraft', 'draft', 'waiting_approval'))) {
      $node = node_load($nid);
      $project_department = ict_department_get_department_tid_of_entity('project', $node);
      $user_department = ict_department_get_department_tid_of_entity('user', $account);
      if ($user_department == $project_department) {
        return TRUE;
      }
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
    if (in_array(ict_project_get_workflow_state($nid), array('predraft', 'draft')) && in_array($account->uid, ict_project_get_users($nid, ICT_PROJECT_EDITOR_ACCESS))) {
      return TRUE;
    }
    return FALSE;
  }

  if ($op == 'approve' && $nid) {
    if (in_array(ict_project_get_workflow_state($nid), array('waiting_approval')) && in_array($account->uid, ict_project_get_users($nid, ICT_PROJECT_APPROVER_ACCESS))) {
      return TRUE;
    }
    return FALSE;
  }

  if ($op == 'delete' && $nid) {
    if (user_has_role(ICT_DEPARTMENT_ADMIN_ROLE, $account) &&
      ict_project_check_if_baseline_ever_approved($nid)) {
      $node = node_load($nid);
      $project_department = ict_department_get_department_tid_of_entity('project', $node);
      $user_department = ict_department_get_department_tid_of_entity('user', $account);
      if ($user_department == $project_department) {
        return TRUE;
      }
      return FALSE;
    }
    return FALSE;
  }

  return FALSE;
}

function ict_project_access_rebaseline($op, $project_id, $account = NULL) {
  if (!$account) {
    global $user;
    $account = $user;
  }

  if ($account->uid == 1) {
//  FOR DEVELOPMENT PURPOSES ONLY!!!
//    return TRUE;
  }

  if ($op == 'view' && $project_id) {
    $state = ict_project_get_workflow_state($project_id);
    if (in_array($state, array('draft', 'waiting_approval'))) {
      $node = node_load($project_id);
      $project_department = ict_department_get_department_tid_of_entity('project', $node);
      $user_department = ict_department_get_department_tid_of_entity('user', $account);
      if ($user_department == $project_department) {
        return TRUE;
      }
    }
    if (in_array($state, array('approved'))) {
      return TRUE;
    }
    return FALSE;
  }

  if ($op == 'create' && $project_id) {
    $state = ict_project_get_workflow_state($project_id);
    $updates = ict_update_project_get_list($project_id);
    if (!in_array($account->uid, ict_project_get_users($project_id, ICT_PROJECT_EDITOR_ACCESS))) {
      return FALSE;
    }
    if (!in_array($state, array('approved'))) {
      return FALSE;
    }
    if (empty($updates)) {
      return TRUE;
    }
    else {
      $update = reset($updates);
      $update_state = $state = ict_project_get_workflow_state($update);
      if (in_array($update_state, array('approved'))) {
        return TRUE;
      }
    }

    return FALSE;
  }

  if ($op == 'edit' && $project_id) {
    if (in_array(ict_project_get_workflow_state($project_id), array('draft')) && in_array($account->uid, ict_project_get_users($project_id, ICT_PROJECT_EDITOR_ACCESS))) {
      return TRUE;
    }
    return FALSE;
  }

  if ($op == 'approve' && $project_id) {
    if (in_array(ict_project_get_workflow_state($project_id), array('waiting_approval')) && in_array($account->uid, ict_project_get_users($project_id, ICT_PROJECT_APPROVER_ACCESS))) {
      return TRUE;
    }
    return FALSE;
  }

//  if ($op == 'delete' && $project_id) {
//    if (user_has_role(ICT_DEPARTMENT_ADMIN_ROLE, $account) &&
//      ict_project_check_if_baseline_ever_approved($project_id)) {
//      $node = node_load($project_id);
//      $project_department = ict_department_get_department_tid_of_entity('project', $node);
//      $user_department = ict_department_get_department_tid_of_entity('user', $account);
//      if ($user_department == $project_department) {
//        return TRUE;
//      }
//      return FALSE;
//    }
//    return FALSE;
//  }

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
      'predraft',
      'draft',
      'waiting_approval',
      'approved',
    );
  }
  if (in_array($account->uid, ict_project_get_users($project_id, ICT_PROJECT_APPROVER_ACCESS))) {
    $states = array(
      'predraft',
      'draft',
      'waiting_approval',
      'approved',
    );
  }
  if (user_has_role(ICT_DEPARTMENT_ADMIN_ROLE, $account)) {
    $states = array(
      'predraft',
      'draft',
      'waiting_approval',
      'approved',
    );
  }

  return $states;
}
