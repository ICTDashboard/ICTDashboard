<?php
/**
 * @file
 * Code for the ICT Project create functions.
 */


function ict_project_update_gov_entity_name($form, &$form_state) {
  return $form['field_government_entity_name'];
}

function ict_project_update_email_options($form, &$form_state) {
  return $form['emails'];
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

  $form['#attached']['js'] = array(
      drupal_get_path('theme', 'itdash') . '/js/combobox.js',
      drupal_get_path('module', 'ict_project') . '/js/ict_project.js',
  );

  $form['#attached']['css'] = array(
      drupal_get_path('theme', 'itdash') . '/css/combobox.css',
  );

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
  $sql = db_select('users', 'u');
  $sql->fields('u',array('uid','name','mail'));
  $sql->fields('d',array('field_department_tid'));
  $sql->innerJoin('field_data_field_department', 'd', 'd.entity_id = u.uid');
  $sql->condition('d.field_department_tid', $department_tid);
  $res =$sql->execute()->fetchAll();
  $data_approvers_emails = [];
    foreach ($res as $key => $value) {
    $data_approvers_emails[$value->mail] = $value->mail;
  }

  if (isset($form_state['triggering_element']['#attributes']['data-delete']) &&
    $form_state['triggering_element']['#attributes']['data-delete'] == 'approver') {
    $input_approvers = &$form_state['input']['approvers'];
    $index = $form_state['triggering_element']['#attributes']['data-index'];
    unset($input_approvers['email_item_' . $index]);
    $form_state['storage']['approvers']--;

    // collect values
    $values = array();
    foreach ($input_approvers as $editor) {
      $values[] = $editor['email'];
    }
    // update input
    $input_approvers = array();
    foreach ($values as $key => $value) {
      $value_index = $key + 1;
      $input_approvers['email_item_' . $value_index] = array(
        'email' => $value
      );
    }
  }

  // update approvers counter
  if (isset($form_state['storage']['approvers']) &&
    $form_state['triggering_element']['#value'] == 'Add Approver') {
    $form_state['storage']['approvers'] +=1;
  }
  elseif (isset($form_state['storage']['approvers'])) {
    $form_state['storage']['approvers'] = $form_state['storage']['approvers'] ?
      $form_state['storage']['approvers'] :
      1;
  }
  else {
    $form_state['storage']['approvers'] = 1;
  }

  $form['emails'] = array(
    '#type' => 'container',
    '#tree' => TRUE,
    '#theme' => 'ict_project_create_emails'
  );

  $form['emails']['approvers'] = array(
    '#type' => 'container',
    '#tree' => TRUE,
    '#prefix' => '<div id="approvers">',
    '#suffix' => '</div>',
  );

  if ($form_state['storage']['approvers']) {
    for ($i = 1; $i <= $form_state['storage']['approvers']; $i++) {
      $form['emails']['approvers']['email_item_' . $i] = array(
        '#type' => 'container',
        '#tree' => TRUE,
        '#attributes' => array('class' => array('email-container'))
      );

      $form['emails']['approvers']['email_item_' . $i]['email'] = array(
          '#type' => 'select',
          '#required' => TRUE,
          '#title' => t('Project Approvers'),
          '#attributes' => array(
              'placeholder' => t('Please enter email address'),
              'class' => array('ict-combobox')
          ),
          '#title_display' => 'invisible',
          '#options' => $data_approvers_emails
      );

      $form['emails']['approvers']['email_item_' . $i]['remove_btn'] = array(
        '#type' => 'button',
        '#value' => t('Remove'),
        '#href' => '',
        '#name' => 'remove_approver_' . $i,
        '#limit_validation_errors' => array(),
        '#ajax' => array(
          'callback' => 'ict_project_create_project_remove_approver',
          'wrapper' => 'approvers',
        ),
        '#attributes' => array(
          'class' => array('delete-btn'),
          'data-delete' => 'approver',
          'data-index' => $i
        ),
      );

    }
  }

  $form['emails']['approvers']['add_approver'] = array(
    '#type' => 'button',
    '#value' => t('Add Approver'),
    '#href' => '',
    '#limit_validation_errors' => array(),
    '#ajax' => array(
      'callback' => 'ict_project_create_project_add_approver',
      'wrapper' => 'approvers',
    ),
    '#attributes' => array('class' => array('add-button', 'field-add-more-submit'))
  );

  if (isset($form_state['triggering_element']['#attributes']['data-delete']) &&
    $form_state['triggering_element']['#attributes']['data-delete'] == 'editor') {
    $input_editors = &$form_state['input']['editors'];
    $index = $form_state['triggering_element']['#attributes']['data-index'];
    unset($input_editors['email_item_' . $index]);
    $form_state['storage']['editors']--;

    // collect values
    $values = array();
    foreach ($input_editors as $editor) {
      $values[] = $editor['email'];
    }
    // update input
    $input_editors = array();
    foreach ($values as $key => $value) {
      $value_index = $key + 1;
      $input_editors['email_item_' . $value_index] = array(
        'email' => $value
      );
    }
  }

  // update editors counter
  if (!empty($form_state['storage']['editors']) &&
    $form_state['triggering_element']['#value'] == 'Add Editor') {
    $form_state['storage']['editors']++;
  }
  elseif (!empty($form_state['storage']['editors'])) {
    $form_state['storage']['editors'] = $form_state['storage']['editors'] ?
      $form_state['storage']['editors'] :
      1;
  }
  else {
    $form_state['storage']['editors'] = 1;
  }

  $form['emails']['editors'] = array(
    '#type' => 'container',
    '#tree' => TRUE,
    '#prefix' => '<div id="editors">',
    '#suffix' => '</div>',
  );

  if ($form_state['storage']['editors']) {
    for ($i = 1; $i <= $form_state['storage']['editors']; $i++) {
      $form['emails']['editors']['email_item_' . $i] = array(
        '#type' => 'container',
        '#tree' => TRUE,
        '#attributes' => array('class' => array('email-container'))
      );

      $form['emails']['editors']['email_item_' . $i]['email'] = array(
          '#type' => 'select',
          '#required' => TRUE,
          '#title' => t('Project Editor'),
          '#attributes' => array(
              'placeholder' => t('Please enter email address'),
              'class' => array('ict-combobox')
          ),
          '#title_display' => 'invisible',
          '#options' => $data_approvers_emails
      );

      $form['emails']['editors']['email_item_' . $i]['remove_btn'] = array(
        '#type' => 'button',
        '#value' => t('Remove'),
        '#button_type' => 'button',
        '#name' => 'remove_editor_' . $i,
        '#limit_validation_errors' => array(),
        '#ajax' => array(
          'callback' => 'ict_project_create_project_remove_editor',
          'wrapper' => 'editors',
        ),
        '#attributes' => array(
          'class' => array('delete-btn'),
          'data-delete' => 'editor',
          'data-index' => $i
        ),
      );
    }
  }

  $form['emails']['editors']['add_editor'] = array(
    '#type' => 'button',
    '#value' => t('Add Editor'),
    '#href' => '',
    '#limit_validation_errors' => array(),
    '#ajax' => array(
      'callback' => 'ict_project_create_project_add_editor',
      'wrapper' => 'editors',
    ),
    '#attributes' => array('class' => array('add-button', 'field-add-more-submit'))
  );

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
    '#validate' => array('ict_project_create_form_validate')
  );

  $form['#theme'] = 'ict_project_create_form';

  return $form;
}

