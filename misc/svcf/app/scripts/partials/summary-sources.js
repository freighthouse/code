SVCF.SummarySources = function () {
    'use strict';
    var Elements = {
      $el: undefined,
      $summaries: undefined,
      $summaryAttribution: undefined,
      $summarySourcesContainer: undefined,
      $summaryContainers: undefined,
      $prevButton: undefined,
      $nextButton: undefined
    };
    var Module = {
      _hidden: false,
      _height: 225,
      _scrolling: false,
    initialize: function(settings) {
      this.settings = settings;
      Elements.$el = this.settings.$el;
      Elements.$summaryAttribution = $('.summary-attribution');
      Elements.$summarySourcesContainer = Elements.$el.find('.summary-sources-container');
      Elements.$summaries = Elements.$el.find('.summary-source');
      Elements.$summaryContainers = Elements.$el.find('.summary-source-container');
      this.addEvents();
    },
    addEvents: function() {
      var self = this;
      imagesLoaded(Elements.$el, function() {
        self.setDefaults();
        self.removeSlick().addSlick();
        self.eqWidthHeight();
        self.hide();
        Elements.$el.trigger('SUMMARY:SOURCES:READY');
      });
      Elements.$summarySourcesContainer.on('afterChange', function(e) {
        if($(e.currentTarget).find('.slick-active').last().index() === (Elements.$summaryContainers.length - 1)) {
          Elements.$el.find('.summary-sources-container button.slick-prev').show();
          Elements.$el.find('.summary-sources-container button.slick-next').hide();
        }else if($(e.currentTarget).find('.slick-active').first().index() === 0) {
          Elements.$el.find('.summary-sources-container button.slick-next').show();
          Elements.$el.find('.summary-sources-container button.slick-prev').hide();
        }else {
          Elements.$el.find('.summary-sources-container button.slick-prev').show();
          Elements.$el.find('.summary-sources-container button.slick-next').show();
        }
      });
      var resizeTimer;
      $(window).on('resize', function(e) {
        clearTimeout(resizeTimer);
        resizeTimer = setTimeout(function() {
          self.eqWidthHeight(true);
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
    eqWidthHeight: function(force) {
      if(!this.isScrolling() || force) {
        var width = 0;
        var height = 0;
        Elements.$summaryContainers.each(function(ind, obj) {
          var $summaryContainer = $(obj);
          if($summaryContainer.width() > width) {
            width = $summaryContainer.width();
          }
        });

        Elements.$summaryContainers.height(width);

        var summaryContainerHeight = Elements.$summaries.eq(0).innerHeight();
        var parentContainerHeight = summaryContainerHeight + Elements.$summaryAttribution.innerHeight();
        this._height = parentContainerHeight + 25;
        if($('#background-map-svg').height() > 333) {
          Elements.$el.css({
            marginTop: 333
          });
        }else {
          Elements.$el.css({
            marginTop: $('#background-map-svg').height()
          });
        }
        $('[aria-label="Previous"]').html('');
        $('[aria-label="Next"]').html('');
        // Elements.$el.trigger('SVCF:SECTION:HEIGHT');
        return this;
      }
    },
    removeSlick: function() {
      try {
        Elements.$summarySourcesContainer.slick('unslick');
      }catch (err) {}
      return this;
    },
    addSlick: function() {
      var self = this;
      Elements.$summarySourcesContainer.slick({
        dots: false,
        arrows: true,
        speed: 300,
        focusOnSelect: false,
        infinite: false,
        slidesToShow: 5,
        slidesToScroll: 1,
        responsive: [
          {
            breakpoint: 480,
            settings: {
              slidesToShow: 2,
              slidesToScroll: 1
            }
          },
          {
            breakpoint: 640,
            settings: {
              slidesToShow: 3,
              slidesToScroll: 1
            }
          },
          {
            breakpoint: 768,
            settings: {
              slidesToShow: 4,
              slidesToScroll: 1
            }
          },
          {
            breakpoint: 992,
            settings: {
              slidesToShow: 5,
              slidesToScroll: 1
            }
          },
          {
            breakpoint: 1200,
            settings: {
              slidesToShow: 5,
              slidesToScroll: 1
            }
          }
        ]
      });
      $('[aria-label="Previous"]').html('');
      $('[aria-label="Next"]').html('');
      Elements.$el.find('.summary-sources-container button.slick-prev').hide();
    },
    show: function() {
      var self = this;
      if(this.isHidden() === true) {
        this.isHidden(false);
        self.eqWidthHeight();
        new TweenMax.to(Elements.$el, 0.67,
        {
          opacity: 1,
          height: self._height,
          overflow: 'hidden',
          onUpdate: function() {
            Elements.$el.trigger('SVCF:SECTION:HEIGHT');
          }
        });
        new TweenMax.staggerFromTo(Elements.$summaries.toArray(), 0.67, {
          scale: 0,
          opacity: 0
        },
        {
          delay: 0.33,
          scale: 0.93,
          opacity: 1,
          ease: Elastic.easeInOut
        }, 0.17);
      }
      return this;
    },
    hide: function() {
      var self = this;
      new TweenMax.to(Elements.$el, 0.67, {
        opacity: 0,
        height: 0,
        overflow: 'hidden',
        onUpdate: function() {
          Elements.$el.trigger('SVCF:SECTION:HEIGHT');
        }
      });
      new TweenMax.staggerTo(Elements.$summaries.toArray(), 0.67, {
        scale: 0,
        opacity: 0,
        ease: Elastic.easeInOut
      }, 0.17);
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
      new TweenLite.set(Elements.$el.find('.summary-source-container'), {
        boxShadow: '0px 0px 5px ' + Constants.colors['$dark' + this.settings.color].replace(')', ', 0.41)'),
        backgroundColor: Constants.colors['$dark' + this.settings.color],
        borderColor: Constants.colors['$light' + this.settings.color]
      });
      new TweenLite.set(Elements.$summarySourcesContainer, {
        color: 'white'
      });
    }
  };
  return Module;
};
