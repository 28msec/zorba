import module namespace parse-xml = "http://zorba.io/modules/xml";
import schema namespace opt = "http://zorba.io/modules/xml-options";
import module namespace fetch = "http://zorba.io/modules/fetch";

declare namespace an = "http://zorba.io/annotations";

declare %an:sequential function local:test-sequential()
{
  
};
 
variable $xmlcontents := fetch:content("$RBKT_SRC_DIR/Queries/zorba/flwor/flwor24.xml");

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