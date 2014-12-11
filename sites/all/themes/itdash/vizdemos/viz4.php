<html><head>
<script src="http://d3js.org/d3.v3.min.js"></script>
<style type="text/css">

    .chart {
        display: block;
        margin: auto;
        margin-top: 40px;
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
        d3.layout.treemap
        <div class="hint">click or option-click to descend or ascend</div>
        <div><select>
                <option value="size">Size</option>
                <option value="count">Count</option>
            </select></div>
    </div>
</div>
<script type="text/javascript">

    var w = 1280 - 80,
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

    d3.json("http://ckan.itdash.lws.links.com.au/api/action/datastore_search_sql?sql=<?php echo urlencode("select distinct p.name, government_business_unit, government_programme, government_entity,total_value, expected_total_value
FROM (select name, value as government_business_unit from\"2133eaed-150b-4c73-a314-67a0bde04115\" where metric = 'government_business_unit'  ) b full outer JOIN
(select name, value as total_value from \"2133eaed-150b-4c73-a314-67a0bde04115\" where metric = 'total_project_budget' ) z on b.name =z.name full outer JOIN
  (select name, value as government_programme from \"2133eaed-150b-4c73-a314-67a0bde04115\" where metric = 'government_programme' ) p on p.name = b.name full outer JOIN
(select name, value as government_entity from \"2133eaed-150b-4c73-a314-67a0bde04115\" where metric = 'government_entity' ) e on p.name = e.name full outer JOIN
   (select DISTINCT d.name, d.value as expected_total_value from \"2133eaed-150b-4c73-a314-67a0bde04115\" d join (select name,metric, max(timestamp) as timestamp 
from \"2133eaed-150b-4c73-a314-67a0bde04115\" GROUP BY name,metric) s on d.metric=s.metric and d.timestamp=s.timestamp 
where d.metric = 'current_total_expected_budget') t on p.name = t.name  ");?>",
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
                if (typeof ents[d.government_entity] == 'undefined') {
                    ents[d.government_entity] = [];
                }
                ents[d.government_entity].push(d.government_programme);
                if (typeof progs[d.government_programme] == 'undefined') {
                    progs[d.government_programme] = [];
                }
                progs[d.government_programme].push(d.government_business_unit);
                if (typeof gbus[d.government_business_unit]  == 'undefined') {
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
</body>
</html>
