<div id="ict-dashboard-overview-number-indicators">
  <div class="wrap cf">
    <div class="t-2of3 d-2of3">
      <div  id="overview-graphs">
        <div class="label">
          <?php print t('Expenditure and Budget'); ?>
          <a href="javascript:void(0);" class="tooltip budget-tooltip">
            <i class="tooltip-icon"></i>
              <span class="tooltip-content">
                <?php print t('Expenditure to date and budget across active projects, by current financial year or total across all years.'); ?>
              </span>
          </a>
        </div>

        <div id="current-fin-year-budget-graph" class="overview-expenditure-graphs">
          <div class="graph-container"></div>
          <div class="expenditure-budget-value">
            <?php print '<strong>$' . number_format($current_year_expenditure, 2)  . 'm</strong> / $' . number_format($current_year_budget, 2) . 'm'; ?>
          </div>
        </div>

        <div id="total-budget-graph" class="overview-expenditure-graphs" style="display: none;">
          <div class="graph-container"></div>
          <div class="expenditure-budget-value">
            <?php print '<strong>$' . number_format($total_expenditure, 2)  . 'm</strong> / $' . number_format($total_budget, 2) . 'm'; ?>
          </div>
        </div>
        
        <div id="overview-expenditure-switch">
          <div >
            <label><?php print t('Display'); ?></label>
            <select>
              <option value="current-fin-year-budget"><?php print t('Current Financial Year'); ?></option>
              <option value="total-budget"><?php print t('All years'); ?></option>
            </select>
          </div>
        </div>
        <div class="legend" id="expenditure_legend">
          <ul class="bar-legend">
            <li>
              <span style="background-color:#ff6161"></span>
              <?php print t('Total Expenditure To Date ($m)'); ?>
            </li>
            <li>
              <span style="background-color:#5c46a4"></span>
              <?php print t('Total Budget ($m)'); ?>
            </li>
          </ul>
        </div>
      </div>
    </div>
    <div class="t-1of3 d-1of3" id="ict-dashboard-numbers1">
      <div class="label">
        <?php print t('Number of Active Projects'); ?>
        <a href="javascript:void(0);" class="tooltip">
          <i class="tooltip-icon"></i>
        <span class="tooltip-content">
          <?php print t('The number of ICT-enabled projects with ICT costs of $10 million or more published on the Dashboard.'); ?>
        </span>
        </a>
      </div>
      <div class="big-number">
        <?php print l($number_of_projects, 'dashboard-projects', array('attributes' => array('title' => t('View all projects')))) ?>
      </div>
    </div>

    <div class="row graph-schedule-status">
      <div class="label">
        <?php print t('Projects Schedule Status'); ?>
        <a href="javascript:void(0);" class="tooltip">
          <i class="tooltip-icon"></i>
        <span class="tooltip-content">
          <?php print t('The current status of active projects.'); ?>
        </span>
        </a>
      </div>
      <div id="project-schedule-status-graph"></div>
      <div class="legend" id="statuses_legend">
        <ul class="bar-legend">
          <li>
            <span style="background-color:<?php print $project_statuses['behind_schedule']['color']; ?>"></span>
            <?php print t('Behind Schedule'); ?>
          </li>
          <li>
            <span style="background-color:<?php print $project_statuses['on_track']['color']; ?>"></span>
            <?php print t('On Track'); ?>
          </li>
          <li>
            <span style="background-color:<?php print $project_statuses['ahead_schedule']['color']; ?>"></span>
            <?php print t('Ahead of Schedule'); ?>
          </li>
          <li>
            <b>#</b> <?php print t('No. of Projects'); ?>
          </li>
        </ul>
      </div>
    </div>

    <div class="t-1of3 d-1of3" id="ict-dashboard-numbers">
      <div class="row">
        <div class="label">
          <?php print t('Total Number of Benefits Listed'); ?>
          <a href="javascript:void(0);" class="tooltip">
            <i class="tooltip-icon"></i>
            <span class="tooltip-content">
              <?php print t('The number of benefits over active projects.'); ?>
            </span>
          </a>
        </div>
        <div class="big-number">
          <?php print $total_number_of_benefits; ?>
        </div>
      </div>
      <a href="<?php print url('detailed-overview'); ?>" title="<?php print t('View Detailed Overview'); ?>" class="general-button arrow-right"><span><?php print t('View Detailed Overview'); ?></span></a>
    </div>
  </div>
</div>

