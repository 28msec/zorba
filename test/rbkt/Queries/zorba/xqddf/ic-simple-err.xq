import module namespace m = 'xqueryzorba.org/test/xqddf/ic' at 'ic.xqlib';
import module namespace ddl = "http://www.zorba-xquery.com/modules/store/static/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/static/collections/dml";
import module namespace ic_ddl = "http://www.zorba-xquery.com/modules/store/static/integrity_constraints/ddl";



ddl:create($m:empc);  

ic_ddl:activate(xs:QName("m:ic_simple"));


(: employees - all values inserted in a single update, 
   but m:ic_simple still fails 
:)
dml:insert-nodes($m:empc, 
   <emp>
     <salary>100</salary>
   </emp>
  )
,
dml:insert-nodes($m:empc, 
   <emp>
     <salary>600</salary>
   </emp>
  )


