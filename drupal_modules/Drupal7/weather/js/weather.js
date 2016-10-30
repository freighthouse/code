(function ($) {
    Drupal.behaviors.weatherBlock = {
        attach: function (context) {
            $(".block-weather").delay(10000).fadeOut(500);
        }
    };
})(jQuery);
