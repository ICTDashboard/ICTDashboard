<?php $number = 1; ?>
<?php $projects_num = $updates_num = 0; ?>
<table id="financial-benefits" class="table_field_collection">

  <?php foreach(element_children($element) as $key) : ?>
    <?php if (!is_numeric($key)) continue; ?>
    <?php if (!empty($element[$key]['#archived_benefit'])) : ?>
      <tr class="row-grey" >
        <td colspan="2">
          <?php print t('Archived'); ?>
          <?php print format_date($element[$key]['#archived_benefit'], 'medium', 'd M Y'); ?>:
          <?php print $element[$key]['field_benefit']['und'][0]['value']['#default_value']; ?>
        </td>
        <td class="table-remove-button"><?php print drupal_render($element[$key]['history_button']); ?></td>
      </tr>
    <?php else : ?>
      <tr class="<?php print !fmod($number, 2) ? 'row-blue' : 'row-white'; ?>" >
        <th width="30%"><div class="label"><?php print t('Benefits'); ?><a href="javascript:void(0);" class="tooltip"><i class="tooltip-icon"></i><span class="tooltip-content">List the benefits (quantitative or qualitative) this project will deliver or contribute to, as identified in the business case.
    </span></a></div></th>
        <td colspan="2"><?php print drupal_render($element[$key]['field_benefit']); ?></td>
      </tr>
      <tr class="<?php print !fmod($number, 2) ? 'row-blue' : 'row-white'; ?>" >
        <th>
        <div class="label">
          <?php print t('Realised Status'); ?>
          <a href="javascript:void(0);" class="tooltip"><i class="tooltip-icon"></i><span class="tooltip-content">For each benefit listed, indicate the status of benefit realisation. Realised - The benefit has been realised; Partially - The benefit has been partially realised; On Track – The project is on track to realise the benefit as originally expected; At Risk - The benefit is not likely to be realised as originally expected; Not Realised - The benefit will not be realised.
    </span></a>
        </div>
      </th>
        <td colspan="2" class="select-no-border"><?php print drupal_render($element[$key]['field_status']); ?></td>
      </tr>
      <tr class="<?php print !fmod($number, 2) ? 'row-blue' : 'row-white'; ?>" >
        <th>
        <div class="label">
          <?php print t('Commentary'); ?>
        </div>
      </th>
        <td colspan="2" ><?php print drupal_render($element[$key]['field_commentary']); ?></td>
      </tr>
      <?php $element[$key]['field_benefit_start_date']['und'][0]['value']['date']['#title'] =
            $element[$key]['field_benefit_start_date']['und'][0]['value']['date']['#description'] =
            $element[$key]['field_end_date']['und'][0]['value']['date']['#title'] =
            $element[$key]['field_end_date']['und'][0]['value']['date']['#description'] = ''; ?>
      <tr class="<?php print !fmod($number, 2) ? 'row-blue' : 'row-white'; ?>" >
        <th>
        <div class="label">
          <?php print t('Date Range: Start - End'); ?>
          <a href="javascript:void(0);" class="tooltip"><i class="tooltip-icon"></i><span class="tooltip-content">For each benefit listed, the date range when benefit is expected to be realised.
    </span></a>
        </div>
      </th>
        <td><?php print drupal_render($element[$key]['field_benefit_start_date']); ?></td>
        <td><?php print drupal_render($element[$key]['field_end_date']); ?></td>
      </tr>
<!--      <tr class="--><?php //print !fmod($number, 2) ? 'row-blue' : 'row-white'; ?><!--" >-->
<!--        <th>-->
<!--        <div class="label">-->
<!--          --><?php //print t('Financial'); ?>
<!--          <a href="javascript:void(0);" class="tooltip"><i class="tooltip-icon"></i><span class="tooltip-content">For each benefit listed, mark those where the benefit can be measured financially.-->
<!--    </span></a>-->
<!--        </div>-->
<!--      </th>-->
<!--        <td colspan="2">--><?php //print drupal_render($element[$key]['field_financial']); ?><!--</td>-->
<!--      </tr>-->

      <tr class="last-benefit-row <?php print !fmod($number, 2) ? 'row-blue' : 'row-white'; ?>" >
        <th>
        <div class="label">
          <?php print t('Action'); ?>
        </div>
      </th>
        <td colspan="2" class="table-remove-button">
          <?php print drupal_render($element[$key]['remove_button']); ?>
          <?php print drupal_render($element[$key]['history_button']); ?>
        </td>
      </tr>
    <?php endif; ?>
    <?php $number ++ ?>
  <?php endforeach; ?>
</table>
<?php print drupal_render($element['add_more']); ?>
<div class="element-invisible">
  <?php print drupal_render_children($element); ?>
</div>
