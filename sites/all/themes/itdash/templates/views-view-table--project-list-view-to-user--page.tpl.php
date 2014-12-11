<?php

/**
 * @file
 * Template to display a view as a table.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $header: An array of header labels keyed by field id.
 * - $caption: The caption for this table. May be empty.
 * - $header_classes: An array of header classes keyed by field id.
 * - $fields: An array of CSS IDs to use for each field id.
 * - $classes: A class or classes to apply to the table, based on settings.
 * - $row_classes: An array of classes to apply to each row, indexed by row
 *   number. This matches the index in $rows.
 * - $rows: An array of row items. Each row is an array of content.
 *   $rows are keyed by row number, fields within rows are keyed by field ID.
 * - $field_classes: An array of classes to apply to each field, indexed by
 *   field id, then row number. This matches the index in $rows.
 * @ingroup views_templates
 */
?>

<?php
  $classes = array(
    0 => 'title',
    1 => 'dates',
    2 => 'update',
  );
?>

<div class="project-lists d-all t-all">
  <table border="0" cellspacing="0" cellpadding="0">

    <?php if (!empty($header)) : ?>
      <tr>
        <?php $i = 0; ?>
        <?php foreach ($header as $field => $label): ?>
          <?php if ($i == 2 && !user_is_logged_in()) continue; ?>
          <th <?php if ($header_classes[$field]) { print 'class="'. $header_classes[$field] . '" '; } ?>>
            <?php print $label; ?>
          </th>
        <?php ++$i; endforeach; ?>
      </tr>
    <?php endif; ?>

    <?php foreach ($rows as $row_count => $row): ?>
      <tr <?php if ($row_classes[$row_count]) { print 'class="' . implode(' ', $row_classes[$row_count]) .'"';  } ?>>
        <?php $i = 0; ?>
        <?php foreach ($row as $field => $content): ?>
          <?php if ($i == 2 && !user_is_logged_in()) continue; ?>
          <td <?php print isset($classes[$i]) ? "class=\"$classes[$i]\"" : ''; ?>>
            <?php print $content; ?>
          </td>
        <?php ++$i; endforeach; ?>
      </tr>
    <?php endforeach; ?>
  </table>
</div>
