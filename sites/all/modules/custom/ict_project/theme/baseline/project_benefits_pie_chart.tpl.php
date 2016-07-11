<div style="overflow: hidden;">
  <div id="benefits_chart_div" style="float:left; width: 100%; max-width: 325px;"></div>
  <div class="legend" id="benefits_legend">
    <ul class="bar-legend">
    </ul>
  </div>
</div>
<script>
  (function ($) {
    $(document).ready(function () {
      google.charts.setOnLoadCallback(drawChart);

      function drawChart() {
        var data_items = Drupal.settings.benefits_pie_chart.chart_items,
            slices_settings = Drupal.settings.benefits_pie_chart.slices_settings,
            legend_items = Drupal.settings.benefits_pie_chart.legend_items;

        data_items.unshift(['Status', 'Percentage']);

        var data = google.visualization.arrayToDataTable(data_items, false);

        var options = {
          titlePosition: 'none',
          height: 325,
          width: '100%',
          pieSliceText: 'none',
          tooltip: { trigger: 'none' },
          enableInteractivity: false,
          chartArea: {
            left:7,
            top:7,
            right: 7,
            bottom: 7,
            width:'100%',
            height:'100%'
          },
          animation: {
            startup: true,
            duration: 1000,
            easing: 'out'
          },
          legend: {
            position: 'none'
          },
          slices: slices_settings
        };

        // legend
        for (benefit_item in legend_items) {
          $('#benefits_legend .bar-legend')
            .append('<li><span style="background-color:' + legend_items[benefit_item]['color'] + '">' + '<img src="/sites/all/themes/itdash/html/images/legends/legend-' + legend_items[benefit_item]['color'].replace('#', '') + '.jpg" />' + '</span>' + legend_items[benefit_item]['number'] + ' Project Benefits, ' + legend_items[benefit_item]['label'] + '</li>')
        }

        var chart = new google.visualization.PieChart(document.getElementById('benefits_chart_div'));

        google.visualization.events.addListener(chart, 'ready', function () {
          document.getElementById('benefits_chart_div').innerHTML = '<img src="' + chart.getImageURI() + '">';
        });

        chart.draw(data, options);

        var graph_height = $('#benefits_chart_div').outerHeight();
        $('#benefits_legend .bar-legend').css('margin-top', (graph_height - $('#benefits_legend').height())/2 + 'px');
      }
    });
  })(jQuery);
</script>
