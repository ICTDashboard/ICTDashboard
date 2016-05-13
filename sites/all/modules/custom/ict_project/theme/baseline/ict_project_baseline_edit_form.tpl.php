<div class="submit">
  <div style="margin-bottom: 20px; text-align: right;" class="text">
	<div class="other-option-buttons">
		<?php print render($form['edit']); ?>
		<?php print print_pdf_insert_link(); ?>
	</div>
    <?php print render($form['request_approve']); ?>
  </div>
</div>

<div style="display:none;">
  <?php print drupal_render_children($form); ?>
</div>
