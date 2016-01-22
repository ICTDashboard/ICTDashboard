<table id="field_end_predicted_budget" class="table_field_collection">
  <tbody>
  <tr>
    <th><?php print t('FY (yy/yy)'); ?></th>
    <?php  foreach ($baseline as $item) : ?>
      <th>
        <?php print $item['year']; ?>
      </th>
    <?php endforeach; ?>
  </tr>
  <tr class="sum">
    <td><div class="label"><?php print t('Baseline'); ?></div></td>
    <?php  foreach ($baseline as $item) : ?>
      <td>
        <?php print $item['total']; ?>
      </td>
    <?php endforeach; ?>
  </tr>
  </tbody>
</table>
<?php print render($element['add_more']); ?>