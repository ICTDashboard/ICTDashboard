<div class="page-title dotbg">
	<div class="inner-title-content wrap cf">
		<h1>Create project</h1>
	</div>
</div>
<div id="inner-content" class="wrap cf">
	<h3><?php print t('Basic Project Information'); ?></h3>
	<div class="project-update-submission d-all">
		<form class="node-form node-project-form" action="/node/add/project" method="post" id="project-node-form" accept-charset="UTF-8">
			<table>
        <tr>
          <td class="label">
            <?php
            print $form['field_portfolio_name']['#title'];
            ?>
          </td>
          <td class="text">
            <?php
            print render($form['field_portfolio_name']);
            ?>
          </td>
        </tr>

				<tr>
					<td class="label">
						<?php
							print $form['field_government_entity_name']['#title'];
						?>
					</td>
					<td class="text">
							<?php print render($form['field_government_entity_name']); ?>
					</td>
				</tr>

				<tr>
					<td class="label">
						<?php
							print $form['title']['#title'];
						?>
					</td>
					<td class="text">
						<?php
							print render($form['title']);
						?>
					</td>
				</tr>

				<tr><td colspan="2"><div class="dotted-line"></div></td></tr>

				<tr><td colspan="2"><h3>User Information</h3></td></tr>

        <tr>
          <td class="label">
            <?php
            print $form['field_department']['#title'];
            ?>
          </td>
          <td class="text">
            <?php
            print render($form['field_department']);
            ?>
          </td>
        </tr>
			</table>
			<?php print render($form['emails']); ?>
      <div style="display:none;">
        <?php
        print drupal_render_children($form);
        ?>
      </div>
			<p class="submit">
        <?php print render($form['submit']) ;?>
      </p>
		</form>
	</div>
</div>
