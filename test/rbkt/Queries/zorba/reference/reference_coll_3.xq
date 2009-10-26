import module namespace ddl = "http://www.zorba-xquery.com/module/ddl";
import module namespace dc = "http://www.zorba-xquery.com/module/dynamic-context";
import datamodule namespace ns = "http://example.org/datamodule/" at "collections.xqdata";

import module namespace zorba =
"http://www.zorba-xquery.com/zorba/node-ref-functions";

declare sequential function local:test()
{
ddl:create-collection(xs:QName("ns:test"));
ddl:insert-nodes-last(xs:QName("ns:test"), <a><b><c d="e"></c></b></a>);

exit returning
fn:data(zorba:node-by-reference(zorba:node-reference(dc:collection(xs:QName("ns:test"))/b/c/@d)));
};

local:test()
