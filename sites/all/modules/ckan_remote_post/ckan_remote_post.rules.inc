<?php

/**
 * Implement hook_rules_action_info().
 */
function ckan_remote_post_rules_action_info()
{

    return array(
        'ckan_remote_post_rules_action_remote_post' => array(
            'label' => t('Post form/node content to remote CKAN'),
            'group' => t('Custom'),
            'parameter' => array(
                'nid' => array(
                    'type' => 'text',
                    'label' => t('Node ID'),
                    'description' => t('Enter a value for a string that will be hashed using the md5 hash-algorithm.'),
                ),

                'sid' => array(
                    'type' => 'text',
                    'label' => t('Submission ID'),
                    'description' => t('Enter a value for a string that will be hashed using the md5 hash-algorithm.'),
                )
            ),

            'provides' => array(
                'result' => array(
                    'type' => 'text',
                    'label' => t('Submission Result'),
                ),
            ),
            'callback' => 'ckan_remote_post_rules_action_remote_post',
        ),
    );
}


// This callback creates the hashed string by using the parameters provided through rules' UI
function ckan_remote_post_rules_action_remote_post($nid, $sid)
{

    $string = "";

    $node = node_load($nid);
    if ($node && $node->type == 'webform') {
        $submission = webform_get_submission($nid, $sid);
        // Skip draft forms:
        if ($submission->is_draft) {
            return;
        }

        // Create a map with webform component ID's and the component themselves,
        // handy later on.
        $component_map = array();
        foreach ($node->webform['components'] as $component) {
            $component_map[$component['cid']] = $component;
        }

        // Prepare the submission data for remote posting. Creating a two-dimensional
        // array of form field names and the data.
        $payload = array();
        $value = "";
        foreach ($submission->data as $cid => $component_data) {
            if (isset($component_data['value'])) {
                $value = implode('; ', $component_data['value']);
            } else {
                $value = implode('; ', $component_data);
            }

            if (!empty($value)) {
                $payload[$component_map[$cid]['form_key']] = $value;
            }

        }
        if (isset($_GET['project'])) {
            $project_id = $_GET['project'];
            $project = node_load($project_id);
            $payload['project'] = $project->title;
        } else if (isset($_POST['submitted']['project'])) {
            $project_id = $_POST['submitted']['project'];
            $project = node_load($project_id);
            $payload['project'] = $project->title;
        }
        submit_key_value($payload);
    } else if ($node && $node->type == 'project') {
        $payload = Array('project' => $node->title);
        //$data=field_info_instances("node",$node-type);
        //where $source_node_type is the type of the node (not its name).
        // https://api.drupal.org/api/drupal/modules%21field%21field.info.inc/function/field_info_fields/7
        foreach ($node as $field_name => $field) {
            if (strpos($field_name, "field_") !== false) {
                $field_name = str_replace("field_", "", $field_name);
                #TODO implementation partners field
                if ($field_name == 'rebaselined_total_budget' || $field_name == 'original_total_budget') {
                    foreach ($field['und'] as $row) {
                        $entity = entity_load("field_collection_item",  array($row['value']));
                        $year = str_replace('/','',reset($entity)->field_year['und']['0']['value']);

                        $payload[$field_name.'_fy'.$year.'_opex'] = reset($entity)->field_opex['und']['0']['value'];
                        $payload[$field_name.'_fy'.$year.'_capex'] = reset($entity)->field_capex['und']['0']['value'];
                        $payload[$field_name.'_fy'.$year.'_total'] = reset($entity)->field_total['und']['0']['value'];
                    }
                } else if ($field_name == 'implementation_partners') {
                    $partners = Array();
                   /* foreach ($field['und'] as $row) {
                        $entity = entity_load("field_collection_item", array($row['value']));
                        $partner = reset($entity)->field_year['und']['0']['value'];
                        $payload[$field_name] = '';
                        $partners[] = $partner;
                    }*/
                    $payload[$field_name] = implode(';',$partners);
                } else if (isset($field['und'][0]['value'])) {
                    $payload[$field_name] = $field['und'][0]['value'];
                } else if (isset($field['und'][0]['tid'])) {
                    $term = taxonomy_term_load($field['und'][0]['tid']);
                    $payload[$field_name] = $term->name;
                }
            }
        }
        submit_key_value($payload);
    } else if ($nid == "") {
        $entityform_id = $sid; // entity form id
        $entityform = entityform_load($entityform_id);
        $entityform_wrapper = entity_metadata_wrapper('entityform', $entityform);
        $payload = Array();
        if (isset($_GET['project'])) {
            $project_id = $_GET['project'];
            $project = node_load($project_id);
            $payload['project'] = $project->title;
        } else if (isset($_POST['submitted']['project'])) {
            $project_id = $_POST['submitted']['project'];
            $project = node_load($project_id);
            $payload['project'] = $project->title;
        }
        //$data=field_info_instances("node",$node-type);
        //where $source_node_type is the type of the node (not its name).
        // https://api.drupal.org/api/drupal/modules%21field%21field.info.inc/function/field_info_fields/7
        foreach ($entityform as $field_name => $field) {
            #TODO FY tables

            if (strpos($field_name, "field_") !== false) {
                $field_name = str_replace(array("field_", "mid_", 'end_'), "", $field_name);
                 if ($field_name == 'predicted_budget') {
                    foreach ($field['und'] as $row) {
                        $entity = entity_load("field_collection_item",  array($row['value']));
                        $year = str_replace('/','',reset($entity)->field_predicted_year['und']['0']['value']);

                        $payload[$field_name.'_fy'.$year.'_opex'] = reset($entity)->field_predicted_opex['und']['0']['value'];
                        $payload[$field_name.'_fy'.$year.'_capex'] = reset($entity)->field_predicted_capex['und']['0']['value'];
                        $payload[$field_name.'_fy'.$year.'_total'] = reset($entity)->field_predicted_total['und']['0']['value'];
                    }
                } else if (isset($field['und'][0]['value'])) {
                     $payload[$field_name] = $field['und'][0]['value'];
                 } else if (isset($field['und'][0]['tid'])) {
                    $term = taxonomy_term_load($field['und'][0]['tid']);
                    $payload[$field_name] = $term->name;
                }
            }
        }
        submit_key_value($payload);
    }

    return array(
        'result' => $string,
    );
}
