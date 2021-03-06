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
	
	$('#main-menu').slicknav({
		prependTo: '#navigation',
		label: 'Menu'
	});

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

    //$(document).click(function (e)
    //{
    //  if (!$(this).hasClass('ui-datepicker-trigger'))
    //  {
    //    $('.add_datepicker').datepicker("hide");
    //  }
    //});

    $(".add_datepicker").each(function () {
      	var id = $(this).attr('id');
		var parent = $(this).parents('.popup-radio');
		var dateinput = $('.form-type-date-popup input[type=text]', parent);
		var opts = {
			buttonImage: "/sites/all/themes/itdash/html/images/calendar-icon.png",
			buttonImageOnly: true,
			showOn: 'button',
			onClose: function(dateText, inst) {
				dateinput.val(dateText);
			}
		};
		var dateFormat = $(this).attr('data-dateFormat');
		if (dateFormat) {
			opts.dateFormat = dateFormat;
		}
		if (dateinput.length > 0) {
			var defaultDate = dateinput.val();
		}
      	$(this).datepicker(opts);
		$(this).val(defaultDate);
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
		if( $('.delta-order.tabledrag-hide').is(':visible') ) {
			// Visible
			$('.tabledrag-hide').prev('td').css({
				'border-right': '0'
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
	});
}); /* end of as page load scripts */

Drupal.behaviors.initSelectbox = {
	attach: function(context) {
		jQuery('.field_implementation_partners-delta-order', context).selectbox('attach');
		jQuery('.field-multiple-drag', context).remove();
		jQuery('table[id^="field-implementation-partners-values"] tr th', context).attr('colspan', 1);

		jQuery('.form-select:not([multiple="multiple"],.ict-combobox, #financial-benefits select)', context).selectbox();
		var ictSelects = jQuery('#financial-benefits select', context);
		ictSelects.selectbox({onChange: function(value, inst){
			var holder = jQuery(inst.input).parent().find('.sbHolder');
			holder.removeClass().addClass('sbHolder ' + value);
		}});

		ictSelects.each(function(){
			var selected = jQuery(this).find('option:selected').val();
			jQuery(this).parent().find('.sbHolder').addClass(selected);
		});


		jQuery('.form-select[disabled="disabled"]', context).selectbox("disable");
		jQuery('.field_implementation_partners-delta-order', context).selectbox();
	}
}

Drupal.behaviors.textareaBenefits = {
	attach: function(context) {
		var textarea = jQuery("#financial-benefits textarea", context);
		var heightLimit = 200; /* Maximum height: 200px */

		textarea.on('input', function() {
			jQuery(this).height(Math.min(jQuery(this)[0].scrollHeight, heightLimit));
		});
	}
}

Drupal.behaviors.ictFaq = {
	attach: function(context) {
		jQuery('.ict-faq-question', context).click(function(){
			if (jQuery(this).hasClass('ict-faq-question-active')) {
				var wrap = jQuery(this).parent(),
					answer = wrap.find('.ict-faq-answer');

				jQuery(this).removeClass('ict-faq-question-active');
				answer.slideUp(function(){answer.css('overflow', 'visible')});
			}
			else {
				var wrap = jQuery(this).parent(),
					answer = wrap.find('.ict-faq-answer'),
					activeQuest = jQuery('.ict-faq-question-active'),
					activeWrap = activeQuest.parent(),
					activeAnsw = activeWrap.find('.ict-faq-answer');

				activeQuest.removeClass('ict-faq-question-active');
				activeAnsw.slideUp(function(){answer.css('overflow', 'visible')});
				jQuery(this).addClass('ict-faq-question-active');
				answer.slideDown(function(){answer.css('overflow', 'visible')});
			}
			return false;
		});
	}
}

Drupal.behaviors.atepickerIcon = {
	attach: function(context) {
		for (id in Drupal.settings.datePopup) {
			Drupal.settings.datePopup[id].settings.changeMonth = true;
			Drupal.settings.datePopup[id].settings.changeYear = true;
			jQuery('#' + id).datepicker(Drupal.settings.datePopup[id].settings)
			.addClass('date-popup-init');
		}
	}
}
