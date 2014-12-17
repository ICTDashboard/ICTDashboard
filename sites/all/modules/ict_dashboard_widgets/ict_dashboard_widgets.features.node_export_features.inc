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
      \'vid\' => \'1673\',
      \'uid\' => \'1\',
      \'title\' => \'ICT Project Treemap\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'1\',
      \'promote\' => \'0\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'2bc7d7bc-d1ef-4384-b46f-bb042cff32f0\',
      \'ds_switch\' => \'\',
      \'nid\' => \'1673\',
      \'type\' => \'page\',
      \'language\' => \'und\',
      \'created\' => \'1418733726\',
      \'changed\' => \'1418800115\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'5436dc7d-c224-44a2-9db4-02091f155065\',
      \'revision_timestamp\' => \'1418800115\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<style type=\\"text/css\\">\\r\\n\\r\\n    .chart {\\r\\n        display: block;\\r\\n        margin: auto;\\r\\n        margin-top: 40px;\\r\\n    }\\r\\n#treemap {\\r\\nwidth: 930px;\\r\\n}\\r\\n\\r\\n    text {\\r\\n        font-size: 11px;\\r\\n    }\\r\\n\\r\\n    rect {\\r\\n        fill: none;\\r\\n    }\\r\\n\\r\\n</style>\\r\\n        <div><select class=\\"treemap\\">\\r\\n                <option value=\\"size\\">Value of Projects</option>\\r\\n                <option value=\\"count\\">Number of Projects</option>\\r\\n            </select></div>\\r\\n<div id=\\"treemap\\"></div>\\r\\n<script type=\\"text/javascript\\">\\r\\n    var w = 930 - 80,\\r\\n        h = 800 - 180,\\r\\n        x = d3.scale.linear().range([0, w]),\\r\\n        y = d3.scale.linear().range([0, h]),\\r\\n        color = d3.scale.category20c(),\\r\\n        root,\\r\\n        node;\\r\\njQuery(document).ready(function()\\r\\n{\\r\\n    function size(d) {\\r\\n        return d.size;\\r\\n    }\\r\\n\\r\\n    function count(d) {\\r\\n        return 1;\\r\\n    }\\r\\n\\r\\n    function zoom(d) {\\r\\n        var kx = w / d.dx, ky = h / d.dy;\\r\\n        x.domain([d.x, d.x + d.dx]);\\r\\n        y.domain([d.y, d.y + d.dy]);\\r\\n\\r\\n        var t = svg.selectAll(\\"g.cell\\").transition()\\r\\n            .duration(d3.event.altKey ? 7500 : 750)\\r\\n            .attr(\\"transform\\", function(d) { return \\"translate(\\" + x(d.x) + \\",\\" + y(d.y) + \\")\\"; });\\r\\n\\r\\n        t.select(\\"rect\\")\\r\\n            .attr(\\"width\\", function(d) { return kx * d.dx - 1; })\\r\\n            .attr(\\"height\\", function(d) { return ky * d.dy - 1; })\\r\\n\\r\\n        t.select(\\"text\\")\\r\\n            .attr(\\"x\\", function(d) { return kx * d.dx / 2; })\\r\\n            .attr(\\"y\\", function(d) { return ky * d.dy / 2; })\\r\\n            .style(\\"opacity\\", function(d) { return kx * d.dx > d.w ? 1 : 0; });\\r\\n\\r\\n        node = d;\\r\\n        d3.event.stopPropagation();\\r\\n    }\\r\\n\\r\\n    var treemap = d3.layout.treemap()\\r\\n        .round(false)\\r\\n        .size([w, h])\\r\\n        .sticky(true)\\r\\n        .value(function(d) { return d.size; });\\r\\n\\r\\n    var svg = d3.select(\\"#treemap\\").append(\\"div\\")\\r\\n        .attr(\\"class\\", \\"chart\\")\\r\\n        .style(\\"width\\", w + \\"px\\")\\r\\n        .style(\\"height\\", h + \\"px\\")\\r\\n        .append(\\"svg:svg\\")\\r\\n        .attr(\\"width\\", w)\\r\\n        .attr(\\"height\\", h)\\r\\n        .append(\\"svg:g\\")\\r\\n        .attr(\\"transform\\", \\"translate(.5,.5)\\");\\r\\n    d3.json(\\"/datastore_search_sql.js.php?sql=SELECT%20*%20from%20%222133eaed-150b-4c73-a314-67a0bde04115%22%20WHERE%20metric%20%3D%20%27total_project_budget%27\\",\\r\\n        function(error, data) {\\r\\n            datum = {\\r\\n                \\"name\\": \\"flare\\",\\r\\n                \\"children\\": data.result.records.map(function (d) {\\r\\n                return {name: d.name, size: d.value};\\r\\n            })\\r\\n            };\\r\\n        node = root = datum;\\r\\n\\r\\n        var nodes = treemap.nodes(root)\\r\\n            .filter(function(d) { return !d.children; });\\r\\n\\r\\n        var cell = svg.selectAll(\\"g\\")\\r\\n            .data(nodes)\\r\\n            .enter().append(\\"svg:g\\")\\r\\n            .attr(\\"class\\", \\"cell\\")\\r\\n            .attr(\\"transform\\", function(d) { return \\"translate(\\" + d.x + \\",\\" + d.y + \\")\\"; })\\r\\n            .on(\\"click\\", function(d) { return zoom(node == d.parent ? root : d.parent); });\\r\\n\\r\\n        cell.append(\\"svg:rect\\")\\r\\n            .attr(\\"width\\", function(d) { return d.dx - 1; })\\r\\n            .attr(\\"height\\", function(d) { return d.dy - 1; })\\r\\n            .style(\\"fill\\", function(d) { return color(d.size); });\\r\\n\\r\\n        cell.append(\\"svg:text\\")\\r\\n            .attr(\\"x\\", function(d) { return d.dx / 2; })\\r\\n            .attr(\\"y\\", function(d) { return d.dy / 2; })\\r\\n            .attr(\\"dy\\", \\".35em\\")\\r\\n            .attr(\\"text-anchor\\", \\"middle\\")\\r\\n            .text(function(d) { return d.name; })\\r\\n            .style(\\"opacity\\", function(d) { d.w = this.getComputedTextLength(); return d.dx > d.w ? 1 : 0; });\\r\\n\\r\\n        d3.select(window).on(\\"click\\", function() { zoom(root); });\\r\\n\\r\\n        d3.select(\\"select.treemap\\").on(\\"change\\", function() {\\r\\n            treemap.value(this.value == \\"size\\" ? size : count).nodes(root);\\r\\n            zoom(node);\\r\\n        });\\r\\n    });\\r\\n});\\r\\n\\r\\n\\r\\n</script>\\r\\n",
            \'summary\' => \'\',
            \'format\' => \'full_html\',
            \'safe_value\' => "<style type=\\"text/css\\">\\n<!--/*--><![CDATA[/* ><!--*/\\n\\n\\n    .chart {\\n        display: block;\\n        margin: auto;\\n        margin-top: 40px;\\n    }\\n#treemap {\\nwidth: 930px;\\n}\\n\\n    text {\\n        font-size: 11px;\\n    }\\n\\n    rect {\\n        fill: none;\\n    }\\n\\n\\n/*--><!]]>*/\\n</style><div>\\n<select class=\\"treemap\\"><option value=\\"size\\">Value of Projects</option><br /><option value=\\"count\\">Number of Projects</option><br /></select></div>\\n<div id=\\"treemap\\"></div>\\n<script type=\\"text/javascript\\">\\n<!--//--><![CDATA[// ><!--\\n\\n    var w = 930 - 80,\\n        h = 800 - 180,\\n        x = d3.scale.linear().range([0, w]),\\n        y = d3.scale.linear().range([0, h]),\\n        color = d3.scale.category20c(),\\n        root,\\n        node;\\njQuery(document).ready(function()\\n{\\n    function size(d) {\\n        return d.size;\\n    }\\n\\n    function count(d) {\\n        return 1;\\n    }\\n\\n    function zoom(d) {\\n        var kx = w / d.dx, ky = h / d.dy;\\n        x.domain([d.x, d.x + d.dx]);\\n        y.domain([d.y, d.y + d.dy]);\\n\\n        var t = svg.selectAll(\\"g.cell\\").transition()\\n            .duration(d3.event.altKey ? 7500 : 750)\\n            .attr(\\"transform\\", function(d) { return \\"translate(\\" + x(d.x) + \\",\\" + y(d.y) + \\")\\"; });\\n\\n        t.select(\\"rect\\")\\n            .attr(\\"width\\", function(d) { return kx * d.dx - 1; })\\n            .attr(\\"height\\", function(d) { return ky * d.dy - 1; })\\n\\n        t.select(\\"text\\")\\n            .attr(\\"x\\", function(d) { return kx * d.dx / 2; })\\n            .attr(\\"y\\", function(d) { return ky * d.dy / 2; })\\n            .style(\\"opacity\\", function(d) { return kx * d.dx > d.w ? 1 : 0; });\\n\\n        node = d;\\n        d3.event.stopPropagation();\\n    }\\n\\n    var treemap = d3.layout.treemap()\\n        .round(false)\\n        .size([w, h])\\n        .sticky(true)\\n        .value(function(d) { return d.size; });\\n\\n    var svg = d3.select(\\"#treemap\\").append(\\"div\\")\\n        .attr(\\"class\\", \\"chart\\")\\n        .style(\\"width\\", w + \\"px\\")\\n        .style(\\"height\\", h + \\"px\\")\\n        .append(\\"svg:svg\\")\\n        .attr(\\"width\\", w)\\n        .attr(\\"height\\", h)\\n        .append(\\"svg:g\\")\\n        .attr(\\"transform\\", \\"translate(.5,.5)\\");\\n    d3.json(\\"/datastore_search_sql.js.php?sql=SELECT%20*%20from%20%222133eaed-150b-4c73-a314-67a0bde04115%22%20WHERE%20metric%20%3D%20%27total_project_budget%27\\",\\n        function(error, data) {\\n            datum = {\\n                \\"name\\": \\"flare\\",\\n                \\"children\\": data.result.records.map(function (d) {\\n                return {name: d.name, size: d.value};\\n            })\\n            };\\n        node = root = datum;\\n\\n        var nodes = treemap.nodes(root)\\n            .filter(function(d) { return !d.children; });\\n\\n        var cell = svg.selectAll(\\"g\\")\\n            .data(nodes)\\n            .enter().append(\\"svg:g\\")\\n            .attr(\\"class\\", \\"cell\\")\\n            .attr(\\"transform\\", function(d) { return \\"translate(\\" + d.x + \\",\\" + d.y + \\")\\"; })\\n            .on(\\"click\\", function(d) { return zoom(node == d.parent ? root : d.parent); });\\n\\n        cell.append(\\"svg:rect\\")\\n            .attr(\\"width\\", function(d) { return d.dx - 1; })\\n            .attr(\\"height\\", function(d) { return d.dy - 1; })\\n            .style(\\"fill\\", function(d) { return color(d.size); });\\n\\n        cell.append(\\"svg:text\\")\\n            .attr(\\"x\\", function(d) { return d.dx / 2; })\\n            .attr(\\"y\\", function(d) { return d.dy / 2; })\\n            .attr(\\"dy\\", \\".35em\\")\\n            .attr(\\"text-anchor\\", \\"middle\\")\\n            .text(function(d) { return d.name; })\\n            .style(\\"opacity\\", function(d) { d.w = this.getComputedTextLength(); return d.dx > d.w ? 1 : 0; });\\n\\n        d3.select(window).on(\\"click\\", function() { zoom(root); });\\n\\n        d3.select(\\"select.treemap\\").on(\\"change\\", function() {\\n            treemap.value(this.value == \\"size\\" ? size : count).nodes(root);\\n            zoom(node);\\n        });\\n    });\\n});\\n\\n\\n\\n//--><!]]>\\n</script>",
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
      \'last_comment_timestamp\' => \'1418733726\',
      \'last_comment_name\' => NULL,
      \'last_comment_uid\' => \'1\',
      \'comment_count\' => \'0\',
      \'name\' => \'admin\',
      \'picture\' => \'0\',
      \'data\' => \'b:0;\',
      \'path\' => array(
        \'pid\' => \'35\',
        \'source\' => \'node/1673\',
        \'alias\' => \'content/ict-project-treemap\',
        \'language\' => \'und\',
      ),
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'1674\',
      \'uid\' => \'1\',
      \'title\' => \'ICT Project Timelines\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'1\',
      \'promote\' => \'0\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'e9808e16-4fe8-43be-8a0d-b716c0d3bd61\',
      \'ds_switch\' => \'\',
      \'nid\' => \'1674\',
      \'type\' => \'page\',
      \'language\' => \'und\',
      \'created\' => \'1418733726\',
      \'changed\' => \'1418781613\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'8754ca37-1410-4671-bb58-ce670b640f5d\',
      \'revision_timestamp\' => \'1418781613\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "    <script type=\\"text/javascript\\">\\r\\n\\r\\njQuery(document).ready(function () {\\r\\n    var source = [];\\r\\nvar color = [\'Red\',\'Green\',\'Orange\'];\\r\\n    d3.json(\\"/datastore_search_sql.js.php?sql=select+distinct+p.name%2C+start_date%2C+end_date%2C+expected_end_date%2C+total_value%2C+expected_total_value%0AFROM+%28select+name%2C+value+as+start_date+from%222133eaed-150b-4c73-a314-67a0bde04115%22+where+metric+%3D+%27original_completion_date%27++%29+p+full+outer+JOIN%0A++%28select+name%2C+value+as+end_date+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+where+metric+%3D+%27start_date%27+%29+a+on+p.name+%3D+a.name+full+outer+JOIN%0A++%28select+name%2C+value+as+total_value+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+where+metric+%3D+%27total_project_budget%27+%29+v+on+p.name+%3D+v.name+full+outer+JOIN%0A++%28select+DISTINCT+d.name%2C+d.value+as+expected_end_date+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+d+join+%28select+name%2Cmetric%2C+max%28timestamp%29+as+timestamp%0Afrom+%222133eaed-150b-4c73-a314-67a0bde04115%22+GROUP+BY+name%2Cmetric%29+s+on+d.metric%3Ds.metric+and+d.timestamp%3Ds.timestamp%0Awhere+d.metric+%3D+%27current_expected_completion_date%27%29+c+on+p.name+%3D+c.name+full+outer+JOIN%0A++%28select+DISTINCT+d.name%2C+d.value+as+expected_total_value+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+d+join+%28select+name%2Cmetric%2C+max%28timestamp%29+as+timestamp%0Afrom+%222133eaed-150b-4c73-a314-67a0bde04115%22+GROUP+BY+name%2Cmetric%29+s+on+d.metric%3Ds.metric+and+d.timestamp%3Ds.timestamp%0Awhere+d.metric+%3D+%27current_total_expected_budget%27%29+b+on+p.name+%3D+b.name+\\",\\r\\n        function (error, data) {\\r\\n            for (var i in data.result.records) {\\r\\n                d = data.result.records[i];\\r\\n                starting_time = new Date(moment(d.start_date)).getTime();\\r\\n                ending_time = new Date(moment(d.end_date)).getTime();\\r\\n                expected_ending_time = new Date(moment(d.expected_end_date)).getTime();\\r\\n\\r\\n                source.push({\\r\\n                    name: d.name,\\r\\n                    desc: \\"\\",\\r\\n                    values: [{\\r\\n                        from: starting_time,\\r\\n                        to: expected_ending_time,\\r\\n                        label: d.name,\\r\\n                        customClass: \\"gantt\\" + color[i%3]\\r\\n                    }]\\r\\n                });\\r\\n            }\\r\\n\\r\\n            jQuery(\\".gantt\\").gantt({\\r\\n                source: source,\\r\\n                navigate: \\"scroll\\",\\r\\n                minScale: \\"months\\",\\r\\n                maxScale: \\"years\\",\\r\\n                itemsPerPage: 10,\\r\\n                \\r\\n                onRender: function () {\\r\\n                    if (window.console && typeof console.log === \\"function\\") {\\r\\n                        console.log(\\"chart rendered\\");\\r\\n                    }\\r\\n                }\\r\\n            });\\r\\n// window.setTimeout(function() {jQuery(\'.nav-zoomIn\')[0].click();}, 800);\\r\\n        });\\r\\n});\\r\\n    </script>\\r\\n<style>\\r\\n.gantt, .gantt2 {\\r\\n    width: 930px;\\r\\n    margin: 20px auto;\\r\\n    border: 14px solid #ddd;\\r\\n    position: relative;\\r\\n        -webkit-border-radius: 6px;\\r\\n        -moz-border-radius: 6px;\\r\\n        border-radius: 6px;\\r\\n            -webkit-box-sizing: border-box;\\r\\n            -moz-box-sizing: border-box;\\r\\n            box-sizing: border-box;\\r\\n}\\r\\n\\r\\n.gantt:after {\\r\\n    content: \\".\\";\\r\\n    visibility: hidden;\\r\\n    display: block;\\r\\n    height: 0;\\r\\n    clear: both;\\r\\n}\\r\\n\\r\\n.fn-gantt {\\r\\n    width: 100%;Hunter Connection\\r\\n}\\r\\n\\r\\n.fn-gantt .fn-content {\\r\\n    overflow: hidden;\\r\\n    position: relative;\\r\\n    width: 100%;\\r\\n}\\r\\n\\r\\n\\r\\n\\r\\n\\r\\n/* === LEFT PANEL === */\\r\\n\\r\\n.fn-gantt .leftPanel {\\r\\n    float: left;\\r\\n    width: 225px;\\r\\n    overflow: hidden;\\r\\n    border-right: 1px solid #DDD;\\r\\n    position: relative;\\r\\n    z-index: 20;\\r\\nbackground-color: #f6f6f6;\\r\\n}\\r\\n\\r\\n.fn-gantt .row {\\r\\n    float: left;\\r\\n    height: 24px;\\r\\n    line-height: 24px;\\r\\n    margin-left: -1px;\\r\\n}\\r\\n.header .fn-label {background-color: #f6f6f6 !important;}\\r\\n\\r\\n.fn-gantt .leftPanel .fn-label {\\r\\n    display: inline-block;\\r\\n    margin: 0 0 0 5px;\\r\\n    color: #484A4D;\\r\\n    width: 110px;\\r\\n    white-space: nowrap;\\r\\n    text-overflow: ellipsis;\\r\\n    overflow: hidden;\\r\\n}\\r\\n\\r\\n.fn-gantt .leftPanel .row0 {\\r\\n    border-top: 1px solid #DDD;\\r\\n}\\r\\n.fn-gantt .leftPanel .name, .fn-gantt .leftPanel .desc {\\r\\n    float: left;\\r\\n    height: 23px;\\r\\n    margin: 0;\\r\\n    border-bottom: 1px solid #DDD;\\r\\n    background-color: #f6f6f6;\\r\\n}\\r\\n\\r\\n.fn-gantt .leftPanel .name {\\r\\n    width: 110px;\\r\\n    font-weight: bold;\\r\\n}\\r\\n\\r\\n.fn-gantt .leftPanel .desc {\\r\\n    width: 114px;\\r\\n}\\r\\n\\r\\n.fn-gantt .leftPanel .fn-wide, .fn-gantt .leftPanel .fn-wide .fn-label {\\r\\n    width: 225px;\\r\\n}\\r\\n\\r\\n.fn-gantt .spacer {\\r\\n    margin: -2px 0 1px 0;\\r\\n    border-bottom: none;\\r\\n    background-color: #f6f6f6;\\r\\n}\\r\\n\\r\\n\\r\\n\\r\\n\\r\\n/* === RIGHT PANEL === */\\r\\n\\r\\n.fn-gantt .rightPanel {\\r\\n    overflow: hidden;\\r\\n}\\r\\n\\r\\n.fn-gantt .dataPanel {\\r\\n    margin-left: 0px;\\r\\n    border-right: 1px solid #DDD;\\r\\n    background-image: url(/sites/all/themes/itdash/js/grid.png);\\r\\n    background-repeat: repeat;\\r\\n    background-position: 24px 24px;\\r\\n    position: relative;\\r\\n}\\r\\n.fn-gantt .day, .fn-gantt .date {\\r\\n    overflow: visible;\\r\\n    width: 24px;\\r\\n    line-height: 24px;\\r\\n    text-align: center;\\r\\n    border-left: 1px solid #DDD;\\r\\n    border-bottom: 1px solid #DDD;\\r\\n    margin: -1px 0 0 -1px;\\r\\n    font-size: 11px;\\r\\n    color: #484a4d;\\r\\n    text-shadow: 0 1px 0 rgba(255,255,255,0.75);\\r\\n    text-align: center;\\r\\n}\\r\\n\\r\\n.fn-gantt .holiday {\\r\\n    background-color: #ffd263;\\r\\n    height: 23px;\\r\\n    margin: 0 0 -1px -1px;\\r\\n}\\r\\n\\r\\n.fn-gantt .today {\\r\\n    background-color: #fff8da;\\r\\n    height: 23px;\\r\\n    margin: 0 0 -1px -1px;\\r\\n    font-weight: bold;\\r\\n    text-align: center;\\r\\n}\\r\\n\\r\\n.fn-gantt .sa, .fn-gantt .sn, .fn-gantt .wd {\\r\\n    height: 23px;\\r\\n    margin: 0 0 0 -1px;\\r\\n    text-align: center;\\r\\n}\\r\\n\\r\\n.fn-gantt .sa, .fn-gantt .sn {\\r\\n    color: #939496;\\r\\n    background-color: #f5f5f5;\\r\\n    text-align: center;\\r\\n}\\r\\n\\r\\n.fn-gantt .wd {\\r\\n    background-color: #f6f6f6;\\r\\n    text-align: center;\\r\\n}\\r\\n\\r\\n.fn-gantt .rightPanel .month, .fn-gantt .rightPanel .year {\\r\\n    float: left;\\r\\n    overflow: hidden;\\r\\n    border-left: 1px solid #DDD;\\r\\n    border-bottom: 1px solid #DDD;\\r\\n    height: 23px;\\r\\n    margin: 0 0 0 -1px;\\r\\n    background-color: #f6f6f6;\\r\\n    font-weight: bold;\\r\\n    font-size: 11px;\\r\\n    color: #484a4d;\\r\\n    text-shadow: 0 1px 0 rgba(255,255,255,0.75);\\r\\n    text-align: center;\\r\\n}\\r\\n\\r\\n.fn-gantt-hint {\\r\\n    border: 5px solid #edc332;\\r\\n    background-color: #fff5d4;\\r\\n    padding: 10px;\\r\\n    position: absolute;\\r\\n    display: none;\\r\\n    z-index: 11;\\r\\n        -webkit-border-radius: 4px;\\r\\n        -moz-border-radius: 4px;\\r\\n        border-radius: 4px;\\r\\n}\\r\\n\\r\\n.fn-gantt .bar {\\r\\n    background-color: #D0E4FD;\\r\\n    height: 18px;\\r\\n    margin: 0px 3px 3px 0px;\\r\\n    position: absolute;\\r\\n    z-index: 10;\\r\\n    text-align: center;\\r\\n        -webkit-box-shadow: 0 0 1px rgba(0,0,0,0.25) inset;\\r\\n        -moz-box-shadow: 0 0 1px rgba(0,0,0,0.25) inset;\\r\\n        box-shadow: 0 0 1px rgba(0,0,0,0.25) inset;\\r\\n            -webkit-border-radius: 3px;\\r\\n            -moz-border-radius: 3px;\\r\\n            border-radius: 3px;\\r\\n}\\r\\n\\r\\n.fn-gantt .bar .fn-label {\\r\\n    line-height: 18px;\\r\\n    font-weight: bold;\\r\\n    white-space: nowrap;\\r\\n    width: 110px;\\r\\n    text-overflow: ellipsis;\\r\\n    overflow: hidden;\\r\\n    text-shadow: 0 1px 0 rgba(255,255,255,0.4);\\r\\n    color: #414B57 !important;\\r\\n    text-align: center;\\r\\n    font-size: 11px;\\r\\n}\\r\\n\\r\\n.fn-gantt .ganttRed {\\r\\n    background-color: #F9C4E1;\\r\\n}\\r\\n.fn-gantt .ganttRed .fn-label {\\r\\n    color: #78436D !important;\\r\\n}\\r\\n\\r\\n.fn-gantt .ganttGreen {\\r\\n    background-color: #D8EDA3;\\r\\n}\\r\\n.fn-gantt .ganttGreen .fn-label {\\r\\n    color: #778461 !important;\\r\\n}\\r\\n\\r\\n.fn-gantt .ganttOrange {\\r\\n    background-color: #FCD29A;\\r\\n}\\r\\n.fn-gantt .ganttOrange .fn-label {\\r\\n    color: #714715 !important;\\r\\n}\\r\\n\\r\\n\\r\\n/* === BOTTOM NAVIGATION === */\\r\\n\\r\\n.fn-gantt .bottom {\\r\\n    clear: both;\\r\\n    background-color: #f6f6f6;\\r\\n    width: 100%;\\r\\n}\\r\\n.fn-gantt .navigate {\\r\\n    border-top: 1px solid #DDD;\\r\\n    padding: 10px 0 10px 225px;\\r\\n}\\r\\n\\r\\n.fn-gantt .navigate .nav-slider {\\r\\n    height: 20px;\\r\\n    display: inline-block;\\r\\n}\\r\\n\\r\\n.fn-gantt .navigate .nav-slider-left, .fn-gantt .navigate .nav-slider-right {\\r\\n    text-align: center;\\r\\n    height: 20px;\\r\\n    display: inline-block;\\r\\n}\\r\\n\\r\\n.fn-gantt .navigate .nav-slider-left {\\r\\n    float: left;\\r\\n}\\r\\n\\r\\n.fn-gantt .navigate .nav-slider-right {\\r\\n    float: right;\\r\\n}\\r\\n\\r\\n.fn-gantt .navigate .nav-slider-content {\\r\\n    text-align: left;\\r\\n    width: 160px;\\r\\n    height: 20px;\\r\\n    display: inline-block;\\r\\n    margin: 0 10px;\\r\\n}\\r\\n\\r\\n.fn-gantt .navigate .nav-slider-bar, .fn-gantt .navigate .nav-slider-button {\\r\\n    position: absolute;\\r\\n    display: block;\\r\\n}\\r\\n\\r\\n.fn-gantt .navigate .nav-slider-bar {\\r\\n    width: 155px;\\r\\n    height: 6px;\\r\\n    background-color: #838688;\\r\\n    margin: 8px 0 0 0;\\r\\n        -webkit-box-shadow: 0 1px 3px rgba(0,0,0,0.6) inset;\\r\\n        -moz-box-shadow: 0 1px 3px rgba(0,0,0,0.6) inset;\\r\\n        box-shadow: 0 1px 3px rgba(0,0,0,0.6) inset;\\r\\n            -webkit-border-radius: 3px;\\r\\n            -moz-border-radius: 3px;\\r\\n            border-radius: 3px;\\r\\n}\\r\\n\\r\\n.fn-gantt .navigate .nav-slider-button {\\r\\n    width: 17px;\\r\\n    height: 60px;\\r\\n    background: url(/sites/all/themes/itdash/js/slider_handle.png) center center no-repeat;\\r\\n    left: 0px;\\r\\n    top: 0px;\\r\\n    margin: -26px 0 0 0;\\r\\n    cursor: pointer;\\r\\n}\\r\\n\\r\\n.fn-gantt .navigate .page-number {\\r\\n    display: inline-block;\\r\\n    font-size: 10px;\\r\\n    height: 20px;\\r\\n}\\r\\n\\r\\n.fn-gantt .navigate .page-number span {\\r\\n    color: #666666;\\r\\n    margin: 0 6px;\\r\\n    height: 20px;\\r\\n    line-height: 20px;\\r\\n    display: inline-block;\\r\\n}\\r\\n\\r\\n.fn-gantt .navigate a:link, .fn-gantt .navigate a:visited, .fn-gantt .navigate a:active {\\r\\n    text-decoration: none;\\r\\n}\\r\\n\\r\\n.fn-gantt .nav-link {\\r\\n    margin: 0 3px 0 0;\\r\\n    display: inline-block;\\r\\n    width: 20px;\\r\\n    height: 20px;\\r\\n    font-size: 0px;\\r\\n    background: #595959 url(/sites/all/themes/itdash/js/icon_sprite.png) !important;\\r\\n    border: 1px solid #454546;\\r\\n    cursor: pointer;\\r\\n    vertical-align: top;\\r\\n        -webkit-border-radius: 2px;\\r\\n        -moz-border-radius: 2px;\\r\\n        border-radius: 2px;\\r\\n            -webkit-box-shadow: 0 1px 0 rgba(255,255,255,0.1) inset, 0 1px 1px rgba(0,0,0,0.2);\\r\\n            -moz-box-shadow: 0 1px 0 rgba(255,255,255,0.1) inset, 0 1px 1px rgba(0,0,0,0.2);\\r\\n            box-shadow: 0 1px 0 rgba(255,255,255,0.1) inset, 0 1px 1px rgba(0,0,0,0.2);\\r\\n                -webkit-box-sizing: border-box;\\r\\n                -moz-box-sizing: border-box;\\r\\n                box-sizing: border-box;\\r\\n}\\r\\n.fn-gantt .nav-link:active {\\r\\n    -webkit-box-shadow: 0 1px 1px rgba(0,0,0,0.25) inset, 0 1px 0 #FFF;\\r\\n    -moz-box-shadow: 0 1px 1px rgba(0,0,0,0.25) inset, 0 1px 0 #FFF;\\r\\n    box-shadow: 0 1px 1px rgba(0,0,0,0.25) inset, 0 1px 0 #FFF;\\r\\n}\\r\\n\\r\\n.fn-gantt .navigate .nav-page-back {\\r\\n    background-position: 1px 0 !important;\\r\\n    margin: 0;\\r\\n}\\r\\n\\r\\n.fn-gantt .navigate .nav-page-next {\\r\\n    background-position: 1px -16px !important;\\r\\n    margin-right: 15px;\\r\\n}\\r\\n\\r\\n.fn-gantt .navigate .nav-slider .nav-page-next {\\r\\n    margin-right: 5px;\\r\\n}\\r\\n\\r\\n.fn-gantt .navigate .nav-begin {\\r\\n    background-position: 1px -112px !important;\\r\\n}\\r\\n\\r\\n.fn-gantt .navigate .nav-prev-week {\\r\\n    background-position: 1px -128px !important;\\r\\n}\\r\\n\\r\\n.fn-gantt .navigate .nav-prev-day {\\r\\n    background-position: 1px -48px !important;\\r\\n}\\r\\n\\r\\n.fn-gantt .navigate .nav-next-day {\\r\\n    background-position: 1px -64px !important;\\r\\n}\\r\\n\\r\\n.fn-gantt .navigate .nav-next-week {\\r\\n    background-position: 1px -160px !important;\\r\\n}\\r\\n\\r\\n.fn-gantt .navigate .nav-end {\\r\\n    background-position: 1px -144px !important;\\r\\n}\\r\\n\\r\\n.fn-gantt .navigate .nav-zoomOut {\\r\\n    background-position: 1px -96px !important;\\r\\n}\\r\\n\\r\\n.fn-gantt .navigate .nav-zoomIn {\\r\\n    background-position: 1px -80px !important;\\r\\n    margin-left: 15px;\\r\\n}\\r\\n\\r\\n.fn-gantt .navigate .nav-now {\\r\\n    background-position: 1px -32px !important;\\r\\n}\\r\\n\\r\\n.fn-gantt .navigate .nav-slider .nav-now {\\r\\n    margin-right: 5px;\\r\\n}\\r\\n\\r\\n.fn-gantt-loader {\\r\\n    position: absolute;\\r\\n    width: 100%;\\r\\n    height: 100%;\\r\\n    left: 0;\\r\\n    top: 0;\\r\\n    filter: progid:DXImageTransform.Microsoft.gradient( startColorstr=\'#bf000000\', endColorstr=\'#bf000000\',GradientType=0 );\\r\\n    background: rgba(0,0,0,0.75);\\r\\n    cursor: wait;\\r\\n    z-index: 30;\\r\\n}\\r\\n.fn-gantt-loader-spinner span {\\r\\n    position: absolute;\\r\\n    margin: auto;\\r\\n    top: 0;\\r\\n    right: 0;\\r\\n    bottom: 0;\\r\\n    left: 0;\\r\\n    width: 100%;\\r\\n    text-align: center;\\r\\n    height: 1em;\\r\\n    line-height: 1em;\\r\\n    color: #fff;\\r\\n    font-size: 1em;\\r\\n    font-weight: bold;\\r\\n}\\r\\n\\r\\n.row:after {\\r\\n    clear: both;\\r\\n}\\r\\n\\r\\n</style>\\r\\n<div class=\\"gantt\\"></div>",
            \'summary\' => \'\',
            \'format\' => \'full_html\',
            \'safe_value\' => "<script type=\\"text/javascript\\">\\n<!--//--><![CDATA[// ><!--\\n\\n\\njQuery(document).ready(function () {\\n    var source = [];\\nvar color = [\'Red\',\'Green\',\'Orange\'];\\n    d3.json(\\"/datastore_search_sql.js.php?sql=select+distinct+p.name%2C+start_date%2C+end_date%2C+expected_end_date%2C+total_value%2C+expected_total_value%0AFROM+%28select+name%2C+value+as+start_date+from%222133eaed-150b-4c73-a314-67a0bde04115%22+where+metric+%3D+%27original_completion_date%27++%29+p+full+outer+JOIN%0A++%28select+name%2C+value+as+end_date+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+where+metric+%3D+%27start_date%27+%29+a+on+p.name+%3D+a.name+full+outer+JOIN%0A++%28select+name%2C+value+as+total_value+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+where+metric+%3D+%27total_project_budget%27+%29+v+on+p.name+%3D+v.name+full+outer+JOIN%0A++%28select+DISTINCT+d.name%2C+d.value+as+expected_end_date+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+d+join+%28select+name%2Cmetric%2C+max%28timestamp%29+as+timestamp%0Afrom+%222133eaed-150b-4c73-a314-67a0bde04115%22+GROUP+BY+name%2Cmetric%29+s+on+d.metric%3Ds.metric+and+d.timestamp%3Ds.timestamp%0Awhere+d.metric+%3D+%27current_expected_completion_date%27%29+c+on+p.name+%3D+c.name+full+outer+JOIN%0A++%28select+DISTINCT+d.name%2C+d.value+as+expected_total_value+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+d+join+%28select+name%2Cmetric%2C+max%28timestamp%29+as+timestamp%0Afrom+%222133eaed-150b-4c73-a314-67a0bde04115%22+GROUP+BY+name%2Cmetric%29+s+on+d.metric%3Ds.metric+and+d.timestamp%3Ds.timestamp%0Awhere+d.metric+%3D+%27current_total_expected_budget%27%29+b+on+p.name+%3D+b.name+\\",\\n        function (error, data) {\\n            for (var i in data.result.records) {\\n                d = data.result.records[i];\\n                starting_time = new Date(moment(d.start_date)).getTime();\\n                ending_time = new Date(moment(d.end_date)).getTime();\\n                expected_ending_time = new Date(moment(d.expected_end_date)).getTime();\\n\\n                source.push({\\n                    name: d.name,\\n                    desc: \\"\\",\\n                    values: [{\\n                        from: starting_time,\\n                        to: expected_ending_time,\\n                        label: d.name,\\n                        customClass: \\"gantt\\" + color[i%3]\\n                    }]\\n                });\\n            }\\n\\n            jQuery(\\".gantt\\").gantt({\\n                source: source,\\n                navigate: \\"scroll\\",\\n                minScale: \\"months\\",\\n                maxScale: \\"years\\",\\n                itemsPerPage: 10,\\n                \\n                onRender: function () {\\n                    if (window.console && typeof console.log === \\"function\\") {\\n                        console.log(\\"chart rendered\\");\\n                    }\\n                }\\n            });\\n// window.setTimeout(function() {jQuery(\'.nav-zoomIn\')[0].click();}, 800);\\n        });\\n});\\n    \\n//--><!]]>\\n</script><style>\\n<!--/*--><![CDATA[/* ><!--*/\\n\\n.gantt, .gantt2 {\\n    width: 930px;\\n    margin: 20px auto;\\n    border: 14px solid #ddd;\\n    position: relative;\\n        -webkit-border-radius: 6px;\\n        -moz-border-radius: 6px;\\n        border-radius: 6px;\\n            -webkit-box-sizing: border-box;\\n            -moz-box-sizing: border-box;\\n            box-sizing: border-box;\\n}\\n\\n.gantt:after {\\n    content: \\".\\";\\n    visibility: hidden;\\n    display: block;\\n    height: 0;\\n    clear: both;\\n}\\n\\n.fn-gantt {\\n    width: 100%;Hunter Connection\\n}\\n\\n.fn-gantt .fn-content {\\n    overflow: hidden;\\n    position: relative;\\n    width: 100%;\\n}\\n\\n\\n\\n\\n/* === LEFT PANEL === */\\n\\n.fn-gantt .leftPanel {\\n    float: left;\\n    width: 225px;\\n    overflow: hidden;\\n    border-right: 1px solid #DDD;\\n    position: relative;\\n    z-index: 20;\\nbackground-color: #f6f6f6;\\n}\\n\\n.fn-gantt .row {\\n    float: left;\\n    height: 24px;\\n    line-height: 24px;\\n    margin-left: -1px;\\n}\\n.header .fn-label {background-color: #f6f6f6 !important;}\\n\\n.fn-gantt .leftPanel .fn-label {\\n    display: inline-block;\\n    margin: 0 0 0 5px;\\n    color: #484A4D;\\n    width: 110px;\\n    white-space: nowrap;\\n    text-overflow: ellipsis;\\n    overflow: hidden;\\n}\\n\\n.fn-gantt .leftPanel .row0 {\\n    border-top: 1px solid #DDD;\\n}\\n.fn-gantt .leftPanel .name, .fn-gantt .leftPanel .desc {\\n    float: left;\\n    height: 23px;\\n    margin: 0;\\n    border-bottom: 1px solid #DDD;\\n    background-color: #f6f6f6;\\n}\\n\\n.fn-gantt .leftPanel .name {\\n    width: 110px;\\n    font-weight: bold;\\n}\\n\\n.fn-gantt .leftPanel .desc {\\n    width: 114px;\\n}\\n\\n.fn-gantt .leftPanel .fn-wide, .fn-gantt .leftPanel .fn-wide .fn-label {\\n    width: 225px;\\n}\\n\\n.fn-gantt .spacer {\\n    margin: -2px 0 1px 0;\\n    border-bottom: none;\\n    background-color: #f6f6f6;\\n}\\n\\n\\n\\n\\n/* === RIGHT PANEL === */\\n\\n.fn-gantt .rightPanel {\\n    overflow: hidden;\\n}\\n\\n.fn-gantt .dataPanel {\\n    margin-left: 0px;\\n    border-right: 1px solid #DDD;\\n    background-image: url(/sites/all/themes/itdash/js/grid.png);\\n    background-repeat: repeat;\\n    background-position: 24px 24px;\\n    position: relative;\\n}\\n.fn-gantt .day, .fn-gantt .date {\\n    overflow: visible;\\n    width: 24px;\\n    line-height: 24px;\\n    text-align: center;\\n    border-left: 1px solid #DDD;\\n    border-bottom: 1px solid #DDD;\\n    margin: -1px 0 0 -1px;\\n    font-size: 11px;\\n    color: #484a4d;\\n    text-shadow: 0 1px 0 rgba(255,255,255,0.75);\\n    text-align: center;\\n}\\n\\n.fn-gantt .holiday {\\n    background-color: #ffd263;\\n    height: 23px;\\n    margin: 0 0 -1px -1px;\\n}\\n\\n.fn-gantt .today {\\n    background-color: #fff8da;\\n    height: 23px;\\n    margin: 0 0 -1px -1px;\\n    font-weight: bold;\\n    text-align: center;\\n}\\n\\n.fn-gantt .sa, .fn-gantt .sn, .fn-gantt .wd {\\n    height: 23px;\\n    margin: 0 0 0 -1px;\\n    text-align: center;\\n}\\n\\n.fn-gantt .sa, .fn-gantt .sn {\\n    color: #939496;\\n    background-color: #f5f5f5;\\n    text-align: center;\\n}\\n\\n.fn-gantt .wd {\\n    background-color: #f6f6f6;\\n    text-align: center;\\n}\\n\\n.fn-gantt .rightPanel .month, .fn-gantt .rightPanel .year {\\n    float: left;\\n    overflow: hidden;\\n    border-left: 1px solid #DDD;\\n    border-bottom: 1px solid #DDD;\\n    height: 23px;\\n    margin: 0 0 0 -1px;\\n    background-color: #f6f6f6;\\n    font-weight: bold;\\n    font-size: 11px;\\n    color: #484a4d;\\n    text-shadow: 0 1px 0 rgba(255,255,255,0.75);\\n    text-align: center;\\n}\\n\\n.fn-gantt-hint {\\n    border: 5px solid #edc332;\\n    background-color: #fff5d4;\\n    padding: 10px;\\n    position: absolute;\\n    display: none;\\n    z-index: 11;\\n        -webkit-border-radius: 4px;\\n        -moz-border-radius: 4px;\\n        border-radius: 4px;\\n}\\n\\n.fn-gantt .bar {\\n    background-color: #D0E4FD;\\n    height: 18px;\\n    margin: 0px 3px 3px 0px;\\n    position: absolute;\\n    z-index: 10;\\n    text-align: center;\\n        -webkit-box-shadow: 0 0 1px rgba(0,0,0,0.25) inset;\\n        -moz-box-shadow: 0 0 1px rgba(0,0,0,0.25) inset;\\n        box-shadow: 0 0 1px rgba(0,0,0,0.25) inset;\\n            -webkit-border-radius: 3px;\\n            -moz-border-radius: 3px;\\n            border-radius: 3px;\\n}\\n\\n.fn-gantt .bar .fn-label {\\n    line-height: 18px;\\n    font-weight: bold;\\n    white-space: nowrap;\\n    width: 110px;\\n    text-overflow: ellipsis;\\n    overflow: hidden;\\n    text-shadow: 0 1px 0 rgba(255,255,255,0.4);\\n    color: #414B57 !important;\\n    text-align: center;\\n    font-size: 11px;\\n}\\n\\n.fn-gantt .ganttRed {\\n    background-color: #F9C4E1;\\n}\\n.fn-gantt .ganttRed .fn-label {\\n    color: #78436D !important;\\n}\\n\\n.fn-gantt .ganttGreen {\\n    background-color: #D8EDA3;\\n}\\n.fn-gantt .ganttGreen .fn-label {\\n    color: #778461 !important;\\n}\\n\\n.fn-gantt .ganttOrange {\\n    background-color: #FCD29A;\\n}\\n.fn-gantt .ganttOrange .fn-label {\\n    color: #714715 !important;\\n}\\n\\n\\n/* === BOTTOM NAVIGATION === */\\n\\n.fn-gantt .bottom {\\n    clear: both;\\n    background-color: #f6f6f6;\\n    width: 100%;\\n}\\n.fn-gantt .navigate {\\n    border-top: 1px solid #DDD;\\n    padding: 10px 0 10px 225px;\\n}\\n\\n.fn-gantt .navigate .nav-slider {\\n    height: 20px;\\n    display: inline-block;\\n}\\n\\n.fn-gantt .navigate .nav-slider-left, .fn-gantt .navigate .nav-slider-right {\\n    text-align: center;\\n    height: 20px;\\n    display: inline-block;\\n}\\n\\n.fn-gantt .navigate .nav-slider-left {\\n    float: left;\\n}\\n\\n.fn-gantt .navigate .nav-slider-right {\\n    float: right;\\n}\\n\\n.fn-gantt .navigate .nav-slider-content {\\n    text-align: left;\\n    width: 160px;\\n    height: 20px;\\n    display: inline-block;\\n    margin: 0 10px;\\n}\\n\\n.fn-gantt .navigate .nav-slider-bar, .fn-gantt .navigate .nav-slider-button {\\n    position: absolute;\\n    display: block;\\n}\\n\\n.fn-gantt .navigate .nav-slider-bar {\\n    width: 155px;\\n    height: 6px;\\n    background-color: #838688;\\n    margin: 8px 0 0 0;\\n        -webkit-box-shadow: 0 1px 3px rgba(0,0,0,0.6) inset;\\n        -moz-box-shadow: 0 1px 3px rgba(0,0,0,0.6) inset;\\n        box-shadow: 0 1px 3px rgba(0,0,0,0.6) inset;\\n            -webkit-border-radius: 3px;\\n            -moz-border-radius: 3px;\\n            border-radius: 3px;\\n}\\n\\n.fn-gantt .navigate .nav-slider-button {\\n    width: 17px;\\n    height: 60px;\\n    background: url(/sites/all/themes/itdash/js/slider_handle.png) center center no-repeat;\\n    left: 0px;\\n    top: 0px;\\n    margin: -26px 0 0 0;\\n    cursor: pointer;\\n}\\n\\n.fn-gantt .navigate .page-number {\\n    display: inline-block;\\n    font-size: 10px;\\n    height: 20px;\\n}\\n\\n.fn-gantt .navigate .page-number span {\\n    color: #666666;\\n    margin: 0 6px;\\n    height: 20px;\\n    line-height: 20px;\\n    display: inline-block;\\n}\\n\\n.fn-gantt .navigate a:link, .fn-gantt .navigate a:visited, .fn-gantt .navigate a:active {\\n    text-decoration: none;\\n}\\n\\n.fn-gantt .nav-link {\\n    margin: 0 3px 0 0;\\n    display: inline-block;\\n    width: 20px;\\n    height: 20px;\\n    font-size: 0px;\\n    background: #595959 url(/sites/all/themes/itdash/js/icon_sprite.png) !important;\\n    border: 1px solid #454546;\\n    cursor: pointer;\\n    vertical-align: top;\\n        -webkit-border-radius: 2px;\\n        -moz-border-radius: 2px;\\n        border-radius: 2px;\\n            -webkit-box-shadow: 0 1px 0 rgba(255,255,255,0.1) inset, 0 1px 1px rgba(0,0,0,0.2);\\n            -moz-box-shadow: 0 1px 0 rgba(255,255,255,0.1) inset, 0 1px 1px rgba(0,0,0,0.2);\\n            box-shadow: 0 1px 0 rgba(255,255,255,0.1) inset, 0 1px 1px rgba(0,0,0,0.2);\\n                -webkit-box-sizing: border-box;\\n                -moz-box-sizing: border-box;\\n                box-sizing: border-box;\\n}\\n.fn-gantt .nav-link:active {\\n    -webkit-box-shadow: 0 1px 1px rgba(0,0,0,0.25) inset, 0 1px 0 #FFF;\\n    -moz-box-shadow: 0 1px 1px rgba(0,0,0,0.25) inset, 0 1px 0 #FFF;\\n    box-shadow: 0 1px 1px rgba(0,0,0,0.25) inset, 0 1px 0 #FFF;\\n}\\n\\n.fn-gantt .navigate .nav-page-back {\\n    background-position: 1px 0 !important;\\n    margin: 0;\\n}\\n\\n.fn-gantt .navigate .nav-page-next {\\n    background-position: 1px -16px !important;\\n    margin-right: 15px;\\n}\\n\\n.fn-gantt .navigate .nav-slider .nav-page-next {\\n    margin-right: 5px;\\n}\\n\\n.fn-gantt .navigate .nav-begin {\\n    background-position: 1px -112px !important;\\n}\\n\\n.fn-gantt .navigate .nav-prev-week {\\n    background-position: 1px -128px !important;\\n}\\n\\n.fn-gantt .navigate .nav-prev-day {\\n    background-position: 1px -48px !important;\\n}\\n\\n.fn-gantt .navigate .nav-next-day {\\n    background-position: 1px -64px !important;\\n}\\n\\n.fn-gantt .navigate .nav-next-week {\\n    background-position: 1px -160px !important;\\n}\\n\\n.fn-gantt .navigate .nav-end {\\n    background-position: 1px -144px !important;\\n}\\n\\n.fn-gantt .navigate .nav-zoomOut {\\n    background-position: 1px -96px !important;\\n}\\n\\n.fn-gantt .navigate .nav-zoomIn {\\n    background-position: 1px -80px !important;\\n    margin-left: 15px;\\n}\\n\\n.fn-gantt .navigate .nav-now {\\n    background-position: 1px -32px !important;\\n}\\n\\n.fn-gantt .navigate .nav-slider .nav-now {\\n    margin-right: 5px;\\n}\\n\\n.fn-gantt-loader {\\n    position: absolute;\\n    width: 100%;\\n    height: 100%;\\n    left: 0;\\n    top: 0;\\n    filter: progid:DXImageTransform.Microsoft.gradient( startColorstr=\'#bf000000\', endColorstr=\'#bf000000\',GradientType=0 );\\n    background: rgba(0,0,0,0.75);\\n    cursor: wait;\\n    z-index: 30;\\n}\\n.fn-gantt-loader-spinner span {\\n    position: absolute;\\n    margin: auto;\\n    top: 0;\\n    right: 0;\\n    bottom: 0;\\n    left: 0;\\n    width: 100%;\\n    text-align: center;\\n    height: 1em;\\n    line-height: 1em;\\n    color: #fff;\\n    font-size: 1em;\\n    font-weight: bold;\\n}\\n\\n.row:after {\\n    clear: both;\\n}\\n\\n\\n/*--><!]]>*/\\n</style><div class=\\"gantt\\"></div>\\n",
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
      \'last_comment_timestamp\' => \'1418733726\',
      \'last_comment_name\' => NULL,
      \'last_comment_uid\' => \'1\',
      \'comment_count\' => \'0\',
      \'name\' => \'admin\',
      \'picture\' => \'0\',
      \'data\' => \'b:0;\',
      \'path\' => array(
        \'pid\' => \'36\',
        \'source\' => \'node/1674\',
        \'alias\' => \'content/ict-project-timelines\',
        \'language\' => \'und\',
      ),
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'1675\',
      \'uid\' => \'1\',
      \'title\' => \'ICT Project Budgets\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'1\',
      \'promote\' => \'0\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'358e5d58-366e-4add-9672-418e6ccafb80\',
      \'ds_switch\' => \'\',
      \'nid\' => \'1675\',
      \'type\' => \'page\',
      \'language\' => \'und\',
      \'created\' => \'1418733726\',
      \'changed\' => \'1418799996\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'ff1441b5-255b-465e-ba64-21149cc90807\',
      \'revision_timestamp\' => \'1418799996\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<style>\\r\\n.field-name-body {\\r\\nheight: auto;\\r\\nbackground-color: transparent;\\r\\nwidth: 100%;\\r\\n}\\r\\n.field-name-body:active {\\r\\nbackground-color: transparent;\\r\\n}\\r\\n\\r\\n#node-1674.content {\\r\\nheight: 400px;\\r\\n}\\r\\n\\r\\n     #chart {\\r\\n        width : 930px;\\r\\n        height: 384px;\\r\\n        margin: 8px auto;\\r\\n      }\\r\\n</style>\\r\\n\\r\\n\\r\\n    <div id=\\"chart\\"></div>\\r\\n\\r\\n<script>\\r\\n\\r\\njQuery(document).ready(function()\\r\\n{\\r\\n    d3.json(\\"/datastore_search_sql.js.php?sql=select+distinct+p.name%2C+total_value%2C+expected_total_value++FROM+%28select+name%2C+value+as+total_value+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+where+metric+%3D+%27total_project_budget%27+%29+p+full+outer+JOIN+++++%28select+DISTINCT+d.name%2C+d.value+as+expected_total_value+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+d+join+%28select+name%2Cmetric%2C+max%28timestamp%29+as+timestamp+++++from+%222133eaed-150b-4c73-a314-67a0bde04115%22+GROUP+BY+name%2Cmetric%29+s+on+d.metric%3Ds.metric+and+d.timestamp%3Ds.timestamp+++++where+d.metric+%3D+%27current_total_expected_budget%27%29+b+on+p.name+%3D+b.name%3B\\",\\r\\n        function(error, data) {\\r\\n            project_names = [];\\r\\n            project_orig_budget = [];\\r\\n            project_current_budget = [];\\r\\n\\r\\n            for (var i in data.result.records) {\\r\\n                d =  data.result.records[i]\\r\\n                project_names[parseInt(i)] = d.name;\\r\\n                project_orig_budget.push([parseInt(i),parseInt(d.total_value) || 0]);\\r\\n                project_current_budget.push([parseInt(i)+0.5,parseInt(d.expected_total_value) || 0]);\\r\\n            }\\r\\n\\r\\n       var\\r\\n          container = document.getElementById(\'chart\'),\\r\\n          graph, i;\\r\\n  function ticksFn (n) { \\r\\nreturn project_names[parseInt(n)]; \\r\\n}\\r\\nfunction hoverFn (obj){\\r\\nreturn project_names[parseInt(obj.x)] +\', \'+obj.series.label+\': $\'+obj.y+\'m\';\\r\\n  }\\r\\n        // Draw Graph\\r\\n        graph = Flotr.draw(container, [ {data: project_orig_budget, label: \\"Original Budget\\"}, {data: project_current_budget, label: \\"Current Budget\\"} ], {\\r\\n      bars : {\\r\\n        show : true,\\r\\nbarWidth: 0.4\\r\\n},\\r\\n      legend : {\\r\\n        position : \'nw\'\\r\\n      },\\r\\nmouse : {\\r\\n        track : true,\\r\\n        relative : true,\\r\\ntrackFormatter: hoverFn\\r\\n      },\\r\\nxaxis: {\\r\\ntickFormatter : ticksFn,\\r\\n},\\r\\n      yaxis : {\\r\\n        min : 0,\\r\\n        autoscaleMargin : 1\\r\\n      },\\r\\n      title : \'\'  });\\r\\n});\\r\\n});\\r\\n\\r\\n</script>\\r\\n",
            \'summary\' => \'\',
            \'format\' => \'full_html\',
            \'safe_value\' => "<style>\\n<!--/*--><![CDATA[/* ><!--*/\\n\\n.field-name-body {\\nheight: auto;\\nbackground-color: transparent;\\nwidth: 100%;\\n}\\n.field-name-body:active {\\nbackground-color: transparent;\\n}\\n\\n#node-1674.content {\\nheight: 400px;\\n}\\n\\n     #chart {\\n        width : 930px;\\n        height: 384px;\\n        margin: 8px auto;\\n      }\\n\\n/*--><!]]>*/\\n</style><div id=\\"chart\\"></div>\\n<script>\\n<!--//--><![CDATA[// ><!--\\n\\n\\njQuery(document).ready(function()\\n{\\n    d3.json(\\"/datastore_search_sql.js.php?sql=select+distinct+p.name%2C+total_value%2C+expected_total_value++FROM+%28select+name%2C+value+as+total_value+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+where+metric+%3D+%27total_project_budget%27+%29+p+full+outer+JOIN+++++%28select+DISTINCT+d.name%2C+d.value+as+expected_total_value+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+d+join+%28select+name%2Cmetric%2C+max%28timestamp%29+as+timestamp+++++from+%222133eaed-150b-4c73-a314-67a0bde04115%22+GROUP+BY+name%2Cmetric%29+s+on+d.metric%3Ds.metric+and+d.timestamp%3Ds.timestamp+++++where+d.metric+%3D+%27current_total_expected_budget%27%29+b+on+p.name+%3D+b.name%3B\\",\\n        function(error, data) {\\n            project_names = [];\\n            project_orig_budget = [];\\n            project_current_budget = [];\\n\\n            for (var i in data.result.records) {\\n                d =  data.result.records[i]\\n                project_names[parseInt(i)] = d.name;\\n                project_orig_budget.push([parseInt(i),parseInt(d.total_value) || 0]);\\n                project_current_budget.push([parseInt(i)+0.5,parseInt(d.expected_total_value) || 0]);\\n            }\\n\\n       var\\n          container = document.getElementById(\'chart\'),\\n          graph, i;\\n  function ticksFn (n) { \\nreturn project_names[parseInt(n)]; \\n}\\nfunction hoverFn (obj){\\nreturn project_names[parseInt(obj.x)] +\', \'+obj.series.label+\': $\'+obj.y+\'m\';\\n  }\\n        // Draw Graph\\n        graph = Flotr.draw(container, [ {data: project_orig_budget, label: \\"Original Budget\\"}, {data: project_current_budget, label: \\"Current Budget\\"} ], {\\n      bars : {\\n        show : true,\\nbarWidth: 0.4\\n},\\n      legend : {\\n        position : \'nw\'\\n      },\\nmouse : {\\n        track : true,\\n        relative : true,\\ntrackFormatter: hoverFn\\n      },\\nxaxis: {\\ntickFormatter : ticksFn,\\n},\\n      yaxis : {\\n        min : 0,\\n        autoscaleMargin : 1\\n      },\\n      title : \'\'  });\\n});\\n});\\n\\n\\n//--><!]]>\\n</script>",
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
      \'last_comment_timestamp\' => \'1418733726\',
      \'last_comment_name\' => NULL,
      \'last_comment_uid\' => \'1\',
      \'comment_count\' => \'0\',
      \'name\' => \'admin\',
      \'picture\' => \'0\',
      \'data\' => \'b:0;\',
      \'path\' => array(
        \'pid\' => \'37\',
        \'source\' => \'node/1675\',
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
