<?php

function itdash_form_element($variables) {

  if (isset($variables['element']['#custom_structure']) && $variables['element']['#custom_structure']) {
    $element = &$variables['element'];

    // This function is invoked as theme wrapper, but the rendered form element
    // may not necessarily have been processed by form_builder().
    $element += array(
      '#title_display' => 'before',
    );

    // Add element #id for #type 'item'.
    if (isset($element['#markup']) && !empty($element['#id'])) {
      $attributes['id'] = $element['#id'];
    }
    // Add element's #type and #name as class to aid with JS/CSS selectors.
    $attributes['class'] = array('form-item');
    if (!empty($element['#type'])) {
      $attributes['class'][] = 'form-type-' . strtr($element['#type'], '_', '-');
    }
    if (!empty($element['#name'])) {
      $attributes['class'][] = 'form-item-' . strtr($element['#name'], array(' ' => '-', '_' => '-', '[' => '-', ']' => ''));
    }
    // Add a class for disabled elements to facilitate cross-browser styling.
    if (!empty($element['#attributes']['disabled'])) {
      $attributes['class'][] = 'form-disabled';
    }
    if (!is_string($element['#custom_structure'])) {
      $output = '<p>' . "\n";
    }
    else {
      $parts = explode('  ', $element['#custom_structure']);
      $output = reset($parts) . "\n";
    };

    // If #title is not set, we don't display any label or required marker.
    if (!isset($element['#title'])) {
      $element['#title_display'] = 'none';
    }
    $prefix = isset($element['#field_prefix']) ? '<span class="field-prefix">' . $element['#field_prefix'] . '</span> ' : '';
    $suffix = isset($element['#field_suffix']) ? ' <span class="field-suffix">' . $element['#field_suffix'] . '</span>' : '';

    switch ($element['#title_display']) {
      case 'before':
      case 'invisible':
        $output .= ' ' . theme('form_element_label', $variables);
        $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
        break;

      case 'after':
        $output .= ' ' . $prefix . $element['#children'] . $suffix;
        $output .= ' ' . theme('form_element_label', $variables) . "\n";
        break;

      case 'none':
      case 'attribute':
        // Output no label and no required marker, only the children.
        $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
        break;
    }

    if (!empty($element['#description'])) {
      $output .= '<div class="description">' . $element['#description'] . "</div>\n";
    }

    if (!is_string($element['#custom_structure'])) {
      $output .= '</p>' . "\n";
    }
    else {
      $parts = explode('  ', $element['#custom_structure']);
      $output .= end($parts) . "\n";
    }
  }
  else {


    $element = &$variables['element'];

    // This function is invoked as theme wrapper, but the rendered form element
    // may not necessarily have been processed by form_builder().
    $element += array(
      '#title_display' => 'before',
    );

    // Add element #id for #type 'item'.
    if (isset($element['#markup']) && !empty($element['#id'])) {
      $attributes['id'] = $element['#id'];
    }

    // Add element's #type and #name as class to aid with JS/CSS selectors.
    $attributes['class'] = array('form-item');
    if (!empty($element['#type'])) {
      $attributes['class'][] = 'form-type-' . strtr($element['#type'], '_', '-');
    }
    if (!empty($element['#name'])) {
      $attributes['class'][] = 'form-item-' . strtr($element['#name'], array(' ' => '-', '_' => '-', '[' => '-', ']' => ''));
    }
    // Add a class for disabled elements to facilitate cross-browser styling.
    if (!empty($element['#attributes']['disabled'])) {
      $attributes['class'][] = 'form-disabled';
    }

    if (isset($element['#wrapper_class']) && is_array($element['#wrapper_class'])) {
      $attributes['class'] = array_merge($attributes['class'], $element['#wrapper_class']);
    }
    $output = '<div' . drupal_attributes($attributes) . '>' . "\n";

    // If #title is not set, we don't display any label or required marker.
    if (!isset($element['#title'])) {
      $element['#title_display'] = 'none';
    }
    $prefix = isset($element['#field_prefix']) ? '<span class="field-prefix">' . $element['#field_prefix'] . '</span> ' : '';
    $suffix = isset($element['#field_suffix']) ? ' <span class="field-suffix">' . $element['#field_suffix'] . '</span>' : '';

    switch ($element['#title_display']) {
      case 'before':
      case 'invisible':
        $output .= ' ' . theme('form_element_label', $variables);
        $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
        break;

      case 'after':
        $output .= ' ' . $prefix . $element['#children'] . $suffix;
        $output .= ' ' . theme('form_element_label', $variables) . "\n";
        break;

      case 'none':
      case 'attribute':
        // Output no label and no required marker, only the children.
        $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
        break;
    }

    if (!empty($element['#description'])) {
      $output .= '<div class="description">' . $element['#description'] . "</div>\n";
    }

    $output .= "</div>\n";
  }

  return $output;
}


