<?php
// $Id: $

// Plugin definition
$plugin = array(
  'title' => t('ICT Dashboard Dashboard layout'),
  'category' => t('ICT'),
  'icon' => 'itdash_main.png',
  'theme' => 'itdash_itdash_dashboard',
  'admin theme' => 'itdash_itdash_dashboard_admin',
  'admin css' => 'itdash_main.css',
	'hook menu'	=> 'itdash_site_panels_layouts_menu',
  'regions' => array(
    'content' => t('Main Content Section'),
  ),
);
