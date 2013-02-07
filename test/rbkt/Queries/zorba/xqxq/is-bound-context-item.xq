import module namespace xqxq = 'http://www.zorba-xquery.com/modules/xqxq';

variable $query-key := xqxq:prepare-main-module("insert node <child/> into /parent");  
xqxq:is-bound-context-item($query-key)
