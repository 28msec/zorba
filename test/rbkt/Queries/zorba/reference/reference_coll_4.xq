import module namespace ddl = "http://www.zorba-xquery.com/modules/store/static/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/static/collections/dml";
import module namespace ns = "http://example.org/datamodule/" at "collections.xqdata";

import module namespace ref = "http://zorba.io/modules/reference";

declare namespace ann = "http://www.zorba-xquery.com/annotations";

declare %ann:sequential function local:test()
{
  ddl:create(xs:QName("ns:test2"));
  dml:insert-nodes(xs:QName("ns:test2"), <a><b><c d="e"></c></b></a>);
  variable $node := dml:collection(xs:QName("ns:test2"))/b/c/@d;
  variable $has1 := ref:has-reference($node);
  variable $ref  := ref:reference($node);
  variable $has2 := ref:has-reference($node);
  ($has1, $has2)
};

local:test()
