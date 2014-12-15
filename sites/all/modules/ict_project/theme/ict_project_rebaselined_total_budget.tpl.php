<table>
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
          <?php print $element[$item]['field_year']['#default_value']; ?>
        </td>
      <?php endforeach; ?>
    </tr>
    <tr>
      <td><?php print t('Opex'); ?></td>
      <?php foreach (element_children($element) as $item) : ?>
        <td>
          <?php print drupal_render($element[$item]['field_opex']); ?>
        </td>
      <?php endforeach; ?>
    </tr>
    <tr>
      <td><?php print t('Capex'); ?></td>
      <?php foreach (element_children($element) as $item) : ?>
        <td>
          <?php print drupal_render($element[$item]['field_capex']); ?>
        </td>
      <?php endforeach; ?>
    </tr>
    <tr>
      <td><?php print t('Total'); ?></td>
      <?php foreach (element_children($element) as $item) : ?>
        <td>
          <?php print drupal_render($element[$item]['field_total']); ?>
        </td>
      <?php endforeach; ?>
    </tr>
  </tbody>
</table>
