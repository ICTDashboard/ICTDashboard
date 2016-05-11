<?php if (!empty($result)) : ?>
<?php $projects =ict_project_get_all_rebaselines($nid); $parents = ict_project_get_all_parents_project($nid);?>
<div class="last-updated-block">	
	<div class="last-updated-on wrap cf">
	  <p><strong><?php print t('Information Last Updated on'); ?></strong></p>
	  <p><span><?php print format_date($result, 'medium', 'd F Y'); ?></span></p>
	</div>
	<?php if (!empty($nid)) : ?>
  	<div class= "view-baseline-history">
  		<?php if(ict_project_is_rebaseline($nid)) : ?>
  			<?php if(ict_project_get_last_rebaseline_project($nid)) : ?>
  				<?php $rebaseline = (ict_project_get_last_rebaseline_project($nid)); ?>
	  			<a href="<?php print url('project/' . $rebaseline. '/history'); ?>" class="view-baseline-link">View Baseline History (<?php print count($projects); ?>)</a>
	  			<a href="javascript:void(0);" class="tooltip view-baseline-tooltip">
			        <i class="tooltip-icon"></i>
			      	<span class="tooltip-content">
			        	<?php print variable_get('ict_project_last_updated_tooltip_text', "Click to view the previous (" . count($projects) . ") Baselines for this project."); ?>
			      	</span>
    			</a>
	  		<?php else : ?>
	  			<a href="<?php print url('project/' . $nid . '/history'); ?>" class="view-baseline-link">View Baseline History(<?php print count($parents); ?>)</a>
	  			<a href="javascript:void(0);" class="tooltip view-baseline-tooltip">
			        <i class="tooltip-icon"></i>
			      	<span class="tooltip-content">
			        	<?php print variable_get('ict_project_last_updated_tooltip_text', "Click to view the previous (" . count($parents) . ") Baselines for this project."); ?>
			      	</span>
    			</a>
	  		<?php endif; ?>
  		<?php else : ?>
				<?php if(ict_project_get_last_rebaseline_project($nid)) : ?>
					<?php $rebaseline = (ict_project_get_last_rebaseline_project($nid)); ?>
					<a href="<?php print url('project/' . $rebaseline . '/history'); ?>" class="view-baseline-link">View Baseline History (<?php print count($projects); ?>)</a>
					<a href="javascript:void(0);" class="tooltip view-baseline-tooltip">
							<i class="tooltip-icon"></i>
							<span class="tooltip-content">
								<?php print variable_get('ict_project_last_updated_tooltip_text', "Click to view the previous (" . count($projects) . ") Baselines for this project."); ?>
							</span>
					</a>
				<?php endif; ?>
			<?php endif; ?>
    </div>
	<?php endif; ?>
</div>              
<?php endif; ?>