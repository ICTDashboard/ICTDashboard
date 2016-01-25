<?php $number = 1; ?>
<?php $projects_num = $updates_num = 0; ?>
<table id="financial-benefits">
  <tr>
    <?php if (empty($element['#baseline'])) : ?>
      <th></th>
    <?php endif; ?>
    <th><?php print t('Benefits'); ?></th>
    <th><?php print t('Realised status'); ?></th>
    <th><?php print t('Commentary'); ?></th>
    <th><?php print t('Start date'); ?></th>
    <th><?php print t('End date'); ?></th>
    <th><?php print t('Financial'); ?></th>
  </tr>
  <?php foreach($benefits as $val) : ?>
    <?php if ($val['type'] == 'project')
            $projects_num++;
          else
            $updates_num++;
    ?>
    <?php foreach($val as $key => $benefit) : ?>
      <?php if (!is_numeric($key)) continue; ?>
      <?php $collection_wrapper = entity_metadata_wrapper('field_collection_item', $benefit); ?>
      <tr>
        <td>
          <?php if ($val['type'] == 'update') print t('Update ') . $updates_num; ?>
          <?php if ($val['type'] == 'project' && $projects_num == 1) print t('Baseline'); ?>
          <?php if ($val['type'] == 'project' && $projects_num > 1) print t('Rebaseline'); ?>
        </td>
        <td><?php print $collection_wrapper->field_benefit->value(); ?></td>
        <td><?php print $collection_wrapper->field_status->value(); ?></td>
        <td><?php print $collection_wrapper->field_commentary->value(); ?></td>
        <td><?php print format_date($collection_wrapper->field_benefit_start_date->value(), 'medium', 'm/Y'); ?></td>
        <td><?php print format_date($collection_wrapper->field_end_date->value(), 'medium', 'm/Y'); ?></td>
        <td><?php print $collection_wrapper->field_financial->value() ? 'YES' : 'NO'; ?></td>
      </tr>
    <?php endforeach; ?>
  <?php endforeach; ?>
  <?php $updates_num++; ?>
  <?php foreach(element_children($element) as $key) : ?>
    <?php if (!is_numeric($key)) continue; ?>
    <tr class="<?php print !fmod($number, 2) ? 'row-blue' : 'row-white'; ?>" >
      <?php print (!empty($element['#baseline'])) ? '' : '<td>' . t('Update ') . $updates_num . '</td>'; ?>
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
      <td class="table-remove-button"><?php print drupal_render($element[$key]['remove_button']); ?></td>
    </tr>
    <?php $number ++ ?>
  <?php endforeach; ?>
</table>
<?php print drupal_render($element['add_more']); ?>
