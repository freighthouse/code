(function ($) {
  Drupal.behaviors.sunrun_click_to_call = {
    attach: function (context, settings) {
      var $clickToCallBtn = $('.click-to-call');
      var $submit = $('.click-to-call-form input[type=submit]');

      var form = '<div class="click-to-call-form">' +
        '<form action="//www.sunruntransit.com/track/lead" autocomplete="on" zeus-quote-form" id="zeus-quote-form" method="post">' +
        // '<input type="hidden" name="oid" value="' + settings.sunrun_click_to_call.oid + '">' +
        '<input type="hidden" name="retURL" value="' + settings.sunrun_click_to_call.return_url + '">' +
        //'<input type="hidden" name="debug" value=1>' +

        '<div class="form-row">' +
          '<label for="first_name">First Name</label>' +
          '<input id="first_name" maxlength="40" name="first_name" size="20" type="text" placeholder="First Name" required=true/>' +
        '</div>' +

        '<div class="form-row">' +
          '<label for="last_name">Last Name</label>' +
          '<input id="last_name" maxlength="80" name="last_name" size="20" type="text" placeholder="Last Name" required=true/>' +
        '</div>' +

        '<div class="form-row">' +
          '<label for="phone">Phone</label>' +
          '<input id="phone" maxlength="40" name="phone" size="20" type="text" placeholder="(555) 555-5555" required=true/>' +
        '</div>' +

        '<div class="form-row">' +
          '<label for="zip">Zip Code</label>' +
          '<input id="zip" maxlength="5" name="zip" size="20" type="text" placeholder="99999" required=true pattern = "[[0-9]{1,5}" /> ' +
        '</div>' +

        '<div class="hidden">' +
          // campid
          '<input id="campid" type="hidden" name="campid" value="">' +
          // default_campid
          '<input type="hidden" id="default_campid" name="default_campid" value="283B89FE5A3FC6F9">' +

          // Keywords Last
          '<input type="hidden" id="Keywords_Last__c" name="Keywords_Last__c" value="">' +
          // Technology
          '<input type="hidden" id="technology" name="technology" value="Sunrun.com Click-to-Call" />' +
        '</div>' +

        '<input type="submit" name="submit" value="' + settings.sunrun_click_to_call.button_text + '" class="btn-cta btn">' +
        '</form>' +
        '<p class="form-autodialer-opt-in pageid-tcpa">' + settings.sunrun_click_to_call.tcpa_disclosure+ '</p>' +
        '</div>';

      if(typeof($clickToCallBtn.popover) !== 'undefined') {
        $clickToCallBtn.popover({
          html: true,
          content: form,
          placement: 'right'
        }).parent().delegate('input[type=submit]', 'click', function() {
          submitValues();
        });
      }

      $submit.on('click', function() {
        submitValues();
      });

      function submitValues() {
        // campid
        if($.cookie('campid')) {
          $('#campid').val($.cookie('campid'));
        }        
        // Keywords
        if($.cookie('sr_tr[kw]')) {
          $('#Keywords_Last__c').val($.cookie('sr_tr[kw]'));
        }
      }
    }
  };

})(jQuery);
