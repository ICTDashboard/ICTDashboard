
jQuery(document).ready(function(){
    jQuery('.fancybox-inline').fancybox({
        type: 'inline',
        maxWidth: 700,
        padding: 0,
        closeBtn: false,
        afterShow: function() {
            setTimeout(function(){
                var topPadding = jQuery('.fancybox-inner .fancybox-title').outerHeight(),
                    bottomPadding = jQuery('.fancybox-inner .fancybox-actions').outerHeight(),
                    fancyHeight = jQuery('.fancybox-inner').outerHeight();

                jQuery('.fancybox-inner .bean-opt-out-policy').height(fancyHeight - topPadding - bottomPadding);
                jQuery('.fancybox-inner .bean-opt-out-policy').css('margin-top', topPadding);
                jQuery('.fancybox-inner .bean-opt-out-policy').css('margin-bottom', bottomPadding);
            }, 0);
        }
    });
});

Drupal.behaviors.ictFancyClose = {
    attach: function(context) {
        jQuery('.ict-fancybox-close', context).click(function(){
            jQuery.fancybox.close();
            return false;
        });
    }
}
