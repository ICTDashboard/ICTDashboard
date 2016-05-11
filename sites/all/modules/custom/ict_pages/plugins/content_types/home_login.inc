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
					<div class="welcome-text d-all">
						<p>' . t('The purpose of this Dashboard is to increase transparency of, and accountability for, the performance of major Government ICT-enabled projects.') . '</p>
            <p>' . t('The Dashboard shows active projects with ICT costs of $10 million or more. Projects’ expenditure, schedule and benefits are measured against plan, and can be viewed collectively and individually.') . '</p>
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
