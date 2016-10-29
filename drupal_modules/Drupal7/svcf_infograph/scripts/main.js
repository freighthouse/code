jq214 = jQuery.noConflict(true); (function($) { $(function() {
var Constants = {
  colors: {
    $white: 'rgb(255, 255, 255)',
    $darkGreen: 'rgb(115, 152, 73)',
    $mediumGreen: 'rgb(172, 198, 143)',
    $lightGreen: 'rgb(209, 224, 193)',
    $darkBlue: 'rgb(0, 121, 175)',
    $mediumBlue: 'rgb(139, 188, 225)',
    $lightBlue: 'rgb(176, 210, 236)',
    $darkPurple: 'rgb(99, 62, 152)',
    $mediumPurple: 'rgb(161, 139, 193)',
    $lightPurple: 'rgb(224, 216, 234)',
    $black: 'rgb(0, 0, 0)'
  },
  settings: [
    {
      id: 0,
      className: 'local',
      prefixText: 'Local',
      color: 'Blue',
      pagination: {
        next: 'national'
      }
    },
    {
      id: 1,
      className: 'national',
      prefixText: 'National',
      color: 'Green',
      pagination: {
        prev: 'local',
        next: 'global'
      }
    },
    {
      id: 2,
      className: 'global',
      prefixText: 'Global',
      color: 'Purple',
      pagination: {
        prev: 'national',
        next: 'local'
      }
    }
  ],
  getSettingsByClassName: function(className) {
    for(var i in this.settings) {
      var settings = this.settings[i];
      if(settings.className === className) {
        return settings;
      }
    }
  }
};
var SVCF = SVCF || function() {
  var Elements = {
    $el: $('#svcf-datavis'),
    $main: $('#svcf-datavis div.module-main'),
    $content: $('#svcf-datavis div.module-main .content'),
    $sections: $('#svcf-datavis div.module-main .content section.section'),
    $header: $('#svcf-datavis div.module-header'),
    $navMain: $('#svcf-datavis div.module-nav-main')
  };
  var Module = {
    sections: [],
    header: {},
    scenes: [],
    _contentHeight: 0,
    initialize: function() {
      this.addSections();
      this.addNavMain();
      this.addHeader();
      this.addEvents();
      this.eqHeightSections();
    },
    addEvents: function() {
      var self = this;
      Elements.$el.find('section.section.index .panel').on('click', function(e) {
        new TweenMax.to(Elements.$el.find('section.section.index'), 1, {
          y: '-100%'
        });
        Elements.$el.trigger('NAV:MAIN:NAVIGATE', self.getSectionByClassName('local').settings);
      });
      Elements.$el.on('SECTION:READY', function(e, data) {
        self.sectionReady(self.contentHeight(data));
      });
      Elements.$el.on('SECTION:NEXT', function(e, data) {
        self.sectionNext(e, data);
      });
      Elements.$el.on('NAV:MAIN:NAVIGATE', function(e, settings) {
        self.navMainNavigate(settings);
      });
    },
    sectionNext: function(e, data) {
      var nextSection = this.getSectionByClassName(data.className).settings.pagination.next;
      var nextSectionSettings = this.getSectionByClassName(nextSection).settings;
      this.navMainNavigate(nextSectionSettings);
    },
    navMainNavigate: function(settings) {
      var self = this;
      this.header.scene(settings);
      this.navMain.scene(settings.className, settings.id);
      var section = this.getSectionByClassName(settings.className);
      section.backgroundMap.scene(settings);
      new TimelineMax({
        tweens: [
          new TweenMax.to(Elements.$el, 1, {
            backgroundColor: Constants.colors['$medium' + settings.color],
          }),
          new TweenMax.to([
            Elements.$sections
          ], 1, {
            onStart: function() {
              var section = self.getSectionByClassName(settings.className);
              section.hide();
            },
            opacity: 0,
            onComplete: function() {
              self.killAllSections();
              var section = self.getSectionByClassName(settings.className);
              section.show();
            }
          })
        ]
      });
      $(window).trigger('resize');
    },
    getSectionByClassName: function(className) {
      var section;
      for(var i in this.sections) {
        if(this.sections[i].settings.className === className) {
          section = this.sections[i];
        }
      }
      return section;
    },
    addSections: function() {
      for(var i in Constants.settings) {
        var settings = Constants.settings[i];
        var section = new SVCF.Section();
        section.initialize(settings)
        section.hide();
        this.sections.push(section);
      }
      return this;
    },
    addNavMain: function() {
      this.navMain = new SVCF.NavMain();
      this.navMain.initialize({
        $el: $('#svcf-datavis .module-nav-main')
      });
      return this;
    },
    addHeader: function() {
      this.header = new SVCF.Header();
      this.header.initialize({
        $el: $('#svcf-datavis div.module-header')
      });
      return this.header;
    },
    sectionReady: function(val) {
      Elements.$content.height(val);
    },
    contentHeight: function(val) {
      if(val && (val !== this._contentHeight)) {
        if(val > this._contentHeight || this._contentHeight === 0) {
          this._contentHeight = val;
        }
      }
      return this._contentHeight;
    },
    killAllSections: function() {
      for(var i in this.sections) {
        this.sections[i].killAllAnimations();
      }
      return this;
    },
    eqHeightSections: function() {
      var self = this;
      var height = 0;
      Elements.$sections.each(function(ind, obj) {
        var $section = $(obj);
        if(height < $section.height()) {
          height = $section.height();
        }
      });
      TweenMax.set(Elements.$sections, {
        height: height
      });
    }
  };
  return Module;
};

$(document).ready(function(){
  if($('#svcf-datavis').length) { 
    imagesLoaded($('#svcf-datavis'), function() {
      new TweenMax.to($('#svcf-datavis'), 1, {
        delay: 0.3,
        opacity: 1
      });
      var svcf = new SVCF();
      svcf.initialize(); 
    });
  }
});
SVCF.Header = function() {
  var Elements = {
    $el: undefined,
    $pageTitle: undefined,
    $pageSubtitle: undefined,
    $subtitlePrefix: undefined,
    $subtitleSuffix: undefined
  };
  var Module = {
    sceneSettings: undefined,
    prefixText: undefined,    
    initialize: function(settings) {
      this.settings = settings;
      Elements.$el = this.settings.$el;
      Elements.$pageTitle = this.settings.$el.find('.page-title');
      Elements.$pageSubtitle = this.settings.$el.find('.page-subtitle');
      Elements.$subtitlePrefix = this.settings.$el.find('.subtitle-prefix');
      Elements.$subtitleSuffix = this.settings.$el.find('.subtitle-suffix');
      this.setDefaults();
      this.addEvents();
    },
    addEvents: function() {
      var self = this;
      $(window).resize(function() {
        if(self.sceneSettings) { 
          self.windowResize();
        }
      });
    },
    windowResize: function() {
      this.scene(this.sceneSettings);
    },
    scene: function(settings) {
      new TweenLite.set(Elements.$subtitlePrefix, {
        display: 'inline-block'
      });
      var widthStart = Elements.$subtitlePrefix.width();
      var widthStop = Elements.$subtitlePrefix.width('auto').html(settings.prefixText).width();
      this.sceneSettings = settings;
      new TimelineMax({
        align: 'normal',
        tweens: [
          new TweenLite.set(Elements.$subtitleSuffix, {
            marginLeft: '0px'
          }),
          new TweenMax.to(Elements.$el, 1, {
            color: Constants.colors['$dark' + settings.color]
          }),
          new TweenMax.fromTo(Elements.$subtitlePrefix, 1, {
            width: widthStart
          },
          {
            width: widthStop
          })
        ]
      });
      return this;
    },
    setDefaults: function() {
      new TweenLite.set(Elements.$subtitlePrefix, {
        display: 'none',
        overflow: 'hidden'
      });
    }
  };
  return Module;
};
SVCF.NavMain = function() {
  var Elements = {
    $el: {},
    $buttons: {},
    $buttonPaths: {}
  };
  var Module = {
    animation: {},
    _scene: undefined,
    initialize: function(settings) {
      this.settings = settings;
      Elements.$el = this.settings.$el;
      Elements.$buttons = Elements.$el.find('a');
      Elements.$buttonSVG = Elements.$buttons.find('svg');
      Elements.$buttonElements = Elements.$el.find('a svg g');
      Elements.$buttonPaths = Elements.$el.find('a svg path');
      this.setDefaults();
      this.addEvents();
    },
    addEvents: function() {
      var self = this;
      Elements.$buttons.each(function(ind, obj) {
        var $button = $(obj);
        var settings = Constants.getSettingsByClassName($button.attr('data-id'));
        $button.on('click', function(e) {
          if(self._scene != $(e.currentTarget).attr('data-id')) {
            $('#svcf-datavis div.module-main .content').trigger('NAV:MAIN:NAVIGATE', settings);
          }
        });
      });
    },
    scene: function(val, id) {
      if(val !== this._scene) {
        this._scene = val;
        var backgroundColorGradient = 
        'linear-gradient(to bottom, '
         + Constants.colors['$dark' + Constants.getSettingsByClassName(val).color].replace('rgb(', 'rgba(').replace(')', ', 0.43)') + ', '
         + Constants.colors['$dark' + Constants.getSettingsByClassName(val).color].replace('rgb(', 'rgba(').replace(')', ', 0.37)') + ' 37%,'
         + Constants.colors['$dark' + Constants.getSettingsByClassName(val).color].replace('rgb(', 'rgba(').replace(')', ', 0)') + ' 73%'
         + ')'
        new TimelineMax({
          align: 'normal',
          tweens: [
            new TweenMax.to(Elements.$el, 1, {
              opacity: 1
            }),
            new TweenMax.to(Elements.$buttonPaths, 1, {
              fill: Constants.colors['$dark' + Constants.getSettingsByClassName(val).color],
              onStart: function() {
                Elements.$el.css({
                  background: backgroundColorGradient
                });
              }
            }),
            new TweenMax.to($('#svcf-datavis'), 1, {
              backgroundColor: Constants.colors['$medium' + Constants.getSettingsByClassName(val).color]
            }),
            new TweenMax.to(Elements.$buttonElements, 1, {
              scale: 1 
            }),
            new TweenMax.to(Elements.$buttonPaths.eq(id), 1, {
              fill: Constants.colors['$white']
            }),
            new TweenMax.to(Elements.$buttonElements.eq(id), 1, {
              scale: 1.2
            })
          ]
        });
      }
      return this._scene;
    },
    eqHeight: function() {
      var height = $('#svcf-datavis section .background-map').eq(0).height()
                 + $('#svcf-datavis section .panel').eq(0).height();
      var top = $('#svcf-datavis div.module-header').innerHeight();
      Elements.$el.css({
        top: top,
        height: height
      });
      return height;
    },
    setDefaults: function() {
      TweenLite.set(Elements.$buttonElements, {
        transformOrigin: 'center center',
        scale: 1
      });
      TweenLite.set([Elements.$buttonPaths, Elements.$buttonSVG], {
        fill: Constants.colors.$white
      });
    }
  };
  return Module;
};
SVCF.Section = function() {
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
        if(this.ready()) $('#svcf-datavis').trigger('SECTION:READY', self.sectionHeight());
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
        if(self.ready()) $('#svcf-datavis').trigger('SECTION:READY', self.sectionHeight());
      });
      $('#svcf-datavis').on('SUMMARY:BODIES:READY', function() {
        self.summaryBodyReady = true; 
        if(self.ready()) $('#svcf-datavis').trigger('SECTION:READY', self.sectionHeight());
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
                })
              },
              onComplete: function() {
                new TweenMax.to(this.target, 1, {
                  delay: 3.5,
                  onComplete: function() {}
                })
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
            })
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
            }, 0.2)
          }
        })
      }
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
      var msie = ua.indexOf("MSIE ");
      var isIE = (msie >= 0 || navigator.userAgent.match(/Trident.*rv[ :]*11\./));
      if (!isIE)
        return;

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
SVCF.BackgroundMap = function() {
  var Configuration = {
    // local
    local: {
      $bayAreaCountyMap: $('#svcf-datavis #bay-area-county-map'),
      $bayAreaCountyMapCounty: $('#svcf-datavis #bay-area-county-map > g'),
      $bayAreaMarker: $('#svcf-datavis #bay-area-marker'),
      $bayAreaMagnification: $('#svcf-datavis #bay-area-magnification'),
      $bayAreaMagnificationFocus: $('#svcf-datavis #bay-area-magnification-focus'),
      $bayAreaMagnificationHighlight: $('#svcf-datavis #bay-area-magnification-highlight'),
      $bayAreaMagnificationStream: $('#svcf-datavis #bay-area-magnification-stream'),
      $usMapStateCalifornia: $('#svcf-datavis #us-map-state-california'),
      $usMapBackground: $('#svcf-datavis #us-map-background'),
      $usMapBackgroundStates: $('#svcf-datavis #us-map-background > *'),
      $bayAreaCountyMapTextOverlay: $('#svcf-datavis #bay-area-county-map-text-overlay')
    },
    // national
    national: {
      $usMapStatesBackground: $('#svcf-datavis #us-map-states-background'),
      $usMapStatesBackgroundStates: $('#svcf-datavis #us-map-states-background > *'),
      $usMapStatesBackgroundCalifornia: $('#svcf-datavis #us-map-states-background #us-map-state-4'),
      $usMapStatesBackgroundOverlayText: $('#svcf-datavis #us-map-states-background-overlay-text')
    },
    // global
    global: {
      $worldMapCountries: $('#svcf-datavis #world-map-countries'),
      $worldMapCountry: $('#svcf-datavis #world-map-countries > *'),
      $worldMapCountriesBackground: $('#svcf-datavis #world-map-countries-background'),
      $worldMapTextBoxOverlay: $('#svcf-datavis #world-map-text-box-overlay'),
      $worldMapCountriesPanelList: $('#svcf-datavis #world-map-countries-panel-list'),
      $worldMapCountriesPanelTitle: $('#svcf-datavis #world-map-countries-panel-title'),
      $worldMapTextBoxOverlayBackground: $('#svcf-datavis #world-map-text-box-overlay-background')
    }
  };
  var Elements = {
    $el: undefined,
    $svg: undefined,
    $backgroundMapContainer: undefined
  };
  var Module = {
    animation: {},
    initialize: function(settings) {
      this.settings = settings;
      Elements.$el = this.settings.$el;
      Elements.$svg = Elements.$el.find('svg');
      Elements.$backgroundMapContainer = Elements.$el.find('svg > *');
      this.configureElements();
    },
    addEvents: function() {
      imagesLoaded(Elements.$el, function() {
        $('#svcf-datavis').trigger('BACKGROUND:MAP:READY'); 
        this.addAnimation();
        this.addEvents();
      });
    },
    addAnimation: function() {
      this.animation = {
        // Local
        local: {
          default: new TimelineMax({
            paused: true,
            onStart: function() {
              new TweenMax.staggerFromTo(Elements.$usMapBackgroundStates.toArray(), 1, {
                opacity: 0
              },
              {
                ease: Linear.easeOut,
                opacity: 0.77
              }, 0.07);
            },
            tweens: [
              new TweenMax.set([
                Elements.$bayAreaCountyMap,
                Elements.$bayAreaCountyMapCounty,
                Elements.$bayAreaMagnification,
                Elements.$bayAreaMagnificationFocus,
                Elements.$bayAreaMagnificationHighlight,
                Elements.$bayAreaMagnificationStream,
                Elements.$usMapStateCalifornia,
                Elements.$bayAreaCountyMapTextOverlay
              ], {
                opacity: 0
              }),
              new TweenMax.fromTo([
                Elements.$usMapBackground
              ], 1, 
              {
                opacity: 0
              },
              {
                opacity: 1
              }),
              new TweenMax.fromTo(Elements.$backgroundMapContainer, 3.5, {
                x: -350,
                y: -100,
                scale: 1
              },
              {
                x: -150,
                y: -100,
                scale: 1.75,
                ease: Linear.easeInEaseOut
              }),
              new TweenMax.fromTo([
                Elements.$bayAreaMarker,
                Elements.$usMapStateCalifornia
              ], 1, {
                opacity: 0
              },
              {
                delay: 2.5,
                opacity: 1,
                onComplete: function() {
                  new TweenMax.to(Elements.$bayAreaMarker, 1, {
                    repeat: 1,
                    yoyo: true,
                    scale: 1.31,
                    transformOrigin: 'bottom center'
                  });
                }
              })
            ]
          }),
          focus: new TimelineMax({
            paused: true,
            onStart: function() {},
            tweens: [
              new TweenMax.to([
                Elements.$bayAreaMarker,
                Elements.$usMapBackground,
                Elements.$usMapBackgroundStates
              ], 1, {
                opacity: 0,
                onComplete: function() {
                  new TweenMax.to(Elements.$bayAreaCountyMapTextOverlay, 2, {
                    opacity: 1,
                    ease: Linear.easeInEaseOut
                  })
                }
              }),
              new TweenMax.to([
                Elements.$bayAreaCountyMap,
                Elements.$usMapStateCalifornia,
                Elements.$bayAreaMagnification,
                Elements.$bayAreaMagnificationFocus,
                Elements.$bayAreaMagnificationHighlight,
                Elements.$bayAreaMagnificationStream
              ], 1, {
                opacity: 1
              }),
              new TweenMax.staggerTo(Elements.$bayAreaCountyMapCounty, 1, {
                opacity: 1
              }, 0.25),
              new TweenMax.to(Elements.$backgroundMapContainer, 2, {
                x: 100,
                y: -175,
                scale: 1.45
              })
            ],
            onComplete: function() {
              // 
            }
          })
        },


        // National
        national: {
          default: new TimelineMax({
            paused: true,
            onStart: function() {
              new TweenMax.set(Elements.$backgroundMapContainer, {
                x: 165,
                y: 0,
                scale: 1
              });
              
            },
            tweens: [
              new TweenMax.set([Elements.$usMapStatesBackgroundOverlayText], {
                opacity: 0
              }),
              new TweenMax.to([
                Elements.$usMapStatesBackground
              ], 3, {
                opacity: 1
              }),
              new TweenMax.staggerTo(Elements.$usMapStatesBackgroundStates, ((Math.random() * 3.5) + 2.5), {
                onStart: function() {
                  TweenMax.to(this.target, 1, {
                    opacity: 1
                  });
                },
                overwrite: 'all',
                yoyo: true,
                fill: Constants.colors.$darkGreen
              }, 0.17)/*,
              new TweenMax.fromTo([Elements.$usMapStatesBackgroundCalifornia], 1, {
                opacity: 1,
                x: 0,
                y: 0
              },
              {
                overwrite: 'all',
                opacity: 1,
                fill: Constants.colors.$white
              })*/
            ],
            onComplete: function() {
            }
          }),
          focus: new TimelineMax({
            paused: true,
            onStart: function() {
              new TweenMax.staggerTo(Elements.$usMapStatesBackgroundStates, 1.5, {
                overwrite: 'all',
                yoyo: false,
                fill: Constants.colors.$darkGreen
              });
              /*new TweenMax.to([Elements.$usMapStatesBackgroundCalifornia], 2, {
                overwrite: 'all',
                x: -75,
                y: 50,
                ease: Linear.easeInEaseOut,
                fill: Constants.colors.$white
              });*/
            },
            tweens: [
              new TweenMax.to([Elements.$backgroundMapContainer], 2, {
                x: -150,
                y: -75,
                scale: 1.33,
                ease: Linear.easeInEaseOut
              }),
              new TweenMax.fromTo([Elements.$usMapStatesBackgroundOverlayText], 1, {
                opacity: 0
              },
              {
                delay: 1.5,
                opacity: 1
              })
            ]
          })
        },


        // Global
        global: {
          default: new TimelineMax({
            paused: true,
            onStart: function() {
              new TweenMax.to(Elements.$backgroundMapContainer, 0, {
                x: 0,
                y: 0,
                scale: 1
              });
              TweenLite.set(Elements.$worldMapTextBoxOverlay, {
                opacity: 0
              });
            },
            tweens: [
              new TweenMax.staggerFromTo(Elements.$worldMapCountry, 4, {
                fill: Constants.colors.$lightPurple,
                opacity: 0.73
              },
              {
                onStart: function() {
                  TweenMax.to(this.target, 1, {
                    opacity: 1
                  });
                },
                overwrite: 'all',
                yoyo: true,
                fill: Constants.colors.$darkPurple
              }, 0.17),

              new TweenMax.fromTo($('#world-map-countries-background'), 1.5, {
                fill: Constants.colors.$darkPurple,
                opacity: 0
              },
              {
                onStart: function() {
                  TweenMax.to(this.target, 1, {
                    opacity: 1
                  });
                },
                fill: Constants.colors.$lightPurple,
                opacity: 1
              })
            ],
            onComplete: function() {
              // 
            }
          }),
          focus: new TimelineMax({
            paused: true,
            onStart: function() {
              new TweenMax.set([Elements.$worldMapTextBoxOverlay], {
                transformOrigin: 'center center'
              });
            },
            tweens: [
              new TweenMax.fromTo([Elements.$worldMapTextBoxOverlay], 1, {
                opacity: 0,
                y: -150,
                scale: 1
              },
              {
                opacity: 1,
                y: 0,
                scale: 1.15
              })
            ]
          })
        }
      };
      return this;
    },
    killAllAnimations: function() {
      for(var i in this.animation) {
        var animation = this.animation[i];
        for(var j in animation) {
          var timeline = animation[j];
          timeline.kill(true);
        }
      }
      return this;
    },
    configureElements: function() {
      var configurationElement = Configuration[this.settings.className];
      for(var j in configurationElement) {
        Elements[j] = configurationElement[j];
      }
      return this;
    },
    scene: function(settings) {
      this.addAnimation();
      this.animation[settings.className].default.restart();
      return this;
    },
    setDefaults: function() {}
  };

  return Module;
};

SVCF.SummarySources = function() {
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
        if($(e.currentTarget).find('.slick-active').last().index() == (Elements.$summaryContainers.length - 1)) {
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
SVCF.SummaryBody = function() {
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
});})(jq214);