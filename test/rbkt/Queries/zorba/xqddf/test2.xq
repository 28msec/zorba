import module namespace init = "http://www.zorba-xquery.com/modules/store/static-collections/initialization";
import module namespace manip = "http://www.zorba-xquery.com/modules/store/static-collections/manipulation";

import module namespace test2 = "www.test2.com" at "test2.xqlib";

declare variable $foo := xs:QName("test2:foo");
declare variable $idx := xs:QName("test2:idx");


init:create-collection($foo);

manip:insert-nodes($foo, doc("test2.xml"));

init:create-index($idx);

manip:probe-index-point-value($idx, xs:long(501321));


