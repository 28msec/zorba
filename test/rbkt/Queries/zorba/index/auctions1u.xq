import module namespace ddl = "http://www.zorba-xquery.com/modules/store/static/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/static/collections/dml";
import module namespace index_ddl = "http://www.zorba-xquery.com/modules/store/static/indexes/ddl";
import module namespace index_dml = "http://www.zorba-xquery.com/modules/store/static/indexes/dml";

import module namespace auctions = "http://www.w3.org/TestModules/auctions" at
                                       "auctions_module1.xqlib";

declare variable $emp-id := $auctions:PersonId;
declare variable $emp-city := $auctions:PersonCity;

{
  auctions:create-db();

  for $x in auctions:probe-point-id($emp-id, "person1")
  return <person id = "{$x/@id}">{$x/name}</person>
}
,
{
  insert node
    <person id="person50"><name>Some Name</name><city>Amsterdam</city></person>
  as first into
    dml:collection($auctions:auctions)/site/people;
  
  fn:trace("HELLO WORLD", "");

  index_dml:refresh-index($emp-id);
  (: don't refresh the emp-city index manually because it's done automatically :)

  ()
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
,
{
  dml:insert-nodes($auctions:auctions, doc("auctions2.xml"));
  ()
}
,
"

"
,
for $x in auctions:probe-range-city($emp-city, "T")
return <person id = "{$x/@id}">{$x/name}</person>
