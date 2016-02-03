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
    }
})(jQuery);
