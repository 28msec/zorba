import module namespace parse-xml = "http://zorba.io/modules/xml";
import schema namespace opt = "http://zorba.io/modules/xml-options";
import module namespace fetch = "http://zorba.io/modules/fetch";
import module namespace ddl = "http://zorba.io/modules/store/dynamic/collections/ddl";
import module namespace dml = "http://zorba.io/modules/store/dynamic/collections/dml";

declare namespace an = "http://zorba.io/annotations";
declare namespace ext = "http://zorba.io/extensions";

declare variable $coll := xs:QName("ddl:coll1");

declare %an:sequential function local:test-sequential($pos)
{
  if ($pos eq 1)
  then dml:insert-last($coll, <d>{$pos}</d>);
  else ();
};
 
ddl:create($coll);
dml:insert-last($coll, (<a/>,<c/>,<b/>));

(# ext:no-materialization #)
{
  for $w at $pos in dml:collection($coll)
  return
  {
    local:test-sequential($pos);
    $w
  }
}
