import module namespace parse-xml = "http://www.zorba-xquery.com/modules/xml";
import schema namespace opt = "http://www.zorba-xquery.com/modules/xml-options";
import module namespace fetch = "http://www.zorba-xquery.com/modules/fetch";

variable $xmlcontents := fetch:content(resolve-uri("bad.xml"));

let $contents := parse-xml:parse(
      $xmlcontents,
      <opt:options>
        <opt:parse-external-parsed-entity opt:skip-root-nodes="1"/>
      </opt:options>)

return $contents
