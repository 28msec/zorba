
import module namespace auctions = "http://www.w3.org/TestModules/auctions" at
                                   "auctions_module1.xqlib";

import module namespace init = "http://www.zorba-xquery.com/modules/store/static-collections/initialization";
import module namespace manip = "http://www.zorba-xquery.com/modules/store/static-collections/manipulation";

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

for $x in auctions:probe-point-watch($auctions:PersonWatches,
                                     ("open_auction6", "open_auction2"))
return <person id = "{$x/@id}">{$x//watches}</person>,

"

",

for $x in manip:probe-index-point-general($auctions:PersonWatches2, 
                                          ("open_auction6", "open_auction2"))
return <person id = "{$x/@id}">{$x//watches}</person>,

"

",

try
{
   manip:probe-index-point-value(xs:QName("auctions:PersonWatches2"), "open_auction7")
}
catch * ($code, $desc)
{
  <exception>{$code} : {$desc}</exception>
},

"

---------------------------------------------------
Probing the typed AuctionDates sorted general index
---------------------------------------------------

",

try
{ 
  manip:probe-index-point-value($auctions:AuctionDates, xs:date("2000-12-04"))
}
catch * ($code, $desc)
{
  <exception>{$code} : {$desc}</exception>
},

"

",

try
{
  manip:probe-index-point-value($auctions:AuctionDates, 10)
}
catch * ($code, $desc)
{
  <exception>{$code} : {$desc}</exception>
},

"

",

for $id in manip:probe-index-point-general($auctions:AuctionDates, 
                                           (xs:date("2000-12-04"),
                                            xs:date("2000-01-03"),
                                            xs:date("1998-08-18")))/@id
return <open_auction>{$id}</open_auction>,

"

",

try
{
  manip:probe-index-point-general($auctions:AuctionDates, 
                                  (xs:date("2000-12-04"), "2000-12-04"))
}
catch * ($code, $desc)
{
  <exception>{$code} : {$desc}</exception>
},

"

-------------------------------------------------------
Probing the untyped AuctionDates2 sorted general index
-------------------------------------------------------

",

try
{
  manip:probe-index-point-value($auctions:AuctionDates2, xs:date("2000-12-04"))
}
catch * ($code, $desc)
{
  <exception>{$code} : {$desc}</exception>
},

"

",

try
{
  manip:probe-index-point-value($auctions:AuctionDates2, 10)
}
catch * ($code, $desc)
{
  <exception>{$code} : {$desc}</exception>
},

"

",



for $id in manip:probe-index-point-general($auctions:AuctionDates2, 
                                           (xs:date("2000-12-04"),
                                            xs:date("2000-01-03"),
                                            xs:date("1998-08-18")))/@id
return <open_auction>{$id}</open_auction>,

"

",

for $id in manip:probe-index-point-general($auctions:AuctionDates2, 
                                           ("2000-12-04",
                                            "2000-01-03",
                                            10.23,
                                            xs:date("2000-01-03"),
                                            "1998-08-18"))/@id
return <open_auction>{$id}</open_auction>,

"
"

)
