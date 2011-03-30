import module namespace init = "http://www.zorba-xquery.com/modules/store/static-collections/initialization";
import module namespace manip = "http://www.zorba-xquery.com/modules/store/static-collections/manipulation";
import module namespace ns = "http://example.org/datamodule/" at "collections.xqdata";

import module namespace ref = "http://www.zorba-xquery.com/modules/node-reference";

declare sequential function local:test()
{
  init:create-collection(xs:QName("ns:test"));
  manip:insert-nodes-last(xs:QName("ns:test"), (<a/>,<b><z/></b>,<c/>));
  exit returning ref:node-by-reference(ref:node-reference(manip:collection(xs:QName("ns:test"))[2]/z));
};

local:test()
