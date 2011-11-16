import module namespace x = "http://www.zorba-xquery.com/modules/xml";
import schema namespace opt = "http://www.zorba-xquery.com/modules/xml-options";

x:parse-xml("<?xml version='1.0'?><a/>", 
  <opt:options>
    <opt:parseExternalParsedEntity/>
  </opt:options>
)

