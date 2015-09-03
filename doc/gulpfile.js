'use strict';

var fs = require('fs');
var ffs = require('final-fs');
var gulp = require('gulp');
var Book = require('gitbook').Book;
var $ = require('gulp-load-plugins')();
var YAML = require('yamljs');
var _ = require('lodash');

var base = '';
var swaggerTpl = fs.readFileSync(base + 'templates/api.md.tpl', 'utf-8');

gulp.task('gitbook:generate-modules', function(){
    ffs.readdirSync(base + 'swagger').forEach(function(file){
        var api = YAML.parse(fs.readFileSync(base + 'swagger/' + file, 'utf-8'));
        console.log(JSON.stringify(api, null, 2));
        var md = _.template(swaggerTpl)(api);
        console.log(md);
    });
});

gulp.task('gitbook:generate-apis', function(){

});

gulp.task('gitbook:install', ['gitbook:generate-apis', 'gitbook:generate-modules'], function(){
    var book = new Book(base);
    return book.config.load().then(function() {
        return book.plugins.install();
    });
});

gulp.task('gitbook:generate', ['gitbook:install'], function(){
    ffs.rmdirRecursiveSync('site');
    var book = new Book(base);
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
