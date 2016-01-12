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

  });
})(jQuery);
