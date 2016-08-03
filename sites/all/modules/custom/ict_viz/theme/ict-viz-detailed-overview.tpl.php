<script src="http://labratrevenge.com/d3-tip/javascripts/d3.tip.v0.6.3.js"></script>
<div id="ict-dashboard-detailed-overview">
  <div class="wrap cf">
    <div class="section-title">
      <h2>
        <?php print t('Projects Expenditure and Budget'); ?>
        <a href="javascript:void(0);" class="tooltip">
          <i class="tooltip-icon"></i>
              <span class="tooltip-content">
                <?php print t('Expenditure to date and budget across all active projects by financial year.'); ?>
              </span>
        </a>
      </h2>
    </div>
    <div id="detailed-view-expenditure" style="max-width: 945px;">
        <!-- <canvas id="detailed_budget_chart" width="945" height="360"></canvas> -->
        <svg id="detailed-overview-chart"></svg>
        <svg id="detailed-overview-chart1"></svg>
        <div id="expenditure_legend" class="legend">
          <ul class="bar-legend">
            <li>
              <span style="background-color:#ff6161">
                <img src="/<?php print drupal_get_path('theme', 'itdash') . '/html/images/legends/legend-ff6161.jpg';?>" />
              </span>
              <?php print t('Expenditure to Date ($m)'); ?>
            </li>
            <li>
              <span style="background-color:#5c46a4">
                <img src="/<?php print drupal_get_path('theme', 'itdash') . '/html/images/legends/legend-5c46a4.jpg';?>" />
              </span>
              <?php print t('Total Budget ($m)'); ?>
            </li>
<!--             <li>
              <span class="required">*</span>
              <?php print t('Current Financial Year'); ?>
            </li> -->
          </ul>
        </div>
    </div>
    <div id="ict-all-benefits-setion" class="section-title">
      <h2>
        <?php print t('Projects Schedule Status'); ?>
        <a href="javascript:void(0);" class="tooltip">
          <i class="tooltip-icon"></i>
          <span class="tooltip-content">
            <?php print t('A summary of schedule status for all active projects compared to their planned schedule.'); ?>
          </span>
        </a>
      </h2>
    </div>
    <div id="detailed-view-schedule-status">
      <div id="detailed_schedule_chart_current"></div>
      <div style="display: none;" id="detailed_schedule_chart_previous"></div>
      <div class="legend" id="statuses_legend">
        <ul class="bar-legend">
          <li>
            <span style="background-color:<?php print '#f6d000'; ?>">
              <img src="/<?php print drupal_get_path('theme', 'itdash') . '/html/images/legends/legend-f6d000.jpg';?>" />
            </span>
            <?php print t('Behind Schedule'); ?>
          </li>
          <li>
            <span style="background-color:<?php print '#1fd063'; ?>">
              <img src="/<?php print drupal_get_path('theme', 'itdash') . '/html/images/legends/legend-1fd063.jpg';?>" />
            </span>
            <?php print t('On Track'); ?>
          </li>
          <li>
            <span style="background-color:<?php print '#75a2df'; ?>">
              <img src="/<?php print drupal_get_path('theme', 'itdash') . '/html/images/legends/legend-75a2df.jpg';?>" />
            </span>
            <?php print t('Ahead of Schedule'); ?>
          </li>
          <li>
            <span class="noofproj"><b>#</b></span> <?php print t('No. of Projects'); ?>
          </li>
          <li>
            <span class="curqua"><b>*</b></span> <?php print t('Current Quarter'); ?>
          </li>
        </ul>
      </div>
      <a href="javascript:void(0);" title="<?php print t('View All Previous Quarters'); ?>" id="schedule-expand" class="general-button plus expand-collapse-button">
        <span><?php print t('View All Previous Quarters');?></span>
      </a>
      <a href="javascript:void(0);" title="<?php print t('View Current Quarters'); ?>" id="schedule-collapse" style="display: none;" class="general-button minus expand-collapse-button">
        <span><?php print t('View Current Quarters'); ?></span>
      </a>
    </div>
    <div class="section-title">
      <h2>
        <?php print t('Project Benefits'); ?>
        <a href="javascript:void(0);" class="tooltip">
          <i class="tooltip-icon"></i>
              <span class="tooltip-content">
                <?php print t('Benefits over all active projects.'); ?>
              </span>
        </a>
      </h2>

    </div>
    <?php print theme('all_benefits_pie_chart'); ?>
  </div>
</div>
