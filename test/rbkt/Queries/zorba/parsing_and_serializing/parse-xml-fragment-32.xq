(:
  Test parse-xml:parse() with a single top element which has an attribute
:)

import module namespace parse-xml = "http://www.zorba-xquery.com/modules/xml";
import schema namespace opt = "http://www.zorba-xquery.com/modules/xml-options";

parse-xml:parse(
  "<template head='test'></template>",
  <opt:options>
    <opt:parse-external-parsed-entity opt:skip-root-nodes="0"/>
  </opt:options>)
