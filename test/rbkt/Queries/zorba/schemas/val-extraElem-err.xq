import schema namespace 
  s = "http://www.zorba-xquery.com/simple.xsd" 
  at "simple.xsd";

validate 
{
    <product xmlns='simple.xsd'>
    	<name>p1</name>
    	<number>1</number>
    	<extraElement> text </extraElement>
    </product>
}
