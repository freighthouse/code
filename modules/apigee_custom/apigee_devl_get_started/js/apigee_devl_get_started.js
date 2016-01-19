(function ($) {
    Drupal.behaviors.getStarted = {
        attach:function (context, settings) {
            setInterval(function () {
                $.get("get-started/ajax", function (data) {
                    if (data.book_created !== false) {
                        jQuery('span.step').addClass('done');
                    }
                })
            }, 5000);
        }
    };
})(jQuery);
