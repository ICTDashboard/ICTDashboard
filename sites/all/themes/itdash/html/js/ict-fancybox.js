
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
                    fancyHeight = jQuery('.fancybox-inner').outerHeight(),
                    marginTop = parseInt(jQuery('.fancybox-inner .ict-fancy-content').css('margin-top')),
                    marginBottom = parseInt(jQuery('.fancybox-inner .ict-fancy-content').css('margin-bottom'));

                jQuery('.fancybox-inner .ict-fancy-content').css('max-height', fancyHeight - bottomPadding - topPadding - marginTop - marginBottom);
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
                    fancyHeight = jQuery('.fancybox-inner').outerHeight(),
                    marginTop = parseInt(jQuery('.fancybox-inner .ict-fancy-content').css('margin-top')),
                    marginBottom = parseInt(jQuery('.fancybox-inner .ict-fancy-content').css('margin-bottom'));

                jQuery('.fancybox-inner .ict-fancy-content').css('max-height', fancyHeight - bottomPadding - topPadding - marginTop - marginBottom);
            }, 0);
        }
    });
    jQuery('.fancybox-benefit-history').fancybox({
        type: 'ajax',
        maxWidth: 970,
        minWidth: 700,
        //maxHeight: 600,
        height: 'auto',
        padding: 0,
        closeBtn: false,
        afterShow: function() {
            setTimeout(function(){
                var topPadding = jQuery('.fancybox-inner .fancybox-title').outerHeight(),
                    bottomPadding = jQuery('.fancybox-inner .fancybox-actions').outerHeight(),
                    fancyHeight = jQuery('.fancybox-inner').outerHeight(),
                    marginTop = parseInt(jQuery('.fancybox-inner .ict-fancy-content').css('margin-top')),
                    marginBottom = parseInt(jQuery('.fancybox-inner .ict-fancy-content').css('margin-bottom'));

                jQuery('.fancybox-inner .ict-fancy-content').css('max-height', fancyHeight - bottomPadding - topPadding - marginTop - marginBottom);
            }, 0);

            Drupal.attachBehaviors(document.getElementById('ict-policy'));
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
