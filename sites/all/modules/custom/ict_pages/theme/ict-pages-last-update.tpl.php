<?php if (!empty($result)) : ?>
<div class="last-updated-block">	
	<div class="last-updated-on wrap cf">
	  <p><strong><?php print t('Information Last Updated on'); ?></strong></p>
	  <p><span><?php print format_date($result, 'medium', 'd F Y'); ?></span></p>
	</div>
  	<div class= "view-baseline-history"><a href="<?php print url('project/' . $nid . '/history'); ?>" class="view-baseline-link">View Baseline History</a>
  		<a href="javascript:void(0);" class="tooltip view-baseline-tooltip">
	        <i class="tooltip-icon"></i>
	      	<span class="tooltip-content">
	        	<?php print variable_get('ict_project_last_updated_tooltip_text', "Click to view the previous Baselines for this project."); ?>
	      	</span>
    	</a>
    </div>
</div>              
<?php endif; ?>