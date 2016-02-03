// Using the closure to map jQuery to $.
(function ($) {

    Drupal.behaviors.apigeeCustpmMktgPricing = {
        attach: function (context, settings) {
            $('.collapsible', context).click(
                function () {
                    $(this).toggleClass('collapsed');
                }
            );
        }
    };

}(jQuery));


