import module namespace xqd = "http://www.zorba-xquery.com/modules/xqdoc";
import schema namespace xqds = "http://www.xqdoc.org/1.0";

declare namespace ann = "http://www.zorba-xquery.com/annotations";

declare %ann:sequential function local:remove-date($xqdoc)
{
  let $date := $xqdoc//xqds:date[1]
  return
	replace value of node $date with "";
  exit returning $xqdoc;
};

let $content := "
  (:~
   : <p>
   :)
  module namespace foo = 'http://www.example.com/';
"
let $xqdoc as document-node (schema-element(xqds:xqdoc)) := 
  validate lax {
    xqd:xqdoc-content($content)
  }
return
  local:remove-date($xqdoc)


