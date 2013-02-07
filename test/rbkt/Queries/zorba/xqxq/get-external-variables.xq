import module namespace xqxq = 'http://www.zorba-xquery.com/modules/xqxq';
variable $query-key2 := xqxq:prepare-main-module('declare variable $c external; $c');
variable $query-key := xqxq:prepare-main-module('declare variable $a external;declare variable $d := "hi"; $a');                                                
xqxq:external-variables($query-key)