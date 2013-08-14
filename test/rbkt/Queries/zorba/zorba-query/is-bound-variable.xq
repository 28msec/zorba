import module namespace zq = 'http://zorba.io/modules/zorba-query';
variable $query-key := zq:prepare-main-module('
  declare variable $a external;
  declare variable $b external := 2;
  declare variable $c external;
  $a');
zq:bind-variable($query-key, xs:QName('a'), "foo");
zq:is-bound-variable($query-key, xs:QName('a')),
zq:is-bound-variable($query-key, xs:QName('b')),
zq:is-bound-variable($query-key, xs:QName('c')),
zq:variable-value($query-key, xs:QName('a'))
