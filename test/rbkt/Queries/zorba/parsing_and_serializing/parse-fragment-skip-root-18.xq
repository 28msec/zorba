import module namespace z = "http://www.zorba-xquery.com/modules/xml";
import schema namespace opt = "http://www.zorba-xquery.com/modules/xml-options"; 

z:parse-xml("<?xml version='1.0'?>
<root>Jani0<from1>Jani1</from1></root>", 
  <opt:options>
    <opt:parseExternalParsedEntity opt:skipRootNodes="2"/>
  </opt:options>
)
