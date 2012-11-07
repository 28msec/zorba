import module namespace xqxq = 'http://www.zorba-xquery.com/modules/xqxq';
variable $query-key := xqxq:prepare-main-module('
  declare variable $a external;
  declare variable $b external := 2;
  declare variable $c external;
  $a');
xqxq:is-bound-variable($query-key, xs:QName('x'))