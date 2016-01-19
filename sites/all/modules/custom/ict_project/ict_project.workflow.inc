<?php

/**
 * Set workflow state. If revision is NULL set for the latest revision
 */
function ict_project_set_workflow_state($state, $nid, $vid = NULL) {
  global $user;

  if (!$vid) {
    $node = node_load($nid);
    $revisions = node_revision_list($node);
    $last = reset($revisions);
    $vid = !empty($last->vid) ? $last->vid : NULL;
  }

  if (!$nid || !$vid || !$state) {
    return FALSE;
  }
  $current_state = ict_project_get_workflow_state($nid);
  if ($state == $current_state) {
    return FALSE;
  }
  $query = db_insert('project_workflow');
  $query->fields(array(
    'nid' => $nid,
    'vid' => $vid,
    'old_state' => $current_state,
    'state' => $state,
    'created' => REQUEST_TIME,
    'uid' => $user->uid,
  ));
  return $query->execute();
}

/**
 * Get workflow state. If revision is NULL set for the latest revision
 */
function ict_project_get_workflow_state($nid, $vid = NULL) {
  if (!$nid) {
    return FALSE;
  }
  $query = db_select('project_workflow', 'w');
  $query->addField('w', 'state');
  $query->condition('nid', $nid);
  if ($vid) {
    $query->condition('vid', $vid);
  }
  $query->orderBy('created', 'DESC');
  $res = $query->execute()->fetchCol();

  return reset($res);
}

/**
 * Get workflow state. If revision is NULL set for the latest revision
 */
function ict_project_get_last_transaction_by_state($nid, $state) {
  if (!$nid) {
    return FALSE;
  }
  $query = db_select('project_workflow', 'w');
  $query->fields('w');
  $query->condition('nid', $nid);
  $query->condition('state', $state);
  $query->orderBy('created', 'DESC');
  $res = $query->execute()->fetchAll();

  return reset($res);
}
