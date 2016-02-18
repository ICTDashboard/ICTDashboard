<?php
/**
 * @file
 * ict_user_guide.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function ict_user_guide_default_rules_configuration() {
  $items = array();
  $items['rules_feedback_submission'] = entity_import('rules_config', '{ "rules_feedback_submission" : {
      "LABEL" : "Feedback submission",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "entityform" ],
      "ON" : { "entityform_insert" : [] },
      "DO" : [
        { "mail" : {
            "to" : [ "site:mail" ],
            "subject" : "New feedback submission on [site:name]",
            "message" : "New feedback submission created\\r\\n\\r\\nName: [entityform:field-feedback-name]\\r\\nE-mail: [entityform:field-feedback-email]\\r\\nFeedback:\\r\\n[entityform:field-feedback-text]\\r\\n\\r\\nYou can view submission on [site:url]entityform\\/[entityform:entityform-id]",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  return $items;
}
