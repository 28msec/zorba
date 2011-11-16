import module namespace z = "http://www.zorba-xquery.com/modules/xml";
import schema namespace opt = "http://www.zorba-xquery.com/modules/xml-options"; 

z:parse-xml("<?xml version='1.0'?>
<root>
  <root2>
    <from1>Jani1</from1>
  </root2>
  <root2>
    <from2>Jani2</from2>
  </root2>
  <root2>
    <from3>Jani3</from3>
  </root2>
</root>", 
  <opt:options>
    <opt:parseExternalParsedEntity opt:skipRootNodes="2"/>
  </opt:options>
)
