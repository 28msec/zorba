import module namespace ddl = "http://zorba.io/modules/store/static/collections/ddl";
import module namespace dml = "http://zorba.io/modules/store/static/collections/dml";
import module namespace index_ddl = "http://zorba.io/modules/store/static/indexes/ddl";
import module namespace index_dml = "http://zorba.io/modules/store/static/indexes/dml";

import module namespace test3 = "www.test3.com" at "test3.xqlib";

declare variable $foo := xs:QName("test3:foo");
declare variable $idx := xs:QName("test3:idx");


ddl:create($foo);

dml:insert($foo, doc("test3.xml"));

index_ddl:create($idx);

index_dml:probe-index-point-value($idx, xs:long(68000))
