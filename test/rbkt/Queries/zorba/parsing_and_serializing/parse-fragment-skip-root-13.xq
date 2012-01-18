import module namespace z = "http://www.zorba-xquery.com/modules/xml";
import schema namespace opt = "http://www.zorba-xquery.com/modules/xml-options"; 

z:parse("<?xml version='1.0'?>
<root><root2><root3><from1>Jani1</from1></root3></root2></root>", 
  <opt:options>
    <opt:parse-external-parsed-entity opt:skip-root-nodes="3"/>
  </opt:options>
)
