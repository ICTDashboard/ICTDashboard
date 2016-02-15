<?php
/**
 * @file
 * Code for the ICT Project create functions.
 */


function ict_project_update_gov_entity_name($form, &$form_state) {
  return $form['field_government_entity_name'];
}

/**
 * Project create form
 *
 * @param $form
 * @param $form_state
 * @return mixed
 */
function ict_project_projects_create_form($form, &$form_state) {
  global $user;

  $portfolio_vocab = taxonomy_vocabulary_machine_name_load('portfolio');
  $portfolios = taxonomy_get_tree($portfolio_vocab->vid, 0, 1);
  $portfolio_options = array();
  foreach ($portfolios as $entity) {
    $portfolio_options[$entity->tid] = $entity->name;
  }

  $fields = array('title', 'field_department', 'field_portfolio_name', 'field_government_entity_name');
  foreach($fields as $field) {
    $field_info = field_info_instance('node', $field, 'project');
    if (!empty($field_info['description'])) {
      $form[$field . '_description'] = array(
        '#type' => 'markup',
        '#markup' => $field_info['description']
      );
    }
  }

  $form['field_portfolio_name'] = array(
    '#type' => 'select',
    '#required' => TRUE,
    '#title' => t('Portfolio Name'),
    '#title_display' => 'invisible',
    '#options' => $portfolio_options,
    '#ajax' => array(
      'callback' => 'ict_project_update_gov_entity_name',
      'wrapper' => 'ict-form-government-entity-name',
      'method' => 'replace',
      'effect' => 'fade',
    ),
  );

  $form['field_government_entity_name'] = array(
    '#type' => 'select',
    '#title' => t('Government Entity Name'),
    '#title_display' => 'invisible',
    '#prefix' => '<div id="ict-form-government-entity-name">',
    '#suffix' => '</div>',
    '#required' => TRUE,
    '#options' => array(),
    '#disabled' => TRUE,
  );

  if (!empty($form_state['values']['field_portfolio_name'])) {
    $portfolios = taxonomy_get_tree($portfolio_vocab->vid, $form_state['values']['field_portfolio_name'], 1);
    $portfolio_options = array();
    foreach ($portfolios as $entity) {
      $portfolio_options[$entity->tid] = $entity->name;
    }
    $form['field_government_entity_name']['#options'] = $portfolio_options;
    $form['field_government_entity_name']['#disabled'] = FALSE;
  }

  $department_vocab = taxonomy_vocabulary_machine_name_load('department');
  $departments = taxonomy_get_tree($department_vocab->vid);
  $departments_options = array();
  foreach ($departments as $entity) {
    $departments_options[$entity->tid] = $entity->name;
  }

  $form['field_department'] = array(
    '#type' => 'select',
    '#required' => TRUE,
    '#title' => t('Department'),
    '#title_display' => 'invisible',
    '#options' => $departments_options,
    '#ajax' => array(
      'callback' => 'ict_project_update_email_options',
      'wrapper' => 'ict-project-create-emails',
      'method' => 'replace',
      'effect' => 'fade',
    ),
  );

  // if Departmental Admin the department is selected by default
  if (in_array('Departmental Admin', $user->roles)) {
    $user = user_load($user->uid);
    $form['field_department']['#default_value'] =
    $form['field_department']['#value'] = array(
      $user->field_department[LANGUAGE_NONE][0]['tid']
    );
    $form['field_department']['#disabled'] = TRUE;
  }

  $department_tid = !empty($form_state['input']['field_department']) ?
    $form_state['input']['field_department'] :
    $form['field_department']['#value'];

  // project users
  __ict_project_manage_users($form, $form_state, $department_tid);

  $form['title'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title' => t('Project Title'),
    '#title_display' => 'invisible',
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Create Project'),
    '#submit' => array('ict_project_create_form_submit'),
    '#validate' => array('ict_project_manage_users_emails_validate'),
    '#attributes' => array('class' => array('submit-button'))
  );

  $form['#theme'] = 'ict_project_create_form';

  return $form;
}

/**
 * Create project
 *
 * @param $form
 * @param $form_state
 * @throws \Exception
 */
function ict_project_create_form_submit($form, &$form_state) {
  $values = $form_state['values'];
  $node = new stdClass();
  $node->type = 'project';
  $node->title = $values['title'];
  $node->status = 1;

  $node->language = LANGUAGE_NONE;
  node_object_prepare($node);

  $node->field_government_entity_name[$node->language][0]['tid'] = $values['field_government_entity_name'];
  $node->field_portfolio_name[$node->language][0]['tid'] = $values['field_portfolio_name'];
  $node->field_department[$node->language][0]['tid'] = $values['field_department'];
  node_save($node);

  if (!empty($node->nid)) {
    $approvers = $form_state['approvers'];
    foreach ($approvers as $approver) {
      ict_project_access_add_approver($approver, $node->nid);
    }

    $editors = $form_state['editors'];
    foreach ($editors as $editor) {
      ict_project_access_add_editor($editor, $node->nid);
    }
    drupal_set_message(t('The project has been created.'));
    $form_state['redirect'] = 'projects';
  }
  else {
    drupal_set_message(t('Error occurred. Please contact the administrator or try later.'), 'error');
  }
}

