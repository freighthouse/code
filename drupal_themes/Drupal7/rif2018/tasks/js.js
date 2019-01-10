/**
 * @file
 * Compiling tasks for site Javascript.
 */

const gulp = require('gulp');
const gutil = require('gulp-util');
const glob = require('glob');
const browserify = require('browserify');
const source = require('vinyl-source-stream');
const argv = require('yargs').argv;

const config = require('../config').js;
const paths = require('../config').paths.js;

/**
 * Bundle a browserify object Javascript.
 */
function bundle(b) {
  b.bundle()
    .pipe(source('main.js'))
    .pipe(gulp.dest(paths.build));
}

gulp.task('js', (cb) => {
  glob(paths.source, (error, files) => {
    // Add a watcher plugin if a watch flag is set.
    if (argv.watch) { config.plugins.push('watchify'); }

    // Create a varible with our browserify settings we can utilize later.
    let b = browserify({
      entries: files,
      cache: {},
      packageCache: {},
      plugin: config.plugins,
      paths: config.paths
    })
    // Ignore global JS objects.
    .exclude('jQuery')
    .exclude('Drupal')
    // Expose the global JS objects.
    .transform('exposify', config.expose)
    // Transform ES6 code.
    .transform('babelify', config.babelify)
    // Browserify error handling.
    .on('error', function(error) {
      gutil.log(err.message);
      gutil.beep();
      this.emit('end');
    });

    // Watchify event handlers.
    if (argv.watch) {
      // Watchify log handler
      b.on('log', function(msg) {
        gutil.log(msg);
      });

      // Watchify update handler
      b.on('update', function(id) {
        gutil.log(id);
        bundle(b);
      });
    }

    // Initial compile.
    bundle(b);
    cb(error);
  });
});
