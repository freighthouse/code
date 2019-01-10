/**
 * Main JS for ziptool
 */
/* globals zipcodes, Drupal, MktoForms2, jQuery, google, SunrunZipCode */
(function($) {
  Drupal.behaviors.sunrunZiptool = {
    attach: function(context, settings) {
        var $sections = [],
          zipFound = 0,
          map = {},
          state = '',
          zip = '',
          address_found = true,
          editing = false,
          $this = {};
          var geocoder = new google.maps.Geocoder();
          var sunrunZipCode = new SunrunZipCode();

          // load validator if not admin page
          if ($.validator) {
            // phone validation set in sunrun_zeus_forms.js

              $.validator.addMethod("sunrun_zipcode", function(value, element) {
                  return this.optional(element) || sunrunZipCode.inService($('#zipcode').val());
              }, "Sorry, currently we\'re not in your state.");

            $.validator.addMethod("address", function(value, element) {
              codeAddress();
              return this.optional(element) || address_found;
            }, "Please enter a valid zip code. Example: 94704");

            var validator = $(".ziptoolForm").validate({
              rules: {
                zipcode: {
                  required: true,
                    sunrun_zipcode: true
                },
                ziptoolStreet: "required",
                Bill: {
                  required: true,
                  min: 0,
                }
              },
              messages: {
                Bill: {
                  number: "Please enter a number.",
                  min: "Please enter a positive number"
                }
              },
              errorElement: "div",
              onfocusout: false,
            });
          }
          // Set zipcode field, if submitted from homepage

          if (typeof(settings.sunrun_ziptool.zipcode) !== 'undefined') {
            $('.ziptoolForm #zipcode').val(settings.sunrun_ziptool.zipcode);
          }

          initializeZiptool();

          function initializeZiptool() {
            // hide edit button
            $sections = $('.ziptoolForm > .formRow');
            $('.step-4').hide();
            navigateTo(0);
          }

          function navigateTo(index) {
            // Mark the current section with the class 'current'
            //console.log("navigateTo: " + index);
            $sections
              .removeClass('current')
              .removeClass('complete')
              .eq(index)
              .addClass('current')
              .prevAll('.formRow')
              .addClass("complete");

            if (index === 0) {
              handleStepOne();
            } else if (index === 1) {
              handleStepTwo();
            } else if (index === 2) {
              handleStepThree();
            } else if (index === 3) {
              handleStepFour();
            } else if (index === 4) {
              handleStepFive();
            }
          }

          // Next button handler
          $('.next').on('click', function(e) {
            //console.log('click handler called');
            e.preventDefault();
            var currentStep = curIndex() + 1;
            var clickedButton = '#' + $('.step-' + currentStep).find('input').attr('id');
            //console.log("clicked button: " + clickedButton);
            if ( validator.element(clickedButton) ) {
              navigateTo(curIndex() + 1);
            }
          });


          function handleStepOne() {
            if ( ($('.ziptoolForm #zipcode').val()) && (editing === false) ) {
              setTimeout(skipStepOne, 1000);
            }
            $('#results-header').hide();
            $('.ziptool-content-panel').hide();
            $('.step-1 .edit-link').hide();
            $('.step-1 .city-state').hide();
            $('.step-1 .help-block').show();
            $('.step-1 .help-block').replaceWith('<p class="help-block">See if we\'re in your area.</p>');

            $('.step-2 .edit-link').hide();
            // $('.step-2 .help-block').hide();
            // $('.step-2 .bill-review').hide();
            $('.step-2 .supporting-text').hide();

            $('.step-3 .edit-link').hide();
            $('.step-3 .address').hide();
            $('.step-3 .help-block').hide();

            $('#map-container').hide();
            $('.step-4').hide();

          }

          function skipStepOne() {
            if ( validator.element('#zipcode') ) {
              navigateTo(1);
            }
          }

          function handleStepTwo() {
            //console.log('debug: handleStepTwo');
            $('.ziptool-content-panel').hide();
            $('.step-1 .edit-link').show();
            $('.step-1 .help-block').replaceWith('<p class="help-block">We\'re in your area.</p>');
            $('.step-1 .city-state').show();
            $('.step-1 .in-area').show();

            $('.step-2 .supporting-text').show();

            $('.step-2 .bill-review').hide();
            $('.step-2 .monthly-bill').hide();
            $('.step-2 .help-block').replaceWith('<p class="help-block">What\'s your average monthly electric bill?</p>');

            $('.step-3 .edit-link').hide();
            $('.step-3 .supporting-text').hide();

            $('#ziptool-out-of-area').hide();
            getAddressInfoByZip($('#zipcode').val());
            $('#Bill').focus();
            $('.step-4').hide();
          }

          function handleStepThree() {
            //console.log('debug: handleStepThree');
            $('.ziptool-content-panel').hide();
            $('.step-2 .edit-link').show();

            var bill = $('#Bill').val();
            $('.step-2 .help-block').replaceWith('<p class="help-block">$' + bill + '/month</p>');
            if ( bill < 75 ) {
              $('.bill-review').replaceWith('<p class="bill-review">Actually that\'s not bad.</p>');
              $('#bill-low').show();
            } else if ( (bill >= 75 ) && (bill < 150) ) {
              $('.bill-review').replaceWith('<p class="bill-review">That\'s pretty high</p>');
              $('#bill-medium').show();
            } else {
              $('.bill-review').replaceWith('<p class="bill-review">Wow, that\'s really high.</p>');
              $('#bill-high').show();
            }
            $('.step-3 .help-block').show();
            $('.step-3 .help-block').replaceWith('<p class="help-block">What\'s your street address?</p>');

            $('.step-3 .edit-link').hide();
            $('.step-4').hide();
            $('.step-3 .supporting-text').show();

            $('.bill-review').show();
            $('#ziptoolStreet').focus();
          }

          function handleStepFour() {
            //console.log('debug: handleStepFour');
            $('.ziptool-content-panel').hide();
            $('.step-4').show();
            $('.step-3 .edit-link').show();
            // set step 1 - 3 to 30%
            $('.step-1, .step-2, .step-3').css('width', '30%');
            $('.step-3 .help-block').replaceWith('<p class="help-block">' + $('#ziptoolStreet').val() + '</p>');
            $('#request-quote').hide();
            $('#map-container').show();
            initializeMap();
            codeAddress($('#ziptoolStreet').val(), $('.city-state').text());
          }

          function handleStepFive() {
            //console.log('handleStepFive');
            $('.ziptool-content-panel').hide();
            $('.pane-sunrun-ziptool-ziptool-block').hide();
            $('#default-header').hide();
            $('#results-header').show();

            $('.step-1, .step-2, .step-3, .step-4').hide();
            $('.divider').hide();
            $(".pane-sunrun-leadform").show();
            $("#ziptool-house").show();
            $('#FirstName').focus();
            $('#ziptool-rating').show();

            var selectedInput = $('input[name=shade]:checked').val();
            if (selectedInput === 'max') {
              $('.shade').text('high');
            } else if (selectedInput === 'mid') {
              $('.shade').text('medium');
            } else {
              $('.shade').text('small');
            }

            // Transfer form values to Zeus quote form
            $('#zip').val($('#zipcode').val());
            //$('#zip').closest('.form-group').hide();


            // Add arrow to standard quote form CTA
            $('.mktoForm .mktoButton').html($('.mktoForm .mktoButton').text() + ' &#10095;');
          }

          // Edit button handler
          $( ".step-1 .edit" ).on( "click", function() {
            editing = true;
            navigateTo(0);
          });
          $( ".step-2 .edit" ).on( "click", function() {
            navigateTo(1);
          });
          $( ".step-3 .edit" ).on( "click", function() {
            navigateTo(2);
          });

        function curIndex() {
          // Return the current index by looking at which section has the class 'current'
          return $sections.index($sections.filter('.current'));
        }

        function handleZipNotFound() {
          //console.log('handleZipNotFound');
          $('.step-1').find('.help-block').replaceWith('Sunrun is not currently available in your area.');
          $('.step-1 .form-group').hide();
          $('#ziptool-out-of-area').show();
        }

        function initializeMap() {
          var latlng = new google.maps.LatLng(-34.397, 150.644);
          var mapOptions = {
            center: latlng,
            navigationControl: false,
            mapTypeControl: false,
            scaleControl: false,
            draggable: false,
            disableDoubleClickZoom: true,
            zoom: 20,
            disableDefaultUI: true,
            mapTypeId: google.maps.MapTypeId.SATELLITE
          };
          map = new google.maps.Map(document.getElementById("map"), mapOptions);
        }

        function codeAddress(street, cityStateZip) {
          var fullAddress = street + ', ' + cityStateZip + ', USA';
          // console.log(fullAddress);
          geocoder.geocode({
            'address': fullAddress,
          }, function(results, status) {
            if (status === google.maps.GeocoderStatus.OK) {
              map.setCenter(results[0].geometry.location);
              // var marker = new google.maps.Marker({
              //   map: map,
              //   position: results[0].geometry.location
              // });
              address_found = true;
            } else {
              if (status === 'ZERO_RESULTS') {
                //console.log(status);
                $('.address').replaceWith('<p>Address not found</p>');
                address_found = false;
              }
            }
          });
        }

        function getAddressInfoByZip(zip) {
          var city, state, county, formatted_address;
            geocoder.geocode({
            'address': zip,
          }, function(results, status) {
            if (status === google.maps.GeocoderStatus.OK) {
              formatted_address = results[0].formatted_address.replace(", USA", "");

              // Get address components
              for (var i = 0; i < results[0].address_components.length; i++) {
                if (results[0].address_components[i].types[0] === "administrative_area_level_1") {
                  state = results[0].address_components[i].short_name;
                } else if (results[0].address_components[i].types[0] === "locality"){
                  city = results[0].address_components[i].long_name;
                } else if (results[0].address_components[i].types[0] === "administrative_area_level_2") {
                  county = results[0].address_components[i].long_name;
                }
              }
              $('.step-1 .city-state').replaceWith('<p class="city-state">' + formatted_address + '</p>');

              loadState(state);
            }
          });
        }

        function loadState(state) {
          switch (state) {
            case 'AZ':
              $('#ziptool-az').show();
              break;
            case 'CA':
              $('#ziptool-ca').show();
              break;
            case 'CO':
              $('#ziptool-co').show();
              break;
            case 'CT':
              $('#ziptool-ct').show();
              break;
            case 'DE':
              $('#ziptool-de').show();
              break;
            case 'HI':
              $('#ziptool-hi').show();
              break;
            case 'MD':
              $('#ziptool-md').show();
              break;
            case 'MA':
              $('#ziptool-ma').show();
              break;
            case 'NV':
              $('#ziptool-nv').show();
              break;
            case 'NH':
              $('#ziptool-nh').show();
              break;
            case 'NJ':
              $('#ziptool-nj').show();
              break;
            case 'NY':
              $('#ziptool-ny').show();
              break;
            case 'OR':
              $('#ziptool-or').show();
              break;
            case 'PA':
              $('#ziptool-pa').show();
              break;
            case 'SC':
              $('#ziptool-sc').show();
              break;
          }
        }
      } // attach: function (context, settings)
  }; // Drupal.behaviors.sunrunZiptool
})(jQuery); //function($)
