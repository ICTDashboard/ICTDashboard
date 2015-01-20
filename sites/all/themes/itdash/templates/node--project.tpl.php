<div class="node-<?php print $node->nid; ?> node<?php if ($sticky) { print ' sticky'; } ?><?php if (!$status) { print ' node-unpublished'; } ?> clearfix thing"><div class="node-inner">

  <?php if ($page == 1 || $page == 0 && $teaser == 0): ?>

    <div class="full-node clearfix">
      <div class="page-title dotbg">
        <div class="inner-title-content wrap cf">
          <h1><?php print t('Service Delivery Reform ICT Project'); ?></h1>
        </div>
      </div>

      <div id="inner-content" class="wrap cf">
        <h2>Project Information</h2>
        <div class="project-view info d-all project-update-submission ">

          </pre>
          <table>
            <tbody>
              <?php if (!empty($node->field_government_entity_name['und'][0]['value'])) : ?>
                <tr>
                  <td class="label"><?php print $content['field_government_entity_name']['#title']; ?></td>
                  <td class="text"><?php print $node->field_government_entity_name['und'][0]['value']; ?></td>
                </tr>
              <?php endif; ?>
              <?php if (!empty($node->field_government_business_unit['und'][0]['value'])) : ?>
                <tr>
                  <td class="label"><?php print $content['field_government_business_unit']['#title']; ?></td>
                  <td class="text"><?php print $node->field_government_business_unit['und'][0]['value']; ?></td>
                </tr>
              <?php endif; ?>
              <?php if (!empty($node->field_program_name['und'][0]['value'])) : ?>
                <tr>
                  <td class="label"><?php print ict_project_bracket_italics($content['field_program_name']['#title']); ?></td>
                  <td class="text"><?php print $node->field_program_name['und'][0]['value']; ?></td>
                </tr>
              <?php endif; ?>
              <tr><td colspan="2"><div class="dotted-line"></div></td></tr>
              <?php if (!empty($node->title)) : ?>
                <tr>
                  <td class="label"><?php print t('Project title'); ?></td>
                  <td class="text"><?php print $node->title; ?></td>
                </tr>
              <?php endif; ?>
              <?php if (!empty($node->field_brief_project_summary['und'][0]['value'])) : ?>
                <tr>
                  <td class="label"><?php print $content['field_brief_project_summary']['#title']; ?></td>
                  <td class="text"><?php print $node->field_brief_project_summary['und'][0]['value']; ?></td>
                </tr>
              <?php endif; ?>

              <?php if (!empty($node->field_implementation_partners['und'][0]['value'])) : ?>
                <tr>
                  <td class="label">Implementation Partners?<span>A list of any implementation partners for the project. This includes primary contractors and any formally supporting Government entities.</span></td>
                  <td class="text"><?php
                    for ($i=0, $count = count($node->field_implementation_partners['und']); $i<$count; $i++){
                      if ($i) print ', ';
                      print $node->field_implementation_partners['und'][$i]['value'];
                    }

                    ?></td>
                </tr>
              <?php endif; ?>

              <?php if (!empty($node->field_internal_fte['und'][0]['value'])) : ?>
                <tr>
                  <td class="label"><?php print $content['field_internal_fte']['#title']; ?></td>
                  <td class="text"><?php print $node->field_internal_fte['und'][0]['value']; ?></td>
                </tr>
              <?php endif; ?>
              <?php if (!empty($node->field_external_fte['und'][0]['value'])) : ?>
                <tr>
                  <td class="label"><?php print $content['field_external_fte']['#title']; ?></td>
                  <td class="text"><?php print $node->field_external_fte['und'][0]['value']; ?></td>
                </tr>
              <?php endif; ?>

              <?php if (!empty($node->field_start_date['und'][0]['value'])) : ?>
                <tr>
                  <td class="label"><?php print $content['field_start_date']['#title']; ?></td>
                  <td class="text"><?php print date_format(date_create($node->field_start_date['und'][0]['value']), 'd M Y'); ?></td>
                </tr>
              <?php endif; ?>
              <?php if (!empty($node->field_original_completion_date['und'][0]['value'])) : ?>
                <tr>
                  <td class="label"><?php print $content['field_original_completion_date']['#title']; ?></td>
                  <td class="text"><?php print date_format(date_create($node->field_original_completion_date['und'][0]['value']), 'd M Y'); ?></td>
                </tr>
              <?php endif; ?>
              <?php if (!empty($node->field_rebaselined_project_start['und'][0]['value'])) : ?>
                <tr>
                  <td class="label"><?php print $content['field_rebaselined_project_start']['#title']; ?></td>
                  <td class="text"><?php print date_format(date_create($node->field_rebaselined_project_start['und'][0]['value']), 'd M Y'); ?></td>
                </tr>
              <?php endif; ?>
              <?php if (!empty($node->field_rebaselined_project_compl['und'][0]['value'])) : ?>
                <tr>
                  <td class="label"><?php print $content['field_rebaselined_project_compl']['#title']; ?></td>
                  <td class="text"><?php print date_format(date_create($node->field_rebaselined_project_compl['und'][0]['value']), 'd M Y'); ?></td>
                </tr>
              <?php endif; ?>
              <?php if (!empty($node->field_project_stage['und'][0]['taxonomy_term']->name)) : ?>
                <tr>
                  <td class="label"><?php print $content['field_project_stage']['#title']; ?></td>
                  <td class="text"><?php print $node->field_project_stage['und'][0]['taxonomy_term']->name; ?></td>
                </tr>
              <?php endif; ?>
              <?php if (!empty($node->field_project_category['und'][0]['taxonomy_term']->name)) : ?>
                <tr>
                  <td class="label"><?php print $content['field_project_category']['#title']; ?></td>
                  <td class="text"><?php print $node->field_project_category['und'][0]['taxonomy_term']->name; ?></td>
                </tr>
              <?php endif; ?>

              <?php if (!empty($node->field_expenditure_type['und'][0]['value'])) : ?>
                <tr>
                  <td class="label"><?php print $content['field_expenditure_type']['#title']; ?></td>
                  <td class="text"><?php print $node->field_expenditure_type['und'][0]['value']; ?></td>
                </tr>
              <?php endif; ?>

              <?php if (!empty($node->field_project_manager['und'][0]['value'])) : ?>
                <tr>
                  <td class="label"><?php print $content['field_project_manager']['#title']; ?></td>
                  <td class="text"><?php print $node->field_project_manager['und'][0]['value']; ?></td>
                </tr>
              <?php endif; ?>
              <?php if (!empty($node->field_project_manager_email['und'][0]['email'])) : ?>
                <tr>
                  <td class="label"><?php print $content['field_project_manager_email']['#title']; ?></td>
                  <td class="text"><?php print $node->field_project_manager_email['und'][0]['email']; ?></td>
                </tr>
              <?php endif; ?>
              <tr><td colspan="2"><div class="dotted-line"></div></td></tr>
              <?php if (!empty($node->field_total_project_budget['und'][0]['value'])) : ?>
                <tr>
                  <td class="label"><?php print ict_project_bracket_italics($content['field_total_project_budget']['#title']); ?></td>
                  <td class="text">$<?php print ((int)$node->field_total_project_budget['und'][0]['value']); ?>m</td>
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

              <tr>
                <td class="label">Rebaselined total project budget <em>($m)</em></td>
                <td class="text">
                  <?php if (!empty($node->field_rebaselined_total_project['und'][0]['value'])) : ?>
                    $<?php print $node->field_rebaselined_total_project['und'][0]['value']; ?>m
                  <?php endif; ?>
                </td>
              </tr>

              <tr>
                <td class="label">Rebaselined Total project budget by FY <em>($m, predicted & past)</em></td>
                <td class="text">
                    <?php
                    $fci = $node->field_rebaselined_total_budget['und'];
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
              <?php if (!empty($node->field_predicted_project_benefit['und'][0]['value'])) : ?>
                <tr>
                  <td class="label">
                    <?php print ict_project_bracket_italics($content['field_predicted_project_benefit']['#title']); ?></td>
                  <td class="text">$<?php print ucfirst($node->field_predicted_project_benefit['und'][0]['value']); ?>m</td>
                </tr>
              <?php endif; ?>
              <?php if (!empty($node->field_project_status['und'][0]['value'])) : ?>
                <tr>
                  <td class="label"><?php print $content['field_project_status']['#title']; ?></td>
                  <td class="text"><?php print ucfirst($node->field_project_status['und'][0]['value']); ?></td>
                </tr>
              <?php endif; ?>

            </tbody>
          </table>
        </div>

      </div>
    </div>
  <?php endif; ?>

</div></div> <!-- /node-inner, /node -->
