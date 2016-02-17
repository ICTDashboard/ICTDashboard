
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
    jQuery('.fancybox-benefit-history').fancybox({
        type: 'inline',
        maxWidth: 700,
        // TEMPORARY SOLUTION
        minWidth: 700,
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
                // TEMPORARY SOLUTION
                Drupal.attachBehaviors();
            }, 0);
        },
        content: '<div id="ict-policy">' +
                    '<h2 class="fancybox-title">Benefit history</h2>' +
                    '<div class="ict-fancy-content"><h2>History view will be available soon...</h2></div>' +
                    '<div class="fancybox-actions">' +
                    '<a class="ict-fancybox-close general-button" href="#"><span>Close</span></a>' +
                    '</div></div>'
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
