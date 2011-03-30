import module namespace m = 'xqueryzorba.org/test/xqddf/ic' at 'ic.xqlib';
import module namespace init = "http://www.zorba-xquery.com/modules/store/static-collections/initialization";
import module namespace manip = "http://www.zorba-xquery.com/modules/store/static-collections/manipulation";



init:create-collection($m:empc);  

init:activate-integrity-constraint(xs:QName("m:ic_uniqueKey"));


(: employees :)
manip:insert-nodes($m:empc, 
   <emp>
     <id>1</id>
   </emp>
  )
,
manip:insert-nodes($m:empc, 
   <emp>
     <id>2</id>
   </emp>
  )
,
manip:insert-nodes($m:empc, 
   <emp>
     <id>1</id>
   </emp>
  );

fn:data(manip:collection($m:empc)/id)
,
let $ids := manip:collection($m:empc)/id 
return fn:count( $ids ) eq fn:count( fn:distinct-values( $ids ) );
