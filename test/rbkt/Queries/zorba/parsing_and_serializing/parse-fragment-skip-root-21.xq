import module namespace z = "http://www.zorba-xquery.com/modules/xml";
import schema namespace opt = "http://www.zorba-xquery.com/modules/xml-options"; 

z:parse("<?xml version='1.0'?>
<level1>
  <level2>
    <level3>
      <level4>level4 text</level4>
    </level3>
  </level2>
</level1>",
  <opt:options>
    <opt:parse-external-parsed-entity opt:skip-root-nodes="2"/>
  </opt:options>
)
