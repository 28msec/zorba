import schema namespace s = "http://www.zorba-xquery.org/schema" 
	at "simple2.xsd";

validate lax 
{ 
  <s:person>
    <s:name>david</s:name>
    <age>123</age>
  </s:person> 
}


