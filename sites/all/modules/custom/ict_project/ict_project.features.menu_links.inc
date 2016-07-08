<?php
/**
 * @file
 * ict_project.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function ict_project_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: management_honeypot-configuration:admin/config/content/honeypot.
  $menu_links['management_honeypot-configuration:admin/config/content/honeypot'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/content/honeypot',
    'router_path' => 'admin/config/content/honeypot',
    'link_title' => 'Honeypot configuration',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure Honeypot spam prevention and the forms on which Honeypot will be used.',
      ),
      'identifier' => 'management_honeypot-configuration:admin/config/content/honeypot',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_content-authoring:admin/config/content',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Honeypot configuration');

  return $menu_links;
}
