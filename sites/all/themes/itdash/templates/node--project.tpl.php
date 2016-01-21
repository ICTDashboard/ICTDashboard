<div class="page-title dotbg">
  <div class="inner-title-content wrap cf">
    <h1><?php print $title; ?></h1>
  </div>
</div>

<div id="inner-content" class="wrap cf">
  <h2><?php print t('Baseline data'); ?></h2>
  <h3><?php print t('Basic project information'); ?></h3>
  <div class="project-draft-submission d-all">

    <div class="row">
      <div class="label">
        <?php print $field_government_entity_name['meta']['#title']; ?>
        <?php if (!empty($field_government_entity_name['meta']['#description'])) : ?>
          <a href="javascript:void(0);" class="tooltip">
            <i class="tooltip-icon"></i>
            <span class="tooltip-content">
              <?php print $field_government_entity_name['meta']['#description']; ?>
            </span>
          </a>
        <?php endif; ?>
      </div>
      <div class="text">
        <?php foreach (_ict_project_baseline_get_simple_values($field_government_entity_name) as $value) : ?>
          <p><?php print $value; ?></p>
        <?php endforeach; ?>
      </div>
    </div>

    <div class="row">
      <div class="label">
        <?php print $field_implementation_partners['meta']['#title']; ?>
        <?php if (!empty($field_implementation_partners['meta']['#description'])) : ?>
          <a href="javascript:void(0);" class="tooltip">
            <i class="tooltip-icon"></i>
            <span class="tooltip-content">
              <?php print $field_implementation_partners['meta']['#description']; ?>
            </span>
          </a>
        <?php endif; ?>
      </div>
      <div class="text">
        <?php foreach (_ict_project_baseline_get_simple_values($field_implementation_partners) as $value) : ?>
          <p><?php print $value; ?></p>
        <?php endforeach; ?>
      </div>
    </div>

    <div class="row">
      <div class="label">
        <?php print $field_portfolio_name['meta']['#title']; ?>
        <?php if (!empty($field_portfolio_name['meta']['#description'])) : ?>
          <a href="javascript:void(0);" class="tooltip">
            <i class="tooltip-icon"></i>
            <span class="tooltip-content">
              <?php print $field_portfolio_name['meta']['#description']; ?>
            </span>
          </a>
        <?php endif; ?>
      </div>
      <div class="text">
        <?php foreach (_ict_project_baseline_get_simple_values($field_portfolio_name) as $value) : ?>
          <p><?php print $value; ?></p>
        <?php endforeach; ?>
      </div>
    </div>

    <div class="row">
      <div class="label">
        <?php print $field_program_name['meta']['#title']; ?>
        <?php if (!empty($field_program_name['meta']['#description'])) : ?>
          <a href="javascript:void(0);" class="tooltip">
            <i class="tooltip-icon"></i>
            <span class="tooltip-content">
              <?php print $field_program_name['meta']['#description']; ?>
            </span>
          </a>
        <?php endif; ?>
      </div>
      <div class="text">
        <?php foreach (_ict_project_baseline_get_simple_values($field_program_name) as $value) : ?>
          <p><?php print $value; ?></p>
        <?php endforeach; ?>
      </div>
    </div>

    <div class="row">
      <div class="label">
        <?php print $field_brief_project_summary['meta']['#title']; ?>
        <?php if (!empty($field_brief_project_summary['meta']['#description'])) : ?>
          <a href="javascript:void(0);" class="tooltip">
            <i class="tooltip-icon"></i>
            <span class="tooltip-content">
              <?php print $field_brief_project_summary['meta']['#description']; ?>
            </span>
          </a>
        <?php endif; ?>
      </div>
      <div class="text">
        <?php foreach (_ict_project_baseline_get_simple_values($field_brief_project_summary) as $value) : ?>
          <p><?php print $value; ?></p>
        <?php endforeach; ?>
      </div>
    </div>

    <div class="dotted-line"></div>

    <h3><?php print t('User information'); ?></h3>

    <div class="row">
      <div class="label">
        <?php print $field_responsible_officer_name['meta']['#title']; ?>
        <?php if (!empty($field_responsible_officer_name['meta']['#description'])) : ?>
          <a href="javascript:void(0);" class="tooltip">
            <i class="tooltip-icon"></i>
            <span class="tooltip-content">
              <?php print $field_responsible_officer_name['meta']['#description']; ?>
            </span>
          </a>
        <?php endif; ?>
      </div>
      <div class="text">
        <?php foreach (_ict_project_baseline_get_simple_values($field_responsible_officer_name) as $value) : ?>
          <p><?php print $value; ?></p>
        <?php endforeach; ?>
      </div>
    </div>

    <div class="row">
      <div class="label">
        <?php print $field_resp_officer_position['meta']['#title']; ?>
        <?php if (!empty($field_resp_officer_position['meta']['#description'])) : ?>
          <a href="javascript:void(0);" class="tooltip">
            <i class="tooltip-icon"></i>
            <span class="tooltip-content">
              <?php print $field_resp_officer_position['meta']['#description']; ?>
            </span>
          </a>
        <?php endif; ?>
      </div>
      <div class="text">
        <?php foreach (_ict_project_baseline_get_simple_values($field_resp_officer_position) as $value) : ?>
          <p><?php print $value; ?></p>
        <?php endforeach; ?>
      </div>
    </div>

    <?php print $admin_user_details; ?>

    <div class="dotted-line"></div>

    <h3><?php print t('Cost benefits and timings'); ?></h3>

    <div class="row">
      <div class="label">
        <?php print $field_project_stage['meta']['#title']; ?>
        <?php if (!empty($field_project_stage['meta']['#description'])) : ?>
          <a href="javascript:void(0);" class="tooltip">
            <i class="tooltip-icon"></i>
            <span class="tooltip-content">
              <?php print $field_project_stage['meta']['#description']; ?>
            </span>
          </a>
        <?php endif; ?>
      </div>
      <div class="text">
        <?php foreach (_ict_project_baseline_get_simple_values($field_project_stage) as $value) : ?>
          <p><?php print $value; ?></p>
        <?php endforeach; ?>
      </div>
    </div>

    <?php if (!$project_updates_available) : ?>
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
    <?php endif; ?>

    <div class="row">
      <div class="label">
        <?php print $field_start_date['meta']['#title']; ?>
        <?php if (!empty($field_start_date['meta']['#description'])) : ?>
          <a href="javascript:void(0);" class="tooltip">
            <i class="tooltip-icon"></i>
            <span class="tooltip-content">
              <?php print $field_start_date['meta']['#description']; ?>
            </span>
          </a>
        <?php endif; ?>
      </div>
      <div class="text">
        <?php foreach (_ict_project_baseline_get_simple_values($field_start_date) as $value) : ?>
          <p><?php print $value; ?></p>
        <?php endforeach; ?>
      </div>
    </div>

    <div class="row">
      <div class="label">
        <?php print $field_original_completion_date['meta']['#title']; ?>
        <?php if (!empty($field_original_completion_date['meta']['#description'])) : ?>
          <a href="javascript:void(0);" class="tooltip">
            <i class="tooltip-icon"></i>
            <span class="tooltip-content">
              <?php print $field_original_completion_date['meta']['#description']; ?>
            </span>
          </a>
        <?php endif; ?>
      </div>
      <div class="text">
        <?php foreach (_ict_project_baseline_get_simple_values($field_original_completion_date) as $value) : ?>
          <p><?php print $value; ?></p>
        <?php endforeach; ?>
      </div>
    </div>

    <div class="row">
      <div class="label">
        <?php print $field_predicted_project_benefit['meta']['#title'] . ' <em>($m)</em>'; ?>
        <?php if (!empty($field_predicted_project_benefit['meta']['#description'])) : ?>
          <a href="javascript:void(0);" class="tooltip">
            <i class="tooltip-icon"></i>
            <span class="tooltip-content">
              <?php print $field_predicted_project_benefit['meta']['#description']; ?>
            </span>
          </a>
        <?php endif; ?>
      </div>
      <div class="text">
        <?php foreach (_ict_project_baseline_get_simple_values($field_predicted_project_benefit) as $value) : ?>
          <p><?php print $value; ?></p>
        <?php endforeach; ?>
      </div>
    </div>

    <?php if (isset($approve_form)) : ?>
      <?php print $approve_form; ?>
    <?php endif; ?>

  </div>
</div>