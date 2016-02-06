<div style="margin-left: 25px; width: 945px;">
  <canvas id="budgetChart" width="945" height="325"></canvas>
  <div class="legend" id="expenditure_legend"></div>
</div>
<script>
  (function ($) {
    $(document).ready(function () {

      var ctx = document.getElementById("budgetChart").getContext("2d");
      var ExpenditureChart = new Chart(ctx).Bar(
        Drupal.settings.budget_chart.data,
        Drupal.settings.budget_chart.options
      );

      document
        .getElementById("expenditure_legend")
        .innerHTML = ExpenditureChart.generateLegend();

    });
  })(jQuery);
</script>