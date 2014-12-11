<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Home Bottom'),
  'description' => t('Home Bottom page.'),
  'category' => t('ICT'),
  'render callback' => 'ict_pages_home_bottom_render',
  'admin info' => 'ict_pages_home_bottom_admin_info',
  'defaults' => array()
);

function ict_pages_home_bottom_render ($subtype, $conf, $panel_args, $context = NULL) {
  $block = new stdClass;

  $block->content = '
    <div class="home-banner">
				<img src="' . drupal_get_path('theme', 'itdash') . '/html/images/home-banner.png" alt="Home banner"/>
			</div>

			<div class="project-categories">
				<div class="wrap cf">
					<div class="box blue t-1of3 d-1of3">
						<div class="inner-box">
							<h3>Title of data project category</h3>
							<img src="' . drupal_get_path('theme', 'itdash') . '/html/images/box/1.png" alt="sample"/>
							<div class="text">
								<h4>CATEGORY</h4>
								<p>Quisque efficitur eros non semper pretium. Nunc et ex erat. Pellentesque elementum accumsan diam sit ameted.</p>
							</div>
						</div>
					</div>
					<div class="box blue t-1of3 d-1of3">
						<div class="inner-box">
							<h3>Title of data project category</h3>
							<img src="' . drupal_get_path('theme', 'itdash') . '/html/images/box/2.png" alt="sample"/>
							<div class="text">
								<h4>CATEGORY</h4>
								<p>Quisque efficitur eros non semper pretium. Nunc et ex erat. Pellentesque elementum accumsan diam sit ameted.</p>
							</div>
						</div>
					</div>
					<div class="box green d-1of3 t-1of3 last-col">
						<div class="inner-box">
							<h3>Title of data project category</h3>
							<img src="' . drupal_get_path('theme', 'itdash') . '/html/images/box/3.png" alt="sample"/>
							<div class="text">
								<h4>CATEGORY</h4>
								<p>Quisque efficitur eros non semper pretium. Nunc et ex erat. Pellentesque elementum accumsan diam sit ameted.</p>
							</div>
						</div>
					</div>
				</div>
			</div>

			<div id="inner-content" class="wrap cf">
  ';

  return $block;
}


/**
 * 'admin info' callback for panel pane.
 */
function ict_pages_home_bottom_admin_info ($subtype, $conf, $contexts) {
  $block = new stdClass;
  $block->title = t('Home Bottom Block');
  $block->content = t('Home Bottom Block');

  return $block;
}
