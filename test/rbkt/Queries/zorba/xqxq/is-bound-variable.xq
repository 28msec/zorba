import module namespace xqxq = 'http://www.zorba-xquery.com/modules/xqxq';
variable $query-key := xqxq:prepare-main-module('
  declare variable $a external;
  declare variable $b external := 2;
  declare variable $c external;
  $a');
xqxq:bind-variable($query-key, xs:QName('a'), "foo");
xqxq:is-bound-variable($query-key, xs:QName('a')),
xqxq:is-bound-variable($query-key, xs:QName('b')),
xqxq:is-bound-variable($query-key, xs:QName('c'))