Drupal.apigee = Drupal.apigee || {};

// Using the closure to map jQuery to $.
(function ($) {

Drupal.apigee.apiCreateDots = function($view, settings) {
  var dots = ['<div class="slider-dots">'];
  for (var i = 0; i < settings.slidesqty; i++) {
    dots.push('<div sindex = "' + (i + 1) + '" class="slider-dot-' + (i + 1) + '"></div>');
  }
  dots.push('</div>');
  var sliderDots = $(dots.join(''));
  $view.append(sliderDots);

  var width = 20 * settings.slidesqty;

  sliderDots.css({
    position: 'absolute',
    bottom: 0,
    // 'background-color': 'red',
    height: 20,
    width: width,
    right: (settings.carouselwidth - width) / 2
  });

  sliderDots.find('div').click(function() {

    $this = $(this);
    var index = $this.attr('sindex');

    function turn() {
      Drupal.apigee.apiPageRight($view, settings, 200);
      var currentIndex = $view.find('.slider-dots .active').attr('sindex');
      if (currentIndex != index) {
        setTimeout(turn, 200);
      }
    }
    
    var currentIndex = $view.find('.slider-dots .active').attr('sindex');

    if (currentIndex != index) {
      setTimeout(turn, 0);
    }
  });
}

Drupal.apigee.apiPageRight = function($view, settings, time) {
  $view.find('.prev-slide').removeClass('prev-slide').addClass('inactive');

  var $prev = $view.find('.active').removeClass('active').addClass('prev-slide');
  var $active = $view.find('.next-slide').removeClass('next-slide').addClass('active');

  var index = $active.index();

  if (index == 0) {
    $view.find('.views-row:last-child').insertBefore($active);
  }

  else if (index == (settings.slidesqty - 1)) {
    $view.find('.views-row:first-child').insertAfter($active);
  }

  var $next = $active.next().addClass('next-slide').removeClass('inactive');

  $prev.find('img').css('z-index', 201);

  $next.find('img').css('z-index', 200);

  Drupal.apigee.countslide($view, settings, time)
}

Drupal.apigee.countslide = function($view, settings, time) {

  $view.find('.inactive img').animate({
    left: settings.posfirst,
    height: settings.smallimageheight,
    width: settings.smallimagewidth,
    top: settings.imagepadding - 20
  }, time);

  $view.find('.prev-slide img').animate({
    left: settings.posleft,
    height: settings.smallimageheight,
    width: settings.smallimagewidth,
    top: settings.imagepadding - 20
  }, time);

  $view.find('.next-slide img').animate({
    left: settings.posright,
    height: settings.smallimageheight,
    width: settings.smallimagewidth,
    top: settings.imagepadding - 20
  }, time);

  $view.find('.active img').animate({
    left: settings.posfirst,
    height: settings.imageheight,
    width: settings.imagewidth,
    top: settings.imagetop
  }, time);

  var index = $view.find('.active').index();
  var classValues = $view.find('.active').attr('class');

  var index = /views-row-(\d+)/.exec(classValues)[1];

  var slider = $view.find('.slider-dot-' + index);
  $view.find('.slider-dots div').removeClass('active');
  slider.addClass('active');
};

Drupal.apigee.carouselClick = function($view, $rows, settings) {
  $rows.each(function () {
    var $row = $(this);

    $row.find('img').click(function () {

      if ($row.hasClass('active')) {
        $row.find('.download-btn').click();
      }
      
      else {

        var index = $row.index();

        if (index == 0) {
          $view.find('.views-row:last-child').insertBefore($row);
        }

        else if (index == (settings.slidesqty - 1)) {
          $view.find('.views-row:first-child').insertAfter($row);
        }

        if ($row.hasClass('next-slide')) {
          var zprev = 201;
          var znext = 200;
        }
        else {
          var zprev = 200;
          var znext = 201;
        }

        $rows
          .removeClass('prev-slide')
          .removeClass('next-slide')
          .removeClass('active')
          .addClass('inactive');

        $row.addClass('active').removeClass('inactive');

        $row.prev()
          .addClass('prev-slide')
          .removeClass('inactive')
          .find('img')
            .css('z-index', zprev);

        $row.next()
          .addClass('next-slide')
          .removeClass('inactive')
          .find('img')
            .css('z-index', znext);

        Drupal.apigee.countslide($view, settings, 400);
      }
    });
  });
}

Drupal.behaviors.apigeeCustpmMktgCover = {
  attach: function (context, settings) {
    var $view = $('.books-slider', context);
    var $rows = $view.find('.views-row');

    if ($rows.length > 0) {
      var settings = {};
      
      settings.slidesqty = $rows.length;

      settings.carouselwidth = $view.width();

      // The image height we get is always wrong and causes skewing. We have 
      // an image style that sets the height to 266 so this should be pretty
      // safe.
      settings.imagewidth = 200;
      settings.imageheight = 266;

      settings.smallimagewidth = parseInt(settings.imagewidth * .75);
      settings.smallimageheight = parseInt(settings.imageheight * .75);

      var overlap = parseInt(settings.imagewidth * .20);
      settings.posfirst = parseInt((settings.carouselwidth - settings.imagewidth)/2);
      var rightSideFront = parseInt((settings.carouselwidth + settings.imagewidth)/2);

      settings.posleft = settings.posfirst - settings.smallimagewidth + overlap;
      settings.posright = rightSideFront - overlap;

      settings.imagetop = 80;
      var imagespace = parseInt(settings.imageheight * 0.2);
      settings.imagepadding = settings.imagetop + imagespace;

      $rows.addClass('inactive');

      var $first = $view.find('.views-row-2');

      $first.addClass('active').removeClass('inactive');
      $first.prev().addClass('prev-slide').removeClass('inactive');
      $first.next().addClass('next-slide').removeClass('inactive');
      
      Drupal.apigee.apiCreateDots($view, settings);

      Drupal.apigee.countslide($view, settings, 0);
      Drupal.apigee.carouselClick($view, $rows, settings);
      Drupal.apigee.carouselTurns = 0;

      var turn = function() {
        Drupal.apigee.carouselTurns++;
        $view.find('.next-slide img').click();
        if (Drupal.apigee.carouselTurns < settings.slidesqty) {
          setTimeout(turn, 500);
        }
      }

      // setTimeout(turn, 500);
    }
  }
};

}(jQuery));
