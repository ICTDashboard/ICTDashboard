<?php
/**
 * @file
 * ict_mail.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function ict_mail_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'mailsystem_theme';
  $strongarm->value = 'current';
  $export['mailsystem_theme'] = $strongarm;

  return $export;
}
