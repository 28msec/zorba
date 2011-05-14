import module namespace m = 'xqueryzorba.org/test/xqddf/ic' at 'ic.xqlib';
import module namespace init = "http://www.zorba-xquery.com/modules/store/static-collections/initialization";
import module namespace manip = "http://www.zorba-xquery.com/modules/store/static-collections/manipulation";



init:create-collection($m:empc);  

init:activate-integrity-constraint(xs:QName("m:ic_simple"));

{
(: employees - even if element salary is missing in one collection item 
   m:ic_simple holds 
:)
manip:insert-nodes($m:empc, 
   <emp>
     <!-- no salary element -->
   </emp>
  ),

manip:insert-nodes($m:empc, 
   <emp>
     <salary>600</salary>
   </emp>
  ),

manip:insert-nodes($m:empc, 
   <emp>
     <salary>700</salary>
   </emp>
  )
};

sum( manip:collection($m:empc)/salary ),
sum( manip:collection($m:empc)/salary ) gt 1000
