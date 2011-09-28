import schema namespace s = "http://www.zorba-xquery.org/schema" 
	at "simple2.xsd";

validate lax 
{ 
  <s:person2 age="123">
    <s:name>david</s:name>
  </s:person2> 
}


