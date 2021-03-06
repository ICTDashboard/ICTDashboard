<?php if (!empty($result)) : ?>
<div class="last-updated-block">
	<div class="last-updated-and-active-block">	
		<div class="last-updated-on wrap cf">
		  <p><strong><?php print t('Information Last Updated on'); ?></strong></p>
		  <p><span><?php print format_date($result, 'medium', 'd F Y'); ?></span></p>
		</div>
		<?php if($active_from) : ?>
		<div class="induvidual-project-state">
			<p><strong><?php print t('Active From'); ?></strong>
				<a href="javascript:void(0);" class="tooltip">
		        	<i class="tooltip-icon"></i>
		        	<span class="tooltip-content">
		          		<?php print variable_get('ict_project_active_from_to_active_state_tooltip_text', "The date range when the project was published on the Dashboard"); ?>
		        	</span>
		     	</a>
			</p>
			<p><?php print date('d M Y', $active_from); ?> - 
				<?php print $active ? date('d M Y', $active) : t('Still active'); ?></p>
		</div>
		<?php endif; ?>
		</div>
		<?php if (!empty($nid) && ($projects > 1)) : ?>
	  	<div class= "view-baseline-history">
	  			<div>
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
<!-- Link to Data.gov.au  -->
<!-- 			<div class="external-link-to-data-gov">
					<a href="http://data.gov.au">
						<?php print t('View data in data.gov.au'); ?>
					</a>
				</div> -->
	    </div>
	<?php endif; ?>
</div>              
<?php endif; ?>