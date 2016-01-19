SVCF.SummaryBody = function () {
    'use strict';
    var Elements = {
      $el: undefined,
      $summaryBody: undefined,
      $summaryBodyContainer: undefined,
      $summaryBodyImage: undefined,
      $summaryBodyText: undefined,
      $summaryBodyTextContainer: undefined
    };
  var Module = {
    _height: 145,
    _hidden: false,
    _scrolling: false,
        initialize: function(settings) {
          this.settings = settings;
          Elements.$el = this.settings.$el;
          Elements.$summaryBodyContainer = Elements.$el.find('.summary-body-container');
          Elements.$summaryBody = Elements.$el.find('.summary-body');
          Elements.$summaryBodyImage = Elements.$el.find('.summary-body-image');
          Elements.$summaryBodyText = Elements.$el.find('.summary-body-text');
          Elements.$summaryBodyTextContainer = Elements.$el.find('.summary-body-text-container');
          this.addEvents();
        },
    addEvents: function() {
      var self = this;
      imagesLoaded(Elements.$el, function() {
        self.setDefaults();
        self.addSlick();
        self.eqContent();
        self.hide();
        Elements.$el.trigger('SUMMARY:BODIES:READY');
      });
      var resizeTimer;
      $(window).on('resize', function(e) {
        clearTimeout(resizeTimer);
        resizeTimer = setTimeout(function() {
          self.eqContent(true);
        }, 300);
      });
      var scrollTimer;
      $(window).on('scroll', function(e) {
        clearTimeout(scrollTimer);
        self.isScrolling(true);
        scrollTimer = setTimeout(function() {
          self.isScrolling(false);
        }, 300);
      });
      return this;
    },
    eqContent: function(force) {
      if(!this.isScrolling() || force) {
        var width = 0;
        var height = 0;
        Elements.$summaryBodyText.each(function(ind, obj) {
          var $summaryBodyText = $(obj);
          if($summaryBodyText.height() > height) {
            height = $summaryBodyText.height();
          }
        });
        Elements.$summaryBodyImage.each(function(ind, obj) {
          var $summaryBodyImage = $(obj);
          if($summaryBodyImage.height() > height) {
            height = $summaryBodyImage.height();
          }
        });
        this._height = height;
        Elements.$el.height(height);
        Elements.$summaryBody.height(height);
        Elements.$el.find('[aria-label="Previous"]').html('');
        Elements.$el.find('[aria-label="Next"]').html('');
        // Elements.$el.trigger('SVCF:SECTION:HEIGHT');
        return this;
      }
    },
    addSlick: function() {
      var self = this;
      Elements.$summaryBodyContainer.slick({
        dots: false,
        arrows: true,
        speed: 300,
        autoplay: true,
        autoplaySpeed: 5000,
        slidesToShow: 3,
        slidesToScroll: 1,
        variableWidth: false,
        responsive: [
          {
            breakpoint: 480,
            settings: {
              slidesToShow: 1,
              slidesToScroll: 1
            }
          },
          {
            breakpoint: 640,
            settings: {
              centerMode: true,
              centerPadding: '60px',
              slidesToShow: 1,
              slidesToScroll: 1
            }
          },
          {
            breakpoint: 768,
            settings: {
              slidesToShow: 2,
              slidesToScroll: 1
            }
          },
          {
            breakpoint: 992,
            settings: {
              centerMode: true,
              centerPadding: '30px',
              slidesToShow: 2,
              slidesToScroll: 1
            }
          },
          {
            breakpoint: 1024,
            settings: {
              slidesToShow: 3,
              slidesToScroll: 1
            }
          }
        ]
      });
      Elements.$summaryBodyContainer.on('reInit', function(e) {});
      return this;
    },
    show: function() {
      var self = this;
      if(this.isHidden() === true) {
        this.isHidden(false);
        this.eqContent();
        new TweenMax.fromTo(Elements.$el, 1, {
          opacity: 0,
          height: 0,
          onUpdate: function() {
            Elements.$el.trigger('SVCF:SECTION:HEIGHT');
          }
        },
        {
          opacity: 1,
          height: self._height
        });
      }
      return this;
    },
    hide: function() {
      var self = this;
      new TweenMax.fromTo(Elements.$el, 1, {
        opacity: 1,
        height: self._height,
        onUpdate: function() {
          Elements.$el.trigger('SVCF:SECTION:HEIGHT');
        }
      },
      {
        opacity: 0,
        height: 0
      });
      this.isHidden(true);
      return this;
    },
    isHidden: function(val) {
      if(val === true || val === false)  {
        this._hidden = val;
      }
      return this._hidden;
    },

    isScrolling: function(val) {
      if(val && this._scrolling !== val) {
        this._scrolling = val;
      }
      return this._scrolling;
    },
    setDefaults: function() {
      var self = this;
      new TweenLite.set(Elements.$el, {
        backgroundColor: Constants.colors['$light' + self.settings.color]
      });
      new TweenLite.set(Elements.$summaryBodyContainer, {
        color: Constants.colors['$dark' + self.settings.color]
      });
      new TweenLite.set(Elements.$summaryBody, {
        backgroundColor: Constants.colors['$light' + self.settings.color],
        color: Constants.colors['$dark' + self.settings.color]
      });
      new TweenMax.set(Elements.$el, {
        overflow: 'hidden',
        height: 0
      });
    }
  };
  return Module;
};
