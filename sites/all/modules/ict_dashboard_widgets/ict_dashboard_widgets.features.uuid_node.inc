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
  'created' => 1418733726,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '5436dc7d-c224-44a2-9db4-02091f155065',
  'revision_uid' => 1,
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<p class="dashboard-description">The ICT Project Treemap compares how each of the major projects compare with each other according to either the total project value or number of projects being delivered by agencies.</p>

<style type="text/css">

    .chart {
        display: block;
        margin: auto;
        margin-top: 40px;
    }
#treemap {
width: 930px;
}

    text {
        font-size: 11px;
    }

    rect {
        fill: none;
    }

</style>
        <div><select class="treemap">
                <option value="size">Value of Projects</option>
                <option value="count">Number of Projects</option>
            </select></div>
<div id="treemap"></div>
<script type="text/javascript">
    var w = 930 - 80,
        h = 800 - 180,
        x = d3.scale.linear().range([0, w]),
        y = d3.scale.linear().range([0, h]),
        color = d3.scale.category20c(),
        root,
        node;
jQuery(document).ready(function()
{
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

    var treemap = d3.layout.treemap()
        .round(false)
        .size([w, h])
        .sticky(true)
        .value(function(d) { return d.size; });

    var svg = d3.select("#treemap").append("div")
        .attr("class", "chart")
        .style("width", w + "px")
        .style("height", h + "px")
        .append("svg:svg")
        .attr("width", w)
        .attr("height", h)
        .append("svg:g")
        .attr("transform", "translate(.5,.5)");
    d3.json("/datastore_search_sql.js.php?sql=SELECT%20*%20from%20%222133eaed-150b-4c73-a314-67a0bde04115%22%20WHERE%20metric%20%3D%20%27total_project_budget%27",
        function(error, data) {
            datum = {
                "name": "flare",
                "children": data.result.records.map(function (d) {
                return {name: d.name, size: d.value};
            })
            };
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
            .style("fill", function(d) { return color(d.size); });

        cell.append("svg:text")
            .attr("x", function(d) { return d.dx / 2; })
            .attr("y", function(d) { return d.dy / 2; })
            .attr("dy", ".35em")
            .attr("text-anchor", "middle")
            .text(function(d) { return d.name; })
            .style("opacity", function(d) { d.w = this.getComputedTextLength(); return d.dx > d.w ? 1 : 0; });

        d3.select(window).on("click", function() { zoom(root); });

        d3.select("select.treemap").on("change", function() {
            treemap.value(this.value == "size" ? size : count).nodes(root);
            zoom(node);
        });
    });
});


</script>
',
        'summary' => '',
        'format' => 'full_html',
        'safe_value' => '<p class="dashboard-description">The ICT Project Treemap compares how each of the major projects compare with each other according to either the total project value or number of projects being delivered by agencies.</p>
<style type="text/css">
<!--/*--><![CDATA[/* ><!--*/


    .chart {
        display: block;
        margin: auto;
        margin-top: 40px;
    }
#treemap {
width: 930px;
}

    text {
        font-size: 11px;
    }

    rect {
        fill: none;
    }


/*--><!]]>*/
</style><div>
<select class="treemap"><option value="size">Value of Projects</option><br /><option value="count">Number of Projects</option><br /></select></div>
<div id="treemap"></div>
<script type="text/javascript">
<!--//--><![CDATA[// ><!--

    var w = 930 - 80,
        h = 800 - 180,
        x = d3.scale.linear().range([0, w]),
        y = d3.scale.linear().range([0, h]),
        color = d3.scale.category20c(),
        root,
        node;
