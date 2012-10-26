import module namespace xqxq = 'http://www.zorba-xquery.com/modules/xqxq';

variable $query-key := xqxq:prepare-main-module('
    import module namespace r = "http://www.zorba-xquery.com/modules/random";

    count((for $i in 1 to 10 return r:random(10), r:random())) eq 101
    ');
xqxq:evaluate($query-key)