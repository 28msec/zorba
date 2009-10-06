import module namespace idx = "http://www.w3.org/TestModules/idx" at "module2.xqlib";

declare namespace zorba = "http://www.zorba-xquery.com/zorba/op-extensions";

zorba:create-index(xs:QName("idx:foo"));

(
for $x in idx:probe(xs:QName("idx:foo"), ())
return <person id = "{$x/@id}">{$x//city}</person>,

"

",

for $x in idx:probe2(xs:QName("idx:foo"), "Foo")
return <person id = "{$x/@id}">{$x//city}</person>
);
