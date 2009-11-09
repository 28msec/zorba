import module namespace xqd = "http://www.zorba-xquery.com/modules/xqdoc";
import schema namespace xqds = "http://www.xqdoc.org/1.0" at "xqdoc-1.0.xsd";

declare sequential function local:remove-date($xqdoc)
{
  let $date := $xqdoc//xqds:date[1]
  return
	replace value of node $date with "";
  exit returning $xqdoc;
};

let $xqdoc as document-node (schema-element(xqds:xqdoc)) := 
  validate lax {
    xqd:xqdoc("gdata.xqlib")
  }
return
  local:remove-date($xqdoc)
