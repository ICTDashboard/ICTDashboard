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
<div class="wrap cf">
  <div class="ict-home-projects-table" id="ict-home-projects-table-id">
    <h2><?php print $table_header; ?></h2>
    <div class="table-config-bar pager-tags-top">
      <?php print render($pager); ?>
      <?php print theme('pager', array('tags' => $pager_tags)); ?>
    </div>
      <table class="ict-home-projects-table-table">
        <tr class="<?php print !empty($query['direction']) ? 'sort-direction-' . $query['direction'] : ''; ?>">
          <th class="<?php print $col_classes[0] ?>">
            <?php print t('Entity'); ?>
            <?php $query['order'] = 'eg_name'; ?>
            <a class="ict-sort-link-desktop" href="<?php print url(current_path(), array('query' => $query, 'fragment' => 'ict-home-projects-table-id')); ?>"><span></span></a>
          </th>
          <th class="<?php print $col_classes[1] ?>">
            <?php print t('Project Title'); ?>
            <?php $query['order'] = 'title'; ?>
            <a class="ict-sort-link-desktop" href="<?php print url(current_path(), array('query' => $query, 'fragment' => 'ict-home-projects-table-id')); ?>"><span></span></a>
          </th>
          <th colspan="2" class="<?php print $col_classes[2] ?>">
            <?php print t('Expenditure to Date/Budget'); ?>
            <?php $query['order'] = 'budget'; ?>
            <a class="ict-sort-link-desktop" href="<?php print url(current_path(), array('query' => $query, 'fragment' => 'ict-home-projects-table-id')); ?>"><span></span></a>
          </>
          <th class="<?php print $col_classes[3] ?>">
            <?php print t('No. of Benefits'); ?>
            <?php $query['order'] = 'benefits'; ?>
            <a class="ict-sort-link-desktop" href="<?php print url(current_path(), array('query' => $query, 'fragment' => 'ict-home-projects-table-id')); ?>"><span></span></a>
          </th>
          <th class="<?php print $col_classes[4] ?>">
            <?php print t('Project Schedule Status'); ?>
            <?php $query['order'] = 'status'; ?>
            <a class="ict-sort-link-desktop" href="<?php print url(current_path(), array('query' => $query, 'fragment' => 'ict-home-projects-table-id')); ?>"><span></span></a>
          </th>
        </tr>
        <tr class="tooltips-row <?php print !empty($query['direction']) ? 'sort-direction-' . $query['direction'] : ''; ?>">
          <th class="<?php print $col_classes[0] ?>"><a href="javascript:void(0);" class="tooltip"><i class="tooltip-icon"></i><span class="tooltip-content">
            <?php print t('The Government entity responsible for the project.'); ?>
            </span></a>
            <?php $query['order'] = 'eg_name'; ?>
            <a class="ict-sort-link-mobile" href="<?php print url(current_path(), array('query' => $query, 'fragment' => 'ict-home-projects-table-id')); ?>"><span></span></a>
          </th>
          <th class="<?php print $col_classes[1] ?>"><a href="javascript:void(0);" class="tooltip"><i class="tooltip-icon"></i><span class="tooltip-content">
            <?php print t('The official full name of the project'); ?>
            </span></a>
            <?php $query['order'] = 'title'; ?>
            <a class="ict-sort-link-mobile" href="<?php print url(current_path(), array('query' => $query, 'fragment' => 'ict-home-projects-table-id')); ?>"><span></span></a>
          </th>
          <th colspan="2" class="<?php print $col_classes[2] ?>"><a href="javascript:void(0);" class="tooltip"><i class="tooltip-icon"></i><span class="tooltip-content">
            <?php print t('The actual expenditure to date and total budgeted funding for the project'); ?>
            </span></a>
            <?php $query['order'] = 'budget'; ?>
            <a class="ict-sort-link-mobile" href="<?php print url(current_path(), array('query' => $query, 'fragment' => 'ict-home-projects-table-id')); ?>"><span></span></a>
          </th>
          <th class="<?php print $col_classes[3] ?>"><a href="javascript:void(0);" class="tooltip"><i class="tooltip-icon"></i><span class="tooltip-content">
            <?php print t('The number of benefits expect to be delivered by the project'); ?>
            </span></a>
            <?php $query['order'] = 'benefits'; ?>
            <a class="ict-sort-link-mobile" href="<?php print url(current_path(), array('query' => $query, 'fragment' => 'ict-home-projects-table-id')); ?>"><span></span></a>
          </th>
          <th class="<?php print $col_classes[4] ?>"><a href="javascript:void(0);" class="tooltip"><i class="tooltip-icon"></i><span class="tooltip-content">
            <?php print t('A status of the project compared to its planned schedule'); ?>
            </span></a>
            <?php $query['order'] = 'status'; ?>
            <a class="ict-sort-link-mobile" href="<?php print url(current_path(), array('query' => $query, 'fragment' => 'ict-home-projects-table-id')); ?>"><span></span></a>
          </th>
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
              <?php print l(check_plain($row->title), 'node/' . $row->nid); ?>
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
    <?php print render($pager); ?>
    <?php print theme('pager', array('tags' => $pager_tags)); ?>
  </div>
</div></div>
