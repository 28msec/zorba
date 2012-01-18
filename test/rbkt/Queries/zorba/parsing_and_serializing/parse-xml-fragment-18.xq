import module namespace z = "http://www.zorba-xquery.com/modules/xml";
import schema namespace opt = "http://www.zorba-xquery.com/modules/xml-options";

z:parse("<root><a id='0'/></root></test>",
  <opt:options>
    <opt:parse-external-parsed-entity/>
  </opt:options>
)
