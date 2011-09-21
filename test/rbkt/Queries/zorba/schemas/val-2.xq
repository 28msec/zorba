import schema namespace 
  s = "http://www.zorba-xquery.com/simple.xsd" 
  at "simple.xsd";

validate strict
{
    <product xmlns='http://www.zorba-xquery.com/simple.xsd'>
    	<name>p1</name>
    	<number>1</number>
    	<!--this is a comment -->
    </product>
}
