import module namespace zq = 'http://zorba.io/modules/zorba-query';

variable $queryID := zq:prepare-main-module("1+1");
variable $query-plan := zq:query-plan($queryID); 
variable $queryID2 := zq:load-from-query-plan($query-plan);
zq:evaluate ($queryID2)
