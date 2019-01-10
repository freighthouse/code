/**
 * Main JS for saving calculator
 */

/*global
GenabilityApi, google, History, zipcodes, accounting
*/
(function ($) {
  Drupal.behaviors.sunrunCalculator = {
    attach: function (context, settings) {

      $('.savings-calculator', context).once('sunrun-calculator', function () {
        var $initial = $(this).find('.step.initial');
        var $results = $(this).find('.map-results');
        var $calculator_results = $(this).find('.calculator-results');
        var account_id = "";
        var profile_id = "";
        var lse_id = "";

        // Parse address
        var street_number = typeof (settings.sunrun_calculator.street_number) !== 'undefined' ? settings.sunrun_calculator.street_number : '';
        var street = typeof (settings.sunrun_calculator.street) !== 'undefined' ? settings.sunrun_calculator.street : '';
        var city = typeof (settings.sunrun_calculator.city) !== 'undefined' ? settings.sunrun_calculator.city : '';
        var state = typeof (settings.sunrun_calculator.state) !== 'undefined' ? settings.sunrun_calculator.state : '';
        var zipcode = typeof (settings.sunrun_calculator.zipcode) !== 'undefined' ? settings.sunrun_calculator.zipcode : '';
        var country = typeof (settings.sunrun_calculator.country) !== 'undefined' ? settings.sunrun_calculator.country : '';

        var addressPresent = false;
        if (street_number && street && city && state && zipcode) {
          addressPresent = true;
        }

        if (addressPresent && country !== 'United States') {
          window.location.replace(Drupal.settings.sunrun_calculator.error_redirect_url);
        }

        // Exclude zipcodes using Residential NEM 2 tariff for Palo Alto (MasterTariffID=3270057)
        var excludedZipCodes = ['94301', '94302', '94304', '92201', '92202', '92222', '92227', '92231', '92232', '92233', '92236', '92243', '92244', '92247', '92248', '92249', '92250', '92251', '92253', '92254', '92257', '92259', '92273', '92274', '92275', '92276', '92281', '92283', '95353', '95397'];
        if (excludedZipCodes.indexOf(zipcode) > -1) {
          window.location.replace(Drupal.settings.sunrun_calculator.error_redirect_url);
        }


        var address = addressPresent ? street_number + ' ' + street + ', ' + city + ' ' + state + ', ' + zipcode : "";

        // Defaults for accounting plugin (for formatting numeric values)
        accounting.settings.currency.precision = 0;

        var eligibilityResponses = {
          "success": "Great news! Your estimated lifetime solar savings could be up to <span></span></h1>",
          "noaddress": "See how much you can save by going solar with Sunrun!"
        };

        // $('.toggle-methods a').on('click', function () {
        //   $('.compare').toggleClass('hidden');
        // });

        // Hide various elements and show address form if they got here without first filling out the form
        if (addressPresent !== true) {
          $('.map-results.obscurable').removeClass('obscured');
          $('.blur-overlay').addClass('receded');
          $('.savings-calculator').addClass('no-address');
          $('.no-address-hide').hide();
          $calculator_results.find('.message h1').html(eligibilityResponses.noaddress);
          $('.map-canvas .map').addClass('no-address');
        }

        // Initialize and handle slider events
        $('input[type="range"]').rangeslider({
          polyfill: false,
          rangeClass: 'rangeslider',
          disabledClass: 'rangeslider--disabled',
          horizontalClass: 'rangeslider--horizontal',
          fillClass: 'rangeslider__fill',
          handleClass: 'rangeslider__handle',

          onInit: function () {
            $rangeEl = this.$range;
            var $handle = $rangeEl.find('.rangeslider__handle');
            var handleValue = '<div class="rangeslider__handle__value">$' + this.value + '</div>';
            $handle.append(handleValue);

            $rangeEl.append('<div class="rangeslider__labels"></div>');
            $rangeEl.find('.rangeslider__labels').append('<div class="rangeslider__labels__label min">$' + this.min + '</div>');
            $rangeEl.find('.rangeslider__labels').append('<div class="rangeslider__labels__label max">$' + this.max + '+</div>');
          },

          onSlide: function (position, value) {
            var $handle = this.$range.find('.rangeslider__handle__value');
            var formattedValue = this.value == this.max ? '$' + this.value + '+' : '$' + this.value;
            $handle.text(formattedValue);
            debouncedFinancingEstimateCall();
          }
        });

        var debouncedFinancingEstimateCall = debounce(function () {
          $('.obscurable').addClass('obscured');
          $('.blur-overlay').removeClass('receded').show();
          getAdjustedSavingsResult();
        }, 500);


        function getMap() {
          var mapOptions = {
            scrollwheel: false,
            navigationControl: false,
            mapTypeControl: false,
            scaleControl: false,
            draggable: true,
            disableDoubleClickZoom: true,
            zoom: 21,
            disableDefaultUI: true,
            mapTypeId: google.maps.MapTypeId.SATELLITE
          };

          var geocoder = new google.maps.Geocoder();
          var state;
          geocoder.geocode({
            'address': address
          }, function (results, status) {
            if (status === google.maps.GeocoderStatus.OK) {
              $('.map').each(function (idx, val) {
                var map = new google.maps.Map($(this)[0], mapOptions);
                var location = results[0].geometry.location;
                map.setCenter(location);

                var full_address = results[0].address_components;
                var index = full_address.length;

                $results.find('.overlay-address span').html(results[0].formatted_address.replace(', USA', ''));
                getInitialSavingsResults();
              });
            }
          });
        }

        function getInitialSavingsResults() {

          var analysisUrl = "/rest/v1/savings-analysis";

          var max_lifetime_savings = 0;

          var monthly = false;
          var prepaid = false;
          var advantage = false;
          var buy = false;

          var purchase_plans_available = false;
          var lease_plans_available = false;

          var params = {
            "street_address": street_number + " " + street,
            "state": state,
            "zipcode": zipcode,
            "est_monthly_bill": $('input[type="range"]').val()
          };

          $.ajax({
            type: 'POST',
            url: analysisUrl,
            contentType: "application/json",
            crossDomain: true,
            dataType: "json",
            data: JSON.stringify(params),
            success: function (data) {
              account_id = data.account_id;
              profile_id = data.profile_id;
              lse_id = data.lse_id;

              if (data.status !== "success") {
                window.location.replace(Drupal.settings.sunrun_calculator.error_redirect_url);
              }

              if (data.advantage) {
                advantage = true;
              } else {
                $('.compare.advantage').remove();
              }

              if (data.monthly) {
                monthly = true;
              } else {
                $('.compare.monthly').remove();
              }

              if (data.buy) {
                buy = true;
              } else {
                $('.compare.cash').remove();
              }

              if (data.prepaid) {
                prepaid = true;
              } else {
                $('.compare.prepaid').remove();
              }

              if (!buy && !advantage || !prepaid && !monthly) {
                $('.toggle-methods').remove();
              }

              if (buy || advantage) {
                purchase_plans_available = true;
              }

              if (prepaid || monthly) {
                lease_plans_available = true;
              }

              if (purchase_plans_available && lease_plans_available) {
                $('.show-lease-toggle').addClass('hidden');
                $('.show-purchase-toggle').removeClass('hidden');
              }

              if (buy && data.buy.lifetime_savings > max_lifetime_savings) {
                max_lifetime_savings = data.buy.lifetime_savings;
              }

              if (advantage && data.advantage.lifetime_savings > max_lifetime_savings) {
                max_lifetime_savings = data.advantage.lifetime_savings;
              }

              if (prepaid && data.prepaid.lifetime_savings > max_lifetime_savings) {
                max_lifetime_savings = data.prepaid.lifetime_savings;
              }

              if (monthly && data.monthly.lifetime_savings > max_lifetime_savings) {
                max_lifetime_savings = data.monthly.lifetime_savings;
              }

              // Round to nearest $100

              $calculator_results.find('.message h1').html(eligibilityResponses.success);
              $calculator_results.find('.message h1 span').html(accounting.formatMoney(roundUp(max_lifetime_savings, 'max_lifetime_savings')));

              // Header results
              $('.property-size').find('span').html(accounting.formatNumber(data.property_size) + ' sq. ft.');
              $('.home-value-increase').find('span').html(accounting.formatMoney(roundUp(data.home_appreciation, 'data.home_appreciation')));
              $('.electric-cost').find('span').html(accounting.formatMoney(roundUp(data.electricity_cost_lifetime, 'data.electricity_cost_lifetime')));
              $('.trees-planted').find('span').html(data.trees_planted);

              // Monthly results
              if (monthly) {
                $('.monthly-upfront-cost').html(accounting.formatMoney(data.monthly.upfront_cost));
                $('.monthly-monthly-payment').html(accounting.formatMoney(data.monthly.monthly_pmt));
                $('.monthly-lifetime-savings').html(accounting.formatMoney(roundUp(data.monthly.lifetime_savings, 'data.monthly.lifetime_savings')));
                $('.compare.monthly').removeClass('hidden');
              }

              // Advantage results
              if (advantage) {
                $('.advantage-upfront-cost').html(accounting.formatMoney(data.advantage.upfront_cost));
                $('.advantage-monthly-payment').html(accounting.formatMoney(data.advantage.monthly_pmt));
                $('.advantage-lifetime-savings').html(accounting.formatMoney(roundUp(data.advantage.lifetime_savings, 'data.advantage.lifetime_savings')));
              }

              // Prepaid results
              if (prepaid) {
                $('.prepaid-upfront-cost').html(accounting.formatMoney(data.prepaid.upfront_cost));
                $('.prepaid-monthly-payment').html(accounting.formatMoney(data.prepaid.monthly_pmt));
                $('.prepaid-lifetime-savings').html(accounting.formatMoney(roundUp(data.prepaid.lifetime_savings, 'data.prepaid.lifetime_savings')));
                $('.compare.prepaid').removeClass('hidden');
              }

              // Cash results
              if (buy) {
                $('.cash-upfront-cost').html(accounting.formatMoney(data.buy.upfront_cost));
                $('.cash-monthly-payment').html(accounting.formatMoney(data.buy.monthly_pmt));
                $('.cash-lifetime-savings').html(accounting.formatMoney(roundUp(data.buy.lifetime_savings, 'data.buy.lifetime_savings')));
              }

              if (prepaid || monthly) {
                $('.lease-plans h2').removeClass('hidden');
              }

              if ((buy || advantage) && (!prepaid && !monthly)) {
                $('.purchase-plans h2').removeClass('hidden');

                if (buy) {
                  $('.compare.cash').removeClass('hidden');
                }

                if (advantage) {
                  $('.compare.advantage').removeClass('hidden');
                }
              }

              $('.cost-comparison .icon-chevron-down').on('click', function () {
                $('.compare .toggle').toggleClass('expanded');
              });

              $('.toggle-methods a').on('click', function() {
                $('.toggle-methods p').toggleClass('hidden');
                if ($('.purchase-plans h2').is(':visible')) {
                  $('.lease-plans h2, .lease-plans .compare').removeClass('hidden');
                  $('.purchase-plans h2, .purchase-plans .compare').addClass('hidden');
                } else {
                  $('.lease-plans h2, .lease-plans .compare').addClass('hidden');
                  $('.purchase-plans h2, .purchase-plans .compare').removeClass('hidden');
                }
              });

              $('.map-results .hide').removeClass('hide');
              $('.bill-wrapper').removeClass('disable');

              $('.blur-overlay').fadeOut(500);
              setTimeout(function() {
                $('.blur-overlay').addClass('receded');
                $('.obscurable').removeClass('obscured');
              }, 500);
            },
            error: function(xhr, d, i) {
              window.location.replace(Drupal.settings.sunrun_calculator.error_redirect_url);
            },
            failure: function (data) {
              window.location.replace(Drupal.settings.sunrun_calculator.error_redirect_url);
            }
          });
        }

        function getAdjustedSavingsResult() {
          var savingsUrl = "/rest/v1/financing-estimate";

          var max_lifetime_savings = 0;

          var monthly = false;
          var prepaid = false;
          var advantage = false;
          var buy = false;

          var params = {
            "account_id": account_id,
            "lse_id": lse_id,
            "state": state,
            "est_monthly_bill": $('input[type="range"]').val()
          };

          $.ajax({
            type: 'POST',
            url: savingsUrl,
            contentType: "application/json",
            crossDomain: true,
            dataType: "json",
            data: JSON.stringify(params),
            success: function (data) {

              if (data.advantage) {
                advantage = true;
              } else {
                $('.compare.advantage').remove();
              }

              if (data.monthly) {
                monthly = true;
              } else {
                $('.compare.monthly').remove();
              }

              if (data.buy) {
                buy = true;
              } else {
                $('.compare.cash').remove();
              }

              if (data.prepaid) {
                prepaid = true;
              } else {
                $('.compare.prepaid').remove();
              }

              if (!buy && !advantage || !prepaid && !monthly) {
                $('.toggle-methods').remove();
              }

              if (buy && data.buy.lifetime_savings > max_lifetime_savings) {
                max_lifetime_savings = data.buy.lifetime_savings;
              }

              if (advantage && data.advantage.lifetime_savings > max_lifetime_savings) {
                max_lifetime_savings = data.advantage.lifetime_savings;
              }

              if (prepaid && data.prepaid.lifetime_savings > max_lifetime_savings) {
                max_lifetime_savings = data.prepaid.lifetime_savings;
              }

              if (monthly && data.monthly.lifetime_savings > max_lifetime_savings) {
                max_lifetime_savings = data.monthly.lifetime_savings;
              }

              $calculator_results.find('.message h1 span').html(accounting.formatMoney(roundUp(max_lifetime_savings, 'max_lifetime_savings')));

              // Header results
              $('.home-value-increase').find('span').html(accounting.formatMoney(roundUp(data.home_appreciation, 'data.home_appreciation')));
              $('.electric-cost').find('span').html(accounting.formatMoney(roundUp(data.electricity_cost_lifetime, 'data.electricity_cost_lifetime')));
              $('.trees-planted').find('span').html(data.trees_planted);

              // Monthly results
              if (monthly) {
                $('.monthly-upfront-cost').html(accounting.formatMoney(data.monthly.upfront_cost));
                $('.monthly-monthly-payment').html(accounting.formatMoney(data.monthly.monthly_pmt));
                $('.monthly-lifetime-savings').html(accounting.formatMoney(roundUp(data.monthly.lifetime_savings, 'data.monthly.lifetime_savings')));
              }

              // Advantage results
              if (advantage) {
                $('.advantage-upfront-cost').html(accounting.formatMoney(data.advantage.upfront_cost));
                $('.advantage-monthly-payment').html(accounting.formatMoney(data.advantage.monthly_pmt));
                $('.advantage-lifetime-savings').html(accounting.formatMoney(roundUp(data.advantage.lifetime_savings, 'data.advantage.lifetime_savings')));
              }

              // Prepaid results
              if (prepaid) {
                $('.prepaid-upfront-cost').html(accounting.formatMoney(data.prepaid.upfront_cost));
                $('.prepaid-monthly-payment').html(accounting.formatMoney(data.prepaid.monthly_pmt));
                $('.prepaid-lifetime-savings').html(accounting.formatMoney(roundUp(data.prepaid.lifetime_savings, 'data.prepaid.lifetime_savings')));
              }

              // Cash results
              if (buy) {
                $('.cash-upfront-cost').html(accounting.formatMoney(data.buy.upfront_cost));
                $('.cash-monthly-payment').html(accounting.formatMoney(data.buy.monthly_pmt));
                $('.cash-lifetime-savings').html(accounting.formatMoney(roundUp(data.buy.lifetime_savings, "data.buy.lifetime_savings")));
              }
              $('.blur-overlay').fadeOut(500);
              setTimeout(function() {
                $('.blur-overlay').addClass('receded');
                $('.obscurable').removeClass('obscured');
              }, 500);
            },
            error: function (xhr) {
              window.location.replace(Drupal.settings.sunrun_calculator.error_redirect_url);
            },
            failure: function (data) {
              window.location.replace(Drupal.settings.sunrun_calculator.error_redirect_url);
            }
          });
        }

        if (addressPresent === true) {
          getMap();
        }

        function roundUp(data, dataName) {
          // console.log(dataName);
          // console.log(data);
          return Math.round(data/100)*100;
        }

        function makeid(x) {
          var text = "";
          var possible = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

          for (var i = 0; i < x; i++)
            text += possible.charAt(Math.floor(Math.random() * possible.length));

          return text;
        }

      });
    }
  }
})(jQuery);
