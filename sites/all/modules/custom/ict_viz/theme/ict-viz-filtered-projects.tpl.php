<?php $get = $query; ?>
<div class="wrap cf"><div class="ict-home-projects-table ict-filtered-projects-table" id="ict-home-projects-table-id">
  <div class="table-config-bar"></div>
  <table>
    <tr class="<?php print !empty($query['direction']) ? 'sort-direction-' . $query['direction'] : ''; ?>">
      <th class="<?php print $col_classes[0] ?>">
        <?php print t('Entity'); ?>
        <?php $query['order'] = 'eg_name'; ?>
        <a class="ict-sort-link" href="<?php print url(current_path(), array('query' => $query)); ?>"><span></span></a>
      </th>
      <th class="<?php print $col_classes[1] ?>">
        <?php print t('Project Title'); ?>
        <?php $query['order'] = 'title'; ?>
        <a class="ict-sort-link" href="<?php print url(current_path(), array('query' => $query)); ?>"><span></span></a>
      </th>
      <th class="<?php print $col_classes[2] ?>">
        <?php print t('Project Schedule Status'); ?>
        <?php $query['order'] = 'status'; ?>
        <a class="ict-sort-link" href="<?php print url(current_path(), array('query' => $query)); ?>"><span></span></a>
      </th>
      <th class="<?php print $col_classes[3] ?>">
        <?php print t('Level of Completion'); ?>
        <?php $query['order'] = 'level'; ?>
        <a class="ict-sort-link" href="<?php print url(current_path(), array('query' => $query)); ?>"><span></span></a>
      </th>
      <th class="<?php print $col_classes[4] ?>">
        <?php print t('Total Project Budget'); ?>
        <?php $query['order'] = 'budget'; ?>
        <a class="ict-sort-link" href="<?php print url(current_path(), array('query' => $query)); ?>"><span></span></a>
      </th>
      <th class="<?php print $col_classes[5] ?>">
        <?php print t('Start Date'); ?>
        <?php $query['order'] = 'o_comp_date'; ?>
        <a class="ict-sort-link" href="<?php print url(current_path(), array('query' => $query)); ?>"><span></span></a>
      </th>
      <th class="<?php print $col_classes[6] ?>">
        <?php print t('Expected Completion Date'); ?>
        <?php $query['order'] = 'exp_comp_date'; ?>
        <a class="ict-sort-link" href="<?php print url(current_path(), array('query' => $query)); ?>"><span></span></a>
      </th>
      <th class="<?php print $col_classes[7] ?>">
        <?php print t('Project Dashboard'); ?>
      </th>
    </tr>
    <tr class="tooltips-row">
      <th class="<?php print $col_classes[0] ?>"><a href="javascript:void(0);" class="tooltip"><i class="tooltip-icon"></i><span class="tooltip-content">
            <?php print t('The Government entity responsible for the project.'); ?>
      </span></a></th>
      <th class="<?php print $col_classes[1] ?>"><a href="javascript:void(0);" class="tooltip"><i class="tooltip-icon"></i><span class="tooltip-content">
            <?php print t('The official full name of the project.'); ?>
      </span></a></th>
      <th class="<?php print $col_classes[2] ?>"><a href="javascript:void(0);" class="tooltip"><i class="tooltip-icon"></i><span class="tooltip-content">
            <?php print t('A status of the project compared to its planned schedule.'); ?>
      </span></a></th>
      <th class="<?php print $col_classes[3] ?>"><a href="javascript:void(0);" class="tooltip"><i class="tooltip-icon"></i><span class="tooltip-content">
            <?php print t('The percentage of work completed to date.'); ?>
      </span></a></th>
      <th class="<?php print $col_classes[4] ?>"><a href="javascript:void(0);" class="tooltip"><i class="tooltip-icon"></i><span class="tooltip-content">
            <?php print t('The total funding for the project.'); ?>
      </span></a></th>
      <th class="<?php print $col_classes[5] ?>"><a href="javascript:void(0);" class="tooltip"><i class="tooltip-icon"></i><span class="tooltip-content">
            <?php print t('The date when the project commenced.'); ?>
      </span></a></th>
      <th class="<?php print $col_classes[6] ?>"><a href="javascript:void(0);" class="tooltip"><i class="tooltip-icon"></i><span class="tooltip-content">
            <?php print t('The forecasted date when the project will be completed.'); ?>
      </span></a></th>
      <th class="<?php print $col_classes[7] ?>"><a href="javascript:void(0);" class="tooltip"><i class="tooltip-icon"></i><span class="tooltip-content">
            <?php print t('The overview of the project’s current performance against the baseline.'); ?>
      </span></a></th>
    </tr>
    <?php foreach($results as $row) : ?>
      <tr>
        <td class="<?php print $col_classes[0] ?>">
          <?php $query = $get;
                $query['filter_by'] = 'eg_name';
                $query['filter'] = $row->eg_tid; ?>
          <?php print l($row->eg_name, 'dashboard-projects', array('query' => $query)); ?>
        </td>
        <td class="<?php print $col_classes[1] ?>">
          <?php print l($row->title, 'node/' . $row->nid); ?>
        </td>
        <td class="<?php print $col_classes[2] ?> schedule-status-col schedule-status-<?php print $row->field_schedule_status_calc_value; ?>">
          <?php $query = $get;
                $query['filter_by'] = 'status';
                $query['filter'] = $row->field_schedule_status_calc_value; ?>
          <?php print l($statuses[$row->field_schedule_status_calc_value], 'dashboard-projects', array('query' => $query)); ?>
        </td>
        <td class="<?php print $col_classes[3] ?>">
          <div class="graph-container graph-container-level">
            <div class="graph-bg" ></div>
            <div class="graph-level" style="width: <?php print $row->field_actual_level_of_project_co_value; ?>%"></div>
          </div>
          <div class="graph-value"><?php print (int)$row->field_actual_level_of_project_co_value; ?>%</div>
        </td>
        <td class="<?php print $col_classes[4] ?>">
          $<?php print number_format($row->field_expenditure_budget_calc_value, 2, '.', ''); ?>m
        </td>
        <td class="<?php print $col_classes[5] ?>">
          <?php print format_date(strtotime($row->field_start_date_value), 'medium', 'd F Y') ?>
        </td>
        <td class="<?php print $col_classes[6] ?>">
          <?php print format_date(strtotime($row->field_expected_completion_date_value), 'medium', 'd F Y') ?>
        </td>
        <td class="<?php print $col_classes[7] ?>">
          <div class="ict-project-button">
            <?php print l($row->title, 'node/' . $row->nid); ?>
          </div>
        </td>
      </tr>
    <?php endforeach; ?>
  </table>
  <div class="table-config-bar"></div>
</div></div>
