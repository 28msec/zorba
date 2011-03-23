import module namespace v = "http://www.zorba-xquery.com/modules/schema";

import schema namespace s = "http://www.w3.org/XQueryTest/val-inplace" 
  at "val-inplace.xsd"; 

copy $d := <s:ii>
             <s:int>seven</s:int>
           </s:ii>
modify ( 
    v:validate-in-place($d) 
 )
return v:schema-type($d/s:int) 


