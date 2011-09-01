import module namespace ddl = "http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/dynamic/collections/dml";
import module namespace ref = "http://www.zorba-xquery.com/modules/node-reference";

ddl:create(xs:QName("ddl:bar"));
let $x := dml:apply-insert-nodes-last(xs:QName("ddl:bar"), <a>1</a>)
return ref:node-by-reference(ref:node-reference($x))
