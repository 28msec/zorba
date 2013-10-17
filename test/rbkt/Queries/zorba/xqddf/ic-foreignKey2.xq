import module namespace m = 'xqueryzorba.org/test/xqddf/ic' at 'ic.xqlib';
import module namespace ddl = "http://zorba.io/modules/store/static/collections/ddl";
import module namespace dml = "http://zorba.io/modules/store/static/collections/dml";
import module namespace ic_ddl = "http://zorba.io/modules/store/static/integrity-constraints/ddl";

ddl:create($m:empc);  
ddl:create($m:trnc);  

(
ic_ddl:activate(xs:QName("m:ic_foreignKey")),
ic_ddl:activate(xs:QName("m:ic_foreignKey"))
);

"OK"
