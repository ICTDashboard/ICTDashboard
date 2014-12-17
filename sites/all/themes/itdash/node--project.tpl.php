<div class="node-<?php print $node->nid; ?> node<?php if ($sticky) { print ' sticky'; } ?><?php if (!$status) { print ' node-unpublished'; } ?> clearfix thing"><div class="node-inner">

  <?php if ($page == 1 || $page == 0 && $teaser == 0): ?>
    
    <div class="full-node clearfix">
      <div class="page-title dotbg">
        <div class="inner-title-content wrap cf">
          <h1>Service Delivery Reform ICT Project</h1>
        </div>
      </div>
      
      <div id="inner-content" class="wrap cf">
        <h2>Project Information</h2>
        <div class="project-view info d-all project-update-submission ">
          
            <?php 
              $sql = 'SELECT DISTINCT d.name, s.timestamp, d.metric, d.value from "'.variable_get("ckan_resource_id").'"
              d join (select name,metric, max(timestamp) as timestamp from "'.variable_get("ckan_resource_id").'" GROUP BY name,metric) s on d.metric=s.metric and d.timestamp=s.timestamp
              WHERE d.name = \''.$node->title.'\'';
              $url = variable_get("ckan_url").'/api/action/datastore_search_sql?sql='.urlencode($sql);
              $request = drupal_http_request($url);
              $result = json_decode($request->data);
              $data = Array();
              $report_date = "";
              foreach ($result->result->records as $row) {
                $data[$row->metric][$row->timestamp] = $row->value;
                $report_date = $row->timestamp;
              }
            ?>
          </pre> 
          <table>
            <tbody>
              <tr>
                <td class="label">Government entity name</td>
                <td class="text"><?php print $node->field_government_entity_name['und'][0]['value']; ?></td>
              </tr>
              <tr>
                <td class="label">Government entity business group, division, & branch</td>
                <td class="text"><?php print $node->field_government_business_unit['und'][0]['value']; ?></td>
              </tr>
              <tr>
                <td class="label">Government programme <em>(if applicable)</em></td>
                <td class="text"><?php print $node->field_program_name['und'][0]['value']; ?></td>
              </tr>
              <tr><td colspan="2"><div class="dotted-line"></div></td></tr>
              <tr>
                <td class="label">Project title</td>
                <td class="text"><?php print $node->title; ?></td>
              </tr>
              <tr>
                <td class="label">Project description</td>
                <td class="text"><?php print $node->field_brief_project_summary['und'][0]['value']; ?></td>
              </tr>
              <tr>
                <td class="label">Original project start date</td>
                <td class="text"><?php print date_format(date_create($node->field_start_date['und'][0]['value']), 'd M Y'); ?></td>
              </tr>
              <tr>
                <td class="label">Original project completion date</td>
                <td class="text"><?php print date_format(date_create($node->field_original_completion_date['und'][0]['value']), 'd M Y'); ?></td>
              </tr>
              <tr>
                <td class="label">Rebaselined project start date</td>
                <td class="text"><?php print date_format(date_create($node->field_rebaselined_project_start['und'][0]['value']), 'd M Y'); ?></td>
              </tr>
              <tr>
                <td class="label">Rebaselined project completion date</td>
                <td class="text"><?php print date_format(date_create($node->field_rebaselined_project_compl['und'][0]['value']), 'd M Y'); ?></td>
              </tr>
              <tr>
                <td class="label">Project stage</td>
                <td class="text"><?php print $node->field_project_stage['und'][0]['taxonomy_term']->name; ?></td>
              </tr>
              <tr>
                <td class="label">Project category</td>
                <td class="text"><?php print $node->field_project_category['und'][0]['taxonomy_term']->name; ?></td>
              </tr>
              <tr>
                <td class="label">Project manager</td>
                <td class="text"><?php print $node->field_project_manager['und'][0]['value']; ?></td>
              </tr>
              <tr>
                <td class="label">Project manager email</td>
                <td class="text"><?php print $node->field_project_manager_email['und'][0]['email']; ?></td>
              </tr>
              <tr><td colspan="2"><div class="dotted-line"></div></td></tr>
              <tr>
                <td class="label">Original total project budget <em>($m)</em></td>
                <td class="text"><?php print $node->field_total_project_budget['und'][0]['value'].'$'; ?></td>
              </tr>
              <tr>
                <td class="label">Original Total project budget by FY <em>(predicted & past)</em></td>
                <td class="text">
                  <?php
                  $fci = $node->field_original_total_budget['und'];
                  $fci_cols = array();
                  foreach($fci as $col){
                    $fci_cols[] = field_collection_item_load($col['value']);
                  }
                  ?>
                  <table><tbody><tr><th></th><th>Previous</th><th>Current</th><th>1</th><th>2</th><th>3</th></tr><tr><td>FY (yy/yy)</td>
                  <?php
                    for ($i = 0; $i<5; $i++) {
                      print ('<td>'.$fci_cols[$i]->field_year['und'][0]['value'].'</td>');
                    }
                  ?>

                  </tr><tr><td>Opex</td>
                  <?php
                    for ($i = 0; $i<5; $i++) {
                      print ('<td>'.$fci_cols[$i]->field_opex['und'][0]['value'].'</td>');
                    }
                  ?>
                  </tr><tr><td>Capex</td>
                  <?php
                    for ($i = 0; $i<5; $i++) {
                      print ('<td>'.$fci_cols[$i]->field_capex['und'][0]['value'].'</td>');
                    }
                  ?>
                  </tr><tr><td>Total</td>
                  <?php
                    for ($i = 0; $i<5; $i++) {
                      print ('<td>'.$fci_cols[$i]->field_total['und'][0]['value'].'</td>');
                    }
                  ?>
                  </tr></tbody></table>
                </td>
              </tr>
              <tr>
                <td class="label">Rebaselined total project budget <em>($m)</em></td>
                <td class="text"><?php print $node->field_rebaselined_total_budget['und'][0]['value'].'$'; ?></td>
              </tr>
              <tr>
                <td class="label">Rebaselined Total project budget by FY <em>(predicted & past)</em></td>
                <td class="text">
                    <?php
                    $fci = $node->field_rebaselined_total_budget['und'];
                    $fci_cols = array();
                    foreach($fci as $col){
                      $fci_cols[] = field_collection_item_load($col['value']);
                    }
                    ?>
                    <table><tbody><tr><th></th><th>Previous</th><th>Current</th><th>1</th><th>2</th><th>3</th></tr><tr><td>FY (yy/yy)</td>
                    <?php
                      for ($i = 0; $i<5; $i++) {
                        print ('<td>'.$fci_cols[$i]->field_year['und'][0]['value'].'</td>');
                      }
                    ?>
                    </tr><tr><td>Opex</td>
                    <?php
                      for ($i = 0; $i<5; $i++) {
                        print ('<td>'.$fci_cols[$i]->field_opex['und'][0]['value'].'</td>');
                      }
                    ?>
                    </tr><tr><td>Capex</td>
                    <?php
                      for ($i = 0; $i<5; $i++) {
                        print ('<td>'.$fci_cols[$i]->field_capex['und'][0]['value'].'</td>');
                      }
                    ?>
                    </tr><tr><td>Total</td>
                    <?php
                      for ($i = 0; $i<5; $i++) {
                        print ('<td>'.$fci_cols[$i]->field_total['und'][0]['value'].'</td>');
                      }
                    ?>
                    </tr></tbody></table>
                </td>
              </tr>
              <tr>
                <td class="label">Project status</td>
                <td class="text"><?php print ucfirst($node->field_project_status['und'][0]['value']); ?></td>
              </tr>
              <tr>
                <td class="label">Expenditure type</td>
                <td class="text"><?php print $node->field_expenditure_type['und'][0]['value']; ?></td>
              </tr>
              <tr>
                <td class="label">Implementation Partners?<span>A list of any implementation partners for the project. This includes primary contractors and any formally supporting Government entities.</span></td>
                <td class="text"><?php 
                 for ($i=0, $count = count($node->field_implementation_partners['und']); $i<$count; $i++){
                  if ($i) print ', ';
                   print $node->field_implementation_partners['und'][$i]['value'];
                 }

                ?></td>
              </tr>
              <tr>
                <td class="label">Internal FTE</td>
                <td class="text"><?php print $node->field_internal_fte['und'][0]['value']; ?></td>
              </tr>
              <tr>
                <td class="label">External FTE</td>
                <td class="text"><?php print $node->field_external_fte['und'][0]['value']; ?></td>
              </tr>
              <tr>
                <td class="label">Users</td>
                <td class="text"><?php print $node->field_project_users['und'][0]['value']; ?></td>
              </tr>
            </tbody>
          </table>
        </div>
      
      </div>
    </div>
  <?php endif; ?>
  
</div></div> <!-- /node-inner, /node -->
