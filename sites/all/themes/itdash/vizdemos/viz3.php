<!doctype html>
<html>
<head>
    <script src="http://code.jquery.com/jquery-latest.min.js"></script>
    <script src="http://d3js.org/d3.v3.min.js" charset="utf-8"></script>
    <script src="http://itdash.127.0.0.1.xip.io/sites/all/themes/itdash/js/d3-timeline.js"></script>

    <style type="text/css">
        .axis path,
        .axis line {
            fill: none;
            stroke: black;
            shape-rendering: crispEdges;
        }

        .axis text {
            font-family: sans-serif;
            font-size: 10px;
        }

        .timeline-label {
            font-family: sans-serif;
            font-size: 12px;
        }

        #timeline2 .axis {
            transform: translate(0px,30px);
            -ms-transform: translate(0px,30px); /* IE 9 */
            -webkit-transform: translate(0px,30px); /* Safari and Chrome */
            -o-transform: translate(0px,30px); /* Opera */
            -moz-transform: translate(0px,30px); /* Firefox */
        }

        .coloredDiv {
            height:20px; width:20px; float:left;
        }
    </style>
    <script type="text/javascript">
        (function() {

            var d = window.Date,
                regexIso8601 = /^(\d{4}|\+\d{6})(?:-(\d{2})(?:-(\d{2})(?:T(\d{2}):(\d{2}):(\d{2})?)?)?)?$/;

            if (d.parse('2011-11-29T15:52:30') !== 1322581950500 ||
                d.parse('2011-11-29') !== 1322524800000 ||
                d.parse('2011-11') !== 1320105600000 ||
                d.parse('2011') !== 1293840000000) {

                d.__parse = d.parse;

                d.parse = function(v) {

                    var m = regexIso8601.exec(v);

                    if (m) {
                        return Date.UTC(
                            m[1],
                            (m[2] || 1) - 1,
                            m[3] || 1,
                            m[4] - (m[8] ? m[8] + m[9] : 0) || 0,
                            m[5] - (m[8] ? m[8] + m[10] : 0) || 0,
                            m[6] || 0,
                            ((m[7] || 0) + '00').substr(0, 3)
                        );
                    }

                    return d.__parse.apply(this, arguments);

                };
            }

            d.__fromString = d.fromString;

            d.fromString = function(v) {

                if (!d.__fromString || regexIso8601.test(v)) {
                    return new d(d.parse(v));
                }

                return d.__fromString.apply(this, arguments);
            };

        })();
        window.onload = function() {






                    var width = 930;
            var colorScale = d3.scale.ordinal().range(['#6b0000','#ef9b0f','#ffee00'])
                .domain(['apple','orange','lemon']);

            function timelineHover() {
                d3.json("http://ckan.itdash.lws.links.com.au/api/action/datastore_search_sql?sql=<?php print urlencode("select distinct p.name, start_date, end_date, expected_end_date, total_value, expected_total_value
FROM (select name, value as start_date from\"2133eaed-150b-4c73-a314-67a0bde04115\" where metric = 'original_completion_date'  ) p full outer JOIN
  (select name, value as end_date from \"2133eaed-150b-4c73-a314-67a0bde04115\" where metric = 'start_date' ) a on p.name = a.name full outer JOIN
  (select name, value as total_value from \"2133eaed-150b-4c73-a314-67a0bde04115\" where metric = 'total_project_budget' ) v on p.name = v.name full outer JOIN
  (select DISTINCT d.name, d.value as expected_end_date from \"2133eaed-150b-4c73-a314-67a0bde04115\" d join (select name,metric, max(timestamp) as timestamp
from \"2133eaed-150b-4c73-a314-67a0bde04115\" GROUP BY name,metric) s on d.metric=s.metric and d.timestamp=s.timestamp
where d.metric = 'current_expected_completion_date') c on p.name = c.name full outer JOIN
  (select DISTINCT d.name, d.value as expected_total_value from \"2133eaed-150b-4c73-a314-67a0bde04115\" d join (select name,metric, max(timestamp) as timestamp
from \"2133eaed-150b-4c73-a314-67a0bde04115\" GROUP BY name,metric) s on d.metric=s.metric and d.timestamp=s.timestamp
where d.metric = 'current_total_expected_budget') b on p.name = b.name ")?>",
                    function(error, data) {
                        labelTestData = data.result.records.map(function (d) {
                            /* end_date: "2014-08-02T00:00:00"expected_end_date: "2015-08-10"expected_total_value: "70"name: "AAT Project B"start_date: "2015-07-02T00:00:00"total_value: "60.00"*/
                            starting_time = Date.fromString(d.start_date).getTime();
                            ending_time = Date.fromString(d.end_date).getTime();

                            return {label: d.name,
                                times: [{"starting_time": starting_time, "ending_time": ending_time}]}
                        });
                        /*                  .colors( colorScale )
                         .colorProperty('budget')*/
                var chart = d3.timeline()
                    .width(width)
                    .stack()
                    .margin({left:170, right:30, top:0, bottom:0})

                    .tickFormat({
                            format: d3.time.format("%B %Y"),
                                tickTime: d3.time.months})
                    .hover(function (d, i, datum) {
                        // d is the current rendering object
                        // i is the index during d3 rendering
                        // datum is the id object
                        var div = $('#hoverRes');
                        var colors = chart.colors();
                        div.find('.coloredDiv').css('background-color', colors(i))
                        div.find('#name').text(datum.label);
                    })
                    .click(function (d, i, datum) {
                        console.log(datum.label);
                    });

                var svg = d3.select("#timeline3").append("svg").attr("width", width)
                    .datum(labelTestData).call(chart);
                    });
            }

            timelineHover();
        }
    </script>
</head>
<body>

<div>
    <div id="timeline3"></div>
    <div id="hoverRes">
        <div class="coloredDiv"></div>
        <div id="name"></div>
        <div id="scrolled_date"></div>
    </div>
</div>


</body>
</html>