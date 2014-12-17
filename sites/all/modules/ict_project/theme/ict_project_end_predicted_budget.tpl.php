<table id="<?php print $element['#field_name'];?>">
  <tbody>
    <tr>
      <th></th>
      <th><?php print t('Previous'); ?></th>
      <th><?php print t('Current'); ?></th>
      <th><?php print t('1'); ?></th>
      <th><?php print t('2'); ?></th>
      <th><?php print t('3'); ?></th>
    </tr>
    <tr>
      <td><?php print t('FY (yy/yy)'); ?></td>
      <?php foreach (element_children($element) as $item) : ?>
        <td>
          <div style="display: none;">
            <?php print drupal_render($element[$item]['field_predicted_year']); ?>
          </div>
          <?php print $element[$item]['field_predicted_year']['und'][0]['value']['#value']; ?>
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
