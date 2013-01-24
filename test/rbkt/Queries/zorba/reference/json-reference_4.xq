import module namespace ddl = "http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/dynamic/collections/dml";
import module namespace ns = "http://example.org/datamodule/" at "collections.xqdata";

import module namespace ref = "http://www.zorba-xquery.com/modules/reference";

declare namespace ann = "http://www.zorba-xquery.com/annotations";

declare %ann:sequential function local:test()
{
  ddl:create(xs:QName("ns:coll"));
  dml:insert-last(xs:QName("ns:coll"), { "foo" : "bar" });
  variable $node := dml:collection(xs:QName("ns:coll"));
  variable $has1 := ref:has-reference($node);
  variable $ref  := ref:reference($node);
  variable $has2 := ref:has-reference($node);
  ($has1, $has2)
};

local:test()

