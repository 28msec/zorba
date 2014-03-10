import module namespace parse-xml = "http://zorba.io/modules/xml";
import schema namespace opt = "http://zorba.io/modules/xml-options";
import module namespace fetch = "http://zorba.io/modules/fetch";

variable $xmlcontents := fetch:content(resolve-uri("bad.xml"));

let $contents := parse-xml:parse(
      $xmlcontents,
      <opt:options>
        <opt:parse-external-parsed-entity opt:skip-root-nodes="1"/>
      </opt:options>)

return $contents
