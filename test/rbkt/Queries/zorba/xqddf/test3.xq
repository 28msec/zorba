import module namespace init = "http://www.zorba-xquery.com/modules/store/static-collections/initialization";
import module namespace manip = "http://www.zorba-xquery.com/modules/store/static-collections/manipulation";

import module namespace test3 = "www.test3.com" at "test3.xqlib";

declare variable $foo := xs:QName("test3:foo");
declare variable $idx := xs:QName("test3:idx");


init:create-collection($foo);

manip:insert-nodes($foo, doc("test3.xml"));

init:create-index($idx);

manip:probe-index-point-value($idx, xs:long(68000));
