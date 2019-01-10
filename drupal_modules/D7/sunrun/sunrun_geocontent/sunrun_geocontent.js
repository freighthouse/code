/**
 * General geo location code
 */
(function ($) {
  /**
   * Get location from smart_ip module
   */
  Drupal.behaviors.sunrunGeo = {
    attach: function ( context, settings ) {
      // Get from cookie
      if(typeof $.cookie === 'function'){
        var geolocation = $.cookie('geolocation');
        if(!geolocation){
          $.ajax({
            url: window.location.protocol + '//api.ipinfodb.com/v3/ip-city',
            jsonp: 'callback',
            jsonpCallback: 'infodbcallback',
            dataType: 'jsonp',
            data: {
                key : settings.sunrun_geocontent.infodb_key,
                format: 'json',
            },
            // Save results in cookie
            success: function(response) {
              if(response.statusCode == 'OK'){
                $.cookie('geolocation', JSON.stringify(response));
                // Set state
                setState(response);
              }
            }
          });
        } else {
          geolocation = JSON.parse(geolocation);
          // Set state
          setState(geolocation);
        }
      }
    }
  }
  // Set <state> tag
  function setState(geolocation) {
    $('state').once('sunrun-geo', function(){
      // Avoid undefined
      if('regionName' in geolocation){
        $(this).html(geolocation.regionName);
      }
    });
  }
})(jQuery);