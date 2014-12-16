(function($){
  $(document).ready(function(){

    $("td.total input").attr('readonly', true);


    $('tr.sum input.form-text').keyup(function(){
      var table = $(this).parents('table').attr('id');
      $("#" + table +' td.total').each(function(i){
        var sum = parseInt($("#" +table+" td.opex[data-sum='" + i + "']").find('.form-text').val())+parseInt($("#" +table+ " td.capex[data-sum='" + i + "']").find('.form-text').val());
        var total =  (sum === parseInt(sum, 10)) ? sum : '';
        $(this).find('.form-text').val(total);
      });

    });

  });
})(jQuery);