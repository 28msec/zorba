import module namespace z = "http://www.zorba-xquery.com/modules/xml";

z:parse-xml-fragment("<?xml version='1.0'?>
<root>
  <from1>Jani1</from1>
  <from2>Jani2</from2>
  <from3>Jani3</from3>
</root>", 
"er1")
