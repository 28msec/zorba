import module namespace m = 'xqueryzorba.org/test/xqddf/ic' at 'ic.xqlib';
import module namespace ddl = "http://www.zorba-xquery.com/modules/store/static/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/static/collections/dml";
import module namespace ic_ddl = "http://www.zorba-xquery.com/modules/store/static/integrity_constraints/ddl";

ddl:create($m:empc);
(
ic_ddl:activate(xs:QName("m:ic_simple")),
ic_ddl:activate(xs:QName("m:ic_simple")) 
);

"OK"