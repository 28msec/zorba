import module namespace z = "http://zorba.io/modules/xml";
import schema namespace opt = "http://zorba.io/modules/xml-options";

z:parse("<?xml version='1.0'?>
<level1>
  level1 text start
  <level2>
    level2 text start
    <level3>
      level3 text start
      <level4>level4 text</level4>
      level3 text end
    </level3>
    level2 text end
  </level2>
  level1 text end
</level1>",
  <opt:options>
    <opt:parse-external-parsed-entity opt:skip-root-nodes="0"/>
  </opt:options>
)
