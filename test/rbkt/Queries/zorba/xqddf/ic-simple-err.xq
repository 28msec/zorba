import module namespace m = 'xqueryzorba.org/test/xqddf/ic' at 'ic.xqlib';
import module namespace ddl = "http://zorba.io/modules/store/static/collections/ddl";
import module namespace dml = "http://zorba.io/modules/store/static/collections/dml";
import module namespace ic_ddl = "http://zorba.io/modules/store/static/integrity-constraints/ddl";



ddl:create($m:empc);  

ic_ddl:activate(xs:QName("m:ic_simple"));


(: employees - all values inserted in a single update, 
   but m:ic_simple still fails 
:)
dml:insert($m:empc, 
   <emp>
     <salary>100</salary>
   </emp>
  )
,
dml:insert($m:empc, 
   <emp>
     <salary>600</salary>
   </emp>
  )
