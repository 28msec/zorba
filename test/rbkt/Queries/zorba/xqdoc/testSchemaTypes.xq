(: test if prefixes declared by schema imports can be used in type constructors :)
import module namespace xqd = "http://www.zorba-xquery.com/modules/xqdoc";

declare namespace ann = "http://www.zorba-xquery.com/annotations";

declare %ann:sequential function local:remove-date($xqdoc)
{
  let $date := $xqdoc//*:date[1]
  return
  replace value of node $date with "";
  exit returning $xqdoc;
};

let $xqdoc := xqd:xqdoc("image.xqlib")
return
  local:remove-date($xqdoc)
