import module namespace parse-xml = "http://www.zorba-xquery.com/modules/xml";
import schema namespace opt = "http://www.zorba-xquery.com/modules/xml-options";

parse-xml:parse("one",
  <opt:options>
    <opt:parse-external-parsed-entity/>
  </opt:options>
)
