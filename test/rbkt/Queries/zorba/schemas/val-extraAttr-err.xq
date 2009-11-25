import schema namespace 
  s = "http://www.zorba-xquery.com/simple.xsd" 
  at "simple.xsd";

validate 
{
    <product xmlns='simple.xsd'
       extraAttribute='att value'>
    	<name>p1</name>
    	<number>1</number>
    </product>
}
