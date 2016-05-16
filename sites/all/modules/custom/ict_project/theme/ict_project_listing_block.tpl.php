<?php

/**
 * @file
 * Project List template.
 */
?>
<div class="page-title dotbg">
  <div class="inner-title-content wrap cf">
    <h1><?php print t('Project List'); ?></h1>
  </div>
</div>




<div id="inner-content" class="wrap cf">
  <?php global $user; ?>

  <?php if (isset($user->name)) : ?>
    <h2><?php print t('Add and manage projects'); ?></h2>
  <?php endif; ?>
  <div id="project-listings">
    <div class="project-list-content">

      <?php if (user_is_logged_in()) : ?>

        <div class="text d-4of5">
          <p><?php print t('Use this page to register a new project, or administer any existing projects associated with your login. Mid financial year updates are to be completed between November and January. End financial year updates are to be completed between May and July. Select the Add Project button to register a new project.'); ?></p>
          <p><?php print t('The ICT Project Dashboard shows the performance of major ICT enabled projects. These are ICT enabled projects that meet the threshold for consideration as part of the ICT Two Pass Review Process.'); ?></p>
        </div>
        <?php global $user; ?>
        <?php if (node_access('create', 'project', $user)): ?>
          <div class="button-add d-1of5 t-2of5 last-col">
            <a href="<?php print url('project/add'); ?>" class="general-button plus"><span><?php print t('Add Project'); ?></span></a>
            <?php if (user_access('view any opt_out_policy bean')): ?>
              <div>
                <a href="#ict-policy" class="fancybox-inline"><?php print t('Opt-out policy'); ?></a>
              </div>
            <?php endif; ?>
          </div>
        <?php endif; ?>
        <div style="display: none;" id="ict-policy">
          <?php $bean = bean_load_delta('opt-out-policy'); ?>
          <h2 class="fancybox-title"><?php print $bean->title; ?></h2>
          <div class="ict-fancy-content"><?php print drupal_render(bean_view($bean)); ?></div>
          <div class="fancybox-actions">
            <a class="ict-fancybox-close general-button" href="#"><span><?php print t('Close'); ?></span></a>
          </div>
        </div>
      <?php endif; ?>
    </div>


    <?php if ($rows) : ?>
      <div class="project-lists d-all t-all">
        <table border="0" cellspacing="0" cellpadding="0">

          <tbody><tr>
            <th class="views-field views-field-title">
              <?php print t('Project Name'); ?>
              <a class="asc" href="/projects?order=title&amp;sort=desc">
<!--                <i class="fa fa-sort-asc"></i>-->
<!--                <i class="fa fa-sort-desc"></i>-->
              </a>
            </th>
            <th class="views-field views-field-changed">
              <?php print t('Last Updated'); ?>
              <a class="desc" href="/projects?order=changed&amp;sort=asc">
