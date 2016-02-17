<div class="row">
  <div class="label">
    <?php print t('Project Approvers'); ?>
    <a class="tooltip" href="javascript:void(0);">
      <i class="tooltip-icon"></i>
      <span class="tooltip-content">
        Project Approvers can review, approve or reject baseline and update submissions once submitted for approval. They can not be Departmental Administrators or Editors within the same project.
      </span>
    </a>
    <span class="form-helptext">
      <em><?php print t('<a href="!url">Invite a new user</a> or enter the email of an existing user below.', array(
          '!url' => url('user/create', array(
              'query' => array('destination' => current_path()))
          )
        )); ?></em>
    </span>
  </div>
  <div class="text">
    <?php print render($element['approvers']); ?>
  </div>
</div>

<div class="row">
  <div class="label">
    <?php print t('Project Editors'); ?>
    <a class="tooltip" href="javascript:void(0);">
      <i class="tooltip-icon"></i>
      <span class="tooltip-content">
        Project Editors can review, edit and submit baseline and update submissions for approval. They can not be Departmental Administrators or Approvers within the same project.
      </span>
    </a>
    <span class="form-helptext">
     <em><?php print t('<a href="!url">Invite a new user</a> or enter the email of an existing user below.', array(
          '!url' => url('user/create', array(
            'query' => array('destination' => current_path()))
          )
        )); ?></em>
    </span>
  </div>
  <div class="text">
    <?php print render($element['editors']); ?>
  </div>
</div>

