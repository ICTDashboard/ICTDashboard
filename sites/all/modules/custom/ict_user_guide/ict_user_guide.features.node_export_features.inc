<?php
/**
 * @file
 * ict_user_guide.features.node_export_features.inc
 */

/**
 * Implements hook_node_export_features_default().
 */
function ict_user_guide_node_export_features_default() {
  $node_export = array(
  'code_string' => 'array(
  (object) array(
      \'vid\' => \'1801\',
      \'uid\' => \'1\',
      \'title\' => \'User Guide\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'1\',
      \'promote\' => \'0\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'39b49b1e-3e28-44a2-a131-bc951b87bf7a\',
      \'ds_switch\' => \'\',
      \'nid\' => \'1787\',
      \'type\' => \'page\',
      \'language\' => \'und\',
      \'created\' => \'1453806633\',
      \'changed\' => \'1453817069\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'4697e6b4-6f76-4804-9ab0-a59dad085786\',
      \'revision_timestamp\' => \'1453817069\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<h1>Content to be added after Pilot stage, prior to launch</h1>\\r\\n",
            \'summary\' => \'\',
            \'format\' => \'filtered_html\',
            \'safe_value\' => "<p>Content to be added after Pilot stage, prior to launch</p>\\n",
            \'safe_summary\' => \'\',
          ),
        ),
      ),
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
          \'foaf:Document\',
        ),
        \'title\' => array(
          \'predicates\' => array(
            \'dc:title\',
          ),
        ),
        \'created\' => array(
          \'predicates\' => array(
            \'dc:date\',
            \'dc:created\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'changed\' => array(
          \'predicates\' => array(
            \'dc:modified\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'body\' => array(
          \'predicates\' => array(
            \'content:encoded\',
          ),
        ),
        \'uid\' => array(
          \'predicates\' => array(
            \'sioc:has_creator\',
          ),
          \'type\' => \'rel\',
        ),
        \'name\' => array(
          \'predicates\' => array(
            \'foaf:name\',
          ),
        ),
        \'comment_count\' => array(
          \'predicates\' => array(
            \'sioc:num_replies\',
          ),
          \'datatype\' => \'xsd:integer\',
        ),
        \'last_activity\' => array(
          \'predicates\' => array(
            \'sioc:last_activity_date\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
      ),
      \'path\' => array(
        \'pid\' => \'464\',
        \'source\' => \'node/1787\',
        \'alias\' => \'content/user-guide\',
        \'language\' => \'und\',
      ),
      \'cid\' => \'0\',
      \'last_comment_timestamp\' => \'1453806633\',
      \'last_comment_name\' => NULL,
      \'last_comment_uid\' => \'1\',
      \'comment_count\' => \'0\',
      \'name\' => \'admin\',
      \'picture\' => \'0\',
      \'data\' => \'a:5:{s:16:"ckeditor_default";s:1:"t";s:20:"ckeditor_show_toggle";s:1:"t";s:14:"ckeditor_width";s:4:"100%";s:13:"ckeditor_lang";s:2:"en";s:18:"ckeditor_auto_lang";s:1:"t";}\',
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
    ),
)',
);
  return $node_export;
}
