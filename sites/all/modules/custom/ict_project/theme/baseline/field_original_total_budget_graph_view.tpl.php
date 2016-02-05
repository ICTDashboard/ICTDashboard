<canvas id="budgetChart" width="640" height="300"></canvas>
<script>
  var ctx = document.getElementById("budgetChart").getContext("2d");
  console.log(Drupal.settings.budget_chart.data);
  var myNewChart = new Chart(ctx).Bar(
    Drupal.settings.budget_chart.data,
    Drupal.settings.budget_chart.options
  );
</script>