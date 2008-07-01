import schema namespace 
  s = "simple.xsd" 
  at "simple.xsd";

validate strict
{
    <product xmlns='simple.xsd'>
    	<name>p1</name>
    	<number>1</number>
    	<!--this is a comment -->
    </product>
}
