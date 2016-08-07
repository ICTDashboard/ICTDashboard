  jQuery(document).ready(function () {

    var margin = {top: 20, right: 20, bottom: 30, left: 40},
      width = 960 - margin.left - margin.right,
      height = 360 - margin.top - margin.bottom;

    var budget_chart = Drupal.settings.budget_chart;

   if(jQuery( window ).width() > 1024) {
    var tooltip_bar_x = -70;
    var tooltip_bar_y = 30;
   }
   else {
    var tooltip_bar_x = -50;
    var tooltip_bar_y = 30;
   }

    var arr = [];
    var element = [];

    for(i = 0; i < budget_chart.data.labels.length; i++) {
      arr.push({
        x: budget_chart.data.datasets[0].data[i],y: budget_chart.data.datasets[1].data[i], years: budget_chart.data['labels'][i], element : i
      });
      element.push(i);
    };

  var current_year = "20" + budget_chart.data.current_year.replace("/", "-") + "*";
  var current_year2 = "20" + budget_chart.data.current_year.replace("/", "-");

  var current = jQuery.map(arr, function(value,key){
    if(value.years == current_year) {
      var current_key = key;
      return value;

    }    
  })

  var margin = {top: 20, right: 30, bottom: 30, left: 40},
    width = 960 - margin.left - margin.right,
    height = 360 - margin.top - margin.bottom;

  var x = d3.scale.ordinal()
    .domain(arr.map(function(d) { return d.years; }))
    .rangeRoundBands([0, width], .1);

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
      return "<span style='border-radius: 5px;padding: 10px;background: #fff; display: block;color:black; font-weight:bold; font-size: 12px;'>"+ d.years + "</br><span style='display: inline-block;width: 10px;height: 10px;background: #FF6161;content:'';'></span> $" + d.x + "m" + "</br><span style='display: inline-block;width: 10px;height: 10px;background: #5C46A4;content:'';'></span> $" + d.y + "m" + "</span>";
    })
  var chart = d3.select("#project-individual-budget-chart")
    .attr("width", width + margin.left + margin.right)
    .attr("height", height + margin.top + margin.bottom)
    .append("g")
    .attr("transform", "translate(" + margin.left + "," + margin.top + ")")
    .call(d3.behavior.zoom().scaleExtent([1, 1]).on("zoom", zoom));

    chart.call(tip);
  
    chart.append("g")            
      .attr("class", "grid")
      .call(make_y_axis()
        .tickSize(-width , 0, 0)
        .tickFormat("")
    )


  //Add a clip path, so the content outside the domain should be hidden

  var mSvg = d3.select("#project-individual-budget-chart");



  //Add a "defs" element to the svg
  var defs = mSvg.append("defs");

  //Append a clipPath element to the defs element, and a Shape
  // to define the cliping area
  defs.append("clipPath").attr('id','my-clip-path').append('rect')
      .attr('width',width) //Set the width of the clipping area
      .attr('height',height); // set the height of the clipping area

  //clip path for x axis
  defs.append("clipPath").attr('id','x-clip-path').append('rect')
      .attr('width',width) //Set the width of the clipping area
      .attr('height',height + margin.bottom); // set the height of the clipping area

  //add a group that will be clipped (this will contain the bars)
  var barsGroup = chart.append('g');

  //Set the clipping path to the group (g element) that you want to clip
  barsGroup.attr('clip-path','url(#my-clip-path)');

  var xAxisGroup = chart.append("g").attr('class','x-axis')

  xAxisGroup.append('g')
    .attr("class", "x axis")
    .attr("transform", "translate(0," + height + ")")
    .call(xAxis);

  //The xAxis is scalled on zoom, so we need to clip it to

  xAxisGroup.attr('clip-path','url(#x-clip-path)');

  chart.append("g")
    .attr("class", "y axis")
    .call(yAxis);

  var bars = barsGroup.selectAll(".div ")
    .data(arr)
    .enter().append("rect")
    .attr("class",function(d) {if(d.x == current[0].x){ return "active_bar";} else { return "bar";} } )
    .style("fill",function(d) {if(d.x == current[0].x){ return "#FC3E3E";} else { return "#FF6161";} } )
    .attr("x", function(d) { return x(d.years); })
    .attr("width", x.rangeBand() / 2)
    .attr("height", 0)
    .attr("y", height)
    .on('mouseover', tip.show)
    .on('mouseout', tip.hide)
    
    bars.transition()
    .duration(1500)
    .attr("y", function(d) { return y(d.x); })
    .attr("height", function(d) { return height - y(d.x); })

  var bars2 = barsGroup.selectAll(".div")
    .data(arr)
    .enter().append("rect")
    .attr("class",function(d) {if(d.y == current[0].y){ return "active_bar2";} else { return "bar2";} } )
    .style("fill", function(d) {if(d.y == current[0].y){ return "#3D2390";} else { return "#5C46A4";} })
    .attr("x", function(d) { return x(d.years) + x.rangeBand() / 2 + 1; })
    .attr("width", x.rangeBand() / 2)
    .attr("height", 0)
    .attr("y", height)
    .on('mouseover', tip.show)
    .on('mouseout', tip.hide)
    
    bars2.transition()
    .duration(1500)
    .attr("y", function(d) { return y(d.y); })
    .attr("height", function(d) { return height - y(d.y); })

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
                    "x1" :  -x.rangeBand() / 2,
                     "x2" : x.rangeBand() / 2,
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
    bars.attr("transform", "translate(" + d3.event.translate[0]+",0)scale(" + d3.event.scale + ",1)");
    bars2.attr("transform", "translate(" + d3.event.translate[0]+",0)scale(" + d3.event.scale + ",1)");
      chart.select(".x.axis").attr("transform", "translate(" + d3.event.translate[0]+","+(height)+")")
          .call(xAxis.scale(x.rangeRoundBands([0, width * d3.event.scale],.1 * d3.event.scale)));
    chart.select(".y.axis").call(yAxis);

    jQuery( "text:contains("+ current_year +")").css('fill', '#3D2390').text(current_year2);

      chart.selectAll('.x .tick')
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
                      "x1" : -x.rangeBand() / 2,
                       "x2" : x.rangeBand() / 2,
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
  }
});

     // (function ($) {
  //   $(document).ready(function () {

  //     var ctx = document.getElementById("budgetChart").getContext("2d");
  //     var ExpenditureChart = new Chart(ctx).Bar(
  //       Drupal.settings.budget_chart.data,
  //       Drupal.settings.budget_chart.options
  //     );

  //   });
  // })(jQuery);