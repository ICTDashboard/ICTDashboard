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
        #treemap {
            width: 960px;
            height: 500px;
            background: #ddd;
        }

        text {
            pointer-events: none;
        }

        .grandparent text {
            font-weight: bold;
        }

        rect {
            fill: none;
            stroke: #fff;
        }

        rect.parent,
        .grandparent rect {
            stroke-width: 2px;
        }

        .grandparent rect {
            fill: orange;
        }

        .grandparent:hover rect {
            fill: #ee9700;
        }

        .children rect.parent,
        .grandparent rect {
            cursor: pointer;
        }

        .children rect.parent {
            fill: #bbb;
            fill-opacity: 1;
        }

        .children:hover rect.child {
            fill: #bbb;
        }
    </style>
</head>
<body>

<div id="treemap"></div>

<script type="text/javascript">
    jQuery(document).ready(function() {
        d3.json("/datastore_search_sql.js.php?sql=select%20budget.name%2C%20value%20total_project_budget%2C%20government_entity_name%20from%20%222133eaed-150b-4c73-a314-67a0bde04115%22%20budget%20inner%20join%20%20%20%20(%20select%20name%2C%20value%20government_entity_name%20from%20%222133eaed-150b-4c73-a314-67a0bde04115%22%20where%20metric%20%3D%20\'government_entity_name\')%20gen%20on%20budget.name%20%3D%20gen.name%20where%20metric%20%3D%20\'total_project_budget\'%3B",
            function (error, data) {
                var datum = {};
                for (var i in data.result.records) {
                    d = data.result.records[i];
                    if (typeof(d.name) != "undefined") {
                        if (!datum[d.government_entity_name]) {
                            datum[d.government_entity_name] = [];
                        }
                        datum[d.government_entity_name].push({"name": d.name, "value": parseInt(d.total_project_budget)});
                    }
                }
                var innerArray = [];
                for (property in datum) {
                    innerArray.push({name: property, value:0, children: datum[property]});
                }
                var root = {
                    "name": "Projects by organisation",
                    "value": 0,
                    "children": innerArray
                };
                var color = d3.scale.category20c();
                var margin = {top: 20, right: 0, bottom: 0, left: 0},
                    width = 960,
                    height = 500 - margin.top - margin.bottom,
                    formatNumber = d3.format(",d"),
                    transitioning;

                var x = d3.scale.linear()
                    .domain([0, width])
                    .range([0, width]);

                var y = d3.scale.linear()
                    .domain([0, height])
                    .range([0, height]);

                var treemap = d3.layout.treemap()
                    .children(function (d, depth) {
                        return depth ? null : d._children;
                    })
                    .sort(function (a, b) {
                        return a.value - b.value;
                    })
                    .ratio(height / width * 0.5 * (1 + Math.sqrt(5)))
                    .round(false);

                var svg = d3.select("#treemap").append("svg")
                    .attr("width", width + margin.left + margin.right)
                    .attr("height", height + margin.bottom + margin.top)
                    .style("margin-left", -margin.left + "px")
                    .style("margin.right", -margin.right + "px")
                    .append("g")
                    .attr("transform", "translate(" + margin.left + "," + margin.top + ")")
                    .style("shape-rendering", "crispEdges");

                var grandparent = svg.append("g")
                    .attr("class", "grandparent");

                grandparent.append("rect")
                    .attr("y", -margin.top)
                    .attr("width", width)
                    .attr("height", margin.top);

                grandparent.append("text")
                    .attr("x", 6)
                    .attr("y", 6 - margin.top)
                    .attr("dy", ".75em");


                initialize(root);
                accumulate(root);
                layout(root);
                display(root);

                function initialize(root) {
                    root.x = root.y = 0;
                    root.dx = width;
                    root.dy = height;
                    root.depth = 0;
                }

                // Aggregate the values for internal nodes. This is normally done by the
                // treemap layout, but not here because of our custom implementation.
                // We also take a snapshot of the original children (_children) to avoid
                // the children being overwritten when when layout is computed.
                function accumulate(d) {
                    return (d._children = d.children)
                        ? d.value = d.children.reduce(function (p, v) {
                        return p + accumulate(v);
                    }, 0)
                        : d.value;
                }

                // Compute the treemap layout recursively such that each group of siblings
                // uses the same size (1×1) rather than the dimensions of the parent cell.
                // This optimizes the layout for the current zoom state. Note that a wrapper
                // object is created for the parent node for each group of siblings so that
                // the parent’s dimensions are not discarded as we recurse. Since each group
                // of sibling was laid out in 1×1, we must rescale to fit using absolute
                // coordinates. This lets us use a viewport to zoom.
                function layout(d) {
                    if (d._children) {
                        treemap.nodes({_children: d._children});
                        d._children.forEach(function (c) {
                            c.x = d.x + c.x * d.dx;
                            c.y = d.y + c.y * d.dy;
                            c.dx *= d.dx;
                            c.dy *= d.dy;
                            c.parent = d;
                            layout(c);
                        });
                    }
                }

                function display(d) {
                    grandparent
                        .datum(d.parent)
                        .on("click", transition)
                        .select("text")
                        .text(name(d));

                    var g1 = svg.insert("g", ".grandparent")
                        .datum(d)
                        .attr("class", "depth");

                    var g = g1.selectAll("g")
                        .data(d._children)
                        .enter().append("g");

                    g.filter(function (d) {
                        return d._children;
                    })
                        .classed("children", true)
                        .on("click", transition);

                    g.selectAll(".child")
                        .data(function (d) {
                            return d._children || [d];
                        })
                        .enter().append("rect")
                        .attr("class", "child")
                        .style("fill",function(d,i){return color(d.parent.name);})
                        .call(rect);

                    g.append("rect")
                        .attr("class", "parent")
                        .call(rect)
                        .style("fill",function(d,i){return color(d.name);})
                        .append("title")
                        .text(function (d) {
                            return formatNumber(d.value);
                        });

                    g.append("text")
                        .attr("dy", ".75em")
                        .text(function (d) {
                            return d.name + " ($"+ d.value+"m)";
                        })
                        .call(text);

                    function transition(d) {
                        if (transitioning || !d) return;
                        transitioning = true;

                        var g2 = display(d);
                      /*  if ($.browser.msie && $.browser.version < 9.0) {

                            var t1 = g1.transition().duration(0),
                                t2 = g2.transition().duration(0);
                        } else {*/

                            var t1 = g1.transition().duration(750),
                                t2 = g2.transition().duration(750);
                        //}

                        // Update the domain only after entering new elements.
                        x.domain([d.x, d.x + d.dx]);
                        y.domain([d.y, d.y + d.dy]);

                        // Enable anti-aliasing during the transition.
                        svg.style("shape-rendering", null);

                        // Draw child nodes on top of parent nodes.
                        svg.selectAll(".depth").sort(function (a, b) {
                            return a.depth - b.depth;
                        });

                        // Fade-in entering text.
                        g2.selectAll("text").style("fill-opacity", 0);

                        // Transition to the new view.
                        t1.selectAll("text").call(text).style("fill-opacity", 0);
                        t2.selectAll("text").call(text).style("fill-opacity", 1);
                        t1.selectAll("rect").call(rect);
                        t2.selectAll("rect").call(rect);

                        // Remove the old node when the transition is finished.
                        t1.remove().each("end", function () {
                            svg.style("shape-rendering", "crispEdges");
                            transitioning = false;
                        });
                    }

                    return g;
                }

                function text(text) {
                    text.attr("x", function (d) {
                        return x(d.x) + 6;
                    })
                        .attr("y", function (d) {
                            return y(d.y) + 6;
                        });
                }

                function rect(rect) {
                    rect.attr("x", function (d) {
                        return x(d.x);
                    })
                        .attr("y", function (d) {
                            return y(d.y);
                        })
                        .attr("width", function (d) {
                            return x(d.x + d.dx) - x(d.x);
                        })
                        .attr("height", function (d) {
                            return y(d.y + d.dy) - y(d.y);
                        });
                }

                function name(d) {
                    return d.parent
                        ? name(d.parent) + " >> " + d.name
                        : d.name;
                }

            });
    });
