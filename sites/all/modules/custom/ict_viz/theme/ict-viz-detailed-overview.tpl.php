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
    <div id="detailed-view-expenditure" style="margin-left: 25px; max-width: 945px;">
        <canvas id="detailed_budget_chart" width="945" height="360"></canvas>
        <div id="expenditure_legend" class="legend"></div>
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

<script>
  (function ($){
    $(document).ready(function () {
      var ctx = document.getElementById("detailed_budget_chart").getContext("2d");
      var ExpenditureChart = new Chart(ctx).Bar(
        Drupal.settings.detailed_budget_chart.data,
        Drupal.settings.detailed_budget_chart.options
      );

      document
        .getElementById("expenditure_legend")
        .innerHTML = ExpenditureChart.generateLegend();

    });
  })(jQuery);
</script>
