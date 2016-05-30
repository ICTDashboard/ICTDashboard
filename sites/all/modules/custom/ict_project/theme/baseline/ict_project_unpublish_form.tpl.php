<div class="ict-fancy-content entity-bean">
  <?php print render($form['project_id']); ?>
  <?php print render($form['comment']); ?>
</div>
<div class="fancybox-actions">
  <a class="ict-fancybox-close export-btn" href="#"><span><?php print t('Cancel'); ?></span></a>
  <?php print render($form['submit']); ?>
</div>

<?php print drupal_render_children($form) ?>