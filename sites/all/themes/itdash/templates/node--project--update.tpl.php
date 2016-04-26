    <h2><?php print t('Project Information'); ?></h2>
    
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
        <?php foreach (_ict_project_baseline_get_simple_values($field_implementation_partners, TRUE) as $value) : ?>
          <p><?php print $value; ?></p>
        <?php endforeach; ?>
      </div>
    </div>

    <div class="row">
      <div class="label">
        <?php print t('Project Title'); ?>
        <a href="javascript:void(0);" class="tooltip">
          <i class="tooltip-icon"></i>
          <span class="tooltip-content">
            <?php print t('The official full name of the project, excluding acronyms.'); ?>
          </span>
        </a>
      </div>
      <div class="text">
        <?php print $title; ?>
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
          <?php print $value; ?>
        <?php endforeach; ?>
      </div>
    </div>
