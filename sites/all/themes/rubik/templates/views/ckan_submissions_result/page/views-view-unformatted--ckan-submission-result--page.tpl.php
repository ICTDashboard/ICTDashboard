<?php
/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<table>
  <tr>
    <th><?php print t('ID'); ?></th>
    <th style="width: 10%;"><?php print t('Date'); ?></th>
    <th><?php print t('URL'); ?></th>
<!--    <th>--><?php //print t('Header'); ?><!--</th>-->
    <th><?php print t('Data'); ?></th>
    <th><?php print t('Status'); ?></th>
    <th><?php print t('Result'); ?></th>
    <th><?php print t('Action'); ?></th>
  </tr>
  <?php foreach ($rows as $id => $row): ?>
    <tr>
      <?php print $row; ?>
    </tr>
  <?php endforeach; ?>
</table>
