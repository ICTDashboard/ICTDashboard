<div class="panel-2col-stacked clear-block panel-display" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <div class="center-wrapper">

    <div class="panel-col-top panel-panel">
        <div class="panel-col-top panel-panel">
        <?php if ($content['content']): ?>
        <div class="inside"><?php print $content['content']; ?></div>
        <?php endif; ?>
        </div>
    </div>

		<div class="panel-col-last-end"></div>
  </div>
</div>