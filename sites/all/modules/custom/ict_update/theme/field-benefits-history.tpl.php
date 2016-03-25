<?php $number = 1; ?>
<?php $projects_num = $updates_num = 0; ?>
<div id="ict-policy">
  <h2 class="fancybox-title">Benefit history</h2>
  <div class="ict-fancy-content">
    <div class="project-draft-submission">
      <div class="row">
        <div class="text">
    <table id="financial-benefits">
  <tr>
    <th></th>
    <th><div class="label"><?php print t('Benefits'); ?><a href="javascript:void(0);" class="tooltip tooltip-bottom "><i class="tooltip-icon"></i><span class="tooltip-content">List the benefits (quantitative or qualitative) this project will deliver or contribute to, as identified in the business case.
    </span></a></div></th>
    <th>
      <div class="label">
        <?php print t('Realised Status'); ?>
        <a href="javascript:void(0);" class="tooltip tooltip-bottom"><i class="tooltip-icon"></i><span class="tooltip-content">For each benefit listed, indicate the status of benefit realisation. Realised - The benefit has been realised; Partially - The benefit has been partially realised; On Track – The project is on track to realise the benefit as originally expected; At Risk - The benefit is not likely to be realised as originally expected; Not Realised - The benefit will not be realised.
    </span></a>
      </div>
    </th>
    <th>
      <div class="label">
        <?php print t('Commentary'); ?>
      </div>
    </th>
    <th colspan="2">
      <div class="label">
        <?php print t('Date Range: Start - End'); ?>
        <a href="javascript:void(0);" class="tooltip tooltip-bottom"><i class="tooltip-icon"></i><span class="tooltip-content">For each benefit listed, the date range when benefit is expected to be realised.
    </span></a>
      </div>
    </th>
  </tr>
  <?php foreach($benefits as $val) : ?>
    <?php if ($val['bundle'] == 'baseline')
            $projects_num++;
          else
            $updates_num++;
    ?>
      <tr>
        <td>
          <?php if ($val['bundle'] == 'update') print t('Update ') . $updates_num; ?>
          <?php if ($val['bundle'] == 'baseline' && $projects_num == 1) print t('Baseline'); ?>
          <?php if ($val['bundle'] == 'baseline' && $projects_num > 1) print t('Rebaseline'); ?>
        </td>
        <?php if (empty($val['benefit'])) : ?>
          <td></td><td></td><td></td><td></td><td></td>
        <?php else : ?>
          <?php $collection_wrapper = entity_metadata_wrapper('field_collection_item', $val['benefit']); ?>
          <td><?php print $collection_wrapper->field_benefit->value(); ?></td>
          <td><?php print $collection_wrapper->field_status->label(); ?></td>
          <td><?php print $collection_wrapper->field_commentary->value(); ?></td>
          <td><?php print format_date($collection_wrapper->field_benefit_start_date->value(), 'medium', 'd F Y'); ?></td>
          <td><?php print format_date($collection_wrapper->field_end_date->value(), 'medium', 'd F Y'); ?></td>
        <?php endif; ?>
      </tr>
  <?php endforeach; ?>
</table>
        </div>
      </div>
    </div>
  </div>
  <div class="fancybox-actions">
    <a class="ict-fancybox-close general-button" href="#"><span>Close</span></a>
  </div></div>
