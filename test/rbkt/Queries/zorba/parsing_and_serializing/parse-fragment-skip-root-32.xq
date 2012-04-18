import module namespace z = "http://www.zorba-xquery.com/modules/xml";
import schema namespace opt = "http://www.zorba-xquery.com/modules/xml-options";

z:parse("<?xml version='1.0'?>
level0 text
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
</level1>
level0 text
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
</level1>
level0 text
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
</level1>
level0 text
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
</level1>
level0 text",
  <opt:options>
    <opt:parse-external-parsed-entity opt:skip-root-nodes="1"/>
  </opt:options>
)
