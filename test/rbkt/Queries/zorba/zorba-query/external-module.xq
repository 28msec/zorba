import module namespace zq = 'http://zorba.io/modules/zorba-query';

variable $query-key := zq:prepare-main-module('
    import module namespace r = "http://zorba.io/modules/random";

    count((for $i in 1 to 10 return r:random(10), r:random())) eq 101
    ');
zq:evaluate($query-key)