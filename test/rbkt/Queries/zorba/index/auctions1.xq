
import module namespace auctions = "http://www.w3.org/TestModules/auctions" at
                                   "auctions_module1.xqlib";

auctions:create-db();


(
for $x in auctions:probe-point-id(xs:QName("auctions:PersonId"), "person1")
return <person id = "{$x/@id}">{$x/name}</person>,

"

",

for $x in auctions:probe-range-id(xs:QName("auctions:PersonId"), "person3")
return <person id = "{$x/@id}">{$x/name}</person>,

"

",

for $x in auctions:probe-point-city(xs:QName("auctions:PersonCity"), "X")
return <person id = "{$x/@id}">{$x//city}</person>,

"

",

for $x in auctions:probe-range-city(xs:QName("auctions:PersonCity"), "Foo")
return <person id = "{$x/@id}">{$x//city}</person>,


"

",

for $x in auctions:probe-point-watch(xs:QName("auctions:PersonWatches"),
                                     ("open_auction6", "open_auction2"))
return <person id = "{$x/@id}">{$x//watches}</person>
);
