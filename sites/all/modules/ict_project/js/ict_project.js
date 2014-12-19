(function($){
  $(document).ready(function(){

    $("td.total input").attr('readonly', true);


    $('.date-day .form-select option:first').text('Day');
    $('.date-month .form-select option:first').text('Month');
    $('.date-year .form-select option:first').text('Year');

    $('tr.sum input.form-text').keyup(function(){
      var table = $(this).parents('table').attr('id');
      $("#" + table +' td.total').each(function(i){
        var sum = 0;
        sum += parseFloat($("#" +table+" td.opex[data-sum='" + i + "']").find('.form-text').val()) || 0;
        sum += parseFloat($("#" +table+ " td.capex[data-sum='" + i + "']").find('.form-text').val()) || 0;
        var total =  (sum === parseFloat(sum, 10)) ? sum : '';

          $(this).find('.form-text').val(Number(total).toFixed(2));
      });

    });

    if ($('.tooltipster-icon').length) {console.log(1);
      $('.tooltipster-icon').each(function () {
        $(this).tooltipster({
          position: 'right'
        });
      });
    }

  });
})(jQuery);