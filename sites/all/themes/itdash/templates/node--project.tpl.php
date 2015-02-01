<div class="node-<?php print $node->nid; ?> node<?php if ($sticky) { print ' sticky'; } ?><?php if (!$status) { print ' node-unpublished'; } ?> clearfix thing"><div class="node-inner">

  <?php if ($page == 1 || $page == 0 && $teaser == 0): ?>

    <div class="full-node clearfix">
      <div class="page-title dotbg">
        <div class="inner-title-content wrap cf">
          <?php if (!empty($variables['data']['project'])): ?>
            <h1><?php print reset($variables['data']['project']) ?></h1>
          <?php else: ?>
            <h1><?php print $node->title; ?></h1>
          <?php endif; ?>
        </div>
      </div>

      <div id="inner-content" class="wrap cf">
        <h2>Project Information</h2>
        <div class="project-view info d-all project-update-submission ">
          </pre>
          <table>
            <tbody>
              <?php
              function showField($node,$content,$variables, $fieldname) {
                $labels = Array(
"agency_comments" => "Agency comments",
                    'project_completed' => "% Project completed",
                'predicted_project' => 'Predicted project benefit <em>($m, as identified in business case)</em>',
                'predicted_realised' =>'% Predicted project benefit realised <em>($m, as identified in business case)</em>'
                );
                if (!empty($node->{'field_'.$fieldname}['und'][0]['value']) || !empty($variables['data'][$fieldname])) : ?>
                  <tr>
                  <?php if (!empty($content['field_'.$fieldname]['#title'])): ?>
                    <td class="label"><?php print $content['field_'.$fieldname]['#title']; ?></td>
                  <?php else: ?>
                    <td class="label"><?php print $labels[$fieldname] ; ?></td>
                  <?php endif; ?>

                    <?php if (!empty($variables['data'][$fieldname])): ?>
                      <td class="text"><?php print reset($variables['data'][$fieldname]) ?></td>
                    <?php else: ?>
                      <td class="text"><?php print $node->{'field_'.$fieldname}['und'][0]['value']; ?></td>
                    <?php endif; ?>
                  </tr>
               <?php endif;
              }
              function showDateField($node,$content,$variables, $fieldname) {
                $labels = Array(
                    "expected_project" => "Expected project completion date"
                );
                if (!empty($node->{'field_'.$fieldname}['und'][0]['value']) || !empty($variables['data'][$fieldname])) : ?>
                  <tr>
                    <?php if (!empty($content['field_'.$fieldname]['#title'])): ?>
                      <td class="label"><?php print $content['field_'.$fieldname]['#title']; ?></td>
                    <?php else: ?>
                      <td class="label"><?php print $labels[$fieldname] ; ?></td>
                    <?php endif; ?>
                    <?php if (!empty($variables['data'][$fieldname])): ?>
                      <td class="text"><?php print date_format(date_create(reset($variables['data'][$fieldname])), 'd M Y'); ?></td>
                    <?php else: ?>
                      <td class="text"><?php print date_format(date_create($node->{'field_'.$fieldname}['und'][0]['value']), 'd M Y'); ?></td>
                    <?php endif; ?>
                  </tr>
                <?php endif;
              }
              showField($node,$content,$variables, 'government_entity_name');
              showField($node,$content,$variables, 'government_business_unit');
              showField($node,$content,$variables, 'program_name');
              ?>

              <tr><td colspan="2"><div class="dotted-line"></div></td></tr>

                <tr>
                  <td class="label"><?php print t('Project title'); ?></td>
                  <?php if (!empty($variables['data']['project'])
                      && reset($variables['data']['project']) != $node->title) : ?>
                    <td class="text"><?php print reset($variables['data']['project']) ?></td>
                  <?php else: ?>
                    <td class="text"><?php print $node->title; ?></td>
                  <?php endif; ?>

                </tr>

              <?php
              showField($node,$content,$variables, 'brief_project_summary');
              showField($node,$content,$variables, 'project_completed');
              ?>

              <?php if (!empty($node->field_project_status['und'][0]['value'])) : ?>
                <tr>
                  <td class="label"><?php print $content['field_project_status']['#title']; ?></td>
                  <?php if (!empty($variables['data']['project_status'])) : ?>
                    <td class="text"> <?php print ucfirst(reset($variables['data']['project_status'])); ?></td>
                  <?php else: ?>
                    <td class="text"><?php print ucfirst($node->field_project_status['und'][0]['value']); ?></td>
                  <?php endif; ?>
                </tr>
              <?php endif; ?>


              <?php if (!empty($node->field_predicted_project_benefit['und'][0]['value'])) : ?>
                <tr>
                  <td class="label">
                    <?php print ict_project_bracket_italics($content['field_predicted_project_benefit']['#title']); ?></td>
                  <?php if (!empty($variables['data']['predicted_project_benefit'])) : ?>
                    <td class="text">$<?php print ucfirst(reset($variables['data']['predicted_project_benefit'])); ?>m</td>
                  <?php else: ?>
                    <td class="text">$<?php print ucfirst($node->field_predicted_project_benefit['und'][0]['value']); ?>m</td>
                  <?php endif; ?>
                </tr>
              <?php endif;
              showField($node,$content,$variables, 'predicted_realised');

              ?>

              <?php if (!empty($node->field_implementation_partners['und'][0]['value'])) : ?>
                <tr>
                  <td class="label">Implementation Partners?<span>A list of any implementation partners for the project. This includes primary contractors and any formally supporting Government entities.</span></td>
                  <td class="text"><?php
                    $partners = Array();
                    for ($i=0, $count = count($node->field_implementation_partners['und']); $i<$count; $i++){
                      $partners[] = $node->field_implementation_partners['und'][$i]['value'];
                    }
                if (!empty($variables['data']['implementation_partners'])) {
                  $partners = explode(';',reset($variables['data']['implementation_partners']));
                      }
                    print implode(', ',$partners);
                    ?></td>
                </tr>
              <?php endif; ?>

              <?php
              showField($node,$content,$variables, 'internal_fte');
              showField($node,$content,$variables, 'external_fte');
              showDateField($node,$content,$variables, 'start_date');
              showDateField($node,$content,$variables, 'original_completion_date');
              showDateField($node,$content,$variables, 'rebaselined_project_start');
              showDateField($node,$content,$variables, 'rebaselined_project_compl');
              showDateField($node,$content,$variables, 'expected_project');
              ?>


              <?php if (!empty($node->field_project_stage['und'][0]['taxonomy_term']->name)) : ?>
                <tr>
                  <td class="label"><?php print $content['field_project_stage']['#title']; ?></td>
                <?php if (!empty($variables['data']['project_stage'])) : ?>
                  <td class="text"><?php print  ucfirst(reset($variables['data']['project_stage'])); ?></td>
                  <?php else: ?>
                  <td class="text"><?php print $node->field_project_stage['und'][0]['taxonomy_term']->name; ?></td>
                <?php endif; ?>
                </tr>
              <?php endif; ?>
              <?php if (!empty($node->field_project_category['und'][0]['taxonomy_term']->name)) : ?>
                <tr>
                  <td class="label"><?php print $content['field_project_category']['#title']; ?></td>
                <?php if (!empty($variables['data']['project_category'])): ?>
                  <td class="text"><?php print reset($variables['data']['project_category']); ?></td>
                <?php else: ?>
                  <td class="text"><?php print $node->field_project_category['und'][0]['taxonomy_term']->name; ?></td>
                <?php endif; ?>
                </tr>
              <?php endif; ?>

              <?php
              showField($node,$content,$variables, 'expenditure_type');
              showField($node,$content,$variables, 'project_manager');
              showField($node,$content,$variables, 'project_manager_email');
              ?>

              <tr><td colspan="2"><div class="dotted-line"></div></td></tr>
              <?php if (!empty($node->field_total_project_budget['und'][0]['value'])) : ?>
                <tr>
                  <td class="label"><?php print ict_project_bracket_italics($content['field_total_project_budget']['#title']); ?></td>
                <?php if (!empty($variables['data']['total_project_budget'])) : ?>
                  <td class="text">$<?php print reset($variables['data']['total_project_budget']); ?>m</td>
                <?php else: ?>
                  <td class="text">$<?php print ((int)$node->field_total_project_budget['und'][0]['value']); ?>m</td>
                <?php endif; ?>
                </tr>
              <?php endif; ?>
              <tr>
                <td class="label">Original Total project budget by FY <em>($m, predicted & past)</em></td>
                <td class="text">
                  <?php
                  $fci = $node->field_original_total_budget['und'];
                  $fci_cols = array();
                  foreach($fci as $col){
                    $fci_cols[] = field_collection_item_load($col['value']);
                  }
                  ?>
                  <table><tbody><tr><th></th><th>Previous</th><th>Current</th><th>+1</th><th>+2</th><th>+3</th></tr><tr><td>FY (yy/yy)</td>
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
              <?php if (!empty($node->field_rebaselined_total_project['und'][0]['value'])) : ?>
              <tr>
                <td class="label">Rebaselined total project budget <em>($m)</em></td>
                <td class="text">

                    <?php if (!empty($variables['data']['rebaselined_total_project'])): ?>
                      $<?php print reset($variables['data']['rebaselined_total_project']); ?>m
                    <?php else: ?>
                    $<?php print $node->field_rebaselined_total_project['und'][0]['value']; ?>m
                    <?php endif; ?>
                </td>
              </tr>

              <?php endif; ?>
              <?php if (!empty($node->field_rebaselined_total_budget['und'])) {
                $fci = $node->field_rebaselined_total_budget['und'];
                $fci_cols = array();
                foreach($fci as $col){
                  $fci_cols[] = field_collection_item_load($col['value']);
                }
              }
              $total = 0;
              for ($i = 0; $i<5; $i++) {
                $total += $fci_cols[$i]->field_total['und'][0]['value'];
              }
              if ($total) :
                ?>
              <tr>
                <td class="label">Rebaselined Total project budget by FY <em>($m, predicted & past)</em></td>
                <td class="text">
                    <table><tbody><tr><th></th><th>Previous</th><th>Current</th><th>+1</th><th>+2</th><th>+3</th></tr><tr><td>FY (yy/yy)</td>
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
              <?php endif; ?>
              <?php if (!empty($variables['data']['revised_total_project'])): ?>
              <tr>
                <td class="label">Revised total project budget <em>($m)</em></td>
                <td class="text">
                      $<?php print (int)reset($variables['data']['revised_total_project']); ?>m
                </td>
              </tr>
              <?php endif; ?>
              <?php if (!empty($variables['data']['total_project_spend'])): ?>
                <tr>
                  <td class="label">Total project spend to date <em>($m)</em></td>
                  <td class="text">
                    $<?php print (int)reset($variables['data']['total_project_spend']); ?>m
                  </td>
                </tr>
              <?php endif; ?>
              <?php if (!empty($variables['data']['total_project_current'])): ?>
                <tr>
                  <td class="label">Total project spend current Financial Year <em>($m)</em></td>
                  <td class="text">
                    $<?php print (int)reset($variables['data']['total_project_current']); ?>m
                  </td>
                </tr>
              <?php endif;
              $fybudget = Array();
              $years= Array();
              $total = 0;
              foreach ($variables['data'] as $key => $value) {
                if (strpos($key,'predicted_budget') !== false) {
                  $keyParts = explode('_',str_replace('predicted_budget_','',$key));
                  $year = $keyParts[0];
                  $metric= $keyParts[1];
                  $fybudget[$year][$metric] = reset($value);
                  if ($metric == 'total') {
                    $total += reset($value);
                  }
                  if (array_search($year,$years) === false) {
                    $years[] = $year;
                  }
                }
              }
              sort($years);
              if ($total):
              ?>
              <tr>
                <td class="label">Five year predicted project budget <em>($m)</em></td>
                <td class="text">

                  <table><tbody><tr><th></th><th>Previous</th><th>Current</th><th>+1</th><th>+2</th><th>+3</th></tr><tr><td>FY (yy/yy)</td>
                      <?php
                      foreach ($years as $year) {
                        print ('<td>'.$year[2].$year[3].'/'.$year[4].$year[5].'</td>');
                      }
                      ?>
                    </tr><tr><td>Opex</td>
                      <?php
                      foreach ($years as $year) {
                        print ('<td>'. $fybudget[$year]['opex'].'</td>');
                      }
                      ?>
                    </tr><tr><td>Capex</td>
                      <?php
                      foreach ($years as $year) {
                        print ('<td>'. $fybudget[$year]['capex'].'</td>');
                      }
                      ?>
                    </tr><tr><td>Total</td>
                      <?php
                      foreach ($years as $year) {
                        print ('<td>'. $fybudget[$year]['total'].'</td>');
                      }
                      ?>
                    </tr></tbody></table>
                </td>
              </tr>
              <?php endif; ?>



            </tbody>
          </table>

        </div>

      </div>
    </div>
  <?php endif; ?>

</div></div> <!-- /node-inner, /node -->
