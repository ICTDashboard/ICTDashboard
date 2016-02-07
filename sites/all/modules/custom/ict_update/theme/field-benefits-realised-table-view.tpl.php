<?php
$colors = __ict_project_get_benefit_status_colors();
$number = 0;
?>
<div class="ict-benefits">
<?php foreach($benefits as $benefit) : ?>
  <?php $benefit_wrap = entity_metadata_wrapper('field_collection_item', $benefit); ?>
  <div class="node-faq-item <?php print !fmod($number, 2) ? 'row-blue' : 'row-white'; ?>">
    <div class="ict-faq-question">
      <h4><?php print $benefit_wrap->field_benefit->value(); ?></h4>
      <div class="benfit-status">
        <span class="status-marker" style="background-color: <?php print $colors[$benefit_wrap->field_status->raw()]; ?>"></span>
        <?php print $benefit_wrap->field_status->label(); ?>
      </div>
    </div>
    <div class="ict-faq-answer" style="display: none;">
      <ul>
        <li>
          <div class="label"><?php print t('Commentary:'); ?></div>
          <div class="benefit"><?php print $benefit_wrap->field_commentary->value(); ?></div>
        </li>
        <li>
          <div class="label"><?php print t('Start date:'); ?></div>
          <div class="benefit"><?php print format_date($benefit_wrap->field_benefit_start_date->value(), 'medium', 'd M Y'); ?></div>
        </li>
        <li>
          <div class="label"><?php print t('End date:'); ?></div>
          <div class="benefit"><?php print format_date($benefit_wrap->field_end_date->value(), 'medium', 'd M Y'); ?></div>
        </li>
        <li>
          <div class="label"><?php print t('Financial:'); ?></div>
          <div class="benefit"><?php print $benefit_wrap->field_financial->value() ? '<span class="ict-tick"></span>' : '-'; ?></div>
        </li>
      </ul>
    </div>
  </div>
  <?php $number++; ?>
<?php endforeach; ?>
</div>
