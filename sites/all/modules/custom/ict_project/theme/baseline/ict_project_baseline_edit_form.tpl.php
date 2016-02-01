<div class="submit">
  <div style="margin-bottom: 20px; text-align: right;" class="text">
    <?php print render($form['edit']); ?>
    <?php print render($form['request_approve']); ?>
  </div>
</div>

<div style="display:none;">
  <?php print drupal_render_children($form); ?>
</div>
