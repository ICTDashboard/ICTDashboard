(function($){
  $(document).ready(function(){

    $("td.total input").attr('readonly', true);


    $('tr.sum input.form-text').keyup(function(){
      var table = $(this).parents('table').attr('id');
      $("#" + table +' td.total').each(function(i){
        var sum = parseFloat($("#" +table+" td.opex[data-sum='" + i + "']").find('.form-text').val())+parseFloat($("#" +table+ " td.capex[data-sum='" + i + "']").find('.form-text').val());
        var total =  (sum === parseFloat(sum, 10)) ? sum : '';
        $(this).find('.form-text').val(total);
      });

    });

  });
})(jQuery);