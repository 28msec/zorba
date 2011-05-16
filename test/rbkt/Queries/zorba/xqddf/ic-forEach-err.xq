import module namespace m = 'xqueryzorba.org/test/xqddf/ic' at 'ic.xqlib';
import module namespace ddl = "http://www.zorba-xquery.com/modules/store/static/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/static/collections/dml";
import module namespace ic_ddl = "http://www.zorba-xquery.com/modules/store/static/integrity_constraints/ddl";



ddl:create-collection($m:empc);  

ic_ddl:activate-integrity-constraint(xs:QName("m:ic_forEachNode"));


(: employees - m:ic_forEachNode fails :)
dml:insert-nodes($m:empc, 
   <emp>
     <id>1</id>
   </emp>
  )
,
dml:insert-nodes($m:empc, 
   <emp>
     <id>2</id>
   </emp>
  )
,
dml:insert-nodes($m:empc, 
   <emp>
     <id>0</id>
   </emp>
  ),

fn:data( dml:collection($m:empc)/id ),
every $id in dml:collection($m:empc)/id 
satisfies $id > 0
