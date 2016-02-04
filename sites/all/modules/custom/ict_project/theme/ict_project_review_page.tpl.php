<div class="page-title dotbg">
  <div class="inner-title-content wrap cf">
    <h1><?php print t('Review form');?></h1>
  </div>
</div>
<div id="inner-content" class="wrap cf">
  <h2><?php print t('Mid financial year project reporting');?></h2>
  <div class="project-view info d-all project-update-submission">
      <table>
        <tbody>
          <tr>
            <td class="label"><?php print t('Project name');?></td>
            <td class="text"><?php print $form_state['values']['field_mid_project_name']['und'][0]['value'];?></td>
          </tr>

        <tr>
          <td class="label"><?php print t('Project Stage');?></td>
          <td class="text"><?php print $form_state['values']['field_mid_project_stage']['und'][0]['value'];?></td>
        </tr>

          <tr>
            <td class="label"><?php print t('Project manager');?></td>
            <td class="text"><?php print $form_state['values']['field_mid_project_manager']['und'][0]['value'];?></td>
          </tr>

          <tr>
            <td class="label"><?php print t('Project manager email');?></td>
            <td class="text"><?php print $form_state['values']['field_mid_project_manager_email']['und'][0]['value'];?></td>
          </tr>

          <tr>
            <td class="label"><?php print t('Expected project completion date');?></td>
            <td class="text"><?php
              $date = $form_state['values']['field_mid_expected_project']['und'][0]['value'];
              print ($date) ? date('d/M/Y', strtotime($date)): '';?></td>
          </tr>

          <tr>
            <td class="label"><?php print t('Revised total project budget ($m)');?></td>
            <td class="text"><?php print $form_state['values']['field_mid_revised_total_project']['und'][0]['value'];?></td>
          </tr>

          <tr>
            <td class="label"><?php print t('Total project spend to date ($m)');?></td>
            <td class="text"><?php print $form_state['values']['field_mid_total_project_spend']['und'][0]['value'];?></td>
          </tr>

          <tr>
            <td class="label"><?php print t('Total project spend current Financial Year ($m)');?></td>
            <td class="text"><?php print $form_state['values']['field_mid_total_project_current']['und'][0]['value'];?></td>
          </tr>

          <tr>
            <td class="label"><?php print t('% Project completed');?></td>
            <td class="text"><?php print $form_state['values']['field_mid_project_completed']['und'][0]['value'];?></td>
          </tr>

          <tr>
            <td class="label"><?php print t('Predicted project benefit ($m, as identified in business case)');?></td>
            <td class="text"><?php print $form_state['values']['field_mid_predicted_project']['und'][0]['value'];?></td>
          </tr>


          <tr>
            <td class="label"><?php print t('% Predicted project benefit realised ($m, as identified in business case)');?></td>
            <td class="text"><?php print $form_state['values']['field_mid_predicted_project_real']['und'][0]['value'];?></td>
          </tr>

          <tr>
            <td class="label"><?php print t('Internal FTE');?></td>
            <td class="text"><?php print $form_state['values']['field_mid_internal_fte']['und'][0]['value'];?></td>
          </tr>


          <tr>
            <td class="label"><?php print t('External FTE');?></td>
            <td class="text"><?php print $form_state['values']['field_mid_external_fte']['und'][0]['value'];?></td>
          </tr>

          <tr>
            <td class="label"><?php print t('Project status');?></td>
            <td class="text"><?php print $form_state['values']['field_mid_project_status']['und'][0]['value'];?></td>
          </tr>

          <tr>
            <td class="label"><?php print t('Agency comments');?></td>
            <td class="text"><?php print $form_state['values']['field_mid_agency_comments']['und'][0]['value'];?></td>
          </tr>
        </tbody>
      </table>

      <div class="submit">
        <a class="general-button back" href="#"><span>Edit</span></a>
        <?php print render(drupal_get_form('ict_project_review_form'));?>
      </div>

    </div>
</div>

