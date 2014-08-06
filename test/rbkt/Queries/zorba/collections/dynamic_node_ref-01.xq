import module namespace ddl = "http://zorba.io/modules/store/dynamic/collections/ddl";
import module namespace dml = "http://zorba.io/modules/store/dynamic/collections/dml";
import module namespace ref = "http://zorba.io/modules/reference";

ddl:create(xs:QName("ddl:bar"));
let $x := dml:apply-insert-last(xs:QName("ddl:bar"), <a>1</a>)
return ref:dereference(ref:reference($x))
