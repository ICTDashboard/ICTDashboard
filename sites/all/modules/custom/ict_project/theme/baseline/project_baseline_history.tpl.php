<div id="project-baseline-history">
	<div class="page-title dotbg">
	  <div class="inner-title-content wrap cf">
	    <h1><?php print t('Baseline History for !project', array('!project' => $current_baseline->title)); ?></h1>
	  </div>
	</div>

	<div id="inner-content" class="wrap cf">
		<h2><?php print t('Current Baseline'); ?></h2>
		<div class="project-draft-submission d-all ict-view-page">
			<div class="row">
				<div class="label">
					<?php print t('Active from'); ?>
				</div>
				<div class="text">
					<?php print $current_baseline->first_update ? date('d M Y', $current_baseline->first_update): t('Not active yet'); ?>
				</div>
			</div>
			<div class="row">
				<div class="label">
					<?php print t('Original Approved Start Date'); ?>
				</div>
				<div class="text">
					<?php print date('d M Y', strtotime($current_baseline->field_start_date['und'][0]['value'])); ?>
				</div>
			</div>
			<div class="row">
				<div class="label">
					<?php print t('Original Approved Completion Date'); ?>
				</div>
				<div class="text">
					<?php print date('d M Y', strtotime($current_baseline->field_original_completion_date['und'][0]['value'])); ?>
				</div>
			</div>
			<div class="row">
				<div class="label">
					<?php print t('Total Project Budget'); ?>
				</div>
				<div class="text">
					<?php print '$' . $current_baseline->field_original_total_budget . 'm'; ?>
				</div>
			</div>
			<div class="pbh-buttons">
				<a href="<?php print url('node/' . $current_baseline->nid); ?>" class="general-button arrow-right">
					<span><?php print t('View Project'); ?></span>
				</a>
			</div>
		</div>
		<h2><?php print t('Previous Baselines (!count)', array('!count' => $count_baselines)); ?></h2>
		<?php foreach($old_baselines as $key => $project): ?>
			<div class="project-history">
				<div class="label">
					<?php print $count_baselines--; ?>.
				</div>
				<div class="project-draft-submission ict-view-page sub-content">
					<div class="row">
						<div class="label">
							<?php print t('Active from'); ?>
						</div>
						<div class="text">
							<?php print date('d M Y', $project->first_update); ?> - 
							<?php print $project->unpublished_on ? date('d M Y', $project->unpublished_on) : t('Still active'); ?>
						</div>
					</div>
					<div class="row">
						<div class="label">
							<?php print t('Original Approved Start Date'); ?>
						</div>
						<div class="text">
							<?php print date('d M Y', strtotime($project->field_start_date['und'][0]['value'])); ?>
						</div>
					</div>
					<div class="row">
						<div class="label">
							<?php print t('Original Approved Completion Date'); ?>
						</div>
						<div class="text">
							<?php print date('d M Y', strtotime($project->field_original_completion_date['und'][0]['value'])); ?>
						</div>
					</div>
					<div class="row">
						<div class="label">
							<?php print t('Total Project Budget'); ?>
						</div>
						<div class="text">
							<?php print '$' . $project->field_original_total_budget . 'm'; ?>
						</div>
					</div>
					<div class="pbh-buttons">
						<a href="<?php print url('node/' . $project->nid); ?>" class="general-button arrow-right">
							<span><?php print t('View last update'); ?></span>
						</a>
					</div>
				</div>
			</div>
		<?php endforeach; ?>
	</div>
</div>