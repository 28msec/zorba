import module namespace xqdoc-mod = "http://www.zorba-xquery.com/zorba/xqdoc-functions";
import schema namespace xqdoc = "http://www.xqdoc.org/1.0" at "xqdoc-1.0.xsd";

declare sequential function local:remove-date($xqdoc)
{
  delete node $xqdoc//xqdoc:date;
  exit returning $xqdoc;
};

let $xqdoc as document-node (schema-element(xqdoc:xqdoc)) := validate lax { xqdoc-mod:xqdoc("gdata.xqlib") }
return local:remove-date($xqdoc)
