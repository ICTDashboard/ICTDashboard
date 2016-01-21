<?php $number = 1; ?>
<table>
  <tr>
    <th></th>
    <th><?php print t('Benefits'); ?></th>
    <th><?php print t('Realised status'); ?></th>
    <th><?php print t('Commentary'); ?></th>
    <th><?php print t('Start date'); ?></th>
    <th><?php print t('End date'); ?></th>
    <th><?php print t('Financial'); ?></th>
  </tr>
  <?php foreach(element_children($element) as $key) : ?>
    <?php if (!is_numeric($key)) continue; ?>
    <tr>
      <td><?php print t('Updated'); ?></td>
      <td><?php print drupal_render($element[$key]['field_benefit']); ?></td>
      <td class="select-no-border"><?php print drupal_render($element[$key]['field_status']); ?></td>
      <td><?php print drupal_render($element[$key]['field_commentary']); ?></td>
      <td><?php print drupal_render($element[$key]['field_benefit_start_date']); ?></td>
      <td><?php print drupal_render($element[$key]['field_end_date']); ?></td>
      <td><?php print drupal_render($element[$key]['field_financial']); ?></td>
    </tr>
    <?php $number ++ ?>
  <?php endforeach; ?>
</table>
<?php print drupal_render($element['add_more']); ?>
