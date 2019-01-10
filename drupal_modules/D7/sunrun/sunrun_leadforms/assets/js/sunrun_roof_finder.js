(function ($) {
    Drupal.behaviors.sunrun_roof_finder = {
        attach: function (context, settings) {
            var mapOptions = {
                scrollwheel: false,
                navigationControl: false,
                mapTypeControl: false,
                scaleControl: false,
                draggable: false,
                disableDoubleClickZoom: true,
                zoom: 20,
                center: new google.maps.LatLng(-34.397, 150.644),
                disableDefaultUI: true,
                mapTypeId: google.maps.MapTypeId.SATELLITE
            }

            var geocoder = new google.maps.Geocoder(), crosshairs = [], offsets = [];
            geocoder.geocode({ 'address': settings.sunrun_roof_finder.address}, function(results, status){
                if (status == google.maps.GeocoderStatus.OK) {
                    $('.map-canvas').each(function(idx, val){
                        var map = new google.maps.Map($(this)[0], mapOptions);

                        // Retrieve starting location of map
                        // and use to set center; and default lat/long
                        // for form.
                        var location = results[0].geometry.location;
                        $('input[name="latitude"]').val(location.lb);
                        $('input[name="longitude"]').val(location.mb);
                        map.setCenter(location);
                    });

                }
            });
        }
    };

})(jQuery);
