import module namespace parse-xml = "http://zorba.io/modules/xml";
import schema namespace opt = "http://zorba.io/modules/xml-options";
import module namespace fetch = "http://zorba.io/modules/fetch";

declare namespace an = "http://zorba.io/annotations";
declare namespace ext = "http://zorba.io/extensions";

declare %an:sequential function local:test-sequential($pos)
{
  
};
 
variable $xmlcontents := fetch:content("$RBKT_SRC_DIR/Queries/zorba/flwor/flwor24.xml");

variable $contents := parse-xml:parse(
      $xmlcontents,
      <opt:options>
        <opt:parse-external-parsed-entity opt:skip-root-nodes="1" />
      </opt:options>);

(# ext:no-materialization #)
{
  for $w at $pos in $contents
  order by local-name($w) descending
  return
  {
    local:test-sequential($pos);
    $w
  }
}