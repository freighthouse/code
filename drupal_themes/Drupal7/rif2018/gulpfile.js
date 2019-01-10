/**
 * @file
 * Starting file for FED tools.
 */

 const requireDir = require('require-dir');

 // Require all tasks in gulp, including subfolders
 requireDir('./tasks', { recurse: true });
