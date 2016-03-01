<?php global $user; ?>

<div class="row">
  <div class="label">
    <?php print t('Departmental Administrators'); ?>
    <a href="javascript:void(0);" class="tooltip">
      <i class="tooltip-icon"></i>
      <span class="tooltip-content">
       <?php print t('Departmental Administrators can create project on the dashboard. They can also create and assign both Project Approvers and Project Editors to a project. They cannot be Project Approvers within the same project. They can be Project Editors within the same project.'); ?>
      </span>
    </a>
  </div>
  <div class="text">
    <?php foreach ($departmental_admins as $email) : ?>
      <a class="email-value" href="mailto:<?php print $email; ?>"><?php print $email; ?></a>
    <?php endforeach; ?>
  </div>
</div>

<div class="row">
  <div class="label">
    <?php print t('Project Approvers'); ?>
    <a href="javascript:void(0);" class="tooltip">
      <i class="tooltip-icon"></i>
      <span class="tooltip-content">
        <?php print t('Project Approvers can review, approve or reject baseline and update submissions once submitted for approval. They cannot be Departmental Administrators or Project Editors within the same project.'); ?>
      </span>
    </a>
    <?php if (ict_project_access_project('manage_users', $user, $project_id)) : ?>
      <a href="<?php print url('project/' . $project_id . '/manage-users', array('query' => array('destination' => current_path()))); ?>" class="edit-btn">Edit</a>
    <?php endif; ?>
  </div>
  <div class="text">
    <?php foreach ($data_approvers as $email) : ?>
      <a class="email-value" href="mailto:<?php print $email; ?>"><?php print $email; ?></a>
    <?php endforeach; ?>
  </div>
</div>

<div class="row">
  <div class="label">
    <?php print t('Project Editors'); ?>
    <a href="javascript:void(0);" class="tooltip">
      <i class="tooltip-icon"></i>
      <span class="tooltip-content">
        <?php print t('Project Editors can review, edit and submit baseline and update submissions for approval. They cannot be Project Approvers within the same project.'); ?>
      </span>
    </a>
    <?php if (ict_project_access_project('manage_users', $user, $project_id)) : ?>
      <a href="<?php print url('project/' . $project_id . '/manage-users', array('query' => array('destination' => current_path()))); ?>" class="edit-btn">Edit</a>
    <?php endif; ?>
  </div>
  <div class="text">
    <?php foreach ($data_editors as $email) : ?>
      <a class="email-value" href="mailto:<?php print $email; ?>"><?php print $email; ?></a>
    <?php endforeach; ?>
  </div>
</div>

