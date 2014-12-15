<?php
/**
 * @file
 * ict_dashboard_widgets.features.uuid_node.inc
 */

/**
 * Implements hook_uuid_features_default_content().
 */
function ict_dashboard_widgets_uuid_features_default_content() {
  $nodes = array();

  $nodes[] = array(
  'uid' => 1,
  'title' => 'ICT Project Treemap',
  'log' => '',
  'status' => 1,
  'comment' => 1,
  'promote' => 0,
  'sticky' => 0,
  'vuuid' => '2bc7d7bc-d1ef-4384-b46f-bb042cff32f0',
  'ds_switch' => '',
  'type' => 'page',
  'language' => 'und',
  'created' => 1418048094,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '5436dc7d-c224-44a2-9db4-02091f155065',
  'revision_uid' => 1,
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<style type="text/css">

    .chart {
        display: block;
        margin: auto;
    }

    text {
        font-size: 11px;
    }

    rect {
        fill: none;
    }

</style>
</head>
<body>
<div id="body">
    <div id="footer">
        <div class="hint">click or option-click to descend or ascend</div>
        <div><select>
                <option value="size">Value of Projects</option>
                <option value="count">Number of Projects</option>
            </select></div>
    </div>
</div>
<script type="text/javascript">

    var w = 930 - 80,
        h = 800 - 180,
        x = d3.scale.linear().range([0, w]),
        y = d3.scale.linear().range([0, h]),
        color = d3.scale.category20c(),
        root,
        node;

    var treemap = d3.layout.treemap()
        .round(false)
        .size([w, h])
        .sticky(true)
        .value(function(d) { return d.size; });

    var svg = d3.select("#body").append("div")
        .attr("class", "chart")
        .style("width", w + "px")
        .style("height", h + "px")
        .append("svg:svg")
        .attr("width", w)
        .attr("height", h)
        .append("svg:g")
        .attr("transform", "translate(.5,.5)");

      d3.json("http://ckan.itdash.lws.links.com.au/api/action/datastore_search_sql?sql=select+distinct+p.name%2C+government_business_unit%2C+government_programme%2C+government_entity%2Ctotal_value%2C+expected_total_value%0AFROM+%28select+name%2C+value+as+government_business_unit+from%222133eaed-150b-4c73-a314-67a0bde04115%22+where+metric+%3D+%27government_business_unit%27++%29+b+full+outer+JOIN%0A%28select+name%2C+value+as+total_value+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+where+metric+%3D+%27total_project_budget%27+%29+z+on+b.name+%3Dz.name+full+outer+JOIN%0A++%28select+name%2C+value+as+government_programme+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+where+metric+%3D+%27government_programme%27+%29+p+on+p.name+%3D+b.name+full+outer+JOIN%0A%28select+name%2C+value+as+government_entity+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+where+metric+%3D+%27government_entity%27+%29+e+on+p.name+%3D+e.name+full+outer+JOIN%0A+++%28select+DISTINCT+d.name%2C+d.value+as+expected_total_value+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+d+join+%28select+name%2Cmetric%2C+max%28timestamp%29+as+timestamp+%0Afrom+%222133eaed-150b-4c73-a314-67a0bde04115%22+GROUP+BY+name%2Cmetric%29+s+on+d.metric%3Ds.metric+and+d.timestamp%3Ds.timestamp+%0Awhere+d.metric+%3D+%27current_total_expected_budget%27%29+t+on+p.name+%3D+t.name++",
        function(error, data) {
            ents = {};
            progs = {};
            gbus = {};
            datum = {
                "name": "flare",
                "children": []
            };
            for (var i in data.result.records) {
                d = data.result.records[i];
                if (typeof ents[d.government_entity] == \'undefined\') {
                    ents[d.government_entity] = [];
                }
                ents[d.government_entity].push(d.government_programme);
                if (typeof progs[d.government_programme] == \'undefined\') {
                    progs[d.government_programme] = [];
                }
                progs[d.government_programme].push(d.government_business_unit);
                if (typeof gbus[d.government_business_unit]  == \'undefined\') {
                    gbus[d.government_business_unit] = [];
                }
                gbus[d.government_business_unit].push({name: d.name,
                    size: ( d.expected_total_value == null ? parseInt(d.total_value) : parseInt(d.expected_total_value))});
            }
            for (var ent in ents) {
                entobj = {
                    name: ent,
                    children: []
                };
                programs = ents[ent];
                for (var i in programs) {
                    prog = programs[i];
                    for (var j in progs[prog]) {
                        gbu = progs[prog][j];
                        progobj = {
                            name: prog,
                            children: gbus[gbu]
                        };
                        entobj.children.push(progobj);
                    }
                }
                datum.children.push(entobj);
            }
        node = root = datum;

        var nodes = treemap.nodes(root)
            .filter(function(d) { return !d.children; });

        var cell = svg.selectAll("g")
            .data(nodes)
            .enter().append("svg:g")
            .attr("class", "cell")
            .attr("transform", function(d) { return "translate(" + d.x + "," + d.y + ")"; })
            .on("click", function(d) { return zoom(node == d.parent ? root : d.parent); });

        cell.append("svg:rect")
            .attr("width", function(d) { return d.dx - 1; })
            .attr("height", function(d) { return d.dy - 1; })
            .style("fill", function(d) { return color(d.parent.name); });

        cell.append("svg:text")
            .attr("x", function(d) { return d.dx / 2; })
            .attr("y", function(d) { return d.dy / 2; })
            .attr("dy", ".35em")
            .attr("text-anchor", "middle")
            .text(function(d) { return d.name; })
            .style("opacity", function(d) { d.w = this.getComputedTextLength(); return d.dx > d.w ? 1 : 0; });

        d3.select(window).on("click", function() { zoom(root); });

        d3.select("select").on("change", function() {
            treemap.value(this.value == "size" ? size : count).nodes(root);
            zoom(node);
        });
    });

    function size(d) {
        return d.size;
    }

    function count(d) {
        return 1;
    }

    function zoom(d) {
        var kx = w / d.dx, ky = h / d.dy;
        x.domain([d.x, d.x + d.dx]);
        y.domain([d.y, d.y + d.dy]);

        var t = svg.selectAll("g.cell").transition()
            .duration(d3.event.altKey ? 7500 : 750)
            .attr("transform", function(d) { return "translate(" + x(d.x) + "," + y(d.y) + ")"; });

        t.select("rect")
            .attr("width", function(d) { return kx * d.dx - 1; })
            .attr("height", function(d) { return ky * d.dy - 1; })

        t.select("text")
            .attr("x", function(d) { return kx * d.dx / 2; })
            .attr("y", function(d) { return ky * d.dy / 2; })
            .style("opacity", function(d) { return kx * d.dx > d.w ? 1 : 0; });

        node = d;
        d3.event.stopPropagation();
    }

</script>
',
        'summary' => '',
        'format' => 'full_html',
        'safe_value' => '<style type="text/css">
<!--/*--><![CDATA[/* ><!--*/


    .chart {
        display: block;
        margin: auto;
    }

    text {
        font-size: 11px;
    }

    rect {
        fill: none;
    }


/*--><!]]>*/
</style><p><br /></p>
<div id="body">
<div id="footer">
<div class="hint">click or option-click to descend or ascend</div>
<div>
<select><option value="size">Value of Projects</option><br /><option value="count">Number of Projects</option><br /></select></div>
</div>
</div>
<script type="text/javascript">
<!--//--><![CDATA[// ><!--


    var w = 930 - 80,
        h = 800 - 180,
        x = d3.scale.linear().range([0, w]),
        y = d3.scale.linear().range([0, h]),
        color = d3.scale.category20c(),
        root,
        node;

    var treemap = d3.layout.treemap()
        .round(false)
        .size([w, h])
        .sticky(true)
        .value(function(d) { return d.size; });

    var svg = d3.select("#body").append("div")
        .attr("class", "chart")
        .style("width", w + "px")
        .style("height", h + "px")
        .append("svg:svg")
        .attr("width", w)
        .attr("height", h)
        .append("svg:g")
        .attr("transform", "translate(.5,.5)");

      d3.json("http://ckan.itdash.lws.links.com.au/api/action/datastore_search_sql?sql=select+distinct+p.name%2C+government_business_unit%2C+government_programme%2C+government_entity%2Ctotal_value%2C+expected_total_value%0AFROM+%28select+name%2C+value+as+government_business_unit+from%222133eaed-150b-4c73-a314-67a0bde04115%22+where+metric+%3D+%27government_business_unit%27++%29+b+full+outer+JOIN%0A%28select+name%2C+value+as+total_value+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+where+metric+%3D+%27total_project_budget%27+%29+z+on+b.name+%3Dz.name+full+outer+JOIN%0A++%28select+name%2C+value+as+government_programme+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+where+metric+%3D+%27government_programme%27+%29+p+on+p.name+%3D+b.name+full+outer+JOIN%0A%28select+name%2C+value+as+government_entity+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+where+metric+%3D+%27government_entity%27+%29+e+on+p.name+%3D+e.name+full+outer+JOIN%0A+++%28select+DISTINCT+d.name%2C+d.value+as+expected_total_value+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+d+join+%28select+name%2Cmetric%2C+max%28timestamp%29+as+timestamp+%0Afrom+%222133eaed-150b-4c73-a314-67a0bde04115%22+GROUP+BY+name%2Cmetric%29+s+on+d.metric%3Ds.metric+and+d.timestamp%3Ds.timestamp+%0Awhere+d.metric+%3D+%27current_total_expected_budget%27%29+t+on+p.name+%3D+t.name++",
        function(error, data) {
            ents = {};
            progs = {};
            gbus = {};
            datum = {
                "name": "flare",
                "children": []
            };
            for (var i in data.result.records) {
                d = data.result.records[i];
                if (typeof ents[d.government_entity] == \'undefined\') {
                    ents[d.government_entity] = [];
                }
                ents[d.government_entity].push(d.government_programme);
                if (typeof progs[d.government_programme] == \'undefined\') {
                    progs[d.government_programme] = [];
                }
                progs[d.government_programme].push(d.government_business_unit);
                if (typeof gbus[d.government_business_unit]  == \'undefined\') {
                    gbus[d.government_business_unit] = [];
                }
                gbus[d.government_business_unit].push({name: d.name,
                    size: ( d.expected_total_value == null ? parseInt(d.total_value) : parseInt(d.expected_total_value))});
            }
            for (var ent in ents) {
                entobj = {
                    name: ent,
                    children: []
                };
                programs = ents[ent];
                for (var i in programs) {
                    prog = programs[i];
                    for (var j in progs[prog]) {
                        gbu = progs[prog][j];
                        progobj = {
                            name: prog,
                            children: gbus[gbu]
                        };
                        entobj.children.push(progobj);
                    }
                }
                datum.children.push(entobj);
            }
        node = root = datum;

        var nodes = treemap.nodes(root)
            .filter(function(d) { return !d.children; });

        var cell = svg.selectAll("g")
            .data(nodes)
            .enter().append("svg:g")
            .attr("class", "cell")
            .attr("transform", function(d) { return "translate(" + d.x + "," + d.y + ")"; })
            .on("click", function(d) { return zoom(node == d.parent ? root : d.parent); });

        cell.append("svg:rect")
            .attr("width", function(d) { return d.dx - 1; })
            .attr("height", function(d) { return d.dy - 1; })
            .style("fill", function(d) { return color(d.parent.name); });

        cell.append("svg:text")
            .attr("x", function(d) { return d.dx / 2; })
            .attr("y", function(d) { return d.dy / 2; })
            .attr("dy", ".35em")
            .attr("text-anchor", "middle")
            .text(function(d) { return d.name; })
            .style("opacity", function(d) { d.w = this.getComputedTextLength(); return d.dx > d.w ? 1 : 0; });

        d3.select(window).on("click", function() { zoom(root); });

        d3.select("select").on("change", function() {
            treemap.value(this.value == "size" ? size : count).nodes(root);
            zoom(node);
        });
    });

    function size(d) {
        return d.size;
    }

    function count(d) {
        return 1;
    }

    function zoom(d) {
        var kx = w / d.dx, ky = h / d.dy;
        x.domain([d.x, d.x + d.dx]);
        y.domain([d.y, d.y + d.dy]);

        var t = svg.selectAll("g.cell").transition()
            .duration(d3.event.altKey ? 7500 : 750)
            .attr("transform", function(d) { return "translate(" + x(d.x) + "," + y(d.y) + ")"; });

        t.select("rect")
            .attr("width", function(d) { return kx * d.dx - 1; })
            .attr("height", function(d) { return ky * d.dy - 1; })

        t.select("text")
            .attr("x", function(d) { return kx * d.dx / 2; })
            .attr("y", function(d) { return ky * d.dy / 2; })
            .style("opacity", function(d) { return kx * d.dx > d.w ? 1 : 0; });

        node = d;
        d3.event.stopPropagation();
    }


//--><!]]>
</script>',
        'safe_summary' => '',
      ),
    ),
  ),
  'rdf_mapping' => array(
    'rdftype' => array(
      0 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
  ),
  'cid' => 0,
  'last_comment_name' => NULL,
  'last_comment_uid' => 1,
  'comment_count' => 0,
  'name' => 'admin',
  'picture' => 0,
  'data' => 'b:0;',
  'date' => '2014-12-09 01:14:54 +1100',
);
  $nodes[] = array(
  'uid' => 1,
  'title' => 'ICT Project Timelines',
  'log' => '',
  'status' => 1,
  'comment' => 1,
  'promote' => 0,
  'sticky' => 0,
  'vuuid' => 'e9808e16-4fe8-43be-8a0d-b716c0d3bd61',
  'ds_switch' => '',
  'type' => 'page',
  'language' => 'und',
  'created' => 1418048094,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '8754ca37-1410-4671-bb58-ce670b640f5d',
  'revision_uid' => 1,
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '  <style type="text/css">
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
<div>
    <div id="timeline3"></div>
    <div id="hoverRes">
        <div class="coloredDiv"></div>
        <div id="name"></div>
        <div id="scrolled_date"></div>
    </div>
</div>
    <script type="text/javascript">

        window.onload = function() {






                    var width = 930;


            function timelineHover() {
                           d3.json("http://ckan.itdash.lws.links.com.au/api/action/datastore_search_sql?sql=select+distinct+p.name%2C+start_date%2C+end_date%2C+expected_end_date%2C+total_value%2C+expected_total_value%0AFROM+%28select+name%2C+value+as+start_date+from%222133eaed-150b-4c73-a314-67a0bde04115%22+where+metric+%3D+%27original_completion_date%27++%29+p+full+outer+JOIN%0A++%28select+name%2C+value+as+end_date+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+where+metric+%3D+%27start_date%27+%29+a+on+p.name+%3D+a.name+full+outer+JOIN%0A++%28select+name%2C+value+as+total_value+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+where+metric+%3D+%27total_project_budget%27+%29+v+on+p.name+%3D+v.name+full+outer+JOIN%0A++%28select+DISTINCT+d.name%2C+d.value+as+expected_end_date+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+d+join+%28select+name%2Cmetric%2C+max%28timestamp%29+as+timestamp%0Afrom+%222133eaed-150b-4c73-a314-67a0bde04115%22+GROUP+BY+name%2Cmetric%29+s+on+d.metric%3Ds.metric+and+d.timestamp%3Ds.timestamp%0Awhere+d.metric+%3D+%27current_expected_completion_date%27%29+c+on+p.name+%3D+c.name+full+outer+JOIN%0A++%28select+DISTINCT+d.name%2C+d.value+as+expected_total_value+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+d+join+%28select+name%2Cmetric%2C+max%28timestamp%29+as+timestamp%0Afrom+%222133eaed-150b-4c73-a314-67a0bde04115%22+GROUP+BY+name%2Cmetric%29+s+on+d.metric%3Ds.metric+and+d.timestamp%3Ds.timestamp%0Awhere+d.metric+%3D+%27current_total_expected_budget%27%29+b+on+p.name+%3D+b.name+",
                    function(error, data) {
                        labelTestData = data.result.records.map(function (d) {
                            /* end_date: "2014-08-02T00:00:00"expected_end_date: "2015-08-10"expected_total_value: "70"name: "AAT Project B"start_date: "2015-07-02T00:00:00"total_value: "60.00"*/
                            starting_time = Date.fromString(d.start_date).getTime();
                            ending_time = Date.fromString(d.end_date).getTime();

                            return {label: d.name,
                                times: [{"starting_time": starting_time, "ending_time": ending_time}]}
                        });
                var chart = d3.timeline()
                    .width(width)
                    .stack()
                    .margin({left:170, right:30, top:0, bottom:0})
                    .tickFormat({
                            format: d3.time.format("%B %Y"),
                                tickTime: d3.time.months})
                   ;

                var svg = d3.select("#timeline3").append("svg").attr("width", width)
                    .datum(labelTestData).call(chart);
                    });
            }

            timelineHover();
        }
    </script>',
        'summary' => '',
        'format' => 'full_html',
        'safe_value' => '<style type="text/css">
<!--/*--><![CDATA[/* ><!--*/

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
    
/*--><!]]>*/
</style><div>
<div id="timeline3"></div>
<div id="hoverRes">
<div class="coloredDiv"></div>
<div id="name"></div>
<div id="scrolled_date"></div>
</div>
</div>
<script type="text/javascript">
<!--//--><![CDATA[// ><!--


        window.onload = function() {






                    var width = 930;


            function timelineHover() {
                           d3.json("http://ckan.itdash.lws.links.com.au/api/action/datastore_search_sql?sql=select+distinct+p.name%2C+start_date%2C+end_date%2C+expected_end_date%2C+total_value%2C+expected_total_value%0AFROM+%28select+name%2C+value+as+start_date+from%222133eaed-150b-4c73-a314-67a0bde04115%22+where+metric+%3D+%27original_completion_date%27++%29+p+full+outer+JOIN%0A++%28select+name%2C+value+as+end_date+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+where+metric+%3D+%27start_date%27+%29+a+on+p.name+%3D+a.name+full+outer+JOIN%0A++%28select+name%2C+value+as+total_value+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+where+metric+%3D+%27total_project_budget%27+%29+v+on+p.name+%3D+v.name+full+outer+JOIN%0A++%28select+DISTINCT+d.name%2C+d.value+as+expected_end_date+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+d+join+%28select+name%2Cmetric%2C+max%28timestamp%29+as+timestamp%0Afrom+%222133eaed-150b-4c73-a314-67a0bde04115%22+GROUP+BY+name%2Cmetric%29+s+on+d.metric%3Ds.metric+and+d.timestamp%3Ds.timestamp%0Awhere+d.metric+%3D+%27current_expected_completion_date%27%29+c+on+p.name+%3D+c.name+full+outer+JOIN%0A++%28select+DISTINCT+d.name%2C+d.value+as+expected_total_value+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+d+join+%28select+name%2Cmetric%2C+max%28timestamp%29+as+timestamp%0Afrom+%222133eaed-150b-4c73-a314-67a0bde04115%22+GROUP+BY+name%2Cmetric%29+s+on+d.metric%3Ds.metric+and+d.timestamp%3Ds.timestamp%0Awhere+d.metric+%3D+%27current_total_expected_budget%27%29+b+on+p.name+%3D+b.name+",
                    function(error, data) {
                        labelTestData = data.result.records.map(function (d) {
                            /* end_date: "2014-08-02T00:00:00"expected_end_date: "2015-08-10"expected_total_value: "70"name: "AAT Project B"start_date: "2015-07-02T00:00:00"total_value: "60.00"*/
                            starting_time = Date.fromString(d.start_date).getTime();
                            ending_time = Date.fromString(d.end_date).getTime();

                            return {label: d.name,
                                times: [{"starting_time": starting_time, "ending_time": ending_time}]}
                        });
                var chart = d3.timeline()
                    .width(width)
                    .stack()
                    .margin({left:170, right:30, top:0, bottom:0})
                    .tickFormat({
                            format: d3.time.format("%B %Y"),
                                tickTime: d3.time.months})
                   ;

                var svg = d3.select("#timeline3").append("svg").attr("width", width)
                    .datum(labelTestData).call(chart);
                    });
            }

            timelineHover();
        }
    
//--><!]]>
</script>',
        'safe_summary' => '',
      ),
    ),
  ),
  'rdf_mapping' => array(
    'rdftype' => array(
      0 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
  ),
  'cid' => 0,
  'last_comment_name' => NULL,
  'last_comment_uid' => 1,
  'comment_count' => 0,
  'name' => 'admin',
  'picture' => 0,
  'data' => 'b:0;',
  'date' => '2014-12-09 01:14:54 +1100',
);
  $nodes[] = array(
  'uid' => 1,
  'title' => 'ICT Project Budgets',
  'log' => '',
  'status' => 1,
  'comment' => 1,
  'promote' => 0,
  'sticky' => 0,
  'vuuid' => '358e5d58-366e-4add-9672-418e6ccafb80',
  'ds_switch' => '',
  'type' => 'page',
  'language' => 'und',
  'created' => 1418048094,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => 'ff1441b5-255b-465e-ba64-21149cc90807',
  'revision_uid' => 1,
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<style>

    #chart svg {
        height: 400px;
width: 600px;
        padding: 22px;
    }
