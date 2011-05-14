import module namespace m = 'xqueryzorba.org/test/xqddf/ic' at 'ic.xqlib';
import module namespace init = "http://www.zorba-xquery.com/modules/store/static-collections/initialization";
import module namespace manip = "http://www.zorba-xquery.com/modules/store/static-collections/manipulation";



init:create-collection($m:empc);  

init:activate-integrity-constraint(xs:QName("m:ic_simple"));


(: employees - all values inserted in a single update, 
   but m:ic_simple still fails 
:)
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


