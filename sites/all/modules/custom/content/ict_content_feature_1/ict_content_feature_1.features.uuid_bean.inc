<?php
/**
 * @file
 * ict_content_feature_1.features.uuid_bean.inc
 */

/**
 * Implements hook_uuid_features_default_beans().
 */
function ict_content_feature_1_uuid_features_default_beans() {
  $beans = array();

  $beans[] = array(
    'label' => 'Project Page description',
    'description' => NULL,
    'title' => 'Add and manage projects',
    'type' => 'prject_list_description',
    'data' => array(
      'view_mode' => 'default',
    ),
    'delta' => 'project-page-description',
    'view_mode' => 'default',
    'created' => 1464228424,
    'log' => '',
    'uid' => 1,
    'default_revision' => 1,
    'revisions' => array(),
    'vuuid' => '8b245e43-9e2a-4053-89c0-53e5d242127e',
    'uuid' => '03921703-a9f4-428e-8168-bdcbce2acefc',
    'field_description' => array(
      'und' => array(
        0 => array(
          'value' => '<p>On this page, a user can view all major ICT-enabled projects within their organisation and manage projects that they have been assigned to. Major ICT-enabled projects are defined as projects with ICT costs of $10 million or more. Initially, all current projects that meet this threshold will be included in the Dashboard. New projects should be added to the Dashboard once they have been approved.</p>

<p>A user will have an edit/approve button in the action column if the user has been assigned to a specific project.</p>

<p>Only the Departmental Administrator can register a new project, delete drafts and assign/remove users within the project.</p>
',
          'format' => 'filtered_html',
          'safe_value' => '<p>On this page, a user can view all major ICT-enabled projects within their organisation and manage projects that they have been assigned to. Major ICT-enabled projects are defined as projects with ICT costs of $10 million or more. Initially, all current projects that meet this threshold will be included in the Dashboard. New projects should be added to the Dashboard once they have been approved.</p>
<p>A user will have an edit/approve button in the action column if the user has been assigned to a specific project.</p>
<p>Only the Departmental Administrator can register a new project, delete drafts and assign/remove users within the project.</p>
',
        ),
      ),
    ),
  );
  $beans[] = array(
    'label' => 'Home Page Main copy',
    'description' => NULL,
    'title' => '',
    'type' => 'home_page_main_copy',
    'data' => array(
      'view_mode' => 'default',
    ),
    'delta' => 'home-page-main-copy',
    'view_mode' => 'default',
    'created' => 1464153609,
    'log' => '',
    'uid' => 1,
    'default_revision' => 1,
    'revisions' => array(),
    'vuuid' => 'c4b2ed40-9921-49d3-99be-4e07ec3d9c96',
    'uuid' => '52b0ada2-8235-4209-a9ed-9c5e4ad117a1',
    'field_description' => array(
      'und' => array(
        0 => array(
          'value' => '<p>The purpose of this Dashboard is to increase transparency of, and accountability for, the performance of major Government ICT-enabled projects.<br />
&nbsp;<br />
The Dashboard shows active projects with ICT costs of $10 million or more. Projects’ expenditure, schedule and benefits are measured against plan, and can be viewed collectively and individually.</p>
',
          'format' => 'filtered_html',
          'safe_value' => '<p>The purpose of this Dashboard is to increase transparency of, and accountability for, the performance of major Government ICT-enabled projects.<br />
 <br />
The Dashboard shows active projects with ICT costs of $10 million or more. Projects’ expenditure, schedule and benefits are measured against plan, and can be viewed collectively and individually.</p>
',
        ),
      ),
    ),
  );
  $beans[] = array(
    'label' => 'Sign-in helptext',
    'description' => NULL,
    'title' => '',
    'type' => 'sign_in_helptext',
    'data' => array(
      'view_mode' => 'default',
    ),
    'delta' => 'sign-in-helptext',
    'view_mode' => 'default',
    'created' => 1464159683,
    'log' => '',
    'uid' => 1,
    'default_revision' => 1,
    'revisions' => array(),
    'vuuid' => '0de4ef83-fd00-4b0e-b08a-fee6ccf6b7e3',
    'uuid' => '8bd1cb21-c896-48ec-b39b-97b7c5ee15d3',
    'field_description' => array(
      'und' => array(
        0 => array(
          'value' => '<p>This is an access point for Departmental Administrators and assigned officers. A user account is not required to view information on the ICT Projects Dashboard. If you are not a Departmental Administrator or an assigned officer please return to the <a href="/">Dashboard</a>.</p>
',
          'format' => 'filtered_html',
          'safe_value' => '<p>This is an access point for Departmental Administrators and assigned officers. A user account is not required to view information on the ICT Projects Dashboard. If you are not a Departmental Administrator or an assigned officer please return to the <a href="/">Dashboard</a>.</p>
',
        ),
      ),
    ),
  );
  return $beans;
}
