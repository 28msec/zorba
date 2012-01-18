import module namespace z = "http://www.zorba-xquery.com/modules/xml";
import schema namespace opt = "http://www.zorba-xquery.com/modules/xml-options"; 

z:parse("<?xml version='1.0'?>
<root>
  <from1>Jani1</from1>
  <from2>Jani2</from2>
  <from3>Jani3</from3>
</root>", 
  <opt:options>
    <opt:parse-external-parsed-entity opt:skip-root-nodes="2"/>
  </opt:options>
)
