<table id="<?php print $element['#field_name'];?>">
  <tbody>
    <tr>
      <th></th>
      <th><?php print t('Year 1'); ?></th>
      <th><?php print t('Year 2'); ?></th>
      <th><?php print t('Year 3'); ?></th>
      <th><?php print t('Year 4'); ?></th>
      <th><?php print t('Year 5'); ?></th>
    </tr>
    <tr>
      <td><?php print t('FY (yy/yy)'); ?></td>
      <?php foreach (element_children($element) as $item) : ?>
        <td>
          <?php print $element[$item]['field_predicted_year']['#default_value']; ?>
        </td>
      <?php endforeach; ?>
    </tr>
    <tr class="sum">
      <td><?php print t('Opex'); ?></td>
      <?php foreach (element_children($element) as $key => $item) : ?>
        <td data-sum="<?php print $key;?>" class="opex">
          <?php print drupal_render($element[$item]['field_predicted_opex']); ?>
        </td>
      <?php endforeach; ?>
    </tr>
    <tr class="sum">
      <td><?php print t('Capex'); ?></td>
      <?php foreach (element_children($element) as $key => $item) : ?>
        <td data-sum="<?php print $key;?>" class="capex">
          <?php print drupal_render($element[$item]['field_predicted_capex']); ?>
        </td>
      <?php endforeach; ?>
    </tr>
    <tr>
      <td><?php print t('Total'); ?></td>
      <?php foreach (element_children($element) as $key => $item) : ?>
        <td data-sum="<?php print $key;?>" class="total">
          <?php print drupal_render($element[$item]['field_predicted_total']); ?>
        </td>
      <?php endforeach; ?>
    </tr>
  </tbody>
</table>
