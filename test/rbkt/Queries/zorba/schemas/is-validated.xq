import schema namespace s = "http://www.zorba-xquery.org/schema" at "simple2.xsd";

import module namespace schema = "http://www.zorba-xquery.com/modules/schema";

for $x in (validate strict { 
               <s:person>
                 <s:name>david</s:name>
                 <s:age>123</s:age>
               </s:person> 
           }, <s:person>
                <s:name>david</s:name>
                <age>123</age>
              </s:person>)
return schema:is-validated($x)



