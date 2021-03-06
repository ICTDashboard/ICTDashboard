<div class="page-title dotbg">
	<div class="inner-title-content wrap cf">
		<h1><?php print empty($form['#page_title']) ? t('Create Project') : $form['#page_title']; ?></h1>
	</div>
</div>
<div id="inner-content" class="wrap cf project-update-submission">
	<h2><?php print t('Project Information'); ?></h2>
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

			<div class="user-information"><h2>
			<?php print t('User Information'); ?>
				<a href="javascript:void(0);" class="tooltip">
			        <i class="tooltip-icon"></i>
			        <span class="tooltip-content">
			          <?php print variable_get('ict_project_user_information_text', "No user information is made publicly available."); ?>
			        </span>
		      </a>
	      	</h2>
	    	</div>

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
				<a class="export-btn" href="<?php print url('projects')?>"><span><?php print t('Cancel'); ?></span></a>
				<?php if (empty($form['baseline']['#value'])) : ?>
        	<?php print render($form['submit']) ;?>
				<?php else : ?>
					<div id="hidden-submit" style="display:none"><?php print render($form['submit']) ;?></div>
					<a href="#ict-create-rebaseline" class="fancybox-inline submit-button">
						<span><?php print t('Create Re-baseline'); ?></span>
					</a>
					<div style="display: none;" id="ict-create-rebaseline" class="ict-rebaseline-warn">
						<?php $bean = bean_load_delta('opt-out-policy'); ?>
						<h2 class="fancybox-title"><?php print t('Warning'); ?></h2>
						<div class="ict-fancy-content entity-bean">
							<div class="field">
								<p>
									<?php print t('You are about to create a re-baselined project. Project @BASELINE’s details cannot be edited once a re-baselined project is created. Project @BASELINE will remain published on the dashboard until the first re-baselined update has been approved.', array(
										'@BASELINE' => check_plain($form['baseline']['#value']->title)
									)); ?>
								</p>
								<strong>
                          			<?php print t('Please note this change is permanent.') ?>
                        		</strong>
                        		<p>
                        			<?php print t('Do you want to continue?') ?>
                        		</p>
							</div>
						</div>
						<div class="fancybox-actions">
							<a class="ict-fancybox-close export-btn" href="#"><span><?php print t('No'); ?></span></a>
							<a class="general-button arrow-right confirm-proceed" href="javascript:void(0);" onclick="jQuery('#hidden-submit input[type=submit]').click()">
								<span>
									<?php print t('Yes'); ?>
								</span>
							</a>
						</div>
					</div>
				<?php endif; ?>
      </div>
		</form>
	</div>
</div>
