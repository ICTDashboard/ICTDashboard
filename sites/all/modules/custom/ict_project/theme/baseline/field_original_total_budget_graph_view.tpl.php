<div style="margin-left: 25px; max-width: 945px;">
  <canvas id="budgetChart" width="945" height="325"></canvas>
  <div class="legend" id="expenditure_legend">
    <ul class="bar-legend">
      <li>
        <span style="background-color:#ff6161"></span>
        <?php print t('Total Expenditure to Date ($m)'); ?>
      </li>
      <li>
        <span style="background-color:#5c46a4"></span>
        <?php print t('Total Budget ($m)'); ?>
      </li>
      <li>
        <span class="required">*</span>
        <?php print t('Current Financial Year'); ?>
      </li>
    </ul>
  </div>
</div>
<script>
  (function ($) {
    $(document).ready(function () {

      var ctx = document.getElementById("budgetChart").getContext("2d");
      var ExpenditureChart = new Chart(ctx).Bar(
        Drupal.settings.budget_chart.data,
        Drupal.settings.budget_chart.options
      );

    });
  })(jQuery);
</script>