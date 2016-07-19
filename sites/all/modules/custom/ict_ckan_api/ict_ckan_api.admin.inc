<?php
/**
 * @file
 * ict_ckan_api.admin.inc
 */

include_once 'ckan_api/ckan_api.inc';

/**
 * Page callback: CKAN config form
 */
function ckan_conf_form($form, &$form_state)
{
  global $base_url;

  $form['ckan_admin_key'] = array(
    '#type' => 'textfield',
    '#title' => t('CKAN admin\'s API-Key'),
    '#default_value' => variable_get('ckan_admin_key', ''),
    '#size' => 40,
    '#description' => t('The key which used in requests to CKAN API.'),
    '#required' => TRUE,
  );
  $form['ckan_url'] = array(
    '#type' => 'textfield',
    '#title' => t('CKAN URL'),
    '#default_value' => variable_get('ckan_url', ''),
    '#size' => 40,
    '#description' => t('URL of CKAN instance.'),
    '#required' => TRUE,
  );
  $form['ckan_api_version'] = array(
    '#type' => 'textfield',
    '#title' => t('CKAN API version'),
    '#default_value' => variable_get('ckan_api_version', 3),
    '#size' => 40,
    '#description' => t('API\'s version for using in requests.'),
    '#required' => TRUE,
  );

  $form['dataset_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Dataset ID'),
    '#default_value' => variable_get('dataset_id', ''),
    '#size' => 40,
    '#description' => t('Dataset\'s id where to import all projects'),
    '#required' => TRUE,
  );

  $form['embargo_period'] = array(
    '#type' => 'textfield',
    '#title' => t('Embargo period in days'),
    '#default_value' => variable_get('embargo_period', 7),
    '#size' => 40,
    '#description' => t('The embargo period starts when an update submission is approved'),
    '#required' => TRUE,
  );

  return system_settings_form($form);
}

