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
        <div class="label">
          <?php print $field_benefits_realised['meta']['#title'] . ' <em>($m)</em>'; ?>
          <?php if (!empty($field_benefits_realised['meta']['#description'])) : ?>
            <a href="javascript:void(0);" class="tooltip">
              <i class="tooltip-icon"></i>
            <span class="tooltip-content">
              <?php print $field_benefits_realised['meta']['#description']; ?>
            </span>
            </a>
          <?php endif; ?>
        </div>
        <div class="text">
          <?php print theme('field_benefits_realised_table_view', array('project_id' => $nid)); ?>
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
