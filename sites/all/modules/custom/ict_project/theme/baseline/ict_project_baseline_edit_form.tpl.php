<div class="submit">
  <div style="margin-bottom: 20px; text-align: right;" class="text">
	<div class="other-option-buttons">
		<?php print render($form['edit']); ?>

    <div class="pdf_button submit">
      <span class="print_pdf"><a href="javascript:void(0);" title="Print this page." class="print-pdf export-btn" onclick="window.print(); return false" rel="nofollow">Print Preview</a></span>
    </div>
	</div>
    <?php print render($form['request_approve']); ?>
  </div>
</div>

<div style="display:none;">
  <?php print drupal_render_children($form); ?>
</div>
