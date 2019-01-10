/**
 * Tracking code
 */
(function ($) {
  Drupal.behaviors.sunrunAnalitycs = {
    attach: function ( context, settings ) {
      /**
       * Track links on main nav
       */
      $('.navbar-nav.primary').once('sunrun-analitycs', function(data){
        // Do not track last link (Get Started)
        $(this).find('li:not(.last)').find('a').on('click', function(e){
          // Check external url
          var url = $(this).attr('href');
          if (!(/^https?:\/\//i.test(url))) {
            url = window.location.origin + url;
          }
          ga('send', 'event', 'navigation', 'global header', url);
        });
        // Track last link (Get Started)
        $(this).find('li.last').find('a').on('click', function(e){
          ga('send', 'event', 'navigation', 'get started ', settings.sunrun_tracking.full_url);
        });
      });
      /**
       * Track links on secondary nav
       */
      $('.navbar-nav.secondary').once('sunrun-analitycs', function(data){
        // Contact link
        $(this).find('li.contact > a:first').on('click', function(e){
          ga('send', 'event', 'navigation', 'global header', 'contact us');
        });
        // Click to call
        $(this).find('li.phone > a:first').on('click', function(e){
          ga('send', 'event', 'navigation', 'to: tel:18554786786', 'click-to-call');
        });
        // Click to call
        $(this).find('li.login > a:first').on('click', function(e){
          ga('send', 'event', 'engagement', 'click on www.mysunrun.com link', settings.sunrun_tracking.full_url);
        });
      });
      /**
       * Track footer menu links
       */
      $('#block-menu-menu-footer-links').once('sunrun-analitycs', function(data){
        // Menu links, first level
        $(this).find('ul.menu > li > a').on('click', function(e){
          // Check external url
          var url = $(this).attr('href');
          if (!(/^https?:\/\//i.test(url))) {
            url = window.location.origin + url;
          }
          ga('send', 'event', 'navigation', 'global footer', url);
        });
        // Click to call
        $(this).find('.dropdown-menu a').on('click', function(e){
          var state = $(this).html().trim();
          ga('send', 'event', 'navigation', 'global footer', state);
        });
      });
      /**
       * Track social menu links
       */
      $('.footer-social').once('sunrun-analitycs', function(data){
        // Facebook
        $(this).find('.fa-facebook').parent().on('click', function(e){
          ga('send', 'event', 'navigation', 'go to Facebook', settings.sunrun_tracking.full_url);
        });
        // Twitter
        $(this).find('.fa-twitter').parent().on('click', function(e){
          ga('send', 'event', 'navigation', 'go to Twitter', settings.sunrun_tracking.full_url);
        });
        // Youtube
        $(this).find('.fa-youtube').parent().on('click', function(e){
          ga('send', 'event', 'navigation', 'go to Youtube', settings.sunrun_tracking.full_url);
        });
        // G++
        $(this).find('.fa-google-plus').parent().on('click', function(e){
          ga('send', 'event', 'navigation', 'go to G++', settings.sunrun_tracking.full_url);
        });
      });
      /**
       * HOME: Giant Hero 
       */
      $('body.front .pane-bean-giant-hero-block-home-hero .submit').once('sunrun-analitycs', function(data){
        $(this).on('click', function(e){
          ga('send', 'event', 'home page', 'hero', 'calculate savings');
        });
      });
      /**
       * HOME: Promo blocks home page
       */
      $('body.front .view-id-promo_blocks a').once('sunrun-analitycs', function(data){
        $(this).on('click', function(e){
          ga('send', 'event', 'home page', $(this).find('span.title').html().trim(), $(this).attr('href'));
        });
      });
      /**
       * HOME: Plans and services 
       */
      $('body.front .pane-bean-content-block-products-backgro .nav-tabs').once('sunrun-analitycs', function(data){
        $(this).find('a').on('click', function(e){
          ga('send', 'event', 'home page', 'product selection', $(this).attr('title'));
        });
      });
      $('body.front .pane-bean-content-block-products-backgro .tab-pane').once('sunrun-analitycs', function(data){
        $(this).find('a').on('click', function(e){
          ga('send', 'event', 'home page', 'product detail', $(this).attr('href'));
        });
      });

      /**
       * CONTACT: Click to call
       */
      $('a.ctc-phone').once('sunrun-analitycs', function(data){
        $(this).on('click', function(e){
          ga('send', 'event', 'contact', 'to: tel:18554786786', 'click-to-call');
        });
      });
      /**
       * CONTACT: Email
       */
      $('a.ctc-email').once('sunrun-analitycs', function(data){
        $(this).on('click', function(e){
          ga('send', 'event', 'mailto', $(this).attr('href'), settings.sunrun_tracking.full_url);
        });
      });
      /**
       * CONTACT: Navigation
       */
      $('a.ctc-navigation').once('sunrun-analitycs', function(data){
        $(this).on('click', function(e){
          ga('send', 'event', 'navigation', 'contact', $(this).attr('href'));
        });
      });
      /**
       * CONTACT: Account
       */
      $('a.ctc-account').once('sunrun-analitycs', function(data){
        $(this).on('click', function(e){
          ga('send', 'event', 'engagement', 'click on www.mysunrun.com link', settings.sunrun_tracking.full_url);
        });
      });
      /**
       * ALL: External links
       */
      $('a[href^="http"]:not([href*="' + window.location.host  + '"])').once('sunrun-external', function(data){
        $(this).on('click', function(e){
          ga('send', 'event', 'navigation', settings.sunrun_tracking.full_url, 'to ' + $(this).attr('href'));
        });
      });
    }
  }

  /**
   * Google Analitycs custom command.
   */
  Drupal.ajax.prototype.commands.sunrun_ga = function(ajax, response, status) {
    if(response.nonInteraction){
      ga('send', 'event', response.category, response.action, response.label, response.value, {nonInteraction: 1});
    } else {
      ga('send', 'event', response.category, response.action, response.label, response.value);
    }
  }
})(jQuery);
