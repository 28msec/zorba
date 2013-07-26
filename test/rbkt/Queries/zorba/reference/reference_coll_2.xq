import module namespace ddl = "http://www.zorba-xquery.com/modules/store/static/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/static/collections/dml";
import module namespace ns = "http://example.org/datamodule/" at "collections.xqdata";

import module namespace ref = "http://zorba.io/modules/reference";

declare namespace ann = "http://www.zorba-xquery.com/annotations";

declare %ann:sequential function local:test()
{
  ddl:create(xs:QName("ns:test"));
  dml:insert-nodes-last(xs:QName("ns:test"), (<a/>,<b><z/></b>,<c/>));
  exit returning ref:dereference(ref:reference(dml:collection(xs:QName("ns:test"))[2]/z));
};

local:test()
