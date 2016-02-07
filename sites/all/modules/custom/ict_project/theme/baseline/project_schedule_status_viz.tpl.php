<div id="schedule_chart_div"></div>
<div class="legend" id="schedule_legend">
  <ul class="bar-legend">
    <li><span style="background-color:#1fd063"></span>Actual Level of Completion (%)</li>
    <li><span style="background-color:#007299"></span>Forecast Level of Project Completion (%)</li>
  </ul>
</div>
<script>
  (function ($) {
    $(document).ready(function () {

      google.charts.load('current', {packages: ['corechart', 'bar']});
      google.charts.setOnLoadCallback(drawBasic);

      function drawBasic() {

        var data = google.visualization.arrayToDataTable([
          [
            'Progress Index',
            'Percentage',
            {role: 'style'},
            {role: 'annotation'}
          ],
          [
            5,
            <?php print $actual_level ?>,
            '#1fd063',
            <?php print $actual_level ?>+'%'
          ],
          [
            2,
            <?php print $forecast_level ?>,
            '#007299',
            <?php print $forecast_level ?>+'%'
          ]
        ]);

        var options = {
          width: '100%',
          height: 175,
          bar: {groupWidth: '75%'},
          chartArea: {
            width: '95%',
            top: 5,
            bottom: 20,
            left: 3
          },
          legend: {position: "none"},
          enableInteractivity: false,
          tooltip: {
            trigger: 'none'
          },
          animation: {
            startup: true,
            duration: 1000,
            easing: 'out'
          },
          annotations: {
            highContrast: false,
            alwaysOutside: true,
            stem: {
              color: 'none'
            },
            textStyle: {
              fontName: 'Open Sans',
              fontSize: 16,
              bold: true,
              italic: false,
              color: '#202b3d',
              opacity: 1
            }
          },
          hAxis: {
            baselineColor: '#1e2635',
            minValue: 0,
            ticks: [0, 50, 100],
            minorGridlines: {
              count: 4,
              color: '#f0f4fa',
            },
            gridlines: {
              color: '#f0f4fa'
            },
            textStyle: {
              fontName: 'Open Sans',
              fontSize: 13,
              bold: true,
              italic: false,
              color: '#202b3d',
            }
          },
          vAxis: {
            baselineColor: '#1e2635',
            textPosition: 'none',
            ticks: [0, 2, 5, 7],
            gridlines: {
              color: 'none'
            }
          }
        };

        var chart = new google.visualization.BarChart(document.getElementById('schedule_chart_div'));

        chart.draw(data, options);
      }
    });
  })(jQuery);
</script>