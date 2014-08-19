import module namespace parse-xml = "http://zorba.io/modules/xml";
import schema namespace opt = "http://zorba.io/modules/xml-options";
import module namespace fetch = "http://zorba.io/modules/fetch";

declare namespace an = "http://zorba.io/annotations";

declare variable $file external;

declare %an:sequential function local:test-sequential()
{  
};
 
variable $xmlcontents := fetch:content($file);

let $contents := parse-xml:parse(
      $xmlcontents,
      <opt:options>
        <opt:parse-external-parsed-entity opt:skip-root-nodes="1" />
      </opt:options>)

for $w at $pos in $contents
return
{
    local:test-sequential();
    $w
}