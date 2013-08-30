import module namespace zq = 'http://zorba.io/modules/zorba-query';
variable $query-key := zq:prepare-main-module('declare variable $a external; $a');
zq:bind-variable($query-key,xs:QName('a'),"foo");
zq:is-bound-variable($query-key, xs:QName('a'))