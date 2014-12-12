<div class="page-title dotbg">
	<div class="inner-title-content wrap cf">
		<h1>ICT Project Update Form</h1>
	</div>
</div>
<div id="inner-content" class="wrap cf">
				<h2>Regular reporting data</h2>
				<div class="project-update-submission d-all">
						<table>
							<?php
								foreach ($form as $key => &$value) {
									//skip attributes
									if ($key[0] === '#') continue;
									switch ($key) {
										case 'submitted':
											foreach ( $value as $fname => $field){
												if ($fname[0] === '#') continue; //skip attributes
												$form[$key][$fname]['#title_display'] = 'invisible';
												$tmp_desc = @$form[$key][$fname]['#description'];
												$tmp_desc = $tmp_desc ? "<span>$tmp_desc</span>" : '';
												$form[$key][$fname]['#description'] = '';
												$second_row = '';
												switch ($field['#type']) {
													case 'select':
														//if defined GET['project'] - select value from list and make select disabled
														if ($form[$key][$fname]['#id'] === 'edit-submitted-project' && isset($_GET['project']) && is_numeric($_GET['project'])){
															$second_row .= "<input type='hidden' name='{$key}[{$fname}]' value='{$_GET['project']}' />";
															$second_row .= "<script>window.onload = function(){var select = document.querySelector(\"#edit-submitted-project [value='{$_GET['project']}']\"); if (!select) return; select.setAttribute('selected', 'selected'); select.parentNode.setAttribute('disabled', 'disabled');}</script>";
														}
													case 'webform_number':
													case 'textarea':
													case 'radios':
													case 'textfield':
													case 'email':
													case 'file':
													case 'number':
													case 'time':
													// case 'markup':
														$second_row .= render($form[$key][$fname]);
														break;
													case 'date':
														$form[$key][$fname]['day']['#wrapper_class'][] = 
														$form[$key][$fname]['month']['#wrapper_class'][] = 
														$form[$key][$fname]['year']['#wrapper_class'][] = 'd-1of3'; //styling - 3 in row
                            $form[$key][$fname]['year']['#wrapper_class'][] = 'last-col';
														$second_row .=	render($form[$key][$fname]['day']).
																render($form[$key][$fname]['month']).
																render($form[$key][$fname]['year']);
													break;
												}
												if ($second_row) 
													print	'<tr><td class="label">'.
															$form[$key][$fname]['#title'].
															$tmp_desc.
															'</td><td class="text">'.
															$second_row.
															'</td></tr>';
											}
											break;
									}
								}
							?>
						</table>
						<p class="submit"><?php print drupal_render($form['actions']['submit']) ?></p>
						<div style="display: none">
						<?php print drupal_render_children($form) ?>
						</div>

						<h2>Submit CSV</h2>
						<table>
							<tr>
								<td class="label">
									Export form fields as CSV file
								</td>
								<td class="text">
									<?php
										print render($form['export_csv']);
									?>
								</td>
							</tr>
							<tr>
								<td class="label">
									<?php
										print $form['csv_file']['#title'];
									?>
									<span>Enter path to CSV file</span>
								</td>
								<td class="text">
									<?php
										print render($form['csv_file']);
									?>
								</td>
							</tr>
						</table>
						<p class="submit">
							<?php
								print render($form['actions']['submit_csv']);
							?>
						</p>
				</div>

			</div>