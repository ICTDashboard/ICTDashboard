<div class="project-update-submission">
  <div class="row">
    <div class="label"><?php print $form['account']['mail']['#title']; ?></div>
    <div class="text"><?php  print drupal_render($form['account']['mail']); ?></div>
  </div>
  <div class="row">
    <div class="label"><?php print $form['field_first_name']['und'][0]['value']['#title']; ?></div>
    <div class="text"><?php  print drupal_render($form['field_first_name']); ?></div>
  </div>
  <div class="row">
    <div class="label"><?php print $form['field_last_name']['und'][0]['value']['#title']; ?></div>
    <div class="text"><?php  print drupal_render($form['field_last_name']); ?></div>
  </div>
  <div class="row">
    <div class="label"><?php print $form['field_department']['und']['#title']; ?></div>
    <div class="text"><?php  print drupal_render($form['field_department']); ?></div>
  </div>

  <?php print drupal_render($form['actions']['submit']); ?>

</div>

<div class="element-hidden">
  <?php print drupal_render_children($form); ?>
</div>
