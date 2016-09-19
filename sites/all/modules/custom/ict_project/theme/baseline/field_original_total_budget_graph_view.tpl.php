   <script src="//d3js.org/d3.v3.min.js"></script>
    <script src="//labratrevenge.com/d3-tip/javascripts/d3.tip.v0.6.3.js"></script>

<div class="project-individual-page-graph" style="max-width: 945px;">
  <svg id="project-individual-budget-chart"></svg>
  <!-- <canvas id="budgetChart" width="945" height="325"></canvas> -->
  <div class="legend" id="expenditure_legend">
    <ul class="bar-legend">
      <li>
        <span style="background-color:#ff6161">
          <img src="/<?php print drupal_get_path('theme', 'itdash') . '/html/images/legends/legend-ff6161.jpg';?>" />
        </span>
        <?php print t('Total Expenditure to Date ($m)'); ?>
      </li>
      <li>
        <span style="background-color:#5c46a4">
          <img src="/<?php print drupal_get_path('theme', 'itdash') . '/html/images/legends/legend-5c46a4.jpg';?>" />
        </span>
        <?php print t('Total Budget ($m)'); ?>
      </li>
<!--       <li>
        <span class="required">*</span>
        <?php print t('Current Financial Year'); ?>
      </li> -->
    </ul>
  </div>
</div>
