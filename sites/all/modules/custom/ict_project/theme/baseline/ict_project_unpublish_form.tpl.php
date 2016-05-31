<div class="ict-fancy-content">
  <div class="row">
    <div class="label"><?php print t('Unpublishing comment'); ?></div>
    <div class="text">
      <?php print render($form['project_id']); ?>
      <?php print render($form['comment']); ?>
      <br />
      <p>
        <strong><?php print t('Note: '); ?></strong>
        <em>
          <?php print t('This comment will be sent to all users associated to this project'); ?>
        </em>
      </p>
    </div>
  </div>
</div>
<div class="fancybox-actions">
  <a class="ict-fancybox-close export-btn" href="#"><span><?php print t('Cancel'); ?></span></a>
  <?php print render($form['submit']); ?>
</div>

<?php print drupal_render_children($form) ?>