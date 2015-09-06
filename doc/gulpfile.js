'use strict';

var fs = require('fs');
var ffs = require('final-fs');
var gulp = require('gulp');
var Book = require('gitbook').Book;
var $ = require('gulp-load-plugins')();
var YAML = require('yamljs');
var _ = require('lodash');
var mkdirp = require('mkdirp');
var stylish = require('jshint-stylish');

var base = '';
var swaggerTpl = fs.readFileSync(base + 'templates/api.md.tpl', 'utf-8');

gulp.task('lint:jslint', function(){
    return gulp.src('gulpfile.js')
        .pipe($.jshint())
        .pipe($.jshint.reporter())
        .pipe($.jshint.reporter(stylish))
        .pipe($.jshint.reporter('fail'));
});

gulp.task('gitbook:clean', ['lint:jslint'], function(){
    ffs.rmdirRecursiveSync('site');
    ffs.rmdirRecursiveSync('book/apis');
    ffs.rmdirRecursiveSync('book/modules');
    mkdirp('book/apis');
    mkdirp('book/modules');
    mkdirp('site');
});

gulp.task('gitbook:build', ['gitbook:clean'], function() {
    ffs.readdirSync(base + 'swagger').forEach(function(file){
        var api = YAML.parse(fs.readFileSync(base + 'swagger/' + file, 'utf-8'));
        var md = _.template(swaggerTpl)(api);
        fs.writeFileSync(base + 'book/apis/' + file.replace('\.yml', '.md'), md);
    });
});

gulp.task('gitbook:install', ['gitbook:build'], function(){
    var book = new Book('book');
    return book.config.load().then(function() {
        return book.plugins.install();
    });
});

gulp.task('gitbook:generate', ['gitbook:install'], function(){
    var book = new Book('book');
    return book.parse().then(function() {
        return book.generate('website');
    });
});

gulp.task('gitbook:deploy', function(){
    var isOnMaster = false;
    if(isOnMaster) {
        return gulp.src('site/**/*')
            .pipe($.ghPages());
    }
});

gulp.task('gitbook', ['gitbook:generate']);
gulp.task('default', ['gitbook']);
