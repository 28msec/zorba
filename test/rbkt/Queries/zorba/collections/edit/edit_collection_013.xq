import module namespace ddl = "http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/dynamic/collections/dml";

ddl:create(xs:QName("dml:collection"));

dml:insert-first(xs:QName("dml:collection"), document { <a b="c"><!-- d --><?e f?>g</a> } );

dml:edit(dml:collection(xs:QName("dml:collection")), document { <b c="d"><!-- e --><?f g?>h</b> });

dml:collection(xs:QName("dml:collection"))
