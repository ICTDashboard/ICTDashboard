
jQuery(document).ready(function(){
    jQuery('.fancybox-inline').fancybox({
        type: 'inline',
        maxWidth: 700,
        minHeight: 320,
        padding: 0,
        closeBtn: false,
        afterShow: function() {
            setTimeout(function(){
                var topPadding = jQuery('.fancybox-inner .fancybox-title').outerHeight(),
                    bottomPadding = jQuery('.fancybox-inner .fancybox-actions').outerHeight(),
                    fancyHeight = jQuery('.fancybox-inner').outerHeight();

                jQuery('.fancybox-inner .ict-fancy-content').height(fancyHeight - topPadding - bottomPadding);
                jQuery('.fancybox-inner .ict-fancy-content').css('margin-top', topPadding);
                jQuery('.fancybox-inner .ict-fancy-content').css('margin-bottom', bottomPadding);
            }, 0);
        }
    });
    jQuery('.fancybox-baseline-decline-form').fancybox({
        type: 'inline',
        maxWidth: 700,
        minHeight: 320,
        padding: 0,
        closeBtn: false,
        afterShow: function() {
            setTimeout(function(){
                var topPadding = jQuery('.fancybox-inner .fancybox-title').outerHeight(),
                    bottomPadding = jQuery('.fancybox-inner .fancybox-actions').outerHeight(),
                    fancyHeight = jQuery('.fancybox-inner').outerHeight();

                jQuery('.fancybox-inner .ict-fancy-content').height(fancyHeight - topPadding - bottomPadding);
                jQuery('.fancybox-inner .ict-fancy-content').css('margin-top', topPadding);
                jQuery('.fancybox-inner .ict-fancy-content').css('margin-bottom', bottomPadding);
                jQuery('.fancybox-wrap').appendTo('form');
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
