/*
 * Get Viewport Dimensions
 * returns object with viewport dimensions to match css in width and height properties
 * ( source: http://andylangton.co.uk/blog/development/get-viewport-size-width-and-height-javascript )
*/
function updateViewportDimensions() {
	var w=window,d=document,e=d.documentElement,g=d.getElementsByTagName('body')[0],x=w.innerWidth||e.clientWidth||g.clientWidth,y=w.innerHeight||e.clientHeight||g.clientHeight;
	return { width:x,height:y }
}
// setting the viewport width
var viewport = updateViewportDimensions();


/*
 * Throttle Resize-triggered Events
 * Wrap your actions in this function to throttle the frequency of firing them off, for better performance, esp. on mobile.
 * ( source: http://stackoverflow.com/questions/2854407/javascript-jquery-window-resize-how-to-fire-after-the-resize-is-completed )
*/
var waitForFinalEvent = (function () {
	var timers = {};
	return function (callback, ms, uniqueId) {
		if (!uniqueId) { uniqueId = "Don't call this twice without a uniqueId"; }
		if (timers[uniqueId]) { clearTimeout (timers[uniqueId]); }
		timers[uniqueId] = setTimeout(callback, ms);
	};
})();

// how long to wait before deciding the resize has stopped, in ms. Around 50-100 should work ok.
var timeToWaitForLast = 100;

/*
 * Put all your regular jQuery in here.
*/
jQuery(document).ready(function($) {

	/* $('#main-menu').slicknav({
		prependTo: '#mobile-nav',
		label: 'MENU'
	}); */

	$('.signin-request .tab-head a').click(function(){
		var $this = $(this);

		$('.signin-request .tab-head a').removeClass('active');
		$this.addClass('active');

		$('.tab-content .tab').removeClass('active');
		$('.tab-content ' + $this.attr('href')).addClass('active');

		return false;
	});

	$('.arrowdown').click(function(){

		var $this = $(this);

		if( $this.hasClass('active') ) {
			$this.removeClass('active');
			$this.siblings('ul').hide();
		} else {
			$this.addClass('active');
			$this.siblings('ul').show();
		}
		return false;
	});

	$(document).click(function(event) {
		if (!$(event.target).is(".arrowdown")) {
			$('.arrowdown').removeClass('active');
			$('.arrowdown').siblings('ul').hide();
		}
	});

  if ($("#start-date").length) {
    $("#start-date").datepicker({
          buttonImage: "http://itdash.lws.links.com.au/sites/all/themes/itdash/html/images/calendar-icon.png",
          buttonImageOnly: true,
          showOn: 'button',
          onClose: function(dateText, inst) {
              $('#start-date-year').val(dateText.split('/')[2]);
              $('#start-date-month').val(dateText.split('/')[0]);
              $('#start-date-day').val(dateText.split('/')[1]);
          }
      });
  }

  if ($("#original-date").length) {
    $("#original-date").datepicker({
          buttonImage: "images/calendar-icon.png",
          buttonImageOnly: true,
          showOn: 'button',
          onClose: function(dateText, inst) {
              $('#original-date-year').val(dateText.split('/')[2]);
              $('#original-date-month').val(dateText.split('/')[0]);
              $('#original-date-day').val(dateText.split('/')[1]);
          }
      });
  }

  if ($("#expected-date").length) {
    $("#expected-date").datepicker({
          buttonImage: "images/calendar-icon.png",
          buttonImageOnly: true,
          showOn: 'button',
          onClose: function(dateText, inst) {
              $('#expected-date-year').val(dateText.split('/')[2]);
              $('#expected-date-month').val(dateText.split('/')[0]);
              $('#expected-date-day').val(dateText.split('/')[1]);
          }
      });
  }
  
	$("#edit-field-project-users-und").multiSelect({
		noneSelected: 'Select users'
	});
}); /* end of as page load scripts */
