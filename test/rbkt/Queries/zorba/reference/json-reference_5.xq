import module namespace ddl = "http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/dynamic/collections/dml";

import module namespace ref = "http://zorba.io/modules/reference";

declare namespace ann = "http://www.zorba-xquery.com/annotations";

declare %ann:sequential function local:test()
{
  ddl:create(xs:QName("local:coll"));
  dml:insert-last(xs:QName("local:coll"), [ 1 ]);
  ref:dereference(ref:reference(dml:collection(xs:QName("local:coll"))))
};

local:test()

