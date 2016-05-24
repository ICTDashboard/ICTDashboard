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
        <div id="expenditure_legend" class="legend">
          <ul class="bar-legend">
            <li>
              <span style="background-color:#ff6161"></span>
              <?php print t('Expenditure to Date ($m)'); ?>
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
            <span style="background-color:<?php print '#f6d000'; ?>"></span>
            <?php print t('Behind Schedule'); ?>
          </li>
          <li>
            <span style="background-color:<?php print '#1fd063'; ?>"></span>
            <?php print t('On Track'); ?>
          </li>
          <li>
            <span style="background-color:<?php print '#75a2df'; ?>"></span>
            <?php print t('Ahead of Schedule'); ?>
          </li>
          <li>
            <b>#</b> <?php print t('No. of Projects'); ?>
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
<script>
  (function ($){
    $(document).ready(function () {
      // *** Expenditure Graph ***
      var ctx = document.getElementById("detailed_budget_chart").getContext("2d");
      var ExpenditureChart = new Chart(ctx).Bar(
        Drupal.settings.detailed_budget_chart.data,
        Drupal.settings.detailed_budget_chart.options
      );

      // *** Schedule Status Graph ***
      var data = Drupal.settings.detailed_schedule_chart,
        width = $('#detailed-view-schedule-status').innerWidth();

      var max_bar = width < 684 ? width : 684,
          left_padding = 94;

      // align legend with graph
      $('#statuses_legend .bar-legend').css('padding-left', left_padding+'px');
      $('#detailed-view-schedule-status .expand-collapse-button').css('margin-left', left_padding+'px');

      // expand/collapse buttons
      if (typeof data.data['previous'] == 'undefined') {
        $('#detailed-view-schedule-status .expand-collapse-button').hide();
      }
      else {
        $('#detailed-view-schedule-status .expand-collapse-button').click(function() {
          $('#detailed-view-schedule-status .expand-collapse-button')
            .show()
            .addClass('visible');

          $(this)
            .hide()
            .removeClass('visible');

          if (!$('#schedule-collapse').hasClass('visible')) {
            $('#detailed_schedule_chart_previous').hide();
          }
          else {
            $('#detailed_schedule_chart_previous').show();
          }
        });
      }

      x = d3.scale.linear()
        .domain([0, data.max_number])
        .range([0, max_bar - 1]);

      // get ordinal for quarter
      getGetOrdinal = function (n) {
        var s=["th","st","nd","rd"],
            v=n%100;
        return n+(s[(v-20)%10]||s[v]||s[0]);
      };

      var years = ['current', 'previous'];
      for (i in years) {
        var year = years[i];

        // if no data provide for year don't show it
        if (typeof data.data[year] == 'undefined') continue;

        var y = 0,
            bar_padding = 16;

        var chart = d3.select('#detailed_schedule_chart_'+year)
          .append("svg:svg")
          .attr("class", "chart")
          .attr("width", width)
          .attr("height", Object.keys(data.data[year]).length * 72.5);

        for (var quarter = 4; quarter > 0; quarter--) {
          // if no data provide for the quarter don't show it
          if (typeof data.data[year][quarter] == 'undefined') continue;

          var height = 40,
              current_x = left_padding + 1;

          // update Y start
          y += bar_padding;

          // add row group
          var quarter_g = chart.append("g");

          // add text on the left
          var quarter_text = quarter_g
            .append("svg:text")
            .attr("x", 13)
            .attr("y", y + height/3 + 2)
            .attr("font-size", '13px')
            .attr("font-family", 'Open Sans')
            .attr("color", '#202b3d');
          // quarter number
          quarter_text
            .append("svg:tspan")
            .text(getGetOrdinal(quarter)+" Quarter");
          // year
          quarter_text
            .append("svg:tspan")
            .attr("font-weight", 'bold')
            .attr("x", 13)
            .attr("dy", 22)
            .attr("dx", 23)
            .attr("text-anchor", 'right')
            .text(data[year]);

          // initial line on the left
          quarter_g
            .append("svg:line")
            .attr('x1', left_padding)
            .attr('y1', y - bar_padding)
            .attr('x2', left_padding)
            .attr('y2', y  + height + bar_padding)
            .attr("style", 'stroke:#1e2635;stroke-width:1');

          var statuses = ['behind_schedule', 'on_track', 'ahead_schedule'];
          for (i in statuses) {
            var current_item = statuses[i],
              current_value = data.data[year][quarter][current_item];

            // draw only status that have at least one project
            if (typeof data.data[year][quarter][current_item] == 'undefined') continue;

            var current_width = x(current_value.value);

            quarter_g
              .append("svg:rect")
              .attr("y", y)
              .attr("x", current_x)
              .attr("width", current_width)
              .attr("height", height)
              .attr("style", 'fill:'+current_value.color);

            quarter_g
              .append('svg:text')
              .attr("x", current_x)
              .attr("y", y)
              .attr('font-size', '13px')
              .attr('font-weight', '600')
              .attr('font-family', 'Open Sans')
              .attr('dy', (height+bar_padding)/2 - 3)
              .attr('dx', current_width/2)
              .attr('text-anchor', 'middle')
              .text(current_value.value);

            current_x += current_width;
          }

          // draw delimiter if nex item exists
          if (typeof data.data[year][quarter-1] == 'undefined') continue;

          // update Y start
          y += height + bar_padding;

          // add row delimiter
          quarter_g.append("svg:line")
            .attr('x1', left_padding)
            .attr('y1', y)
            .attr('x2', width)
            .attr('y2', y)
            .attr("style", 'stroke:#f0f4fa;stroke-width:1');
        }
      }
    });
  })(jQuery);
</script>
