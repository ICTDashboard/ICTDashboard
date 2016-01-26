<?php $number = 1; ?>
<?php $projects_num = $updates_num = 0; ?>
<table id="financial-benefits">
  <tr>
    <th></th>
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
        <?php if ($key == 0) : ?>
          <td rowspan="<?php print $val['count']; ?>">
            <?php if ($val['type'] == 'update') print t('Update ') . $updates_num; ?>
            <?php if ($val['type'] == 'project' && $projects_num == 1) print t('Baseline'); ?>
            <?php if ($val['type'] == 'project' && $projects_num > 1) print t('Rebaseline'); ?>
          </td>
        <?php endif; ?>
        <td><?php print $collection_wrapper->field_benefit->value(); ?></td>
        <td><?php print $collection_wrapper->field_status->value(); ?></td>
        <td><?php print $collection_wrapper->field_commentary->value(); ?></td>
        <td><?php print format_date($collection_wrapper->field_benefit_start_date->value(), 'medium', 'm/Y'); ?></td>
        <td><?php print format_date($collection_wrapper->field_end_date->value(), 'medium', 'm/Y'); ?></td>
        <td class="ict-align-center"><?php print $collection_wrapper->field_financial->value() ? '<span class="ict-tick"></span>' : '-'; ?></td>
      </tr>
    <?php endforeach; ?>
  <?php endforeach; ?>
</table>
