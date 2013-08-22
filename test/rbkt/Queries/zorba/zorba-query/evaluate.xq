import module namespace zq = 'http://zorba.io/modules/zorba-query';

variable $query-key := zq:prepare-main-module("1+1");
variable $a := zq:evaluate($query-key);
$a
