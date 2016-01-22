<?php $element_keys = element_children($element); ?>

<table id="field_end_predicted_budget" class="table_field_collection">
  <tbody>
  <tr>
    <th><?php print t('FY (yy/yy)'); ?></th>
    <?php  foreach ($element_keys as $item) : ?>
      <?php if ($item === 'add_more') continue; ?>
      <th>
        <div style="display: none;">
          <?php print render($element[$item]['field_year']); ?>
        </div>
        <?php print $element[$item]['field_year'][LANGUAGE_NONE][0]['value']['#value']; ?>
      </th>
    <?php endforeach; ?>
  </tr>
  <tr class="sum">
    <td><div class="label"><?php print t('Baseline'); ?></div></td>
    <?php foreach ($element_keys as $item) : ?>
      <?php if ($item === 'add_more') continue; ?>
      <td>
        <?php print render($element[$item]['field_total']); ?>
      </td>
    <?php endforeach; ?>
  </tr>
  </tbody>
</table>
<?php print render($element['add_more']); ?>