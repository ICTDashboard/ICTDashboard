<div class="page-title dotbg">
  <div class="inner-title-content wrap cf">
    <h1><?php print t('Edit Baseline Draft'); ?></h1>
  </div>
</div>
<div id="inner-content" class="wrap cf">
  <h2>Update data</h2>
  <h3>Basic project information</h3>
  <div class="project-draft-submission d-all">

    <div class="row">
      <div class="label">Government Entity Name <a href="javascript:void(0);" class="tooltip"><i class="tooltip-icon"></i><span class="tooltip-content">The Government department or entity responsible for leading the project.</span></a></div>
      <div class="text">
        <?php print render($form['field_government_entity_name']); ?>
      </div>
    </div>

    <div class="row">
      <div class="label">Portfolio Name<a href="javascript:void(0);" class="tooltip"><i class="tooltip-icon"></i><span class="tooltip-content">The Portfolio for which the department or entity belongs.</span></a></div>
      <div class="text">
        <?php print render($form['field_portfolio_name']); ?>
      </div>
    </div>

    <div class="dotted-line"></div>

    <div class="row">
      <div class="label">
        Other fields ...
      </div>
    </div>

    <div class="row">
      <div class="label">
        Other fields ...
      </div>
    </div>

    <div class="row">
      <div class="label">
        Other fields ...
      </div>
    </div>

    <div class="row">
      <div class="label">
        Other fields ...
      </div>
    </div>

    <div class="dotted-line"></div>

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
