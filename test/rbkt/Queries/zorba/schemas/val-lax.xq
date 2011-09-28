import schema namespace 
  s = "http://www.zorba-xquery.com/simple.xsd" 
  at "simple.xsd";

validate lax
{
    <a xmlns='http://www.zorba-xquery.com/simple.xsd'>
    	<b>p1</b>
    	<c>1</c>
    	<!--this is a comment -->
    </a>
}
