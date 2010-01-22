import module namespace m = 'xqueryzorba.org/test/xqddf/ic' at 'ic.xqlib';
import module namespace xqddf = "http://www.zorba-xquery.com/modules/xqddf";



xqddf:create-collection($m:empc);  

xqddf:activate-integrity-constraint(xs:QName("m:ic_forEachNode"));


(: employees - m:ic_forEachNode holds :)
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
     <id>3</id>
   </emp>
  );

fn:data( xqddf:collection($m:empc)/id ),
every $id in xqddf:collection($m:empc)/id 
satisfies $id > 0;