<!DOCTYPE html>
<meta charset="utf-8">
<body>
<script src="http://d3js.org/d3.v3.min.js"></script>
<link href="http://nvd3.org/assets/css/nv.d3.css" rel="stylesheet">
<script src="http://nvd3.org/assets/js/nv.d3.js"></script>
<style>

    #chart svg {
        height: 400px;
        width: 600px;
        padding: 22px;
    }
    .field-name-body {
        height: 400px;
        background-color: transparent;
        width: 100%;
    }

</style>


<div id="chart">
    <svg></svg>
</div>

<script>


    d3.json("http://ckan.itdash.lws.links.com.au/api/action/datastore_search_sql?sql=<?php print urlencode("select distinct p.name, total_value, expected_total_value  FROM (select name, value as total_value from \"2133eaed-150b-4c73-a314-67a0bde04115\" where metric = 'total_project_budget' ) p full outer JOIN     (select DISTINCT d.name, d.value as expected_total_value from \"2133eaed-150b-4c73-a314-67a0bde04115\" d join (select name,metric, max(timestamp) as timestamp     from \"2133eaed-150b-4c73-a314-67a0bde04115\" GROUP BY name,metric) s on d.metric=s.metric and d.timestamp=s.timestamp     where d.metric = 'current_total_expected_budget') b on p.name = b.name;")?>",
        function(error, data) {
            project_names = [];
            project_orig_budget = [];
            project_current_budget = [];

            for (var i in data.result.records) {
                d =  data.result.records[i]
                project_names[i] = d.name;
                project_orig_budget[i] = d.total_value;
                project_current_budget[i] = d.expected_total_value;
            }



            datum = [{'key': "Planned Budget", 'values': []}, {'key': "Actual Budget", 'values': []}];
            for (var i in project_names) {
                datum[0]['values'].push({'x': i, 'y': parseInt(project_orig_budget[i])});
                datum[1]['values'].push({'x': i, 'y': parseInt(project_current_budget[i])});
            }
            nv.addGraph(function() {
                var chart = nv.models.multiBarChart();

                chart.xAxis
                    .tickFormat(function(d) {
                        return project_names[d];
                    });

                chart.yAxis
                    .tickFormat(d3.format('$,.1f'));

                d3.select('#chart svg')
                    .datum(datum)
                    .transition().duration(500)
                    .call(chart)
                ;

                nv.utils.windowResize(chart.update);

                return chart;
            });

        });


</script>
