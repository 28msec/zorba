import module namespace z = "http://zorba.io/modules/xml";
import schema namespace opt = "http://zorba.io/modules/xml-options";

z:parse("<root><a id='0'/></root></test>",
  <opt:options>
    <opt:parse-external-parsed-entity/>
  </opt:options>
)
