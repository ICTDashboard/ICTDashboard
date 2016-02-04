<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Home Login'),
  'description' => t('Home Login page.'),
  'category' => t('ICT'),
  'render callback' => 'ict_pages_home_login_render',
  'admin info' => 'ict_pages_home_login_admin_info',
  'defaults' => array()
);

function ict_pages_home_login_render ($subtype, $conf, $panel_args, $context = NULL) {
  $block = new stdClass;

  $form = '';

  if (!user_is_logged_in()) {
    $elements = drupal_get_form("user_login");

    $elements['name']['#title_display'] = 'invisible';
    $elements['name']['#field_prefix'] = '<p>';
    $elements['name']['#field_suffix'] = '</p>';
    $elements['name']['#description'] = '';
    $elements['pass']['#description'] = '';
    $elements['name']['#attributes']['placeholder'] = t('Username');
    $elements['pass']['#attributes']['placeholder'] = t('Password');
    $elements['pass']['#title_display'] = 'invisible';
    $elements['pass']['#field_prefix'] = '<p>';
    $elements['pass']['#field_suffix'] = '</p>';
    $elements['actions']['submit']['#prefix'] = '<p class="submit">';
    $elements['actions']['submit']['#suffix'] = '</p>';
    $elements['#attributes']['autocomplete'] = 'off';

    $elements['#attached']['js'] = array(
      drupal_get_path('theme', 'itdash') . '/js/jquery.watermark.min.js',
      drupal_get_path('theme', 'itdash') . '/js/watermark_settings.js',
    );

    $form = '<div class="welcome-form d-1of3 t-1of2 last-col">' . drupal_render($elements) . '</div>';
  }

  $block->content = '
    <div class="welcome dotbg">
				<div class="wrap cf">
					<h1>ICT Projects Dashboard</h1>
					<div class="welcome-text d-2of3 t-1of2">
						<p>The purpose of the ICT Projects Dashboard is to increase transparency of the performance of major Government ICT-enabled projects by publishing their status against a baseline, focusing on cost, schedule and expected benefits.</p>
            <p>Major ICT-enabled projects are defined as those with a total project cost of $30 million or more, including ICT costs of at least $10 million.</p>
            <p>A dashboard user account is required to report or update project information. If you do not have a user account please contact your ICT Projects Dashboard Departmental Administrator.</p>
            <p><a href="mailto:ICTProjectDashboard@finance.gov.au">ICTProjectDashboard@finance.gov.au</a> or phone (02) 6215 2091</p>
					</div>
					' . $form . '
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
