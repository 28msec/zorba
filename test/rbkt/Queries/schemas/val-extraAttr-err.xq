import schema namespace 
  s = "simple.xsd" 
  at "simple.xsd";

validate 
{
    <product xmlns='simple.xsd'
       extraAttribute='att value'>
    	<name>p1</name>
    	<number>1</number>
    </product>
}
