var SVCF = SVCF || function() {
  'use strict';
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
        section.initialize(settings);
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
  'use strict';
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
