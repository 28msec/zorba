import module namespace ddl = "http://www.zorba-xquery.com/modules/ddl";
import module namespace ns = "http://example.org/datamodule/" at "collections.xqdata";

import module namespace zorba = "http://www.zorba-xquery.com/zorba/node-ref-functions";

declare sequential function local:test()
{
  ddl:create-collection(xs:QName("ns:test"));
  ddl:insert-nodes-last(xs:QName("ns:test"), (<a/>,<b><z/></b>,<c/>));
  exit returning zorba:node-by-reference(zorba:node-reference(ddl:collection(xs:QName("ns:test"))[2]/z));
};

local:test()
