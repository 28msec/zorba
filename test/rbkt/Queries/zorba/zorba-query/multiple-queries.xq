import module namespace zq = 'http://zorba.io/modules/zorba-query';

variable $query-key1 := zq:prepare-main-module("1+1");
variable $query-key2 := zq:prepare-main-module("1+2");
variable $a := zq:evaluate($query-key1);
variable $b := zq:evaluate($query-key2);
zq:delete-query($query-key1);
zq:delete-query($query-key2);
$a, $b
