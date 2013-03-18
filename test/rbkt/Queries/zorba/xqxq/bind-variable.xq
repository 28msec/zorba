import module namespace xqxq = 'http://www.zorba-xquery.com/modules/xqxq';
variable $query-key := xqxq:prepare-main-module('declare variable $a external; $a');
xqxq:bind-variable($query-key,xs:QName('a'),"foo");
xqxq:is-bound-variable($query-key, xs:QName('a'))