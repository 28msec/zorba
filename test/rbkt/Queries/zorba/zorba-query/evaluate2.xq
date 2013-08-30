import module namespace zq = 'http://zorba.io/modules/zorba-query';

variable $query-key := zq:prepare-main-module("declare variable $a external; $a+1");
zq:bind-variable($query-key, xs:QName("a"), 1);
variable $b := zq:evaluate($query-key);
$b
