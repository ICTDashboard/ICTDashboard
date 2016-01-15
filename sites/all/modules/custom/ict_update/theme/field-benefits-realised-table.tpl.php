<?php $number = 1; ?>
<table>
  <tr>
    <th></th>
    <th><?php print t('Benefits'); ?></th>
    <th><?php print t('Realised status'); ?></th>
    <th><?php print t('Commentary'); ?></th>
  </tr>
  <?php foreach(element_children($element) as $key) : ?>
    <?php if (!is_numeric($key)) continue; ?>
    <tr>
      <td><?php print t('Updated'); ?></td>
      <td><?php print t('Benefit ' . $number); ?></td>
      <td class="select-no-border"><?php print drupal_render($element[$key]['field_status']); ?></td>
      <td><?php print drupal_render($element[$key]['field_commentary']); ?></td>
    </tr>
    <?php $number ++ ?>
  <?php endforeach; ?>
</table>
<?php print drupal_render($element['add_more']); ?>
