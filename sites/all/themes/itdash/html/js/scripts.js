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

  if ($(".add_datepicker").length) {

    $(".add_datepicker").each(function () {
      var id = $(this).attr('id');

      $(this).datepicker({
        buttonImage: "/sites/all/themes/itdash/html/images/calendar-icon.png",
        buttonImageOnly: true,
        showOn: 'button',
        onClose: function(dateText, inst) {
          $('#' + id + '-und-0-value-year').val(Number(dateText.split('/')[2]));
          $('#' + id + '-und-0-value-month').val(Number(dateText.split('/')[0]));
          $('#' + id + '-und-0-value-day').val(Number(dateText.split('/')[1]));
		  $('.form-select').selectbox('detach');
		  $('.form-select').selectbox('attach');
        }
      });
    });

  }

	$("#edit-field-project-users-und").multiSelect({
		noneSelected: 'Select users'
	});

	
	/* Partner table implementation */
	
	if( $('.delta-order.tabledrag-hide').is(':visible') ) {
		// Visible
		$('.tabledrag-hide').prev('td').css({
			'border-right': '0 none'
		});
		$('.tabledrag-hide').prev('th').css({
			'border-radius': '4px 0 0 0'
		});
	} else {
		// Invisible 
		$('.tabledrag-hide').prev('td').css({
			'border-right': '1px solid #abb6cb'
		});
		$('.tabledrag-hide').prev('th').css({
			'border-radius': '4px 4px 0 0'
		});
	}
	
	$('.field-multiple-drag').remove();
	$('table[id^="field-implementation-partners-values"] tr th').attr('colspan', 1);
	$('.tabledrag-toggle-weight').click(function(){
		console.log('test');
		if( $('.delta-order.tabledrag-hide').is(':visible') ) {
			// Visible
			console.log('visible');
			$('.tabledrag-hide').prev('td').css({
				'border-right': '0'
			});
			$('.tabledrag-hide').prev('th').css({
				'border-radius': '4px 0 0 0'
			});
		} else {
			// Invisible 
			console.log('invisible');
			$('.tabledrag-hide').prev('td').css({
				'border-right': '1px solid #abb6cb'
			});
			$('.tabledrag-hide').prev('th').css({
				'border-radius': '4px 4px 0 0'
			});
		}
	});
	
	$("body").bind("ajaxComplete", function(e, xhr, settings){
		$('.field_implementation_partners-delta-order').selectbox('attach');
		$('.field-multiple-drag').remove();
		$('table[id^="field-implementation-partners-values"] tr th').attr('colspan', 1);
    });
	
	$('.form-select').selectbox();
	$('.field_implementation_partners-delta-order').selectbox();
}); /* end of as page load scripts */
