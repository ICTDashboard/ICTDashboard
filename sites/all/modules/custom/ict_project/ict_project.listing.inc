<?php

/**
 * @file
 * Code for the ICT Project edit functions.
 */

/**
 * Project List
 */
function ict_project_project_list_block() {
  global $user;
  $user = user_load($user->uid);
  $results = array();

  if (user_is_logged_in()) {
    $query = db_select('node', 'n')
      ->fields('n', array('nid', 'title', 'changed'))
      ->condition('n.type', 'project');

    $tid = !empty($user->field_department[LANGUAGE_NONE][0]['tid']) ?
      $user->field_department[LANGUAGE_NONE][0]['tid'] :
      NULL;

    if (!array_intersect($user->roles, array('administrator', 'Finance Admin')) &&
      $tid) {

      $query->join(
        'field_data_field_department',
        'd',
        'd.bundle = n.type AND n.nid = d.entity_id'
      );

      $query->condition(
        'd.field_department_tid',
        $user->field_department[LANGUAGE_NONE][0]['tid']
      );

    }

    $results = $query
      ->orderBy('n.title', 'ASC')
      ->execute()
      ->fetchAll();
  }
  //############################################################################
  // temporary work around for demo
  // SHOULD BE REMOVED LATER
  $nid = !empty($_GET['nid']) ? $_GET['nid'] : NULL;
  $all_fields_on_my_website = field_info_fields();
  $buttons = list_allowed_values($all_fields_on_my_website['field_demo_buttons']);
  foreach ($results as &$result) {
    $result->entity = node_load($result->nid);

    if ($nid && $nid == $result->nid) {
      $values_add = array();
      $values_remove = array();

      $options = array_keys($buttons);

      foreach ($options as $option) {
        ${$option} = isset($_GET[$option]) ? $_GET[$option] : NULL;
        if (!is_null(${$option})) {
          if (${$option}) {
            $values_add[] = $option;
          }
          else {
            $values_remove[] = $option;
          }
        }
      }

      if (empty($result->entity->field_demo_buttons[LANGUAGE_NONE])) {
        $result->entity->field_demo_buttons[LANGUAGE_NONE] = array();
      }

      foreach ($values_add as $value) {
        $value_exists = FALSE;
        foreach ($result->entity->field_demo_buttons[LANGUAGE_NONE] as $item) {
          if ($item['value'] ==  $value) {
            $value_exists = TRUE;
          }
        }
        if (!$value_exists) {
          $result->entity->field_demo_buttons[LANGUAGE_NONE][] = array(
            'value' => $value
          );
        }
      }

      foreach ($values_remove as $value) {
        foreach ($result->entity->field_demo_buttons[LANGUAGE_NONE] as $key => $item) {
          if ($item['value'] == $value) {
            unset($result->entity->field_demo_buttons[LANGUAGE_NONE][$key]);
          }
        }
      }

      node_save($result->entity);
    }
    if (!empty($result->entity->field_demo_buttons[LANGUAGE_NONE])) {
      foreach ($result->entity->field_demo_buttons[LANGUAGE_NONE] as $button) {
        $result->demo_buttons[$button['value']] = $buttons[$button['value']];
      }
    }
    unset($result->entity);
  }
  //############################################################################

  return theme('ict_project_listing_block', array(
    'rows' => $results
  ));
}