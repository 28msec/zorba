import module namespace z = "http://www.zorba-xquery.com/modules/xml";
import schema namespace opt = "http://www.zorba-xquery.com/modules/xml-options";

z:parse-xml("<?xml version='1.0'?><root><from1>Jani</from1></root>", 
  <opt:options>
    <opt:parseExternalParsedEntity opt:skipRootNodes="1"/>
  </opt:options>
)
