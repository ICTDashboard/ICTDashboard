Drupal.behaviors.projectsTablePerPage = {
    attach: function(context) {
        jQuery('.ict-projects-table-perpage', context).change(function(){
            var url = Drupal.settings.ict.base_path + '&per_page=' + jQuery('option:selected', this).val();
            console.log(url);
            window.location.href = url;
        });
    }
}
