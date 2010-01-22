import module namespace m = 'xqueryzorba.org/test/xqddf/ic' at 'ic.xqlib';
import module namespace xqddf = "http://www.zorba-xquery.com/modules/xqddf";



xqddf:create-collection($m:empc);  

xqddf:activate-integrity-constraint(xs:QName("m:ic_simple"));


(: employees - even if element salary is missing in one collection item 
   m:ic_simple holds 
:)
xqddf:insert-nodes($m:empc, 
   <emp>
     <!-- no salary element -->
   </emp>
  ),

xqddf:insert-nodes($m:empc, 
   <emp>
     <salary>600</salary>
   </emp>
  ),

xqddf:insert-nodes($m:empc, 
   <emp>
     <salary>700</salary>
   </emp>
  );

sum( xqddf:collection($m:empc)/salary ),
sum( xqddf:collection($m:empc)/salary ) gt 1000;