import module namespace z = "http://www.zorba-xquery.com/modules/xml";

z:parse-xml-fragment("<?xml version='1.0'?>
<root><root2><from1>Jani1</from1></root2></root>", 
"er3")