<!--                <i class="fa fa-sort-asc"></i>-->
<!--                <i class="fa fa-sort-desc"></i>-->
              </a>
            </th>
            <th class="views-field views-field-nothing">
              <?php print t('Actions'); ?>
            </th>
          </tr>

          <?php foreach ($rows as $project) : ?>
            <tr class="odd views-row-first">
              <td class="title">
                <a href="<?php print url('node/' . $project->nid); ?>">
                  <?php print $project->title; ?>
                </a>
              </td>
              <td class="dates">
                <?php print format_date($project->changed, 'medium', 'j M Y h:i A'); ?>
              </td>
              <td class="update">
                <a href="<?php print url('node/' . $project->nid); ?>">
                  <span><?php print t('View Project'); ?></span>
                </a>

                <?php if (ict_project_access_project('delete', $user, $project->nid)) : ?>
                  <a href="<?php print url('node/' . $project->nid . '/delete', array(
                      'query' => array('destination' => 'projects')
                    )
                  ); ?>">
                    <span><?php print t('Delete Project'); ?></span>
                  </a>
                <?php endif; ?>

                <?php // create or edit draft ?>
                <?php if (ict_project_access_project('edit', $user, $project->nid)) : ?>
                  <a href="<?php print url('baseline/' . $project->nid . '/edit-draft'); ?>">
                    <span><?php print t('Edit Baseline Draft'); ?></span>
                  </a>
                <?php endif; ?>

                <?php // create or edit draft ?>
                <?php if (ict_project_access_project('approve', $user, $project->nid)) : ?>
                  <a href="<?php print url('node/' . $project->nid); ?>">
                    <span><?php print t('Review Baseline Draft'); ?></span>
                  </a>
                <?php endif; ?>

                <?php $updates = ict_update_project_get_list($project->nid); ?>
                <?php $update_id = reset($updates); ?>
                <?php if (ict_update_creation_allowed($project->nid)) : ?>
                  <a href="<?php print url('project/' . $project->nid . '/update'); ?>">
                    <span><?php print t('Create Update Draft'); ?></span>
                  </a>
                <?php endif; ?>

                <?php if (ict_update_edit_allowed($project->nid, $update_id)) : ?>
                  <a href="<?php print url('update/' . $update_id . '/edit'); ?>">
                    <span><?php print t('Edit Update Draft'); ?></span>
                  </a>
                <?php endif; ?>

                <?php if (ict_update_approve_allowed($project->nid, $update_id)) : ?>
                  <a href="<?php print url('node/' . $project->nid); ?>">
                    <span><?php print t('Review Update Draft'); ?></span>
                  </a>
                <?php endif; ?>

                <?php if (ict_update_delete_allowed($project->nid, $update_id)) : ?>
                  <a href="<?php print url('node/' . $update_id .'/delete', array(
                      'query' => array('destination' => 'projects')
                    )
                  ); ?>">
                    <span><?php print t('Delete Update Draft'); ?></span>
                  </a>
                <?php endif; ?>

                <?php if (ict_project_access_project('manage_users', $user, $project->nid)) : ?>
                  <a href="<?php print url('project/' . $project->nid .'/manage-users', array(
                      'query' => array('destination' => 'projects')
                    )
                  ); ?>">
                    <span><?php print t('Manage Users'); ?></span>
                  </a>
                <?php endif; ?>

                <?php if (ict_project_access_project('rebaseline', $user, $project->nid)) : ?>
                  <a href="#ict-rebaseline-<?php print $project->nid; ?>" class="fancybox-inline">
                    <span><?php print t('Create Re-baseline Draft'); ?></span>
                  </a>
                  <div style="display: none;" id="ict-rebaseline-<?php print $project->nid; ?>" class="ict-rebaseline-warn">
                    <?php $bean = bean_load_delta('opt-out-policy'); ?>
                    <h2 class="fancybox-title"><?php print t('Warning'); ?></h2>
                    <div class="ict-fancy-content entity-bean">
                      <div class="field">
                        <p>
                          <?php print t('Rebaselining a project requires approval of the project’s highest governance body and potentially the Government.'); ?>
                        </p>
                        <strong>
                          <?php print t('Only proceed if this is the case.') ?>
                        </strong>
                      </div>
                    </div>
                    <div class="fancybox-actions">
                      <a class="ict-fancybox-close export-btn" href="#"><span><?php print t('Cancel'); ?></span></a>
                      <a class="general-button arrow-right confirm-proceed" href="<?php print url('project/' . $project->nid .'/rebaseline', array(
                          'query' => array('destination' => 'projects')
                        )
                      ); ?>"><span><?php print t('Confirm and proceed'); ?></span></a>
                    </div>
                  </div>
                <?php endif; ?>
              </td>
            </tr>
          <?php endforeach; ?>
          </tbody>

        </table>
      </div>
    <?php else : ?>
      <div class="views-no-results">
        <h2><?php print t('No available projects'); ?></h2>
      </div>
    <?php endif; ?>

    <?php if ($pager) : ?>
      <div class="table-config-bar">
        <?php print theme('pager', array('tags' => $pager_tags)); ?>
        <?php print render($pager); ?>
      </div>
    <?php endif; ?>
  </div>
</div>



