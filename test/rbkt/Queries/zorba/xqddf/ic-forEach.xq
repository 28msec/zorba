import module namespace m = 'xqueryzorba.org/test/xqddf/ic' at 'ic.xqlib';
import module namespace init = "http://www.zorba-xquery.com/modules/store/static-collections/initialization";
import module namespace manip = "http://www.zorba-xquery.com/modules/store/static-collections/manipulation";



init:create-collection($m:empc);  

init:activate-integrity-constraint(xs:QName("m:ic_forEachNode"));


(: employees - m:ic_forEachNode holds :)
manip:insert-nodes($m:empc, 
   <emp>
     <id>1</id>
   </emp>
  )
,
manip:insert-nodes($m:empc, 
   <emp>
     <id>2</id>
   </emp>
  )
,
manip:insert-nodes($m:empc, 
   <emp>
     <id>3</id>
   </emp>
  );

fn:data( manip:collection($m:empc)/id ),
every $id in manip:collection($m:empc)/id 
satisfies $id > 0;
