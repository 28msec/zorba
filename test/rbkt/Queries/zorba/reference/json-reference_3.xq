import module namespace ddl = "http://zorba.io/modules/store/dynamic/collections/ddl";
import module namespace dml = "http://zorba.io/modules/store/dynamic/collections/dml";

import module namespace ref = "http://zorba.io/modules/reference";

declare namespace ann = "http://zorba.io/annotations";

declare %ann:sequential function local:test()
{
  ddl:create(xs:QName("local:coll"));
  dml:insert-last(xs:QName("local:coll"), { "foo" : "bar" });
  ref:dereference(ref:reference(dml:collection(xs:QName("local:coll"))))
};

local:test()