</script>',
        'summary' => '',
        'format' => 'full_html',
        'safe_value' => '<p class="dashboard-description">The ICT Project Treemap compares how each of the major projects compare with each other according to either the total project value or number of projects being delivered by agencies.</p>
<style type="text/css">
<!--/*--><![CDATA[/* ><!--*/

        #treemap {
            width: 960px;
            height: 500px;
            background: #ddd;
        }

        text {
            pointer-events: none;
        }

        .grandparent text {
            font-weight: bold;
        }

        rect {
            fill: none;
            stroke: #fff;
        }

        rect.parent,
        .grandparent rect {
            stroke-width: 2px;
        }

        .grandparent rect {
            fill: orange;
        }

        .grandparent:hover rect {
            fill: #ee9700;
        }

        .children rect.parent,
        .grandparent rect {
            cursor: pointer;
        }

        .children rect.parent {
            fill: #bbb;
            fill-opacity: 1;
        }

        .children:hover rect.child {
            fill: #bbb;
        }
    
/*--><!]]>*/
</style><p><br /></p>
<div id="treemap"></div>
<script type="text/javascript">
<!--//--><![CDATA[// ><!--

    jQuery(document).ready(function() {
        d3.json("/datastore_search_sql.js.php?sql=select%20budget.name%2C%20value%20total_project_budget%2C%20government_entity_name%20from%20%222133eaed-150b-4c73-a314-67a0bde04115%22%20budget%20inner%20join%20%20%20%20(%20select%20name%2C%20value%20government_entity_name%20from%20%222133eaed-150b-4c73-a314-67a0bde04115%22%20where%20metric%20%3D%20\'government_entity_name\')%20gen%20on%20budget.name%20%3D%20gen.name%20where%20metric%20%3D%20\'total_project_budget\'%3B",
            function (error, data) {
                var datum = {};
                for (var i in data.result.records) {
                    d = data.result.records[i];
                    if (typeof(d.name) != "undefined") {
                        if (!datum[d.government_entity_name]) {
                            datum[d.government_entity_name] = [];
                        }
                        datum[d.government_entity_name].push({"name": d.name, "value": parseInt(d.total_project_budget)});
                    }
                }
                var innerArray = [];
                for (property in datum) {
                    innerArray.push({name: property, value:0, children: datum[property]});
                }
                var root = {
                    "name": "Projects by organisation",
                    "value": 0,
                    "children": innerArray
                };
                var color = d3.scale.category20c();
                var margin = {top: 20, right: 0, bottom: 0, left: 0},
                    width = 960,
                    height = 500 - margin.top - margin.bottom,
                    formatNumber = d3.format(",d"),
                    transitioning;

                var x = d3.scale.linear()
                    .domain([0, width])
                    .range([0, width]);

                var y = d3.scale.linear()
                    .domain([0, height])
                    .range([0, height]);

                var treemap = d3.layout.treemap()
                    .children(function (d, depth) {
                        return depth ? null : d._children;
                    })
                    .sort(function (a, b) {
                        return a.value - b.value;
                    })
                    .ratio(height / width * 0.5 * (1 + Math.sqrt(5)))
                    .round(false);

                var svg = d3.select("#treemap").append("svg")
                    .attr("width", width + margin.left + margin.right)
                    .attr("height", height + margin.bottom + margin.top)
                    .style("margin-left", -margin.left + "px")
                    .style("margin.right", -margin.right + "px")
                    .append("g")
                    .attr("transform", "translate(" + margin.left + "," + margin.top + ")")
                    .style("shape-rendering", "crispEdges");

                var grandparent = svg.append("g")
                    .attr("class", "grandparent");

                grandparent.append("rect")
                    .attr("y", -margin.top)
                    .attr("width", width)
                    .attr("height", margin.top);

                grandparent.append("text")
                    .attr("x", 6)
                    .attr("y", 6 - margin.top)
                    .attr("dy", ".75em");


                initialize(root);
                accumulate(root);
                layout(root);
                display(root);

                function initialize(root) {
                    root.x = root.y = 0;
                    root.dx = width;
                    root.dy = height;
                    root.depth = 0;
                }

                // Aggregate the values for internal nodes. This is normally done by the
                // treemap layout, but not here because of our custom implementation.
                // We also take a snapshot of the original children (_children) to avoid
                // the children being overwritten when when layout is computed.
                function accumulate(d) {
                    return (d._children = d.children)
                        ? d.value = d.children.reduce(function (p, v) {
                        return p + accumulate(v);
                    }, 0)
                        : d.value;
                }

                // Compute the treemap layout recursively such that each group of siblings
                // uses the same size (1×1) rather than the dimensions of the parent cell.
                // This optimizes the layout for the current zoom state. Note that a wrapper
                // object is created for the parent node for each group of siblings so that
                // the parent’s dimensions are not discarded as we recurse. Since each group
                // of sibling was laid out in 1×1, we must rescale to fit using absolute
                // coordinates. This lets us use a viewport to zoom.
                function layout(d) {
                    if (d._children) {
                        treemap.nodes({_children: d._children});
                        d._children.forEach(function (c) {
                            c.x = d.x + c.x * d.dx;
                            c.y = d.y + c.y * d.dy;
                            c.dx *= d.dx;
                            c.dy *= d.dy;
                            c.parent = d;
                            layout(c);
                        });
                    }
                }

                function display(d) {
                    grandparent
                        .datum(d.parent)
                        .on("click", transition)
                        .select("text")
                        .text(name(d));

                    var g1 = svg.insert("g", ".grandparent")
                        .datum(d)
                        .attr("class", "depth");

                    var g = g1.selectAll("g")
                        .data(d._children)
                        .enter().append("g");

                    g.filter(function (d) {
                        return d._children;
                    })
                        .classed("children", true)
                        .on("click", transition);

                    g.selectAll(".child")
                        .data(function (d) {
                            return d._children || [d];
                        })
                        .enter().append("rect")
                        .attr("class", "child")
                        .style("fill",function(d,i){return color(d.parent.name);})
                        .call(rect);

                    g.append("rect")
                        .attr("class", "parent")
                        .call(rect)
                        .style("fill",function(d,i){return color(d.name);})
                        .append("title")
                        .text(function (d) {
                            return formatNumber(d.value);
                        });

                    g.append("text")
                        .attr("dy", ".75em")
                        .text(function (d) {
                            return d.name + " ($"+ d.value+"m)";
                        })
                        .call(text);

                    function transition(d) {
                        if (transitioning || !d) return;
                        transitioning = true;

                        var g2 = display(d);
                      /*  if ($.browser.msie && $.browser.version < 9.0) {

                            var t1 = g1.transition().duration(0),
                                t2 = g2.transition().duration(0);
                        } else {*/

                            var t1 = g1.transition().duration(750),
                                t2 = g2.transition().duration(750);
                        //}

                        // Update the domain only after entering new elements.
                        x.domain([d.x, d.x + d.dx]);
                        y.domain([d.y, d.y + d.dy]);

                        // Enable anti-aliasing during the transition.
                        svg.style("shape-rendering", null);

                        // Draw child nodes on top of parent nodes.
                        svg.selectAll(".depth").sort(function (a, b) {
                            return a.depth - b.depth;
                        });

                        // Fade-in entering text.
                        g2.selectAll("text").style("fill-opacity", 0);

                        // Transition to the new view.
                        t1.selectAll("text").call(text).style("fill-opacity", 0);
                        t2.selectAll("text").call(text).style("fill-opacity", 1);
                        t1.selectAll("rect").call(rect);
                        t2.selectAll("rect").call(rect);

                        // Remove the old node when the transition is finished.
                        t1.remove().each("end", function () {
                            svg.style("shape-rendering", "crispEdges");
                            transitioning = false;
                        });
                    }

                    return g;
                }

                function text(text) {
                    text.attr("x", function (d) {
                        return x(d.x) + 6;
                    })
                        .attr("y", function (d) {
                            return y(d.y) + 6;
                        });
                }

                function rect(rect) {
                    rect.attr("x", function (d) {
                        return x(d.x);
                    })
                        .attr("y", function (d) {
                            return y(d.y);
                        })
                        .attr("width", function (d) {
                            return x(d.x + d.dx) - x(d.x);
                        })
                        .attr("height", function (d) {
                            return y(d.y + d.dy) - y(d.y);
                        });
                }

                function name(d) {
                    return d.parent
                        ? name(d.parent) + " >> " + d.name
                        : d.name;
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
  'data' => 'a:5:{s:16:"ckeditor_default";s:1:"t";s:20:"ckeditor_show_toggle";s:1:"t";s:14:"ckeditor_width";s:4:"100%";s:13:"ckeditor_lang";s:2:"en";s:18:"ckeditor_auto_lang";s:1:"t";}',
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
  'data' => 'a:5:{s:16:"ckeditor_default";s:1:"t";s:20:"ckeditor_show_toggle";s:1:"t";s:14:"ckeditor_width";s:4:"100%";s:13:"ckeditor_lang";s:2:"en";s:18:"ckeditor_auto_lang";s:1:"t";}',
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
    d3.json("/datastore_search_sql.js.php?sql=select+distinct+p.name%2C+total_value%2C+expected_total_value++FROM+%28select+name%2C+value+as+total_value+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+where+metric+%3D+%27total_project_budget%27+%29+p+full+outer+JOIN+%28select+DISTINCT+d.name%2C+d.value+as+expected_total_value+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+d+join+%28select+name%2Cmetric%2C+max%28timestamp%29+as+timestamp+++++from+%222133eaed-150b-4c73-a314-67a0bde04115%22+GROUP+BY+name%2Cmetric%29+s+on+d.metric%3Ds.metric+and+d.timestamp%3Ds.timestamp+++++where+d.metric+%3D+%27total_project_current%27%29+b+on+p.name+%3D+b.name%3B",
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
        graph = Flotr.draw(container, [ {data: project_orig_budget, label: "Project budget"}, {data: project_current_budget, label: "Project spend"} ], {
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

</script>',
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
    d3.json("/datastore_search_sql.js.php?sql=select+distinct+p.name%2C+total_value%2C+expected_total_value++FROM+%28select+name%2C+value+as+total_value+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+where+metric+%3D+%27total_project_budget%27+%29+p+full+outer+JOIN+%28select+DISTINCT+d.name%2C+d.value+as+expected_total_value+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+d+join+%28select+name%2Cmetric%2C+max%28timestamp%29+as+timestamp+++++from+%222133eaed-150b-4c73-a314-67a0bde04115%22+GROUP+BY+name%2Cmetric%29+s+on+d.metric%3Ds.metric+and+d.timestamp%3Ds.timestamp+++++where+d.metric+%3D+%27total_project_current%27%29+b+on+p.name+%3D+b.name%3B",
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
        graph = Flotr.draw(container, [ {data: project_orig_budget, label: "Project budget"}, {data: project_current_budget, label: "Project spend"} ], {
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
  'data' => 'a:5:{s:16:"ckeditor_default";s:1:"t";s:20:"ckeditor_show_toggle";s:1:"t";s:14:"ckeditor_width";s:4:"100%";s:13:"ckeditor_lang";s:2:"en";s:18:"ckeditor_auto_lang";s:1:"t";}',
  'date' => '2014-12-16 23:42:06 +1100',
);
  return $nodes;
}
