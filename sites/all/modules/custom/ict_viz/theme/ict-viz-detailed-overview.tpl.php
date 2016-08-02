<script src="http://labratrevenge.com/d3-tip/javascripts/d3.tip.v0.6.3.js"></script>
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
    <div id="detailed-view-expenditure" style="max-width: 945px;">
        <!-- <canvas id="detailed_budget_chart" width="945" height="360"></canvas> -->
        <svg id="detailed-overview-chart"></svg>
        <div id="expenditure_legend" class="legend">
          <ul class="bar-legend">
            <li>
              <span style="background-color:#ff6161">
                <img src="/<?php print drupal_get_path('theme', 'itdash') . '/html/images/legends/legend-ff6161.jpg';?>" />
              </span>
              <?php print t('Expenditure to Date ($m)'); ?>
            </li>
            <li>
              <span style="background-color:#5c46a4">
                <img src="/<?php print drupal_get_path('theme', 'itdash') . '/html/images/legends/legend-5c46a4.jpg';?>" />
              </span>
              <?php print t('Total Budget ($m)'); ?>
            </li>
<!--             <li>
              <span class="required">*</span>
              <?php print t('Current Financial Year'); ?>
            </li> -->
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
            <span style="background-color:<?php print '#f6d000'; ?>">
              <img src="/<?php print drupal_get_path('theme', 'itdash') . '/html/images/legends/legend-f6d000.jpg';?>" />
            </span>
            <?php print t('Behind Schedule'); ?>
          </li>
          <li>
            <span style="background-color:<?php print '#1fd063'; ?>">
              <img src="/<?php print drupal_get_path('theme', 'itdash') . '/html/images/legends/legend-1fd063.jpg';?>" />
            </span>
            <?php print t('On Track'); ?>
          </li>
          <li>
            <span style="background-color:<?php print '#75a2df'; ?>">
              <img src="/<?php print drupal_get_path('theme', 'itdash') . '/html/images/legends/legend-75a2df.jpg';?>" />
            </span>
            <?php print t('Ahead of Schedule'); ?>
          </li>
          <li>
            <span class="noofproj"><b>#</b></span> <?php print t('No. of Projects'); ?>
          </li>
          <li>
            <span class="curqua"><b>*</b></span> <?php print t('Current Quarter'); ?>
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

