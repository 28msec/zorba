(:
  Test x:parse() with streamable input
:)

import module namespace fetch = "http://zorba.io/modules/fetch";
import module namespace x = "http://zorba.io/modules/xml";
import schema namespace opt = "http://zorba.io/modules/xml-options";

let $xmlcontents := fetch:content(fn:resolve-uri("streamable.xml"))
let $contents := x:parse(
      $xmlcontents,
      <opt:options>
          <opt:parse-external-parsed-entity opt:skip-root-nodes="0" />
      </opt:options>)
for $article at $pos in $contents
return <ret>{ $article }</ret>
