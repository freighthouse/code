(function ($) {
  Drupal.behaviors.sunrunRanges = {
    attach: function (context, settings) {
      //Example.
      var SRPurlsThresholds = [0, 0, 150, 200];
      //start rating
      var electricBillMax = 350;
      $('.single-slider').jRange({
        from: 0,
        to: electricBillMax,
        step: 1,
        scale: [0, 175, 350],
        format: '%s',
        width: '100%',
        showLabels: true,
        onstatechange: function () {
          validateAndSetElectricBill(this.options.value);
        },
      });
      /* Validate bill input, setting it to an acceptable
       minimum or maximum if it goes out of range. */
      function validateAndSetElectricBill(currBill) {
        currBill = isNaN(currBill) ? 0 :
          (currBill >= electricBillMax) ? electricBillMax :
            (currBill < 0) ? 0 : currBill;

        $('#srPurlsAverageElectricBill').val(currBill);

        // Update the selected state for every star after the first.

        var starRating = 1;
        if (currBill != 0) {
          for (var i = 0; i < SRPurlsThresholds.length; i++) {
            if (parseInt(currBill) >= parseInt(SRPurlsThresholds[i])) {
              starRating++;
              //console.log(SR_Purls.starRating);
            }
          }
        } else {
          starRating = 0;
        }

        if (starRating <= 3) {
          $(".page-header").text(Drupal.settings.sunrunRanges.threeStarsHeadline);
          $("#afterBillAverageText").text(Drupal.settings.sunrunRanges.threeStarsBody);
        } else {
          $(".page-header").text(Drupal.settings.sunrunRanges.fourStarsHeadline);
          $("#afterBillAverageText").text(Drupal.settings.sunrunRanges.fourStarsBody);
        }

        //$('#solar-rating').attr('src', '/sites/default/modules/custom/sunrun_leadforms/assets/images/' + starRating + '-star.png');
        $('#srPurlsSolarStarRating span').attr('class', 'stars rating' + starRating);
      }
    }
  };

})(jQuery);
