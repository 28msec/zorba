import datamodule namespace idx = "http://www.w3.org/TestModules/idx" at
                                  "data_module1.xqlib";

declare namespace zorba = "http://www.zorba-xquery.com/zorba/op-extensions";

zorba:create-index(xs:QName("idx:foo"));

(
for $x in idx:probe(xs:QName("idx:foo"), "person1")
return <person id = "{$x/@id}">{$x/name}</person>,

"

",

for $x in idx:probe2(xs:QName("idx:foo"), "person3")
return <person id = "{$x/@id}">{$x/name}</person>
);
