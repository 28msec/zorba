import module namespace x = "http://www.zorba-xquery.com/modules/xml";

x:parse-xml-fragment("<?xml version='1.0'?>
<root>
  <from1>Jani</from1>
  
  <from2>Jani</from2>
  
  <from3>Jani</from3>
</root>", 
"")
