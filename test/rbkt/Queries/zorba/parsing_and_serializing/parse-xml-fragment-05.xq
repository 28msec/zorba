import module namespace x = "http://www.zorba-xquery.com/modules/xml";
import schema namespace opt = "http://www.zorba-xquery.com/modules/xml-options";

x:parse("<?xml version='1.0'?><a/>", 
  <opt:options>
    <opt:parse-external-parsed-entity/>
  </opt:options>
)

