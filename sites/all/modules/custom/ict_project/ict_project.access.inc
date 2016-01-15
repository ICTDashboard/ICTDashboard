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