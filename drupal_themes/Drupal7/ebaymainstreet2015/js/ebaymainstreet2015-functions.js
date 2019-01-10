(function ($) { Drupal.behaviors.ebaymainstreet = { attach: function (context, settings) {
// Start Drupal Behaviors

  // Homepage hero silder
  // $('.homepage-hero-slider').flexslider({
  //   selector: ".field-item",
  //   animation: "fade",
  //   slideshow: true,
  //   slideshowSpeed: 5000,
  //   animationSpeed: 800,
  //   controlNav: false,
  //   directionNav: false,
  //   pauseOnAction: false,
  //   pauseOnHover: false,
  // });

  // Handle the spinner
  $('.campaign-button button').ladda('bind', { timeout: 10000 });

  // Start the timeline
  if ($('body').hasClass('node-type-timeline') || $('body').hasClass('node-type-issue')) {

    // Get NID
    var nodeid = $('#timeline-embed').data('nid');

    if ($('.issue-page-field-types-timeline').length || $('body').hasClass('node-type-timeline')) {
      createStoryJS({
        type:       'timeline',
        width:      '100%',
        height:     '500',
        css:        '/sites/all/themes/ebaymainstreet2015/stylesheets/timeline.css',
        js:         '/sites/all/themes/ebaymainstreet2015/js/vendor/timeline-min.js',
        source:     '/timelines/' + nodeid + '/timeline.jsonp',
        embed_id:   'timeline-embed'
      });
    }
  }

  //Match Height

   $('.view-microsite-testimonials .view-content').matchHeight();

  // Handle the issues menu display
  $('body').on('hover', '.header-main-menu .main-menu-issues-link', function(event) {

    if ($(window).width() >= 768){
      $('.header-megamenu .issues-menu').removeClass('hidden');
      $('.header-megamenu .our-community-menu').addClass('hidden');
      $('.header-megamenu .about-us-menu').addClass('hidden');
      $('.header-megamenu .action-center-menu').addClass('hidden');

      // Remove and add the selected styling
      $('.header-main-menu .main-menu-issues-link').addClass('selected');
      $('.header-main-menu .main-menu-our-community-link').removeClass('selected');
      $('.header-main-menu .main-menu-about-us-link').removeClass('selected');
      $('.header-main-menu .main-menu-action-center-link').removeClass('selected');
    }

  });

  // Handle the our community menu display
  $('body').on('hover', '.header-main-menu .main-menu-our-community-link', function(event) {

    if ($(window).width() >= 768) {
      $('.header-megamenu .issues-menu').addClass('hidden');
      $('.header-megamenu .our-community-menu').removeClass('hidden');
      $('.header-megamenu .about-us-menu').addClass('hidden');
      $('.header-megamenu .action-center-menu').addClass('hidden');
      // Remove the selected styling
      $('.header-main-menu .main-menu-issues-link').removeClass('selected');
      $('.header-main-menu .main-menu-our-community-link').addClass('selected');
      $('.header-main-menu .main-menu-about-us-link').removeClass('selected');
      $('.header-main-menu .main-menu-action-center-link').removeClass('selected');
    }

  });

  // Handle the about us menu display
  $('body').on('hover', '.header-main-menu .main-menu-about-us-link', function(event) {

    if ($(window).width() >= 768) {
      $('.header-megamenu .issues-menu').addClass('hidden');
      $('.header-megamenu .our-community-menu').addClass('hidden');
      $('.header-megamenu .about-us-menu').removeClass('hidden');
      $('.header-megamenu .action-center-menu').addClass('hidden');
      // Remove the selected styling
      $('.header-main-menu .main-menu-issues-link').removeClass('selected');
      $('.header-main-menu .main-menu-our-community-link').removeClass('selected');
      $('.header-main-menu .main-menu-about-us-link').addClass('selected');
      $('.header-main-menu .main-menu-action-center-link').removeClass('selected');
    }

  });

  // Handle the action-center menu display
  $('body').on('hover', '.header-main-menu .main-menu-action-center-link', function(event) {

    if ($(window).width() >= 768) {
      $('.header-megamenu .issues-menu').addClass('hidden');
      $('.header-megamenu .our-community-menu').addClass('hidden');
      $('.header-megamenu .about-us-menu').addClass('hidden');
      $('.header-megamenu .action-center-menu').removeClass('hidden');
      // Remove the selected styling
      $('.header-main-menu .main-menu-issues-link').removeClass('selected');
      $('.header-main-menu .main-menu-our-community-link').removeClass('selected');
      $('.header-main-menu .main-menu-about-us-link').removeClass('selected');
      $('.header-main-menu .main-menu-action-center-link').addClass('selected');
    }

  });

  // Handle the megamenu hide
  $('body').on('mouseleave', '.header-megamenu', function(event) {
    // Close the menu when we leave the container
    $('.header-megamenu .issues-menu').addClass('hidden');
    $('.header-megamenu .our-community-menu').addClass('hidden');
    $('.header-megamenu .about-us-menu').addClass('hidden');
    $('.header-megamenu .action-center-menu').addClass('hidden');
    // Remove the selected styling
    $('.header-main-menu .main-menu-issues-link').removeClass('selected');
    $('.header-main-menu .main-menu-our-community-link').removeClass('selected');
    $('.header-main-menu .main-menu-about-us-link').removeClass('selected');
    $('.header-main-menu .main-menu-action-center-link').removeClass('selected');
  });

  // By default, hide the mobile menu
  $('.header-main-menu').addClass('hidden');
  // Handle the menu click or focus option
  $('body').on('click focus', '.mobile-menu-link', function(event) {

    var $this = $(this);
    var now = +new Date();
    var lastClicked = $this.data('lastClicked');
    if (lastClicked && (now - lastClicked) < 100) {
      // Don't do anything
      return;
    }
    $this.data('lastClicked', now);

    $('.header-main-menu').toggleClass('hidden');
  });

  $('body').on('click', '.mobile-menu-link', function(event) {
    // Prevent the button click from working
    event.preventDefault();
  });

  $('body').on('click', '.pac-accordion-button', function(event) {
    $('.accordion-wrapper').toggleClass('open');
    $(this).toggleClass('open');
    // Prevent the button click from working
    event.preventDefault();
  });

  $('.pac-contribute-accordion-button').addClass('open');
  $('.pac-contribute-accordion-wrapper').addClass('open');
  $('body').on('click', '.pac-contribute-accordion-button', function(event) {
    $('.pac-contribute-accordion-wrapper').toggleClass('open');
    $(this).toggleClass('open');
    // Prevent the button click from working
    event.preventDefault();
  });

  $('body').on('click', '.pac-ambassador-accordion-button', function(event) {
    $('.pac-ambassador-accordion-wrapper').toggleClass('open');
    $(this).toggleClass('open');
    // Prevent the button click from working
    event.preventDefault();
  });

  $('body').on('click', '.charities.accordian li h3 a', function(event) {
    $(this).parent().siblings('.charity-info').toggleClass('open');
    $(this).parent().toggleClass('open');
    // Prevent the button click from working
    event.preventDefault();
    return false;
  });

  $('body').on('click', '.sban-faq .question', function(event) {
    $(this).next('.answer').toggleClass('open');
    $(this).toggleClass('open');
    // Prevent the button click from working
    event.preventDefault();
  });

  // This function creates a new cookie
  function setCookie(cookieName, cookieValue, cookieExpires) {
    var d = new Date();
    d.setTime(d.getTime() + (cookieExpires * 24 * 60 * 60 * 1000));
    var expires = 'expires=' + d.toUTCString();
    document.cookie = cookieName + '=' + cookieValue + '; ' + expires;
  }

  function deleteCookie(name) {
    document.cookie = name + '=;expires=Thu, 01 Jan 1970 00:00:01 GMT;';
  };

  // This function gets a cookie
  function getCookie(cookieName) {
    var name = cookieName + '=';
    var ca = document.cookie.split(';');
    for (var i=0; i < ca.length; i++) {
        var c = ca[i];
        while (c.charAt(0) === ' ') {
          c = c.substring(1);
        }
        if (c.indexOf(name) === 0) {
          return c.substring(name.length, c.length);
        }
    }
    return '';
  }

  // This function checks to see if our cookie exists
  function checkCookie(cookieName) {
    var cookieExists = 0;
    var cname = getCookie(cookieName);
    if (cname !== '') {
      cookieExists = 1;
    } else {
      cookieExists = 0;
    }
    return cookieExists;
  }

  //
  // Popup Cookie
  //
  // TODO: We need a dynamic cookie name that comes off of the block somehow cookiename-popup20 or something as a class name
  var cookieStatus = checkCookie('popup-20');

  // DISABLE THE POPUP FOR NOW
  var cookieStatus = 1;
  // DISABLE THE POPUP FOR NOW


  // If the cookie exists, handle our popup
  if (cookieStatus === 0 && $('body').hasClass('front')) {
    // Display the popup
    $('.popup').toggleClass('open');

    // Get height of popup area
    var popupHeight = $('.popup').height();
    // Set body height equal to popup height and prevent overflow
    $('html, body').css({'overflow': 'hidden'});

    //tracking when there is a scroll through a touchmove event and storing the height scrolled from top
    $('body').on('touchmove', '.popup', function(event) {

      //height scrolled from top
      var heightTop = $(this).scrollTop();

      // Add an adjustment to make sure the area is tall enough
      var heightAadjustment = 100;

      // finds height of the popup
      var popupHeightMobile = $('.popup-wrapper').height() + heightAadjustment + heightTop;

      // finds height of the popup minus the height that has been scrolled and limits the window size
      $('html, body').css({
        'height': popupHeightMobile,
        'overflow': 'hidden'
      });

      $('.main').css({
        'display': 'none',
      });

      // Set height of popup
      $('.popup').css({
        'height': popupHeightMobile,
      });

    });

    // Handle the close button click
    $('body').on('click', '.popup-close', function(event) {
      // Close the popup
      $('.popup').toggleClass('open');
      // Set our cookie
      setCookie('popup-20', 'viewed', 2000);
      // Remove our inline body styles
      $('body').removeAttr('style');
      $('html').removeAttr('style');
      $('.popup').removeAttr('style');
      $('.main').removeAttr('style');
      // Prevent the button click from working
      event.preventDefault();
    });
  }

  //
  // ` Cookie
  //
  // Check for the existance of our cookie
  var announcementCookieName = 'announcement-02-2017'; // Change this name when we have a new announcement
  var announcementCookieStatus = checkCookie(announcementCookieName);
  // Make sure our announcement is always marked as seen until we do our check
  $('.announcement-wrapper').addClass('seen');
  // If the cookie does not exist, handle our popup
  if (announcementCookieStatus === 0) {
    // Display the popup
    $('.announcement-wrapper').removeClass('seen');

    // Handle the close button click
    $('body').on('click', '.announcement-close', function(event) {
      // Close the popup
      $('.announcement-wrapper').addClass('seen');
      // Set our cookie
      setCookie(announcementCookieName, 'viewed', 14);
      // Prevent the button click from working
      event.preventDefault();
    });
  }

  // Search form
  $('body').on('click', '.header-search-link', function(event) {
    $('.header-search-form').toggleClass('open');
    $('.header-search-form .form-text.form-search').css('width','0');
    $('.header-search-form .form-text.form-search').animate({width:'13em'}, 1500);
    $('.header-search-form .form-text.form-search').focus();

    // If text box has content perform search
    if (($('.header-search-form .form-text.form-search').val() != '') && $('.header-search-form').hasClass('open') === false) {
      $('#search-block-form').submit();
    }
    else if ($('.header-search-form .form-text.form-search').val() === '' && $('.header-search-form').hasClass('open') === false) {
      // else move focus to body
      $('.header-search-link').blur();
    }

    // Prevent the button click from working
    event.preventDefault();
  });

  // Bipac Voting Block Interactivity
  $('.vote-accordion-wrapper').find('.vote-accordion-header a').click(function(event){
    // Toggle the item
    $(this).parents('.vote-accordion-header').toggleClass('is-expanded').next('.vote-content').toggleClass('is-visible');
    // Prevent the button click from working
    event.preventDefault();
  });

  // if ($('#block-bipac-vote-bipac-vote-block').find('.vote-data') != false) {
  //   $('#block-bipac-vote-bipac-vote-block').css('display', 'none');
  // }

  // Set the policy paper region dropdown to all on page load
  window.onbeforeunload = function () {
    currentVal = $('#edit-field-policy-region-tid-selective').val();
    localStorage.currentRegion = currentVal;
  }

  // When page is loaded, read in localStorage and set dropdown appropriately
  //  attempting to force ajax
  window.onload = function(){
    if(localStorage.getItem('currentRegion')){
      localStorageValue = localStorage.getItem('currentRegion');
      $('#edit-field-policy-region-tid-selective').val(localStorageValue);
      $('#edit-field-policy-region-tid-selective').change();
    }
  }

  // Get the height of the news container (add the 24px padding from the top of it)
  var newsheight = $('.front-blog-feature .content .view-news').height() + 24;
  // Set the max-height of the twitter container equal to our news container
  $('.front-twitter .content .view-tweets').css('max-height', newsheight + 'px');

  if ($('.view-display-id-issues_landing_page_listing .view-content').length === 1) {
    var num_issue_rows = $('.view-display-id-issues_landing_page_listing .view-content > .views-row').length;
    if (num_issue_rows % 2 == 0) {
      console.log('even');
    }
    else {
      console.log('odd');
    }

  }


$('.node-type-bipac-campaign .personal-info input').on('focus', function(){
  $(this).parent().addClass('component-active');
}).on('blur', function(e){
  if($.trim(e.target.value) === ''){
    $(this).parent().removeClass('component-active');
  }
});

//ny only validation
jQuery('body.page-node-130414 #edit-writer-state').find('option').remove().end().append('<option value="NY">New York</option>').val('NY');

  $('.node-type-countable-campaign-1 .field-name-field-button-text-video').on('click', 'a', function(e){
    Countable.openCreateVideo();
    return false;
  })


// End Drupal Behaviors
}};}(jQuery));
