<div id="inner-content" class="wrap cf">
  <div class="project-update-submission d-all">
    <?php print drupal_render(node_view($form['#project_node'], 'update')); ?>

    <div class="user-information"><h2><?php print t('User Information'); ?></h2></div>
    <div class="row">
      <div class="label"><?php print $form['field_responsible_officer_name']['und']['#title']; ?></div>
      <div class="text"><?php print drupal_render($form['field_responsible_officer_name']); ?></div>
    </div>
    <div class="row">
      <div class="label"><?php print $form['field_resp_officer_position']['und']['#title']; ?></div>
      <div class="text"><?php print drupal_render($form['field_resp_officer_position']); ?></div>
    </div>
    <?php print $form['#admin_user_details']; ?>
    <div class="dotted-line"></div>

    <h2><?php print t('Project Expenditure and Budget'); ?></h2>
    <div class="row">
      <div class="label"><?php print $form['field_project_stage']['und']['#title']; ?></div>
      <div class="text"><?php print drupal_render($form['field_project_stage']); ?></div>
    </div>
    <div class="row">
      <div class="label"><?php print t('Original Approved Start Date'); ?> </div>
      <div class="text"><?php print format_date(strtotime($form['#project_node']->field_start_date['und'][0]['value']), 'medium', 'j F Y'); ?></div>
    </div>
    <div class="row">
      <div class="label"><?php print t('Original Approved Completion Date'); ?></div>
      <div class="text"><?php print format_date(strtotime($form['#project_node']->field_original_completion_date['und'][0]['value']), 'medium', 'j F Y'); ?></div>
    </div>
    <div class="row">
      <div class="label"><?php print $form['field_expected_completion_date']['und']['#title']; ?><a href="javascript:void(0);" class="tooltip"><i class="tooltip-icon"></i><span class="tooltip-content">The current expected completion date of the project.</span></a></div>
      <div class="text"><div class="date-field-wrapper"><?php print drupal_render($form['field_expected_completion_date']); ?></div></div>
    </div>
    <div class="row">
      <div class="label"><?php print $form['field_actual_level_of_project_co']['und']['#title'] . ' <em>(%)</em>'; ?><a href="javascript:void(0);" class="tooltip"><i class="tooltip-icon"></i><span class="tooltip-content">The actual percentage of work completed at the current update.</span></a></div>
      <div class="text">
        <?php print drupal_render($form['field_actual_level_of_project_co']); ?>
      </div>
    </div>
    <div class="row">
      <div class="label"><?php print $form['field_forecast_level_of_project_']['und']['#title'] . ' <em>(%)</em>'; ?><a href="javascript:void(0);" class="tooltip"><i class="tooltip-icon"></i><span class="tooltip-content">The percentage of work forecasted to be completed at the current update.</span></a></div>
      <div class="text"><?php print drupal_render($form['field_forecast_level_of_project_']); ?></div>
    </div>

    <div class="row">
      <div class="label">
        <?php print t('Project Budget By Financial Year'); ?>
        <?php if (!empty($form['field_original_total_budget'][LANGUAGE_NONE]['#description'])) : ?>
          <a href="javascript:void(0);" class="tooltip">
            <i class="tooltip-icon"></i>
            <span class="tooltip-content">
              <?php print $form['field_original_total_budget'][LANGUAGE_NONE]['#description']; ?>
            </span>
          </a>
        <?php endif; ?>
      </div>
      <div class="text">
        <?php print render($form['field_original_total_budget']); ?>
      </div>
    </div>

    <div class="row">
      <div class="label">
        <?php print t('Total Project Budget'); ?>
      </div>
      <div class="text">
        <?php print render($form['original_total_budget_number']); ?>
      </div>
    </div>

    <div class="row">
      <div class="label">
        <?php print t('Total Project Expenditure'); ?>
      </div>
      <div class="text">
        <span id="total-project-expenditure">$0.00m</span>
      </div>
    </div>

    <div class="row">
      <div class="label"><?php print $form['field_benefits_realised']['und']['#title']; ?></div>
      <div class="text"><?php print drupal_render($form['field_benefits_realised']); ?></div>
    </div>
    <div class="row">
      <div class="label">Original Expected Financial Benefits<a href="javascript:void(0);" class="tooltip"><i class="tooltip-icon"></i><span class="tooltip-content">The financial value of benefits expected by the project as identified in the business case. Where project is part of a larger programme, only use benefits that this project will deliver or contribute to.</span></a></div>
      <div class="text">$<?php print number_format($form['#project_node']->field_predicted_project_benefit['und'][0]['value'], 2, '.', ''); ?>m</div>
    </div>
    <div class="row">
      <div class="label"><?php print $form['field_current_financial_benefits']['und']['#title'] . ' <em>($m)</em>'; ?><a href="javascript:void(0);" class="tooltip"><i class="tooltip-icon"></i><span class="tooltip-content">The current financial value of benefits expected by the project. Where project is part of a larger programme, only use benefits that this project will deliver or contribute to.</span></a></div>
      <div class="text">
        <?php print drupal_render($form['field_current_financial_benefits']); ?>
      </div>
      <div class="text"></div>
    </div>
    <div class="row">
      <div class="label"><?php print $form['field_estimated_value_of_benefit']['und']['#title'] . ' <em>($m)</em>'; ?><a href="javascript:void(0);" class="tooltip"><i class="tooltip-icon"></i><span class="tooltip-content">The estimated financial benefits that have been realised to date.</span></a></div>
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
        <?php print render($form['actions']['submit_approve']); ?>
      </div>
      <div style="overflow:hidden; text-align: right;" class="text">
        <?php print render($form['actions']['submit_request']); ?>
        <?php print render($form['actions']['submit_decline']); ?>
      </div>
    </div>
  </div>
</div>
<div class="element-invisible">
  <?php print drupal_render_children($form); ?>
</div>
