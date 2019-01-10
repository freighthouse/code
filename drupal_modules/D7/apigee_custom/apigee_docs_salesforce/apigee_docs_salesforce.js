// Support Request Form javascript to add tip to the description textarea.

(function ($) {
    Drupal.behaviors.webformSupportFormDescription = {
        attach: function (context, settings) {
            $('#edit-submitted-request-details-description', context).once(
                'webform-support-form-description', function () {
                    var $field = $(this);
                    var initial_value = Drupal.t('Enter a brief description of your issue...');

                    $field.focus(
                        function () {
                            if ($field.val() === initial_value) {
                                $field.val('');
                                $field.removeClass('grey');
                            }
                        }
                    );

                    $field.blur(
                        function () {
                            if ($field.val() === '') {
                                $field.val(initial_value);
                                $field.addClass('grey');
                            }
                        }
                    );

                    $field.trigger('blur');
                }
            );

            $('#edit-submitted-request-details-service', context).once(
                'webform-support-form-service', function() {
                    var $options = $('#edit-submitted-request-details-feature option');
                    $('#webform-component-request-details--feature').hide();
                    $(this).change(
                        function(){
                            var $value = $(this).val();
                            switch ($value) {
                            case '':
                                $('#webform-component-request-details--feature').hide();
                                $('#edit-submitted-request-details-feature option').remove();
                                break;
                            case 'App services':
                                $('#edit-submitted-request-details-feature option').remove();
                                $('#edit-submitted-request-details-feature').append($options.get(0));
                                // Set proper options
                                for ($i = 1; $i <= 5; $i++) {
                                    $('#edit-submitted-request-details-feature').append($options.get($i));
                                }
                                $('#edit-submitted-request-details-feature').val('');
                                $('#webform-component-request-details--feature').show();
                                break;
                            case 'Gateway services':
                                $('#edit-submitted-request-details-feature option').remove();
                                $('#edit-submitted-request-details-feature').append($options.get(0));
                                // Set proper options

                                for ($i = 6; $i <= 9; $i++) {
                                    $('#edit-submitted-request-details-feature').append($options.get($i));
                                }
                                $('#edit-submitted-request-details-feature').val('');
                                $('#webform-component-request-details--feature').show();
                                break;
                            case 'Developer channel services':
                                $('#edit-submitted-request-details-feature option').remove();
                                $('#edit-submitted-request-details-feature').append($options.get(0));
                                $('#edit-submitted-request-details-feature').val('');
                                // Set proper options
                                for ($i = 10; $i <= 13; $i++) {
                                    $('#edit-submitted-request-details-feature').append($options.get($i));
                                }
                                $('#webform-component-request-details--feature').show();
                                break;
                            case 'Analytics & data services':
                                $('#edit-submitted-request-details-feature option').remove();
                                $('#edit-submitted-request-details-feature').append($options.get(0));
                                $('#edit-submitted-request-details-feature').val('');
                                // Set proper options
                                for ($i = 14; $i <= 15; $i++) {
                                    $('#edit-submitted-request-details-feature').append($options.get($i));
                                }
                                $('#webform-component-request-details--feature').show();
                                break;
                            }
                        }
                    );
                }
            );
        }
    };
})(jQuery);

