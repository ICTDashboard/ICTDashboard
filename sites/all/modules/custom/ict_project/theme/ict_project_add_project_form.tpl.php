<div class="page-title dotbg">
	<div class="inner-title-content wrap cf">
		<h1>ICT Project Submission Form</h1>
	</div>
</div>
<div id="inner-content" class="wrap cf">
	<div class="project-update-submission d-all">
		<form class="node-form node-project-form" action="/node/add/project" method="post" id="project-node-form" accept-charset="UTF-8">
			<table>
				<tr>
					<td class="label">
						<?php
							print $form['field_government_entity_name']['und']['#title'];
						?>
					</td>
					<td class="text">
						<?php
							print render($form['field_government_entity_name']);
						?>
					</td>
				</tr>
				<tr>
					<td class="label">
						<?php
							print $form['field_government_business_unit']['und']['#title'];
						?>
					</td>
					<td class="text">
						<?php
							print render($form['field_government_business_unit']);
						?>
					</td>
				</tr>
        <tr>
          <td class="label">
            <?php
              print ict_project_bracket_italics ($form['field_program_name']['und']['#title']);
            ?>
            <?php ?>
          </td>
          <td class="text">
            <?php
            print render($form['field_program_name']);
            ?>
          </td>
        </tr>
				<tr><td colspan="2"><div class="dotted-line"></div></td></tr>
				
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

				<tr>
					<td class="label vtop">
						<?php
							print $form['field_brief_project_summary']['und']['#title'];
						?>
					</td>
					<td class="text">
            <?php print render($form['field_brief_project_summary_fake']); ?>
						<div class="element-hidden"><?php print render($form['field_brief_project_summary']); ?></div>
					</td>
				</tr>

        <tr>
          <td class="label">
            <?php
            print $form['field_implementation_partners']['und']['#title'];
            ?>
            <span>A list of any implementation partners for the project. This includes primary contractors and any formally supporting Government entities.</span>
          </td>
          <td class="text">
            <?php
            print render($form['field_implementation_partners']);
            ?>
          </td>
        </tr>

        <tr>
          <td class="label">
            <?php
            print $form['field_internal_fte']['und']['#title'];
            ?>
          </td>
          <td class="text">

            <?php
            print render($form['field_internal_fte']);
            ?>

          </td>
        </tr>


        <tr>
          <td class="label">
            <?php
            print $form['field_external_fte']['und']['#title'];
            ?>
          </td>
          <td class="text">

            <?php
            print render($form['field_external_fte']);
            ?>

          </td>
        </tr>

        <tr>
          <td class="label">
            <?php
            print $form['field_start_date']['und']['#title'];
            ?>
          </td>
          <td class="text date">
            <input type="hidden" class="add_datepicker" id="<?php print $form['field_start_date']['#id']; ?>">
            <?php
            print drupal_render($form['field_start_date']['und'][0]['value']['day']);
            print render($form['field_start_date']['und'][0]['value']['month']);
            print render($form['field_start_date']['und'][0]['value']['year']);
            ?>
          </td>
        </tr>
        <tr>
          <td class="label">
            <?php
            print $form['field_original_completion_date']['und']['#title'];
            ?>
          </td>
          <td class="text date">
            <input type="hidden" class="add_datepicker" id="<?php print $form['field_original_completion_date']['#id']; ?>">
            <?php
            print render($form['field_original_completion_date']['und'][0]['value']['day']);
            print render($form['field_original_completion_date']['und'][0]['value']['month']);
            print render($form['field_original_completion_date']['und'][0]['value']['year']);
            ?>
          </td>
        </tr>


        <tr>
          <td class="label">
            <?php
            print $form['field_rebaselined_project_start']['und']['#title'];
            ?>
          </td>
          <td class="text date">
            <input type="hidden" class="add_datepicker" id="<?php print $form['field_rebaselined_project_start']['#id']; ?>">
            <?php
            print render($form['field_rebaselined_project_start']['und'][0]['value']['day']);
            print render($form['field_rebaselined_project_start']['und'][0]['value']['month']);
            print render($form['field_rebaselined_project_start']['und'][0]['value']['year']);
            ?>
          </td>
        </tr>



        <tr>
          <td class="label">
            <?php
            print $form['field_rebaselined_project_compl']['und']['#title'];
            ?>
          </td>
          <td class="text date">
            <input type="hidden" class="add_datepicker" id="<?php print $form['field_rebaselined_project_compl']['#id']; ?>">
            <?php
            print render($form['field_rebaselined_project_compl']['und'][0]['value']['day']);
            print render($form['field_rebaselined_project_compl']['und'][0]['value']['month']);
            print render($form['field_rebaselined_project_compl']['und'][0]['value']['year']);
            ?>
          </td>
        </tr>

				<tr>
					<td class="label">
						<?php
							print $form['field_project_stage']['und']['#title'];
						?>
					</td>
					<td class="text">
						<?php
							print render($form['field_project_stage']);
						?>
					</td>
				</tr>
				<tr>
					<td class="label">
						<?php
							print $form['field_project_category']['und']['#title'];
						?>
					</td>
					<td class="text">
						
							<?php
							print render($form['field_project_category']);
						?>

					</td>
				</tr>

        <tr>
          <td class="label">
            <?php
            print $form['field_expenditure_type']['und']['#title'];
            ?>
          </td>
          <td class="text">

            <?php
            print render($form['field_expenditure_type']);
            ?>

          </td>
        </tr>

        <tr>
          <td class="label">
            <?php
            print $form['field_project_manager']['und']['#title'];
            ?>
          </td>
          <td class="text">
            <?php
            print render($form['field_project_manager']);
            ?>
          </td>
        </tr>
        <tr>
          <td class="label">
            <?php
            print $form['field_project_manager_email']['und']['#title'];
            ?>
          </td>
          <td class="text">
            <?php
            print render($form['field_project_manager_email']);
            ?>
          </td>
        </tr>

				<tr><td colspan="2"><div class="dotted-line"></div></td></tr>

				<tr>
					<td class="label">
						<?php
							print ict_project_bracket_italics ($form['field_total_project_budget']['und']['#title']);
						?>
					</td>
					<td class="text">
						<?php
							print render($form['field_total_project_budget']);
						?>
					</td>
				</tr>

        <tr>
          <td class="label">
            <?php print ict_project_bracket_italics ($form['field_original_total_budget']['und']['#title']); ?>
          </td>
          <td class="text">
            <?php
            print render($form['field_original_total_budget']);
            ?>
          </td>
        </tr>

        <tr>
          <td class="label">
            <?php
            print ict_project_bracket_italics ($form['field_rebaselined_total_project']['und']['#title']);
            ?>
          </td>
          <td class="text">
            <?php
            print render($form['field_rebaselined_total_project']);
            ?>
          </td>
        </tr>


        <tr>
          <td class="label">
            <?php print ict_project_bracket_italics ($form['field_rebaselined_total_budget']['und']['#title']); ?>
          </td>
          <td class="text">
            <?php
              print render($form['field_rebaselined_total_budget']);
            ?>
          </td>
        </tr>

        <tr>
          <td class="label">
            <?php
              print ict_project_bracket_italics ($form['field_predicted_project_benefit']['und']['#title']);
            ?>
          </td>
          <td class="text">

            <?php
              print render($form['field_predicted_project_benefit']);
            ?>

          </td>
        </tr>

        <tr>
          <td class="label">
            <?php
            print $form['field_project_status']['und']['#title'];
            ?>
          </td>
          <td class="text">

            <?php
            print render($form['field_project_status']);
            ?>

          </td>
        </tr>

				<?php
				global $user;

				if (in_array('administrator', $user->roles)) {

				?>
				<tr>
					<td class="label">
						<?php
						print $form['field_project_users']['und']['#title'];
						?>
					</td>
					<td class="text">
						<?php
						print render($form['field_project_users']['und']);
						?>
					</td>
				</tr>
				<?php } ?>
			</table>
      <div style="display:none;">
        <?php
        print drupal_render_children($form);
        ?>
      </div>
			<p class="submit">
        <?php print render($form['preview']) ;?>
        <input type="submit" id="edit-submit" name="op" value="Save" class="form-submit"></p>
		</form>
	</div>
</div>
