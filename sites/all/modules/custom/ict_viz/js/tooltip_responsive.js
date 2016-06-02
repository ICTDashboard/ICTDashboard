Drupal.behaviors.positionTooltip = {
    attach: function(context) {
        var width = window.innerWidth;
        jQuery('.tooltip-custom', context).hover( function(event){
            var span = jQuery(event.target).find('.custom-tooltip-content').css({right: 0, position:'absolute', width: width < 360 ? '280px' : '300px'});
            if (width < 768) {
                span.css({left: width < 360 ?  28 - event.clientX : 28 + (width - 360)/2 - event.clientX}).addClass('custom-tooltip-corner-no');
            } else {
                span.css({left: event.clientX > width/2 ? -300 : 16}).addClass(event.clientX > width/2 ? 'custom-tooltip-corner-right' : 'custom-tooltip-corner-left');
            }
        });
    }
}