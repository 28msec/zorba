
import datamodule namespace auctions = "http://www.w3.org/TestModules/auctions" at
                                       "auctions_module1.xqlib";

auctions:create-db();


(
for $x in auctions:probe-point-id(xs:QName("auctions:EmpId"), "person1")
return <person id = "{$x/@id}">{$x/name}</person>,

"

",

for $x in auctions:probe-range-id(xs:QName("auctions:EmpId"), "person3")
return <person id = "{$x/@id}">{$x/name}</person>,

"

",

for $x in auctions:probe-point-city(xs:QName("auctions:EmpCity"), ())
return <person id = "{$x/@id}">{$x//city}</person>,

"

",

for $x in auctions:probe-range-city(xs:QName("auctions:EmpCity"), "Foo")
return <person id = "{$x/@id}">{$x//city}</person>

);
