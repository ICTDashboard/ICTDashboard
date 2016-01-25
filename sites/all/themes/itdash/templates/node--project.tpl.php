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
          <?php if (!empty($field_original_total_budget['meta']['#description'])) : ?>
            <a href="javascript:void(0);" class="tooltip">
              <i class="tooltip-icon"></i>
              <span class="tooltip-content">
                <?php print $field_original_total_budget['meta']['#description']; ?>
              </span>
            </a>
          <?php endif; ?>
        </div>
        <div class="text">
          <?php print $field_original_total_budget; ?>
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

    <?php if (!$project_updates_available) : ?>
      <div class="row">
        <div class="label">Benefits</div>
        <div class="text">
          <table id="field_end_predicted_budget" style="max-width:100%;">
            <tbody>
            <tr>
              <th><div class="label" style="color:white; margin:0;">Benefits<a href="javascript:void(0);" class="tooltip"><i class="tooltip-icon"></i><span class="tooltip-content">List the benefits (quantitative or qualitative) this project will deliver or contribute to, as identified in the business case.
    </span></a></div>

              </th><th><div class="label" style="color:white; margin:0;">Realised?<a href="javascript:void(0);" class="tooltip"><i class="tooltip-icon"></i><span class="tooltip-content">For each benefit listed, indicate the status of benefit realisation. Realised - The benefit has been realised; Partially - The benefit has been partially realised; On Track – The project is on track to realise the benefit as originally expected; At Risk - The benefit is not likely to be realised as originally expected; Not Realised - The benefit has not been realised.
    </span></a></div></th>
              <th><div class="label" style="color:white; margin:0;">Commentary</div></th>
              <th colspan="2"><div class="label" style="color:white; margin:0;">Date Range <a href="javascript:void(0);" class="tooltip"><i class="tooltip-icon"></i><span class="tooltip-content">For each benefit listed, the date range when benefit is expected to be realised.
    </span></a> From - To</div></th>
              <th><div class="label" style="color:white; margin:0;">Financial<a href="javascript:void(0);" class="tooltip"><i class="tooltip-icon"></i><span class="tooltip-content">For each benefit listed, mark those where the benefit can be measured financially.
    </span></a></div>
              </th></tr>
            <tr class="sum">
              <td><em>1. Lorem ipsum dolor sit amet</em></td>
              <td data-sum="1" class="capex" style="background-color:white; padding-left:3px;">
                <div class="field-type-number-decimal field-name-field-predicted-capex field-widget-number form-wrapper" id="edit-field-end-predicted-budget-und-1-field-predicted-capex"><div id="field-end-predicted-budget-und-1-field-predicted-capex-add-more-wrapper"><div class="form-item form-type-textfield form-item-field-end-predicted-budget-und-1-field-predicted-capex-und-0-value">
                      <select><option selected="">Realised</option><option>Partially</option><option>On Track</option><option>At Risk</option><option>Not Realised</option></select>
                    </div>
                  </div></div>        </td>
              <td data-sum="2" class="capex" style="background-color:white;">
                <div class="field-type-number-decimal field-name-field-predicted-capex field-widget-number form-wrapper" id="edit-field-end-predicted-budget-und-2-field-predicted-capex"><div id="field-end-predicted-budget-und-2-field-predicted-capex-add-more-wrapper"><div class="form-item form-type-textfield form-item-field-end-predicted-budget-und-2-field-predicted-capex-und-0-value">
                      <textarea type="text" rows="3" width="14"></textarea>
                    </div>
                  </div></div>        </td>
              <td data-sum="3" class="capex" style="background-color:white;">
                <div class="field-type-number-decimal field-name-field-predicted-capex field-widget-number form-wrapper" id="edit-field-end-predicted-budget-und-3-field-predicted-capex"><div id="field-end-predicted-budget-und-3-field-predicted-capex-add-more-wrapper"><div class="form-item form-type-textfield form-item-field-end-predicted-budget-und-3-field-predicted-capex-und-0-value">

                      10/2013
                      <input type="hidden" class="add_datepicker hasDatepicker" id="edit-field-mid-expected-project"><img class="ui-datepicker-trigger" src="/sites/all/themes/itdash/html/images/calendar-icon.png" alt="..." title="...">
                      <div class="form-item form-type-select form-item-field-mid-expected-project-und-0-value-day">


                      </div>
                    </div>
                  </div></div>        </td>
              <td data-sum="3" class="capex" style="background-color:white;"><div class="field-type-number-decimal field-name-field-predicted-capex field-widget-number form-wrapper" id="edit-field-end-predicted-budget-und-3-field-predicted-capex"><div id="field-end-predicted-budget-und-3-field-predicted-capex-add-more-wrapper"><div class="form-item form-type-textfield form-item-field-end-predicted-budget-und-3-field-predicted-capex-und-0-value">

                      10/2014
                      <input type="hidden" class="add_datepicker hasDatepicker" id="edit-field-mid-expected-project"><img class="ui-datepicker-trigger" src="/sites/all/themes/itdash/html/images/calendar-icon.png" alt="..." title="...">
                      <div class="form-item form-type-select form-item-field-mid-expected-project-und-0-value-day">


                      </div>
                    </div>
                  </div></div>        </td>
              <td data-sum="4" class="capex" style="background-color:white;">
                <div class="field-type-number-decimal field-name-field-predicted-capex field-widget-number form-wrapper" id="edit-field-end-predicted-budget-und-4-field-predicted-capex"><div id="field-end-predicted-budget-und-4-field-predicted-capex-add-more-wrapper"><div class="form-item form-type-textfield form-item-field-end-predicted-budget-und-4-field-predicted-capex-und-0-value">

                      <input type="checkbox" name="checkbox" id="checkbox" checked="">

                    </div>
                  </div></div>
              </td>
            </tr>
            <tr class="sum">
              <td><em>2. Lorem ipsum dolor sit amet</em></td>
              <td data-sum="1" class="capex" style="background-color:white; padding-left:3px;"><div class="field-type-number-decimal field-name-field-predicted-capex field-widget-number form-wrapper" id="edit-field-end-predicted-budget-und-1-field-predicted-capex2">
                  <div id="field-end-predicted-budget-und-1-field-predicted-capex-add-more-wrapper2">
                    <div class="form-item form-type-textfield form-item-field-end-predicted-budget-und-1-field-predicted-capex-und-0-value">

                      <select><option>Realised</option><option selected="">Partially</option><option>On Track</option><option>At Risk</option><option>Not Realised</option></select>
                    </div>
                  </div>
                </div></td>
              <td data-sum="2" class="capex" style="background-color:white;"><div class="field-type-number-decimal field-name-field-predicted-capex field-widget-number form-wrapper" id="edit-field-end-predicted-budget-und-2-field-predicted-capex2">
                  <div id="field-end-predicted-budget-und-2-field-predicted-capex-add-more-wrapper2">
                    <div class="form-item form-type-textfield form-item-field-end-predicted-budget-und-2-field-predicted-capex-und-0-value">
                      <textarea name="textarea" rows="3" type="text" width="14"></textarea>
                    </div>
                  </div>
                </div></td>
              <td data-sum="3" class="capex" style="background-color:white;"><div class="field-type-number-decimal field-name-field-predicted-capex field-widget-number form-wrapper" id="edit-field-end-predicted-budget-und-3-field-predicted-capex2">
                  <div id="field-end-predicted-budget-und-3-field-predicted-capex-add-more-wrapper2">
                    <div class="form-item form-type-textfield form-item-field-end-predicted-budget-und-3-field-predicted-capex-und-0-value">
                      <label class="element-invisible" for="edit-field-end-predicted-budget-und-3-field-predicted-capex-und-0-value2">Capex </label>
                      10/2014
                      <input type="hidden" class="add_datepicker hasDatepicker" id="edit-field-mid-expected-project2"><img class="ui-datepicker-trigger" src="/sites/all/themes/itdash/html/images/calendar-icon.png" alt="..." title="...">
                      <div class="form-item form-type-select form-item-field-mid-expected-project-und-0-value-day"></div>
                    </div>
                  </div>
                </div></td>
              <td data-sum="3" class="capex" style="background-color:white;"><div class="field-type-number-decimal field-name-field-predicted-capex field-widget-number form-wrapper" id="edit-field-end-predicted-budget-und-3-field-predicted-capex2">
                  <div id="field-end-predicted-budget-und-3-field-predicted-capex-add-more-wrapper2">
                    <div class="form-item form-type-textfield form-item-field-end-predicted-budget-und-3-field-predicted-capex-und-0-value">
                      <label class="element-invisible" for="edit-field-end-predicted-budget-und-3-field-predicted-capex-und-0-value2">Capex </label>
                      10/2015
                      <input type="hidden" class="add_datepicker hasDatepicker" id="edit-field-mid-expected-project2"><img class="ui-datepicker-trigger" src="/sites/all/themes/itdash/html/images/calendar-icon.png" alt="..." title="...">
                      <div class="form-item form-type-select form-item-field-mid-expected-project-und-0-value-day"></div>
                    </div>
                  </div>
                </div></td>
              <td data-sum="4" class="capex" style="background-color:white;"><div class="field-type-number-decimal field-name-field-predicted-capex field-widget-number form-wrapper" id="edit-field-end-predicted-budget-und-4-field-predicted-capex2">
                  <div id="field-end-predicted-budget-und-4-field-predicted-capex-add-more-wrapper2">
                    <div class="form-item form-type-textfield form-item-field-end-predicted-budget-und-4-field-predicted-capex-und-0-value">

                      <input type="checkbox" name="checkbox2" id="checkbox2" checked="checked">
                    </div>
                  </div>
                </div></td>
            </tr>
            </tbody>
          </table>
        </div>
      </div>
    <?php endif; ?>

    <?php if (!empty($update_node)) : ?>
      <?php print drupal_render(node_view($update_node)); ?>
    <?php endif; ?>

    <div class="submit">
      <?php if (isset($update_form)) : ?>
        <?php print drupal_render($update_form); ?>
      <?php endif; ?>
      <?php if (isset($edit_form)) : ?>
          <?php print $edit_form; ?>
      <?php endif; ?>
    </div>

    <?php if (isset($approve_form)) : ?>
      <?php print $approve_form; ?>
    <?php endif; ?>
  </div>
</div>
