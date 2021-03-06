(function($){
  $(document).ready(function(){

    $("td.total input").attr('readonly', true);


    $('.date-day .form-select option[value=""]').text('Day');
    $('.date-month .form-select option[value=""]').text('Month');
    $('.date-year .form-select option[value=""]').text('Year');

    $('tr.sum input.form-text').keyup(function(){
      var table = $(this).parents('table').attr('id');
      $("#" + table +' td.total').each(function(i){
        var sum = 0;
        sum += parseFloat($("#" +table+" td.opex[data-sum='" + i + "']").find('.form-text').val()) || 0;
        sum += parseFloat($("#" +table+ " td.capex[data-sum='" + i + "']").find('.form-text').val()) || 0;
        var total =  (sum === parseFloat(sum, 10)) ? sum : '';
        if (total) {
          $(this).find('.form-text').val(total.toFixed(1));
        }
        else {
            $(this).find('.form-text').val('');
        }
      });

    });

    // Allows users to input only one decimal number
    $('.opex input,.capex input').on({
        'paste': function () {
            $(this).val(ict_project_one_decimal_validate ($(this).val()));
        },
        'keyup': function () {
            $(this).val(ict_project_one_decimal_validate ($(this).val()));
        }
    });

    function ict_project_one_decimal_validate (val) {
        var ex = /^[0-9]*\.?([0-9]{1})?$/;
        if(ex.test(val) == false) {
            val = val.substring(0, val.length - 1);
            return ict_project_one_decimal_validate (val);
        }
        return val;
    }

    if ($('.tooltipster-icon').length) {
      $('.tooltipster-icon').each(function () {
        $(this).tooltipster({
          position: 'right'
        });
      });
    }

    if ($('.start-year-select').length) {
        var select_box = $('.start-year-select select');

        function n(n){
            return ("0" + n).slice(-2);;
        }

        for (index in Drupal.settings.year_range.year_range) {
            var value = Drupal.settings.year_range.year_range[index],
                year_str = n(value)+'/'+n(value+1);
            select_box.append($('<option>', {
                value: year_str,
                text: year_str
            }));
        }
        select_box.val(Drupal.settings.year_range.start_year);
        select_box.change(function() {
            var value = select_box.val(),
                start_year = value.split('/')[0];
            $('#field_end_predicted_budget th.year_header').each(function() {
                var new_val = n(start_year)+'/'+n(++start_year);
                $(this).find('input[type="text"]').val(new_val);
                $(this).find('.year_value').text(new_val);
            });
        });
    }

  });

// overriding autocomplete popup behevior
if (Drupal.jsAC) {
  Drupal.jsAC.prototype.populatePopup = function () {
    var $input = $(this.input);
    var position = $input.position();
    // Show popup.
    if (this.popup) {
      $(this.popup).remove();
    }
    this.selected = false;
    this.popup = $('<div id="autocomplete"></div>')[0];
    this.popup.owner = this;
    $(this.popup).css({
      top: parseInt(position.top + this.input.offsetHeight, 10) + 'px',
      left: parseInt(position.left, 10) + 'px',
      width: $input.innerWidth() + 2 + 'px',
      display: 'none'
    });
    $input.before(this.popup);

    // Do search.
    this.db.owner = this;
    this.db.search(this.input.value);
  };
}

Drupal.behaviors.totalExpenditure = {
        attach: function(context) {
            if ($('.expenditure-values').length) {

                update_total_expenditure = function() {
                    var total_expenditure = 0;

                    $('.expenditure-values .number-cell').each(function () {
                        var element = $(this).find('input');
                        if (element.val()) {
                            var val = Number(element.val());
                            if (isNaN(Number(val))) return;

                            total_expenditure += val;
                        }
                    });

                    $('#total-project-budget')
                        .text('$' + total_expenditure.toFixed(2) + 'm');
                };
                update_total_expenditure();

                $('.expenditure-values .number-cell input')
                    .bind('input', update_total_expenditure);
            }
        }
    };
})(jQuery);


Drupal.behaviors.addCombobox = {
    attach: function(context) {
        if (typeof jQuery.fn.combobox != 'undefined') {
            jQuery( ".ict-combobox" ).combobox();
        }
    }
}
