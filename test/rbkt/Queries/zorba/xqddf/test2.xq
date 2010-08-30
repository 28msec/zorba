
import module namespace xqddf = "http://www.zorba-xquery.com/modules/xqddf";

import module namespace test2 = "www.test2.com" at "test2.xqlib";

declare variable $foo := xs:QName("test2:foo");
declare variable $idx := xs:QName("test2:idx");


xqddf:create-collection($foo);

xqddf:insert-nodes($foo, doc("test2.xml"));

xqddf:create-index($idx);

xqddf:probe-index-point-value($idx, xs:long(501321));


