
import module namespace auctions = "http://www.w3.org/TestModules/auctions" at
                                   "auctions_module1.xqlib";

import module namespace ddl = "http://www.zorba-xquery.com/modules/store/static/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/static/collections/dml";
import module namespace index_ddl = "http://www.zorba-xquery.com/modules/store/static/indexes/ddl";
import module namespace index_dml = "http://www.zorba-xquery.com/modules/store/static/indexes/dml";

declare namespace err = "http://www.w3.org/2005/xqt-errors";

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

for $x in index_dml:probe-index-point-general($auctions:PersonWatches2, 
                                          ("open_auction6", "open_auction2"))
return <person id = "{$x/@id}">{$x//watches}</person>,

"

",

try
{
   index_dml:probe-index-point-value(xs:QName("auctions:PersonWatches2"), "open_auction7")
}
catch * 
{
  <exception>{$err:code} : {$err:description}</exception>
},

"

---------------------------------------------------
Probing the typed AuctionDates sorted general index
---------------------------------------------------

probe 1:
",

try
{ 
  index_dml:probe-index-point-value($auctions:AuctionDates, xs:date("2000-12-04"))
}
catch * 
{
  <exception>{$err:code} : {$err:description}</exception>
},

"

probe 2:
",

try
{
  index_dml:probe-index-point-value($auctions:AuctionDates, 10)
}
catch * 
{
  <exception>{$err:code} : {$err:description}</exception>
},

"

probe 3:
",

for $id in index_dml:probe-index-point-general($auctions:AuctionDates, 
                                           (xs:date("2000-12-04"),
                                            xs:date("2000-01-03"),
                                            xs:date("1998-08-18")))/@id
return <open_auction>{$id}</open_auction>,

"

probe 4:
",

try
{
  index_dml:probe-index-point-general($auctions:AuctionDates, 
                                      (xs:date("2000-12-04"), "2000-12-04"))
}
catch * 
{
  <exception>{$err:code} : {$err:description}</exception>
},

"

probe 5:
",

try
{
  index_dml:probe-index-range-value($auctions:AuctionDates, 
                                    xs:date("1998-12-11"),
                                    xs:date("1999-12-11"),
                                    fn:true(), fn:true(), fn:true(), fn:true())
}
catch * 
{
  <exception>{$err:code} : {$err:description}</exception>
},

"

probe 6:
",

for $id in index_dml:probe-index-range-general($auctions:AuctionDates,
                                               (), 
                                               (xs:date("1998-12-11"),
                                                xs:date("1998-01-13")),
                                               fn:false(),
                                               fn:true(),
                                               fn:false(),
                                               fn:true())/@id
return <open_auction>{$id}</open_auction>,

"

probe 7:
",

for $id in index_dml:probe-index-range-general($auctions:AuctionDates, 
                                               (xs:date("2001-11-11"),
                                                xs:date("2001-12-13")),
                                               (),
                                               fn:true(),
                                               fn:false(),
                                               fn:true(),
                                               fn:true())/@id
return <open_auction>{$id}</open_auction>,

"

probe 8:
",

for $id in index_dml:probe-index-range-general($auctions:AuctionDates, 
                                               (xs:date("2001-11-11"),
                                                xs:date("2001-12-13")),
                                               (),
                                               fn:true(),
                                               fn:false(),
                                               fn:false(),
                                               fn:true())/@id
return <open_auction>{$id}</open_auction>,

"

probe 9:
",

for $id in index_dml:probe-index-range-general($auctions:AuctionDates, 
                                               (xs:date("2001-11-11"),
                                                xs:date("2001-12-13")),
                                               (xs:date("1998-09-01")),
                                               fn:true(),
                                               fn:true(),
                                               fn:true(),
                                               fn:true())/@id
return <open_auction>{$id}</open_auction>,


"

Empty Probe
",

for $id in index_dml:probe-index-range-general($auctions:AuctionDates, 
                                               (xs:date("2011-11-11"),
                                                xs:date("2011-12-13")),
                                               (),
                                               fn:true(),
                                               fn:false(),
                                               fn:true(),
                                               fn:true())/@id
return <open_auction>{$id}</open_auction>,

"

Empty Probe
",

for $id in index_dml:probe-index-range-general($auctions:AuctionDates,
                                               (), 
                                               (xs:date("1011-11-11"),
                                                xs:date("1011-12-13")),
                                               fn:false(),
                                               fn:true(),
                                               fn:true(),
                                               fn:false())/@id
return <open_auction>{$id}</open_auction>,

"

Empty Probe
",

for $id in index_dml:probe-index-range-general($auctions:AuctionDates, 
                                               (),
                                               (),
                                               fn:true(),
                                               fn:false(),
                                               fn:true(),
                                               fn:true())/@id
return <open_auction>{$id}</open_auction>,


"

Full Probe

",

for $id in index_dml:probe-index-range-general($auctions:AuctionDates, 
                                               (),
                                               (),
                                               fn:false(),
                                               fn:false(),
                                               fn:true(),
                                               fn:true())/@id
return <open_auction>{$id}</open_auction>,

"

-------------------------------------------------------
Probing the untyped AuctionDates2 sorted general index
-------------------------------------------------------

probe 1:
",

try
{
  index_dml:probe-index-point-value($auctions:AuctionDates2, xs:date("2000-12-04"))
}
catch * 
{
  <exception>{$err:code} : {$err:description}</exception>
},

"

probe 2:
",

try
{
  index_dml:probe-index-point-value($auctions:AuctionDates2, 10)
}
catch * 
{
  <exception>{$err:code} : {$err:description}</exception>
},

"

probe 3:
",

for $id in index_dml:probe-index-point-general($auctions:AuctionDates2, 
                                               (xs:date("2000-12-04"),
                                                xs:date("2000-01-03"),
                                                xs:date("1998-08-18")))/@id
return <open_auction>{$id}</open_auction>,

"

probe 4:
",

for $id in index_dml:probe-index-point-general($auctions:AuctionDates2, 
                                               ("2000-12-04",
                                                "2000-01-03",
                                                10.23,
                                                xs:date("2000-01-03"),
                                                "1998-08-18"))/@id
return <open_auction>{$id}</open_auction>,

"

probe 5:
",

for $id in index_dml:probe-index-range-general($auctions:AuctionDates2, 
                                               (xs:date("2001-12-13"),
                                                xs:date("2001-11-11")),
                                               (),
                                               fn:true(),
                                               fn:false(),
                                               fn:false(),
                                               fn:true())/@id
return <open_auction>{$id}</open_auction>,

"

probe 6:
",

for $id in index_dml:probe-index-range-general($auctions:AuctionDates2, 
                                               xs:double("2001"),
                                               (),
                                               fn:true(),
                                               fn:false(),
                                               fn:false(),
                                               fn:true())/@id
return <open_auction>{$id}</open_auction>,

"

probe 7:
",

for $id in index_dml:probe-index-range-general($auctions:AuctionDates2, 
                                               (xs:untypedAtomic("2001-12-13"),
                                                xs:untypedAtomic("2001-11-11")),
                                               (),
                                               fn:true(),
                                               fn:false(),
                                               fn:false(),
                                               fn:true())/@id
return <open_auction>{$id}</open_auction>,

"

Full Probe:
",

for $id in index_dml:probe-index-range-general($auctions:AuctionDates2, 
                                               (),
                                               (),
                                               fn:false(),
                                               fn:false(),
                                               fn:true(),
                                               fn:true())/@id
return <open_auction>{$id}</open_auction>,

"

-----------------------------------------------------------
Probing the untyped PersonIncome2 sorted general 1-1 index
-----------------------------------------------------------

probe 1:

",

try
{
for $person in index_dml:probe-index-range-value($auctions:PersonIncome2, 
                                                 10000,
                                                 50000,
                                                 fn:true(),
                                                 fn:false(),
                                                 fn:true(),
                                                 fn:true())
return <person>{$person/@id, $person//@income}</person>
}
catch *
{
  <exception>{$err:code} : {$err:description}</exception>
},

"

probe 2:

",

for $person in index_dml:probe-index-range-value($auctions:PersonIncome2, 
                                                 "10000",
                                                 "50000",
                                                 fn:true(),
                                                 fn:true(),
                                                 fn:true(),
                                                 fn:true())
return <person>{$person/@id, $person//@income}</person>,

"

probe 3:

",

for $person in index_dml:probe-index-range-value($auctions:PersonIncome2, 
                                                 "50000",
                                                 "10000",
                                                 fn:true(),
                                                 fn:false(),
                                                 fn:true(),
                                                 fn:true())
return <person>{$person/@id, $person//@income}</person>,

"

probe 4:

",

for $person in index_dml:probe-index-range-value($auctions:PersonIncome2, 
                                                 "50000",
                                                 "10000",
                                                 fn:true(),
                                                 fn:true(),
                                                 fn:true(),
                                                 fn:true())
return <person>{$person/@id, $person//@income}</person>,

"

probe 5:

",

for $person in index_dml:probe-index-range-value($auctions:PersonIncome2, 
                                                 "50000",
                                                 "50000",
                                                 fn:true(),
                                                 fn:true(),
                                                 fn:true(),
                                                 fn:false())
return <person>{$person/@id, $person//@income}</person>,

"

probe 6 (full probe):

",

for $person in index_dml:probe-index-range-value($auctions:PersonIncome2, 
                                                 "50000",
                                                 "50000",
                                                 fn:false(),
                                                 fn:false(),
                                                 fn:true(),
                                                 fn:false())
return <person>{$person/@id, $person//@income}</person>,


"
"

)
