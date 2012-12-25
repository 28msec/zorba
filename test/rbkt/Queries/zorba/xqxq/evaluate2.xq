import module namespace xqxq = 'http://www.zorba-xquery.com/modules/xqxq';

variable $query-key := xqxq:prepare-main-module("declare variable $a external; $a+1");
xqxq:bind-variable($query-key, xs:QName("a"), 1);
variable $b := xqxq:evaluate($query-key);
$b
