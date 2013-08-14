import module namespace zq = 'http://zorba.io/modules/zorba-query';
variable $query-key := zq:prepare-main-module('
  declare variable $a external;
  declare variable $b external := 2;
  declare variable $c external;
  $a');
zq:is-bound-variable($query-key, xs:QName('x'))