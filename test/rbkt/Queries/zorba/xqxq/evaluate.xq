import module namespace xqxq = 'http://www.zorba-xquery.com/modules/xqxq';

variable $query-key := xqxq:prepare-main-module("1+1");
variable $a := xqxq:evaluate($query-key);
$a
