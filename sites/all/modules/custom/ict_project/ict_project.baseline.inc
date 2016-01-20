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
    drupal_set_message(t('You need to create draft first.'), 'error');
    drupal_goto('projects');
  }

  module_load_include('inc', 'node', 'node.pages');
  $form = drupal_get_form('project_node_form', $node);

  // makes form elements titles
  function make_title_display(&$elem) {
    foreach (element_children($elem) as $element) {
      $elem[$element]['#title_display'] = 'invisible';
      make_title_display($element);
    }
  }

  foreach (element_children($form) as $element) {
    $element_name = explode('_', $element);
    if (reset($element_name) == 'field') {
      $form[$element]['#title_display'] = 'invisible';
      make_title_display($form[$element]);
    }
  }

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
function ict_project_baseline_approve_form($form, $form_state, $nid) {
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
  $form_state['#redirect'] = "projects";
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
  $form_state['#redirect'] = "projects";
}