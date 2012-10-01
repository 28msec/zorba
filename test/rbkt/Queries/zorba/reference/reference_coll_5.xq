import module namespace ddl = "http://www.zorba-xquery.com/modules/store/static/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/static/collections/dml";
import module namespace ns = "http://example.org/datamodule/" at "collections.xqdata";

import module namespace ref = "http://www.zorba-xquery.com/modules/node-reference";

declare namespace ann = "http://www.zorba-xquery.com/annotations";

declare %ann:sequential function local:test()
{
  ddl:create(xs:QName("ns:test2"));
  variable $ref  := xs:anyURI("urn:uuid:e35e9021-0a1c-48c7-8902-833105a2f013");
  variable $node := dml:apply-insert-nodes(xs:QName("ns:test2"), <f><g><h i="j"></h></g></f>);
  variable $has1 := ref:has-node-reference($node);
  ref:assign-node-reference($node, $ref);
  variable $has2 := ref:has-node-reference($node);
  variable $find := ref:node-by-reference($ref);
  ($has1, $has2, $node is $find)
};

local:test()
