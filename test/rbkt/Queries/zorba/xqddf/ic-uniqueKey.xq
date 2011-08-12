import module namespace m = 'xqueryzorba.org/test/xqddf/ic' at 'ic.xqlib';
import module namespace ddl = "http://www.zorba-xquery.com/modules/store/static/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/static/collections/dml";
import module namespace ic_ddl = "http://www.zorba-xquery.com/modules/store/static/integrity_constraints/ddl";



ddl:create($m:empc);  

ic_ddl:activate(xs:QName("m:ic_uniqueKey"));

{
(: employees :)
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
};

dml:insert-nodes($m:empc, 
   <emp>
     <id>3</id>
   </emp>
  );

fn:data(dml:collection($m:empc)/id)
,
let $ids := dml:collection($m:empc)/id 
return fn:count( $ids ) eq fn:count( fn:distinct-values( $ids ) )
