import module namespace x = "http://zorba.io/modules/xml";
import schema namespace opt = "http://zorba.io/modules/xml-options";
import module namespace fetch = "http://zorba.io/modules/fetch";

variable $xmlcontents := fetch:content(resolve-uri("wiki.xml"));

let $contents := x:parse(
      $xmlcontents,
      <opt:options>
        <opt:parse-external-parsed-entity opt:skip-root-nodes="1" />
      </opt:options>)

for $article at $pos in $contents
let $title := $article//title
return
    $title
