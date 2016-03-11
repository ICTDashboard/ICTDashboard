<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Home Upper'),
  'description' => t('Home Upper.'),
  'category' => t('ICT'),
  'render callback' => 'ict_pages_home_login_render',
  'admin info' => 'ict_pages_home_login_admin_info',
  'defaults' => array()
);

function ict_pages_home_login_render ($subtype, $conf, $panel_args, $context = NULL) {
  $block = new stdClass;

  $block->content = '
    <div class="welcome dotbg">
				<div class="wrap cf">
					<h1>' . t('Overview of Active Projects') . '</h1>
					<div class="welcome-text d-all">
						<p>' . t('The purpose of the ICT Projects Dashboard is to increase transparency of the performance of major Government ICT-enabled projects by publishing their status against a baseline, focusing on cost, schedule and expected benefits.') . '</p>
            <p>' . t('Major ICT-enabled projects are defined as those with a total project cost of $30 million or more, including ICT costs of at least $10 million.') . '</p>
					</div>
				</div>
			</div>
  ';

  return $block;
}


/**
 * 'admin info' callback for panel pane.
 */
function ict_pages_home_login_admin_info ($subtype, $conf, $contexts) {
  $block = new stdClass;
  $block->title = t('Home Login Block');
  $block->content = t('Home Login Block');

  return $block;
}
