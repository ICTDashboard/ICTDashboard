<?php

/**
 * @file
 * Main view template.
 *
 * Variables available:
 * - $classes_array: An array of classes determined in
 *   template_preprocess_views_view(). Default classes are:
 *     .view
 *     .view-[css_name]
 *     .view-id-[view_name]
 *     .view-display-id-[display_name]
 *     .view-dom-id-[dom_id]
 * - $classes: A string version of $classes_array for use in the class attribute
 * - $css_name: A css-safe version of the view name.
 * - $css_class: The user-specified classes names, if any
 * - $header: The view header
 * - $footer: The view footer
 * - $rows: The results of the view query, if any
 * - $empty: The empty text to display if the view is empty
 * - $pager: The pager next/prev links to display, if any
 * - $exposed: Exposed widget form/info to display
 * - $feed_icon: Feed icon to display, if any
 * - $more: A link to view more, if any
 *
 * @ingroup views_templates
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

        <div class="button-add d-1of5 t-2of5 last-col">
          <a href="<?php print url('project/add'); ?>" class="general-button plus"><span><?php print t('Add Project'); ?></span></a>
        </div>

      <?php endif; ?>
    </div>


  <?php if ($rows): ?>
    <?php print $rows; ?>
  <?php elseif ($empty): ?>
    <?php print $empty; ?>
  <?php endif; ?>

  <?php if ($pager): ?>
    <?php print $pager; ?>
  <?php endif; ?>
  </div>
</div>



