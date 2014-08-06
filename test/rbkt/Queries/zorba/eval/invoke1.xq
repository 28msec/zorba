import module namespace invoke = 'http://zorba.io/modules/reflection';

import module namespace foo1 = "http://foo1.com/" at "invoke1_1.xqlib";

invoke:invoke-s ( fn:QName ( 'http://foo1.com/', 'bar' ) )
