import module namespace zq = 'http://zorba.io/modules/zorba-query';

variable $query-key := zq:prepare-main-module("insert node <child/> into /parent");  
zq:is-bound-context-item($query-key)
