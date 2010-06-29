import module namespace xqddf = "http://www.zorba-xquery.com/modules/xqddf";
import module namespace ns = "http://example.org/datamodule/" at "collections.xqdata";

import module namespace ref = "http://www.zorba-xquery.com/modules/node-reference";

declare sequential function local:test()
{
xqddf:create-collection(xs:QName("ns:test"));
xqddf:insert-nodes-last(xs:QName("ns:test"), <a><b><c d="e"></c></b></a>);

exit returning
fn:data(ref:node-by-reference(ref:node-reference(xqddf:collection(xs:QName("ns:test"))/b/c/@d)));
};

local:test()
