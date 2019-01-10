/* globals Drupal, jQuery, dataLayer, SunrunZipCode, window, ga, dataLayer */
(function ($) {
    Drupal.behaviors.sunrun_zeus_forms = {
        attach: function (context, settings) {

            var sunrunZipCode = new SunrunZipCode();

            // Show out of territory message if sr_oot cookie set

            if ($.validator) {
                // US phone number validation
                $.validator.addMethod("phone", function (value, element) {
                    return this.optional(element) || (/^\(?([0-9]{3})\)?[\-.\s]?([0-9]{3})[\-.\s]?([0-9]{4})$/).test(value);
                }, "Please enter a valid phone number.");

                // standard zip code validation
                $.validator.addMethod("zipcode", function (value, element) {
                    return this.optional(element) || (/^\d{5}$/).test(value);
                }, "Please enter a five digit zip code.");

                // Valid Name
                $.validator.addMethod('validname', function (value, element) {
                    return this.optional(element) || (/^[A-Z\-\s']+$/i).test(value);
                }, 'Please enter a valid name.');

                // Zeus Form Validation
                $("#zeus-quote-form").validate({
                    rules: {
                        // simple rule, converted to {required:true}
                        first_name: {
                            required: true,
                            validname: true
                        },
                        last_name: {
                            required: true,
                            validname: true
                        },
                        email: {
                            required: true,
                            email: true
                        },
                        phone: {
                            phone: true,
                            required: true
                        },
                        zip: {
                            required: true,
                            zipcode: true
                        }
                    },
                    messages: {
                        first_name: "Please enter your first name.",
                        last_name: "Please enter your last name.",
                        email: "Please enter a valid email address.",
                        phone: "Please enter a valid phone number"
                    },
                    submitHandler: function (form) {
                        sunrunZipCode.sr_oot($('#zip').val());
                        window.dataLayer = window.dataLayer || [];
                        dataLayer.push({
                            'category': 'quote form',
                            'action': 'form submit',
                            'label': window.location.pathname
                        });
                        if (window.location.pathname.indexOf('calculator') > -1) {
                          ga('send', 'event', 'calculator', 'step 1', 'submit success');
                          dataLayer.push({'event': 'lead-form-submitted'});
                        }

                        form.submit();
                    }
                });
            } // if ($.validator)

            var offer_promotion = $('meta[property=offer_promotion]').attr("content");
            if (offer_promotion !== undefined) {
                document.getElementById("offerPromoCode").value = offer_promotion;
            }

            // Copy pane-title to headline on horizontal standard lead form
            if (
                typeof settings.sunrun_leadforms != 'undefined' 
                && typeof settings.sunrun_leadforms.form != 'undefined'
                && settings.sunrun_leadforms.form === 'standard-leadform-horizontal'
                
               ) {

                if ( $('.panel-pane.pane-sunrun-leadform > .pane-title').length ) {
                    $('#standard-leadform-horizontal-headline').text($('.panel-pane.pane-sunrun-leadform > .pane-title').text());
                    $('.panel-pane.pane-sunrun-leadform > .pane-title').remove();
                    
                } else {
                  $('#headline-container').remove();
                }
            }
        }
    };
})(jQuery);
