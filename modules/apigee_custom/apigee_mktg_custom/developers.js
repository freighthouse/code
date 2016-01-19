// Using the closure to map jQuery to $.
(function ($) {

Drupal.behaviors.apigeeCustomDevelopers = {
  attach: function (context, settings) {
    var $link = $('.field-name-field-panel-text a.btn', context);
    var xml = '';
    $link.click(function () {
      if ($(this).hasClass('current')) {}
        else {
      $(this).addClass('current btn');
      if ($('.field-name-field-panel-text textarea').length) {
        return false;
      }
      $.ajax({
        url: 'http://demo-prod.apigee.net/weather/forecastrss?w=2502265',
        global: false,
        dataType: 'text',
        success: function(thing) {
        	xml = $('<pre class="left prettyprint linenums pre-scrollable"></pre>');
          xml.text(thing);
          $link.after(xml);
        },
        complete: function() {
          $.ajax({
            url: 'http://demo-prod.apigee.net/weather/forecasts/2502265.json',
            global: false,
            dataType: 'text',
            success: function(json) {
            	var markup2 = $('<pre class="right prettyprint linenums pre-scrollable"></pre>');
              markup2.text(json);
              xml.after(markup2);
              var links = '<a class="bottom-link-1 btn btn-large" href="/about/sign-up">Sign Up <span class="white-arrow"></span></a><a class="bottom-link-2 btn btn-large" href="/about/developer-capabilities">See capabilities <span class="white-arrow"></span></a>';
              markup2.after(links);
              $('.panel-pane.pane-node-body').addClass('clearfix');
              prettyPrint();
            }
          });
        }
      });

      return false;
    }
    });
  }
};

}(jQuery));
