<div id="inner-content" class="wrap cf">
  <h2><?php print t('Update data'); ?></h2>
  <h3><?php print t('Update data'); ?></h3>
  <div class="project-update-submission d-all">
    <form class="node-form node-project-form" action="/node/add/project" method="post" id="project-node-form" accept-charset="UTF-8">
      <table>
        <tr>
          <td class="label">
            <?php print $form['field_spend_to_date_by_financial']['und']['#title']; ?>
          </td>
          <td class="text">
            <?php print render($form['field_spend_to_date_by_financial']); ?>
          </td>
        </tr>
        <tr>
          <td class="label">
            <?php print $form['field_expected_completion_date']['und']['#title']; ?>
          </td>
          <td class="text popup-radio">
            <?php print render($form['field_expected_completion_date']); ?>
          </td>
        </tr>
        <tr>
          <td class="label">
            <?php print $form['field_forecast_level_of_project_']['und']['#title']; ?>

          </td>
          <td class="text">
            <?php print render($form['field_forecast_level_of_project_']); ?>
          </td>
        </tr>

        <tr>
          <td class="label">
            <?php print $form['field_actual_level_of_project_co']['und']['#title']; ?>
          </td>
          <td class="text">
            <?php print render($form['field_actual_level_of_project_co']); ?>
          </td>
        </tr>
        <tr>
          <td class="label">
            <?php print $form['field_current_financial_benefits']['und']['#title']; ?>
          </td>
          <td class="text">
            <?php print render($form['field_current_financial_benefits']); ?>
          </td>
        </tr>
        <tr>
          <td class="label">
            <?php print $form['field_estimated_value_of_benefit']['und']['#title']; ?>
          </td>
          <td class="text">
            <?php print render($form['field_estimated_value_of_benefit']); ?>
          </td>
        </tr>
        <tr>
          <td class="label">
            <?php print $form['field_benefits_realised']['und']['#title']; ?>
          </td>
          <td class="text">
            <?php print render($form['field_benefits_realised']); ?>
          </td>
        </tr>
        <tr>
          <td class="label">
            <?php print $form['field_entity_comments']['und']['#title']; ?>
          </td>
          <td class="text">
            <?php print render($form['field_entity_comments']); ?>
          </td>
        </tr>
      </table>
      <p class="submit">
        <?php print render($form['preview']) ;?>
        <input type="submit" id="edit-submit" name="op" value="Save" class="form-submit"></p>
    </form>
  </div>
</div>

<div class="element-invisible">
  <?php print drupal_render_children($form); ?>
</div>
