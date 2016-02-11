<?php $row_num = 1; ?>
<table id="field_end_predicted_budget" class="table_field_collection">
  <tbody>
  <tr>
    <th><?php print t('FY (yy/yy)'); ?></th>
    <?php  foreach ($delta_range as $delta) : ?>
      <th>
        <?php print $max_item['budget_items'][$delta]->field_year[LANGUAGE_NONE][0]['value']; ?>
      </th>
    <?php endforeach; ?>
  </tr>
  <?php foreach ($rows as $row) : ?>
    <tr class="sum">
      <td>
        <div class="label">
          <?php print $row['title']; ?>
          <a class="tooltip" href="javascript:void(0);">
            <i class="tooltip-icon"></i>
            <span class="tooltip-content">
              <?php print $row['description']; ?>
            </span>
          </a>
          <em>($m)</em>
          <?php if ($row['type']) : ?>
            <em><?php print $row['type']; ?></em>
          <?php endif; ?>
          <em><?php print $row['date']; ?></em>
        </div>
      </td>
      <?php  foreach ($delta_range as $delta) : ?>
        <td>
          <?php if ($row_num == count($rows) && isset($diff['field_original_total_budget'][$row['budget_items'][$delta]->field_year[LANGUAGE_NONE][0]['value']])) : ?>
            <?php print itdash_edited_tooltip_render($diff['field_original_total_budget'][$row['budget_items'][$delta]->field_year[LANGUAGE_NONE][0]['value']], '$', 'm'); ?>
          <?php endif; ?>
          <?php if (!empty($row['budget_items'][$delta]->field_total[LANGUAGE_NONE][0]['value'])) : ?>
            <?php print '$' . $row['budget_items'][$delta]->field_total[LANGUAGE_NONE][0]['value'] . 'm'; ?>
          <?php endif; ?>
        </td>
      <?php endforeach; ?>
      <?php $row_num++; ?>
    </tr>
  <?php endforeach; ?>
  </tbody>
</table>
