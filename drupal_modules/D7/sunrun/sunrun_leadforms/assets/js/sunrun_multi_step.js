/* global SunrunZipCode */
(function($) {
  Drupal.behaviors.sunrun_leadforms_multi_step = {
    attach: function(context, settings) {
      $('.pane-sunrun-leadform-multi-step').once('multi-step-form', function() {
        var current_fs, next_fs, previous_fs, //fieldsets
        left, opacity, scale, //fieldset properties which we will animate
        animating, //flag to prevent quick multi-click glitches
        ms_form = $("#multi-step-form"),
        success_msg = $(".thank-you"),
        validator;

        success_msg.hide();

        if ($.validator) {
          // US phone number validation
          $.validator.addMethod("phoneUS", function(phone_number, element) {
            phone_number = phone_number.replace(/\s+/g, "");
            return this.optional(element) || phone_number.length > 9 &&
              phone_number.match(/^(\+?1-?)?(\([2-9]([02-9]\d|1[02-9])\)|[2-9]([02-9]\d|1[02-9]))-?[2-9]([02-9]\d|1[02-9])-?\d{4}$/);
          }, "Please specify a valid phone number");

          // standard zip code validation
          $.validator.addMethod("zipcode", function(value, element) {
            return /^\d{5}$/.test(value);
          }, "Please enter a valid zip code.");

          $.validator.addMethod("email_custom", function(value, element) {
            return this.optional(element) || /^(([^<>()\[\]\\.,;:\s@"]+(\.[^<>()\[\]\\.,;:\s@"]+)*)|(".+"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/.test(value);
          }, "Please enter a valid email address.");
          validator = ms_form.validate({
            rules: {
              zip: {
                required: true,
                zipcode: true,
              },
              electric_bill: {
                required: true,
              },
              first_name: {
                required: true,
              },
              last_name: {
                required: true,
              },
              phone: {
                required: true,
                phoneUS: true,
              },
              email: {
                required: true,
                email_custom: true
              },
            },
            messages: {
              zip: {
                required: "Please enter your zip code.",
                zipcode: "Please enter your zip code.",
              },
              first_name: "Please enter your first name.",
              last_name: "Please enter your last name.",
              email: "Please enter your email address.",
              phone: "Please enter a valid phone number.",
              electric_bill: "Please enter your monthly electric bill.",
            },
            submitHandler: function(form) {
              _submitHandler();
            }
          });
        }

        $(".next").click(function() {
          current_fs = $(this).closest("fieldset");
          //console.log(current_fs.attr('id'));
          if (current_fs.attr('id') === 'first' && validator.element('#zip')) {

            dataLayer.push({
              'event': 'form-step-complete',
              'form-name': 'Multi Step',
              'step-name': 'SR Step 1'
            });
            // If the Rent option is checked redirect the page
            if ($('#property_ownership-RENT').is(':checked')) {
              document.location.href = "https://gosolar.sunrun.com/noho/";
            }
          }
          else if (current_fs.attr('id') === 'second' && $('#electric_bill').valid()) {
            dataLayer.push({
              'event': 'form-step-complete',
              'form-name': 'Multi Step',
              'step-name': 'SR Step 2'
            });
          }
          if (current_fs.attr('id') === 'first' && validator.element('#zip') ||
            current_fs.attr('id') === 'second' && validator.element('#electric_bill')) {
            //console.log(current_fs.attr('id') + " step");
            if (animating) {
              //console.log(animating);
              return false;
            }
            animating = true;
            next_fs = $(this).closest("fieldset").next();

            //activate next step on progressbar using the index of next_fs
            $("#progressbar li").eq($("fieldset").index(next_fs)).addClass("active");

            //show the next fieldset
            next_fs.show();
            var bheight = next_fs.height();
            //Programatically set height on cap-box-bottom
            $(".cap-box-bottom").height(bheight+120);
            //hide the current fieldset with style
            current_fs.animate({
              opacity: 0
            }, {
              step: function(now, mx) {
                //as the opacity of current_fs reduces to 0 - stored in "now"
                //1. scale current_fs down to 80%
                scale = 1 - (1 - now) * 0.2;
                //2. bring next_fs from the right(50%)
                left = (now * 50) + "%";
                //3. increase opacity of next_fs to 1 as it moves in
                opacity = 1 - now;
                current_fs.css({
                  'transform': 'scale(' + scale + ')'
                });
                next_fs.css({
                  'left': left,
                  'opacity': opacity
                });
              },
              duration: 800,
              complete: function() {
                current_fs.hide();
                animating = false;
              },
              //this comes from the custom easing plugin
              easing: 'easeInOutBack'
            });
          }
        });

      function _submitHandler() {
        var data = ms_form.serializeArray();
        $.ajax({
          type: 'post',
          url: '//www.sunruntransit.com/track/lead',
          contentType: 'text/plain',
          xhrFields: {
            withCredentials: true
          },
          data: $.param(data),
          success: function(result) {
            // handle success
            console.log('SUCCESS; Lead ID = ' + result.lead_id);
          },
          error: function(error) {
            // handle error
            alert('ERROR:' + error);
          }
        });
        window.dataLayer = window.dataLayer || [];
        dataLayer.push({
          'category': 'Multi-step Quote Form',
          'action': 'Submit',
          'label': window.location.pathname,
          'event': 'form-step-complete',
          'form-name': 'Multi Step',
          'step-name': 'SR Step 3'
        });
        dataLayer.push({
          'category': 'quote form',
          'action': 'form submit',
          'label': window.location.pathname
        });
        dataLayer.push({'event' : 'lead­form­submitted'});

        _thankyouHandler();
        // return false to prevent normal browser submit and page navigation
        return false;
      }
      function _thankyouHandler() {
        if (animating) return false;
        animating = true;
        $('#progressbar').hide();
        success_msg.show();

        var sunrunZipCode = new SunrunZipCode();

        // Display thank you message
        if ( sunrunZipCode.inService($('#zip').val()) === false ){
          $('.in-service-msg').hide();
          $('.out-of-service-msg')
              .show();
        }

        $(".cap-box-bottom").height(425);
        ms_form.animate({
          opacity: 0
        }, {
          step: function(now, mx) {
            scale = 1 - (1 - now) * 0.2;
            left = (now * 50) + "%";
            opacity = 1 - now;
            ms_form.css({
              'transform': 'scale(' + scale + ')'
            });
            success_msg.css({
              'left': left,
              'opacity': opacity
            });
          },
          duration: 800,
          complete: function() {
            ms_form.hide();
            animating = false;
          },
          easing: 'easeInOutBack'
        });
      }
      return false;
    });
    }
  };

}(jQuery));
