import module namespace m = 'xqueryzorba.org/test/xqddf/ic' at 'ic.xqlib';
import module namespace ddl = "http://zorba.io/modules/store/static/collections/ddl";
import module namespace dml = "http://zorba.io/modules/store/static/collections/dml";
import module namespace ic_ddl = "http://zorba.io/modules/store/static/integrity-constraints/ddl";

ddl:create($m:empc);
ic_ddl:activate(xs:QName("m:ic_simple"));

(
ic_ddl:deactivate(xs:QName("m:ic_simple")),
ic_ddl:deactivate(xs:QName("m:ic_simple")) 
);

"OK"
