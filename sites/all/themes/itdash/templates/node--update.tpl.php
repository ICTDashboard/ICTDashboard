<div id="inner-content" class="wrap cf">
  <h2><?php print t('Update data'); ?></h2>
  <h3><?php print t('Costs, Benefits and Timings'); ?></h3>
  <div class="project-draft-submission d-all">
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

    <div class="row">
      <div class="label">
        <?php print $field_expected_completion_date['meta']['#title']; ?>
        <?php if (!empty($field_expected_completion_date['meta']['#description'])) : ?>
          <a href="javascript:void(0);" class="tooltip">
            <i class="tooltip-icon"></i>
            <span class="tooltip-content">
              <?php print $field_expected_completion_date['meta']['#description']; ?>
            </span>
          </a>
        <?php endif; ?>
      </div>
      <div class="text">
        <?php foreach (_ict_project_baseline_get_simple_values($field_expected_completion_date) as $value) : ?>
          <p><?php print empty($value) ? 'N/A' : $value; ?></p>
        <?php endforeach; ?>
      </div>
    </div>

    <div class="row">
      <div class="label">
        <?php print $field_forecast_level_of_project_['meta']['#title']; ?>
        <?php if (!empty($field_forecast_level_of_project_['meta']['#description'])) : ?>
          <a href="javascript:void(0);" class="tooltip">
            <i class="tooltip-icon"></i>
            <span class="tooltip-content">
              <?php print $field_forecast_level_of_project_['meta']['#description']; ?>
            </span>
          </a>
        <?php endif; ?>
      </div>
      <div class="text">
        <?php foreach (_ict_project_baseline_get_simple_values($field_forecast_level_of_project_) as $value) : ?>
          <p><?php print $value; ?></p>
        <?php endforeach; ?>
      </div>
    </div>

    <div class="row">
      <div class="label">
        <?php print $field_actual_level_of_project_co['meta']['#title']; ?>
        <?php if (!empty($field_actual_level_of_project_co['meta']['#description'])) : ?>
          <a href="javascript:void(0);" class="tooltip">
            <i class="tooltip-icon"></i>
            <span class="tooltip-content">
              <?php print $field_actual_level_of_project_co['meta']['#description']; ?>
            </span>
          </a>
        <?php endif; ?>
      </div>
      <div class="text">
        <?php foreach (_ict_project_baseline_get_simple_values($field_actual_level_of_project_co) as $value) : ?>
          <p><?php print $value; ?></p>
        <?php endforeach; ?>
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
          <tr class="sum">
            <td><div class="label" style="color:black; margin:0; font-weight:normal">Updated</div></td>
            <td data-sum="0" class="opex"><div class="field-type-number-decimal field-name-field-predicted-opex field-widget-number form-wrapper" id="edit-field-end-predicted-budget-und-0-field-predicted-opex3">
                <div id="field-end-predicted-budget-und-0-field-predicted-opex-add-more-wrapper3">
                  <div class="form-item form-type-textfield form-item-field-end-predicted-budget-und-0-field-predicted-opex-und-0-value">
                    <label for="edit-field-end-predicted-budget-und-0-field-predicted-opex-und-0-value2">$9 </label>
                  </div>
                </div>
              </div></td>
            <td data-sum="1" class="opex"><div class="field-type-number-decimal field-name-field-predicted-opex field-widget-number form-wrapper" id="edit-field-end-predicted-budget-und-1-field-predicted-opex3">
                <div id="field-end-predicted-budget-und-1-field-predicted-opex-add-more-wrapper3">
                  <div class="form-item form-type-textfield form-item-field-end-predicted-budget-und-1-field-predicted-opex-und-0-value">
                    <label for="edit-field-end-predicted-budget-und-1-field-predicted-opex-und-0-value3">$11 </label>
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
                    <label for="edit-field-end-predicted-budget-und-3-field-predicted-opex-und-0-value3">$8 </label>
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

    <div class="row">
      <div class="label">
        <?php print t('Benefits realised'); ?>
        <?php if (!empty($form['field_benefits_realised']['#description'])) : ?>
          <a href="javascript:void(0);" class="tooltip">
            <i class="tooltip-icon"></i>
              <span class="tooltip-content">
                <?php print $form['field_benefits_realised']['#description']; ?>
              </span>
          </a>
        <?php endif; ?>
      </div>
      <div class="text">
        <!--        --><?php //print render($form['field_original_total_budget']); ?>
        <table id="field_end_predicted_budget">
          <tbody>
          <tr>
            <th></th><th>
              <div style="display: none;">
                <div class="field-type-text field-name-field-predicted-year field-widget-text-textfield form-wrapper" id="edit-field-end-predicted-budget-und-0-field-predicted-year"><div id="field-end-predicted-budget-und-0-field-predicted-year-add-more-wrapper"><div class="form-item form-type-textfield form-item-field-end-predicted-budget-und-0-field-predicted-year-und-0-value">
                      <label class="element-invisible" for="edit-field-end-predicted-budget-und-0-field-predicted-year-und-0-value">Year </label>
                      <input class="text-full form-text" type="text" id="edit-field-end-predicted-budget-und-0-field-predicted-year-und-0-value" name="field_end_predicted_budget[und][0][field_predicted_year][und][0][value]" value="13/14" size="60" maxlength="255">
                    </div>
                  </div></div>          </div>
              Benefits        </th>
            <th>
              <div style="display: none;">
                <div class="field-type-text field-name-field-predicted-year field-widget-text-textfield form-wrapper" id="edit-field-end-predicted-budget-und-1-field-predicted-year"><div id="field-end-predicted-budget-und-1-field-predicted-year-add-more-wrapper"><div class="form-item form-type-textfield form-item-field-end-predicted-budget-und-1-field-predicted-year-und-0-value">
                      <label class="element-invisible" for="edit-field-end-predicted-budget-und-1-field-predicted-year-und-0-value">Year </label>
                      <input class="text-full form-text" type="text" id="edit-field-end-predicted-budget-und-1-field-predicted-year-und-0-value" name="field_end_predicted_budget[und][1][field_predicted_year][und][0][value]" value="14/15" size="60" maxlength="255">
                    </div>
                  </div></div>          </div>
              Status        </th>
            <th>
              <div style="display: none;">
                <div class="field-type-text field-name-field-predicted-year field-widget-text-textfield form-wrapper" id="edit-field-end-predicted-budget-und-2-field-predicted-year"><div id="field-end-predicted-budget-und-2-field-predicted-year-add-more-wrapper"><div class="form-item form-type-textfield form-item-field-end-predicted-budget-und-2-field-predicted-year-und-0-value">
                      <label class="element-invisible" for="edit-field-end-predicted-budget-und-2-field-predicted-year-und-0-value">Year </label>
                      <input class="text-full form-text" type="text" id="edit-field-end-predicted-budget-und-2-field-predicted-year-und-0-value" name="field_end_predicted_budget[und][2][field_predicted_year][und][0][value]" value="15/16" size="60" maxlength="255">
                    </div>
                  </div></div>          </div>
              Commentary        </th>
            <th>
              <div style="display: none;">
                <div class="field-type-text field-name-field-predicted-year field-widget-text-textfield form-wrapper" id="edit-field-end-predicted-budget-und-3-field-predicted-year"><div id="field-end-predicted-budget-und-3-field-predicted-year-add-more-wrapper"><div class="form-item form-type-textfield form-item-field-end-predicted-budget-und-3-field-predicted-year-und-0-value">
                      <label class="element-invisible" for="edit-field-end-predicted-budget-und-3-field-predicted-year-und-0-value">Year </label>
                      <input class="text-full form-text" type="text" id="edit-field-end-predicted-budget-und-3-field-predicted-year-und-0-value" name="field_end_predicted_budget[und][3][field_predicted_year][und][0][value]" value="16/17" size="60" maxlength="255">
                    </div>
                  </div></div>          </div>
              Start date        </th>
            <th>
              <div style="display: none;">
                <div class="field-type-text field-name-field-predicted-year field-widget-text-textfield form-wrapper" id="edit-field-end-predicted-budget-und-4-field-predicted-year"><div id="field-end-predicted-budget-und-4-field-predicted-year-add-more-wrapper"><div class="form-item form-type-textfield form-item-field-end-predicted-budget-und-4-field-predicted-year-und-0-value">
                      <label class="element-invisible" for="edit-field-end-predicted-budget-und-4-field-predicted-year-und-0-value">Year </label>
                      <input class="text-full form-text" type="text" id="edit-field-end-predicted-budget-und-4-field-predicted-year-und-0-value" name="field_end_predicted_budget[und][4][field_predicted_year][und][0][value]" value="17/18" size="60" maxlength="255">
                    </div>
                  </div></div>          </div>
              End date
            </th>
            <th>
              <div style="display: none;">
                <div class="field-type-text field-name-field-predicted-year field-widget-text-textfield form-wrapper" id="edit-field-end-predicted-budget-und-4-field-predicted-year"><div id="field-end-predicted-budget-und-4-field-predicted-year-add-more-wrapper"><div class="form-item form-type-textfield form-item-field-end-predicted-budget-und-4-field-predicted-year-und-0-value">
                      <label class="element-invisible" for="edit-field-end-predicted-budget-und-4-field-predicted-year-und-0-value">Year </label>
                      <input class="text-full form-text" type="text" id="edit-field-end-predicted-budget-und-4-field-predicted-year-und-0-value" name="field_end_predicted_budget[und][4][field_predicted_year][und][0][value]" value="17/18" size="60" maxlength="255">
                    </div>
                  </div></div>          </div>
              Financial
            </th></tr>
          </tr>

          <tr class="sum">
            <td><div class="label" style="color:black; margin:0; font-weight:normal">Baseline</div></td>
            <td data-sum="0" class="opex"><div class="field-type-number-decimal field-name-field-predicted-opex field-widget-number form-wrapper" id="edit-field-end-predicted-budget-und-0-field-predicted-opex3">
                <div id="field-end-predicted-budget-und-0-field-predicted-opex-add-more-wrapper3">
                  <div class="form-item form-type-textfield form-item-field-end-predicted-budget-und-0-field-predicted-opex-und-0-value">
                    <label for="edit-field-end-predicted-budget-und-0-field-predicted-opex-und-0-value2">Benefit One </label>
                  </div>
                </div>
              </div></td>
            <td data-sum="1" class="opex"><div class="field-type-number-decimal field-name-field-predicted-opex field-widget-number form-wrapper" id="edit-field-end-predicted-budget-und-1-field-predicted-opex3">
                <div id="field-end-predicted-budget-und-1-field-predicted-opex-add-more-wrapper3">
                  <div class="form-item form-type-textfield form-item-field-end-predicted-budget-und-1-field-predicted-opex-und-0-value">
                    <label for="edit-field-end-predicted-budget-und-1-field-predicted-opex-und-0-value3">Completed </label>
                  </div>
                </div>
              </div></td>
            <td data-sum="2" class="opex"><div class="field-type-number-decimal field-name-field-predicted-opex field-widget-number form-wrapper" id="edit-field-end-predicted-budget-und-2-field-predicted-opex3">
                <div id="field-end-predicted-budget-und-2-field-predicted-opex-add-more-wrapper3">
                  <div class="form-item form-type-textfield form-item-field-end-predicted-budget-und-2-field-predicted-opex-und-0-value">
                    <label for="edit-field-end-predicted-budget-und-2-field-predicted-opex-und-0-value3">No Commentary </label>
                  </div>
                </div>
              </div></td>
            <td data-sum="3" class="opex"><div class="field-type-number-decimal field-name-field-predicted-opex field-widget-number form-wrapper" id="edit-field-end-predicted-budget-und-3-field-predicted-opex3">
                <div id="field-end-predicted-budget-und-3-field-predicted-opex-add-more-wrapper3">
                  <div class="form-item form-type-textfield form-item-field-end-predicted-budget-und-3-field-predicted-opex-und-0-value">
                    <label for="edit-field-end-predicted-budget-und-3-field-predicted-opex-und-0-value3">10/2015 </label>
                  </div>
                </div>
              </div></td>
            <td data-sum="4" class="opex"><div class="field-type-number-decimal field-name-field-predicted-opex field-widget-number form-wrapper" id="edit-field-end-predicted-budget-und-4-field-predicted-opex3">
                <div id="field-end-predicted-budget-und-4-field-predicted-opex-add-more-wrapper2">
                  <div class="form-item form-type-textfield form-item-field-end-predicted-budget-und-4-field-predicted-opex-und-0-value">
                    <label for="edit-field-end-predicted-budget-und-4-field-predicted-opex-und-0-value2">02/2016 </label>
                  </div>
                </div>
              </div></td>
            <td data-sum="4" class="opex"><div class="field-type-number-decimal field-name-field-predicted-opex field-widget-number form-wrapper" id="edit-field-end-predicted-budget-und-4-field-predicted-opex3">
                <div id="field-end-predicted-budget-und-4-field-predicted-opex-add-more-wrapper2">
                  <div class="form-item form-type-textfield form-item-field-end-predicted-budget-und-4-field-predicted-opex-und-0-value">
                    <label for="edit-field-end-predicted-budget-und-4-field-predicted-opex-und-0-value2">Yes </label>
                  </div>
                </div>
              </div></td>
          </tr>
          <tr class="sum">
            <td><div class="label" style="color:black; margin:0; font-weight:normal">Updated</div></td>
            <td data-sum="0" class="opex"><div class="field-type-number-decimal field-name-field-predicted-opex field-widget-number form-wrapper" id="edit-field-end-predicted-budget-und-0-field-predicted-opex3">
                <div id="field-end-predicted-budget-und-0-field-predicted-opex-add-more-wrapper3">
                  <div class="form-item form-type-textfield form-item-field-end-predicted-budget-und-0-field-predicted-opex-und-0-value">
                    <label for="edit-field-end-predicted-budget-und-0-field-predicted-opex-und-0-value2">Benefit One </label>
                  </div>
                </div>
              </div></td>
            <td data-sum="1" class="opex"><div class="field-type-number-decimal field-name-field-predicted-opex field-widget-number form-wrapper" id="edit-field-end-predicted-budget-und-1-field-predicted-opex3">
                <div id="field-end-predicted-budget-und-1-field-predicted-opex-add-more-wrapper3">
                  <div class="form-item form-type-textfield form-item-field-end-predicted-budget-und-1-field-predicted-opex-und-0-value">
                    <label for="edit-field-end-predicted-budget-und-1-field-predicted-opex-und-0-value3">Completed </label>
                  </div>
                </div>
              </div></td>
            <td data-sum="2" class="opex"><div class="field-type-number-decimal field-name-field-predicted-opex field-widget-number form-wrapper" id="edit-field-end-predicted-budget-und-2-field-predicted-opex3">
                <div id="field-end-predicted-budget-und-2-field-predicted-opex-add-more-wrapper3">
                  <div class="form-item form-type-textfield form-item-field-end-predicted-budget-und-2-field-predicted-opex-und-0-value">
                    <label for="edit-field-end-predicted-budget-und-2-field-predicted-opex-und-0-value3">No Commentary </label>
                  </div>
                </div>
              </div></td>
            <td data-sum="3" class="opex"><div class="field-type-number-decimal field-name-field-predicted-opex field-widget-number form-wrapper" id="edit-field-end-predicted-budget-und-3-field-predicted-opex3">
                <div id="field-end-predicted-budget-und-3-field-predicted-opex-add-more-wrapper3">
                  <div class="form-item form-type-textfield form-item-field-end-predicted-budget-und-3-field-predicted-opex-und-0-value">
                    <label for="edit-field-end-predicted-budget-und-3-field-predicted-opex-und-0-value3">10/2015 </label>
                  </div>
                </div>
              </div></td>
            <td data-sum="4" class="opex"><div class="field-type-number-decimal field-name-field-predicted-opex field-widget-number form-wrapper" id="edit-field-end-predicted-budget-und-4-field-predicted-opex3">
                <div id="field-end-predicted-budget-und-4-field-predicted-opex-add-more-wrapper2">
                  <div class="form-item form-type-textfield form-item-field-end-predicted-budget-und-4-field-predicted-opex-und-0-value">
                    <label for="edit-field-end-predicted-budget-und-4-field-predicted-opex-und-0-value2">02/2016 </label>
                  </div>
                </div>
              </div></td>
            <td data-sum="4" class="opex"><div class="field-type-number-decimal field-name-field-predicted-opex field-widget-number form-wrapper" id="edit-field-end-predicted-budget-und-4-field-predicted-opex3">
                <div id="field-end-predicted-budget-und-4-field-predicted-opex-add-more-wrapper2">
                  <div class="form-item form-type-textfield form-item-field-end-predicted-budget-und-4-field-predicted-opex-und-0-value">
                    <label for="edit-field-end-predicted-budget-und-4-field-predicted-opex-und-0-value2">Yes </label>
                  </div>
                </div>
              </div></td>
          </tr>
          </tbody>
        </table>
      </div>
    </div>

    <div class="row">
      <div class="label">
        <?php print $field_current_financial_benefits['meta']['#title']; ?>
        <?php if (!empty($field_current_financial_benefits['meta']['#description'])) : ?>
          <a href="javascript:void(0);" class="tooltip">
            <i class="tooltip-icon"></i>
            <span class="tooltip-content">
              <?php print $field_current_financial_benefits['meta']['#description']; ?>
            </span>
          </a>
        <?php endif; ?>
      </div>
      <div class="text">
        <?php foreach (_ict_project_baseline_get_simple_values($field_current_financial_benefits) as $value) : ?>
          <p><?php print $value; ?></p>
        <?php endforeach; ?>
      </div>
    </div>

    <div class="row">
      <div class="label">
        <?php print $field_estimated_value_of_benefit['meta']['#title']; ?>
        <?php if (!empty($field_estimated_value_of_benefit['meta']['#description'])) : ?>
          <a href="javascript:void(0);" class="tooltip">
            <i class="tooltip-icon"></i>
            <span class="tooltip-content">
              <?php print $field_estimated_value_of_benefit['meta']['#description']; ?>
            </span>
          </a>
        <?php endif; ?>
      </div>
      <div class="text">
        <?php foreach (_ict_project_baseline_get_simple_values($field_estimated_value_of_benefit) as $value) : ?>
          <p><?php print $value; ?></p>
        <?php endforeach; ?>
      </div>
    </div>

    <div class="row">
      <div class="label">
        <?php print $field_entity_comments['meta']['#title']; ?>
        <?php if (!empty($field_entity_comments['meta']['#description'])) : ?>
          <a href="javascript:void(0);" class="tooltip">
            <i class="tooltip-icon"></i>
            <span class="tooltip-content">
              <?php print $field_entity_comments['meta']['#description']; ?>
            </span>
          </a>
        <?php endif; ?>
      </div>
      <div class="text">
        <?php foreach (_ict_project_baseline_get_simple_values($field_entity_comments) as $value) : ?>
          <p><?php print $value; ?></p>
        <?php endforeach; ?>
      </div>
    </div>

  </div>
</div>
