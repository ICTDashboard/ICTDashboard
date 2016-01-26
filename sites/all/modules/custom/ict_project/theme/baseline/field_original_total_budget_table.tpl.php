<?php $element_keys = element_children($element); ?>

<table id="field_end_predicted_budget" class="table_field_collection">
  <tbody>
  <tr>
    <th><?php print t('FY (yy/yy)'); ?></th>
    <?php  foreach ($element_keys as $item) : ?>
      <?php if (!is_numeric($item)) continue; ?>
      <th class="year_header">
        <div style="display: none;">
          <?php print render($element[$item]['field_year']); ?>
        </div>
        <span class="year_value">
          <?php print $element[$item]['field_year'][LANGUAGE_NONE][0]['value']['#default_value']; ?>
        </span>
        <?php if ($item == $element['#max_delta'] && $item > $element['#min_index']) : ?>
          <?php print render($element[$item]['remove_button']); ?>
        <?php endif; ?>
      </th>
    <?php endforeach; ?>
  </tr>

  <?php foreach ($element['#budget_rows'] as $row) : ?>
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
      <?php foreach ($element_keys as $item) : ?>
        <?php if (!is_numeric($item)) continue; ?>
        <td>
          <?php if (!empty($row['budget_items'][$item]->field_total[LANGUAGE_NONE][0]['value'])) : ?>
            <?php print '$' . $row['budget_items'][$item]->field_total[LANGUAGE_NONE][0]['value']; ?>
          <?php endif; ?>
        </td>
      <?php endforeach; ?>
    </tr>
  <?php endforeach; ?>

  <tr class="sum">
    <td>
      <div class="label">
        <?php print $element['#row_title']; ?>
        <a class="tooltip" href="javascript:void(0);">
          <i class="tooltip-icon"></i>
          <span class="tooltip-content">
            <?php print $element['#row_description']; ?>
          </span>
        </a>
        <em>($m)</em>
        <?php if ($element['#row_type']) : ?>
          <em><?php print $element['#row_type']; ?></em>
        <?php endif; ?>
      </div>
    </td>
    <?php foreach ($element_keys as $item) : ?>
      <?php if (!is_numeric($item)) continue; ?>
      <td class="number-cell">
        <?php print render($element[$item]['field_total']); ?>
      </td>
    <?php endforeach; ?>
  </tr>
  </tbody>
</table>
<?php if (isset($element['add_more_before'])) : ?>
  <?php print render($element['add_more_before']); ?>&nbsp;
<?php endif; ?>
<?php print render($element['add_more']); ?>
