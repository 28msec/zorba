import module namespace xqddf = "http://www.zorba-xquery.com/modules/xqddf";

import module namespace test3 = "www.test3.com" at "test3.xqlib";

declare variable $foo := xs:QName("test3:foo");
declare variable $idx := xs:QName("test3:idx");


xqddf:create-collection($foo);

xqddf:insert-nodes($foo, doc("test3.xml"));

xqddf:create-index($idx);

xqddf:probe-index-point($idx, xs:long(68000));
