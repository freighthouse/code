SVCF.Header = function() {
  'use strict';
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
