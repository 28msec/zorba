import module namespace m = 'xqueryzorba.org/test/xqddf/ic' at 'ic.xqlib';
import module namespace ddl = "http://www.zorba-xquery.com/modules/store/static/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/static/collections/dml";
import module namespace ic_ddl = "http://www.zorba-xquery.com/modules/store/static/integrity_constraints/ddl";



ddl:create($m:empc);  
ddl:create($m:trnc);  

ic_ddl:activate(xs:QName("m:ic_foreignKey"));


(: employees :)
dml:insert-nodes($m:empc, 
   <emp>
     <id>1</id>
   </emp>
  )
,
dml:insert-nodes($m:empc, 
   <emp>
     <id>2</id>
   </emp>
  )
,
dml:insert-nodes($m:empc, 
   <emp>
     <id>3</id>
   </emp>
  ),

(: transactions :)
(: not all empids have corespondent in employees/id - m:ic_foreignKey fails :)
dml:insert-nodes($m:trnc, 
   <sale>
     <empid>1</empid>
   </sale>
  ),

dml:insert-nodes($m:trnc, 
   <sale>
     <empid>2</empid>
   </sale>
  )
,
dml:insert-nodes($m:trnc, 
   <sale>
     <empid>100</empid>
   </sale>
  ),


<emps>{ fn:data(dml:collection($m:empc)/id ) }</emps>
,
<sales>{ fn:data(dml:collection($m:trnc)/empid ) }</sales>
,
every $x in dml:collection($m:trnc) 
       satisfies
         some $y in dml:collection($m:empc)
         satisfies $y/id eq $x/empid

