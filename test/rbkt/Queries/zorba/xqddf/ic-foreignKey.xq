import module namespace m = 'xqueryzorba.org/test/xqddf/ic' at 'ic.xqlib';
import module namespace xqddf = "http://www.zorba-xquery.com/modules/xqddf";



xqddf:create-collection($m:empc);  
xqddf:create-collection($m:trnc);  

xqddf:activate-integrity-constraint(xs:QName("m:ic_foreignKey"));


(: employees :)
xqddf:insert-nodes($m:empc, 
   <emp>
     <id>1</id>
     <salary>300</salary>
   </emp>
  )
,
xqddf:insert-nodes($m:empc, 
   <emp>
     <id>2</id>
     <salary>400</salary>
   </emp>
  )
,
xqddf:insert-nodes($m:empc, 
   <emp>
     <id>3</id>
     <salary>600</salary>
   </emp>
  );

(: transactions :)
(: all empids have corespondent in employees/id - m:ic_foreignKey holds :)
xqddf:insert-nodes($m:trnc, 
   <sale>
     <empid>1</empid>
   </sale>
  );

xqddf:insert-nodes($m:trnc, 
   <sale>
     <empid>2</empid>
   </sale>
  );

xqddf:insert-nodes($m:trnc, 
   <sale>
     <empid>1</empid>
   </sale>
  );


<emps>{ fn:data(xqddf:collection($m:empc)/id ) }</emps>
,
<sales>{ fn:data(xqddf:collection($m:trnc)/empid ) }</sales>
,
every $x in xqddf:collection($m:trnc) 
       satisfies
         some $y in xqddf:collection($m:empc)
         satisfies $y/id eq $x/empid
;