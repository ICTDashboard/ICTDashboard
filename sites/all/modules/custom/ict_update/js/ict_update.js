(function($){
    Drupal.behaviors.expectedTime = {
        attach: function(context) {
            if ($('#edit-field-expected-completion-date-radio-na', context).length) {
                $('#edit-field-expected-completion-date-radio-na', context).change(function () {
                    var na_radio = $(this);
                    if (na_radio.is(':checked')) {
                        na_radio.closest('.field-type-datetime')
                            .find('#field-expected-completion-date-add-more-wrapper input')
                            .val('');
                    }
                });
            }
        }
    };

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

                    $('#total-project-expenditure')
                        .text('$' + total_expenditure.toFixed(2) + 'm');
                };
                update_total_expenditure();

                $('.expenditure-values .number-cell input')
                    .bind('input', update_total_expenditure);
            }
        }
    };

    // $(document).ready(function () {
    //     $(".field-name-field-entity-comments textarea").textareaCounter({
    //         limit: 500
    //     });
    // });
})(jQuery);
