/**
 * Task that processes SVG files and creates fallbacks.
 */

const gulp = require('gulp');
const glob = require('glob');
const gulpicon = require('gulpicon/tasks/gulpicon');

const paths = require('../config').paths.svg;
const config = require(paths.optionsFile);
const files = glob.sync(`${paths.source}/*.svg`);

const options = Object.assign({
  dest: paths.build,
  compressPNG: true
}, config);

gulp.task('svg', gulpicon(files, options));
