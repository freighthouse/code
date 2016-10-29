module.exports = function (grunt) {
     "use strict";
    grunt.initConfig(
        {
            pkg: grunt.file.readJSON('package.json'),
            watch: {
                src: {
                    files: ['**/*.scss', '**/*.php'],
                    tasks: ['compass:dev']
                },
                scripts: {
                    files: ['./js/includes/*.js'],
                    tasks: ['jshint', 'concat:js', 'uglify'],
                    options: {
                        nospawn: true,
                        livereload: 45729
                    }
                },
                options: {
                    livereload: true
                },
                configFiles: {
                    files: ['Gruntfile.js'],
                    options: {
                        reload: true
                    }
                }
            },
            sass: {
                dist: {
                    files: {
                        'css/style.css' : 'custom-sass/style.scss'
                    }
                }
            },
            //Currently not using Compass
            compass: {
                dev: {
                    options: {
                        sassDir: 'custom-sass',
                        cssDir: 'css',
                        // imagesPath: 'assets/img',
                        imagesPath: 'images',
                        noLineComments: false,
                        outputStyle: 'compressed'
                    }
                }
            },
            concat: {
                options: {separator: ';'},
                js: {
                    // src: ['./js/includes/*.js'],
                    // dest: './js/compiled.js'
                    src: ['js/includes/*.js'],
                    dest: 'js/compiled.js'
                },
            },
            jshint: {
                // all: ['js/src/'],
                all: ['js/'],
                options: {
                    loopfunc: true
                },
            },
            // accessibility: {
            //     options : {
            //         accessibilityLevel: 'WCAG2A'
            //     },
            //     test : {
            //         src: ['example/test.html']
            //     }
            // },

            // bootlint: {
            //     options: {
            //         relaxerror: [],
            //         showallerrors: false,
            //         stoponerror: false,
            //         stoponwarning: false
            // },
            //     files: ['path/to/file.html', 'path/to/*.html']
            // },

        }
    );

    grunt.loadNpmTasks('grunt-contrib-compass');
    grunt.loadNpmTasks('grunt-contrib-sass');
    grunt.loadNpmTasks('grunt-contrib-watch');
    // grunt.loadNpmTasks('grunt-contrib-jshint');
    // grunt.loadNpmTasks('grunt-contrib-concat');
    // grunt.loadNpmTasks('grunt-accessibility');
    // grunt.loadNpmTasks('grunt-bootlint');

    grunt.registerTask('default', ['watch']);
};
