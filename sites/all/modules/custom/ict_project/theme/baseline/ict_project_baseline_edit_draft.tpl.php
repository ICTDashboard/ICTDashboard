<div class="page-title dotbg">
  <div class="inner-title-content wrap cf">
    <h1><?php print t('ICT Project Submission Form'); ?></h1>
  </div>
</div>
<div id="inner-content" class="wrap cf">
  <h2><?php print t('Baseline data'); ?></h2>
  <h3><?php print t('Basic project information'); ?></h3>
  <div class="project-draft-submission d-all">

    <div class="row">
      <div class="label">
        <?php print $form['field_government_entity_name']['#title']; ?>
        <?php if (!empty($form['field_government_entity_name']['#description'])) : ?>
          <a href="javascript:void(0);" class="tooltip">
            <i class="tooltip-icon"></i>
            <span class="tooltip-content">
              <?php print $form['field_government_entity_name']['#description']; ?>
            </span>
          </a>
        <?php endif; ?>
      </div>
      <div class="text">
        <?php print render($form['field_government_entity_name']); ?>
      </div>
    </div>

    <div class="row">
      <div class="label">
        <?php print $form['field_implementation_partners']['#title']; ?>
        <?php if (!empty($form['field_implementation_partners']['#description'])) : ?>
          <a href="javascript:void(0);" class="tooltip">
            <i class="tooltip-icon"></i>
            <span class="tooltip-content">
              <?php print $form['field_implementation_partners']['#description']; ?>
            </span>
          </a>
        <?php endif; ?>
      </div>
      <div class="text">
        <?php print render($form['field_implementation_partners']); ?>
      </div>
    </div>

    <div class="row">
      <div class="label">
        <?php print $form['field_portfolio_name']['#title']; ?>
        <?php if (!empty($form['field_portfolio_name']['#description'])) : ?>
          <a href="javascript:void(0);" class="tooltip">
            <i class="tooltip-icon"></i>
            <span class="tooltip-content">
              <?php print $form['field_portfolio_name']['#description']; ?>
            </span>
          </a>
        <?php endif; ?>
      </div>
      <div class="text">
        <?php print render($form['field_portfolio_name']); ?>
      </div>
    </div>

    <div class="row">
      <div class="label">
        <?php print $form['title']['#title']; ?>
        <a href="javascript:void(0);" class="tooltip">
          <i class="tooltip-icon"></i>
          <span class="tooltip-content">
            <?php print t('The official full name of the project, excluding acronyms.'); ?>
          </span>
        </a>
      </div>
      <div class="text">
        <?php print render($form['title']); ?>
      </div>
    </div>

    <div class="row">
      <div class="label">
        <?php print $form['field_program_name']['#title']; ?>
        <?php if (!empty($form['field_program_name']['#description'])) : ?>
          <a href="javascript:void(0);" class="tooltip">
            <i class="tooltip-icon"></i>
            <span class="tooltip-content">
              <?php print $form['field_program_name']['#description']; ?>
            </span>
          </a>
        <?php endif; ?>
      </div>
      <div class="text">
        <?php print render($form['field_program_name']); ?>
      </div>
    </div>

    <div class="row">
      <div class="label">
        <?php print $form['field_brief_project_summary']['#title']; ?>
        <?php if (!empty($form['field_brief_project_summary']['#description'])) : ?>
          <a href="javascript:void(0);" class="tooltip">
            <i class="tooltip-icon"></i>
            <span class="tooltip-content">
              <?php print $form['field_brief_project_summary']['#description']; ?>
            </span>
          </a>
        <?php endif; ?>
      </div>
      <div class="text">
        <?php print render($form['field_brief_project_summary']); ?>
      </div>
    </div>

    <div class="dotted-line"></div>

    <h3><?php print t('User information'); ?></h3>

    <div class="row">
      <div class="label">
        <?php print $form['field_responsible_officer_name']['#title']; ?>
        <?php if (!empty($form['field_responsible_officer_name']['#description'])) : ?>
          <a href="javascript:void(0);" class="tooltip">
            <i class="tooltip-icon"></i>
            <span class="tooltip-content">
              <?php print $form['field_responsible_officer_name']['#description']; ?>
            </span>
          </a>
        <?php endif; ?>
      </div>
      <div class="text">
        <?php print render($form['field_responsible_officer_name']); ?>
      </div>
    </div>

    <div class="row">
      <div class="label">
        <?php print $form['field_resp_officer_position']['#title']; ?>
        <?php if (!empty($form['field_resp_officer_position']['#description'])) : ?>
          <a href="javascript:void(0);" class="tooltip">
            <i class="tooltip-icon"></i>
            <span class="tooltip-content">
              <?php print $form['field_resp_officer_position']['#description']; ?>
            </span>
          </a>
        <?php endif; ?>
      </div>
      <div class="text">
        <?php print render($form['field_resp_officer_position']); ?>
      </div>
    </div>

    <?php print render($form['admin_user_details']); ?>

    <div class="dotted-line"></div>

    <h3><?php print t('Cost benefits and timings'); ?></h3>

    <div class="row">
      <div class="label">
        <?php print $form['field_project_stage']['#title']; ?>
        <?php if (!empty($form['field_project_stage']['#description'])) : ?>
          <a href="javascript:void(0);" class="tooltip">
            <i class="tooltip-icon"></i>
            <span class="tooltip-content">
              <?php print $form['field_project_stage']['#description']; ?>
            </span>
          </a>
        <?php endif; ?>
      </div>
      <div class="text">
        <?php print render($form['field_project_stage']); ?>
      </div>
    </div>

    <div class="row">
      <div class="label">
        <?php print t('Project Budget By Financial Year'); ?>
        <?php if (!empty($form['field_original_total_budget']['#description'])) : ?>
          <a href="javascript:void(0);" class="tooltip">
            <i class="tooltip-icon"></i>
            <span class="tooltip-content">
              <?php print $form['field_original_total_budget']['#description']; ?>
            </span>
          </a>
        <?php endif; ?>
      </div>
      <div class="text">
