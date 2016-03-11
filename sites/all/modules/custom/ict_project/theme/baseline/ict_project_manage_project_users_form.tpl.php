<div class="page-title dotbg">
	<div class="inner-title-content wrap cf">
		<h1><?php print t('Manage Project Users'); ?></h1>
	</div>
</div>
<div id="inner-content" class="wrap cf">
	<h2><?php print t('Project Information'); ?></h2>
	<div class="project-update-submission d-all">

		<div class="row">
			<div class="label">
				<?php print 'Project Title' ?>
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

		<div class="row">
			<div class="label">
				<?php print t('Department'); ?>
				<?php if (!empty($form['field_department_description'])): ?>
					<a class="tooltip" href="javascript:void(0);">
						<i class="tooltip-icon"></i>
							<span class="tooltip-content">
								<?php render($form['field_department_description']); ?>
							</span>
					</a>
				<?php endif; ?>
			</div>
			<div class="text">
				<?php print render($form['department']); ?>
			</div>
		</div>


		<div class="user-information"><h2><?php print t('User Information'); ?></h2></div>

		<?php print render($form['emails']); ?>

		<div class="submit">
			<?php print render($form['submit']) ;?>
		</div>

		<div style="display:none;">
			<?php print drupal_render_children($form); ?>
		</div>
	</div>
</div>
