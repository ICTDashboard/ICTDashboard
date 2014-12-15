<?php
/**
 * @file
 * ict_dashboard_widgets.features.node_export_features.inc
 */

/**
 * Implements hook_node_export_features_default().
 */
function ict_dashboard_widgets_node_export_features_default() {
  $node_export = array(
  'code_string' => 'array(
  (object) array(
      \'vid\' => \'1687\',
      \'uid\' => \'1\',
      \'title\' => \'ICT Project Treemap\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'1\',
      \'promote\' => \'0\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'2bc7d7bc-d1ef-4384-b46f-bb042cff32f0\',
      \'ds_switch\' => \'\',
      \'nid\' => \'1687\',
      \'type\' => \'page\',
      \'language\' => \'und\',
      \'created\' => \'1417468626\',
      \'changed\' => \'1417564494\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'5436dc7d-c224-44a2-9db4-02091f155065\',
      \'revision_timestamp\' => \'1417564494\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<style type=\\"text/css\\">\\r\\n\\r\\n    .chart {\\r\\n        display: block;\\r\\n        margin: auto;\\r\\n    }\\r\\n\\r\\n    text {\\r\\n        font-size: 11px;\\r\\n    }\\r\\n\\r\\n    rect {\\r\\n        fill: none;\\r\\n    }\\r\\n\\r\\n</style>\\r\\n</head>\\r\\n<body>\\r\\n<div id=\\"body\\">\\r\\n    <div id=\\"footer\\">\\r\\n        <div class=\\"hint\\">click or option-click to descend or ascend</div>\\r\\n        <div><select>\\r\\n                <option value=\\"size\\">Value of Projects</option>\\r\\n                <option value=\\"count\\">Number of Projects</option>\\r\\n            </select></div>\\r\\n    </div>\\r\\n</div>\\r\\n<script type=\\"text/javascript\\">\\r\\n\\r\\n    var w = 930 - 80,\\r\\n        h = 800 - 180,\\r\\n        x = d3.scale.linear().range([0, w]),\\r\\n        y = d3.scale.linear().range([0, h]),\\r\\n        color = d3.scale.category20c(),\\r\\n        root,\\r\\n        node;\\r\\n\\r\\n    var treemap = d3.layout.treemap()\\r\\n        .round(false)\\r\\n        .size([w, h])\\r\\n        .sticky(true)\\r\\n        .value(function(d) { return d.size; });\\r\\n\\r\\n    var svg = d3.select(\\"#body\\").append(\\"div\\")\\r\\n        .attr(\\"class\\", \\"chart\\")\\r\\n        .style(\\"width\\", w + \\"px\\")\\r\\n        .style(\\"height\\", h + \\"px\\")\\r\\n        .append(\\"svg:svg\\")\\r\\n        .attr(\\"width\\", w)\\r\\n        .attr(\\"height\\", h)\\r\\n        .append(\\"svg:g\\")\\r\\n        .attr(\\"transform\\", \\"translate(.5,.5)\\");\\r\\n\\r\\n    d3.json(\\"http://ckan.itdash.lws.links.com.au/api/action/datastore_search_sql?sql=select+distinct+p.name%2C+government_business_unit%2C+government_programme%2C+government_entity%2C+expected_total_value%0AFROM+%28select+name%2C+value+as+government_business_unit+from%222133eaed-150b-4c73-a314-67a0bde04115%22+where+metric+%3D+%27government_business_unit%27++%29+b+full+outer+JOIN%0A++%28select+name%2C+value+as+government_programme+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+where+metric+%3D+%27government_programme%27+%29+p+on+p.name+%3D+b.name+full+outer+JOIN%0A%28select+name%2C+value+as+government_entity+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+where+metric+%3D+%27government_entity%27+%29+e+on+p.name+%3D+e.name++join+%0A+++%28select+DISTINCT+d.name%2C+d.value+as+expected_total_value+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+d+join+%28select+name%2Cmetric%2C+max%28timestamp%29+as+timestamp+%0Afrom+%222133eaed-150b-4c73-a314-67a0bde04115%22+GROUP+BY+name%2Cmetric%29+s+on+d.metric%3Ds.metric+and+d.timestamp%3Ds.timestamp+%0Awhere+d.metric+%3D+%27current_total_expected_budget%27%29+t+on+p.name+%3D+t.name++\\",\\r\\n        function(error, data) {\\r\\n            ents = {};\\r\\n            progs = {};\\r\\n            gbus = {};\\r\\n            datum = {\\r\\n                \\"name\\": \\"flare\\",\\r\\n                \\"children\\": []\\r\\n            };\\r\\n            for (var i in data.result.records) {\\r\\n                d = data.result.records[i];\\r\\n                if (typeof ents[d.government_entity] == \'undefined\') {\\r\\n                    ents[d.government_entity] = [];\\r\\n                }\\r\\n                ents[d.government_entity].push(d.government_programme);\\r\\n                if (typeof progs[d.government_programme] == \'undefined\') {\\r\\n                    progs[d.government_programme] = [];\\r\\n                }\\r\\n                progs[d.government_programme].push(d.government_business_unit);\\r\\n                if (typeof gbus[d.government_business_unit]  == \'undefined\') {\\r\\n                    gbus[d.government_business_unit] = [];\\r\\n                }\\r\\n                gbus[d.government_business_unit].push({name: d.name, size: d.expected_total_value});\\r\\n            }\\r\\n            for (var ent in ents) {\\r\\n                entobj = {\\r\\n                    name: ent,\\r\\n                    children: []\\r\\n                };\\r\\n                prog = ents[ent];\\r\\n\\r\\n                for (var j in progs[prog]) {\\r\\n                    gbu = progs[prog][j];\\r\\n                    progobj= {\\r\\n                        name: prog,\\r\\n                        children: gbus[gbu]\\r\\n                    };\\r\\n                    entobj.children.push(progobj);\\r\\n                }\\r\\n                datum.children.push(entobj);\\r\\n            }\\r\\n        node = root = datum;\\r\\n\\r\\n        var nodes = treemap.nodes(root)\\r\\n            .filter(function(d) { return !d.children; });\\r\\n\\r\\n        var cell = svg.selectAll(\\"g\\")\\r\\n            .data(nodes)\\r\\n            .enter().append(\\"svg:g\\")\\r\\n            .attr(\\"class\\", \\"cell\\")\\r\\n            .attr(\\"transform\\", function(d) { return \\"translate(\\" + d.x + \\",\\" + d.y + \\")\\"; })\\r\\n            .on(\\"click\\", function(d) { return zoom(node == d.parent ? root : d.parent); });\\r\\n\\r\\n        cell.append(\\"svg:rect\\")\\r\\n            .attr(\\"width\\", function(d) { return d.dx - 1; })\\r\\n            .attr(\\"height\\", function(d) { return d.dy - 1; })\\r\\n            .style(\\"fill\\", function(d) { return color(d.parent.name); });\\r\\n\\r\\n        cell.append(\\"svg:text\\")\\r\\n            .attr(\\"x\\", function(d) { return d.dx / 2; })\\r\\n            .attr(\\"y\\", function(d) { return d.dy / 2; })\\r\\n            .attr(\\"dy\\", \\".35em\\")\\r\\n            .attr(\\"text-anchor\\", \\"middle\\")\\r\\n            .text(function(d) { return d.name; })\\r\\n            .style(\\"opacity\\", function(d) { d.w = this.getComputedTextLength(); return d.dx > d.w ? 1 : 0; });\\r\\n\\r\\n        d3.select(window).on(\\"click\\", function() { zoom(root); });\\r\\n\\r\\n        d3.select(\\"select\\").on(\\"change\\", function() {\\r\\n            treemap.value(this.value == \\"size\\" ? size : count).nodes(root);\\r\\n            zoom(node);\\r\\n        });\\r\\n    });\\r\\n\\r\\n    function size(d) {\\r\\n        return d.size;\\r\\n    }\\r\\n\\r\\n    function count(d) {\\r\\n        return 1;\\r\\n    }\\r\\n\\r\\n    function zoom(d) {\\r\\n        var kx = w / d.dx, ky = h / d.dy;\\r\\n        x.domain([d.x, d.x + d.dx]);\\r\\n        y.domain([d.y, d.y + d.dy]);\\r\\n\\r\\n        var t = svg.selectAll(\\"g.cell\\").transition()\\r\\n            .duration(d3.event.altKey ? 7500 : 750)\\r\\n            .attr(\\"transform\\", function(d) { return \\"translate(\\" + x(d.x) + \\",\\" + y(d.y) + \\")\\"; });\\r\\n\\r\\n        t.select(\\"rect\\")\\r\\n            .attr(\\"width\\", function(d) { return kx * d.dx - 1; })\\r\\n            .attr(\\"height\\", function(d) { return ky * d.dy - 1; })\\r\\n\\r\\n        t.select(\\"text\\")\\r\\n            .attr(\\"x\\", function(d) { return kx * d.dx / 2; })\\r\\n            .attr(\\"y\\", function(d) { return ky * d.dy / 2; })\\r\\n            .style(\\"opacity\\", function(d) { return kx * d.dx > d.w ? 1 : 0; });\\r\\n\\r\\n        node = d;\\r\\n        d3.event.stopPropagation();\\r\\n    }\\r\\n\\r\\n</script>\\r\\n",
            \'summary\' => \'\',
            \'format\' => \'full_html\',
            \'safe_value\' => "<style type=\\"text/css\\">\\n<!--/*--><![CDATA[/* ><!--*/\\n\\n\\n    .chart {\\n        display: block;\\n        margin: auto;\\n    }\\n\\n    text {\\n        font-size: 11px;\\n    }\\n\\n    rect {\\n        fill: none;\\n    }\\n\\n\\n/*--><!]]>*/\\n</style><p><br /></p>\\n<div id=\\"body\\">\\n<div id=\\"footer\\">\\n<div class=\\"hint\\">click or option-click to descend or ascend</div>\\n<div>\\n<select><option value=\\"size\\">Value of Projects</option><br /><option value=\\"count\\">Number of Projects</option><br /></select></div>\\n</div>\\n</div>\\n<script type=\\"text/javascript\\">\\n<!--//--><![CDATA[// ><!--\\n\\n\\n    var w = 930 - 80,\\n        h = 800 - 180,\\n        x = d3.scale.linear().range([0, w]),\\n        y = d3.scale.linear().range([0, h]),\\n        color = d3.scale.category20c(),\\n        root,\\n        node;\\n\\n    var treemap = d3.layout.treemap()\\n        .round(false)\\n        .size([w, h])\\n        .sticky(true)\\n        .value(function(d) { return d.size; });\\n\\n    var svg = d3.select(\\"#body\\").append(\\"div\\")\\n        .attr(\\"class\\", \\"chart\\")\\n        .style(\\"width\\", w + \\"px\\")\\n        .style(\\"height\\", h + \\"px\\")\\n        .append(\\"svg:svg\\")\\n        .attr(\\"width\\", w)\\n        .attr(\\"height\\", h)\\n        .append(\\"svg:g\\")\\n        .attr(\\"transform\\", \\"translate(.5,.5)\\");\\n\\n    d3.json(\\"http://ckan.itdash.lws.links.com.au/api/action/datastore_search_sql?sql=select+distinct+p.name%2C+government_business_unit%2C+government_programme%2C+government_entity%2C+expected_total_value%0AFROM+%28select+name%2C+value+as+government_business_unit+from%222133eaed-150b-4c73-a314-67a0bde04115%22+where+metric+%3D+%27government_business_unit%27++%29+b+full+outer+JOIN%0A++%28select+name%2C+value+as+government_programme+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+where+metric+%3D+%27government_programme%27+%29+p+on+p.name+%3D+b.name+full+outer+JOIN%0A%28select+name%2C+value+as+government_entity+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+where+metric+%3D+%27government_entity%27+%29+e+on+p.name+%3D+e.name++join+%0A+++%28select+DISTINCT+d.name%2C+d.value+as+expected_total_value+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+d+join+%28select+name%2Cmetric%2C+max%28timestamp%29+as+timestamp+%0Afrom+%222133eaed-150b-4c73-a314-67a0bde04115%22+GROUP+BY+name%2Cmetric%29+s+on+d.metric%3Ds.metric+and+d.timestamp%3Ds.timestamp+%0Awhere+d.metric+%3D+%27current_total_expected_budget%27%29+t+on+p.name+%3D+t.name++\\",\\n        function(error, data) {\\n            ents = {};\\n            progs = {};\\n            gbus = {};\\n            datum = {\\n                \\"name\\": \\"flare\\",\\n                \\"children\\": []\\n            };\\n            for (var i in data.result.records) {\\n                d = data.result.records[i];\\n                if (typeof ents[d.government_entity] == \'undefined\') {\\n                    ents[d.government_entity] = [];\\n                }\\n                ents[d.government_entity].push(d.government_programme);\\n                if (typeof progs[d.government_programme] == \'undefined\') {\\n                    progs[d.government_programme] = [];\\n                }\\n                progs[d.government_programme].push(d.government_business_unit);\\n                if (typeof gbus[d.government_business_unit]  == \'undefined\') {\\n                    gbus[d.government_business_unit] = [];\\n                }\\n                gbus[d.government_business_unit].push({name: d.name, size: d.expected_total_value});\\n            }\\n            for (var ent in ents) {\\n                entobj = {\\n                    name: ent,\\n                    children: []\\n                };\\n                prog = ents[ent];\\n\\n                for (var j in progs[prog]) {\\n                    gbu = progs[prog][j];\\n                    progobj= {\\n                        name: prog,\\n                        children: gbus[gbu]\\n                    };\\n                    entobj.children.push(progobj);\\n                }\\n                datum.children.push(entobj);\\n            }\\n        node = root = datum;\\n\\n        var nodes = treemap.nodes(root)\\n            .filter(function(d) { return !d.children; });\\n\\n        var cell = svg.selectAll(\\"g\\")\\n            .data(nodes)\\n            .enter().append(\\"svg:g\\")\\n            .attr(\\"class\\", \\"cell\\")\\n            .attr(\\"transform\\", function(d) { return \\"translate(\\" + d.x + \\",\\" + d.y + \\")\\"; })\\n            .on(\\"click\\", function(d) { return zoom(node == d.parent ? root : d.parent); });\\n\\n        cell.append(\\"svg:rect\\")\\n            .attr(\\"width\\", function(d) { return d.dx - 1; })\\n            .attr(\\"height\\", function(d) { return d.dy - 1; })\\n            .style(\\"fill\\", function(d) { return color(d.parent.name); });\\n\\n        cell.append(\\"svg:text\\")\\n            .attr(\\"x\\", function(d) { return d.dx / 2; })\\n            .attr(\\"y\\", function(d) { return d.dy / 2; })\\n            .attr(\\"dy\\", \\".35em\\")\\n            .attr(\\"text-anchor\\", \\"middle\\")\\n            .text(function(d) { return d.name; })\\n            .style(\\"opacity\\", function(d) { d.w = this.getComputedTextLength(); return d.dx > d.w ? 1 : 0; });\\n\\n        d3.select(window).on(\\"click\\", function() { zoom(root); });\\n\\n        d3.select(\\"select\\").on(\\"change\\", function() {\\n            treemap.value(this.value == \\"size\\" ? size : count).nodes(root);\\n            zoom(node);\\n        });\\n    });\\n\\n    function size(d) {\\n        return d.size;\\n    }\\n\\n    function count(d) {\\n        return 1;\\n    }\\n\\n    function zoom(d) {\\n        var kx = w / d.dx, ky = h / d.dy;\\n        x.domain([d.x, d.x + d.dx]);\\n        y.domain([d.y, d.y + d.dy]);\\n\\n        var t = svg.selectAll(\\"g.cell\\").transition()\\n            .duration(d3.event.altKey ? 7500 : 750)\\n            .attr(\\"transform\\", function(d) { return \\"translate(\\" + x(d.x) + \\",\\" + y(d.y) + \\")\\"; });\\n\\n        t.select(\\"rect\\")\\n            .attr(\\"width\\", function(d) { return kx * d.dx - 1; })\\n            .attr(\\"height\\", function(d) { return ky * d.dy - 1; })\\n\\n        t.select(\\"text\\")\\n            .attr(\\"x\\", function(d) { return kx * d.dx / 2; })\\n            .attr(\\"y\\", function(d) { return ky * d.dy / 2; })\\n            .style(\\"opacity\\", function(d) { return kx * d.dx > d.w ? 1 : 0; });\\n\\n        node = d;\\n        d3.event.stopPropagation();\\n    }\\n\\n\\n//--><!]]>\\n</script>",
            \'safe_summary\' => \'\',
          ),
        ),
      ),
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
          \'foaf:Document\',
        ),
        \'title\' => array(
          \'predicates\' => array(
            \'dc:title\',
          ),
        ),
        \'created\' => array(
          \'predicates\' => array(
            \'dc:date\',
            \'dc:created\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'changed\' => array(
          \'predicates\' => array(
            \'dc:modified\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'body\' => array(
          \'predicates\' => array(
            \'content:encoded\',
          ),
        ),
        \'uid\' => array(
          \'predicates\' => array(
            \'sioc:has_creator\',
          ),
          \'type\' => \'rel\',
        ),
        \'name\' => array(
          \'predicates\' => array(
            \'foaf:name\',
          ),
        ),
        \'comment_count\' => array(
          \'predicates\' => array(
            \'sioc:num_replies\',
          ),
          \'datatype\' => \'xsd:integer\',
        ),
        \'last_activity\' => array(
          \'predicates\' => array(
            \'sioc:last_activity_date\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
      ),
      \'cid\' => \'0\',
      \'last_comment_timestamp\' => \'1417468626\',
      \'last_comment_name\' => NULL,
      \'last_comment_uid\' => \'1\',
      \'comment_count\' => \'0\',
      \'name\' => \'admin\',
      \'picture\' => \'0\',
      \'data\' => \'b:0;\',
      \'path\' => array(
        \'pid\' => \'48\',
        \'source\' => \'node/1687\',
        \'alias\' => \'content/ict-project-treemap\',
        \'language\' => \'und\',
      ),
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'1688\',
      \'uid\' => \'1\',
      \'title\' => \'ICT Project Timelines\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'1\',
      \'promote\' => \'0\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'e9808e16-4fe8-43be-8a0d-b716c0d3bd61\',
      \'ds_switch\' => \'\',
      \'nid\' => \'1688\',
      \'type\' => \'page\',
      \'language\' => \'und\',
      \'created\' => \'1417468626\',
      \'changed\' => \'1417564004\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'8754ca37-1410-4671-bb58-ce670b640f5d\',
      \'revision_timestamp\' => \'1417564004\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "  <style type=\\"text/css\\">\\r\\n        .axis path,\\r\\n        .axis line {\\r\\n            fill: none;\\r\\n            stroke: black;\\r\\n            shape-rendering: crispEdges;\\r\\n        }\\r\\n\\r\\n        .axis text {\\r\\n            font-family: sans-serif;\\r\\n            font-size: 10px;\\r\\n        }\\r\\n\\r\\n        .timeline-label {\\r\\n            font-family: sans-serif;\\r\\n            font-size: 12px;\\r\\n        }\\r\\n\\r\\n        #timeline2 .axis {\\r\\n            transform: translate(0px,30px);\\r\\n            -ms-transform: translate(0px,30px); /* IE 9 */\\r\\n            -webkit-transform: translate(0px,30px); /* Safari and Chrome */\\r\\n            -o-transform: translate(0px,30px); /* Opera */\\r\\n            -moz-transform: translate(0px,30px); /* Firefox */\\r\\n        }\\r\\n\\r\\n        .coloredDiv {\\r\\n            height:20px; width:20px; float:left;\\r\\n        }\\r\\n    </style>\\r\\n<div>\\r\\n    <div id=\\"timeline3\\"></div>\\r\\n    <div id=\\"hoverRes\\">\\r\\n        <div class=\\"coloredDiv\\"></div>\\r\\n        <div id=\\"name\\"></div>\\r\\n        <div id=\\"scrolled_date\\"></div>\\r\\n    </div>\\r\\n</div>\\r\\n    <script type=\\"text/javascript\\">\\r\\n\\r\\n        window.onload = function() {\\r\\n\\r\\n\\r\\n\\r\\n\\r\\n\\r\\n\\r\\n                    var width = 930;\\r\\n\\r\\n\\r\\n            function timelineHover() {\\r\\n                           d3.json(\\"http://ckan.itdash.lws.links.com.au/api/action/datastore_search_sql?sql=select+distinct+p.name%2C+start_date%2C+end_date%2C+expected_end_date%2C+total_value%2C+expected_total_value%0AFROM+%28select+name%2C+value+as+start_date+from%222133eaed-150b-4c73-a314-67a0bde04115%22+where+metric+%3D+%27original_completion_date%27++%29+p+full+outer+JOIN%0A++%28select+name%2C+value+as+end_date+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+where+metric+%3D+%27start_date%27+%29+a+on+p.name+%3D+a.name+full+outer+JOIN%0A++%28select+name%2C+value+as+total_value+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+where+metric+%3D+%27total_project_budget%27+%29+v+on+p.name+%3D+v.name+full+outer+JOIN%0A++%28select+DISTINCT+d.name%2C+d.value+as+expected_end_date+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+d+join+%28select+name%2Cmetric%2C+max%28timestamp%29+as+timestamp%0Afrom+%222133eaed-150b-4c73-a314-67a0bde04115%22+GROUP+BY+name%2Cmetric%29+s+on+d.metric%3Ds.metric+and+d.timestamp%3Ds.timestamp%0Awhere+d.metric+%3D+%27current_expected_completion_date%27%29+c+on+p.name+%3D+c.name+full+outer+JOIN%0A++%28select+DISTINCT+d.name%2C+d.value+as+expected_total_value+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+d+join+%28select+name%2Cmetric%2C+max%28timestamp%29+as+timestamp%0Afrom+%222133eaed-150b-4c73-a314-67a0bde04115%22+GROUP+BY+name%2Cmetric%29+s+on+d.metric%3Ds.metric+and+d.timestamp%3Ds.timestamp%0Awhere+d.metric+%3D+%27current_total_expected_budget%27%29+b+on+p.name+%3D+b.name+\\",\\r\\n                    function(error, data) {\\r\\n                        labelTestData = data.result.records.map(function (d) {\\r\\n                            /* end_date: \\"2014-08-02T00:00:00\\"expected_end_date: \\"2015-08-10\\"expected_total_value: \\"70\\"name: \\"AAT Project B\\"start_date: \\"2015-07-02T00:00:00\\"total_value: \\"60.00\\"*/\\r\\n                            starting_time = Date.fromString(d.start_date).getTime();\\r\\n                            ending_time = Date.fromString(d.end_date).getTime();\\r\\n\\r\\n                            return {label: d.name,\\r\\n                                times: [{\\"starting_time\\": starting_time, \\"ending_time\\": ending_time}]}\\r\\n                        });\\r\\n                var chart = d3.timeline()\\r\\n                    .width(width)\\r\\n                    .stack()\\r\\n                    .margin({left:170, right:30, top:0, bottom:0})\\r\\n                    .tickFormat({\\r\\n                            format: d3.time.format(\\"%B %Y\\"),\\r\\n                                tickTime: d3.time.months})\\r\\n                   ;\\r\\n\\r\\n                var svg = d3.select(\\"#timeline3\\").append(\\"svg\\").attr(\\"width\\", width)\\r\\n                    .datum(labelTestData).call(chart);\\r\\n                    });\\r\\n            }\\r\\n\\r\\n            timelineHover();\\r\\n        }\\r\\n    </script>",
            \'summary\' => \'\',
            \'format\' => \'full_html\',
            \'safe_value\' => "<style type=\\"text/css\\">\\n<!--/*--><![CDATA[/* ><!--*/\\n\\n        .axis path,\\n        .axis line {\\n            fill: none;\\n            stroke: black;\\n            shape-rendering: crispEdges;\\n        }\\n\\n        .axis text {\\n            font-family: sans-serif;\\n            font-size: 10px;\\n        }\\n\\n        .timeline-label {\\n            font-family: sans-serif;\\n            font-size: 12px;\\n        }\\n\\n        #timeline2 .axis {\\n            transform: translate(0px,30px);\\n            -ms-transform: translate(0px,30px); /* IE 9 */\\n            -webkit-transform: translate(0px,30px); /* Safari and Chrome */\\n            -o-transform: translate(0px,30px); /* Opera */\\n            -moz-transform: translate(0px,30px); /* Firefox */\\n        }\\n\\n        .coloredDiv {\\n            height:20px; width:20px; float:left;\\n        }\\n    \\n/*--><!]]>*/\\n</style><div>\\n<div id=\\"timeline3\\"></div>\\n<div id=\\"hoverRes\\">\\n<div class=\\"coloredDiv\\"></div>\\n<div id=\\"name\\"></div>\\n<div id=\\"scrolled_date\\"></div>\\n</div>\\n</div>\\n<script type=\\"text/javascript\\">\\n<!--//--><![CDATA[// ><!--\\n\\n\\n        window.onload = function() {\\n\\n\\n\\n\\n\\n\\n                    var width = 930;\\n\\n\\n            function timelineHover() {\\n                           d3.json(\\"http://ckan.itdash.lws.links.com.au/api/action/datastore_search_sql?sql=select+distinct+p.name%2C+start_date%2C+end_date%2C+expected_end_date%2C+total_value%2C+expected_total_value%0AFROM+%28select+name%2C+value+as+start_date+from%222133eaed-150b-4c73-a314-67a0bde04115%22+where+metric+%3D+%27original_completion_date%27++%29+p+full+outer+JOIN%0A++%28select+name%2C+value+as+end_date+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+where+metric+%3D+%27start_date%27+%29+a+on+p.name+%3D+a.name+full+outer+JOIN%0A++%28select+name%2C+value+as+total_value+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+where+metric+%3D+%27total_project_budget%27+%29+v+on+p.name+%3D+v.name+full+outer+JOIN%0A++%28select+DISTINCT+d.name%2C+d.value+as+expected_end_date+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+d+join+%28select+name%2Cmetric%2C+max%28timestamp%29+as+timestamp%0Afrom+%222133eaed-150b-4c73-a314-67a0bde04115%22+GROUP+BY+name%2Cmetric%29+s+on+d.metric%3Ds.metric+and+d.timestamp%3Ds.timestamp%0Awhere+d.metric+%3D+%27current_expected_completion_date%27%29+c+on+p.name+%3D+c.name+full+outer+JOIN%0A++%28select+DISTINCT+d.name%2C+d.value+as+expected_total_value+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+d+join+%28select+name%2Cmetric%2C+max%28timestamp%29+as+timestamp%0Afrom+%222133eaed-150b-4c73-a314-67a0bde04115%22+GROUP+BY+name%2Cmetric%29+s+on+d.metric%3Ds.metric+and+d.timestamp%3Ds.timestamp%0Awhere+d.metric+%3D+%27current_total_expected_budget%27%29+b+on+p.name+%3D+b.name+\\",\\n                    function(error, data) {\\n                        labelTestData = data.result.records.map(function (d) {\\n                            /* end_date: \\"2014-08-02T00:00:00\\"expected_end_date: \\"2015-08-10\\"expected_total_value: \\"70\\"name: \\"AAT Project B\\"start_date: \\"2015-07-02T00:00:00\\"total_value: \\"60.00\\"*/\\n                            starting_time = Date.fromString(d.start_date).getTime();\\n                            ending_time = Date.fromString(d.end_date).getTime();\\n\\n                            return {label: d.name,\\n                                times: [{\\"starting_time\\": starting_time, \\"ending_time\\": ending_time}]}\\n                        });\\n                var chart = d3.timeline()\\n                    .width(width)\\n                    .stack()\\n                    .margin({left:170, right:30, top:0, bottom:0})\\n                    .tickFormat({\\n                            format: d3.time.format(\\"%B %Y\\"),\\n                                tickTime: d3.time.months})\\n                   ;\\n\\n                var svg = d3.select(\\"#timeline3\\").append(\\"svg\\").attr(\\"width\\", width)\\n                    .datum(labelTestData).call(chart);\\n                    });\\n            }\\n\\n            timelineHover();\\n        }\\n    \\n//--><!]]>\\n</script>",
            \'safe_summary\' => \'\',
          ),
        ),
      ),
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
          \'foaf:Document\',
        ),
        \'title\' => array(
          \'predicates\' => array(
            \'dc:title\',
          ),
        ),
        \'created\' => array(
          \'predicates\' => array(
            \'dc:date\',
            \'dc:created\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'changed\' => array(
          \'predicates\' => array(
            \'dc:modified\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'body\' => array(
          \'predicates\' => array(
            \'content:encoded\',
          ),
        ),
        \'uid\' => array(
          \'predicates\' => array(
            \'sioc:has_creator\',
          ),
          \'type\' => \'rel\',
        ),
        \'name\' => array(
          \'predicates\' => array(
            \'foaf:name\',
          ),
        ),
        \'comment_count\' => array(
          \'predicates\' => array(
            \'sioc:num_replies\',
          ),
          \'datatype\' => \'xsd:integer\',
        ),
        \'last_activity\' => array(
          \'predicates\' => array(
            \'sioc:last_activity_date\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
      ),
      \'cid\' => \'0\',
      \'last_comment_timestamp\' => \'1417468626\',
      \'last_comment_name\' => NULL,
      \'last_comment_uid\' => \'1\',
      \'comment_count\' => \'0\',
      \'name\' => \'admin\',
      \'picture\' => \'0\',
      \'data\' => \'b:0;\',
      \'path\' => array(
        \'pid\' => \'49\',
        \'source\' => \'node/1688\',
        \'alias\' => \'content/ict-project-timelines\',
        \'language\' => \'und\',
      ),
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'1689\',
      \'uid\' => \'1\',
      \'title\' => \'ICT Project Budgets\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'1\',
      \'promote\' => \'0\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'358e5d58-366e-4add-9672-418e6ccafb80\',
      \'ds_switch\' => \'\',
      \'nid\' => \'1689\',
      \'type\' => \'page\',
      \'language\' => \'und\',
      \'created\' => \'1417468626\',
      \'changed\' => \'1417567030\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'ff1441b5-255b-465e-ba64-21149cc90807\',
      \'revision_timestamp\' => \'1417567030\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<style>\\r\\n\\r\\n    #chart svg {\\r\\n        height: 400px;\\r\\nwidth: 600px;\\r\\n        padding: 22px;\\r\\n    }\\r\\n.field-name-body {\\r\\nheight: auto;\\r\\nbackground-color: transparent;\\r\\nwidth: 100%;\\r\\n}\\r\\n.field-name-body:active {\\r\\nbackground-color: transparent;\\r\\n}\\r\\nselect { color: white;}\\r\\n</style>\\r\\n\\r\\n\\r\\n<div id=\\"chart\\">\\r\\n    <svg></svg>\\r\\n</div>\\r\\n\\r\\n<script>\\r\\n\\r\\n\\r\\n   d3.json(\\"http://ckan.itdash.lws.links.com.au/api/action/datastore_search_sql?sql=select+distinct+p.name%2C+total_value%2C+expected_total_value++FROM+%28select+name%2C+value+as+total_value+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+where+metric+%3D+%27total_project_budget%27+%29+p+full+outer+JOIN+++++%28select+DISTINCT+d.name%2C+d.value+as+expected_total_value+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+d+join+%28select+name%2Cmetric%2C+max%28timestamp%29+as+timestamp+++++from+%222133eaed-150b-4c73-a314-67a0bde04115%22+GROUP+BY+name%2Cmetric%29+s+on+d.metric%3Ds.metric+and+d.timestamp%3Ds.timestamp+++++where+d.metric+%3D+%27current_total_expected_budget%27%29+b+on+p.name+%3D+b.name%3B\\",\\r\\n        function(error, data) {\\r\\n            project_names = [];\\r\\n            project_orig_budget = [];\\r\\n            project_current_budget = [];\\r\\n\\r\\n            for (var i in data.result.records) {\\r\\n                d =  data.result.records[i]\\r\\n                project_names[i] = d.name;\\r\\n                project_orig_budget[i] = d.total_value;\\r\\n                project_current_budget[i] = d.expected_total_value;\\r\\n            }\\r\\n\\r\\n\\r\\n\\r\\n            datum = [{\'key\': \\"Planned Budget\\", \'values\': []}, {\'key\': \\"Actual Budget\\", \'values\': []}];\\r\\n            for (var i in project_names) {\\r\\n                datum[0][\'values\'].push({\'x\': i, \'y\': parseInt(project_orig_budget[i])});\\r\\n                datum[1][\'values\'].push({\'x\': i, \'y\': parseInt(project_current_budget[i])});\\r\\n            }\\r\\n            nv.addGraph(function() {\\r\\n                var chart = nv.models.multiBarChart();\\r\\n\\r\\n                chart.xAxis\\r\\n                    .tickFormat(function(d) {\\r\\n                        return project_names[d];\\r\\n                    });\\r\\n\\r\\n                chart.yAxis\\r\\n                    .tickFormat(d3.format(\'$,.1f\'));\\r\\n\\r\\n                d3.select(\'#chart svg\')\\r\\n                    .datum(datum)\\r\\n                    .transition().duration(500)\\r\\n                    .call(chart)\\r\\n                ;\\r\\n\\r\\n                nv.utils.windowResize(chart.update);\\r\\n\\r\\n                return chart;\\r\\n            });\\r\\n\\r\\n        });\\r\\n\\r\\n\\r\\n</script>\\r\\n",
            \'summary\' => \'\',
            \'format\' => \'full_html\',
            \'safe_value\' => "<style>\\n<!--/*--><![CDATA[/* ><!--*/\\n\\n\\n    #chart svg {\\n        height: 400px;\\nwidth: 600px;\\n        padding: 22px;\\n    }\\n.field-name-body {\\nheight: auto;\\nbackground-color: transparent;\\nwidth: 100%;\\n}\\n.field-name-body:active {\\nbackground-color: transparent;\\n}\\nselect { color: white;}\\n\\n/*--><!]]>*/\\n</style><div id=\\"chart\\">\\n    <svg></svg></div>\\n<script>\\n<!--//--><![CDATA[// ><!--\\n\\n\\n\\n   d3.json(\\"http://ckan.itdash.lws.links.com.au/api/action/datastore_search_sql?sql=select+distinct+p.name%2C+total_value%2C+expected_total_value++FROM+%28select+name%2C+value+as+total_value+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+where+metric+%3D+%27total_project_budget%27+%29+p+full+outer+JOIN+++++%28select+DISTINCT+d.name%2C+d.value+as+expected_total_value+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+d+join+%28select+name%2Cmetric%2C+max%28timestamp%29+as+timestamp+++++from+%222133eaed-150b-4c73-a314-67a0bde04115%22+GROUP+BY+name%2Cmetric%29+s+on+d.metric%3Ds.metric+and+d.timestamp%3Ds.timestamp+++++where+d.metric+%3D+%27current_total_expected_budget%27%29+b+on+p.name+%3D+b.name%3B\\",\\n        function(error, data) {\\n            project_names = [];\\n            project_orig_budget = [];\\n            project_current_budget = [];\\n\\n            for (var i in data.result.records) {\\n                d =  data.result.records[i]\\n                project_names[i] = d.name;\\n                project_orig_budget[i] = d.total_value;\\n                project_current_budget[i] = d.expected_total_value;\\n            }\\n\\n\\n\\n            datum = [{\'key\': \\"Planned Budget\\", \'values\': []}, {\'key\': \\"Actual Budget\\", \'values\': []}];\\n            for (var i in project_names) {\\n                datum[0][\'values\'].push({\'x\': i, \'y\': parseInt(project_orig_budget[i])});\\n                datum[1][\'values\'].push({\'x\': i, \'y\': parseInt(project_current_budget[i])});\\n            }\\n            nv.addGraph(function() {\\n                var chart = nv.models.multiBarChart();\\n\\n                chart.xAxis\\n                    .tickFormat(function(d) {\\n                        return project_names[d];\\n                    });\\n\\n                chart.yAxis\\n                    .tickFormat(d3.format(\'$,.1f\'));\\n\\n                d3.select(\'#chart svg\')\\n                    .datum(datum)\\n                    .transition().duration(500)\\n                    .call(chart)\\n                ;\\n\\n                nv.utils.windowResize(chart.update);\\n\\n                return chart;\\n            });\\n\\n        });\\n\\n\\n\\n//--><!]]>\\n</script>",
            \'safe_summary\' => \'\',
          ),
        ),
      ),
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
          \'foaf:Document\',
        ),
        \'title\' => array(
          \'predicates\' => array(
            \'dc:title\',
          ),
        ),
        \'created\' => array(
          \'predicates\' => array(
            \'dc:date\',
            \'dc:created\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'changed\' => array(
          \'predicates\' => array(
            \'dc:modified\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'body\' => array(
          \'predicates\' => array(
            \'content:encoded\',
          ),
        ),
        \'uid\' => array(
          \'predicates\' => array(
            \'sioc:has_creator\',
          ),
          \'type\' => \'rel\',
        ),
        \'name\' => array(
          \'predicates\' => array(
            \'foaf:name\',
          ),
        ),
        \'comment_count\' => array(
          \'predicates\' => array(
            \'sioc:num_replies\',
          ),
          \'datatype\' => \'xsd:integer\',
        ),
        \'last_activity\' => array(
          \'predicates\' => array(
            \'sioc:last_activity_date\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
      ),
      \'cid\' => \'0\',
      \'last_comment_timestamp\' => \'1417468626\',
      \'last_comment_name\' => NULL,
      \'last_comment_uid\' => \'1\',
      \'comment_count\' => \'0\',
      \'name\' => \'admin\',
      \'picture\' => \'0\',
      \'data\' => \'b:0;\',
      \'path\' => array(
        \'pid\' => \'50\',
        \'source\' => \'node/1689\',
        \'alias\' => \'content/ict-project-budgets\',
        \'language\' => \'und\',
      ),
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
    ),
)',
);
  return $node_export;
}
