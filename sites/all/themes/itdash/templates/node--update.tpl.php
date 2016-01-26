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
        <?php print $field_original_total_budget; ?>
      </div>
    </div>

    <?php if (!empty($project_id)) : ?>
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
          <?php print theme('field_benefits_realised_table_view', array('project_id' => $project_id)); ?>
        </div>
      </div>
    <?php endif; ?>

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
