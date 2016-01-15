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
          <?php print drupal_render(bean_view($bean)); ?>
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
                <?php print date('d/m/Y h:i A', $project->changed); ?>
              </td>
              <td class="update">
                <a href="<?php print url('node/' . $project->nid); ?>">
                  <span><?php print t('View'); ?></span>
                </a>
                <?php if ($user->uid == 1 || in_array($user->uid, ict_project_get_users($project->nid, ICT_PROJECT_EDITOR_ACCESS))) : ?>
                <a href="<?php print url('project/' . $project->nid . '/update'); ?>">
                  <span><?php print t('Create an update draft'); ?></span>
                </a>
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
      <?php print $pager; ?>
    <?php endif; ?>
  </div>
</div>



