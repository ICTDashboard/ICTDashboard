<?php
/**
 * @file
 * ict_dashboard_data_push_rules.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function ict_dashboard_data_push_rules_default_rules_configuration() {
  $items = array();
  $items['rules_create_project'] = entity_import('rules_config', '{ "rules_create_project" : {
      "LABEL" : "Create Project",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "ckan_remote_post" ],
      "ON" : { "node_insert--project" : { "bundle" : "project" } },
      "DO" : [
        { "ckan_remote_post_rules_action_remote_post" : {
            "USING" : { "nid" : "[node:nid]", "sid" : " [node:nid]" },
            "PROVIDE" : { "result" : { "result" : "Submission Result" } }
          }
        }
      ]
    }
  }');
  $items['rules_update_project'] = entity_import('rules_config', '{ "rules_update_project" : {
      "LABEL" : "Update Project",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "ckan_remote_post", "entityform" ],
      "ON" : { "entityform_insert" : [] },
      "IF" : [
        { "entity_is_of_type" : { "entity" : [ "entityform" ], "type" : "entityform" } }
      ],
      "DO" : [
        { "ckan_remote_post_rules_action_remote_post" : {
            "USING" : { "nid" : "[node:nid]", "sid" : "[entityform:entityform-id]" },
            "PROVIDE" : { "result" : { "result" : "Submission Result" } }
          }
        }
      ]
    }
  }');
  return $items;
}