jQuery(document).ready(function () {

 if(jQuery( window ).width() > 1024) {
  var bar_width = 41;
  var bar_distance = 14;
  var bar_distance2 = 56;
  var bar_x_distance = 100;
  var activate_year_line_x1 = -41;
  var activate_year_line_x2 = 42;
  var tooltip_bar_x = -70;
  var tooltip_bar_y = 30;
 }
 else {
  var bar_width = 31;
  var bar_distance = 10;
  var bar_distance2 = 42;
  var bar_x_distance = 325;
  var activate_year_line_x1 = -30
  var activate_year_line_x2 = 32
  var tooltip_bar_x = -50;
  var tooltip_bar_y = 30;
 }


  var margin = {top: 20, right: 20, bottom: 30, left: 40},
    width = 960 - margin.left - margin.right,
    height = 360 - margin.top - margin.bottom;

  var detailed_budget = Drupal.settings.detailed_budget_chart;

  var arr = [];
  var element = [];

  for(i = 0; i < detailed_budget.data.labels.length; i++) {
    arr.push({
      x: detailed_budget.data.datasets[0].data[i],y: detailed_budget.data.datasets[1].data[i], years: detailed_budget.data['labels'][i], element : i
    });
    element.push(i);
  };
  var current_year = "20" + detailed_budget.data.current_year.replace("/", "-") + "*";
  var current_year2 = "20" + detailed_budget.data.current_year.replace("/", "-");

  var current = jQuery.map(arr, function(value,key){
    if(value.years == current_year) {
      var current_key = key;
      return value;

    }    
  })

  var arr2 = arr.slice(current[0].element - 3,current[0].element + 4); 

    var x = d3.scale.ordinal()
    .domain(arr2.map(function(d) { return d.years; }))
    .rangeRoundBands([0, width - margin.right - bar_x_distance])

    var y = d3.scale.linear()
    .range([height, 0])
    .domain([0,
      d3.max(arr2, function(d) {
        return d.y;
      })
    ]);

    var xAxis = d3.svg.axis()
    .scale(x)
    .orient("bottom");

    var yAxis = d3.svg.axis()
    .scale(y)
    .orient("left")
    .tickSize(0)
    .tickFormat(function (d) {
      var prefix = d3.formatPrefix(d);
      return '$' + prefix.scale(d);
    });


    function make_y_axis() {
      return d3.svg.axis()
          .scale(y)
          .orient("left")
    }

  var tip = d3.tip()
    .attr('class', 'd3-tip')
    .offset([tooltip_bar_y, tooltip_bar_x])
    .html(function(d) {
      return "<span style='border-radius: 5px;padding: 10px;background: #fff; display: block;color:black; font-weight:bold; font-size: 12px;'>"+ d.years + "</br><span style='display: inline-block;width: 10px;height: 10px;background: #FF6161;content:'';'></span> $" + d.x + "m" + "</br><span style='display: inline-block;width: 10px;height: 10px;background: #5C46A4;content:'';'></span> $" + d.y + "m" + "</span>";
    })

  var chart = d3.select("#detailed-overview-chart")
    .attr("width", width + margin.left + margin.right)
    .attr("height", height + margin.top + margin.bottom)
    .append("g")
    .attr("transform", "translate(" + margin.left + "," + margin.top + ")");

  chart.call(tip);
 
  chart.append("g")            
    .attr("class", "grid")
    .call(make_y_axis()
      .tickSize(-width , 0, 0)
      .tickFormat("")
    )

  chart.append("g")
      .attr("class", "x axis")
      .attr("transform", "translate(0," + height + ")")
      .call(xAxis);

  chart.append("g")
      .attr("class", "y axis")
      .call(yAxis);


  chart.selectAll("div")
      .data(arr2)
      .enter().append("rect")
      .attr("class", "bar1")
      .style("fill", "#FF6161")
      .attr("x", function(d) {return x(d.years) + bar_distance; })
      .attr("y",height)
      .attr("width", bar_width)  
      .attr("height", 0)
      .on('mouseover', tip.show)
      .on('mouseout', tip.hide)
      .transition()
      .duration(1500)
      .attr("y", function (d) { return y(d.x);})
      .attr("height", function (d) { return (height - y(d.x)); })
      .filter(function(d) { return d.x == current[0].x; })
      .style("fill", "#FC3E3E")
      .attr("class", "fdasfds");

  chart.selectAll("div")
      .data(arr2)
      .enter().append("rect")
      .attr("class", "bar2")
      .style("fill", "#5C46A4")
      .attr("x", function(d) {return x(d.years) + bar_distance2; })
      .attr("y", height)
      .attr("width", bar_width)
      .attr("height", 0)
      .on('mouseover', tip.show)
      .on('mouseout', tip.hide)
      .transition()
      .duration(1500)
      .attr("y", function (d) { return y(d.y);})
      .attr("height", function (d) { return (height - y(d.y)); })
      .filter(function(d) { return d.y == current[0].y; })
        .style("fill", "#3D2390");

  chart.selectAll('.x .tick')
      .data(arr2)
      .each(function(d, i) {
          if(d.years == current_year) {
              d3.select(this)
                .append('line')
                .attr({
                    "text-anchor": "middle",
                    dy: 24,
                    "y1" : 28,
                    "y2" : 28,
                    "x1" : activate_year_line_x1,
                     "x2" : activate_year_line_x2,
                    "font-size": "10.5px",
                    "class": "line-current-year"

                })
              d3.select(this)
                .selectAll('.line-current-year')
                    .style({
                      "stroke": "#FC3E3E",
                      "stroke-width": "4px"

                })
          }
      });

  jQuery( "text:contains("+ current[0].years +")").css('fill', '#3D2390').text(current_year2);

});

  (function ($){
    $(document).ready(function () {
  //     // *** Expenditure Graph ***
  //     var ctx = document.getElementById("detailed_budget_chart").getContext("2d");
  //     var ExpenditureChart = new Chart(ctx).Bar(
  //       Drupal.settings.detailed_budget_chart.data,
  //       Drupal.settings.detailed_budget_chart.options
  //     );
  //     $('#detailed_budget_chart').css('width', '100%');
  //     if (screen.width == 320) {
  //       $('#detailed_budget_chart').css('max-width', 280 + 'px');
  //     }
  //     $('#detailed_budget_chart').css('height', 'auto');
      // *** Schedule Status Graph ***
      var data = Drupal.settings.detailed_schedule_chart,
        width = $('#detailed-view-schedule-status').innerWidth();

      var max_bar = width < 808 ? width - 124 : 684,
          left_padding = 94;

      // align legend with graph
      $('#statuses_legend .bar-legend').css('padding-left', left_padding+'px');
      $('#detailed-view-schedule-status .expand-collapse-button').css('margin-left', left_padding+'px');

      // expand/collapse buttons
      if (typeof data.data['previous'] == 'undefined' || typeof data.data['current'] == 'undefined') {
        $('#detailed-view-schedule-status .expand-collapse-button').hide();

        if (typeof data.data['current'] == 'undefined') {
          $('#detailed_schedule_chart_previous').show();
        }
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
        
        var current_is_printed = false;
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
          // quarter numberX
          quarter_text
            .append("svg:tspan")
            .text(getGetOrdinal(quarter)+" Quarter");

          var year_dy = 22;
          if (!current_is_printed && year == 'current') {
            quarter_text
              .append("svg:tspan")
              .attr("x", 5)
              .attr("dx", 78)
              .attr("dy", 12)
              .text("*");

            current_is_printed = true;
            year_dy = 10;
          }

          // year
          quarter_text
            .append("svg:tspan")
            .attr("font-weight", 'bold')
            .attr("x", 13)
            .attr("dy", year_dy)
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
