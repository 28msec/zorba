import schema namespace 
  s = "simple.xsd" 
  at "simple.xsd";

validate lax
{
    <a xmlns='simple.xsd'>
    	<b>p1</b>
    	<c>1</c>
    	<!--this is a comment -->
    </a>
}
