<?php $number = 1; ?>
<table id="financial-benefits">
  <tr>
    <?php if (!empty($element['#baseline'])) : ?>
      <th></th>
    <?php endif; ?>
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
      <?php if (!empty($element['#baseline'])) : ?>
        <td><?php print (!empty($element['#baseline'])) ? t('Baseline') : t('Updated'); ?></td>
      <?php endif; ?>
      <td><?php print drupal_render($element[$key]['field_benefit']); ?></td>
      <td class="select-no-border"><?php print drupal_render($element[$key]['field_status']); ?></td>
      <td><?php print drupal_render($element[$key]['field_commentary']); ?></td>
      <?php $element[$key]['field_benefit_start_date']['und'][0]['value']['date']['#title'] =
            $element[$key]['field_benefit_start_date']['und'][0]['value']['date']['#description'] =
            $element[$key]['field_end_date']['und'][0]['value']['date']['#title'] =
            $element[$key]['field_end_date']['und'][0]['value']['date']['#description'] = ''; ?>
      <td><?php print drupal_render($element[$key]['field_benefit_start_date']); ?></td>
      <td><?php print drupal_render($element[$key]['field_end_date']); ?></td>
      <td><?php print drupal_render($element[$key]['field_financial']); ?></td>
      <td><?php print drupal_render($element[$key]['remove_button']); ?></td>
    </tr>
    <?php $number ++ ?>
  <?php endforeach; ?>
</table>
<?php print drupal_render($element['add_more']); ?>
