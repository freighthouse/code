/* globals Drupal, MktoForms2, jQuery, zipcodes, dataLayer */
(function ($) {
    Drupal.behaviors.sunrun_leadforms = {
        attach: function (context, settings) {


            // Marketo Forms

            if(typeof(MktoForms2) !== 'undefined')
            {
                MktoForms2.loadForm(settings.sunrun_leadforms.environment, settings.sunrun_leadforms.munchkin_id, settings.sunrun_leadforms.form_id, function (form)
                {
                    //form manipulation
                    switch(settings.sunrun_leadforms.form)
                    {
                        case 'get-quote':
                            break;

                        case 'referral-form':
                            $('#I_m_Already__c').closest('.mktoCheckboxList').find('label').text('I\'m a Customer');
                            break;

                        case 'soft-signup':
                            break;
                    }

                    jQuery(".mktoForm, .mktoForm *").removeAttr("style");
                    var formElement = form.getFormElem();
                    if(settings.sunrun_leadforms.form !== 'soft-signup') {
                        formElement.find(".mktoButtonRow").after('<small class="pageid-tcpa">' + settings.sunrun_leadforms.tcpa_disclosure + "</small>"
                        );
                    }

                    form.onValidate(function (values)
                    {
                        var vals = form.vals();
                        var zipPattern = /(^\d{5}$)/;
                        var numbersPattern = /^[0-9]+$/;
                        var phonePattern = /^\(?([0-9]{3})\)?[-. ]?([0-9]{3})[-. ]?([0-9]{4})$/;
                        var emailPattern = /^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$/;
                        var namePattern = /^[A-Z\-\s\.\,']*$/i;
                        var toperrors = "";
                        var hasErrors = false;
                        var $messages = $('.error-top-fields');

                        var emailValidator = function () {
                          if ( !( emailPattern.test( vals.Email ) ) ) {
                              hasErrors = true;
                              var email = formElement.find("#Email");
                              showError('#Email', 'Please enter a valid email address.', email);
                          } else {
                              removeError('#Email');
                          }
                        }
                        var firstNameValidator = function(firstMessage) {
                          if (vals.FirstName.length === 0 || !( namePattern.test( vals.FirstName ) ) ) {
                              hasErrors = true;
                              var firstName = formElement.find("#FirstName");
                              showError('#FirstName', firstMessage, firstName);
                          } else {
                              removeError('#FirstName');
                          }
                        }
                        var lastNameValidator = function(lastMessage) {
                          if (vals.LastName.length === 0 || !( namePattern.test( vals.LastName ) ) ) {
                              hasErrors = true;
                              var lastName = formElement.find("#LastName");
                              showError('#LastName', lastMessage, lastName);
                          } else {
                              removeError('#LastName');
                          }
                        }
                        var zipCodeValidator = function() {
                          if (!( zipPattern.test(vals.PostalCode) )) {
                              hasErrors = true;
                              var postalCode = formElement.find("#PostalCode");
                              showError('#PostalCode', 'Please enter a valid zip code.', postalCode);
                          } else {
                              removeError('#PostalCode');
                          }
                        }
                        var phoneValidator = function() {
                          if (!( phonePattern.test(vals.Phone) )) {
                              hasErrors = true;
                              var phone = formElement.find("#Phone");
                              showError('#Phone', 'Please enter a valid phone number.', phone);
                          } else {
                              removeError('#Phone');
                          }
                        }
                        var notesValidator = function() {
                          if (vals.Notes__c.length === 0) {
                              hasErrors = true;
                              var notes = formElement.find("#Notes__c");
                              showError('#Notes__c', 'Please enter your previous address.', notes);
                          } else {
                              removeError('#Notes__c');
                          }
                        }

                        //TODO: refactor marketo form validation
                        if(settings.sunrun_leadforms.form === 'soft-signup')
                        {
                          emailValidator();
                        } else if(settings.sunrun_leadforms.form === 'referral-form') {
                            firstNameValidator("Please enter their first name.");
                            lastNameValidator("Please enter their last name.");


                            if ( !( emailPattern.test( vals.Email ) ) ) {
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

                            //Referral information
                            if (vals.Referred_by_Contact_First_Name__c.length === 0 || !( namePattern.test( vals.Referred_by_Contact_First_Name__c ) ) ) {
                                hasErrors = true;
                                var firstName = formElement.find("#Referred_by_Contact_First_Name__c");
                                showError('#Referred_by_Contact_First_Name__c', 'Please enter your first name.', firstName);
                            } else {
                                removeError('#Referred_by_Contact_First_Name__c');
                            }

                            if (vals.Referred_by_Contact_Last_Name__c.length === 0 || !( namePattern.test( vals.Referred_by_Contact_Last_Name__c ) ) ) {
                                hasErrors = true;
                                var lastName = formElement.find("#Referred_by_Contact_Last_Name__c");
                                showError('#Referred_by_Contact_Last_Name__c', 'Please enter your last name.', lastName);
                            } else {
                                removeError('#Referred_by_Contact_Last_Name__c');
                            }

                            if ( !( emailPattern.test( vals.Referred_by_Contact_Email__c ) ) ) {
                                hasErrors = true;
                                var email = formElement.find("#Referred_by_Contact_Email__c");
                                showError('#Referred_by_Contact_Email__c', 'Please enter a valid email address.', email);
                            } else {
                                removeError('#Referred_by_Contact_Email__c');
                            }

                            if (!( phonePattern.test(vals.Referred_by_Contact_Phone__c) )) {
                                hasErrors = true;
                                var phone = formElement.find("#Referred_by_Contact_Phone__c");
                                showError('#Referred_by_Contact_Phone__c', 'Please enter a valid phone number.', phone);
                            } else {
                                removeError('#Referred_by_Contact_Phone__c');
                            }

                            if ( !( namePattern.test( vals.Sales_rep_of_referrer__c ) ) ) {
                              hasErrors = true;
                              var salesRep = formElement.find("#Sales_rep_of_referrer__c");
                              showError('#Sales_rep_of_referrer__c', 'Please enter your sales representative.', salesRep);
                            } else {
                              removeError('#Sales_rep_of_referrer__c');
                            }

                          if ( !( namePattern.test( vals.How_Do_You_Know_This_Person__c ) ) ) {
                            hasErrors = true;
                            var howDoYouKnow = formElement.find("#How_Do_You_Know_This_Person__c");
                            showError('#How_Do_You_Know_This_Person__c', 'Please enter how you know each other.', howDoYouKnow);
                          } else {
                            removeError('#How_Do_You_Know_This_Person__c');
                          }


                        } else if(settings.sunrun_leadforms.form === 'service-transfer-form') {
                          emailValidator();
                          firstNameValidator("Please enter your first name.");
                          lastNameValidator("Please enter your last name.");
                          zipCodeValidator();
                          phoneValidator();
                          notesValidator();

                        } else {
                            if (vals.FirstName.length === 0) {
                                hasErrors = true;
                                var firstName = formElement.find("#FirstName");
                                showError('#FirstName', 'Please enter your first name.', firstName);
                            } else {
                                removeError('#FirstName');
                            }

                            if (vals.LastName.length === 0) {
                                hasErrors = true;
                                var lastName = formElement.find("#LastName");
                                showError('#LastName', 'Please enter your last name.', lastName);
                            } else {
                                removeError('#LastName');
                            }

                            if (!( emailPattern.test(vals.Email) )) {
                                hasErrors = true;
                                var email = formElement.find("#Email");
                                showError('#Email', 'Please enter a valid email address.', email);
                            } else {
                                removeError('#Email');
                            }

                            phoneValidator();

                            zipCodeValidator();

                            // Validate electric bill
                            if (!( numbersPattern.test(vals.Average_Monthly_Electric_Bill__c) )) {
                                hasErrors = true;
                                var monthlyBill = formElement.find("#Average_Monthly_Electric_Bill__c");
                                showError('#Average_Monthly_Electric_Bill__c', 'Please enter the amount of your typical monthly bill, e.g. 180.', monthlyBill);
                            } else {
                                removeError('#Average_Monthly_Electric_Bill__c');
                            }

                        }

                        if(hasErrors) {
                            // Google Analitycs track errors
                            if(settings.sunrun_leadforms.form === 'standard-leadform'){
                                ga('send', 'event', 'errors', 'quote form ', 'validation error');
                            }
                            form.submittable(false);
                        } else {
                            form.submittable(true);
                        }
                        //TODO: there may not be anything needed in this callback if we use the validation given to us by marketo.

                    });

                    form.onSuccess(function (values, followUpUrl)
                    {
                        form.getFormElem().hide();
                        $('.leadform-top-fields').html('Enter your street address');

                        if(settings.sunrun_leadforms.form === 'soft-signup')
                        {
                          ga('send', 'event', 'sign up', 'submit', 'submit success');
                        }
                        else if(settings.sunrun_leadforms.form === 'standard-leadform')
                        {
                          dataLayer.push({
                             'event': 'quote-form-progress',
                             'state': 'Quote Form',
                             'action': 'Submit',
                             'widget': ' Step 1'
                           });
                           dataLayer.push({'event' : 'lead-form-submitted'});
                            

                            MktoForms2.loadForm(settings.sunrun_leadforms.environment, settings.sunrun_leadforms.munchkin_id, settings.sunrun_leadforms.form_id_step_2, function (FollowUpForm)
                            {
                                // Set street address, if FollowUpForm loads with Ziptool module
                                var vals = FollowUpForm.vals();
                                var ziptoolStreet = $('#ziptoolStreet').val();

                                if( ziptoolStreet ) {
                                  if (vals.Street) {
                                    FollowUpForm.vals({ "Street":ziptoolStreet});
                                  } else {
                                    FollowUpForm.vals({ "Address":ziptoolStreet});
                                  }
                                }

                                // scroll to the top of the form div for the second step of the form on mobile
                                if ($(window).width() <= 1024) {
                                  $('html,body').animate({
                                    scrollTop: $('.pane-sunrun-leadform').offset().top - 20
                                  }, 500);
                                }

                                var FollowUpFormElement = FollowUpForm.getFormElem();
                                FollowUpFormElement.removeAttr('style');
                                FollowUpFormElement.find('*').removeAttr('style');

                                FollowUpForm.onValidate(function (values) {

                                });

                                FollowUpForm.onSuccess(function (values, followUpUrl) {
                                    FollowUpFormElement.hide();
                                    // Google Analitycs event
                                    ga('send', 'event', 'quote form', 'submit (step 2) ', settings.sunrun_tracking.full_url);
                                    // Universal Analytics Event Tracking Step 2
                                    dataLayer.push({
                                        'event': 'quote-form-progress',
                                        'state': 'Quote Form',
                                        'action': 'Submit',
                                        'widget': ' Step 2'
                                    });
                                    // Google Analitycs track thanks page
                                    ga('send', 'event', 'quote form', 'view (thanks) ', settings.sunrun_tracking.full_url);
                                    /* Universal Analytics: track thanks page */
                                    dataLayer.push({
                                        'event': 'quote-form-progress',
                                        'state': 'Quote Form',
                                        'action': 'View',
                                        'widget': 'Thanks'
                                    });


                                    // Redirect if needed
                                    if(typeof settings.sunrun_leadforms.redirect !== 'undefined' && settings.sunrun_leadforms.redirect){
                                        window.location.href = settings.basePath + settings.sunrun_leadforms.redirect;
                                        return false;
                                    }
                                });  // FollowUpForm.onSuccess
                            });
                            return false;
                        }
                        // Redirect if needed
                        if(typeof settings.sunrun_leadforms.redirect !== 'undefined' && settings.sunrun_leadforms.redirect){
                            window.location.href = settings.basePath + settings.sunrun_leadforms.redirect;
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

        }
    };

})(jQuery);