jQuery(document).ready(function()
{
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

    var treemap = d3.layout.treemap()
        .round(false)
        .size([w, h])
        .sticky(true)
        .value(function(d) { return d.size; });

    var svg = d3.select("#treemap").append("div")
        .attr("class", "chart")
        .style("width", w + "px")
        .style("height", h + "px")
        .append("svg:svg")
        .attr("width", w)
        .attr("height", h)
        .append("svg:g")
        .attr("transform", "translate(.5,.5)");
    d3.json("/datastore_search_sql.js.php?sql=SELECT%20*%20from%20%222133eaed-150b-4c73-a314-67a0bde04115%22%20WHERE%20metric%20%3D%20%27total_project_budget%27",
        function(error, data) {
            datum = {
                "name": "flare",
                "children": data.result.records.map(function (d) {
                return {name: d.name, size: d.value};
            })
            };
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
            .style("fill", function(d) { return color(d.size); });

        cell.append("svg:text")
            .attr("x", function(d) { return d.dx / 2; })
            .attr("y", function(d) { return d.dy / 2; })
            .attr("dy", ".35em")
            .attr("text-anchor", "middle")
            .text(function(d) { return d.name; })
            .style("opacity", function(d) { d.w = this.getComputedTextLength(); return d.dx > d.w ? 1 : 0; });

        d3.select(window).on("click", function() { zoom(root); });

        d3.select("select.treemap").on("change", function() {
            treemap.value(this.value == "size" ? size : count).nodes(root);
            zoom(node);
        });
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
  'date' => '2014-12-16 23:42:06 +1100',
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
  'created' => 1418733726,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '8754ca37-1410-4671-bb58-ce670b640f5d',
  'revision_uid' => 1,
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<p class="dashboard-description">The ICT Project Timelines provides a high level overview of original predicted and actual project schedules. </p>   
 <script type="text/javascript">

jQuery(document).ready(function () {
    var source = [];
var color = [\'Red\',\'Green\',\'Orange\'];
    d3.json("/datastore_search_sql.js.php?sql=select+distinct+p.name%2C+start_date%2C+end_date%2C+expected_end_date%2C+total_value%2C+expected_total_value%0AFROM+%28select+name%2C+value+as+start_date+from%222133eaed-150b-4c73-a314-67a0bde04115%22+where+metric+%3D+%27original_completion_date%27++%29+p+full+outer+JOIN%0A++%28select+name%2C+value+as+end_date+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+where+metric+%3D+%27start_date%27+%29+a+on+p.name+%3D+a.name+full+outer+JOIN%0A++%28select+name%2C+value+as+total_value+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+where+metric+%3D+%27total_project_budget%27+%29+v+on+p.name+%3D+v.name+full+outer+JOIN%0A++%28select+DISTINCT+d.name%2C+d.value+as+expected_end_date+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+d+join+%28select+name%2Cmetric%2C+max%28timestamp%29+as+timestamp%0Afrom+%222133eaed-150b-4c73-a314-67a0bde04115%22+GROUP+BY+name%2Cmetric%29+s+on+d.metric%3Ds.metric+and+d.timestamp%3Ds.timestamp%0Awhere+d.metric+%3D+%27current_expected_completion_date%27%29+c+on+p.name+%3D+c.name+full+outer+JOIN%0A++%28select+DISTINCT+d.name%2C+d.value+as+expected_total_value+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+d+join+%28select+name%2Cmetric%2C+max%28timestamp%29+as+timestamp%0Afrom+%222133eaed-150b-4c73-a314-67a0bde04115%22+GROUP+BY+name%2Cmetric%29+s+on+d.metric%3Ds.metric+and+d.timestamp%3Ds.timestamp%0Awhere+d.metric+%3D+%27current_total_expected_budget%27%29+b+on+p.name+%3D+b.name+",
        function (error, data) {
            for (var i in data.result.records) {
                d = data.result.records[i];
                starting_time = new Date(moment(d.start_date)).getTime();
                ending_time = new Date(moment(d.end_date)).getTime();
                expected_ending_time = new Date(moment(d.expected_end_date)).getTime();

                source.push({
                    name: d.name,
                    desc: "",
                    values: [{
                        from: starting_time,
                        to: expected_ending_time,
                        label: d.name,
                        customClass: "gantt" + color[i%3]
                    }]
                });
            }

            jQuery(".gantt").gantt({
                source: source,
                navigate: "scroll",
                minScale: "months",
                maxScale: "years",
                itemsPerPage: 10,
                
                onRender: function () {
                    if (window.console && typeof console.log === "function") {
                        console.log("chart rendered");
                    }
                }
            });
// window.setTimeout(function() {jQuery(\'.nav-zoomIn\')[0].click();}, 800);
        });
});
    </script>
<style>
.gantt, .gantt2 {
    width: 930px;
    margin: 20px auto;
    border: 14px solid #ddd;
    position: relative;
        -webkit-border-radius: 6px;
        -moz-border-radius: 6px;
        border-radius: 6px;
            -webkit-box-sizing: border-box;
            -moz-box-sizing: border-box;
            box-sizing: border-box;
}

.gantt:after {
    content: ".";
    visibility: hidden;
    display: block;
    height: 0;
    clear: both;
}

.fn-gantt {
    width: 100%;Hunter Connection
}

.fn-gantt .fn-content {
    overflow: hidden;
    position: relative;
    width: 100%;
}




/* === LEFT PANEL === */

.fn-gantt .leftPanel {
    float: left;
    width: 225px;
    overflow: hidden;
    border-right: 1px solid #DDD;
    position: relative;
    z-index: 20;
background-color: #f6f6f6;
}

.fn-gantt .row {
    float: left;
    height: 24px;
    line-height: 24px;
    margin-left: -1px;
}
.header .fn-label {background-color: #f6f6f6 !important;}

.fn-gantt .leftPanel .fn-label {
    display: inline-block;
    margin: 0 0 0 5px;
    color: #484A4D;
    width: 110px;
    white-space: nowrap;
    text-overflow: ellipsis;
    overflow: hidden;
}

.fn-gantt .leftPanel .row0 {
    border-top: 1px solid #DDD;
}
.fn-gantt .leftPanel .name, .fn-gantt .leftPanel .desc {
    float: left;
    height: 23px;
    margin: 0;
    border-bottom: 1px solid #DDD;
    background-color: #f6f6f6;
}

.fn-gantt .leftPanel .name {
    width: 110px;
    font-weight: bold;
}

.fn-gantt .leftPanel .desc {
    width: 114px;
}

.fn-gantt .leftPanel .fn-wide, .fn-gantt .leftPanel .fn-wide .fn-label {
    width: 225px;
}

.fn-gantt .spacer {
    margin: -2px 0 1px 0;
    border-bottom: none;
    background-color: #f6f6f6;
}




/* === RIGHT PANEL === */

.fn-gantt .rightPanel {
    overflow: hidden;
}

.fn-gantt .dataPanel {
    margin-left: 0px;
    border-right: 1px solid #DDD;
    background-image: url(/sites/all/themes/itdash/js/grid.png);
    background-repeat: repeat;
    background-position: 24px 24px;
    position: relative;
}
.fn-gantt .day, .fn-gantt .date {
    overflow: visible;
    width: 24px;
    line-height: 24px;
    text-align: center;
    border-left: 1px solid #DDD;
    border-bottom: 1px solid #DDD;
    margin: -1px 0 0 -1px;
    font-size: 11px;
    color: #484a4d;
    text-shadow: 0 1px 0 rgba(255,255,255,0.75);
    text-align: center;
}

.fn-gantt .holiday {
    background-color: #ffd263;
    height: 23px;
    margin: 0 0 -1px -1px;
}

.fn-gantt .today {
    background-color: #fff8da;
    height: 23px;
    margin: 0 0 -1px -1px;
    font-weight: bold;
    text-align: center;
}

.fn-gantt .sa, .fn-gantt .sn, .fn-gantt .wd {
    height: 23px;
    margin: 0 0 0 -1px;
    text-align: center;
}

.fn-gantt .sa, .fn-gantt .sn {
    color: #939496;
    background-color: #f5f5f5;
    text-align: center;
}

.fn-gantt .wd {
    background-color: #f6f6f6;
    text-align: center;
}

.fn-gantt .rightPanel .month, .fn-gantt .rightPanel .year {
    float: left;
    overflow: hidden;
    border-left: 1px solid #DDD;
    border-bottom: 1px solid #DDD;
    height: 23px;
    margin: 0 0 0 -1px;
    background-color: #f6f6f6;
    font-weight: bold;
    font-size: 11px;
    color: #484a4d;
    text-shadow: 0 1px 0 rgba(255,255,255,0.75);
    text-align: center;
}

.fn-gantt-hint {
    border: 5px solid #edc332;
    background-color: #fff5d4;
    padding: 10px;
    position: absolute;
    display: none;
    z-index: 11;
        -webkit-border-radius: 4px;
        -moz-border-radius: 4px;
        border-radius: 4px;
}

.fn-gantt .bar {
    background-color: #D0E4FD;
    height: 18px;
    margin: 0px 3px 3px 0px;
    position: absolute;
    z-index: 10;
    text-align: center;
        -webkit-box-shadow: 0 0 1px rgba(0,0,0,0.25) inset;
        -moz-box-shadow: 0 0 1px rgba(0,0,0,0.25) inset;
        box-shadow: 0 0 1px rgba(0,0,0,0.25) inset;
            -webkit-border-radius: 3px;
            -moz-border-radius: 3px;
            border-radius: 3px;
}

.fn-gantt .bar .fn-label {
    line-height: 18px;
    font-weight: bold;
    white-space: nowrap;
    width: 110px;
    text-overflow: ellipsis;
    overflow: hidden;
    text-shadow: 0 1px 0 rgba(255,255,255,0.4);
    color: #414B57 !important;
    text-align: center;
    font-size: 11px;
}

.fn-gantt .ganttRed {
    background-color: #F9C4E1;
}
.fn-gantt .ganttRed .fn-label {
    color: #78436D !important;
}

.fn-gantt .ganttGreen {
    background-color: #D8EDA3;
}
.fn-gantt .ganttGreen .fn-label {
    color: #778461 !important;
}

.fn-gantt .ganttOrange {
    background-color: #FCD29A;
}
.fn-gantt .ganttOrange .fn-label {
    color: #714715 !important;
}


/* === BOTTOM NAVIGATION === */

.fn-gantt .bottom {
    clear: both;
    background-color: #f6f6f6;
    width: 100%;
}
.fn-gantt .navigate {
    border-top: 1px solid #DDD;
    padding: 10px 0 10px 225px;
}

.fn-gantt .navigate .nav-slider {
    height: 20px;
    display: inline-block;
}

.fn-gantt .navigate .nav-slider-left, .fn-gantt .navigate .nav-slider-right {
    text-align: center;
    height: 20px;
    display: inline-block;
}

.fn-gantt .navigate .nav-slider-left {
    float: left;
}

.fn-gantt .navigate .nav-slider-right {
    float: right;
}

.fn-gantt .navigate .nav-slider-content {
    text-align: left;
    width: 160px;
    height: 20px;
    display: inline-block;
    margin: 0 10px;
}

.fn-gantt .navigate .nav-slider-bar, .fn-gantt .navigate .nav-slider-button {
    position: absolute;
    display: block;
}

.fn-gantt .navigate .nav-slider-bar {
    width: 155px;
    height: 6px;
    background-color: #838688;
    margin: 8px 0 0 0;
        -webkit-box-shadow: 0 1px 3px rgba(0,0,0,0.6) inset;
        -moz-box-shadow: 0 1px 3px rgba(0,0,0,0.6) inset;
        box-shadow: 0 1px 3px rgba(0,0,0,0.6) inset;
            -webkit-border-radius: 3px;
            -moz-border-radius: 3px;
            border-radius: 3px;
}

.fn-gantt .navigate .nav-slider-button {
    width: 17px;
    height: 60px;
    background: url(/sites/all/themes/itdash/js/slider_handle.png) center center no-repeat;
    left: 0px;
    top: 0px;
    margin: -26px 0 0 0;
    cursor: pointer;
}

.fn-gantt .navigate .page-number {
    display: inline-block;
    font-size: 10px;
    height: 20px;
}

.fn-gantt .navigate .page-number span {
    color: #666666;
    margin: 0 6px;
    height: 20px;
    line-height: 20px;
    display: inline-block;
}

.fn-gantt .navigate a:link, .fn-gantt .navigate a:visited, .fn-gantt .navigate a:active {
    text-decoration: none;
}

.fn-gantt .nav-link {
    margin: 0 3px 0 0;
    display: inline-block;
    width: 20px;
    height: 20px;
    font-size: 0px;
    background: #595959 url(/sites/all/themes/itdash/js/icon_sprite.png) !important;
    border: 1px solid #454546;
    cursor: pointer;
    vertical-align: top;
        -webkit-border-radius: 2px;
        -moz-border-radius: 2px;
        border-radius: 2px;
            -webkit-box-shadow: 0 1px 0 rgba(255,255,255,0.1) inset, 0 1px 1px rgba(0,0,0,0.2);
            -moz-box-shadow: 0 1px 0 rgba(255,255,255,0.1) inset, 0 1px 1px rgba(0,0,0,0.2);
            box-shadow: 0 1px 0 rgba(255,255,255,0.1) inset, 0 1px 1px rgba(0,0,0,0.2);
                -webkit-box-sizing: border-box;
                -moz-box-sizing: border-box;
                box-sizing: border-box;
}
.fn-gantt .nav-link:active {
    -webkit-box-shadow: 0 1px 1px rgba(0,0,0,0.25) inset, 0 1px 0 #FFF;
    -moz-box-shadow: 0 1px 1px rgba(0,0,0,0.25) inset, 0 1px 0 #FFF;
    box-shadow: 0 1px 1px rgba(0,0,0,0.25) inset, 0 1px 0 #FFF;
}

.fn-gantt .navigate .nav-page-back {
    background-position: 1px 0 !important;
    margin: 0;
}

.fn-gantt .navigate .nav-page-next {
    background-position: 1px -16px !important;
    margin-right: 15px;
}

.fn-gantt .navigate .nav-slider .nav-page-next {
    margin-right: 5px;
}

.fn-gantt .navigate .nav-begin {
    background-position: 1px -112px !important;
}

.fn-gantt .navigate .nav-prev-week {
    background-position: 1px -128px !important;
}

.fn-gantt .navigate .nav-prev-day {
    background-position: 1px -48px !important;
}

.fn-gantt .navigate .nav-next-day {
    background-position: 1px -64px !important;
}

.fn-gantt .navigate .nav-next-week {
    background-position: 1px -160px !important;
}

.fn-gantt .navigate .nav-end {
    background-position: 1px -144px !important;
}

.fn-gantt .navigate .nav-zoomOut {
    background-position: 1px -96px !important;
}

.fn-gantt .navigate .nav-zoomIn {
    background-position: 1px -80px !important;
    margin-left: 15px;
}

.fn-gantt .navigate .nav-now {
    background-position: 1px -32px !important;
}

.fn-gantt .navigate .nav-slider .nav-now {
    margin-right: 5px;
}

.fn-gantt-loader {
    position: absolute;
    width: 100%;
    height: 100%;
    left: 0;
    top: 0;
    filter: progid:DXImageTransform.Microsoft.gradient( startColorstr=\'#bf000000\', endColorstr=\'#bf000000\',GradientType=0 );
    background: rgba(0,0,0,0.75);
    cursor: wait;
    z-index: 30;
}
.fn-gantt-loader-spinner span {
    position: absolute;
    margin: auto;
    top: 0;
    right: 0;
    bottom: 0;
    left: 0;
    width: 100%;
    text-align: center;
    height: 1em;
    line-height: 1em;
    color: #fff;
    font-size: 1em;
    font-weight: bold;
}

.row:after {
    clear: both;
}

</style>
<div class="gantt"></div>',
        'summary' => '',
        'format' => 'full_html',
        'safe_value' => '<p class="dashboard-description">The ICT Project Timelines provides a high level overview of original predicted and actual project schedules. </p>
<script type="text/javascript">
<!--//--><![CDATA[// ><!--


jQuery(document).ready(function () {
    var source = [];
var color = [\'Red\',\'Green\',\'Orange\'];
    d3.json("/datastore_search_sql.js.php?sql=select+distinct+p.name%2C+start_date%2C+end_date%2C+expected_end_date%2C+total_value%2C+expected_total_value%0AFROM+%28select+name%2C+value+as+start_date+from%222133eaed-150b-4c73-a314-67a0bde04115%22+where+metric+%3D+%27original_completion_date%27++%29+p+full+outer+JOIN%0A++%28select+name%2C+value+as+end_date+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+where+metric+%3D+%27start_date%27+%29+a+on+p.name+%3D+a.name+full+outer+JOIN%0A++%28select+name%2C+value+as+total_value+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+where+metric+%3D+%27total_project_budget%27+%29+v+on+p.name+%3D+v.name+full+outer+JOIN%0A++%28select+DISTINCT+d.name%2C+d.value+as+expected_end_date+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+d+join+%28select+name%2Cmetric%2C+max%28timestamp%29+as+timestamp%0Afrom+%222133eaed-150b-4c73-a314-67a0bde04115%22+GROUP+BY+name%2Cmetric%29+s+on+d.metric%3Ds.metric+and+d.timestamp%3Ds.timestamp%0Awhere+d.metric+%3D+%27current_expected_completion_date%27%29+c+on+p.name+%3D+c.name+full+outer+JOIN%0A++%28select+DISTINCT+d.name%2C+d.value+as+expected_total_value+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+d+join+%28select+name%2Cmetric%2C+max%28timestamp%29+as+timestamp%0Afrom+%222133eaed-150b-4c73-a314-67a0bde04115%22+GROUP+BY+name%2Cmetric%29+s+on+d.metric%3Ds.metric+and+d.timestamp%3Ds.timestamp%0Awhere+d.metric+%3D+%27current_total_expected_budget%27%29+b+on+p.name+%3D+b.name+",
        function (error, data) {
            for (var i in data.result.records) {
                d = data.result.records[i];
                starting_time = new Date(moment(d.start_date)).getTime();
                ending_time = new Date(moment(d.end_date)).getTime();
                expected_ending_time = new Date(moment(d.expected_end_date)).getTime();

                source.push({
                    name: d.name,
                    desc: "",
                    values: [{
                        from: starting_time,
                        to: expected_ending_time,
                        label: d.name,
                        customClass: "gantt" + color[i%3]
                    }]
                });
            }

            jQuery(".gantt").gantt({
                source: source,
                navigate: "scroll",
                minScale: "months",
                maxScale: "years",
                itemsPerPage: 10,
                
                onRender: function () {
                    if (window.console && typeof console.log === "function") {
                        console.log("chart rendered");
                    }
                }
            });
// window.setTimeout(function() {jQuery(\'.nav-zoomIn\')[0].click();}, 800);
        });
});
    
//--><!]]>
</script><style>
<!--/*--><![CDATA[/* ><!--*/

.gantt, .gantt2 {
    width: 930px;
    margin: 20px auto;
    border: 14px solid #ddd;
    position: relative;
        -webkit-border-radius: 6px;
        -moz-border-radius: 6px;
        border-radius: 6px;
            -webkit-box-sizing: border-box;
            -moz-box-sizing: border-box;
            box-sizing: border-box;
}

.gantt:after {
    content: ".";
    visibility: hidden;
    display: block;
    height: 0;
    clear: both;
}

.fn-gantt {
    width: 100%;Hunter Connection
}

.fn-gantt .fn-content {
    overflow: hidden;
    position: relative;
    width: 100%;
}




/* === LEFT PANEL === */

.fn-gantt .leftPanel {
    float: left;
    width: 225px;
    overflow: hidden;
    border-right: 1px solid #DDD;
    position: relative;
    z-index: 20;
background-color: #f6f6f6;
}

.fn-gantt .row {
    float: left;
    height: 24px;
    line-height: 24px;
    margin-left: -1px;
}
.header .fn-label {background-color: #f6f6f6 !important;}

.fn-gantt .leftPanel .fn-label {
    display: inline-block;
    margin: 0 0 0 5px;
    color: #484A4D;
    width: 110px;
    white-space: nowrap;
    text-overflow: ellipsis;
    overflow: hidden;
}

.fn-gantt .leftPanel .row0 {
    border-top: 1px solid #DDD;
}
.fn-gantt .leftPanel .name, .fn-gantt .leftPanel .desc {
    float: left;
    height: 23px;
    margin: 0;
    border-bottom: 1px solid #DDD;
    background-color: #f6f6f6;
}

.fn-gantt .leftPanel .name {
    width: 110px;
    font-weight: bold;
}

.fn-gantt .leftPanel .desc {
    width: 114px;
}

.fn-gantt .leftPanel .fn-wide, .fn-gantt .leftPanel .fn-wide .fn-label {
    width: 225px;
}

.fn-gantt .spacer {
    margin: -2px 0 1px 0;
    border-bottom: none;
    background-color: #f6f6f6;
}




/* === RIGHT PANEL === */

.fn-gantt .rightPanel {
    overflow: hidden;
}

.fn-gantt .dataPanel {
    margin-left: 0px;
    border-right: 1px solid #DDD;
    background-image: url(/sites/all/themes/itdash/js/grid.png);
    background-repeat: repeat;
    background-position: 24px 24px;
    position: relative;
}
.fn-gantt .day, .fn-gantt .date {
    overflow: visible;
    width: 24px;
    line-height: 24px;
    text-align: center;
    border-left: 1px solid #DDD;
    border-bottom: 1px solid #DDD;
    margin: -1px 0 0 -1px;
    font-size: 11px;
    color: #484a4d;
    text-shadow: 0 1px 0 rgba(255,255,255,0.75);
    text-align: center;
}

.fn-gantt .holiday {
    background-color: #ffd263;
    height: 23px;
    margin: 0 0 -1px -1px;
}

.fn-gantt .today {
    background-color: #fff8da;
    height: 23px;
    margin: 0 0 -1px -1px;
    font-weight: bold;
    text-align: center;
}

.fn-gantt .sa, .fn-gantt .sn, .fn-gantt .wd {
    height: 23px;
    margin: 0 0 0 -1px;
    text-align: center;
}

.fn-gantt .sa, .fn-gantt .sn {
    color: #939496;
    background-color: #f5f5f5;
    text-align: center;
}

.fn-gantt .wd {
    background-color: #f6f6f6;
    text-align: center;
}

.fn-gantt .rightPanel .month, .fn-gantt .rightPanel .year {
    float: left;
    overflow: hidden;
    border-left: 1px solid #DDD;
    border-bottom: 1px solid #DDD;
    height: 23px;
    margin: 0 0 0 -1px;
    background-color: #f6f6f6;
    font-weight: bold;
    font-size: 11px;
    color: #484a4d;
    text-shadow: 0 1px 0 rgba(255,255,255,0.75);
    text-align: center;
}

.fn-gantt-hint {
    border: 5px solid #edc332;
    background-color: #fff5d4;
    padding: 10px;
    position: absolute;
    display: none;
    z-index: 11;
        -webkit-border-radius: 4px;
        -moz-border-radius: 4px;
        border-radius: 4px;
}

.fn-gantt .bar {
    background-color: #D0E4FD;
    height: 18px;
    margin: 0px 3px 3px 0px;
    position: absolute;
    z-index: 10;
    text-align: center;
        -webkit-box-shadow: 0 0 1px rgba(0,0,0,0.25) inset;
        -moz-box-shadow: 0 0 1px rgba(0,0,0,0.25) inset;
        box-shadow: 0 0 1px rgba(0,0,0,0.25) inset;
            -webkit-border-radius: 3px;
            -moz-border-radius: 3px;
            border-radius: 3px;
}

.fn-gantt .bar .fn-label {
    line-height: 18px;
    font-weight: bold;
    white-space: nowrap;
    width: 110px;
    text-overflow: ellipsis;
    overflow: hidden;
    text-shadow: 0 1px 0 rgba(255,255,255,0.4);
    color: #414B57 !important;
    text-align: center;
    font-size: 11px;
}

.fn-gantt .ganttRed {
    background-color: #F9C4E1;
}
.fn-gantt .ganttRed .fn-label {
    color: #78436D !important;
}

.fn-gantt .ganttGreen {
    background-color: #D8EDA3;
}
.fn-gantt .ganttGreen .fn-label {
    color: #778461 !important;
}

.fn-gantt .ganttOrange {
    background-color: #FCD29A;
}
.fn-gantt .ganttOrange .fn-label {
    color: #714715 !important;
}


/* === BOTTOM NAVIGATION === */

.fn-gantt .bottom {
    clear: both;
    background-color: #f6f6f6;
    width: 100%;
}
.fn-gantt .navigate {
    border-top: 1px solid #DDD;
    padding: 10px 0 10px 225px;
}

.fn-gantt .navigate .nav-slider {
    height: 20px;
    display: inline-block;
}

.fn-gantt .navigate .nav-slider-left, .fn-gantt .navigate .nav-slider-right {
    text-align: center;
    height: 20px;
    display: inline-block;
}

.fn-gantt .navigate .nav-slider-left {
    float: left;
}

.fn-gantt .navigate .nav-slider-right {
    float: right;
}

.fn-gantt .navigate .nav-slider-content {
    text-align: left;
    width: 160px;
    height: 20px;
    display: inline-block;
    margin: 0 10px;
}

.fn-gantt .navigate .nav-slider-bar, .fn-gantt .navigate .nav-slider-button {
    position: absolute;
    display: block;
}

.fn-gantt .navigate .nav-slider-bar {
    width: 155px;
    height: 6px;
    background-color: #838688;
    margin: 8px 0 0 0;
        -webkit-box-shadow: 0 1px 3px rgba(0,0,0,0.6) inset;
        -moz-box-shadow: 0 1px 3px rgba(0,0,0,0.6) inset;
        box-shadow: 0 1px 3px rgba(0,0,0,0.6) inset;
            -webkit-border-radius: 3px;
            -moz-border-radius: 3px;
            border-radius: 3px;
}

.fn-gantt .navigate .nav-slider-button {
    width: 17px;
    height: 60px;
    background: url(/sites/all/themes/itdash/js/slider_handle.png) center center no-repeat;
    left: 0px;
    top: 0px;
    margin: -26px 0 0 0;
    cursor: pointer;
}

.fn-gantt .navigate .page-number {
    display: inline-block;
    font-size: 10px;
    height: 20px;
}

.fn-gantt .navigate .page-number span {
    color: #666666;
    margin: 0 6px;
    height: 20px;
    line-height: 20px;
    display: inline-block;
}

.fn-gantt .navigate a:link, .fn-gantt .navigate a:visited, .fn-gantt .navigate a:active {
    text-decoration: none;
}

.fn-gantt .nav-link {
    margin: 0 3px 0 0;
    display: inline-block;
    width: 20px;
    height: 20px;
    font-size: 0px;
    background: #595959 url(/sites/all/themes/itdash/js/icon_sprite.png) !important;
    border: 1px solid #454546;
    cursor: pointer;
    vertical-align: top;
        -webkit-border-radius: 2px;
        -moz-border-radius: 2px;
        border-radius: 2px;
            -webkit-box-shadow: 0 1px 0 rgba(255,255,255,0.1) inset, 0 1px 1px rgba(0,0,0,0.2);
            -moz-box-shadow: 0 1px 0 rgba(255,255,255,0.1) inset, 0 1px 1px rgba(0,0,0,0.2);
            box-shadow: 0 1px 0 rgba(255,255,255,0.1) inset, 0 1px 1px rgba(0,0,0,0.2);
                -webkit-box-sizing: border-box;
                -moz-box-sizing: border-box;
                box-sizing: border-box;
}
.fn-gantt .nav-link:active {
    -webkit-box-shadow: 0 1px 1px rgba(0,0,0,0.25) inset, 0 1px 0 #FFF;
    -moz-box-shadow: 0 1px 1px rgba(0,0,0,0.25) inset, 0 1px 0 #FFF;
    box-shadow: 0 1px 1px rgba(0,0,0,0.25) inset, 0 1px 0 #FFF;
}

.fn-gantt .navigate .nav-page-back {
    background-position: 1px 0 !important;
    margin: 0;
}

.fn-gantt .navigate .nav-page-next {
    background-position: 1px -16px !important;
    margin-right: 15px;
}

.fn-gantt .navigate .nav-slider .nav-page-next {
    margin-right: 5px;
}

.fn-gantt .navigate .nav-begin {
    background-position: 1px -112px !important;
}

.fn-gantt .navigate .nav-prev-week {
    background-position: 1px -128px !important;
}

.fn-gantt .navigate .nav-prev-day {
    background-position: 1px -48px !important;
}

.fn-gantt .navigate .nav-next-day {
    background-position: 1px -64px !important;
}

.fn-gantt .navigate .nav-next-week {
    background-position: 1px -160px !important;
}

.fn-gantt .navigate .nav-end {
    background-position: 1px -144px !important;
}

.fn-gantt .navigate .nav-zoomOut {
    background-position: 1px -96px !important;
}

.fn-gantt .navigate .nav-zoomIn {
    background-position: 1px -80px !important;
    margin-left: 15px;
}

.fn-gantt .navigate .nav-now {
    background-position: 1px -32px !important;
}

.fn-gantt .navigate .nav-slider .nav-now {
    margin-right: 5px;
}

.fn-gantt-loader {
    position: absolute;
    width: 100%;
    height: 100%;
    left: 0;
    top: 0;
    filter: progid:DXImageTransform.Microsoft.gradient( startColorstr=\'#bf000000\', endColorstr=\'#bf000000\',GradientType=0 );
    background: rgba(0,0,0,0.75);
    cursor: wait;
    z-index: 30;
}
.fn-gantt-loader-spinner span {
    position: absolute;
    margin: auto;
    top: 0;
    right: 0;
    bottom: 0;
    left: 0;
    width: 100%;
    text-align: center;
    height: 1em;
    line-height: 1em;
    color: #fff;
    font-size: 1em;
    font-weight: bold;
}

.row:after {
    clear: both;
}


/*--><!]]>*/
</style><div class="gantt"></div>
',
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
  'date' => '2014-12-16 23:42:06 +1100',
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
  'created' => 1418733726,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => 'ff1441b5-255b-465e-ba64-21149cc90807',
  'revision_uid' => 1,
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<p class="dashboard-description">The ICT Project Budgets provides a high level overview of original predicted and actual project budget spending. </p>

<style>
.field-name-body {
height: auto;
background-color: transparent;
width: 100%;
}
.field-name-body:active {
background-color: transparent;
}

#node-1674.content {
height: 400px;
}

     #chart {
        width : 930px;
        height: 384px;
        margin: 8px auto;
      }
</style>


    <div id="chart"></div>

<script>

jQuery(document).ready(function()
{
    d3.json("/datastore_search_sql.js.php?sql=select+distinct+p.name%2C+total_value%2C+expected_total_value++FROM+%28select+name%2C+value+as+total_value+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+where+metric+%3D+%27total_project_budget%27+%29+p+full+outer+JOIN+++++%28select+DISTINCT+d.name%2C+d.value+as+expected_total_value+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+d+join+%28select+name%2Cmetric%2C+max%28timestamp%29+as+timestamp+++++from+%222133eaed-150b-4c73-a314-67a0bde04115%22+GROUP+BY+name%2Cmetric%29+s+on+d.metric%3Ds.metric+and+d.timestamp%3Ds.timestamp+++++where+d.metric+%3D+%27current_total_expected_budget%27%29+b+on+p.name+%3D+b.name%3B",
        function(error, data) {
            project_names = [];
            project_orig_budget = [];
            project_current_budget = [];

            for (var i in data.result.records) {
                d =  data.result.records[i]
                project_names[parseInt(i)] = d.name;
                project_orig_budget.push([parseInt(i),parseInt(d.total_value) || 0]);
                project_current_budget.push([parseInt(i)+0.5,parseInt(d.expected_total_value) || 0]);
            }

       var
          container = document.getElementById(\'chart\'),
          graph, i;
  function ticksFn (n) { 
return project_names[parseInt(n)]; 
}
function hoverFn (obj){
return project_names[parseInt(obj.x)] +\', \'+obj.series.label+\': $\'+obj.y+\'m\';
  }
        // Draw Graph
        graph = Flotr.draw(container, [ {data: project_orig_budget, label: "Original Budget"}, {data: project_current_budget, label: "Current Budget"} ], {
      bars : {
        show : true,
barWidth: 0.4
},
      legend : {
        position : \'nw\'
      },
mouse : {
        track : true,
        relative : true,
trackFormatter: hoverFn
      },
xaxis: {
tickFormatter : ticksFn,
},
      yaxis : {
        min : 0,
        autoscaleMargin : 1
      },
      title : \'\'  });
});
});

</script>
',
        'summary' => '',
        'format' => 'full_html',
        'safe_value' => '<p class="dashboard-description">The ICT Project Budgets provides a high level overview of original predicted and actual project budget spending. </p>
<style>
<!--/*--><![CDATA[/* ><!--*/

.field-name-body {
height: auto;
background-color: transparent;
width: 100%;
}
.field-name-body:active {
background-color: transparent;
}

#node-1674.content {
height: 400px;
}

     #chart {
        width : 930px;
        height: 384px;
        margin: 8px auto;
      }

/*--><!]]>*/
</style><div id="chart"></div>
<script>
<!--//--><![CDATA[// ><!--


jQuery(document).ready(function()
{
    d3.json("/datastore_search_sql.js.php?sql=select+distinct+p.name%2C+total_value%2C+expected_total_value++FROM+%28select+name%2C+value+as+total_value+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+where+metric+%3D+%27total_project_budget%27+%29+p+full+outer+JOIN+++++%28select+DISTINCT+d.name%2C+d.value+as+expected_total_value+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+d+join+%28select+name%2Cmetric%2C+max%28timestamp%29+as+timestamp+++++from+%222133eaed-150b-4c73-a314-67a0bde04115%22+GROUP+BY+name%2Cmetric%29+s+on+d.metric%3Ds.metric+and+d.timestamp%3Ds.timestamp+++++where+d.metric+%3D+%27current_total_expected_budget%27%29+b+on+p.name+%3D+b.name%3B",
        function(error, data) {
            project_names = [];
            project_orig_budget = [];
            project_current_budget = [];

            for (var i in data.result.records) {
                d =  data.result.records[i]
                project_names[parseInt(i)] = d.name;
                project_orig_budget.push([parseInt(i),parseInt(d.total_value) || 0]);
                project_current_budget.push([parseInt(i)+0.5,parseInt(d.expected_total_value) || 0]);
            }

       var
          container = document.getElementById(\'chart\'),
          graph, i;
  function ticksFn (n) { 
return project_names[parseInt(n)]; 
}
function hoverFn (obj){
return project_names[parseInt(obj.x)] +\', \'+obj.series.label+\': $\'+obj.y+\'m\';
  }
        // Draw Graph
        graph = Flotr.draw(container, [ {data: project_orig_budget, label: "Original Budget"}, {data: project_current_budget, label: "Current Budget"} ], {
      bars : {
        show : true,
barWidth: 0.4
},
      legend : {
        position : \'nw\'
      },
mouse : {
        track : true,
        relative : true,
trackFormatter: hoverFn
      },
xaxis: {
tickFormatter : ticksFn,
},
      yaxis : {
        min : 0,
        autoscaleMargin : 1
      },
      title : \'\'  });
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
  'date' => '2014-12-16 23:42:06 +1100',
);
  return $nodes;
}
