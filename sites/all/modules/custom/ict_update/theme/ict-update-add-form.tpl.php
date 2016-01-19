<div id="inner-content" class="wrap cf">
  <h2>  This is for the first view of a newly created update draft...</h2>
  <p>This one should:</p>
  <p>Show non editable baseline fileds for node 1769</p>
  <p>Show editable update fields.</p>
  <p>Not have any data entered for the update fields.</p>

  <p>Provide a link to  <strong><a href="/?path=preview_update_draft&amp;nid=1769">save and go to update preview page</a></strong> or <strong><a href="http://itdash.lws.links.com.au/projects">cancel and return to projects  list</a></strong>.</p>

  <h2>&nbsp;</h2>
  <h2>&nbsp;</h2>
  <h2>&nbsp;</h2>
  <h2>About this form</h2>
  <p>The information and fields below provide you with a view on how project managers will be able to see previously entered baseline data and data from a previous update, while also having the opportunity to enter details for a new update.</p>
  <p>This sandpit form is not functional and does not attempt to validate data that is entered.</p>
  <p>The form has not yet been optimised for older browsers. If you have difficulty you can <a href="./Sandpit_form_demo.pdf" target="_blank">download a PDF preview</a> and review the <a href="./Dashboard_Data_Definitions.pdf" target="_blank">associated data definition document</a> for reference.<br>
  </p>
  <h2>Update data</h2>
  <h3>Basic project information</h3>
  <div class="project-update-submission d-all">
    <div class="row">
      <div class="label">Government Entity Name <a href="javascript:void(0);" class="tooltip"><i class="tooltip-icon"></i><span class="tooltip-content">The Government department or entity responsible for leading the project.</span></a></div>
      <div class="text">
        Lorem Ipsum
      </div>
    </div>
    <div class="row">
      <div class="label">Portfolio Name<a href="javascript:void(0);" class="tooltip"><i class="tooltip-icon"></i><span class="tooltip-content">The Portfolio for which the department or entity belongs.</span></a></div>
      <div class="text">
        Ut Vinctus project
      </div>
    </div>
    <div class="row">
      <div class="label">Project Title<a href="javascript:void(0);" class="tooltip"><i class="tooltip-icon"></i><span class="tooltip-content">The official full name of the project, excluding acronyms.</span></a></div>
      <div class="text">
        Aliquam aliquet ornare urna
      </div>
    </div>
    <div class="row">
      <div class="label">Programme Name<a href="javascript:void(0);" class="tooltip"><i class="tooltip-icon"></i><span class="tooltip-content">The official government programme that the project supports. Can be the same as the Project Title.</span></a></div>
      <div class="text">
        Sed congue metus in metus
      </div>
    </div>
    <div class="row">
      <div class="label">Project Summary and Objectives</div>
      <div class="text">
        Quisque consectetur viverra mattis. Nam vehicula condimentum augue a sodales. Donec fringilla vel mauris eget varius. Mauris sit amet ligula et orci rhoncus ultricies rhoncus a sapien. Nam auctor ullamcorper elit sit amet hendrerit. Aenean eu mollis felis. Nulla facilisi. Sed sed hendrerit diam. Ut laoreet vel neque ut congue. In a tempus mauris, sed ullamcorper metus. Aenean auctor consectetur sapien vitae varius. Proin magna est, sodales sed urna non, sodales gravida magna.
      </div>
    </div>
    <div class="dotted-line"></div>
    <h3>User information</h3>
    <div class="row">
      <div class="label">Senior Responsibile Officer Name<a href="javascript:void(0);" class="tooltip"><i class="tooltip-icon"></i><span class="tooltip-content">The name of the Senior Responsible Officer (SRO) for the delivery of the project. <em>(Not published)</em>&gt;</span></a></div>
      <div class="text">
        Jordan Ibe
      </div>
    </div>
    <div class="row">
      <div class="label">Senior Responsibile Officer Position<a href="javascript:void(0);" class="tooltip"><i class="tooltip-icon"></i><span class="tooltip-content">The position (including group, division &amp; branch) of the Senior Responsible Officer. <em>(Not published)</em></span></a></div>
      <div class="text">
        Suspendisse facilisis erat nisi
      </div>
    </div>
    <div class="row">
      <div class="label">Departmental Administrators<a href="javascript:void(0);" class="tooltip"><i class="tooltip-icon"></i><span class="tooltip-content">Departmental Administrators can create and assign Data Approvers to a project. They can not be Approvers or Editors within the same project.</span></a><a href="javascript:void(0);" class="edit-btn">Edit</a></div>
      <div class="text">
        <a class="email-value" href="mailto:jordan.henderson@email.com.au">jordan.henderson@email.com.au</a>
        <a class="email-value" href="mailto:joe.allen@email.com.au">joe.allen@email.com.au</a>
      </div>
    </div>
    <div class="row">
      <div class="label">Data Approvers<a href="javascript:void(0);" class="tooltip"><i class="tooltip-icon"></i><span class="tooltip-content">Data Approvers can review, approve or reject baseline and update submissions once submitted for approval. They can not be Departmental Administrators or Editors within the same project.</span></a><a href="javascript:void(0);" class="edit-btn">Edit</a></div>
      <div class="text">
        <a class="email-value" href="mailto:joe.gomez@email.com.au">joe.gomez@email.com.au</a>
      </div>
    </div>
    <div class="row">
      <div class="label">Data Editors<a href="javascript:void(0);" class="tooltip"><i class="tooltip-icon"></i><span class="tooltip-content">Data Editors can review, edit and submit baseline and update submissions for approval. They can not be Departmental Administrators or Approvers within the same project.</span></a><a href="javascript:void(0);" class="edit-btn">Edit</a></div>
      <div class="text">
        <a class="email-value" href="mailto:adam.lallana@email.com.au">adam.lallana@email.com.au</a>
      </div>
    </div>
    <div class="dotted-line"></div>
    <h3>Costs, Benefits and Timings</h3>
    <div class="row">
      <div class="label"><?php print $form['field_project_stage']['und']['#title']; ?></div>
      <div class="text"><?php print drupal_render($form['field_project_stage']); ?></div>
    </div>
    <div class="row">
      <div class="label">Original approved start date </div>
      <div class="text">10/2013</div>
    </div>
    <div class="row">
      <div class="label">Original approved completion date </div>
      <div class="text">10/2018</div>
    </div>
    <div class="row">
      <div class="label"><?php print $form['field_expected_completion_date']['und']['#title']; ?><a href="javascript:void(0);" class="tooltip"><i class="tooltip-icon"></i><span class="tooltip-content">The current expected completion date of the project.</span></a></div>
      <div class="text popup-radio"><?php print drupal_render($form['field_expected_completion_date']); ?></div>
    </div>
    <div class="row">
      <div class="label"><?php print $form['field_forecast_level_of_project_']['und']['#title']; ?><a href="javascript:void(0);" class="tooltip"><i class="tooltip-icon"></i><span class="tooltip-content">The percentage of work forecasted to be completed at the current update.</span></a></div>
      <div class="text"><?php print drupal_render($form['field_forecast_level_of_project_']); ?></div>
    </div>
    <div class="row">
      <div class="label"><?php print $form['field_actual_level_of_project_co']['und']['#title']; ?><a href="javascript:void(0);" class="tooltip"><i class="tooltip-icon"></i><span class="tooltip-content">The actual percentage of work completed at the current update.</span></a></div>
      <div class="text">
        <?php print drupal_render($form['field_actual_level_of_project_co']); ?>
      </div>
    </div>
    <div class="row">
      <div class="label">Project Budget by Financial Year</div>
      <div class="text">
        <table id="field_end_predicted_budget" style="max-width:100%;">
          <tbody>
          <tr>
            <th>FY</th><th>
              <div style="display: none;">
                <div class="field-type-text field-name-field-predicted-year field-widget-text-textfield form-wrapper" id="edit-field-end-predicted-budget-und-0-field-predicted-year"><div id="field-end-predicted-budget-und-0-field-predicted-year-add-more-wrapper"><div class="form-item form-type-textfield form-item-field-end-predicted-budget-und-0-field-predicted-year-und-0-value">
                      <label class="element-invisible" for="edit-field-end-predicted-budget-und-0-field-predicted-year-und-0-value">Year </label>
                      <input class="text-full form-text" type="text" id="edit-field-end-predicted-budget-und-0-field-predicted-year-und-0-value" name="field_end_predicted_budget[und][0][field_predicted_year][und][0][value]" value="13/14" size="60" maxlength="255">
                    </div>
                  </div></div>          </div>
              13/14        </th>
            <th>
              <div style="display: none;">
                <div class="field-type-text field-name-field-predicted-year field-widget-text-textfield form-wrapper" id="edit-field-end-predicted-budget-und-1-field-predicted-year"><div id="field-end-predicted-budget-und-1-field-predicted-year-add-more-wrapper"><div class="form-item form-type-textfield form-item-field-end-predicted-budget-und-1-field-predicted-year-und-0-value">
                      <label class="element-invisible" for="edit-field-end-predicted-budget-und-1-field-predicted-year-und-0-value">Year </label>
                      <input class="text-full form-text" type="text" id="edit-field-end-predicted-budget-und-1-field-predicted-year-und-0-value" name="field_end_predicted_budget[und][1][field_predicted_year][und][0][value]" value="14/15" size="60" maxlength="255">
                    </div>
                  </div></div>          </div>
              14/15        </th>
            <th>
              <div style="display: none;">
                <div class="field-type-text field-name-field-predicted-year field-widget-text-textfield form-wrapper" id="edit-field-end-predicted-budget-und-2-field-predicted-year"><div id="field-end-predicted-budget-und-2-field-predicted-year-add-more-wrapper"><div class="form-item form-type-textfield form-item-field-end-predicted-budget-und-2-field-predicted-year-und-0-value">
                      <label class="element-invisible" for="edit-field-end-predicted-budget-und-2-field-predicted-year-und-0-value">Year </label>
                      <input class="text-full form-text" type="text" id="edit-field-end-predicted-budget-und-2-field-predicted-year-und-0-value" name="field_end_predicted_budget[und][2][field_predicted_year][und][0][value]" value="15/16" size="60" maxlength="255">
                    </div>
                  </div></div>          </div>
              15/16        </th>
            <th>
              <div style="display: none;">
                <div class="field-type-text field-name-field-predicted-year field-widget-text-textfield form-wrapper" id="edit-field-end-predicted-budget-und-3-field-predicted-year"><div id="field-end-predicted-budget-und-3-field-predicted-year-add-more-wrapper"><div class="form-item form-type-textfield form-item-field-end-predicted-budget-und-3-field-predicted-year-und-0-value">
                      <label class="element-invisible" for="edit-field-end-predicted-budget-und-3-field-predicted-year-und-0-value">Year </label>
                      <input class="text-full form-text" type="text" id="edit-field-end-predicted-budget-und-3-field-predicted-year-und-0-value" name="field_end_predicted_budget[und][3][field_predicted_year][und][0][value]" value="16/17" size="60" maxlength="255">
                    </div>
                  </div></div>          </div>
              16/17        </th>
            <th>
              <div style="display: none;">
                <div class="field-type-text field-name-field-predicted-year field-widget-text-textfield form-wrapper" id="edit-field-end-predicted-budget-und-4-field-predicted-year"><div id="field-end-predicted-budget-und-4-field-predicted-year-add-more-wrapper"><div class="form-item form-type-textfield form-item-field-end-predicted-budget-und-4-field-predicted-year-und-0-value">
                      <label class="element-invisible" for="edit-field-end-predicted-budget-und-4-field-predicted-year-und-0-value">Year </label>
                      <input class="text-full form-text" type="text" id="edit-field-end-predicted-budget-und-4-field-predicted-year-und-0-value" name="field_end_predicted_budget[und][4][field_predicted_year][und][0][value]" value="17/18" size="60" maxlength="255">
                    </div>
                  </div></div>          </div>
              17/18
            </th></tr>
          <tr class="sum">
            <td><div class="label" style="color:black; margin:0; font-weight:normal">Project Budget<a href="javascript:void(0);" class="tooltip"><i class="tooltip-icon"></i><span class="tooltip-content">Annual budgeted funding for each financial year of the project, agreed by Cabinet including any additional funding from other sources.
  </span></a>($m)<em>original 01/07/13</em></div></td>
            <td data-sum="0" class="opex"><div class="field-type-number-decimal field-name-field-predicted-opex field-widget-number form-wrapper" id="edit-field-end-predicted-budget-und-0-field-predicted-opex3">
                <div id="field-end-predicted-budget-und-0-field-predicted-opex-add-more-wrapper3">
                  <div class="form-item form-type-textfield form-item-field-end-predicted-budget-und-0-field-predicted-opex-und-0-value">
                    <label for="edit-field-end-predicted-budget-und-0-field-predicted-opex-und-0-value2">$10 </label>
                  </div>
                </div>
              </div></td>
            <td data-sum="1" class="opex"><div class="field-type-number-decimal field-name-field-predicted-opex field-widget-number form-wrapper" id="edit-field-end-predicted-budget-und-1-field-predicted-opex3">
                <div id="field-end-predicted-budget-und-1-field-predicted-opex-add-more-wrapper3">
                  <div class="form-item form-type-textfield form-item-field-end-predicted-budget-und-1-field-predicted-opex-und-0-value">
                    <label for="edit-field-end-predicted-budget-und-1-field-predicted-opex-und-0-value3">$12 </label>
                  </div>
                </div>
              </div></td>
            <td data-sum="2" class="opex"><div class="field-type-number-decimal field-name-field-predicted-opex field-widget-number form-wrapper" id="edit-field-end-predicted-budget-und-2-field-predicted-opex3">
                <div id="field-end-predicted-budget-und-2-field-predicted-opex-add-more-wrapper3">
                  <div class="form-item form-type-textfield form-item-field-end-predicted-budget-und-2-field-predicted-opex-und-0-value">
                    <label for="edit-field-end-predicted-budget-und-2-field-predicted-opex-und-0-value3">$7 </label>
                  </div>
                </div>
              </div></td>
            <td data-sum="3" class="opex"><div class="field-type-number-decimal field-name-field-predicted-opex field-widget-number form-wrapper" id="edit-field-end-predicted-budget-und-3-field-predicted-opex3">
                <div id="field-end-predicted-budget-und-3-field-predicted-opex-add-more-wrapper3">
                  <div class="form-item form-type-textfield form-item-field-end-predicted-budget-und-3-field-predicted-opex-und-0-value">
                    <label for="edit-field-end-predicted-budget-und-3-field-predicted-opex-und-0-value3">$7 </label>
                  </div>
                </div>
              </div></td>
            <td data-sum="4" class="opex"><div class="field-type-number-decimal field-name-field-predicted-opex field-widget-number form-wrapper" id="edit-field-end-predicted-budget-und-4-field-predicted-opex3">
                <div id="field-end-predicted-budget-und-4-field-predicted-opex-add-more-wrapper2">
                  <div class="form-item form-type-textfield form-item-field-end-predicted-budget-und-4-field-predicted-opex-und-0-value">
                    <label for="edit-field-end-predicted-budget-und-4-field-predicted-opex-und-0-value2">$4 </label>
                  </div>
                </div>
              </div></td>
          </tr>
          <tr class="sum">
            <td><div class="label" style="color:black; margin:0; font-weight:normal">Project Budget<a href="javascript:void(0);" class="tooltip"><i class="tooltip-icon"></i><span class="tooltip-content">Annual budgeted funding for each financial year of the project, agreed by Cabinet including any additional funding from other sources.
  </span></a>($m) <em>rebaselined 01/07/14</em></div></td>
            <td data-sum="0" class="opex">
              <div class="field-type-number-decimal field-name-field-predicted-opex field-widget-number form-wrapper" id="edit-field-end-predicted-budget-und-0-field-predicted-opex"><div id="field-end-predicted-budget-und-0-field-predicted-opex-add-more-wrapper"><div class="form-item form-type-textfield form-item-field-end-predicted-budget-und-0-field-predicted-opex-und-0-value">
                    <label for="edit-field-end-predicted-budget-und-0-field-predicted-opex-und-0-value">$10 </label>
                  </div>
                </div></div>        </td>
            <td data-sum="1" class="opex">
              <div class="field-type-number-decimal field-name-field-predicted-opex field-widget-number form-wrapper" id="edit-field-end-predicted-budget-und-1-field-predicted-opex"><div id="field-end-predicted-budget-und-1-field-predicted-opex-add-more-wrapper"><div class="form-item form-type-textfield form-item-field-end-predicted-budget-und-1-field-predicted-opex-und-0-value">
                    <label for="edit-field-end-predicted-budget-und-1-field-predicted-opex-und-0-value">$10 </label>
                  </div>
                </div></div>        </td>
            <td data-sum="2" class="opex">
              <div class="field-type-number-decimal field-name-field-predicted-opex field-widget-number form-wrapper" id="edit-field-end-predicted-budget-und-2-field-predicted-opex"><div id="field-end-predicted-budget-und-2-field-predicted-opex-add-more-wrapper"><div class="form-item form-type-textfield form-item-field-end-predicted-budget-und-2-field-predicted-opex-und-0-value">
                    <label for="edit-field-end-predicted-budget-und-2-field-predicted-opex-und-0-value">$7 </label>
                  </div>
                </div></div>        </td>
            <td data-sum="3" class="opex">
              <div class="field-type-number-decimal field-name-field-predicted-opex field-widget-number form-wrapper" id="edit-field-end-predicted-budget-und-3-field-predicted-opex"><div id="field-end-predicted-budget-und-3-field-predicted-opex-add-more-wrapper"><div class="form-item form-type-textfield form-item-field-end-predicted-budget-und-3-field-predicted-opex-und-0-value">
                    <label for="edit-field-end-predicted-budget-und-3-field-predicted-opex-und-0-value">$7 </label>
                  </div>
                </div></div>        </td>
            <td data-sum="4" class="opex">
              <div class="field-type-number-decimal field-name-field-predicted-opex field-widget-number form-wrapper" id="edit-field-end-predicted-budget-und-4-field-predicted-opex"><div id="field-end-predicted-budget-und-4-field-predicted-opex-add-more-wrapper"><div class="form-item form-type-textfield form-item-field-end-predicted-budget-und-4-field-predicted-opex-und-0-value">
                    <label for="edit-field-end-predicted-budget-und-4-field-predicted-opex-und-0-value">$4 </label>
                  </div>
                </div></div>        </td>
          </tr>
          <tr class="sum">
            <td><div class="label" style="color:black; margin:0; font-weight:normal">Spend to Date<a href="javascript:void(0);" class="tooltip"><i class="tooltip-icon"></i><span class="tooltip-content">Actual project spend for the current financial year at the time of update.
  </span></a>($m)</div></td>
            <td data-sum="0" class="capex">
              <div class="field-type-number-decimal field-name-field-predicted-capex field-widget-number form-wrapper" id="edit-field-end-predicted-budget-und-0-field-predicted-capex"><div id="field-end-predicted-budget-und-0-field-predicted-capex-add-more-wrapper"><div class="form-item form-type-textfield form-item-field-end-predicted-budget-und-0-field-predicted-capex-und-0-value">
                    <input type="text" id="edit-field-end-predicted-budget-und-0-field-predicted-capex-und-0-value" name="field_end_predicted_budget[und][0][field_predicted_capex][und][0][value]" value="11" size="14" maxlength="12" class="form-text">
                  </div>
                </div></div>        </td>
            <td data-sum="1" class="capex">
              <div class="field-type-number-decimal field-name-field-predicted-capex field-widget-number form-wrapper" id="edit-field-end-predicted-budget-und-1-field-predicted-capex"><div id="field-end-predicted-budget-und-1-field-predicted-capex-add-more-wrapper"><div class="form-item form-type-textfield form-item-field-end-predicted-budget-und-1-field-predicted-capex-und-0-value">

                    <input type="text" id="edit-field-end-predicted-budget-und-1-field-predicted-capex-und-0-value" name="field_end_predicted_budget[und][1][field_predicted_capex][und][0][value]" value="9" size="14" maxlength="12" class="form-text">
                  </div>
                </div></div>        </td>
            <td data-sum="2" class="capex">
              <div class="field-type-number-decimal field-name-field-predicted-capex field-widget-number form-wrapper" id="edit-field-end-predicted-budget-und-2-field-predicted-capex"><div id="field-end-predicted-budget-und-2-field-predicted-capex-add-more-wrapper"><div class="form-item form-type-textfield form-item-field-end-predicted-budget-und-2-field-predicted-capex-und-0-value">

                    <input type="text" id="edit-field-end-predicted-budget-und-2-field-predicted-capex-und-0-value" name="field_end_predicted_budget[und][2][field_predicted_capex][und][0][value]" value="2" size="14" maxlength="12" class="form-text">
                  </div>
                </div></div>        </td>
            <td data-sum="3" class="capex">
              <div class="field-type-number-decimal field-name-field-predicted-capex field-widget-number form-wrapper" id="edit-field-end-predicted-budget-und-3-field-predicted-capex"><div id="field-end-predicted-budget-und-3-field-predicted-capex-add-more-wrapper"><div class="form-item form-type-textfield form-item-field-end-predicted-budget-und-3-field-predicted-capex-und-0-value"></div>
                </div></div>        </td>
            <td data-sum="4" class="capex">
              <div class="field-type-number-decimal field-name-field-predicted-capex field-widget-number form-wrapper" id="edit-field-end-predicted-budget-und-4-field-predicted-capex"><div id="field-end-predicted-budget-und-4-field-predicted-capex-add-more-wrapper"><div class="form-item form-type-textfield form-item-field-end-predicted-budget-und-4-field-predicted-capex-und-0-value"></div>
                </div></div>
            </td>
          </tr>
          </tbody>
        </table>
        <div style="float:right: width:55%; overflow:hidden; margin-top: 10px;" class="text">

        </div>
      </div>

    </div>
    <div class="row">
      <div class="label"><?php print $form['field_benefits_realised']['und']['#title']; ?></div>
      <div class="text"><?php print drupal_render($form['field_benefits_realised']); ?></div>
    </div>
    <div class="row">
      <div class="label">Original Expected Financial Benefits<a href="javascript:void(0);" class="tooltip"><i class="tooltip-icon"></i><span class="tooltip-content">The financial value of benefits expected by the project as identified in the business case. Where project is part of a larger programme, only use benefits that this project will deliver or contribute to.</span></a></div>
      <div class="text">
        $60m
      </div>
    </div>
    <div class="row">
      <div class="label"><?php print $form['field_current_financial_benefits']['und']['#title']; ?> <em>($m)</em><a href="javascript:void(0);" class="tooltip"><i class="tooltip-icon"></i><span class="tooltip-content">The current financial value of benefits expected by the project. Where project is part of a larger programme, only use benefits that this project will deliver or contribute to.</span></a></div>
      <div class="text">
        <?php print drupal_render($form['field_current_financial_benefits']); ?>
      </div>
      <div class="text"></div>
    </div>
    <div class="row">
      <div class="label"><?php print $form['field_estimated_value_of_benefit']['und']['#title']; ?> <em>($m)</em><a href="javascript:void(0);" class="tooltip"><i class="tooltip-icon"></i><span class="tooltip-content">The estimated financial benefits that have been realised to date.</span></a></div>
      <div class="text">
        <?php print drupal_render($form['field_estimated_value_of_benefit']); ?>
      </div>
    </div>
    <div class="row">
      <div class="label"><?php print $form['field_entity_comments']['und']['#title']; ?> <a href="javascript:void(0);" class="tooltip"><i class="tooltip-icon"></i><span class="tooltip-content">Context, remedial action, changes in project scope or other commentary.</span></a></div>
      <div class="text">
        <?php print drupal_render($form['field_entity_comments']); ?>
      </div>
    </div>
    <div class="submit">
      <div style="margin-bottom: 20px; text-align: right;" class="text">
        <a href="<?php print url('projects'); ?>" class="export-btn">
          <?php print t('Cancel'); ?>
        </a>
        <?php print render($form['actions']['submit']); ?>
      </div>
      <div style="overflow:hidden; text-align: right;" class="text">
        <?php print render($form['actions']['submit_request']); ?>
      </div>
    </div>
  </div>
</div>
<div class="element-invisible">
  <?php print drupal_render_children($form); ?>
</div>
