/* globals Drupal, jQuery, dataLayer, SunrunZipCode, window */
"use strict";
(function ($) {
  Drupal.behaviors.sunrun_jquery_validate_config = {
    attach: function (context, settings) {

      if ($.validator) {
        // Valid Name
        $.validator.addMethod('validname', function (value, element) {
          return this.optional(element) || (/^[A-Z\-\s']+$/i).test(value);
        }, 'Please enter a valid name.');

        // US phone number validation
        $.validator.addMethod("phone", function (value, element) {
          return this.optional(element) || (/^\(?([0-9]{3})\)?[\-.\s]?([0-9]{3})[\-.\s]?([0-9]{4})$/).test(value);
        }, "Please enter a valid phone number.");

        // zip code should be 5 digits
        $.validator.addMethod("zipcode", function (value, element) {
          return this.optional(element) || (/^\d{5}$/).test(value);
        }, "Please enter a five digit zip code.");

        // Comcast employee email
        $.validator.addMethod("comcast_email", function(value, element) {
          return this.optional( element ) || (/^([0-9a-zA-Z]([\-.\w]*[0-9a-zA-Z])*@(comcast.com|cable.comcast.com|nbcuni.com|comcast-spectacor.com))$/).test( value );
        }, "Please enter a valid Comcast NBCUniversal email address");

        var config = new Object();
        config = {
          rules: {
            first_name: {
              required: true,
              validname: true
            },
            last_name: {
              required: true,
              validname: true
            },
            phone: {
              phone: true,
              required: true
            },
            // zipcode
            '00N60000001aGx2': {
              required: true,
              zipcode: true
            },
            email: {
              required: true
            },
          },
          submitHandler: function (form) {
            // Remove out of territory cookie if set by comcast employee
            window.dataLayer = window.dataLayer || [];
            dataLayer.push({
              'category': settings.webform.datalayer.category,
              'action': 'form submit',
              'label': window.location.pathname
            });
            form.submit();
          }
        };
        // Add email rule from settings (comcast epp form has special rule)
        if(settings.webform.validator.methods.hasOwnProperty('email')){
          config['rules']['email'][settings.webform.validator.methods.email] = true
        }

        // Form Validation
        $("#web-to-lead-form").validate(config);


      } // if ($.validator)
    }
  };
}(jQuery));