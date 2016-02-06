<div class="page-title dotbg">
  <div class="inner-title-content wrap cf">
    <h1><?php print t('Review project form');?></h1>
  </div>
</div>
<div id="inner-content" class="wrap cf">
  <div class="project-view info d-all project-update-submission">
      <table>
        <tbody>
          <tr>
            <td class="label"><?php print t('Government entity name');?></td>
            <td class="text"><?php print $form_state['values']['field_government_entity_name']['und'][0]['value'];?></td>
          </tr>

        <tr>
          <td class="label"><?php print t('Government entity business group, division, & branch');?></td>
          <td class="text"><?php print $form_state['values']['field_government_business_unit']['und'][0]['value'];?></td>
        </tr>

          <tr>
            <td class="label"><?php print t('Which Outcome and Programme does this project support?');?></td>
            <td class="text"><?php print $form_state['values']['field_program_name']['und'][0]['value'];?></td>
          </tr>

          <tr>
            <td class="label"><?php print t('Project title');?></td>
            <td class="text"><?php print $form_state['values']['title'];?></td>
          </tr>

          <tr>
            <td class="label"><?php print t('Project description');?></td>
            <td class="text"><?php print $form_state['values']['field_brief_project_summary']['und'][0]['value'];?></td>
          </tr>

          <tr>
            <td class="label"><?php print t('Implementation Partners?');?></td>
            <td class="text">
              <?php foreach($form_state['values']['field_implementation_partners']['und'] as $key=>$partners):?>
                <?php
                if($key !== 'add_more') {
                  print $partners['value'] . '<br>';
                }
                ;?>
              <?php endforeach;?>
            </td>
          </tr>

          <tr>
            <td class="label"><?php print t('Internal FTE');?></td>
            <td class="text"><?php print $form_state['values']['field_internal_fte']['und'][0]['value'];?></td>
          </tr>

          <tr>
            <td class="label"><?php print t('External FTE');?></td>
            <td class="text"><?php print $form_state['values']['field_external_fte']['und'][0]['value'];?></td>
          </tr>

          <tr>
            <td class="label"><?php print t('Original project start date');?></td>
            <td class="text"><?php
              $date = $form_state['values']['field_start_date']['und'][0]['value'];
              print ($date) ? date('d/M/Y', strtotime($date)): '';?></td>
          </tr>

          <tr>
            <td class="label"><?php print t('Original project completion date');?></td>
            <td class="text"><?php
              $date = $form_state['values']['field_original_completion_date']['und'][0]['value'];
              print ($date) ? date('d/M/Y', strtotime($date)): '';?></td>
          </tr>

          <tr>
            <td class="label"><?php print t('Rebaselined project start date');?></td>
            <td class="text"><?php
              $date = $form_state['values']['field_rebaselined_project_start']['und'][0]['value'];
              print ($date) ? date('d/M/Y', strtotime($date)): '';?></td>
          </tr>

          <tr>
            <td class="label"><?php print t('Rebaselined project completion date');?></td>
            <td class="text"><?php
              $date = $form_state['values']['field_rebaselined_project_compl']['und'][0]['value'];
              print ($date) ? date('d/M/Y', strtotime($date)): '';?></td>
          </tr>

          <tr>
            <td class="label"><?php print t('Project Stage');?></td>
            <td class="text"><?php
              $name_stage = taxonomy_term_load($form_state['values']['field_project_stage']['und'][0]['tid']);
              print $name_stage->name;?></td>
          </tr>

          <tr>
            <td class="label"><?php print t('Project category');?></td>
            <td class="text"><?php
              $name_cat = taxonomy_term_load($form_state['values']['field_project_category']['und'][0]['tid']);
              print $name_cat->name;?></td>
          </tr>

          <tr>
            <td class="label"><?php print t('Expenditure type');?></td>
            <td class="text"><?php print $form_state['values']['field_expenditure_type']['und'][0]['value'];?></td>
          </tr>


          <tr>
            <td class="label"><?php print t('Project manager');?></td>
            <td class="text"><?php print $form_state['values']['field_project_manager']['und'][0]['value'];?></td>
          </tr>

          <tr>
            <td class="label"><?php print t('Project manager email');?></td>
            <td class="text"><?php print $form_state['values']['field_project_manager_email']['und'][0]['email'];?></td>
          </tr>

          <tr>
            <td class="label"><?php print t('Original total project budget ($m)');?></td>
            <td class="text"><?php print $form_state['values']['field_total_project_budget']['und'][0]['value'];?></td>
          </tr>

        <?php $budget = $form_state['values']['field_original_total_budget'][LANGUAGE_NONE];?>
        <tr>
          <td class="label"><?php print t('Original Total project budget by FY ($m, predicted & past)');?></td>
          <td class="text">
            <table>
              <tbody>
              <tr>
                <th></th>
                <th>Previous</th>
                <th>Current</th>
                <th>1</th>
                <th>2</th>
                <th>3</th>
              </tr>
              <tr>
                <td>FY (yy/yy)</td>
                <?php foreach($budget as $b):?>
                    <td><?php print $b['field_year']['und'][0]['value'];?></td>
                <?php endforeach;?>
              </tr>
              <tr>
                <td>Opex</td>
                <?php foreach($budget as $row):?>
                  <td><?php print $row['field_opex'][LANGUAGE_NONE][0]['value'];?></td>
                <?php endforeach;?>
              </tr>
              <tr>
                <td>Capex</td>
                <?php foreach($budget as $row):?>
                  <td><?php print $row['field_capex'][LANGUAGE_NONE][0]['value'];?></td>
                <?php endforeach;?>
              </tr>
              <tr>
                <td>Total</td>
                <?php foreach($budget as $row):?>
                  <td><?php print $row['field_total'][LANGUAGE_NONE][0]['value'];?></td>
                <?php endforeach;?>
              </tr>
              </tbody>
            </table>
          </td>
        </tr>

          <tr>
            <td class="label"><?php print t('Rebaselined total project budget ($m)');?></td>
            <td class="text"><?php print $form_state['values']['field_rebaselined_total_project']['und'][0]['value'];?></td>
          </tr>

          <?php $budget_r = $form_state['values']['field_rebaselined_total_budget'][LANGUAGE_NONE];?>
          <tr>
            <td class="label"><?php print t('Rebaselined Total project budget by FY ($m, predicted & past)');?></td>
            <td class="text">
              <table>
                <tbody>
                <tr>
                  <th></th>
                  <th>Previous</th>
                  <th>Current</th>
                  <th>1</th>
                  <th>2</th>
                  <th>3</th>
                </tr>
                <tr>
                  <td>FY (yy/yy)</td>
                  <?php foreach($budget_r as $b):?>
                    <td><?php print $b['field_year']['und'][0]['value'];?></td>
                  <?php endforeach;?>
                </tr>
                <tr>
                  <td>Opex</td>
                  <?php foreach($budget_r as $row):?>
                    <td><?php print $row['field_opex'][LANGUAGE_NONE][0]['value'];?></td>
                  <?php endforeach;?>
                </tr>
                <tr>
                  <td>Capex</td>
                  <?php foreach($budget_r as $row):?>
                    <td><?php print $row['field_capex'][LANGUAGE_NONE][0]['value'];?></td>
                  <?php endforeach;?>
                </tr>
                <tr>
                  <td>Total</td>
                  <?php foreach($budget_r as $row):?>
                    <td><?php print $row['field_total'][LANGUAGE_NONE][0]['value'];?></td>
                  <?php endforeach;?>
                </tr>
                </tbody>
              </table>
            </td>
          </tr>

          <tr>
            <td class="label"><?php print t('Predicted project benefit ($m, as identified in business case)');?></td>
            <td class="text"><?php print $form_state['values']['field_predicted_project_benefit']['und'][0]['value'];?></td>
          </tr>


          <tr>
            <td class="label"><?php print t('Project status');?></td>
            <td class="text"><?php print $form_state['values']['field_project_status']['und'][0]['value'];?></td>
          </tr>

          <tr>
            <td class="label"><?php print t('Users');?></td>
            <td class="text">
              <?php foreach($form_state['values']['field_project_users'][LANGUAGE_NONE] as $user):?>
                <?php
                 if($user['uid']) {
                   $profile = user_load($user['uid']);
                   print $profile->name . '<br>';
                 }
                ?>
              <?php endforeach;?>
            </td>
          </tr>


        </tbody>
      </table>

      <div class="submit">
        <a class="general-button back" href="#"><span>Edit</span></a>
        <?php
        $form_s = drupal_get_form('ict_project_review_project_form');
        print drupal_render($form_s);?>
      </div>

    </div>
</div>