<!--        --><?php //print render($form['field_original_total_budget']); ?>
        <table id="field_end_predicted_budget">
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
            <td><div class="label" style="color:black; margin:0; font-weight:normal">Baseline</div></td>
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
          </tbody>
        </table>
      </div>
    </div>

    <?php $start_date = &$form['field_start_date']; ?>
    <div class="row">
      <div class="label">
        <?php print $start_date['#title']; ?>
        <?php if (!empty($start_date['#description'])) : ?>
          <a href="javascript:void(0);" class="tooltip">
            <i class="tooltip-icon"></i>
            <span class="tooltip-content">
              <?php print $start_date['#description']; ?>
            </span>
          </a>
        <?php endif; ?>
      </div>
      <div class="text">
        <?php print render($start_date); ?>
      </div>
    </div>

    <?php $end_date = &$form['field_original_completion_date']; ?>
    <div class="row">
      <div class="label">
        <?php print $end_date['#title']; ?>
        <?php if (!empty($end_date['#description'])) : ?>
          <a href="javascript:void(0);" class="tooltip">
            <i class="tooltip-icon"></i>
            <span class="tooltip-content">
              <?php print $end_date['#description']; ?>
            </span>
          </a>
        <?php endif; ?>
      </div>
      <div class="text">
        <?php print render($end_date); ?>
      </div>
    </div>

    <div class="row">
      <div class="label">
        <?php print $form['field_predicted_project_benefit']['#title'] . ' <em>($m)</em>'; ?>
        <?php if (!empty($form['field_original_total_budget']['#description'])) : ?>
          <a href="javascript:void(0);" class="tooltip">
            <i class="tooltip-icon"></i>
            <span class="tooltip-content">
              <?php print $form['field_predicted_project_benefit']['#description']; ?>
            </span>
          </a>
        <?php endif; ?>
      </div>
      <div class="text">
        <?php print render($form['field_predicted_project_benefit']); ?>
      </div>
    </div>

    <div class="row">
      <div class="label">
        <?php print t('Top Benefits'); ?>
        <?php if (!empty($form['field_benefits_realised']['#description'])) : ?>
          <a href="javascript:void(0);" class="tooltip">
            <i class="tooltip-icon"></i>
            <span class="tooltip-content">
              List the measurable benefits (quantitative or qualitative) this project will deliver or contribute to, as identified in the business case.
            </span>
          </a>
        <?php endif; ?>
      </div>
      <div class="text">
        <?php print render($form['field_benefits_realised']); ?>
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


    <div style="display:none;">
      <?php print drupal_render_children($form); ?>
    </div>
  </div>
</div>