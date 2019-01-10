/**
 * Tracking code
 */
(function ($) {
  Drupal.behaviors.sunrunTracking = {
    attach: function ( context, settings ) {
      $('body').once('sunrun-tracking', function(data){
        var nid = 0;

        // retrieve current id node from the body class [page-node-xxx] that gets populated
        // by Drupal automatically for node.
        var $body = $('body.page-node');

        if ($body.length) {
          var bodyClasses = $body.attr('class').split(/\s+/);
          for (i in bodyClasses) {
            var c = bodyClasses[i];
            // confirm page-node-XXX class has been found
            if (c.length > 10 && c.substring(0, 10) === "page-node-") {
              nid = parseInt(c.substring(10), 10);
              break;
            }
          }
        }

        var params = {
            // this variable is purposely spelled without the double 'r' in referer
            http_referer: document.referrer,
            query_string: window.location.search.replace("?", ""),
            request_uri: window.location.pathname + window.location.search,
            nodeid: nid
        };
        $.ajax('/track', {
              'data': JSON.stringify(params),
              'type': 'POST',
              'processData': false,
              'contentType': 'application/json'
        });
      })
    }
  }
})(jQuery);