<script>
  (function ($){
    $(document).ready(function () {

      $('#overview-expenditure-switch select').selectbox();

      $('#overview-expenditure-switch select').change(function() {
        var activeItem = $(this).val();

        $('.overview-expenditure-graphs').hide();
        $('#'+activeItem+'-graph').show();
      });

      var currentFinYearData = [
          Drupal.settings.budget_expenditure_settings.current_year_expenditure,
          Drupal.settings.budget_expenditure_settings.current_year_budget
        ],
        totalData = [
          Drupal.settings.budget_expenditure_settings.total_expenditure,
          Drupal.settings.budget_expenditure_settings.total_budget
        ],
        width = $("#overview-graphs").width();

      initBudgetGraphs(
        currentFinYearData,
        '#current-fin-year-budget-graph .graph-container'
      );
      initBudgetGraphs(
        totalData,
        '#total-budget-graph .graph-container'
      );

      function initBudgetGraphs(data, selector) {
        var chart = d3.select(selector)
          .append("svg:svg")
          .attr("class", "chart")
          .attr("width", width + 4)
          .attr("height", 60);

        var x = d3.scale.linear()
          .domain([0, d3.max(data)])
          .range([0, width]);

        chart.selectAll("rect")
          .data(data.slice().reverse())
          .enter().append("svg:rect")
          .attr("y", function (d, i) {
            return i ? 13 : 5
          })
          .attr("x", 1)
          .attr("width", function (d, i) {
            return x(d) - 1
          })
          .attr("height", function (d, i) {
            return i ? 35 : 50
          })
          .attr("style", function (d, i) {
            return i ? 'fill:#ff6161;' : 'fill:#5c46a4;';
          });

        var expenditure = x(data[0]),
          polygonPoints = [
            expenditure + ',56',
            (expenditure - 4) + ',60',
            (expenditure + 4) + ',60'
          ];

        chart
          .append("svg:polygon")
          .attr('points', polygonPoints.join(' '))
          .attr("style", 'fill:#ff6161');

        chart
          .append("svg:line")
          .attr('x1', width)
          .attr('y1', 0)
          .attr('x2', width)
          .attr('y2', 60)
          .attr("style", 'stroke:#cdd8ec;stroke-width:1');

        chart
          .append("svg:line")
          .attr('x1', 0)
          .attr('y1', 0)
          .attr('x2', 0)
          .attr('y2', 60)
          .attr("style", 'stroke:#cdd8ec;stroke-width:1');
      }

      function initScheduleStatusesGraph () {
        var data = Drupal.settings.budget_expenditure_settings.project_statuses;

        var chart = d3.select('#project-schedule-status-graph')
          .append("svg:svg")
          .attr("class", "chart")
          .attr("width", width)
          .attr("height", 66);

        var sum_of_values = d3.sum([
              data.behind_schedule.value,
              data.on_track.value,
              data.ahead_schedule.value
            ]);

        x = d3.scale.linear()
          .domain([0, sum_of_values])
          .range([0, width - 1]);

        // initial line on the left
        chart.append("svg:line")
          .attr('x1', 0)
          .attr('y1', 0)
          .attr('x2', 0)
          .attr('y2', 66)
          .attr("style", 'stroke:#cdd8ec;stroke-width:1');

        var y = 8,
            height = 50,
            current_x = 1;

        var statuses = ['behind_schedule', 'on_track', 'ahead_schedule'];
        for (i in statuses) {
          var current_item = statuses[i],
              current_value = data[current_item],
              current_width = x(current_value.value);

          // draw only status that have at least one project
          if (!current_width) continue;

          chart.append('svg:a')
            .attr('id', current_item)
            .attr('xlink:href', '/dashboard-projects?filter_by=status&filter='+current_value.filter_value)
            .attr('xlink:title', current_value.title_text)
            .append("svg:rect")
            .attr("y", y)
            .attr("x", current_x)
            .attr("width", current_width)
            .attr("height", 50)
            .attr("style", 'fill:'+current_value.color);

          chart.select('a#'+statuses[i])
            .append('svg:text')
            .attr("x", current_x)
            .attr("y", y)
            .attr('font-size', '16px')
            .attr('font-weight', '600')
            .attr('font-family', 'Open Sans')
            .attr('style', 'text-decoration: inherit;')
            .attr('dy', height/2 + 5)
            .attr('dx', current_width/2)
            .attr('text-anchor', 'middle')
            .text(current_value.value);

          current_x += current_width;

          chart.append("svg:line")
            .attr('x1', current_x)
            .attr('y1', 58)
            .attr('x2', current_x)
            .attr('y2', 66)
            .attr("style", 'stroke:#cdd8ec;stroke-width:1');
        }
      }
      initScheduleStatusesGraph();
    });

  })(jQuery);
</script>
