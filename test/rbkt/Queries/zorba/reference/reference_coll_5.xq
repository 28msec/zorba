import module namespace ddl = "http://zorba.io/modules/store/static/collections/ddl";
import module namespace dml = "http://zorba.io/modules/store/static/collections/dml";
import module namespace ns = "http://example.org/datamodule/" at "collections.xqdata";

import module namespace ref = "http://zorba.io/modules/reference";

declare namespace ann = "http://zorba.io/annotations";

declare %ann:sequential function local:test()
{
  ddl:create(xs:QName("ns:test2"));
  variable $ref  := xs:anyURI("urn:uuid:e35e9021-0a1c-48c7-8902-833105a2f013");
  variable $node := dml:apply-insert(xs:QName("ns:test2"), <f><g><h i="j"></h></g></f>);
  variable $has1 := ref:has-reference($node);
  ref:assign-reference($node, $ref);
  variable $has2 := ref:has-reference($node);
  variable $find := ref:dereference($ref);
  ($has1, $has2, $node is $find)
};

local:test()
