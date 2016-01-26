<?php
/**
 * @file
 * ict_footer_menu.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function ict_footer_menu_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-footer-menu.
  $menus['menu-footer-menu'] = array(
    'menu_name' => 'menu-footer-menu',
    'title' => 'Footer menu',
    'description' => 'Menu available in site footer',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Footer menu');
  t('Menu available in site footer');

  return $menus;
}
