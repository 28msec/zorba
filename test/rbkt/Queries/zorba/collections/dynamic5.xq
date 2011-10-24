import module namespace ddl = "http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/dynamic/collections/dml";

ddl:create(xs:QName("ddl:test2"),(<center1/>,<oldlast/>));

dml:insert-nodes-first(xs:QName("ddl:test2"), (<c1/>,<c2/>));
dml:collection(xs:QName("ddl:test2"))/self::node()