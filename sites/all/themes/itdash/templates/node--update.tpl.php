<?php if ($viz_preview) { $diff = array(); } ?>
<div id="inner-content" class="wrap cf">
  <h2><?php print t(' Project Expenditure and Budget'); ?>
  </h2>
  <div class="project-draft-submission d-all individual-project-content">
    <div class="row">
      <div class="label">
        <?php print t('Total Expenditure To Date'); ?>
      </div>
      <div class="text">
          <?php print '$' . $total_expenditure_number . 'm'; ?>
        </div>
    </div>

    <div class="row">
      <div class="label">
        <?php print $is_rebaseline ?
          t('Total Project Budget') :
          t('Original Total Project Budget'); ?>
      </div>
      <div class="text">
        <?php print '$' . $original_total_budget_number . 'm'; ?>
      </div>
    </div>

    <div class="row">
      <div class="label">
        <?php print t('Project Expenditure and Budget'); ?>
        <?php if (!empty($original_total_budget_meta['#description']) && $view_mode != 'print') : ?>
          <a href="javascript:void(0);" class="tooltip">
            <i class="tooltip-icon"></i>
              <span class="tooltip-content individual-page-tooltip-height">
                <?php print $original_total_budget_meta['#description']; ?>
              </span>
          </a>
        <?php endif; ?>
        <?php if ($view_mode != 'print'): ?>
          <?php print $preview_switch; ?>
        <?php endif; ?>
      </div>
      <div class="text">
        <?php print $field_original_total_budget; ?>
      </div>
    </div> 
    <div class="project-timings"><h2><?php print t('Project Schedule'); ?>
    </h2></div>
    <?php if (!$viz_preview) : ?>
      <div class="row">
        <div class="label">
          <?php if (isset($diff['field_actual_level_of_project_co'])) : ?>
            <?php print itdash_edited_tooltip_render($diff['field_actual_level_of_project_co'], '', '%', TRUE); ?>
          <?php endif; ?>
          <?php print $field_actual_level_of_project_co['meta']['#title']; ?>
          <?php if (!empty($field_actual_level_of_project_co['meta']['#description']) && $view_mode != 'print') : ?>
            <a href="javascript:void(0);" class="tooltip">
              <i class="tooltip-icon"></i>
              <span class="tooltip-content individual-page-tooltip-height">
                <?php print $field_actual_level_of_project_co['meta']['#description']; ?>
              </span>
            </a>
          <?php endif; ?>
          <?php if ($view_mode != 'print'): ?>
            <?php print $preview_switch; ?>
          <?php endif; ?>
        </div>
        <div class="text">
          <?php foreach (_ict_project_baseline_get_simple_values($field_actual_level_of_project_co, FALSE, '', '%', FALSE, TRUE) as $value) : ?>
            <p><?php print $value; ?></p>
          <?php endforeach; ?>
        </div>
      </div>

      <div class="row">
        <div class="label">
          <?php if (isset($diff['field_forecast_level_of_project_'])) : ?>
            <?php print itdash_edited_tooltip_render($diff['field_forecast_level_of_project_'], '', '%', TRUE); ?>
          <?php endif; ?>
          <?php print $field_forecast_level_of_project_['meta']['#title']; ?>
          <?php if (!empty($field_forecast_level_of_project_['meta']['#description']) && $view_mode != 'print') : ?>
            <a href="javascript:void(0);" class="tooltip">
              <i class="tooltip-icon"></i>
              <span class="tooltip-content individual-page-tooltip-height">
                <?php print $field_forecast_level_of_project_['meta']['#description']; ?>
              </span>
            </a>
          <?php endif; ?>
          <?php if ($view_mode != 'print'): ?>
            <?php print $preview_switch; ?>
          <?php endif; ?>
        </div>
        <div class="text">
          <?php foreach (_ict_project_baseline_get_simple_values($field_forecast_level_of_project_, FALSE, '', '%', FALSE, TRUE) as $value) : ?>
            <p><?php print $value; ?></p>
          <?php endforeach; ?>
        </div>
      </div>
    <?php else : ?>
      <div class="row">
        <div class="label">
          <?php print t('Project Schedule Status'); ?>
          <a href="javascript:void(0);" class="tooltip">
            <i class="tooltip-icon"></i>
            <span class="tooltip-content individual-page-tooltip-height">
              <?php print t('The actual percentage of work completed at the current update and the percentage of work forecasted to be completed at the current update.'); ?>
            </span>
          </a>
          <?php if ($view_mode != 'print'): ?>
            <?php print $preview_switch; ?>
          <?php endif; ?>
        </div>
        <div class="text">
          <?php print $project_schedule_status_viz; ?>
        </div>
      </div>
    <?php endif; ?>       
    <div class="row">
      <div class="label">
        <?php if (!empty($diff['field_project_stage'])) : ?>
          <?php print itdash_edited_tooltip_render($diff['field_project_stage']->name); ?>
        <?php endif; ?>
        <?php print $field_project_stage['meta']['#title']; ?>
        <?php if (!empty($field_project_stage['meta']['#description']) && $view_mode != 'print') : ?>
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

    <?php $field_start_date_info = field_info_instance('node', 'field_start_date', 'project');?>
    <div class="row">
      <div class="label">
        <?php print $is_rebaseline ?
          str_replace('Original ', '', $field_start_date_info['label']) :
          $field_start_date_info['label']; ?>
        <?php if (!empty($field_start_date_info['description']) && $view_mode != 'print') : ?>
          <a href="javascript:void(0);" class="tooltip">
            <i class="tooltip-icon"></i>
            <span class="tooltip-content">
              <?php print $field_start_date_info['description']; ?>
            </span>
          </a>
        <?php endif; ?>
      </div>
      <div class="text">
        <?php print format_date(strtotime($project_node->field_start_date['und'][0]['value']), 'medium', 'j F Y'); ?></div>
    </div>

    <?php $field_original_completion_date_info = field_info_instance('node', 'field_original_completion_date', 'project');?>
    <div class="row">
      <div class="label">
        <?php print $is_rebaseline ?
          str_replace('Original ', '', $field_original_completion_date_info['label']) :
          $field_original_completion_date_info['label']; ?>
        <?php if (!empty($field_original_completion_date_info['description']) && $view_mode != 'print') : ?>
          <a href="javascript:void(0);" class="tooltip">
            <i class="tooltip-icon"></i>
            <span class="tooltip-content">
              <?php print $field_original_completion_date_info['description']; ?>
            </span>
          </a>
        <?php endif; ?>
      </div>
      <div class="text">
        <?php print format_date(strtotime($project_node->field_original_completion_date['und'][0]['value']), 'medium', 'j F Y'); ?></div>
    </div>

    <div class="row">
      <div class="label">
        <?php if (!empty($diff['field_expected_completion_date'])) : ?>
          <?php print itdash_edited_tooltip_render(format_date($diff['field_expected_completion_date'], 'medium', 'd M Y')); ?>
        <?php endif; ?>
        <?php print $field_expected_completion_date['meta']['#title']; ?>
        <?php if (!empty($field_expected_completion_date['meta']['#description']) && $view_mode != 'print') : ?>
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
          <p><?php print $value; ?></p>
        <?php endforeach; ?>
      </div>
    </div>
    <?php $field_predicted_project_benefit_info = field_info_instance('node', 'field_predicted_project_benefit', 'project');?>

    <div class="project-benefits">
      <h2 id="project-benefits"><?php print t('Project Benefits'); ?>
        <?php if ($view_mode != 'print') : ?>
          <a href="javascript:void(0);" class="tooltip">
            <i class="tooltip-icon"></i>
            <span class="tooltip-content">
              <?php print variable_get('ict_project_benefits_tooltip_text', "The measurable advantage to stakeholders, realised during or after the project has finished, as a result of the new capabilities produced."); ?>
            </span>
          </a>
        <?php endif; ?>
      </h2>
    </div>
    
    <div class="row">
      <div class="label">
        <?php print $is_rebaseline ?
          str_replace('Original ', '', $field_predicted_project_benefit_info['label']) :
          $field_predicted_project_benefit_info['label']; ?>
        <?php if (!empty($field_predicted_project_benefit_info['description']) && $view_mode != 'print') : ?>
          <a href="javascript:void(0);" class="tooltip">
            <i class="tooltip-icon"></i>
            <span class="tooltip-content">
              <?php print $field_predicted_project_benefit_info['description']; ?>
            </span>
          </a>
        <?php endif; ?>
      </div>
      <div class="text">
        $<?php print number_format($project_node->field_predicted_project_benefit['und'][0]['value'], 2, '.', ''); ?>m
      </div>
    </div>
    <div class="row">
      <div class="label">
        <?php if (isset($diff['field_current_financial_benefits'])) : ?>
          <?php print itdash_edited_tooltip_render(number_format($diff['field_current_financial_benefits'], 2, '.', ''), '$', 'm', TRUE); ?>
        <?php endif; ?>
        <?php print $field_current_financial_benefits['meta']['#title']; ?>
        <?php if (!empty($field_current_financial_benefits['meta']['#description']) && $view_mode != 'print') : ?>
          <a href="javascript:void(0);" class="tooltip">
            <i class="tooltip-icon"></i>
            <span class="tooltip-content">
              <?php print $field_current_financial_benefits['meta']['#description']; ?>
            </span>
          </a>
        <?php endif; ?>
      </div>
      <div class="text">
        <?php foreach (_ict_project_baseline_get_simple_values($field_current_financial_benefits, FALSE, '$', 'm', TRUE) as $value) : ?>
          <p><?php print $value; ?></p>
        <?php endforeach; ?>
      </div>
    </div>

    <div class="row">
      <div class="label">
        <?php if (isset($diff['field_estimated_value_of_benefit'])) : ?>
          <?php print itdash_edited_tooltip_render(number_format($diff['field_estimated_value_of_benefit'], 2, '.', ''), '$', 'm', TRUE); ?>
        <?php endif; ?>
        <?php print $field_estimated_value_of_benefit['meta']['#title']; ?>
        <?php if (!empty($field_estimated_value_of_benefit['meta']['#description']) && $view_mode != 'print') : ?>
          <a href="javascript:void(0);" class="tooltip">
            <i class="tooltip-icon"></i>
            <span class="tooltip-content">
              <?php print $field_estimated_value_of_benefit['meta']['#description']; ?>
            </span>
          </a>
        <?php endif; ?>
      </div>
      <div class="text">
        <?php foreach (_ict_project_baseline_get_simple_values($field_estimated_value_of_benefit, FALSE, '$', 'm', TRUE) as $value) : ?>
          <p><?php print $value; ?></p>
        <?php endforeach; ?>
      </div>
    </div>
    <?php if ($viz_preview) : ?>
      <div class="row">
        <div class="label">
          <?php print t('Project Benefits Status'); ?>
          <?php if ($view_mode != 'print'): ?>
            <?php print $preview_switch; ?>
          <?php endif; ?>
        </div>
        <div class="text">
          <?php print $project_benefits_pie_chart; ?>
        </div>
      </div>
    <?php endif; ?>

    <?php if (!empty($project_id)) : ?>
      <div class="row">
        <?php if (!$viz_preview) : ?>
        <div class="label">
          <?php print t('Benefits Realised'); ?>
          <?php if ($view_mode != 'print'): ?>
            <?php print $preview_switch; ?>
          <?php endif; ?>
          <?php if (!empty($form['field_benefits_realised']['#description']) && $view_mode != 'print') : ?>
            <a href="javascript:void(0);" class="tooltip">
              <i class="tooltip-icon"></i>
                <span class="tooltip-content">
                  <?php print $form['field_benefits_realised']['#description']; ?>
                </span>
            </a>
          <?php endif; ?>
        </div>
        <?php endif; ?>
        <div class="text">
          <?php print theme('field_benefits_realised_table_view', array(
            'project_id' => $project_id,
            'diff' => $diff,
            'viz' => $viz_preview,
          )); ?>
        </div>
      </div>
    <?php endif; ?>


    <div class="row">
      <div class="label">
        <?php if (isset($diff['field_entity_comments'])) : ?>
          <?php print itdash_edited_tooltip_render($diff['field_entity_comments']['value'], '', '', TRUE, TRUE); ?>
        <?php endif; ?>
        <?php print $field_entity_comments['meta']['#title']; ?>
        <?php if (!empty($field_entity_comments['meta']['#description']) && $view_mode != 'print') : ?>
          <a href="javascript:void(0);" class="tooltip">
            <i class="tooltip-icon"></i>
            <span class="tooltip-content">
              <?php print $field_entity_comments['meta']['#description']; ?>
            </span>
          </a>
        <?php endif; ?>
      </div>
      <div class="text entity_comments">
        <?php foreach (_ict_project_baseline_get_simple_values($field_entity_comments) as $value) : ?>
          <?php print $value; ?>
        <?php endforeach; ?>
      </div>
    </div>

  </div>
</div>
