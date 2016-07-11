Drupal.behaviors.projectsTablePerPage = {
    attach: function(context) {
        jQuery('.ict-projects-table-perpage', context).change(function(){
            var url = Drupal.settings.ict.base_path + '&per_page=' + jQuery('option:selected', this).val() + '#ict-home-projects-table-id';
            window.location.href = url;
        });
    }
}

Drupal.behaviors.pager_fragments = {
    attach: function (context, settings) {
        var pager_links = jQuery('#ict-home-projects-table-id .pager a');
        pager_links.each(function(){
            this.href = this.href + '#ict-home-projects-table-id';
        });
    }
}
