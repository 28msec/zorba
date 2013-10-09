import module namespace v = "http://zorba.io/modules/schema";

import schema namespace s = "http://www.w3.org/XQueryTest/val-inplace" 
  at "val-inplace.xsd"; 

copy $d := <s:dd>
             <s:d>P1D</s:d>
           </s:dd>
modify ( 
    v:validate-in-place($d) 
 )
return v:schema-type($d) 


