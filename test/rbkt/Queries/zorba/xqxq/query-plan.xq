import module namespace xqxq = 'http://www.zorba-xquery.com/modules/xqxq';

variable $queryID := xqxq:prepare-main-module("1+1");
variable $query-plan := xqxq:query-plan($queryID); 
variable $queryID2 := xqxq:load-from-query-plan($query-plan);
xqxq:evaluate ($queryID2)
