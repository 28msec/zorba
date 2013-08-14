import module namespace zq = 'http://zorba.io/modules/zorba-query';

variable $query-key := zq:prepare-main-module("1+1");
zq:delete-query($query-key);
zq:evaluate($query-key)
