jQuery(document).ready(function () {

  var margin = {top: 20, right: 20, bottom: 30, left: 40},
    width = 960 - margin.left - margin.right,
    height = 360 - margin.top - margin.bottom;

  var detailed_budget = Drupal.settings.detailed_budget_chart;

   if(jQuery( window ).width() > 767) {
    var bar_distance = 350;
    var bar_distance2 = 350;
    var bar_x_distance = 100;
    var activate_year_line_x = 391;
    var activate_year_line_x2 = 42;
    var tooltip_bar_x = -70;
    var tooltip_bar_y = 30;
    var focus_current = -width / 9;
   }
   else {
    var bar_distance = 85;
    var bar_distance2 = 85;
    var bar_x_distance = 325;
    var activate_year_line_x = 118;
    var tooltip_bar_x = -50;
    var tooltip_bar_y = 30;
    var focus_current = -width / 4;
   }


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
  var length_width = arr.length;

  var margin = {top: 20, right: 30, bottom: 30, left: 40},
    width = 960 - margin.left - margin.right,
    height = 360 - margin.top - margin.bottom;

  var x = d3.scale.ordinal()
    .domain(arr.map(function(d) { return d.years; }))
    .rangeRoundBands([0, length_width * 100 - margin.right  - bar_x_distance ], .25, -1);

  var y = d3.scale.linear()
  .range([height, 0])
  .domain([0,
    d3.max(arr, function(d) {
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
      if(d.years == current_year) {
      d.years = current_year2
      } 
      return "<span style='box-shadow: 0px 0px 5px 0px #4e5365; border:1px solid #ededed; border-radius: 5px;padding: 10px;background: #fff; display: block;color:black; font-weight:bold; font-size: 12px;'>"+ d.years + "</br><span style='display: inline-block;width: 10px;height: 10px;background: #FF6161;content:'';'></span> $" + d.x + "m" + "</br><span style='display: inline-block;width: 10px;height: 10px;background: #5C46A4;content:'';'></span> $" + d.y + "m" + "</span>";
    })
  var chart = d3.select("#detailed-overview-chart")
    .attr("width", width + margin.left + margin.right)
    .attr("height", height + margin.top + margin.bottom)
    .append("g")
    .attr("transform", "translate(" + margin.left + "," + margin.top + ")")
    .call(d3.behavior.zoom().scaleExtent([1, 1]).on("zoom", zoom));

chart.append("chart:rect")
    .attr("width", width)
    .attr("height", height)
    .attr("fill", "#fff")
    .attr("class", "main-scroll-area");

    chart.call(tip);
  
    chart.append("g")            
      .attr("class", "grid")
      .call(make_y_axis()
        .tickSize(-width , 0, 0)
        .tickFormat("")
    )

  var mSvg = d3.select("#detailed-overview-chart");

  var defs = mSvg.append("defs");

  defs.append("clipPath").attr('id','my-clip-path').append('rect')
      .attr('width',width)
      .attr('height',height);
  defs.append("clipPath").attr('id','x-clip-path').append('rect')
      .attr('width',width)
      .attr('height',height + margin.bottom);

  var barsGroup = chart.append('g');

  barsGroup.attr('clip-path','url(#my-clip-path)');

  var xAxisGroup = chart.append("g").attr('class','x-axis')

  xAxisGroup.append('g')
    .attr("class", "x axis")
    .attr("transform", "translate(0," + height + ")")
    .call(xAxis)
    // .transition()
    // .duration(1500)
    // .attr("transform", "translate("+ focus_current +"," + height + ")") //////////////////////////////////////////////////////////////////

  xAxisGroup.attr('clip-path','url(#x-clip-path)');

  chart.append("g")
    .attr("class", "y axis")
    .call(yAxis);

  var bars = barsGroup.selectAll(".div ")
    .data(arr)
    .enter().append("rect")
    .attr("class",function(d) {if(current.length > 0 && d.x == current[0].x){ return "active_bar";} else { return "bar";} } )
    .style("fill",function(d) {if(current.length > 0 && d.x == current[0].x){ return "#FC3E3E";} else { return "#FF6161";} } )
    .attr("x", function(d) { return x(d.years); })
    .attr("width", x.rangeBand() / 2 - 1)
    .attr("height", 0)
    .attr("y", height)
    .on('mouseover', tip.show)
    .on('mouseout', tip.hide)

    var active_bar = jQuery( ".active_bar").attr('x') 
    bars.attr("x", function(d) { return x(d.years) - active_bar + bar_distance; })   
    bars.transition()
    .duration(1500)
    
    .attr("y", function(d) { return y(d.x); })
    .attr("height", function(d) { return height - y(d.x); })
    // .transition()
    // .duration(1500)
    // .attr("transform", "translate("+ focus_current +",0)") //////////////////////////////////////////////////////////////////


  var bars2 = barsGroup.selectAll(".div")
    .data(arr)
    .enter().append("rect")
    .attr("class",function(d) {if(current.length > 0 && d.y == current[0].y){ return "active_bar2";} else { return "bar2";} } )
    .style("fill", function(d) {if(current.length > 0 && d.y == current[0].y){ return "#3D2390";} else { return "#5C46A4";} })
    // .attr("transform", "translate(-165,0)") //////////////////////////////////////////////////////////////////
    .attr("x", function(d) { return x(d.years) + x.rangeBand() / 2 + 1; })
    .attr("width", x.rangeBand() / 2 - 1)
    .attr("height", 0)
    .attr("y", height)
    .on('mouseover', tip.show)
    .on('mouseout', tip.hide)
    
    var active_bar2 = jQuery( ".active_bar2").attr('x')
    bars2.attr("x", function(d) { return x(d.years) + x.rangeBand() / 2 + 1 - active_bar2 + x.rangeBand() / 2 + bar_distance2; })        
    bars2.transition()
    .duration(1500)
   
    .attr("y", function(d) { return y(d.y); })
    .attr("height", function(d) { return height - y(d.y); })
    // .transition()
    // .duration(1500)
    // .attr("transform", "translate("+ focus_current +",0)") //////////////////////////////////////////////////////////////////

var x_path = jQuery( "text:contains("+ current_year +")").parent().attr('transform')
var x_path_sliced = parseFloat(x_path.match(/\((.*)\)/)[1])

jQuery(".x-axis .x g[transform]").attr("transform", function(index, transform){
    var x_coordinate = parseFloat(transform.match(/\((.*)\)/)[1]);
    jQuery(this).attr("transform", "translate("+ (x_coordinate - x_path_sliced + activate_year_line_x) +",0)");
});
  chart.selectAll('.x-axis .x .tick')
      .data(arr)
      .each(function(d, i) {
          if(d.years == current_year) {
              d3.select(this)
                .append('line')
                .attr({
                    "text-anchor": "middle",
                    dy: 24,
                    "y1" : 28,
                    "y2" : 28,
                    "x1" :  -x.rangeBand() / 2 - 1,
                     "x2" : x.rangeBand() / 2 - 2,
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

  jQuery( "text:contains("+ current_year +")").css('fill', '#3D2390').text(current_year2);

  function zoom() {
    var scroll_limit_for_bars1 = jQuery("#detailed-view-expenditure .bar").first().attr('x');
    var scroll_limit_for_bars2 = jQuery("#detailed-view-expenditure .bar2").last().attr('x');
    var tx = Math.min(-scroll_limit_for_bars1 + 20, Math.max(d3.event.translate[0], -scroll_limit_for_bars2 + 40));
    bars.attr("transform", "translate(" + tx +",0)scale(" + d3.event.scale + ",1)");
    bars2.attr("transform", "translate(" + tx +",0)scale(" + d3.event.scale + ",1)");
    chart.select(".x.axis").attr("transform", "translate(" + tx +","+(height)+")")
          .call(xAxis.scale(x.rangeRoundBands([0, length_width * 100 - margin.right  - bar_x_distance * d3.event.scale],.25 * d3.event.scale, -1 * d3.event.scale)));
    chart.select(".y.axis").call(yAxis);

    jQuery( "text:contains("+ current_year +")").css('fill', '#3D2390').text(current_year2);

    chart.selectAll('.x .tick')
      .data(arr)
      .each(function(d, i) {
          if(d.years == current_year) {
            d.years = current_year2
          } 
          if(d.years == current_year2) {
              d3.select(this)
                .append('line')
                .attr({
                    "text-anchor": "middle",
                    dy: 24,
                    "y1" : 28,
                    "y2" : 28,
                    "x1" : -x.rangeBand() / 2 - 1,
                     "x2" : x.rangeBand() / 2 - 2,
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

      chart.select(".grid")
        .call(make_y_axis()
        .tickSize(-width, 0, 0)
        .tickFormat(""));

    jQuery(".x-axis .x g[transform]").attr("transform", function(index, transform){
    var x_coordinate = parseFloat(transform.match(/\((.*)\)/)[1]);
    jQuery(this).attr("transform", "translate("+ (x_coordinate - x_path_sliced + activate_year_line_x) +",0)");
    });
  }
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