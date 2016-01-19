SVCF.BackgroundMap = function() {
  'use strict';
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
                    ease: Linear.easeInEaseOut,
                  });
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
