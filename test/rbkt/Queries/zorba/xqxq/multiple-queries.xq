import module namespace xqxq = 'http://www.zorba-xquery.com/modules/xqxq';

variable $query-key1 := xqxq:prepare-main-module("1+1");
variable $query-key2 := xqxq:prepare-main-module("1+2");
variable $a := xqxq:evaluate($query-key1);
variable $b := xqxq:evaluate($query-key2);
xqxq:delete-query($query-key1);
xqxq:delete-query($query-key2);
$a, $b