.field-name-body {
height: auto;
background-color: transparent;
width: 100%;
}
.field-name-body:active {
background-color: transparent;
}
select { color: white;}
</style>


<div id="chart">
    <svg></svg>
</div>

<script>


   d3.json("http://ckan.itdash.lws.links.com.au/api/action/datastore_search_sql?sql=select+distinct+p.name%2C+total_value%2C+expected_total_value++FROM+%28select+name%2C+value+as+total_value+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+where+metric+%3D+%27total_project_budget%27+%29+p+full+outer+JOIN+++++%28select+DISTINCT+d.name%2C+d.value+as+expected_total_value+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+d+join+%28select+name%2Cmetric%2C+max%28timestamp%29+as+timestamp+++++from+%222133eaed-150b-4c73-a314-67a0bde04115%22+GROUP+BY+name%2Cmetric%29+s+on+d.metric%3Ds.metric+and+d.timestamp%3Ds.timestamp+++++where+d.metric+%3D+%27current_total_expected_budget%27%29+b+on+p.name+%3D+b.name%3B",
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



            datum = [{\'key\': "Planned Budget", \'values\': []}, {\'key\': "Actual Budget", \'values\': []}];
            for (var i in project_names) {
                datum[0][\'values\'].push({\'x\': i, \'y\': parseInt(project_orig_budget[i])});
                datum[1][\'values\'].push({\'x\': i, \'y\': parseInt(project_current_budget[i])});
            }
            nv.addGraph(function() {
                var chart = nv.models.multiBarChart();

                chart.xAxis
                    .tickFormat(function(d) {
                        return project_names[d];
                    });

                chart.yAxis
                    .tickFormat(d3.format(\'$,.1f\'));

                d3.select(\'#chart svg\')
                    .datum(datum)
                    .transition().duration(500)
                    .call(chart)
                ;

                nv.utils.windowResize(chart.update);

                return chart;
            });

        });


</script>
',
        'summary' => '',
        'format' => 'full_html',
        'safe_value' => '<style>
<!--/*--><![CDATA[/* ><!--*/


    #chart svg {
        height: 400px;
width: 600px;
        padding: 22px;
    }
.field-name-body {
height: auto;
background-color: transparent;
width: 100%;
}
.field-name-body:active {
background-color: transparent;
}
select { color: white;}

/*--><!]]>*/
</style><div id="chart">
    <svg></svg></div>
<script>
<!--//--><![CDATA[// ><!--



   d3.json("http://ckan.itdash.lws.links.com.au/api/action/datastore_search_sql?sql=select+distinct+p.name%2C+total_value%2C+expected_total_value++FROM+%28select+name%2C+value+as+total_value+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+where+metric+%3D+%27total_project_budget%27+%29+p+full+outer+JOIN+++++%28select+DISTINCT+d.name%2C+d.value+as+expected_total_value+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+d+join+%28select+name%2Cmetric%2C+max%28timestamp%29+as+timestamp+++++from+%222133eaed-150b-4c73-a314-67a0bde04115%22+GROUP+BY+name%2Cmetric%29+s+on+d.metric%3Ds.metric+and+d.timestamp%3Ds.timestamp+++++where+d.metric+%3D+%27current_total_expected_budget%27%29+b+on+p.name+%3D+b.name%3B",
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



            datum = [{\'key\': "Planned Budget", \'values\': []}, {\'key\': "Actual Budget", \'values\': []}];
            for (var i in project_names) {
                datum[0][\'values\'].push({\'x\': i, \'y\': parseInt(project_orig_budget[i])});
                datum[1][\'values\'].push({\'x\': i, \'y\': parseInt(project_current_budget[i])});
            }
            nv.addGraph(function() {
                var chart = nv.models.multiBarChart();

                chart.xAxis
                    .tickFormat(function(d) {
                        return project_names[d];
                    });

                chart.yAxis
                    .tickFormat(d3.format(\'$,.1f\'));

                d3.select(\'#chart svg\')
                    .datum(datum)
                    .transition().duration(500)
                    .call(chart)
                ;

                nv.utils.windowResize(chart.update);

                return chart;
            });

        });



//--><!]]>
</script>',
        'safe_summary' => '',
      ),
    ),
  ),
  'rdf_mapping' => array(
    'rdftype' => array(
      0 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
  ),
  'cid' => 0,
  'last_comment_name' => NULL,
  'last_comment_uid' => 1,
  'comment_count' => 0,
  'name' => 'admin',
  'picture' => 0,
  'data' => 'b:0;',
  'date' => '2014-12-09 01:14:54 +1100',
);
  return $nodes;
}
