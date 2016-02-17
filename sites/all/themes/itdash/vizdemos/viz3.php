<!doctype html>
<html>
<head>
    <link rel="stylesheet" type="text/css" href="../css/jsgantt.css" />
    <script src="http://code.jquery.com/jquery-latest.min.js"></script>
    <!--[if lte IE 8]>  <script type="text/javascript" src="../js/r2d3.min.js"></script><![endif]-->
    <!--[if gte IE 9]><!-->
    <script src="http://d3js.org/d3.v3.min.js" charset="utf-8"></script>
    <!--<![endif]-->
    <script type="text/javascript" src="../js/moment.min.js"></script>
    <script language="javascript" src="../js/jsgantt.js"></script>
    </head><body>
    <div style="position:relative" class="gantt" id="GanttChartDIV"></div>
    <script>

        var g = new JSGantt.GanttChart('g', document.getElementById('GanttChartDIV'), 'year');
        jQuery(document).ready(function () {
            var source = [];
            d3.json("/datastore_search_sql.js.php?sql=select+distinct+p.name%2C+start_date%2C+end_date%2C+expected_end_date%2C+total_value%2C+expected_total_value%0AFROM+%28select+name%2C+value+as+start_date+from%222133eaed-150b-4c73-a314-67a0bde04115%22+where+metric+%3D+%27start_date%27++%29+p+full+outer+JOIN%0A++%28select+name%2C+value+as+end_date+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+where+metric+%3D+%27end_date%27+%29+a+on+p.name+%3D+a.name+full+outer+JOIN%0A++%28select+name%2C+value+as+total_value+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+where+metric+%3D+%27total_project_budget%27+%29+v+on+p.name+%3D+v.name+full+outer+JOIN%0A++%28select+DISTINCT+d.name%2C+d.value+as+expected_end_date+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+d+join+%28select+name%2Cmetric%2C+max%28timestamp%29+as+timestamp%0Afrom+%222133eaed-150b-4c73-a314-67a0bde04115%22+GROUP+BY+name%2Cmetric%29+s+on+d.metric%3Ds.metric+and+d.timestamp%3Ds.timestamp%0Awhere+d.metric+%3D+%27original_completion_date%27%29+c+on+p.name+%3D+c.name+full+outer+JOIN%0A++%28select+DISTINCT+d.name%2C+d.value+as+expected_total_value+from+%222133eaed-150b-4c73-a314-67a0bde04115%22+d+join+%28select+name%2Cmetric%2C+max%28timestamp%29+as+timestamp%0Afrom+%222133eaed-150b-4c73-a314-67a0bde04115%22+GROUP+BY+name%2Cmetric%29+s+on+d.metric%3Ds.metric+and+d.timestamp%3Ds.timestamp%0Awhere+d.metric+%3D+%27current_total_expected_budget%27%29+b+on+p.name+%3D+b.name+",
                function (error, data) {


                    g.setShowRes(0); // Show/Hide Responsible (0/1)
                    g.setShowDur(0); // Show/Hide Duration (0/1)
                    g.setShowComp(0); // Show/Hide % Complete(0/1)
                    //g.setCaptionType('Resource');  // Set to Show Caption

                    if (g) {
                        /*TaskItem(pID, pName, pStart, pEnd, pColor, pLink, pMile, pRes, pComp, pGroup, pParent, pOpen, pDepend)
                         pID: (required) is a unique ID used to identify each row for parent functions and for setting dom id for hiding/showing
                         pName: (required) is the task Label
                         pStart: (required) the task start date, can enter empty date ('') for groups. You can also enter specific time (2/10/2008 12:00) for additional percision or half days.
                         pEnd: (required) the task end date, can enter empty date ('') for groups
                         pColor: (required) the html color for this task; e.g. '00ff00'
                         pLink: (optional) any http link navigated to when task bar is clicked.
                         pMile:(optional) represent a milestone
                         pRes: (optional) resource name
                         pComp: (required) completion percent
                         pGroup: (optional) indicates whether this is a group(parent) - 0=NOT Parent; 1=IS Parent
                         pParent: (required) identifies a parent pID, this causes this task to be a child of identified task
                         pOpen: can be initially set to close folder when chart is first drawn
                         pDepend: optional list of id's this task is dependent on ... line drawn from dependent to this item
                         pCaption: optional caption that will be added after task bar if CaptionType set to "Caption"*/
                        //g.AddTaskItem(new JSGantt.TaskItem(1,   'Define Chart API',     '',          '',          'ff0000', 'http://help.com', 0, 'Brian',     0, 1, 0, 1));
                        var color = d3.scale.category20b();
                        for (var i in data.result.records) {
                            d = data.result.records[i];
                            if (typeof(d.name) != "undefined" ) {
                                g.AddTaskItem(new JSGantt.TaskItem(i,
                                    d.name,
                                    moment(d.start_date).format('DD/MM/YYYY'),
                                    moment(d.expected_end_date).format('DD/MM/YYYY'),
                                    color(i), '', 0, '', 0, 0, 0, 1));
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
    </script>
  </body>
</html>