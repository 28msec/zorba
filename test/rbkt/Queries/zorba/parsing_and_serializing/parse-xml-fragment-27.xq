import module namespace x = "http://zorba.io/modules/xml";
import schema namespace opt = "http://zorba.io/modules/xml-options";

x:parse("on",
  <opt:options>
    <opt:parse-external-parsed-entity/>
  </opt:options>
)
