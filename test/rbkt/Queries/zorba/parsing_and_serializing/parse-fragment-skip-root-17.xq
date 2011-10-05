import module namespace z = "http://www.zorba-xquery.com/modules/xml";

z:parse-xml-fragment("<?xml version='1.0'?><root>root1 text<root15>root15 text</root15><root2>root2 text<root3>root3 text<from1>Jani1</from1></root3></root2></root>", 
"er3")
