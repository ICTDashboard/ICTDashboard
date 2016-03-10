<div id="ict-dashboard-overview-number-indicators">
  <div class="wrap cf">
    <div class="t-2of3 d-2of3">
      <div class="label">
        <?php print t('Expenditure and Budget'); ?>
      </div>
    </div>
    <div class="t-1of3 d-1of3" id="ict-dashboard-numbers">
      <div class="row">
        <div class="label">
          <?php print t('Number of Active Projects'); ?>
          <a href="javascript:void(0);" class="tooltip">
            <i class="tooltip-icon"></i>
            <span class="tooltip-content">
              <?php print t('Some text'); ?>
            </span>
          </a>
        </div>
        <div class="big-number">
          <?php print $number_of_projects ?>
        </div>
      </div>

      <div class="row">
        <div class="label">
          <?php print t('Total Number of Benefits Listed'); ?>
          <a href="javascript:void(0);" class="tooltip">
            <i class="tooltip-icon"></i>
            <span class="tooltip-content">
              <?php print t('Some text'); ?>
            </span>
          </a>
        </div>
        <div class="big-number">
          <?php print $total_number_of_benefits; ?>
        </div>
      </div>

      <a href="" class="general-button arrow-right"><span><?php print t('View Detailed Overview'); ?></span></a>
    </div>

  </div>
</div>