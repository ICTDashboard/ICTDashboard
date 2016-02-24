<?php
/**
 * @file
 * ict_user_guide.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function ict_user_guide_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: management_feedback-submissions:admin/structure/entityform_types/manage/feedback/submissions.
  $menu_links['management_feedback-submissions:admin/structure/entityform_types/manage/feedback/submissions'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/entityform_types/manage/feedback/submissions',
    'router_path' => 'admin/structure/entityform_types/manage/%/submissions',
    'link_title' => 'Feedback submissions',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'management_feedback-submissions:admin/structure/entityform_types/manage/feedback/submissions',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 50,
    'customized' => 1,
    'parent_identifier' => 'management_content:admin/content',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Feedback submissions');

  return $menu_links;
}
