<?php if (!empty($result)) : ?>
<div class="last-updated-block">	
	<div class="last-updated-on wrap cf">
	  <p><strong><?php print t('Information Last Updated on'); ?></strong></p>
	  <p><span><?php print format_date($result, 'medium', 'd F Y'); ?></span></p>
	</div>
	<?php if (!empty($nid) && ($projects > 1)) : ?>
  	<div class= "view-baseline-history">
			<a href="<?php print url('project/' . $last_rebaseline. '/history'); ?>" class="view-baseline-link">
				<?php print t('View Baseline History (!number)', array('!number' => $projects)); ?>
			</a>
			<a href="javascript:void(0);" class="tooltip view-baseline-tooltip">
					<i class="tooltip-icon"></i>
					<span class="tooltip-content">
						<?php print t('Click to view all (!projects) Baselines for this project.', array('!projects' => $projects)); ?>
					</span>
			</a>
    </div>
	<?php endif; ?>
</div>              
<?php endif; ?>