<?php $number = 1; ?>
<?php $projects_num = $updates_num = 0; ?>
<table id="financial-benefits" class="table_field_collection">

  <?php foreach(element_children($element) as $key) : ?>
    <?php if (!is_numeric($key)) continue; ?>
    <?php if (!empty($element[$key]['#archived_benefit'])) : ?>
      <tr class="row-yellow">
        <th rowspan="3" class="benefit-num"><div class="label"><?php print $number; ?>.</div></th>
        <th width="30%">
          <div class="label"><?php print t('Benefits'); ?>
            <?php if (!empty($descriptions['field_benefit'])) : ?>
              <a href="javascript:void(0);" class="tooltip">
                <i class="tooltip-icon"></i>
            <span class="tooltip-content">
              <?php print $descriptions['field_benefit']; ?>
            </span>
              </a>
            <?php endif; ?>
          </div>
        </th>
        <td colspan="2"><?php print $element[$key]['field_benefit']['und'][0]['value']['#default_value']; ?></td>
      </tr>
      <tr class="row-yellow" >
        <th>
          <div class="label">
            <?php print t('Realised Status'); ?>
            <?php if (!empty($descriptions['field_status'])) : ?>
              <a href="javascript:void(0);" class="tooltip">
                <i class="tooltip-icon"></i>
              <span class="tooltip-content">
                <?php print $descriptions['field_status']; ?>
              </span>
              </a>
            <?php endif; ?>
          </div>
        </th>
        <td colspan="2"><strong><em>
          <?php print t('Archived:'); ?>
          <?php print format_date($element[$key]['#archived_benefit'], 'medium', 'd F Y'); ?>
        </em></strong></td>
      </tr>
      <tr class="row-yellow last-benefit-row" >
        <th>
          <div class="label">
            <?php print t('Action'); ?>
          </div>
        </th>
        <td colspan="2" class="table-remove-button"><?php print drupal_render($element[$key]['history_button']); ?></td>
      </tr>
    <?php else : ?>
      <tr class="<?php print !fmod($number, 2) ? 'row-blue' : 'row-white'; ?>" >
        <th rowspan="5" class="benefit-num"><div class="label"><?php print $number; ?>.</div></th>
        <th width="30%">
          <div class="label"><?php print t('Benefits'); ?>
            <?php if (!empty($descriptions['field_benefit'])) : ?>
              <a href="javascript:void(0);" class="tooltip">
                <i class="tooltip-icon"></i>
            <span class="tooltip-content">
              <?php print $descriptions['field_benefit']; ?>
            </span>
              </a>
            <?php endif; ?>
          </div>
        </th>
        <td colspan="2" class="no-padding"><?php print drupal_render($element[$key]['field_benefit']); ?></td>
      </tr>
      <tr class="<?php print !fmod($number, 2) ? 'row-blue' : 'row-white'; ?>" >
        <th>
          <div class="label">
            <?php print t('Realised Status'); ?>
            <?php if (!empty($descriptions['field_status'])) : ?>
              <a href="javascript:void(0);" class="tooltip">
                <i class="tooltip-icon"></i>
              <span class="tooltip-content">
                <?php print $descriptions['field_status']; ?>
              </span>
              </a>
            <?php endif; ?>
          </div>
        </th>
        <td colspan="2" class="select-no-border no-padding"><?php print drupal_render($element[$key]['field_status']); ?></td>
      </tr>
      <tr class="<?php print !fmod($number, 2) ? 'row-blue' : 'row-white'; ?>" >
        <th>
        <div class="label">
          <?php print t('Commentary'); ?>
          <?php if (!empty($descriptions['field_commentary'])) : ?>
            <a href="javascript:void(0);" class="tooltip">
              <i class="tooltip-icon"></i>
            <span class="tooltip-content">
              <?php print $descriptions['field_commentary']; ?>
            </span>
            </a>
          <?php endif; ?>
        </div>
      </th>
        <td colspan="2" class="no-padding"><?php print drupal_render($element[$key]['field_commentary']); ?></td>
      </tr>
      <?php $element[$key]['field_benefit_start_date']['und'][0]['value']['date']['#title'] =
            $element[$key]['field_benefit_start_date']['und'][0]['value']['date']['#description'] =
            $element[$key]['field_end_date']['und'][0]['value']['date']['#title'] =
            $element[$key]['field_end_date']['und'][0]['value']['date']['#description'] = ''; ?>
      <tr class="<?php print !fmod($number, 2) ? 'row-blue' : 'row-white'; ?>" >
        <th>
        <div class="label">
          <?php print t('Date Range: Start - End'); ?>
          <?php if (!empty($descriptions['field_benefit_start_date'])) : ?>
            <a href="javascript:void(0);" class="tooltip">
              <i class="tooltip-icon"></i>
            <span class="tooltip-content">
              <?php print $descriptions['field_benefit_start_date']; ?>
            </span>
            </a>
          <?php endif; ?>
        </div>
      </th>
        <td><?php print drupal_render($element[$key]['field_benefit_start_date']); ?></td>
        <td><?php print drupal_render($element[$key]['field_end_date']); ?></td>
      </tr>
<!--      <tr class="--><?php //print !fmod($number, 2) ? 'row-blue' : 'row-white'; ?><!--" >-->
<!--        <th>-->
<!--        <div class="label">-->
<!--          --><?php //print t('Financial'); ?>
<!--          <a href="javascript:void(0);" class="tooltip"><i class="tooltip-icon"></i><span class="tooltip-content">For each benefit listed, mark those where the benefit can be measured financially.-->
<!--    </span></a>-->
<!--        </div>-->
<!--      </th>-->
<!--        <td colspan="2">--><?php //print drupal_render($element[$key]['field_financial']); ?><!--</td>-->
<!--      </tr>-->

      <tr class="last-benefit-row <?php print !fmod($number, 2) ? 'row-blue' : 'row-white'; ?>" >
        <th>
        <div class="label">
          <?php print t('Action'); ?>
        </div>
      </th>
        <td colspan="2" class="table-remove-button">
          <?php print drupal_render($element[$key]['remove_button']); ?>
          <?php print drupal_render($element[$key]['history_button']); ?>
        </td>
      </tr>
    <?php endif; ?>
    <?php $number ++ ?>
  <?php endforeach; ?>
</table>
<div class="benefits-action">
<?php print drupal_render($element['add_more']); ?>
</div>
<div class="element-invisible">
  <?php print drupal_render_children($element); ?>
</div>
