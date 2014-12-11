<div class="page-title dotbg">
	<div class="inner-title-content wrap cf">
		<h1>ICT Project Submission Form</h1>
	</div>
</div>
<div id="inner-content" class="wrap cf">
	<h2>Baseline data</h2>
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
						<?php
							print render($form['field_brief_project_summary']);
						?>
					</td>
				</tr>

				<tr>
					<td class="label">
						<?php
							print $form['field_program_name']['und']['#title'];
						?>
					</td>
					<td class="text">
						<?php
							print render($form['field_program_name']);
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
				<tr><td colspan="2"><div class="dotted-line"></div></td></tr>
				
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
				<tr>
					<td class="label">
						<?php
							print substr($form['field_total_project_budget']['und']['#title'], 0, 22).'<em>'.substr($form['field_total_project_budget']['und']['#title'], 22, -1).'</em>'.substr($form['field_total_project_budget']['und']['#title'], -1);
						?>
					</td>
					<td class="text">
						<?php
							print render($form['field_total_project_budget']);
						?>
					</td>
				</tr>
        <tr>
          <td colspan="2">
            <?php
              print render($form['field_rebaselined_total_budget']);
            ?>
          </td>
        </tr>
				<tr>
					<td class="label">
						<?php
							print substr($form['field_expected_project_benefits']['und']['#title'], 0, 27).'<em>'.substr($form['field_expected_project_benefits']['und']['#title'], 27, -1)
							.'</em>'.substr($form['field_expected_project_benefits']['und']['#title'], -1);
						?>
					</td>
					<td class="text">
						<?php
							print render($form['field_expected_project_benefits']);
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
						<?php
							print render($form['field_start_date']['und'][0]['value']['day']);
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
							print $form['field_government_programme']['und']['#title'];
						?>
					</td>
					<td class="text">
						
							<?php
							print render($form['field_government_programme']);
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
							print $form['field_total_spent_to_date']['und']['#title'];
						?>
					</td>
					<td class="text">
						<?php
							print render($form['field_total_spent_to_date']);
						?>
					</td>
				</tr>
				<tr>
					<td class="label">
						<?php
							print $form['field_expected_number_of_gov_fte']['und']['#title'];
						?>
					</td>
					<td class="text">
						<?php
							print render($form['field_expected_number_of_gov_fte']);
						?>
					</td>
				</tr>
				<tr>
					<td class="label">
						<?php
							print $form['field_expected_num_contractors']['und']['#title'];
						?>
					</td>
					<td class="text">
						<?php
							print render($form['field_expected_num_contractors']);
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
			<p class="submit"><input type="submit" id="edit-submit" name="op" value="Save" class="form-submit"></p>
		</form>
	</div>
</div>