SVCF.Section = function() {
  'use strict';
  var Elements = {
    $el: {},
    $backgroundMap: {},
    $summary: {},
    $summaryStatement: {},
    $summaryStatementLabel: {},
    $summaryStatementValue: {},
    $summaryStatementDescription: {},
    $summaryAttribution: {},
    $summarySources: {},
    $summarySourcesButtons: {},
    $summarySource: {},
    $body: {},
    $summaryBodies: {},
    $buttonFoldDownChevron: {}
  };
  var Module = {
    animation: {},
    summaryBodyReady: false,
    summarySourcesReady: false,
    backgroundMapReady: false,
    summaryBody: {},
    summarySources: {},
    backgroundMap: {},
    _scrolling: false,
    initialize: function(settings) {
      this.settings = settings;
      Elements.$el = $('#svcf-datavis section.' + this.settings.className);
      Elements.$summary = Elements.$el.find('.summary');
      Elements.$summaryStatement = Elements.$el.find('.summary .summary-statement');
      Elements.$summaryStatementLabel = Elements.$el.find('.summary .summary-statement-label');
      Elements.$summaryStatementValue = Elements.$el.find('.summary .summary-statement-value');
      Elements.$summaryStatementDescription = Elements.$el.find('.summary .summary-statement-description');
      Elements.$summaryStatementBtn = Elements.$el.find('.summary .btn');
      Elements.$summarySources = Elements.$el.find('.summary-sources');
      Elements.$summarySourcesButtons = Elements.$summarySources.find('button');
      Elements.$summarySource = Elements.$summarySources.find('.summary-source');
      Elements.$summaryAttribution = Elements.$summary.find('.summary-attribution');
      Elements.$summaryBodies = Elements.$el.find('.summary-bodies');
      Elements.$summaryBodyContainer = Elements.$summary.find('.summary-body-container');
      Elements.$summaryBody = Elements.$el.find('.summary-body');
      Elements.$summaryBodyNext = Elements.$el.find('.summary-body-next');
      Elements.$backgroundMap = Elements.$el.find('.background-map');
      Elements.$buttonFoldDownChevron = Elements.$el.find('#button-fold-down-chevron');

      this.applyIEFix();

      this.addSummarySources();
      this.addSummaryBody();
      this.addBackgroundMap();
      this.addAnimation();
      this.addEvents();
      this.sectionHeight();
      this.setDefaults();
      this.hide();
      $('#svcf-datavis').on('BACKGROUND:MAP:READY', function() {
        self.backgroundMapReady = true;
        if(this.ready()) {
          $('#svcf-datavis').trigger('SECTION:READY', self.sectionHeight());
        }
      });
    },
    addEvents: function() {
      var self = this;
      Elements.$summaryStatement.on('click', function(e) {
        if(self.summarySources.isHidden() && self.summaryBody.isHidden()) {
          var $summaryStatementButton = $(e.currentTarget).find('a.btn');
          self.settings.destination = $summaryStatementButton.attr('data-destination');
          self.backgroundMap.animation[self.settings.className].focus.restart();
          self.summarySources.show();
          self.summaryBody.show();
          new TweenMax.to(Elements.$summaryStatement, 0.5, {
            scale: 0,
            opacity: 0
          });
        }else {
          self.summarySources.hide();
          self.summaryBody.hide();
        }
      });
      Elements.$summaryBodyNext.on('click', function(e) {
        if(self.summarySources.isHidden() && self.summaryBody.isHidden()) {
          self.summarySources.show();
          self.summaryBody.show();
          new TweenMax.to(Elements.$summaryStatement, 0.5, {
            scale: 0,
            opacity: 0
          });
          self.backgroundMap.animation[self.settings.className].focus.restart();
        }else {
          self.summarySources.hide();
          self.summaryBody.hide();
          self.settings.destination = $(e.currentTarget).find('.btn.summary-next').attr('data-destination');
          $('#svcf-datavis div.module-main .content').trigger('SECTION:NEXT', self.settings);
        }
      });
      $('#svcf-datavis').on('NAV:MAIN:NAVIGATE', function(e, settings) {
        self.killAllAnimations(settings);
      });
      Elements.$el.on('SVCF:SECTION:HEIGHT', function() {
        self.sectionHeight(true);
      });
      $('#svcf-datavis').on('SUMMARY:SOURCES:READY', function() {
        self.summarySourcesReady = true;
        if(self.ready()) {
          $('#svcf-datavis').trigger('SECTION:READY', self.sectionHeight());
        }
      });
      $('#svcf-datavis').on('SUMMARY:BODIES:READY', function() {
        self.summaryBodyReady = true;
        if(self.ready()) {
          $('#svcf-datavis').trigger('SECTION:READY', self.sectionHeight());
        }
      });
      var resizeTimer;
      $(window).on('resize', function(e) {
        clearTimeout(resizeTimer);
        resizeTimer = setTimeout(function() {
          self.sectionHeight();
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
    killAllAnimations: function() {
      for(var i in this.animation) {
        var animation = this.animation[i];
        animation.kill(true);
      }
      this.backgroundMap.killAllAnimations();
      return this;
    },
    ready: function() {
      this.sectionHeight();
      if(this.summaryBodyReady && this.summarySourcesReady && this.backgroundMapReady) {
        return true;
      }else {
        return false;
      }
    },
    sectionHeight: function(force) {
      if(!this.isScrolling() || force) {
        var height = Elements.$backgroundMap.innerHeight() + Elements.$summary.innerHeight() + 50;
        new TweenMax.to([
          $('#svcf-datavis div.module-main .content'),
          Elements.$el
        ], 0.67, {
          overwrite: 'auto',
          height: height
        });
        return height;
      }
    },
    addAnimation: function() {
      var self = this;
      this.animation = {
        // Summary Statement Section
        summaryStatement: new TimelineMax({
          paused: true,
          opacity: 1,
          tweens: [
            new TweenMax.to(Elements.$summaryStatement, 1, {
              onStart: function() {
                new TweenLite.set(Elements.$el, {
                  x: '0%'
                });
                new TweenMax.to(Elements.$summaryStatementBtn, 0.67, {
                  repeat: 5,
                  yoyo: true,
                  scale: 1.2,
                  textShadow: '0px 0px 1px rgba(255, 255, 255, 0.47)'
                });
              },
              onComplete: function() {
                new TweenMax.to(this.target, 1, {
                  delay: 3.5,
                  onComplete: function() {}
                });
              },
              ease: Elastic.easeOut,
              opacity: 1,
              backgroundColor: Constants.colors['$dark' + self.settings.color],
              borderColor: Constants.colors['$light' + self.settings.color],
              delay: 1,
              scale: 1
            })
          ],
          onComplete: function() {
            new TweenMax.to(Elements.$summaryStatement, 0, {
              ease: Elastic.easeOut,
              opacity: 0
            });
          }
        }),
        // Summary Sources Section
        summarySources: new TimelineMax({
          paused: true,
          onStart: function() {
            new TweenLite.set(Elements.$summarySources, {
              opacity: 1
            });
            new TweenLite.set(Elements.$summarySources.find('button'), {
              color: Constants.colors['$dark' + self.settings.color]
            });
          },
          tweens: [
            new TweenMax.to(Elements.$summaryStatement, 1, {
              ease: Elastic.easeOut,
              opacity: 0,
              scale: 0
            }),
            new TweenMax.to(Elements.$summaryAttribution, 1, {
              color: Constants.colors['$dark' + self.settings.color],
              ease: Elastic.easeOut,
              opacity: 1
            }),
            new TweenMax.staggerTo(Elements.$summarySource.get(), 1, {
              onStart: function() {
                new TweenLite.set($(this.target).find('.summary-source-container'), {
                  color: Constants.colors['$dark' + self.settings.color],
                  backgroundColor: Constants.colors['$light' + self.settings.color],
                  borderColor: Constants.colors['$dark' + self.settings.color]
                });
              },
              scale: 1,
              ease: Elastic.easeOut
            }, 0.2)
          ]
        }),
        // Summary Body Section
        summaryBody: new TimelineMax({
          paused: true,
          onStart: function() {
            new TweenMax.to($('#svcf-datavis div.module-main .content .summary-body').get(), 1, {
              backgroundColor: Constants.colors['$light' + self.settings.color],
              color: Constants.colors['$dark' + self.settings.color],
              ease: Linear.easeInOut
            });
          },
          tweens: [
            new TweenMax.staggerTo(Elements.$summaryBodies.toArray(), 1, {
              opacity: 1
            }, 0.2),
            new TweenMax.staggerTo(Elements.$summaryBodies.toArray(), 1, {
              delay: 2,
              opacity: 0
            }, 0.2)
          ],
          onComplete: function() {
            new TweenMax.to(Elements.$summarySources, 1, {
              opacity: 0
            }, 0.2);
          }
        })
      };
    },
    addSummarySources: function() {
      this.summarySources = new SVCF.SummarySources();
      var data = this.settings;
      data.$el = Elements.$summarySources;
      this.summarySources.initialize(data);
      return this.summarySources;
    },
    addSummaryBody: function() {
      this.summaryBody = new SVCF.SummaryBody();
      var settings = this.settings;
      settings.$el = Elements.$summaryBodies;
      this.summaryBody.initialize(settings);
      return this.summaryBody;
    },
    addBackgroundMap: function() {
      var settings = this.settings;
      settings.$el = Elements.$backgroundMap;
      this.backgroundMap = new SVCF.BackgroundMap();
      this.backgroundMap.initialize(settings);
      return this.backgroundMap;
    },
    show: function() {
      var self = this;
      this.summarySources.eqWidthHeight();
      this.summaryBody.eqContent();
      new TweenMax.to(Elements.$summaryStatement, 0.87, {
        delay: 1,
        borderColor: Constants.colors['$light' + this.settings.color],
        backgroundColor: Constants.colors['$dark' + this.settings.color],
        opacity: 1,
        scale: 1,
        ease: Elastic.easeInOut
      });
      new TweenMax.fromTo(Elements.$el, 1, {
        opacity: 0
      },
      {
        opacity: 1,
        pointerEvents: 'auto',
        onUpdate: function() {
          self.sectionHeight(true);
        },
        onComplete: function() {
          Elements.$el.appendTo(Elements.$el.parent());
        }
      });
      return this;
    },
    hide: function() {
      var self = this;
      new TweenMax.to(Elements.$el, 1, {
        onStart: function() {
          self.summarySources.hide();
          self.summaryBody.hide();
        },
        onUpdate: function() {
          self.sectionHeight(true);
        },
        onComplete: function() {},
        opacity: 0,
        pointerEvents: 'none'
      });
      return this;
    },
    isScrolling: function(val) {
      if(val && this._scrolling !== val) {
        this._scrolling = val;
      }
      return this._scrolling;
    },
    setDefaults: function() {
      new TweenMax.set(Elements.$summaryStatement, {
        borderColor: Constants.colors['$light' + this.settings.color],
        backgroundColor: Constants.colors['$dark' + this.settings.color],
        opacity: 0,
        scale: 0
      });
      new TweenMax.set(Elements.$buttonFoldDownChevron, {
        stroke: Constants.colors['$dark' + this.settings.color]
      });
      new TweenMax.fromTo(Elements.$summaryStatement.find('a.btn'), 1, {
        scale: 1,
        boxShadow: '0px 0px 11px rgba(0, 0, 0, 0.07)'
      },
      {
        yoyo: true,
        repeat: -1,
        scale: 1.3,
        textShadow: '0px 0px 5px rgba(255, 255, 255, 0.57)'
      });
      new TweenLite.set(Elements.$el, {
        opacity: 0,
        width: '100%'
      });
    },
    applyIEFix: function() {

      // detect IE
      var ua = window.navigator.userAgent;
      var msie = ua.indexOf('MSIE ');
      var isIE = (msie >= 0 || navigator.userAgent.match(/Trident.*rv[ :]*11\./));
      if (!isIE) {
        return;
      }

      // wrap our background map svg's in a new parent element
      var $svg = Elements.$backgroundMap.children('svg');
      $svg.wrap('<div class="iePaddingFix"></div>');

      // update the css so its position is absolute...
      $svg.css({
        position: 'absolute',
        top: '0',
        left: '0',
        right: '0'
      });

    }

  };
  return Module;
};
