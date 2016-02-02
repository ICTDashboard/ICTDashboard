<div id="inner-content" class="wrap cf">
  <div class="project-draft-submission d-all">
    <?php dsm($form); ?>
    <div class="row">
      <div class="label">
        <?php print drupal_render($form['description']); ?>
        </div>
    </div>

    <div class="submit">
      <div style="margin-bottom: 20px; text-align: right;" class="text">
        <?php print render($form['actions']['cancel']); ?>
        <?php print render($form['actions']['submit']); ?>
      </div>
    </div>

    <?php print drupal_render_children($form); ?>
  </div>
</div>