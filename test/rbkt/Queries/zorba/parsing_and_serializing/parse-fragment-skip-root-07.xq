import module namespace z = "http://zorba.io/modules/xml";
import schema namespace opt = "http://zorba.io/modules/xml-options"; 

z:parse("<?xml version='1.0'?>
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
    <opt:parse-external-parsed-entity opt:skip-root-nodes="3"/>
  </opt:options>
)
