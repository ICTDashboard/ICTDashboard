<table id="ict-project-create-emails">
  <tr>
    <td class="label">
      <?php
      print t('Data Approvers');
      ?>
    </td>
    <td class="text">
      <?php
      print render($element['approvers']);
      ?>
    </td>
  </tr>

  <tr>
    <td class="label">
      <?php
      print t('Data Editors');
      ?>
    </td>
    <td class="text">
      <?php
      print render($element['editors']);
      ?>
    </td>
  </tr>
</table>