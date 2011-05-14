import module namespace m = 'xqueryzorba.org/test/xqddf/ic' at 'ic.xqlib';
import module namespace init = "http://www.zorba-xquery.com/modules/store/static-collections/initialization";
import module namespace manip = "http://www.zorba-xquery.com/modules/store/static-collections/manipulation";



init:create-collection($m:empc);  
init:create-collection($m:trnc);  

init:activate-integrity-constraint(xs:QName("m:ic_foreignKey"));


(: employees :)
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
  ),

(: transactions :)
(: not all empids have corespondent in employees/id - m:ic_foreignKey fails :)
manip:insert-nodes($m:trnc, 
   <sale>
     <empid>1</empid>
   </sale>
  ),

manip:insert-nodes($m:trnc, 
   <sale>
     <empid>2</empid>
   </sale>
  )
,
manip:insert-nodes($m:trnc, 
   <sale>
     <empid>100</empid>
   </sale>
  ),


<emps>{ fn:data(manip:collection($m:empc)/id ) }</emps>
,
<sales>{ fn:data(manip:collection($m:trnc)/empid ) }</sales>
,
every $x in manip:collection($m:trnc) 
       satisfies
         some $y in manip:collection($m:empc)
         satisfies $y/id eq $x/empid

