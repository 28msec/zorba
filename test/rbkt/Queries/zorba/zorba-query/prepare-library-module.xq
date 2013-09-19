import module namespace zq = 'http://zorba.io/modules/zorba-query';

zq:prepare-library-module('module namespace foo = "foo:bar"; declare function foo:bar() { 1 }')
