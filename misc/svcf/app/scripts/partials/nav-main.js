SVCF.NavMain = function() {
  'use strict';
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
          if(self._scene !== $(e.currentTarget).attr('data-id')) {
            $('#svcf-datavis div.module-main .content').trigger('NAV:MAIN:NAVIGATE', settings);
          }
        });
      });
    },
    scene: function(val, id) {
      if(val !== this._scene) {
        this._scene = val;
        var backgroundColorGradient =
        'linear-gradient(to bottom, ' +
        Constants.colors['$dark' + Constants.getSettingsByClassName(val).color].replace('rgb(', 'rgba(').replace(')', ', 0.43)') + ', ' +
        Constants.colors['$dark' + Constants.getSettingsByClassName(val).color].replace('rgb(', 'rgba(').replace(')', ', 0.37)') + ' 37%,' +
        Constants.colors['$dark' + Constants.getSettingsByClassName(val).color].replace('rgb(', 'rgba(').replace(')', ', 0)') + ' 73%' +
        ')';
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
              fill: Constants.colors.white,
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
      var height = $('#svcf-datavis section .background-map').eq(0).height() +
                   $('#svcf-datavis section .panel').eq(0).height();
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
