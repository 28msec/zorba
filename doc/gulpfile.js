'use strict';

var ffs = require('final-fs');
var gulp = require('gulp');
var Book = require('gitbook').Book;
var $ = require('gulp-load-plugins')();

var base = '';

gulp.task('gitbook:install', function(){
    var book = new Book('');
    return book.config.load().then(function() {
        return book.plugins.install();
    });
});

gulp.task('gitbook:generate', ['gitbook:install'], function(){
    ffs.rmdirRecursiveSync('site');
    var book = new Book('');
    return book.parse().then(function() {
        return book.generate('website');
    });
});

gulp.task('gitbook:deploy', function(){
    if(Config.isOnMaster) {
        return gulp.src('site/**/*')
            .pipe($.ghPages());
    }
});

gulp.task('gitbook', ['gitbook:generate']);
gulp.task('default', ['gitbook']);
