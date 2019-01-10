/*global MktoForms2, dataLayer */
(function ($) {
    Drupal.behaviors.sunrun_purls = {
        attach: function (context, settings) {
            $('.get-quote-form').once('get-quote-form-one-time', function() {
                var MKTO_FORMS = {
                    email: '',
                    phone: '',
                    keycode: settings.sunrun_purls.keycode,
                    first: settings.sunrun_purls.first_name,
                    last: settings.sunrun_purls.last_name,
                    street: settings.sunrun_purls.address,
                    city: settings.sunrun_purls.city,
                    state: settings.sunrun_purls.state,
                    zip: settings.sunrun_purls.zip,
                    bill: settings.sunrun_purls.bill,

                    clean: function(val) {
                        if(undefined!==val) {
                            return val.replace(/\+/g," ");
                        }
                        return;
                    }
                };
                if(typeof(MktoForms2) !== 'undefined')
                {
                    MktoForms2.loadForm(settings.sunrun_purls.environment, settings.sunrun_purls.munchkin_id, settings.sunrun_purls.form_id, function (form)
                    {
                        //jQuery(".mktoForm, .mktoForm *").removeAttr("style");
                        $('.mktoButtonRow .mktoButtonWrap').removeClass('mktoMinimal').addClass('mktoNative');
                        var formElement = form.getFormElem();
                        formElement.find(".mktoButtonRow").after("<small class='pageid-tcpa'>" + settings.sunrun_purls.tcpa_disclosure + "</small>"
                        );
                        var vals = form.vals();
                        // Set content field to value of referrer
                        var referrer;
                        if (typeof document.referrer !== 'undefined') {
                         referrer = document.referrer.split( '/' )[3];
                        } else {
                          referrer = '';
                        }
                        form.vals({
                            "Email": MKTO_FORMS.email,
                            "Phone": MKTO_FORMS.phone,
                            "FirstName": MKTO_FORMS.first,
                            "LastName": MKTO_FORMS.last,
                            "Street": MKTO_FORMS.street,
                            "Address": MKTO_FORMS.street,
                            "City": MKTO_FORMS.city,
                            "State": MKTO_FORMS.state,
                            "PostalCode": MKTO_FORMS.zip,
                            "Average_Monthly_Electric_Bill__c": MKTO_FORMS.bill,
                            "Auto_dialer_Opt_in__c": 1,
                            "Channel__c": MKTO_FORMS.clean(vals.Channel__c),
                            "Custom_Lead_Source__c": MKTO_FORMS.clean(vals.Custom_Lead_Source__c),
                            "Keywords__c": MKTO_FORMS.clean(vals.Keywords__c),
                            "Campaign__c": MKTO_FORMS.clean(vals.Campaign__c),
                            "Network_marketo__c": MKTO_FORMS.clean(vals.Network_marketo__c),
                            "Offer_Promo_Code__c": MKTO_FORMS.clean(vals.Offer_Promo_Code__c),
                            "Channel_Last__c": MKTO_FORMS.clean(vals.Channel_Last__c),
                            "Lead_Source_Last__c": MKTO_FORMS.clean(vals.Lead_Source_Last__c),
                            "Content_Last__c": MKTO_FORMS.keycode,
                            "Keywords_Last__c": MKTO_FORMS.clean(vals.Keywords_Last__c),
                            "Campaign_Last__c": referrer,
                        });

                        form.onValidate(function (values) {
                          form.vals({
                            "Average_Monthly_Electric_Bill__c": $('#srPurlsAverageElectricBill').val()
                          });
                          var vals = form.vals();
                          var phonePattern = /^\(?([0-9]{3})\)?[-. ]?([0-9]{3})[-. ]?([0-9]{4})$/;
                          var emailPattern = /^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$/;
                          var hasErrors = false;
                          console.log(vals);

                          //TODO: refactor marketo form validation
                          if (!( emailPattern.test(vals.Email) )) {
                            hasErrors = true;
                            var email = formElement.find("#Email");
                            showError('#Email', 'Please enter a valid email address.', email);
                          } else {
                            removeError('#Email');
                          }
                          if (!( phonePattern.test(vals.Phone) )) {
                            hasErrors = true;
                            var phone = formElement.find("#Phone");
                            showError('#Phone', 'Please enter a valid phone number.', phone);
                          } else {
                            removeError('#Phone');
                          }

                          if (hasErrors) {
                            form.submittable(false);
                          } else {
                            form.submittable(true);
                          }
                          //TODO: there may not be anything needed in this callback if we use the validation given to us by marketo.

                        });

                        form.onSuccess(function (values, followUpUrl) {
                            // Redirect if needed
                            dataLayer.push({category: "purls", action: "form submit"});
                            if(typeof settings.sunrun_purls.redirect !== 'undefined' && settings.sunrun_purls.redirect){
                                window.location.href = settings.basePath + settings.sunrun_purls.redirect;
                                return false;
                            }
                        });
                    });

                    function showError(field, text, ref) {
                      if(!$(field).closest('.mktoFormRow').children('.error').length) {
                        ref.closest('.mktoFormRow').append('<div class="error">'+ text +'</div>');
                      }
                    }

                    function removeError(field) {
                      if($(field).closest('.mktoFormRow').children('.error').length)
                      {
                        $(field).closest('.mktoFormRow').children('.error').remove();
                      }
                    }
                }
            });
            // Validate PURLs addres form
            $('.purls-address-webform', context).once('sunrun_purls', function() {
                // Adding new method to validate zipcode
                $.validator.addMethod('zipcode', function(value, element) {
                  return this.optional(element) || /(^\d{5}$)/.test(value);
                }, 'Please provide a valid zipcode.');
                // Adding new method to validate select option
                $.validator.addMethod('select_required', function(value, element) {
                  return this.optional(element) || value !== 0;
                }, 'This field is required.');

                $(this).validate({
                  rules: {
                    'submitted[zip]': {
                        zipcode: true,
                    },
                    'submitted[state]': {
                        select_required: true,
                    }
                  }
                });
            });

            // Validate PURLs edit name form
            $('.purls-change-name-form', context).once('sunrun_purls', function() {
                var $form   = $(this);
                var $submit_button = $(this).find('[type="button"].form-submit');
                var $submit_real   = $(this).find('[name="saveNameDetails"]');
                var validator = $form.validate({
                  rules: {
                    'firtsNameTexfield': { required: true },
                    'lastNameTexfield': { required: true },
                  }
                });

                $submit_button.on('click', function(e){
                    validator.form();
                    if($form.valid()) {
                        $submit_button.hide();
                        $submit_real.parent().removeClass('hide');
                        $submit_real.trigger('mousedown');
                    }
                });
            });
            // Validate PURLs edit addres form
            $('.purls-change-address-form', context).once('sunrun_purls', function() {
                // Adding new method to validate zipcode
                $.validator.addMethod('zipcode', function(value, element) {
                  return this.optional(element) || /(^\d{5}$)/.test(value);
                }, 'Please provide a valid zipcode.');
                // Adding new method to validate zipcode available in sunrun
                $.validator.addMethod('zipcode_sunrun', function(value, element) {
                  return this.optional(element) || zipcodes.indexOf(value) >= 0;
                }, 'We\'re sorry! Sunrun is not yet available where you live. We will send you an email when Sunrun becomes available in your area.');

                var $form   = $(this);
                var $submit_button = $(this).find('[type="button"].form-submit');
                var $submit_real   = $(this).find('[name="saveAddressDetails"]');
                var validator = $form.validate({
                  rules: {
                    'addressTextfield': { required: true },
                    'cityTextfield': { required: true },
                    'zipTextfield': {
                        required : true,
                        zipcode: true,
                        zipcode_sunrun: true,
                    }
                  }
                });

                $submit_button.on('click', function(e){
                    validator.form();
                    if($form.valid()) {
                        $submit_button.hide();
                        $submit_real.parent().removeClass('hide');
                        $submit_real.trigger('mousedown');
                    }
                });
            });
        }
    };

})(jQuery);
