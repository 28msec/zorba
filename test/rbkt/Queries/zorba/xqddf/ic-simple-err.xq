import module namespace m = 'xqueryzorba.org/test/xqddf/ic' at 'ic.xqlib';
import module namespace xqddf = "http://www.zorba-xquery.com/modules/xqddf";



xqddf:create-collection($m:empc);  

xqddf:activate-integrity-constraint(xs:QName("m:ic_simple"));


(: employees - all values inserted in a single update, 
   but m:ic_simple still fails 
:)
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
;

