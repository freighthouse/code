(function e(t,n,r){function s(o,u){if(!n[o]){if(!t[o]){var a=typeof require=="function"&&require;if(!u&&a)return a(o,!0);if(i)return i(o,!0);var f=new Error("Cannot find module '"+o+"'");throw f.code="MODULE_NOT_FOUND",f}var l=n[o]={exports:{}};t[o][0].call(l.exports,function(e){var n=t[o][1][e];return s(n?n:e)},l,l.exports,e,t,n,r)}return n[o].exports}var i=typeof require=="function"&&require;for(var o=0;o<r.length;o++)s(r[o]);return s})({1:[function(require,module,exports){
'use strict';

(function ($, Drupal) {
  Drupal.behaviors.linkedRegion = {
    attach: function attach(context, settings) {
      $('.linked-region').addClass('linked-region--js').each(function (index, item) {
        var $item = $(item);
        var link = $item.find('.linked-region--target').attr('href');

        $item.click(function (e) {
          e.preventDefault();
          window.location.href = link;
        });
      });
    }
  };

  Drupal.behaviors.headerScroll = {
    attach: function attach(context, settings) {
      $('body').each(function (index, item) {
        var $item = $(item);
        $item.addClass("notscrolled");
        var scrollPosY = window.pageYOffset | $item.scrollTop;
        if (scrollPosY > 0 && $item.hasClass("notscrolled")) {
          $item.addClass("scrolled");
          $item.removeClass("notscrolled");
        } else if (scrollPosY <= 0 && $item.hasClass("scrolled")) {
          $item.addClass("notscrolled");
          $item.removeClass("scrolled");
        }

        window.onscroll = function changeNav() {
          var scrollPosY = window.pageYOffset | $item.scrollTop;
          if (scrollPosY > 0 && $item.hasClass("notscrolled")) {
            $item.addClass("scrolled");
            $item.removeClass("notscrolled");
          } else if (scrollPosY <= 0 && $item.hasClass("scrolled")) {
            $item.addClass("notscrolled");
            $item.removeClass("scrolled");
          }
        };
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
})(jQuery, Drupal);

},{}]},{},[1]);
