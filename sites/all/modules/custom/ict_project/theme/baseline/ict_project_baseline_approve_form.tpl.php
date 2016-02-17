<div class="submit">
  <div style="margin-bottom: 20px; text-align: right;" class="text">
    <a href="#ict-baseline-decline-form" class="general-button submit-button fancybox-baseline-decline-form"><span><?php print t('Reject Submission'); ?></span></a>
    <?php print render($form['approve']); ?>
  </div>
</div>

<div style="display: none;" id="ict-baseline-decline-form">
  <h2 class="fancybox-title"><?php print t('Reject Submission'); ?></h2>
  <div class="ict-fancy-content">
    <div class="row">
      <div class="label"><?php print t('Rejection comment'); ?></div>
      <div class="text">
        <?php print drupal_render($form['comment']); ?>
      </div>
    </div>
  </div>
  <div class="fancybox-actions">
    <a class="ict-fancybox-close general-button" href="#"><span><?php print t('CANCEL'); ?></span></a>
    <?php print render($form['decline']); ?>
  </div>
</div>

<div style="display:none;">
  <?php print drupal_render_children($form); ?>
</div>
