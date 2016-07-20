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

  // Basic options
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

  // Advanced options
  $form['adv_options'] = array(
    '#type' => 'fieldset', 
    '#title' => t('Advanced options'), 
    '#collapsible' => TRUE, 
    '#collapsed' => FALSE,
  );

  $form['adv_options']['ict_proxy'] = array(
    '#type' => 'textfield',
    '#title' => t('Set Proxy'),
    '#default_value' => variable_get('ict_proxy', ''),
    '#size' => 40,
    '#description' => t('Set proxy if needed, pattern is [host:port].'),
  );

  $form['adv_options']['ict_proxy_type'] = array(
    '#type' => 'textfield',
    '#title' => t('Set Proxy type'),
    '#default_value' => variable_get('ict_proxy_type', ''),
    '#size' => 40,
    '#description' => t('Set proxy type for example CURLPROXY_SOCKS4.'),
  );

  $form['adv_options']['ict_ckan_time'] = array(
    '#type' => 'textfield',
    '#title' => t('Set cron queue time'),
    '#default_value' => variable_get('ict_ckan_time', 300),
    '#size' => 20,
    '#description' => t('Set time for cron queue to run in seconds.'),
  );

  $form['adv_options']['ict_limit_query'] = array(
    '#type' => 'textfield',
    '#title' => t('Set Updates query limit'),
    '#default_value' => variable_get('ict_limit_query'),
    '#size' => 20,
    '#description' => t('Limit the number of updates to run on cron job, leave EMPTY for no limit'),
  );

  return system_settings_form($form);
}

