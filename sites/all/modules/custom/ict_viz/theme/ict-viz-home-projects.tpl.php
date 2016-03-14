<?php
  $get = $query;
  $pager_tags = array(
    t('First'),
    t('Previous'),
    t('...'),
    t('Next'),
    t('Last'),
  );
?>
<div class="wrap cf"><div class="ict-home-projects-table" id="ict-home-projects-table-id">
  <h2><?php print $table_header; ?></h2>
  <div class="table-config-bar">
    <?php print theme('pager', array('tags' => $pager_tags)); ?>
    <?php print render($pager); ?>
  </div>
  <table>
    <tr class="<?php print !empty($query['direction']) ? 'sort-direction-' . $query['direction'] : ''; ?>">
      <th class="<?php print $col_classes[0] ?>">
        <?php print t('Entity'); ?>
        <?php $query['order'] = 'dep_name'; ?>
        <a class="ict-sort-link" href="<?php print url(current_path(), array('query' => $query)); ?>"><span></span></a>
      </th>
      <th class="<?php print $col_classes[1] ?>">
        <?php print t('Project Title'); ?>
        <?php $query['order'] = 'title'; ?>
        <a class="ict-sort-link" href="<?php print url(current_path(), array('query' => $query)); ?>"><span></span></a>
      </th>
      <th colspan="2" class="<?php print $col_classes[2] ?>">
        <?php print t('Expenditure to Date/Budget'); ?>
        <?php $query['order'] = 'budget'; ?>
        <a class="ict-sort-link" href="<?php print url(current_path(), array('query' => $query)); ?>"><span></span></a>
      </>
      <th class="<?php print $col_classes[3] ?>">
        <?php print t('No. of Benefits'); ?>
        <?php $query['order'] = 'benefits'; ?>
        <a class="ict-sort-link" href="<?php print url(current_path(), array('query' => $query)); ?>"><span></span></a>
      </th>
      <th class="<?php print $col_classes[4] ?>">
        <?php print t('Project Schedule Status'); ?>
        <?php $query['order'] = 'status'; ?>
        <a class="ict-sort-link" href="<?php print url(current_path(), array('query' => $query)); ?>"><span></span></a>
      </th>
    </tr>
    <tr class="tooltips-row">
      <th class="<?php print $col_classes[0] ?>"><a href="javascript:void(0);" class="tooltip"><i class="tooltip-icon"></i><span class="tooltip-content">
            Briefly describe benefit.
      </span></a></th>
      <th class="<?php print $col_classes[1] ?>"><a href="javascript:void(0);" class="tooltip"><i class="tooltip-icon"></i><span class="tooltip-content">
            Briefly describe benefit.
      </span></a></th>
      <th colspan="2" class="<?php print $col_classes[2] ?>"><a href="javascript:void(0);" class="tooltip"><i class="tooltip-icon"></i><span class="tooltip-content">
            Briefly describe benefit.
      </span></a></>
      <th class="<?php print $col_classes[3] ?>"><a href="javascript:void(0);" class="tooltip"><i class="tooltip-icon"></i><span class="tooltip-content">
            Briefly describe benefit.
      </span></a></th>
      <th class="<?php print $col_classes[4] ?>"><a href="javascript:void(0);" class="tooltip"><i class="tooltip-icon"></i><span class="tooltip-content">
            Briefly describe benefit.
      </span></a></th>
    </tr>
    <?php foreach($results as $row) : ?>
      <tr>
        <td class="<?php print $col_classes[0] ?>">
          <?php $query = $get;
                $query['filter_by'] = 'dep_name';
                $query['filter'] = $row->dep_tid; ?>
          <?php print l($row->dep_name, 'dashboard-projects', array('query' => $query)); ?>
        </td>
        <td class="<?php print $col_classes[1] ?>">
          <?php print l($row->title, 'node/' . $row->nid); ?>
        </td>
        <td class="<?php print $col_classes[2] ?>">
          <div class="graph-container">
            <div class="graph-budget" style="width: <?php print $row->budget_percent; ?>%"></div>
            <div class="graph-to-date" style="width: <?php print $row->to_date_percent; ?>%"></div>
          </div>
        </td>
        <td class="<?php print $col_classes[2] ?>">
          <strong>$<?php print $row->field_expenditure_to_date_calc_value; ?>m</strong>
          /
          $<?php print $row->field_expenditure_budget_calc_value; ?>m
        </td>
        <td class="<?php print $col_classes[3] ?>">
          <?php print l($row->field_number_of_benefits_calc_value, 'node/' . $row->nid, array('fragment' => 'project-benefits')); ?>
        </td>
        <td class="<?php print $col_classes[4] ?> schedule-status-col schedule-status-<?php print $row->field_schedule_status_calc_value; ?>">
          <?php $query = $get;
                $query['filter_by'] = 'status';
                $query['filter'] = $row->field_schedule_status_calc_value; ?>
          <?php print l($statuses[$row->field_schedule_status_calc_value], 'dashboard-projects', array('query' => $query)); ?>
        </td>
      </tr>
    <?php endforeach; ?>
  </table>
  <div class="table-config-bar">
    <?php print theme('pager', array('tags' => $pager_tags)); ?>
    <?php print render($pager); ?>
  </div>
</div></div>
