(function($){
  $(document).ready(function(){

    $("td.total input").attr('readonly', true);


    $('.date-day .form-select option:first').text('Day');
    $('.date-month .form-select option:first').text('Month');
    $('.date-year .form-select option:first').text('Year');

    $('tr.sum input.form-text').keyup(function(){
      var table = $(this).parents('table').attr('id');
      $("#" + table +' td.total').each(function(i){
        var sum = parseFloat($("#" +table+" td.opex[data-sum='" + i + "']").find('.form-text').val())+parseFloat($("#" +table+ " td.capex[data-sum='" + i + "']").find('.form-text').val());
        var total =  (sum === parseFloat(sum, 10)) ? sum : '';
        if (total) {
          $(this).find('.form-text').val(Number(total).toFixed(2));
        }
      });

    });

  });
})(jQuery);