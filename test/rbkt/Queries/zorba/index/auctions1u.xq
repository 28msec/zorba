
import module namespace dc = "http://www.zorba-xquery.com/module/dynamic-context";
import module namespace ddl = "http://www.zorba-xquery.com/module/ddl";

import datamodule namespace auctions = "http://www.w3.org/TestModules/auctions" at
                                       "auctions_module1.xqlib";

declare variable $emp-id := $auctions:PersonId;
declare variable $emp-city := $auctions:PersonCity;

block
{
  auctions:create-db();

  for $x in auctions:probe-point-id($emp-id, "person1")
  return <person id = "{$x/@id}">{$x/name}</person>;
}
,
block
{
  insert node
    <person id="person50"><name>Some Name</name><city>Amsterdam</city></person>
  as first into
    dc:collection($auctions:auctions)/site/people
  ,
  ddl:refresh-index($emp-id);
}
,
"

"
,
for $x in auctions:probe-point-id($emp-id, "person50")
return <person id = "{$x/@id}">{$x/name}</person>
,
"

"
,
for $x in auctions:probe-point-city($emp-city, "Amsterdam")
return <person id = "{$x/@id}">{$x/name}</person>

