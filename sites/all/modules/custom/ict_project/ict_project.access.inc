<?php
/**
 * @file
 * Code for the ICT Project edit functions.
 */

define ('ICT_PROJECT_APPROVER_ACCESS', 'approve');
define ('ICT_PROJECT_EDITOR_ACCESS', 'edit');

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
