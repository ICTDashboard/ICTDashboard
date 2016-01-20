<div class="row">
  <div class="label">
    <?php print t('Departmental Administrators'); ?>
    <a href="javascript:void(0);" class="tooltip">
      <i class="tooltip-icon"></i>
      <span class="tooltip-content">
       <?php print t('Departmental Administrators can create and assign Data Approvers to a project. They can not be Approvers or Editors within the same project.'); ?>
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
    <?php print t('Data Approvers'); ?>
    <a href="javascript:void(0);" class="tooltip">
      <i class="tooltip-icon"></i>
      <span class="tooltip-content">
        <?php print t('Data Approvers can review, approve or reject baseline and update submissions once submitted for approval. They can not be Departmental Administrators or Editors within the same project.'); ?>
      </span>
    </a>
  </div>
  <div class="text">
    <?php foreach ($data_approvers as $email) : ?>
      <a class="email-value" href="mailto:<?php print $email; ?>"><?php print $email; ?></a>
    <?php endforeach; ?>
  </div>
</div>

<div class="row">
  <div class="label">
    <?php print t('Data Editors'); ?>
    <a href="javascript:void(0);" class="tooltip">
      <i class="tooltip-icon"></i>
      <span class="tooltip-content">
        <?php print t('Data Editors can review, edit and submit baseline and update submissions for approval. They can not be Departmental Administrators or Approvers within the same project.'); ?>
      </span>
    </a>
  </div>
  <div class="text">
    <?php foreach ($data_editors as $email) : ?>
      <a class="email-value" href="mailto:<?php print $email; ?>"><?php print $email; ?></a>
    <?php endforeach; ?>
  </div>
</div>

