<?php

/**
 * Set workflow state. If revision is NULL set for the latest revision
 */
function ict_project_set_workflow_state($state, $nid, $vid = NULL) {
  if (!$vid) {
    $node = node_load($nid);
    $revisions = node_revision_list($node);
    $last = reset($revisions);
    $vid = !empty($last->vid) ? $last->vid : NULL;
  }
  if (!$nid || !$vid || !$state) {
    return FALSE;
  }
  $query = db_insert('project_workflow');
  $query->fields(array(
    'nid' => $nid,
    'vid' => $vid,
    'state' => $state,
    'created' => REQUEST_TIME,
  ));
  return $query->execute();
}

/**
 * Get workflow state. If revision is NULL set for the latest revision
 */
function ict_project_get_workflow_state($nid, $vid = NULL) {
  if (!$vid) {
    $node = node_load($nid);
    $revisions = node_revision_list($node);
    $last = reset($revisions);
    $vid = !empty($last->vid) ? $last->vid : NULL;
  }
  if (!$nid || !$vid) {
    return FALSE;
  }
  $query = db_select('project_workflow', 'w');
  $query->addField('w', 'state');
  $query->orderBy('created', 'DESC');
  $res = $query->execute()->fetchCol();

  return reset($res);
}
