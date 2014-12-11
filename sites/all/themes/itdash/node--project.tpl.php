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
        <div class="project-view info d-all">
          
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
            /*
             * CREATE TABLE public.test
(
    _id SERIAL PRIMARY KEY NOT NULL,
    timestamp TEXT NOT NULL,
    name TEXT NOT NULL,
    metric TEXT NOT NULL,
    value TEXT NOT NULL
);
            select timestamp,name,array_agg(metric),array_agg(value) from test group by timestamp,name;

            http://stackoverflow.com/questions/12414750/is-there-something-like-a-zip-function-in-postgresql-that-combines-two-arrays

select DISTINCT d.name, s.timestamp, d.metric, d.value from "2133eaed-150b-4c73-a314-67a0bde04115" d join (select name,metric, max(timestamp) as timestamp from "2133eaed-150b-4c73-a314-67a0bde04115" GROUP BY name,metric) s on d.metric=s.metric and d.timestamp=s.timestamp where d.name = 'AAT Project B';


select distinct p.name, program, agency, total_value
FROM (select name, value as program from test where metric = 'program'  ) p full outer JOIN
  (select name, value as agency from test where metric = 'agency' ) a on p.name = a.name
  full outer JOIN
  (select name, value as total_value from test where metric = 'total_value' ) v on p.name = v.name;

            https://wiki.postgresql.org/wiki/Grouping_Sets
            */
            ?>
          </pre> 
          <table>
            <tr>
              <td class="label">Current report date:</td>
              <td class="text">
                <?php 
                  print $report_date;
                ?>
              </td>
            </tr>
            <tr>
              <td class="label">Government entity:</td>
              <td class="text">
                <?php print ($node->field_government_entity_name) ? $node->field_government_entity_name['und'][0]['taxonomy_term']->name : ''; ?>
              </td>
            </tr>
            <tr>
              <td class="label">Project name:</td>
              <td class="text"><?php print $node->title; ?></td>
            </tr>
            <tr>
              <td class="label">Brief project summary:</td>
              <td class="text">
                <?php print ($node->field_brief_project_summary) ? $node->field_brief_project_summary['und'][0]['safe_value'] : ''; ?>
              </td>
            </tr>
            <tr>
              <td class="label">Project category: </td>
              <td class="text">
                <?php 
                  print ($node->field_project_category) ? $node->field_project_category['und'][0]['value'] : '';
                ?>
              </td>
            </tr>
            <tr>
              <td class="label">Project manager: </td>
              <td class="text">
                <?php print ($node->field_project_manager) ? $node->field_project_manager['und'][0]['safe_value'] : ''; ?>
              </td>
            </tr>
            <tr>
              <td class="label">Implementation partners:</td>
              <td class="text">
                <?php 
                    print ($node->field_implementation_partners) ? str_replace("\n", ", ", $node->field_implementation_partners['und'][0]['safe_value']) : '';
                ?>
              </td>
            </tr>
            <tr>
              <td class="label">Total project budget ($m):</td>
              <td class="text">
                <?php print ($node->field_total_project_budget) ? '$'.(int)$node->field_total_project_budget['und'][0]['value'].' million' : ''; ?>
              </td>
            </tr>
            <tr>
              <td class="label">Expenditure type:</td>
              <td class="text">
                <?php print ($node->field_expenditure_type) ? $node->field_expenditure_type['und'][0]['value'] : ''; ?>
              </td>
            </tr>
            <tr>
              <td class="label">Start date:</td>
              <td class="text">
                <?php 
                  print date_format(date_create($start_date), 'd M Y');
                ?>
              </td>
            </tr>
            <tr>
              <td class="label">Baseline completion date:</td>
              <td class="text">
                <?php 
                  if ($node->field_original_completion_date)
                    print date_format(date_create($orig_complete_date), 'd M Y');
                ?>
              </td>
            </tr>
            <tr>
              <td class="label">Implementation Partners:</td>
              <td class="text">
                <?php print ($node->field_implementation_partners) ? $node->field_implementation_partners['und'][0]['safe_value'] : ''; ?>
              </td>
            </tr>

          </table>
        </div>
        
        <h2>Project Status</h2>
        <div class="project-view status1 d-all">
          <table>
            <tr>
              <td class="label">Current Project Rating:</td>
              <td class="text">
                <?php
                print reset($data['current_rank']); ?>
              </td>
            </tr>
            <tr>
              <td class="label">Total spent to date ($m):</td>
              <td class="text">
                <?php
                print '$'.(int)reset($data['total_spent_to_date']).' million' ?>
              </td>
            </tr>
            <tr>
              <td class="label">Current Total Expected Spend for Current Financial Year ($m):</td>
              <td class="text">
                <?php
                print '$'.(int)reset($data['current_total_expected_spend_current_financial_year']).' million' ?>
              </td>
            </tr>

            <tr>
              <td class="label">Current Total Expected budget ($m):</td>
              <td class="text">
                <?php
                print '$'.(int)reset($data['current_total_expected_budget']).' million' ?>
              </td>
            </tr>

            <tr>
              <td class="label">Current Expected Completion Date:</td>
              <td class="text">
                <?php
                print reset($data['current_expected_completion_date']); ?>
              </td>
            </tr>

            <tr>
              <td class="label">Current Number of Government FTEs</td>
              <td class="text">
                <?php
                print reset($data['current_number_of_government_ftes']); ?>
              </td>
            </tr>
            <tr>
              <td class="label">Current Number of Contractors</td>
              <td class="text">
                <?php
                print reset($data['current_number_of_contractors']); ?>
              </td>
            </tr>

            <tr>
              <td class="label">Current estimated level of project completion:</td>
              <td class="text">
                <?php
                print reset($data['current_estimated_level_of_project_completion']); ?>%
              </td>
            </tr>
            <tr>
              <td class="label">Current Estimate of Value To Be Realised (% value of project cost)</td>
              <td class="text">
                <?php
                print reset($data['current_estimated_level_of_value_realised']); ?>
              </td>
            </tr>

            <tr>
              <td class="label">Most recent agency comment:</td>
              <td class="text">
                <?php
                print reset($data['agency_comment']); ?>
              </td>
            </tr>
          </table>
        </div>
        
       <!-- <h2>Performance Metrics</h2>
        <div class="project-view metrics d-all">
          <h3>Operational Performance: </h3>
          <table border="0" cellspacing="0" cellpadding="0">
            <tr>
              <th>Metric Description </th>
              <th>Frequency</th>
              <th>Unit of Measure</th>
              <th>FY2014 Target</th>
              <th>Most Recent Actual</th>
              <th>Metric Status *</th>
              <th>Updated Date of Most Recent Actual *</th>
            </tr>
            <tr>
              <td>% high volume transactions digitised</td>
              <td>Quarterly</td>
              <td>% of all transactions identified as high volume (over 50k/yr)</td>
              <td>60%</td>
              <td>60%</td>
              <td>Not yet met</td>
              <td>2014-08-10</td>
            </tr>
            <tr>
              <td>% high volume transactions digitised</td>
              <td>Quarterly</td>
              <td>% of all transactions identified as high volume (over 50k/yr)</td>
              <td>60%</td>
              <td>60%</td>
              <td>Not yet met</td>
              <td>2014-08-10</td>
            </tr>
            <tr>
              <td>% high volume transactions digitised</td>
              <td>Quarterly</td>
              <td>% of all transactions identified as high volume (over 50k/yr)</td>
              <td>60%</td>
              <td>60%</td>
              <td>Not yet met</td>
              <td>2014-08-10</td>
            </tr>
          </table>
        </div> -->
      </div>
    </div>
  <?php endif; ?>
  
</div></div> <!-- /node-inner, /node -->
