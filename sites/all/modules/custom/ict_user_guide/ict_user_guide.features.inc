<?php
/**
 * @file
 * ict_user_guide.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ict_user_guide_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "bean_admin_ui" && $api == "bean") {
    return array("version" => "5");
  }
  if ($module == "field_validation" && $api == "default_field_validation_rules") {
    return array("version" => "2");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_entityform_type().
 */
function ict_user_guide_default_entityform_type() {
  $items = array();
  $items['feedback'] = entity_import('entityform_type', '{
    "type" : "feedback",
    "label" : "Feedback",
    "data" : {
      "draftable" : 0,
      "draft_redirect_path" : "",
      "draft_button_text" : "",
      "draft_save_text" : { "value" : "", "format" : "filtered_html" },
      "submit_button_text" : "Send Feedback",
      "submit_confirm_msg" : "Thank you for your feedback.",
      "your_submissions" : "",
      "disallow_resubmit_msg" : "",
      "delete_confirm_msg" : "",
      "page_title_view" : "",
      "preview_page" : 0,
      "submission_page_title" : "Feedback Submission",
      "submission_text" : {
        "value" : "\\u003Cp\\u003E\\u003Cstrong\\u003EThank you for your feedback.\\u003C\\/strong\\u003E\\u003C\\/p\\u003E\\r\\n",
        "format" : "filtered_html"
      },
      "submission_show_submitted" : 0,
      "submissions_view" : "default",
      "user_submissions_view" : "default",
      "form_status" : "ENTITYFORM_OPEN",
      "roles" : { "1" : "1", "2" : "2", "30037204" : 0, "41888116" : 0, "153917155" : 0 },
      "resubmit_action" : "new",
      "redirect_path" : "feedback",
      "instruction_pre" : { "value" : "", "format" : "filtered_html" },
      "current_type" : "feedback",
      "enable_block" : 1
    },
    "weight" : "0",
    "rdf_mapping" : [],
    "paths" : []
  }');
  return $items;
}
