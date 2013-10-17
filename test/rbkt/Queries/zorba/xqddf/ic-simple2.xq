import module namespace m = 'xqueryzorba.org/test/xqddf/ic' at 'ic.xqlib';
import module namespace ddl = "http://zorba.io/modules/store/static/collections/ddl";
import module namespace dml = "http://zorba.io/modules/store/static/collections/dml";
import module namespace ic_ddl = "http://zorba.io/modules/store/static/integrity-constraints/ddl";



ddl:create($m:empc);  

ic_ddl:activate(xs:QName("m:ic_simple"));

{
(: employees - even if element salary is missing in one collection item 
   m:ic_simple holds 
:)
dml:insert($m:empc, 
   <emp>
     <!-- no salary element -->
   </emp>
  ),

dml:insert($m:empc, 
   <emp>
     <salary>600</salary>
   </emp>
  ),

dml:insert($m:empc, 
   <emp>
     <salary>700</salary>
   </emp>
  )
};

sum( dml:collection($m:empc)/salary ),
sum( dml:collection($m:empc)/salary ) gt 1000
