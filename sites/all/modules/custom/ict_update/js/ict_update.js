(function($){
    $(document).ready(function(){

        if ($('#edit-field-expected-completion-date-radio-na').length) {
            var expected_date_fix = function() {
                var na_radio = $('#edit-field-expected-completion-date-radio-na');
                if (na_radio.is(':checked')) {
                    na_radio
                        .closest('.field-type-datetime')
                        .find('.add_datepicker')
                        .val('');
                }
            };

            $('#edit-field-expected-completion-date-radio-na').change(function () {
                expected_date_fix();
            });
        }

    });
})(jQuery);
