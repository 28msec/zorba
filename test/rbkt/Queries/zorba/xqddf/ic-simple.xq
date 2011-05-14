import module namespace m = 'xqueryzorba.org/test/xqddf/ic' at 'ic.xqlib';
import module namespace init = "http://www.zorba-xquery.com/modules/store/static-collections/initialization";
import module namespace manip = "http://www.zorba-xquery.com/modules/store/static-collections/manipulation";



init:create-collection($m:empc);  

init:activate-integrity-constraint(xs:QName("m:ic_simple"));

{
(: employees - all values inserted in a single update, m:ic_simple holds :)
manip:insert-nodes($m:empc, 
   <emp>
     <salary>100</salary>
   </emp>
  )
,
manip:insert-nodes($m:empc, 
   <emp>
     <salary>600</salary>
   </emp>
  )
,
manip:insert-nodes($m:empc, 
   <emp>
     <salary>400</salary>
   </emp>
  )
};

sum( manip:collection($m:empc)/salary ),
sum( manip:collection($m:empc)/salary ) gt 1000
