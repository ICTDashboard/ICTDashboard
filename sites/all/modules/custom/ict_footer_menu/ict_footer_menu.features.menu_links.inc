<?php
/**
 * @file
 * ict_footer_menu.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function ict_footer_menu_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-footer-menu_accessibility:node/1794.
  $menu_links['menu-footer-menu_accessibility:node/1794'] = array(
    'menu_name' => 'menu-footer-menu',
    'link_path' => 'node/1794',
    'router_path' => 'node/%',
    'link_title' => 'Accessibility',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-footer-menu_accessibility:node/1794',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: menu-footer-menu_contact-us:node/1793.
  $menu_links['menu-footer-menu_contact-us:node/1793'] = array(
    'menu_name' => 'menu-footer-menu',
    'link_path' => 'node/1793',
    'router_path' => 'node/%',
    'link_title' => 'Contact us',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-footer-menu_contact-us:node/1793',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: menu-footer-menu_privacy:node/1792.
  $menu_links['menu-footer-menu_privacy:node/1792'] = array(
    'menu_name' => 'menu-footer-menu',
    'link_path' => 'node/1792',
    'router_path' => 'node/%',
    'link_title' => 'Privacy',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-footer-menu_privacy:node/1792',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Accessibility');
  t('Contact us');
  t('Privacy');

  return $menu_links;
}
