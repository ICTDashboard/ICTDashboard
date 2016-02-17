<div class="page-title dotbg">
	<div class="inner-title-content wrap cf">
		<h1><?php print t('Create Project'); ?></h1>
	</div>
</div>
<div id="inner-content" class="wrap cf project-update-submission">
	<h3><?php print t('Basic Project Information'); ?></h3>
	<div class="project-update-submission d-all">
		<form class="node-form node-project-form" action="/node/add/project" method="post" id="project-node-form" accept-charset="UTF-8">

			<div class="row">
				<div class="label">
					<?php print $form['field_portfolio_name']['#title']; ?>
					<?php if (!empty($form['field_portfolio_name_description'])): ?>
						<a class="tooltip" href="javascript:void(0);">
							<i class="tooltip-icon"></i>
							<span class="tooltip-content">
								<?php print render($form['field_portfolio_name_description']); ?>
							</span>
						</a>
					<?php endif; ?>
				</div>
				<div class="text">
					<?php print render($form['field_portfolio_name']); ?>
				</div>
			</div>

			<div class="row">
				<div class="label">
					<?php print $form['field_government_entity_name']['#title']; ?>
					<?php if (!empty($form['field_government_entity_name_description'])): ?>
						<a class="tooltip" href="javascript:void(0);">
							<i class="tooltip-icon"></i>
							<span class="tooltip-content">
								<?php print render($form['field_government_entity_name_description']); ?>
							</span>
						</a>
					<?php endif; ?>
				</div>
				<div class="text">
					<?php print render($form['field_government_entity_name']); ?>
				</div>
			</div>

			<div class="row">
				<div class="label">
					<?php print $form['title']['#title']; ?>
					<a href="javascript:void(0);" class="tooltip">
						<i class="tooltip-icon"></i>
						<span class="tooltip-content">
							<?php print t('The official full name of the project, excluding acronyms.'); ?>
						</span>
					</a>
				</div>
				<div class="text">
					<?php print render($form['title']); ?>
				</div>
			</div>

			<div class="dotted-line"></div>

			<h3><?php print t('User Information'); ?></h3>

			<div class="row">
				<div class="label">
					<?php print $form['field_department']['#title']; ?>
				</div>
				<div class="text">
					<?php print render($form['field_department']); ?>
				</div>
			</div>
			<?php print render($form['emails']); ?>
      <div style="display:none;">
        <?php
        print drupal_render_children($form);
        ?>
      </div>
			<div class="submit">
        <?php print render($form['submit']) ;?>
      </div>
		</form>
	</div>
</div>