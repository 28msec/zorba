xquery version '3.0';

import module namespace invoke = 'http://zorba.io/modules/reflection';

import module namespace foo = "http://foo.com/" at "${CMAKE_CURRENT_BINARY_DIR}/module4.xq";

declare variable $local:function as xs:string external := "foo";

1+1
