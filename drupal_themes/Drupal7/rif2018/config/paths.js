/**
 * @file
 * Config file containing variables for key paths in the system.
 */

const config = {};

//
// Folder where site files lives.
// config.siteRoot = '../web';
config.siteRoot = '../';

//
// Site theme folders.
// config.theme = `${config.siteRoot}/sites/all/themes/custom/rif2018`;
config.theme = `${config.siteRoot}rif2018`;
// config.theme = `.`;

//
// Site CSS paths.
config.css = {};

// Paths for the platform's main theme CSS
config.css.source = `${config.theme}/src/scss/**/*.{scss,sass}`;
config.css.build = `${config.theme}/build/css`;

//
// Site JS paths.
config.js = {};

// Main theme JS
config.js.source = `${config.theme}/src/js/*.js`;
config.js.build = `${config.theme}/build/js`;

//
// Paths to site SVG files
config.svg = {};

// Main theme SVG
config.svg.source = `${config.theme}/src/img/svg`;
config.svg.build = `${config.theme}/build/css/icon`;
config.svg.optionsFile = `../${config.svg.source}/grunticonOptions.js`;

module.exports = config;
