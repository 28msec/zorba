(:
  Test parse-xml:parse() with streamable input
:)

import module namespace fetch = "http://www.zorba-xquery.com/modules/fetch";
import module namespace parse-xml = "http://www.zorba-xquery.com/modules/xml";
import schema namespace opt = "http://www.zorba-xquery.com/modules/xml-options";

let $xmlcontents := fetch:content(fn:resolve-uri("streamable.xml"))
let $contents := parse-xml:parse(
      $xmlcontents,
      <opt:options>
          <opt:parse-external-parsed-entity opt:skip-root-nodes="0" />
      </opt:options>)
for $article at $pos in $contents
return <ret>{ $article }</ret>
