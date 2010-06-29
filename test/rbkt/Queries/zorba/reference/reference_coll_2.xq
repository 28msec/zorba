import module namespace xqddf = "http://www.zorba-xquery.com/modules/xqddf";
import module namespace ns = "http://example.org/datamodule/" at "collections.xqdata";

import module namespace ref = "http://www.zorba-xquery.com/modules/node-reference";

declare sequential function local:test()
{
  xqddf:create-collection(xs:QName("ns:test"));
  xqddf:insert-nodes-last(xs:QName("ns:test"), (<a/>,<b><z/></b>,<c/>));
  exit returning ref:node-by-reference(ref:node-reference(xqddf:collection(xs:QName("ns:test"))[2]/z));
};

local:test()
