import module namespace ddl = "http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/dynamic/collections/dml";

ddl:create(xs:QName("ddl:coll"),(<a/>,<b/>));
(
ddl:delete(xs:QName("ddl:coll")),
ddl:delete(xs:QName("ddl:coll"))
);

"OK"