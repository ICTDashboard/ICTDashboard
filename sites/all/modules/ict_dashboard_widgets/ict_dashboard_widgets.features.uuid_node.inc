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
            .style("opacity", function(d) { 
if (typeof this.getComputedTextLength  != \'undefined\') {
d.w = this.getComputedTextLength(); 
} else {
d.w = d.name.length * 6
}
return d.dx > d.w ? 1 : 0; });

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
            .style("opacity", function(d) { 
if (typeof this.getComputedTextLength  != \'undefined\') {
d.w = this.getComputedTextLength(); 
} else {
d.w = d.name.length * 6
}
return d.dx > d.w ? 1 : 0; });

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
  <div style="position:relative; width:930px;" class="gantt" id="GanttChartDIV"></div>
    <script>

        var g = new JSGantt.GanttChart(\'g\', document.getElementById(\'GanttChartDIV\'), \'year\');
        jQuery(document).ready(function () {
            var source = [];
            d3.json("/datastore_search_sql.js.php?sql=select+distinct+p.name%2C+start_date%2C+end_date%2C+expected_end_date%2C+total_value%2C+expected_total_value%0AFROM+%28select+name%2C+value+as+start_date+from%222133eaed-150b-4c73-a314-67a0bde04115%22+where+metric+%3D+%27start_date%27++%29+p+full+outer+JOIN%0A++%28select+name%2C+value+as+end_date+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+where+metric+%3D+%27end_date%27+%29+a+on+p.name+%3D+a.name+full+outer+JOIN%0A++%28select+name%2C+value+as+total_value+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+where+metric+%3D+%27total_project_budget%27+%29+v+on+p.name+%3D+v.name+full+outer+JOIN%0A++%28select+DISTINCT+d.name%2C+d.value+as+expected_end_date+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+d+join+%28select+name%2Cmetric%2C+max%28timestamp%29+as+timestamp%0Afrom+%222133eaed-150b-4c73-a314-67a0bde04115%22+GROUP+BY+name%2Cmetric%29+s+on+d.metric%3Ds.metric+and+d.timestamp%3Ds.timestamp%0Awhere+d.metric+%3D+%27original_completion_date%27%29+c+on+p.name+%3D+c.name+full+outer+JOIN%0A++%28select+DISTINCT+d.name%2C+d.value+as+expected_total_value+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+d+join+%28select+name%2Cmetric%2C+max%28timestamp%29+as+timestamp%0Afrom+%222133eaed-150b-4c73-a314-67a0bde04115%22+GROUP+BY+name%2Cmetric%29+s+on+d.metric%3Ds.metric+and+d.timestamp%3Ds.timestamp%0Awhere+d.metric+%3D+%27current_total_expected_budget%27%29+b+on+p.name+%3D+b.name+",
                function (error, data) {


                    g.setShowRes(0); // Show/Hide Responsible (0/1)
                    g.setShowDur(0); // Show/Hide Duration (0/1)
                    g.setShowComp(0); // Show/Hide % Complete(0/1)
                    //g.setCaptionType(\'Resource\');  // Set to Show Caption

                    if (g) {
                        /*TaskItem(pID, pName, pStart, pEnd, pColor, pLink, pMile, pRes, pComp, pGroup, pParent, pOpen, pDepend)
                         pID: (required) is a unique ID used to identify each row for parent functions and for setting dom id for hiding/showing
                         pName: (required) is the task Label
                         pStart: (required) the task start date, can enter empty date (\'\') for groups. You can also enter specific time (2/10/2008 12:00) for additional percision or half days.
                         pEnd: (required) the task end date, can enter empty date (\'\') for groups
                         pColor: (required) the html color for this task; e.g. \'00ff00\'
                         pLink: (optional) any http link navigated to when task bar is clicked.
                         pMile:(optional) represent a milestone
                         pRes: (optional) resource name
                         pComp: (required) completion percent
                         pGroup: (optional) indicates whether this is a group(parent) - 0=NOT Parent; 1=IS Parent
                         pParent: (required) identifies a parent pID, this causes this task to be a child of identified task
                         pOpen: can be initially set to close folder when chart is first drawn
                         pDepend: optional list of id\'s this task is dependent on ... line drawn from dependent to this item
                         pCaption: optional caption that will be added after task bar if CaptionType set to "Caption"*/
                        //g.AddTaskItem(new JSGantt.TaskItem(1,   \'Define Chart API\',     \'\',          \'\',          \'ff0000\', \'http://help.com\', 0, \'Brian\',     0, 1, 0, 1));
                        var color = d3.scale.category20b();
                        for (var i in data.result.records) {
                            d = data.result.records[i];
                            if (typeof(d.name) != "undefined" ) {
                                g.AddTaskItem(new JSGantt.TaskItem(i,
                                    d.name,
                                    moment(d.start_date).format(\'DD/MM/YYYY\'),
                                    moment(d.expected_end_date).format(\'DD/MM/YYYY\'),
                                    color(i), \'\', 0, \'\', 0, 0, 0, 1));
                            }
                        }

                        g.Draw();
                        g.DrawDependencies();


                    }
                    else {
                        alert("not defined");
                    }
                });
        });
    </script>',
        'summary' => '',
        'format' => 'full_html',
        'safe_value' => '<p class="dashboard-description">The ICT Project Timelines provides a high level overview of original predicted and actual project schedules. </p>
<div style="position:relative; width:930px;" class="gantt" id="GanttChartDIV"></div>
<script>
<!--//--><![CDATA[// ><!--


        var g = new JSGantt.GanttChart(\'g\', document.getElementById(\'GanttChartDIV\'), \'year\');
        jQuery(document).ready(function () {
            var source = [];
            d3.json("/datastore_search_sql.js.php?sql=select+distinct+p.name%2C+start_date%2C+end_date%2C+expected_end_date%2C+total_value%2C+expected_total_value%0AFROM+%28select+name%2C+value+as+start_date+from%222133eaed-150b-4c73-a314-67a0bde04115%22+where+metric+%3D+%27start_date%27++%29+p+full+outer+JOIN%0A++%28select+name%2C+value+as+end_date+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+where+metric+%3D+%27end_date%27+%29+a+on+p.name+%3D+a.name+full+outer+JOIN%0A++%28select+name%2C+value+as+total_value+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+where+metric+%3D+%27total_project_budget%27+%29+v+on+p.name+%3D+v.name+full+outer+JOIN%0A++%28select+DISTINCT+d.name%2C+d.value+as+expected_end_date+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+d+join+%28select+name%2Cmetric%2C+max%28timestamp%29+as+timestamp%0Afrom+%222133eaed-150b-4c73-a314-67a0bde04115%22+GROUP+BY+name%2Cmetric%29+s+on+d.metric%3Ds.metric+and+d.timestamp%3Ds.timestamp%0Awhere+d.metric+%3D+%27original_completion_date%27%29+c+on+p.name+%3D+c.name+full+outer+JOIN%0A++%28select+DISTINCT+d.name%2C+d.value+as+expected_total_value+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+d+join+%28select+name%2Cmetric%2C+max%28timestamp%29+as+timestamp%0Afrom+%222133eaed-150b-4c73-a314-67a0bde04115%22+GROUP+BY+name%2Cmetric%29+s+on+d.metric%3Ds.metric+and+d.timestamp%3Ds.timestamp%0Awhere+d.metric+%3D+%27current_total_expected_budget%27%29+b+on+p.name+%3D+b.name+",
                function (error, data) {


                    g.setShowRes(0); // Show/Hide Responsible (0/1)
                    g.setShowDur(0); // Show/Hide Duration (0/1)
                    g.setShowComp(0); // Show/Hide % Complete(0/1)
                    //g.setCaptionType(\'Resource\');  // Set to Show Caption

                    if (g) {
                        /*TaskItem(pID, pName, pStart, pEnd, pColor, pLink, pMile, pRes, pComp, pGroup, pParent, pOpen, pDepend)
                         pID: (required) is a unique ID used to identify each row for parent functions and for setting dom id for hiding/showing
                         pName: (required) is the task Label
                         pStart: (required) the task start date, can enter empty date (\'\') for groups. You can also enter specific time (2/10/2008 12:00) for additional percision or half days.
                         pEnd: (required) the task end date, can enter empty date (\'\') for groups
                         pColor: (required) the html color for this task; e.g. \'00ff00\'
                         pLink: (optional) any http link navigated to when task bar is clicked.
                         pMile:(optional) represent a milestone
                         pRes: (optional) resource name
                         pComp: (required) completion percent
                         pGroup: (optional) indicates whether this is a group(parent) - 0=NOT Parent; 1=IS Parent
                         pParent: (required) identifies a parent pID, this causes this task to be a child of identified task
                         pOpen: can be initially set to close folder when chart is first drawn
                         pDepend: optional list of id\'s this task is dependent on ... line drawn from dependent to this item
                         pCaption: optional caption that will be added after task bar if CaptionType set to "Caption"*/
                        //g.AddTaskItem(new JSGantt.TaskItem(1,   \'Define Chart API\',     \'\',          \'\',          \'ff0000\', \'http://help.com\', 0, \'Brian\',     0, 1, 0, 1));
                        var color = d3.scale.category20b();
                        for (var i in data.result.records) {
                            d = data.result.records[i];
                            if (typeof(d.name) != "undefined" ) {
                                g.AddTaskItem(new JSGantt.TaskItem(i,
                                    d.name,
                                    moment(d.start_date).format(\'DD/MM/YYYY\'),
                                    moment(d.expected_end_date).format(\'DD/MM/YYYY\'),
                                    color(i), \'\', 0, \'\', 0, 0, 0, 1));
                            }
                        }

                        g.Draw();
                        g.DrawDependencies();


                    }
                    else {
                        alert("not defined");
                    }
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
    d3.json("/datastore_search_sql.js.php?sql=select+distinct+p.name%2C+total_value%2C+expected_total_value++FROM+%28select+name%2C+value+as+total_value+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+where+metric+%3D+%27total_project_budget%27+%29+p+full+outer+JOIN+++++%28select+DISTINCT+d.name%2C+d.value+as+expected_total_value+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+d+join+%28select+name%2Cmetric%2C+max%28timestamp%29+as+timestamp+++++from+%222133eaed-150b-4c73-a314-67a0bde04115%22+GROUP+BY+name%2Cmetric%29+s+on+d.metric%3Ds.metric+and+d.timestamp%3Ds.timestamp+++++where+d.metric+%3D+%27revised_total_project%27%29+b+on+p.name+%3D+b.name%3B",
        function(error, data) {
            project_names = [];
            project_orig_budget = [];
            project_current_budget = [];

            for (var i in data.result.records) {
                d =  data.result.records[i]
                project_names[parseInt(i)] = d.name;
                project_orig_budget.push([parseInt(d.total_value) || 0,parseInt(i)]);
                project_current_budget.push([parseInt(d.expected_total_value) || 0,parseInt(i)+0.5]);
            }

       var
          container = document.getElementById(\'chart\'),
          graph, i;
  function ticksFn (n) { 
return project_names[parseInt(n)]; 
}
function hoverFn (obj){
return project_names[parseInt(obj.y)] +\', \'+obj.series.label+\': $\'+obj.x+\'m\';
  }
        // Draw Graph
        graph = Flotr.draw(container, [ {data: project_orig_budget, label: "Original Budget"}, {data: project_current_budget, label: "Current Budget"} ], {
      bars : {
        show : true,
horizontal : true,
barWidth: 0.4
},
      legend : {
        position : \'ne\'
      },
mouse : {
        track : true,
        relative : true,
trackFormatter: hoverFn
      },
xaxis : {
autoscale: true
},
      yaxis : {
tickFormatter: ticksFn,
noTicks: project_names.length,
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
    d3.json("/datastore_search_sql.js.php?sql=select+distinct+p.name%2C+total_value%2C+expected_total_value++FROM+%28select+name%2C+value+as+total_value+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+where+metric+%3D+%27total_project_budget%27+%29+p+full+outer+JOIN+++++%28select+DISTINCT+d.name%2C+d.value+as+expected_total_value+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+d+join+%28select+name%2Cmetric%2C+max%28timestamp%29+as+timestamp+++++from+%222133eaed-150b-4c73-a314-67a0bde04115%22+GROUP+BY+name%2Cmetric%29+s+on+d.metric%3Ds.metric+and+d.timestamp%3Ds.timestamp+++++where+d.metric+%3D+%27revised_total_project%27%29+b+on+p.name+%3D+b.name%3B",
        function(error, data) {
            project_names = [];
            project_orig_budget = [];
            project_current_budget = [];

            for (var i in data.result.records) {
                d =  data.result.records[i]
                project_names[parseInt(i)] = d.name;
                project_orig_budget.push([parseInt(d.total_value) || 0,parseInt(i)]);
                project_current_budget.push([parseInt(d.expected_total_value) || 0,parseInt(i)+0.5]);
            }

       var
          container = document.getElementById(\'chart\'),
          graph, i;
  function ticksFn (n) { 
return project_names[parseInt(n)]; 
}
function hoverFn (obj){
return project_names[parseInt(obj.y)] +\', \'+obj.series.label+\': $\'+obj.x+\'m\';
  }
        // Draw Graph
        graph = Flotr.draw(container, [ {data: project_orig_budget, label: "Original Budget"}, {data: project_current_budget, label: "Current Budget"} ], {
      bars : {
        show : true,
horizontal : true,
barWidth: 0.4
},
      legend : {
        position : \'ne\'
      },
mouse : {
        track : true,
        relative : true,
trackFormatter: hoverFn
      },
xaxis : {
autoscale: true
},
      yaxis : {
tickFormatter: ticksFn,
noTicks: project_names.length,
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
