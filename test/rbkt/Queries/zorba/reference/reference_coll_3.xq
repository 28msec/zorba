import module namespace ddl = "http://zorba.io/modules/store/static/collections/ddl";
import module namespace dml = "http://zorba.io/modules/store/static/collections/dml";
import module namespace ns = "http://example.org/datamodule/" at "collections.xqdata";

import module namespace ref = "http://zorba.io/modules/reference";

declare namespace ann = "http://zorba.io/annotations";

declare %ann:sequential function local:test()
{
  ddl:create(xs:QName("ns:test"));
  dml:insert-last(xs:QName("ns:test"), <a><b><c d="e"></c></b></a>);

  exit returning
  fn:data(ref:dereference(ref:reference(dml:collection(xs:QName("ns:test"))/b/c/@d)));
};

local:test()
