import module namespace parse-xml = "http://zorba.io/modules/xml";
import schema namespace opt = "http://zorba.io/modules/xml-options";
import module namespace fetch = "http://zorba.io/modules/fetch";

declare namespace an = "http://zorba.io/annotations";
declare namespace ext = "http://zorba.io/extensions";

declare variable $file external;

declare %an:sequential function local:test-sequential()
{
  
};
 
variable $xmlcontents := fetch:content($file);

variable $contents := parse-xml:parse(
      $xmlcontents,
      <opt:options>
        <opt:parse-external-parsed-entity opt:skip-root-nodes="1" />
      </opt:options>);

(# ext:no-materialization #)
{
  for $w at $pos in $contents
  return
  {
    local:test-sequential();
    $w
  }
}