import module namespace ddl = "http://www.zorba-xquery.com/modules/store/static/collections/ddl";
import module namespace index_ddl = "http://www.zorba-xquery.com/modules/store/static/indexes/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/static/collections/dml";
import module namespace index_dml = "http://www.zorba-xquery.com/modules/store/static/indexes/dml";

import module namespace test2 = "www.test2.com" at "test2.xqlib";

declare variable $foo := xs:QName("test2:foo");
declare variable $idx := xs:QName("test2:idx");


ddl:create($foo);

dml:insert-nodes($foo, doc("test2.xml"));

index_ddl:create($idx);

index_dml:probe-index-point-value($idx, xs:long(501321))
