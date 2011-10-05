import module namespace z = "http://www.zorba-xquery.com/modules/xml";

z:parse-xml-fragment("<?xml version='1.0'?>
<level1>
  <level2>
    <level3>
      <level4>level4 text</level4>
    </level3>
  </level2>
</level1>",
"er3")
