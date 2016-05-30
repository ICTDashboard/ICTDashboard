<?php
/**
 * @file
 * Code for the ICT Project create functions.
 */

function ict_project_manage_project_users_form ($form, &$form_state, $project) {
  $department_tid = ict_department_get_department_tid_of_entity('project', $project);
  $department = taxonomy_term_load($department_tid);
  $project_admins = ict_project_baseline_get_admin_user_emails($project);

  $form['nid'] = array(
    '#type' => 'value',
    '#value' => $project->nid,
  );

  $fields = array('title', 'field_department');
  foreach($fields as $field) {
    $field_info = field_info_instance('node', $field, 'project');
    if (!empty($field_info['description'])) {
      $form[$field . '_description'] = array(
        '#type' => 'markup',
        '#markup' => $field_info['description']
      );
    }
  }

  $default_admins = array();
  if (empty($form_state['triggering_element'])) {
    foreach ($project_admins['data_approvers'] as $approver_email) {
      $default_admins['approvers'][] = $approver_email;
    }
    foreach ($project_admins['data_editors'] as $editor_email) {
      $default_admins['editors'][] = $editor_email;
    }

    $form_state['storage']['approvers'] = count($default_admins['approvers']);
    $form_state['storage']['editors'] = count($default_admins['editors']);
  }

  $form['title'] = array(
    '#type' => 'markup',
    '#markup' => $project->title
  );

  $form['department'] = array(
    '#type' => 'markup',
    '#markup' => $department->name
  );

  $form['field_department'] = array(
    '#type' => 'hidden',
    '#value' => array($department_tid)
  );

  // project users
  __ict_project_manage_users($form, $form_state, $department_tid, $default_admins);

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Update Users'),
    '#submit' => array('ict_project_update_project_admin_users'),
    '#validate' => array('ict_project_manage_users_emails_validate'),
    '#attributes' => array('class' => array('submit-button'))
  );

  $form['#theme'] = 'ict_project_manage_project_users_form';

  return $form;
}


