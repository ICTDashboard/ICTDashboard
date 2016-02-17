<?php
/**
 * @file
 * ict_footer_menu.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function ict_footer_menu_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_access_article';
  $strongarm->value = array(
    'view_own' => array(
      0 => 2,
      1 => 30037204,
    ),
    'view' => array(
      0 => 2,
      1 => 30037204,
    ),
  );
  $export['content_access_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_access_budget';
  $strongarm->value = array(
    'view_own' => array(
      0 => 2,
      1 => 30037204,
    ),
    'view' => array(
      0 => 2,
      1 => 30037204,
    ),
  );
  $export['content_access_budget'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_access_budget_portfolio';
  $strongarm->value = array(
    'view_own' => array(
      0 => 2,
      1 => 30037204,
    ),
    'view' => array(
      0 => 2,
      1 => 30037204,
    ),
  );
  $export['content_access_budget_portfolio'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_access_investment';
  $strongarm->value = array(
    'view_own' => array(
      0 => 2,
      1 => 30037204,
    ),
    'view' => array(
      0 => 2,
      1 => 30037204,
    ),
  );
  $export['content_access_investment'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_access_page';
  $strongarm->value = array(
    'view_own' => array(
      0 => 1,
      1 => 2,
      2 => 41888116,
      3 => 153917155,
      4 => 30037204,
    ),
    'view' => array(
      0 => 1,
      1 => 2,
      2 => 41888116,
      3 => 153917155,
      4 => 30037204,
    ),
  );
  $export['content_access_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_access_panel';
  $strongarm->value = array(
    'view_own' => array(
      0 => 2,
      1 => 30037204,
    ),
    'view' => array(
      0 => 2,
      1 => 30037204,
    ),
  );
  $export['content_access_panel'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_access_project';
  $strongarm->value = array(
    'view_own' => array(
      0 => 2,
      1 => 30037204,
    ),
    'view' => array(
      0 => 2,
      1 => 30037204,
    ),
  );
  $export['content_access_project'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_access_update';
  $strongarm->value = array(
    'view_own' => array(
      0 => 2,
      1 => 30037204,
    ),
    'view' => array(
      0 => 2,
      1 => 30037204,
    ),
  );
  $export['content_access_update'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_access_webform';
  $strongarm->value = array(
    'view_own' => array(
      0 => 2,
      1 => 30037204,
    ),
    'view' => array(
      0 => 2,
      1 => 30037204,
    ),
  );
  $export['content_access_webform'] = $strongarm;

  return $export;
}
