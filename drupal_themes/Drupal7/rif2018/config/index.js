/**
 * @file
 * Include and export all config files into their own modules.
 */

const fs = require('fs');
const path = require('path');

fs.readdirSync(__dirname)
  .forEach(file => {
    // Exclude current file
    if (file === path.basename(__filename)) { return; }

    // Export modules named after each config file
    module.exports[path.basename(file, '.js')] = require(path.join(__dirname, file));
  });
