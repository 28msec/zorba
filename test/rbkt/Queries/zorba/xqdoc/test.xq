import module namespace xqd = "http://www.zorba-xquery.com/modules/xqdoc";
import schema namespace xqds = "http://www.xqdoc.org/1.0" at "xqdoc-1.0.xsd";

declare sequential function local:remove-date($xqdoc)
{
  delete node $xqdoc//xqds:param[1];
  exit returning $xqdoc;
};

let $xqdoc as document-node (schema-element(xqds:xqdoc)) := 
  validate lax {
    xqd:xqdoc("gdata.xqlib")
  }
return
  local:remove-date($xqdoc)
