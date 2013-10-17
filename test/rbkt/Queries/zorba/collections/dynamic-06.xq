import module namespace ddl = "http://zorba.io/modules/store/dynamic/collections/ddl";
import module namespace dml = "http://zorba.io/modules/store/dynamic/collections/dml";

ddl:create(xs:QName("ddl:test2"),(<center1/>,<oldlast/>));

dml:insert-first(xs:QName("ddl:test2"), (<c1/>,<c2/>));

dml:truncate(xs:QName("ddl:test2"));

count(dml:collection(xs:QName("ddl:test2")))
