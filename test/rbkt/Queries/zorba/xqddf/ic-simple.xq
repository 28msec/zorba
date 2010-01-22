import module namespace m = 'xqueryzorba.org/test/xqddf/ic' at 'ic.xqlib';
import module namespace xqddf = "http://www.zorba-xquery.com/modules/xqddf";



xqddf:create-collection($m:empc);  

xqddf:activate-integrity-constraint(xs:QName("m:ic_simple"));


(: employees - all values inserted in a single update, m:ic_simple holds :)
xqddf:insert-nodes($m:empc, 
   <emp>
     <salary>100</salary>
   </emp>
  )
,
xqddf:insert-nodes($m:empc, 
   <emp>
     <salary>600</salary>
   </emp>
  )
,
xqddf:insert-nodes($m:empc, 
   <emp>
     <salary>400</salary>
   </emp>
  );

sum( xqddf:collection($m:empc)/salary ),
sum( xqddf:collection($m:empc)/salary ) gt 1000;