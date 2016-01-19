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
    'use strict';
    for(var i in this.settings) {
      var settings = this.settings[i];
      if(settings.className === className) {
        return settings;
      }
    }
  }
};
