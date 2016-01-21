<div class="submit">
  <div style="margin-bottom: 20px; text-align: right;" class="text">
    <?php print render($form['decline']); ?>
    <?php print render($form['approve']); ?>
  </div>
</div>


<div style="display:none;">
  <?php print drupal_render_children($form); ?>
</div>