function __ict_project_manage_users(&$form, &$form_state, $department_tid, $default_admins = array()) {
  $sql = db_select('users', 'u');
  $sql->fields('u',array('uid','name','mail'));
  $sql->fields('d',array('field_department_tid'));
  $sql->innerJoin('field_data_field_department', 'd', 'd.entity_id = u.uid');
  $sql->condition('d.field_department_tid', $department_tid);
  $res =$sql->execute()->fetchAll();
  $data_approvers_emails = array();
  foreach ($res as $key => $value) {
    $data_approvers_emails[$value->mail] = $value->mail;
  }

  if (isset($form_state['triggering_element']['#attributes']['data-delete']) &&
    $form_state['triggering_element']['#attributes']['data-delete'] == 'approver') {
    $input_approvers = &$form_state['input']['emails']['approvers'];
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
    '#theme' => 'ict_project_create_emails',
    '#prefix' => '<div id="ict-project-create-emails">',
    '#suffix' => '</div>'
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

      if ($default_admins) {
        $form['emails']['approvers']['email_item_' . $i]['email']['#default_value'] = $default_admins['approvers'][$i - 1];
      }

      $form['emails']['approvers']['email_item_' . $i]['remove_btn'] = array(
        '#type' => 'button',
        '#value' => t('Remove'),
        '#href' => '',
        '#name' => 'remove_approver_' . $i,
        '#limit_validation_errors' => array(),
        '#ajax' => array(
          'callback' => 'ict_project_create_project_remove_approver',
          'wrapper' => 'ict-project-create-emails',
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
      'wrapper' => 'ict-project-create-emails',
    ),
    '#attributes' => array('class' => array('add-button', 'field-add-more-submit', 'export-btn'))
  );

  if (isset($form_state['triggering_element']['#attributes']['data-delete']) &&
    $form_state['triggering_element']['#attributes']['data-delete'] == 'editor') {
    $input_editors = &$form_state['input']['emails']['editors'];
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

      if ($default_admins) {
        $form['emails']['editors']['email_item_' . $i]['email']['#default_value'] = $default_admins['editors'][$i - 1];
      }

      $form['emails']['editors']['email_item_' . $i]['remove_btn'] = array(
        '#type' => 'button',
        '#value' => t('Remove'),
        '#button_type' => 'button',
        '#name' => 'remove_editor_' . $i,
        '#limit_validation_errors' => array(),
        '#ajax' => array(
          'callback' => 'ict_project_create_project_remove_editor',
          'wrapper' => 'ict-project-create-emails',
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
      'wrapper' => 'ict-project-create-emails',
    ),
    '#attributes' => array('class' => array('add-button', 'field-add-more-submit', 'export-btn'))
  );

  $form['#attached']['js'] = array(
    drupal_get_path('theme', 'itdash') . '/js/combobox.js',
    drupal_get_path('module', 'ict_project') . '/js/ict_project.js',
  );

  $form['#attached']['css'] = array(
    drupal_get_path('theme', 'itdash') . '/css/combobox.css',
  );
}

/**
 * Validate project data before creation
 *
 * @param $form
 * @param $form_state
 * @throws \Exception
 */
function ict_project_manage_users_emails_validate($form, &$form_state) {
  global $user;
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

  foreach ($values['emails']['approvers'] as $key => $approver) {
    if ($key == 'add_approver' || !$approver['email']) continue;
    $approver_emails[] = $approver['email'];
  }
  $unique_approvers = array_unique($approver_emails);
  if (count($unique_approvers) < count($approver_emails)) {
    form_set_error('editors', t('It is not allowed to have the same user assigned to Project Approver role multiple times.'));
  }

  foreach ($values['emails']['editors'] as $key => $editor) {
    if ($key == 'add_editor' || !$editor['email']) continue;
    $editor_emails[] = $editor['email'];
  }
  $unique_editors = array_unique($editor_emails);
  if (count($unique_editors) < count($editor_emails)) {
    form_set_error('editors', t('It is not allowed to have the same user assigned to Project Editor role multiple times.'));
  }

//  if (!$approver_emails) {
//    form_set_error('approvers', t('At least one Project Approver email is required.'));
//  }
//
//  if (!$editor_emails) {
//    form_set_error('editors', t('At least one Project Editor email is required.'));
//  }
  foreach ($approver_emails as $email) {
    if (valid_email_address($email) &&
      endsWith($email, '.gov.au')) continue;
    form_set_error('editors', t('Project Approver email address should be valid and belonging to Australian government.'));
  }

  // Departmental admin cannot be an approver
  foreach ($approver_emails as $email) {
    $role_user = user_load_by_mail($email);
    if (!$role_user || !array_key_exists(ICT_DEPARTMENT_ADMIN_ROLE, $role_user->roles)) {
      continue;
    }

    form_set_error('editors', t('A user cannot be Departmental Administrator and Project Approver within the same project.'));
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
    if ((!$department_tid || $department_tid != $current_department) && (!array_key_exists(ICT_FINANCE_ADMIN_ROLE, $user->roles))) {
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


function ict_project_update_project_admin_users($form, &$form_state) {
  $nid = $form['nid']['#value'];
  $node = node_load($nid);

  $project_admins = ict_project_baseline_get_admin_user_emails($node);
  $project_approvers = $project_admins['data_approvers'];
  $project_editors = $project_admins['data_editors'];

  $approvers = $form_state['approvers'];
  $approvers_added = array_diff($approvers, $project_approvers);
  foreach ($approvers_added as $approver) {
    ict_project_access_add_approver($approver, $nid);
  }
  $approvers_removed = array_diff($project_approvers, $approvers);
  foreach ($approvers_removed as $approver) {
    ict_project_access_remove_approver($approver, $nid);
  }

  $editors = $form_state['editors'];
  $editors_added = array_diff($editors, $project_editors);
  foreach ($editors_added as $editor) {
    ict_project_access_add_editor($editor, $nid);
  }
  $editors_removed = array_diff($project_editors, $editors);
  foreach ($editors_removed as $editor) {
    ict_project_access_remove_editor($editor, $nid);
  }

  drupal_set_message(t('Updates have been applied.'));
  $form_state['redirect'] = 'projects';
}

function ict_project_update_email_options($form, &$form_state) {
  return $form['emails'];
}

/**
 * Add approver callback
 *
 * @param $form
 * @param $form_state
 * @return mixed
 */
function ict_project_create_project_add_approver($form, &$form_state) {
  return $form['emails'];
}

/**
 * Add editor callback
 *
 * @param $form
 * @param $form_state
 * @return mixed
 */
function ict_project_create_project_add_editor($form, &$form_state) {
  return $form['emails'];
}

/**
 * Remove approver callback
 *
 * @param $form
 * @param $form_state
 * @return mixed
 */
function ict_project_create_project_remove_approver($form, &$form_state) {
  return $form['emails'];
}

/**
 * Remove editor callback
 *
 * @param $form
 * @param $form_state
 * @return mixed
 */
function ict_project_create_project_remove_editor($form, &$form_state) {
  return $form['emails'];
}
