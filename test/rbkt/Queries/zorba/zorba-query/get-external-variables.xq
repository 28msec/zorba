import module namespace zq = 'http://zorba.io/modules/zorba-query';
variable $query-key2 := zq:prepare-main-module('declare variable $c external; $c');
variable $query-key := zq:prepare-main-module('declare variable $a external;declare variable $d := "hi"; $a');                                                
zq:external-variables($query-key)