Drupal.behaviors.positionTooltip = {
    attach: function(context) {
        //console.log('Working my tooltip');
        var width = window.innerWidth;
        var click;
        var span;
        var footable = jQuery('.footable', context);
        jQuery('.tooltip', context).hover(
            function(event) {
                click = 1;
                console.log('click mouseenter');
                span = jQuery(event.target).css({position: 'relative'}).find('.tooltip-content').css({right: 0, position:'absolute', width: width < 360 ? '280px' : '300px', display: 'block'});
                if (width < 768) {
                    span.css({left: width < 360 ?  28 - event.clientX : 28 + (width - 360)/2 - event.clientX}).addClass('custom-tooltip-corner-no');
                } else {
                    span.css({left: event.clientX > width/2 ? -300 : 16}).addClass(event.clientX > width/2 ? 'custom-tooltip-corner-right' : 'custom-tooltip-corner-left');
                }
            },
            function(event) {
                //console.log(event.clientX);
                span.css({display: 'none'});
            }
        ).click(function(event) {
            console.log(event.target, span, click, event.clientX, width);
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