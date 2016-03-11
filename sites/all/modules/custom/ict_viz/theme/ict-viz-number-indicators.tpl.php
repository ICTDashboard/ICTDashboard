<div id="ict-dashboard-overview-number-indicators">
  <div class="wrap cf">
    <div class="t-2of3 d-2of3">
      <div  id="overview-graphs">
        <div class="label">
          <?php print t('Expenditure and Budget'); ?>
        </div>
        <div id="overview-expenditure-switch">
          <div >
            <label><?php print t('Display'); ?></label>
            <select>
              <option value="current-fin-year-budget"><?php print t('Current Financial Year Total Expenditure and Budget'); ?></option>
              <option value="total-budget"><?php print t('Total Expenditure and Budget'); ?></option>
            </select>

            <a href="javascript:void(0);" class="tooltip budget-tooltip" id="current-fin-year-budget-tooltip">
              <i class="tooltip-icon"></i>
              <span class="tooltip-content">
                <?php print t('Current Financial Year Total Expenditure and Budget help text...'); ?>
              </span>
            </a>

            <a href="javascript:void(0);" class="tooltip budget-tooltip" id="total-budget-tooltip" style="display: none;">
              <i class="tooltip-icon"></i>
              <span class="tooltip-content">
                <?php print t('Total Expenditure and Budget help text...'); ?>
              </span>
            </a>
          </div>
        </div>

        <div id="current-fin-year-budget-graph" class="overview-expenditure-graphs">
          <div class="graph-container"></div>
          <div class="expenditure-budget-value">
            <?php print '<strong>$' . number_format($current_year_expenditure, 1)  . 'm</strong> / $' . number_format($current_year_budget, 1) . 'm'; ?>
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

        <div id="total-budget-graph" class="overview-expenditure-graphs" style="display: none;">
          <div class="graph-container"></div>
          <div class="expenditure-budget-value">
            <?php print '<strong>$' . number_format($total_expenditure, 1)  . 'm</strong> / $' . number_format($total_budget, 1) . 'm'; ?>
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
    </div>
    <div class="t-1of3 d-1of3" id="ict-dashboard-numbers">
      <div class="row">
        <div class="label">
          <?php print t('Number of Active Projects'); ?>
          <a href="javascript:void(0);" class="tooltip">
            <i class="tooltip-icon"></i>
            <span class="tooltip-content">
              <?php print t('The number of ICT-enabled projects with a total project cost of $30 million or more, including ICT costs of at least $10 million.'); ?>
            </span>
          </a>
        </div>
        <div class="big-number">
          <?php print $number_of_projects ?>
        </div>
      </div>

      <div class="row">
        <div class="label">
          <?php print t('Total Number of Benefits Listed'); ?>
          <a href="javascript:void(0);" class="tooltip">
            <i class="tooltip-icon"></i>
            <span class="tooltip-content">
              <?php print t('The number of benefits over all active projects.'); ?>
            </span>
          </a>
        </div>
        <div class="big-number">
          <?php print $total_number_of_benefits; ?>
        </div>
      </div>

      <a href="" class="general-button arrow-right"><span><?php print t('View Detailed Overview'); ?></span></a>
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

        $('.budget-tooltip').hide();
        $('#'+activeItem+'-tooltip').show();
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
    });

  })(jQuery);
</script>