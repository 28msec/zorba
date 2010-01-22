import module namespace m = 'xqueryzorba.org/test/xqddf/ic' at 'ic.xqlib';
import module namespace xqddf = "http://www.zorba-xquery.com/modules/xqddf";



xqddf:create-collection($m:empc);  

xqddf:activate-integrity-constraint(xs:QName("m:ic_uniqueKey"));


(: employees :)
xqddf:insert-nodes($m:empc, 
   <emp>
     <id>1</id>
   </emp>
  )
,
xqddf:insert-nodes($m:empc, 
   <emp>
     <id>2</id>
   </emp>
  )
,
xqddf:insert-nodes($m:empc, 
   <emp>
     <id>1</id>
   </emp>
  );

fn:data(xqddf:collection($m:empc)/id)
,
let $ids := xqddf:collection($m:empc)/id 
return fn:count( $ids ) eq fn:count( fn:distinct-values( $ids ) );
