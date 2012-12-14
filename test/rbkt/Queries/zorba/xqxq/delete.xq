import module namespace xqxq = 'http://www.zorba-xquery.com/modules/xqxq';

variable $query-key := xqxq:prepare-main-module("1+1");
xqxq:delete-query($query-key);
xqxq:evaluate($query-key)
