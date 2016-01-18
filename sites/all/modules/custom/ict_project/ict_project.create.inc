<?php
/**
 * @file
 * Code for the ICT Project create functions.
 */

/**
 * Project create form
 *
 * @param $form
 * @param $form_state
 * @return mixed
 */
function ict_project_projects_create_form($form, &$form_state) {
  global $user;
  $government_entities_vocab = taxonomy_vocabulary_machine_name_load('funding_source');
  $government_entities = taxonomy_get_tree($government_entities_vocab->vid);
  $entities_options = array();
  foreach ($government_entities as $entity) {
    $entities_options[$entity->tid] = $entity->name;
  }

  $form['field_government_entity_name'] = array(
    '#type' => 'select',
    '#title' => t('Government Entity Name'),
    '#title_display' => 'invisible',
    '#required' => TRUE,
    '#options' => $entities_options
  );

  $portfolio_vocab = taxonomy_vocabulary_machine_name_load('portfolio');
  $portfolios = taxonomy_get_tree($portfolio_vocab->vid);
  $portfolio_options = array();
  foreach ($portfolios as $entity) {
    $portfolio_options[$entity->tid] = $entity->name;
  }

  $form['field_portfolio_name'] = array(
    '#type' => 'select',
    '#required' => TRUE,
    '#title' => t('Portfolio Name'),
    '#title_display' => 'invisible',
    '#options' => $portfolio_options
  );

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
    '#options' => $departments_options
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
    $form_state['storage']['approvers'] = $form_state['storage']['approvers'];
  }
  else {
    $form_state['storage']['approvers'] = 1;
  }

  $form['approvers'] = array(
    '#type' => 'container',
    '#tree' => TRUE,
    '#prefix' => '<div id="approvers">',
    '#suffix' => '</div>',
  );

  if ($form_state['storage']['approvers']) {
    for ($i = 1; $i <= $form_state['storage']['approvers']; $i++) {
      $form['approvers']['email_item_' . $i] = array(
        '#type' => 'container',
        '#tree' => TRUE,
        '#attributes' => array('class' => array('email-container'))
      );

      $form['approvers']['email_item_' . $i]['email'] = array(
        '#type' => 'textfield',
        '#required' => $i == 1,
        '#title' => t('Data Approvers'),
        '#attributes' => array(
          'placeholder' => t('Please enter email address'),
          'class' => array('approver-email')
        ),
        '#title_display' => 'invisible',
      );

      $form['approvers']['email_item_' . $i]['remove_btn'] = array(
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

  $form['approvers']['add_approver'] = array(
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
    $form_state['storage']['editors'] = $form_state['storage']['editors'];
  }
  else {
    $form_state['storage']['editors'] = 1;
  }

  $form['editors'] = array(
    '#type' => 'container',
    '#tree' => TRUE,
    '#prefix' => '<div id="editors">',
    '#suffix' => '</div>',
  );

  if ($form_state['storage']['editors']) {
    for ($i = 1; $i <= $form_state['storage']['editors']; $i++) {
      $form['editors']['email_item_' . $i] = array(
        '#type' => 'container',
        '#tree' => TRUE,
        '#attributes' => array('class' => array('email-container'))
      );

      $form['editors']['email_item_' . $i]['email'] = array(
        '#type' => 'textfield',
        '#required' => $i == 1,
        '#title' => t('Data Editor'),
        '#attributes' => array(
          'placeholder' => t('Please enter email address'),
          'class' => array('editor-email')
        ),
        '#title_display' => 'invisible',
      );

      $form['editors']['email_item_' . $i]['remove_btn'] = array(
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

  $form['editors']['add_editor'] = array(
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
  dsm($values);
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
  dsm($editor_emails);
  dsm($approver_emails);

  foreach ($approver_emails as $email) {
    if (valid_email_address($email) &&
      endsWith($email, '.gov.au')) continue;
    form_set_error('editors', t('Data Approver email address should be valid and belonging to Australian government.'));
  }

  foreach ($editor_emails as $email) {
    if (valid_email_address($email) &&
      endsWith($email, '.gov.au')) continue;
    form_set_error('editors', t('Data Editor address should be valid and belonging to Australian government.'));
  }

  $form_state['approvers'] = $approver_emails;
  $form_state['editors'] = $editor_emails;

  foreach ($approver_emails + $editor_emails as $email) {
    if (user_load_by_mail($email)) continue;
    form_set_error('editors',
      t('User with the email !email is not found', array(
        '!email' => $email
      ))
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
  $node->status = 0;

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