/**
 * Add approver callback
 *
 * @param $form
 * @param $form_state
 * @return mixed
 */
function ict_project_create_project_add_approver($form, &$form_state) {
  return $form['approvers'];
}

/**
 * Add editor callback
 *
 * @param $form
 * @param $form_state
 * @return mixed
 */
function ict_project_create_project_add_editor($form, &$form_state) {
  return $form['editors'];
}

/**
 * Remove approver callback
 *
 * @param $form
 * @param $form_state
 * @return mixed
 */
function ict_project_create_project_remove_approver($form, &$form_state) {
  return $form['approvers'];
}

/**
 * Remove editor callback
 *
 * @param $form
 * @param $form_state
 * @return mixed
 */
function ict_project_create_project_remove_editor($form, &$form_state) {
  return $form['editors'];
}

/**
 * Validate project data before creation
 *
 * @param $form
 * @param $form_state
 * @throws \Exception
 */
function ict_project_create_form_validate($form, &$form_state) {
  $values = $form_state['values'];
  $approver_emails = array();
  $editor_emails = array();

  function endsWith($haystack, $needle) {
    $length = strlen($needle);
    if ($length == 0) {
      return true;
    }
    return (substr($haystack, -$length) === $needle);
  }

  foreach ($values['approvers'] as $key => $approver) {
    if ($key == 'add_approver' || !$approver['email']) continue;
    $approver_emails[] = $approver['email'];
  }

  foreach ($values['editors'] as $key => $editor) {
    if ($key == 'add_editor' || !$editor['email']) continue;
    $editor_emails[] = $editor['email'];
  }

  if (!$approver_emails) {
    form_set_error('approvers', t('At least one Project Approver email is required.'));
  }

  if (!$editor_emails) {
    form_set_error('editors', t('At least one Project Editor email is required.'));
  }

  foreach ($approver_emails as $email) {
    if (valid_email_address($email) &&
      endsWith($email, '.gov.au')) continue;
    form_set_error('editors', t('Project Approver email address should be valid and belonging to Australian government.'));
  }

  foreach ($editor_emails as $email) {
    if (valid_email_address($email) &&
      endsWith($email, '.gov.au')) continue;
    form_set_error('editors', t('Project Editor address should be valid be associated to Australian government.'));
  }

  $form_state['approvers'] = $approver_emails;
  $form_state['editors'] = $editor_emails;

  $approver_editor_users = array();
  foreach (array_merge($approver_emails, $editor_emails) as $email) {
    if ($role_user = user_load_by_mail($email)) {
      $approver_editor_users[] = $role_user;
      continue;
    }
    form_set_error('editors',
      t('User with the email !email is not found', array(
        '!email' => $email
      ))
    );
  }

  $current_department = $values['field_department'][0];
  $dep_data = taxonomy_term_load($current_department);
  foreach ($approver_editor_users as $role_user) {
    $department_tid = ict_department_get_department_tid_of_entity('user', $role_user);
    if (!$department_tid || $department_tid != $current_department) {
      form_set_error(
        'editors',
        t('Project Editors and Project Approvers should be associated to !dep_name', array(
          '!dep_name' => $dep_data->name
        ))
      );
    }
  }

  if (array_intersect($approver_emails, $editor_emails)) {
    form_set_error(
      'editors',
      t('Project Editor and Project Approver cannot be the same user.')
    );
  }
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

