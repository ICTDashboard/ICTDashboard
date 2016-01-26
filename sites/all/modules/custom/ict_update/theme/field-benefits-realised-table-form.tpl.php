<?php $number = 1; ?>
<?php $projects_num = $updates_num = 0; ?>
<table id="financial-benefits" class="table_field_collection">
  <tr>
    <?php if (empty($element['#baseline'])) : ?>
      <th></th>
    <?php endif; ?>
    <th><div class="label"><?php print t('Benefits'); ?><a href="javascript:void(0);" class="tooltip"><i class="tooltip-icon"></i><span class="tooltip-content">List the benefits (quantitative or qualitative) this project will deliver or contribute to, as identified in the business case.
  </span></a></div></th>
    <th>
      <div class="label">
        <?php print t('Realised status'); ?>
        <a href="javascript:void(0);" class="tooltip"><i class="tooltip-icon"></i><span class="tooltip-content">For each benefit listed, indicate the status of benefit realisation. Realised - The benefit has been realised; Partially - The benefit has been partially realised; On Track – The project is on track to realise the benefit as originally expected; At Risk - The benefit is not likely to be realised as originally expected; Not Realised - The benefit has not been realised.
  </span></a>
      </div>
    </th>
    <th>
      <div class="label">
        <?php print t('Commentary'); ?>
      </div>
    </th>
    <th colspan="2">
      <div class="label">
        <?php print t('Date Range: Start - End'); ?>
        <a href="javascript:void(0);" class="tooltip"><i class="tooltip-icon"></i><span class="tooltip-content">For each benefit listed, the date range when benefit is expected to be realised.
  </span></a>
      </div>
    </th>
    <th>
      <div class="label">
        <?php print t('Financial'); ?>
        <a href="javascript:void(0);" class="tooltip"><i class="tooltip-icon"></i><span class="tooltip-content">For each benefit listed, mark those where the benefit can be measured financially.
  </span></a>
      </div>
    </th>
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
  <?php $updates_num++; ?>
  <?php foreach(element_children($element) as $key) : ?>
    <?php if (!is_numeric($key)) continue; ?>
    <tr class="<?php print !fmod($number, 2) ? 'row-blue' : 'row-white'; ?>" >
      <?php if ($key == 0) : ?>
        <?php print (!empty($element['#baseline'])) ? '' : '<td rowspan="' . (count(element_children($element)) -1) . '">' . t('Update ') . $updates_num . '</td>'; ?>
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
      <td class="table-remove-button"><?php print drupal_render($element[$key]['remove_button']); ?></td>
    </tr>
    <?php $number ++ ?>
  <?php endforeach; ?>
</table>
<?php print drupal_render($element['add_more']); ?>
