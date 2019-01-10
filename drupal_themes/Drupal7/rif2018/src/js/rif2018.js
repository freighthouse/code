(function ($, Drupal) {
  Drupal.behaviors.linkedRegion = {
    attach: function (context, settings) {
      $('.linked-region')
        .addClass('linked-region--js')
        .each(function(index, item) {
          const $item = $(item);
          const link = $item.find('.linked-region--target').attr('href');

          $item.click(function(e) {
            e.preventDefault();
            window.location.href = link;
          });
        });
    }
  };

  Drupal.behaviors.headerScroll = {
    attach: function (context, settings) {
      $('body')
        .each(function(index, item) {
          const $item = $(item);
          $item.addClass("notscrolled");
          var scrollPosY = window.pageYOffset | $item.scrollTop;
          if(scrollPosY > 0 && $item.hasClass("notscrolled")) {
            $item.addClass("scrolled");
            $item.removeClass("notscrolled");
          } else if(scrollPosY <= 0 && $item.hasClass("scrolled")) {
            $item.addClass("notscrolled");
            $item.removeClass("scrolled");
          }
          
          window.onscroll = function changeNav(){
            var scrollPosY = window.pageYOffset | $item.scrollTop;
            if(scrollPosY > 0 && $item.hasClass("notscrolled")) {
              $item.addClass("scrolled");
              $item.removeClass("notscrolled");
            } else if(scrollPosY <= 0 && $item.hasClass("scrolled")) {
              $item.addClass("notscrolled");
              $item.removeClass("scrolled");
            }
          }
        });
    }
  };

  Drupal.behaviors.linkedRegion = {
    attach: function attach() {
      $('.resource-group-link').matchHeight();
      $('.get-involved-text-box').matchHeight();
    }
  };

  // Drupal.behaviors.waypoints = {
  //   attach: function attach() {
  //     var waypoint = new Waypoint({
  //       element: document.getElementById('basic-waypoint'),
  //       handler: function() {
  //         notify('Basic waypoint triggered')
  //       }
  //     })
  //   }
  // };

}(jQuery, Drupal));

