Drupal.behaviors.positionTooltip = {
    attach: function(context) {
        var width = window.innerWidth;
        var click;
        var span;
        jQuery(document, context)
            .on('mouseenter', '.tooltip, .tooltip-custom', function(event) {
                click = 1;
                // console.log('click mouseenter');
                span = jQuery(event.target).css({position: 'relative'}).find('.tooltip-content').css({right: 0, position:'absolute', width: width < 360 ? '280px' : '300px', display: 'block'});
                if (width < 768) {
                    span.css({left: width < 360 ?  28 - event.clientX : 28 + (width - 360)/2 - event.clientX}).addClass('custom-tooltip-corner-no');
                } else {
                    span.css({left: event.clientX > width/2 ? -300 : 16}).addClass(event.clientX > width/2 ? 'custom-tooltip-corner-right' : 'custom-tooltip-corner-left');
                }
            }
        ).on('mouseleave', '.tooltip, .tooltip-custom', function(event) {
            // console.log('click mouseleave');
            span = jQuery(event.target).css({position: 'relative'}).find('.tooltip-content').css({right: 0, position:'absolute', width: width < 360 ? '280px' : '300px', display: 'block'});
            span.css({display: 'none'});
        }
        ).on('click', '.tooltip, .tooltip-custom', function(event) {
            var span = jQuery(this).find('.tooltip-content');
            if (span.css('display')  == 'block' && click == 2) {
                span.css('display', 'none');
                click = 1;
            } else {
                span.css('display', 'block');
                click = 2;
            }
        });
    }
}