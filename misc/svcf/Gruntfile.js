// Generated on 2015-06-17 using
// generator-webapp 0.5.1
'use strict';

// # Globbing
// for performance reasons we're only matching one level down:
// 'test/spec/{,*/}*.js'
// If you want to recursively match all subfolders, use:
// 'test/spec/**/*.js'

module.exports = function (grunt) {

  // Time how long tasks take. Can help when optimizing build times
  require('time-grunt')(grunt);

  // Load grunt tasks automatically
  require('load-grunt-tasks')(grunt);

  // Configurable paths
  var config = {
    app: 'app',
    dist: 'dist',
    tmp: '.tmp',
    deploy: 'deploy'
  };

  grunt.loadNpmTasks('assemble');

  // Define the configuration for all the tasks
  grunt.initConfig({

    surround: {
      options: {
        prepend: 'jq214 = jQuery.noConflict(true); (function($) { $(function() {',
        append: '});})(jq214);'
      },
      files: {
        src: '<%= config.tmp %>/concat/scripts/main.js',
        dest: '<%= config.deploy %>/scripts/main.js'
      },
    },

    'ftp-deploy': {
      build: {
        auth: {
          host: '50.87.16.92',
          port: 21,
          authKey: 'key1'
        },
        src: '<%= config.deploy %>',
        dest: '/sites/all/modules/svcf_infograph'
      }
    },

    // Project settings
    config: config,
    // Watches files for changes and runs tasks based on the changed files
    watch: {
      bower: {
        files: ['bower.json'],
        tasks: ['wiredep']
      },
      js: {
        files: ['<%= config.app %>/scripts/{,*/}*.js'],
        tasks: [/*'jshint'*/],
        options: {
          livereload: true
        }
      },
      jstest: {
        files: ['test/spec/{,*/}*.js'],
        tasks: ['test:watch']
      },
      gruntfile: {
        files: ['Gruntfile.js']
      },
      sass: {
        files: ['<%= config.app %>/styles/{,*/}*.{scss,sass}'],
        tasks: ['sass:server', 'autoprefixer']
      },
      styles: {
        files: ['<%= config.app %>/styles/{,*/}*.css'],
        tasks: ['newer:copy:styles', 'autoprefixer']
      },
      livereload: {
        options: {
          livereload: '<%= connect.options.livereload %>'
        },
        files: [
          '<%= config.app %>/{,*/}*.html',
          '.tmp/styles/{,*/}*.css',
          '<%= config.app %>/images/{,*/}*'
        ]
      },
      assemble: {
        files: [
          '<%= config.app %>/templates/layouts/*.hbs',
          '<%= config.app %>/templates/pages/{,*/}*.hbs',
          '<%= config.app %>/templates/partials/*.hbs'
        ],
        tasks: [
          'assemble:server'
        ]
      }
    },

    // The actual grunt server settings
    connect: {
      options: {
        port: 9000,
        // port: 8005,
        open: true,
        livereload: 35729,
        // Change this to '0.0.0.0' to access the server from outside
        hostname: 'localhost'
        // hostname: '192.168.1.135'
      },
      livereload: {
        options: {
          middleware: function(connect) {
            return [
              connect.static('.tmp'),
              connect().use('/bower_components', connect.static('./bower_components')),
              connect.static(config.app)
            ];
          }
        }
      },
      test: {
        options: {
          open: false,
          port: 9001,
          middleware: function(connect) {
            return [
              connect.static('.tmp'),
              connect.static('test'),
              connect().use('/bower_components', connect.static('./bower_components')),
              connect.static(config.app)
            ];
          }
        }
      },
      dist: {
        options: {
          base: '<%= config.dist %>',
          livereload: false
        }
      }
    },

    // Empties folders to start fresh
    clean: {
      dist: {
        files: [{
          dot: true,
          src: [
            '.tmp',
            '<%= config.dist %>/*',
            '!<%= config.dist %>/.git*'
          ]
        }]
      },
      server: '.tmp'
    },

    // Make sure code styles are up to par and there are no obvious mistakes
    jshint: {
      options: {
        devel: {
          console: false
        },
        jshintrc: '.jshintrc',
        reporter: require('jshint-stylish')
      },
      all: [
        'Gruntfile.js',
        '<%= config.app %>/scripts/{,*/}*.js',
        '!<%= config.app %>/scripts/vendor/*',
        'test/spec/{,*/}*.js'
      ]
    },

    // Mocha testing framework configuration options
    // mocha: {
    //   all: {
    //     options: {
    //       run: true,
    //       urls: ['http://<%= connect.test.options.hostname %>:<%= connect.test.options.port %>/index.html']
    //     }
    //   }
    // },

    // Compiles Sass to CSS and generates necessary files if requested
    sass: {
      options: {
        sourcemap: true,
        includePaths: ['bower_components']
        },
      dist: {
        files: [{
          expand: true,
          cwd: '<%= config.app %>/styles',
          src: ['*.{scss,sass}'],
          dest: '.tmp/styles',
          ext: '.css'
        }]
      },
      server: {
        files: [{
          expand: true,
          cwd: '<%= config.app %>/styles',
          src: ['*.{scss,sass}'],
          dest: '.tmp/styles',
          ext: '.css'
        }]
      }
    },

    // Add vendor prefixed styles
    autoprefixer: {
      options: {
        browsers: ['> 1%', 'last 2 versions', 'Firefox ESR', 'Opera 12.1']
      },
      dist: {
        files: [{
          expand: true,
          cwd: '.tmp/styles/',
          src: '{,*/}*.css',
          dest: '.tmp/styles/'
        }]
      }
    },

    // Automatically inject Bower components into the HTML file
    wiredep: {
      app: {
        ignorePath: /^\/|\.\.\//,
        src: ['<%= config.app %>/index.html'],
        exclude: ['bower_components/bootstrap-sass-official/assets/javascripts/bootstrap.js']
      },
      sass: {
        src: ['<%= config.app %>/styles/{,*/}*.{scss,sass}'],
        ignorePath: /(\.\.\/){1,2}bower_components\//
      }
    },

    // Renames files for browser caching purposes
    rev: {
      dist: {
        files: {
          src: [
            '<%= config.dist %>/scripts/{,*/}*.js',
            '<%= config.dist %>/styles/{,*/}*.css',
            '<%= config.dist %>/images/{,*/}*.*',
            '<%= config.dist %>/styles/fonts/{,*/}*.*',
            '<%= config.dist %>/*.{ico,png}'
          ]
        }
      }
    },

    // Reads HTML for usemin blocks to enable smart builds that automatically
    // concat, minify and revision files. Creates configurations in memory so
    // additional tasks can operate on them
    useminPrepare: {
      options: {
        dest: '<%= config.dist %>'
      },
      html: '<%= config.app %>/index.html'
    },

    // Performs rewrites based on rev and the useminPrepare configuration
    usemin: {
      options: {
        assetsDirs: [
          '<%= config.dist %>',
          '<%= config.dist %>/images',
          '<%= config.dist %>/styles'
        ]
      },
      html: ['<%= config.dist %>/{,*/}*.html'],
      css: ['<%= config.dist %>/styles/{,*/}*.css']
    },

    // The following *-min tasks produce minified files in the dist folder
    imagemin: {
      dist: {
        files: [{
          expand: true,
          cwd: '<%= config.app %>/images',
          src: '{,*/}*.{gif,jpeg,jpg,png}',
          dest: '<%= config.dist %>/images'
        }]
      }
    },

    svgmin: {
      dist: {
        files: [{
          expand: true,
          cwd: '<%= config.app %>/images',
          src: '{,*/}*.svg',
          dest: '<%= config.dist %>/images'
        }]
      }
    },

    htmlmin: {
      dist: {
        options: {
          collapseBooleanAttributes: true,
          collapseWhitespace: true,
          conservativeCollapse: true,
          removeAttributeQuotes: false,
          removeCommentsFromCDATA: true,
          removeEmptyAttributes: false,
          removeOptionalTags: false,
          removeRedundantAttributes: true,
          useShortDoctype: true
        },
        files: [{
          expand: true,
          cwd: '<%= config.dist %>',
          src: '{,*/}*.html',
          dest: '<%= config.dist %>'
        }]
      }
    },

    // By default, your `index.html`'s <!-- Usemin block --> will take care
    // of minification. These next options are pre-configured if you do not
    // wish to use the Usemin blocks.
    // cssmin: {
    //   dist: {
    //     files: {
    //       '<%= config.dist %>/styles/main.css': [
    //         '.tmp/styles/{,*/}*.css',
    //         '<%= config.app %>/styles/{,*/}*.css'
    //       ]
    //     }
    //   }
    // },
    // uglify: {
    //   dist: {
    //     files: {
    //       '<%= config.dist %>/scripts/scripts.js': [
    //         '<%= config.dist %>/scripts/scripts.js'
    //       ]
    //     }
    //   }
    // },
    // concat: {
    //   dist: {}
    // },

    // Copies remaining files to places other tasks can use
    copy: {
      dist: {
        files: [{
          expand: true,
          dot: true,
          cwd: '<%= config.app %>',
          dest: '<%= config.dist %>',
          src: [
            '*.{ico,png,txt}',
            'images/{,*/}*.webp',
            '{,*/}*.html',
            'styles/fonts/{,*/}*.*'
          ]
        }, {
          src: 'node_modules/apache-server-configs/dist/.htaccess',
          dest: '<%= config.dist %>/.htaccess'
        }, {
          expand: true,
          dot: true,
          cwd: '.',
          src: 'bower_components/bootstrap-sass-official/assets/fonts/bootstrap/*',
          dest: '<%= config.dist %>'
        }, {
          src: '<%= config.app %>/manifest.json',
          dest: '<%= config.dist %>/manifest.json'
        }]
      },
      styles: {
        expand: true,
        dot: true,
        cwd: '<%= config.app %>/styles',
        dest: '.tmp/styles/',
        src: '{,*/}*.css'
      },
      deploy: {
        files: [{
          src: '<%= config.tmp %>/styles/main.css',
          dest: '<%= config.deploy %>/styles/main.css'
        },
        {
          src: '<%= config.app %>/images/ajax-loader.gif',
          dest: '<%= config.deploy %>/styles/ajax-loader.gif'
        }]

      }
    },

    assemble: {
      options: {
        flatten: true,
        layout: 'layout.hbs',
        layoutdir: '<%= config.app %>/templates/layouts',
        assets: 'dist/images',
        partials: ['<%= config.app %>/templates/partials/{,*}*.hbs'],
        data: '<%= config.app %>/data/*.json'
      },
      dist: {
        files: {
          '<%= config.dist %>/': ['<%= config.app %>/templates/pages/*.hbs']
        }
      },
      server: {
        files: {
          '.tmp/': ['<%= config.app %>/templates/pages/*.hbs']
        }
      },
      deploy: {
        options: {
          layout: 'drupal-include.hbs',
          ext: '.inc'
        },
        files: {
          '<%= config.deploy %>': ['<%= config.app %>/templates/pages/svcf_infograph.hbs']
        }
      }
    },

    // Generates a custom Modernizr build that includes only the tests you
    // reference in your app
    // modernizr: {
    //   dist: {
    //     devFile: 'bower_components/modernizr/modernizr.js',
    //     outputFile: '<%= config.dist %>/scripts/vendor/modernizr.js',
    //     files: {
    //       src: [
    //         '<%= config.dist %>/scripts/{,*/}*.js',
    //         '<%= config.dist %>/styles/{,*/}*.css',
    //         '!<%= config.dist %>/scripts/vendor/*'
    //       ]
    //     },
    //     uglify: true
    //   }
    // },

    // Run some tasks in parallel to speed up build process
    concurrent: {
      server: [
        'sass:server',
        'copy:styles',
        'assemble'
      ],
      test: [
        'copy:styles'
      ],
      dist: [
        'sass',
        'copy:styles',
        'imagemin',
        'svgmin',
        'assemble'
      ]
    },

    concat: {
      // scrollmagic: {
      //   options: {
      //     sourceMap: false
      //   },
      //   files: {
      //     '<%= config.app %>/scripts/vendor/scrollmagic.js': [
      //       'bower_components/scrollmagic/scrollmagic/uncompressed/ScrollMagic.js',
      //       'bower_components/scrollmagic/scrollmagic/uncompressed/plugins/jquery.ScrollMagic.js',
      //       'bower_components/scrollmagic/scrollmagic/uncompressed/plugins/debug.addIndicators.js'
      //     ]
      //   }
      // },
      // greensock: {
      //   options: {
      //     sourceMap: false
      //   },
      //   files: {
      //     '<%= config.app %>/scripts/vendor/greensock.js': [
      //       'bower_components/greensock/src/uncompressed/TimelineLite.js',
      //       'bower_components/greensock/src/uncompressed/TimelineMax.js',
      //       'bower_components/greensock/src/uncompressed/TweenLite.js',
      //       'bower_components/greensock/src/uncompressed/TweenMax.js',
      //       'bower_components/greensock/src/uncompressed/jquery.gsap.js',
      //       'bower_components/greensock/src/uncompressed/plugins/ScrollToPlugin.js',
      //       'bower_components/greensock/src/uncompressed/easing/EasePack.js'
      //     ]
      //   }
      // }
    }
  });


  grunt.registerTask('serve', 'start the server and preview your app, --allow-remote for remote access', function (target) {
    if (grunt.option('allow-remote')) {
      grunt.config.set('connect.options.hostname', '0.0.0.0');
    }
    if (target === 'dist') {
      return grunt.task.run(['build', 'connect:dist:keepalive']);
    }

    grunt.task.run([
      'clean:server',
      'wiredep',
      'concurrent:server',
      'autoprefixer',
      'connect:livereload',
      'watch'
    ]);
  });

  grunt.registerTask('server', function (target) {
    grunt.log.warn('The `server` task has been deprecated. Use `grunt serve` to start a server.');
    grunt.task.run([target ? ('serve:' + target) : 'serve']);
  });

  grunt.registerTask('test', function (target) {
    if (target !== 'watch') {
      grunt.task.run([
        'clean:server',
        'concurrent:test',
        'autoprefixer'
      ]);
    }

    grunt.task.run([
      'connect:test'
      // 'mocha'
    ]);
  });

  grunt.registerTask('build', [
    'clean:dist',
    'wiredep',
    'useminPrepare',
    'concurrent:dist',
    'autoprefixer',
    'concat',
    'cssmin',
    // 'concat:greensock',
    // 'concat:scrollmagic',
    // 'uglify',
    'copy:dist',
    'assemble',
    // 'modernizr',
    // 'rev',
    'usemin',
    'htmlmin'
  ]);

  grunt.registerTask('default', [
    // 'newer:jshint',
    'test',
    'build'
  ]);
  grunt.registerTask('deploy', [
    'assemble:deploy',
    'copy:deploy',
    'surround'
    //'ftp-deploy'
  ]);
};
