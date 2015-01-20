<div class="page-title dotbg">
	<div class="inner-title-content wrap cf">
		<h1>Update project</h1>
	</div>
</div>
<div id="inner-content" class="wrap cf">
	<h2>End financial year project reporting</h2>
	<div class="project-update-submission d-all">
		<form class="node-form node-project-form" action="/node/add/project" method="post" id="project-node-form" accept-charset="UTF-8">
			<table>
      <tr>
        <td class="label">
          <?php
          print $form['end_project_name_text']['#title'];
          ?>
        </td>
        <td class="text">
          <?php
          print render($form['end_project_name_text']);
          print render($form['field_end_project_name']);
          ?>
        </td>
      </tr>
				<tr>
					<td class="label">
						<?php
							print $form['field_end_project_stage']['und']['#title'];
						?>
					</td>
					<td class="text">
						<?php
							print render($form['field_end_project_stage']);
						?>
					</td>
				</tr>
				<tr><td colspan="2"><div class="dotted-line"></div></td></tr>

        <tr>
          <td class="label">
            <?php
            print $form['field_end_expected_project']['und']['#title'];
            ?>
          </td>
          <td class="text date">
            <input type="hidden" class="add_datepicker" id="<?php print $form['field_end_expected_project']['#id']; ?>">
            <?php
            print render($form['field_end_expected_project']['und'][0]['value']['day']);
            print render($form['field_end_expected_project']['und'][0]['value']['month']);
            print render($form['field_end_expected_project']['und'][0]['value']['year']);
            ?>
          </td>
        </tr>

      <tr>
        <td class="label">
          <?php
          print $form['field_end_internal_fte']['und']['#title'];
          ?>
        </td>
        <td class="text">
          <?php
          print render($form['field_end_internal_fte']);
          ?>
        </td>
      </tr>

      <tr>
        <td class="label">
          <?php
          print $form['field_end_external_fte']['und']['#title'];
          ?>
        </td>
        <td class="text">
          <?php
          print render($form['field_end_external_fte']);
          ?>
        </td>
      </tr>

				<tr>
					<td class="label vtop">
						<?php
							print $form['field_end_project_manager']['und']['#title'];
						?>
					</td>
					<td class="text">
						<?php
							print render($form['field_end_project_manager']);
						?>
					</td>
				</tr>

        <tr>
          <td class="label">
            <?php
            print $form['field_end_project_manager_email']['und']['#title'];
            ?>
          </td>
          <td class="text">
            <?php
            print render($form['field_end_project_manager_email']);
            ?>
          </td>
        </tr>

        <tr>
          <td class="label">
            <?php
            print ict_project_bracket_italics($form['field_end_revised_total_project']['und']['#title']);
            ?>
          </td>
          <td class="text">
            <?php
            print render($form['field_end_revised_total_project']);
            ?>
          </td>
        </tr>

        <tr>
          <td class="label">
            <?php
            print ict_project_bracket_italics($form['field_end_total_project_spend']['und']['#title']);
            ?>
          </td>
          <td class="text">
            <?php
            print render($form['field_end_total_project_spend']);
            ?>
          </td>
        </tr>


        <tr>
          <td class="label">
            <?php
            print ict_project_bracket_italics($form['field_end_total_project_current']['und']['#title']);
            ?>
          </td>
          <td class="text">
            <?php
            print render($form['field_end_total_project_current']);
            ?>
          </td>
        </tr>

        <tr>
          <td class="label">
            <?php
            print ict_project_bracket_italics($form['field_end_predicted_budget']['und']['#title']);
            ?>
          </td>
          <td class="text">
            <?php
            print render($form['field_end_predicted_budget']);
            ?>
          </td>
        </tr>

        <tr>
          <td class="label">
            <?php
            print $form['field_end_project_completed']['und']['#title'];
            ?>
          </td>
          <td class="text">
            <?php
            print render($form['field_end_project_completed']);
            ?>
          </td>
        </tr>

        <tr>
          <td class="label">
            <?php
            print ict_project_bracket_italics($form['field_end_predicted_project']['und']['#title']);
            ?>
          </td>
          <td class="text">
            <?php
            print render($form['field_end_predicted_project']);
            ?>
          </td>
        </tr>

        <tr>
          <td class="label">
            <?php
            print ict_project_bracket_italics($form['field_end_predicted_realised']['und']['#title']);
            ?>
          </td>
          <td class="text">
            <?php
            print render($form['field_end_predicted_realised']);
            ?>
          </td>
        </tr>

        <tr>
          <td class="label">
            <?php
            print $form['field_end_project_status']['und']['#title'];
            ?>
          </td>
          <td class="text">
            <?php
            print render($form['field_end_project_status']);
            ?>
          </td>
        </tr>

        <tr>
          <td class="label">
            <?php
            print $form['field_end_agency_comments']['und']['#title'];
            ?>
          </td>
          <td class="text">
            <?php
            print render($form['field_end_agency_comments']);
            ?>
          </td>
        </tr>
      </table>


      <h2>Submit CSV</h2>
      <table>
        <tr>
          <td class="label">
            Export form fields as CSV file
          </td>
          <td class="text">
            <?php print l(t('Export'), file_create_url('public://export_end.csv'), array('attributes' => array('class' => 'export-btn')));?>
          </td>
        </tr>
        <tr>
          <td class="label">
            CSV File
            <span>Enter path to CSV file</span>
          </td>
          <td class="text">
              <?php print render($form['field_end_csv_file']);?>
          </td>
        </tr>
      </table>
      <div class="submit">
        <?php print drupal_render($form['preview']); ?>
        <?php print drupal_render($form['actions']); ?>
      </div>

      <div style="display:none;">
        <?php
        print drupal_render_children($form);
        ?>
      </div>

		</form>
	</div>
</div>