function itdash_menu_tree__menu_header_menu ($variables) {
  return '<ul id="main-menu" class="nav">' . $variables['tree'] . '</ul>';
}


function itdash_menu_link__menu_header_menu ($variables) {
  $element = $variables['element'];
  $sub_menu = '';

  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }
  $output = l($element['#title'], $element['#href'], $element['#localized_options']['attributes']);
  $element['#attributes']['class'] = array_merge($element['#attributes']['class'], $element['#localized_options']['attributes']['class']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}


function itdash_preprocess_views_view_table(&$vars) {
  if ($vars['view']->name == 'project_list_view_to_user') {

    $title_order = 'desc';
    $changed_order = 'asc';

    if (isset($_GET['order']) && $_GET['order'] = 'title' && $_GET['sort'] == 'desc') {
      $title_order = 'asc';
    }

    if (isset($_GET['order']) && $_GET['order'] = 'changed'  && $_GET['sort'] == 'asc') {
      $changed_order = 'desc';
    }

    $vars['header']['title'] = $vars['view']->field['title']->options['label'] . '<a class="asc" href="' . url(current_path(), array('query' => array('order' => 'title', 'sort' => $title_order))) . '"><i class="fa fa-sort-asc"></i><i class="fa fa-sort-desc"></i></a>';
    $vars['header']['changed'] = $vars['view']->field['changed']->options['label'] . '<a class="desc" href="' . url(current_path(), array('query' => array('order' => 'changed', 'sort' => $changed_order))) . '"><i class="fa fa-sort-asc"></i><i class="fa fa-sort-desc"></i></a>';
  }
}

function itdash_css_alter(&$css) {
  // Remove defaults.css file.
  unset($css[drupal_get_path('module', 'system') . '/system.menus.css']);
  unset($css[drupal_get_path('module', 'system') . '/system.theme.css']);
}

function itdash_preprocess_html(&$vars) {
  drupal_add_js(drupal_get_path('theme', 'itdash') . '/js/jquery.multiSelect.js', array('type' => 'file', 'scope' => 'footer'));
  drupal_add_js(drupal_get_path('theme', 'itdash') . '/html/js/jquery.slicknav.js', array('type' => 'file', 'scope' => 'footer'));
  drupal_add_js('//select-box.googlecode.com/svn/tags/0.2/jquery.selectbox-0.2.min.js', array('type' => 'file', 'scope' => 'footer'));
  drupal_add_js(drupal_get_path('theme', 'itdash') . '/html/js/scripts.js', array('type' => 'file', 'scope' => 'footer'));
  drupal_add_js(drupal_get_path('theme', 'itdash') . '/js/respond.js', array('type' => 'file', 'scope' => 'header'));
  drupal_add_css(drupal_get_path('theme', 'itdash') . '/html/css/ie.css', array('weight' => 999, 'browsers' => array('IE' => 'lte IE 8', '!IE' => FALSE), 'preprocess' => FALSE));
  drupal_add_css(drupal_get_path('theme', 'itdash') . '/html/css/slicknav.css');
  drupal_add_css(drupal_get_path('theme', 'itdash') . '/html/css/jquery.selectbox.css');
  drupal_add_css(drupal_get_path('theme', 'itdash') . '/css/jquery.multiSelect.css');
  drupal_add_css('//ajax.googleapis.com/ajax/libs/jqueryui/1.8.6/themes/base/jquery-ui.css');
}

function itdash_file_widget($variables) {

  $element = $variables['element'];

  $element['upload_button']['#access'] = FALSE;
  $output = '';
  // The "form-managed-file" class is required for proper Ajax functionality.
  $output .= '<div class="file-widget form-managed-file clearfix">';
  $output .= '<div class="fileUpload btn btn-primary"><span>Choose file</span>';
  if ($element['fid']['#value'] != 0) {
    // Add the file size after the file name.
    $element['filename']['#markup'] .= ' <span class="file-size">(' . format_size($element['#file']->filesize) . ')</span> ';
  }

  $element['upload']['#attributes'] = array('class' => array('upload'));
  $output .= render($element['upload']);
  $output .= '</div>';
  $output .= drupal_render_children($element);
  $output .= '</div>';

  return $output;
}
