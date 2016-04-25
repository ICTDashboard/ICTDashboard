<?php if ($viz_preview) { $diff = array(); } ?>
<div class="page-title dotbg">
  <div class="inner-title-content wrap cf">
    <h1><?php print $title; ?></h1>
  </div>
</div>

<div id="inner-content" class="wrap cf">
  <h2><?php print t('Project Information'); ?></h2>
  <div class="project-draft-submission d-all ict-view-page">

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
        <?php if (!empty($diff['field_implementation_partners'])) : ?>
          <?php print itdash_edited_tooltip_render($diff['field_implementation_partners']); ?>
        <?php endif; ?>
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
        <?php if (!$project_updates_available) : ?>
          <?php foreach (_ict_project_baseline_get_simple_values($field_implementation_partners, TRUE) as $value) : ?>
            <p><?php print $value; ?></p>
          <?php endforeach; ?>
        <?php else : ?>
          <?php foreach (_ict_project_baseline_get_simple_values($update_node->field_implementation_partners['und']) as $value) : ?>
            <p><?php print $value; ?></p>
          <?php endforeach; ?>
        <?php endif; ?>
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
  <?php  if(!user_is_anonymous()) : ?>

    <div class="user-information"><h2>
    <?php print t('User Information'); ?>
      <a href="javascript:void(0);" class="tooltip">
        <i class="tooltip-icon"></i>
        <span class="tooltip-content">
          <?php print variable_get('ict_project_user_information_text', "No user information is made publicly available."); ?>
        </span>
      </a>
    </h2>
    </div>

    <div class="row">
      <div class="label">
        <?php if (!empty($diff['field_responsible_officer_name'])) : ?>
          <?php print itdash_edited_tooltip_render($diff['field_responsible_officer_name']); ?>
        <?php endif; ?>
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
        <?php if (!$project_updates_available) : ?>
          <?php foreach (_ict_project_baseline_get_simple_values($field_responsible_officer_name) as $value) : ?>
            <p><?php print $value; ?></p>
          <?php endforeach; ?>
        <?php else : ?>
          <?php foreach (_ict_project_baseline_get_simple_values($update_node->field_responsible_officer_name['und']) as $value) : ?>
            <p><?php print $value; ?></p>
          <?php endforeach; ?>
        <?php endif; ?>
      </div>
    </div>
    <div class="row">
      <div class="label">
        <?php if (!empty($diff['field_resp_officer_position'])) : ?>
          <?php print itdash_edited_tooltip_render($diff['field_resp_officer_position']); ?>
        <?php endif; ?>
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
        <?php if (!$project_updates_available) : ?>
          <?php foreach (_ict_project_baseline_get_simple_values($field_resp_officer_position) as $value) : ?>
            <p><?php print $value; ?></p>
          <?php endforeach; ?>
        <?php else : ?>
          <?php foreach (_ict_project_baseline_get_simple_values($update_node->field_resp_officer_position['und']) as $value) : ?>
            <p><?php print $value; ?></p>
          <?php endforeach; ?>
        <?php endif; ?>
      </div>
    </div>

    <?php print $admin_user_details; ?>

    <?php endif; ?>

    <?php if (!$project_updates_available) : ?>
      <h3><?php print t('Schedule, Expenditures and Benefits'); ?></h3>

      <div class="row">
        <div class="label">
          <?php if (!empty($diff['field_project_stage'])) : ?>
            <?php print itdash_edited_tooltip_render($diff['field_project_stage']->name); ?>
          <?php endif; ?>
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
          <?php print t('Project Budget By Financial Year'); ?>
          <?php if (!empty($original_total_budget_meta['#description'])) : ?>
            <a href="javascript:void(0);" class="tooltip">
              <i class="tooltip-icon"></i>
              <span class="tooltip-content">
                <?php print $original_total_budget_meta['#description']; ?>
              </span>
            </a>
          <?php endif; ?>
          <?php print $preview_switch; ?>
        </div>
        <div class="text">
          <?php print $field_original_total_budget; ?>
        </div>
      </div>

      <div class="row">
        <div class="label">
          <?php print t('Total Project Budget'); ?>
        </div>
        <div class="text">
          <?php print '$' . $original_total_budget_number . 'm'; ?>
        </div>
      </div>

      <?php if ($viz_preview) : ?>
        <div class="row">
          <div class="label">
            <?php print t('Project Benefits Status'); ?>
            <?php print $preview_switch; ?>
          </div>
          <div class="text">
            <?php print $project_benefits_pie_chart; ?>
          </div>
        </div>
      <?php endif; ?>

      <div class="row">
        <?php if (!$viz_preview) : ?>
          <div class="label">
            <?php print t('Benefits Realised'); ?>
            <?php print $preview_switch; ?>
            <?php if (!empty($form['field_benefits_realised']['#description'])) : ?>
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
          <?php print theme('field_benefits_realised_table_view', array('project_id' => $nid)); ?>
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
          <?php foreach (_ict_project_baseline_get_simple_values($field_predicted_project_benefit, FALSE, '$', 'm', TRUE) as $value) : ?>
            <p><?php print $value; ?></p>
          <?php endforeach; ?>
        </div>
      </div>

    <?php endif; ?>
    <?php if (!empty($update_node)) : ?>
      <?php print drupal_render(node_view($update_node)); ?>
    <?php endif; ?>

    <?php if (!empty($diff)) : ?>
      <p><em><?php print itdash_edited_tooltip_render() . ' - ' . t('fields that was updated.'); ?></em></p>
    <?php endif; ?>

    <?php if (isset($update_form)) : ?>
      <?php print $update_form; ?>
    <?php endif; ?>

    <?php if (isset($edit_form)) : ?>
      <?php print $edit_form; ?>
    <?php endif; ?>

    <?php if (isset($approve_form)) : ?>
      <?php print $approve_form; ?>
    <?php endif; ?>
  </div>
</div>
<?php print theme('ict_pages_last_update', array('nid' => $nid));
