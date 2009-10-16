import module namespace idx = "http://www.w3.org/TestModules/idx" at "module1.xqlib";

declare namespace zorba = "http://www.zorba-xquery.com/zorba/op-extensions";


block
{
  zorba:create-index(xs:QName("idx:foo"));

  for $x in idx:probe(xs:QName("idx:foo"), "person1")
  return <person id = "{$x/@id}">{$x/name}</person>;
}
,
block
{
  insert node
    <person id="person50"><name>Some Name</name></person>
  as first into
    doc("auction.xml")/site/people

  ,

  zorba:refresh-index(xs:QName("idx:foo"));
}

,

for $x in idx:probe(xs:QName("idx:foo"), "person50")
return <person id = "{$x/@id}">{$x/name}</person>
