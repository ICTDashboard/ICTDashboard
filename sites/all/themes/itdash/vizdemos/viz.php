<!DOCTYPE html>
<meta charset="utf-8">
<style>

    .bar {
        fill: steelblue;
    }

    .bar:hover {
        fill: brown;
    }

    .axis {
        font: 10px sans-serif;
    }

    .axis path,
    .axis line {
        fill: none;
        stroke: #000;
        shape-rendering: crispEdges;
    }

    .x.axis path {
        display: none;
    }

</style>
<body>
<script src="http://d3js.org/d3.v3.min.js"></script>
<script src="http://nvd3.org/assets/js/nv.d3.js"></script>
<script>

    var margin = {top: 20, right: 20, bottom: 30, left: 40},
        width = 960 - margin.left - margin.right,
        height = 500 - margin.top - margin.bottom;

    var x = d3.scale.ordinal()
        .rangeRoundBands([0, width], .1);

    var y = d3.scale.linear()
        .range([height, 0]);

    var xAxis = d3.svg.axis()
        .scale(x)
        .orient("bottom");

    var yAxis = d3.svg.axis()
        .scale(y)
        .orient("left")
        .ticks(10, "%");

    var svg = d3.select("body").append("svg")
        .attr("width", width + margin.left + margin.right)
        .attr("height", height + margin.top + margin.bottom)
        .append("g")
        .attr("transform", "translate(" + margin.left + "," + margin.top + ")");


    d3.json("http://ckan.itdash.lws.links.com.au/api/action/datastore_search_sql?sql=SELECT%20*%20from%20%222133eaed-150b-4c73-a314-67a0bde04115%22%20WHERE%20metric%20=%20%27total_project_budget%27",
        function(error, data) {
            console.log(data.result.records);
            x.domain(data.result.records.map(function (d) {
                return d.name;
            }));
            y.domain([0, d3.max(data.result.records, function (d) {
                return parseInt(d.value);
            })]);


    svg.append("g")
            .attr("class", "x axis")
            .attr("transform", "translate(0," + height + ")")
            .call(xAxis);

        svg.append("g")
            .attr("class", "y axis")
            .call(yAxis)
            .append("text")
            .attr("transform", "rotate(-90)")
            .attr("y", 6)
            .attr("dy", ".71em")
            .style("text-anchor", "end")
            .text("Frequency");

        svg.selectAll(".bar")
            .data(data.result.records)
            .enter().append("rect")
            .attr("class", "bar")
            .attr("x", function(d) { return x(d.name); })
            .attr("width", x.rangeBand())
            .attr("y", function(d) { return y(parseInt(d.value)); })
            .attr("height", function(d) { return height - y(parseInt(d.value)); });

    });

    function type(d) {
        d.value = +parseInt(d.value);
        return d;
    }

</script>