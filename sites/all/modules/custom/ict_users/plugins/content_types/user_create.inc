<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Add User'),
  'description' => t('User create form.'),
  'category' => t('ICT'),
  'render callback' => 'ict_user_create_form_render',
);

/**
 * return add project themed form
 */
function ict_user_create_form_render($subtype, $conf, $panel_args, $context = NULL) {

  $form = drupal_get_form('user_register_form');

  $form['#theme'] = 'ict_users_add_new_form';

  $block = new stdClass;
  $block->content = drupal_render($form);
  return $block;
}
