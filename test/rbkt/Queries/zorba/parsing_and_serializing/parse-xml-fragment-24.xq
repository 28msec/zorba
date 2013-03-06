import module namespace x = "http://www.zorba-xquery.com/modules/xml";
import schema namespace opt = "http://www.zorba-xquery.com/modules/xml-options";

x:parse("test
",
  <opt:options>
    <opt:parse-external-parsed-entity/>
  </opt:options>
)
