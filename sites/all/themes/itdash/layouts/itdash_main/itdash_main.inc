<?php
// $Id: $

// Plugin definition
$plugin = array(
  'title' => t('ICT Dashboard Main layout'),
  'category' => t('ICT'),
  'icon' => 'itdash_main.png',
  'theme' => 'itdash_itdash_main',
  'admin theme' => 'itdash_itdash_main_admin',
  'admin css' => 'itdash_main.css',
	'hook menu'	=> 'itdash_site_panels_layouts_menu',
  'regions' => array(
    'content' => t('Main Content Section'),
  ),
);
