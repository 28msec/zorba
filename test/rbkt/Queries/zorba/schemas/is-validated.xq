import schema namespace s = "http://www.zorba-xquery.org/schema" at "simple2.xsd";

import module namespace schema = "http://www.zorba-xquery.com/modules/schema";

declare namespace ann = "http://www.zorba-xquery.com/annotations";

declare variable $var := ();

declare function local:simple()
{
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
};

declare function local:nested()
{
  for $x in (validate strict { 
                 <s:person>
                   <s:name>david</s:name>
                   <s:age>123</s:age>
                 </s:person> 
             }, <s:person>
                  <s:name>david</s:name>
                  <age>123</age>
                </s:person>)
  return schema:is-validated($x/s:name)
};

declare %ann:sequential function local:update()
{
  $var := validate strict { 
                 <s:person>
                   <s:name>david</s:name>
                   <s:age>123</s:age>
                 </s:person> 
              };
  delete node $var/s:age;
  schema:is-validated($var)
};

local:simple(), local:nested(), local:update()

