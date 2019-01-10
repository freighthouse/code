/**
 * @file
 * Config for the site Javascript compile tasks.
 */

const config = {};

//
// Additional paths browserify should check for plugins.
config.paths = [
  __dirname + '/../node_modules'
];

//
// Browserify plugins.
config.plugins = [
  'errorify'
];

// Configure mappings of global objects.
config.expose = {
  expose: {
    jquery: 'jQuery',
    Drupal: 'Drupal'
  }
};

//
// Transpiling config.
config.babelify = {};

config.babelify.presets = [
  'babel-preset-es2015'
].map(require.resolve);

config.babelify.plugins = [
  'babel-plugin-transform-object-rest-spread'
].map(require.resolve);

module.exports = config;
