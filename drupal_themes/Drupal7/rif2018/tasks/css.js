/**
 * @file
 * Task that compiles site Sass into CSS.
 */

const gulp = require('gulp');
const sass = require('gulp-sass');
const postcss = require('gulp-postcss');
const rucksack = require('rucksack-css');
const cssnext = require('postcss-cssnext');
const argv = require('yargs').argv;

const config = require('../config').css;
const paths = require('../config').paths.css;
const plugins = [
  cssnext(config.cssnext)
];

const scssTask = function() {
  return gulp.src(paths.source)
    // Compile Sass files into CSS.
    .pipe(sass(config.options).on('error', sass.logError))
    .pipe(postcss(plugins))
    .pipe(postcss([ rucksack() ]))
    .pipe(gulp.dest(paths.build));
}

const scssWatch = function() {
  scssTask();
  gulp.watch(paths.source, ['scss'])
}

gulp.task('scss', scssTask);

/**
 * CSS task that checks if we're setting up a watcher or a one off compile.
 */
gulp.task('css', argv.watch ? scssWatch : scssTask);
