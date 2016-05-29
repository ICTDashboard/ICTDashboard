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
    <?php print render($pager); ?>
  </div>
      <table>
        <tr class="<?php print !empty($query['direction']) ? 'sort-direction-' . $query['direction'] : ''; ?>">
          <th class="<?php print $col_classes[0] ?>">
            <?php print t('Entity'); ?>
            <?php $query['order'] = 'eg_name'; ?>
            <a class="ict-sort-link" href="<?php print url(current_path(), array('query' => $query, 'fragment' => 'ict-home-projects-table-id')); ?>"><span></span></a>
          </th>
          <th class="<?php print $col_classes[1] ?>">
            <?php print t('Project Title'); ?>
            <?php $query['order'] = 'title'; ?>
            <a class="ict-sort-link" href="<?php print url(current_path(), array('query' => $query, 'fragment' => 'ict-home-projects-table-id')); ?>"><span></span></a>
          </th>
          <th class="<?php print $col_classes[4] ?>">
            <?php print t('Project Schedule Status'); ?>
            <?php $query['order'] = 'status'; ?>
            <a class="ict-sort-link" href="<?php print url(current_path(), array('query' => $query, 'fragment' => 'ict-home-projects-table-id')); ?>"><span></span></a>
          </th>
        </tr>
        <tr class="tooltips-row">
          <th class="<?php print $col_classes[0] ?>"><a href="javascript:void(0);" class="tooltip"><i class="tooltip-icon"></i><span class="tooltip-content">
            <?php print t('The Government entity responsible for the project.'); ?>
          </span></a></th>
          <th class="<?php print $col_classes[1] ?>"><a href="javascript:void(0);" class="tooltip"><i class="tooltip-icon"></i><span class="tooltip-content">
            <?php print t('The official full name of the project'); ?>
      </span></a></th>
          <th class="<?php print $col_classes[4] ?>"><a href="javascript:void(0);" class="tooltip"><i class="tooltip-icon"></i><span class="tooltip-content">
            <?php print t('A status of the project compared to its planned schedule'); ?>
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
