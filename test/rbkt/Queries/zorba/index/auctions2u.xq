import module namespace ddl = "http://www.zorba-xquery.com/modules/store/static/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/static/collections/dml";
import module namespace index_ddl = "http://www.zorba-xquery.com/modules/store/static/indexes/ddl";
import module namespace index_dml = "http://www.zorba-xquery.com/modules/store/static/indexes/dml";

import module namespace auctions = "http://www.w3.org/TestModules/auctions" at
                                       "auctions_module1.xqlib";


{
  auctions:create-db();

  for $x in auctions:probe-point-watch($auctions:PersonWatches,
                                       ("open_auction6", "open_auction2"))
  return <person id = "{$x/@id}">{$x//watches}</person>
}
,
"

"
,
{
  variable $person := 
  <doc>
  <site>
  <people>
  <person id="person203">
  <name>Ewing Andrade</name>
  <emailaddress>mailto:Andrade@fsu.edu</emailaddress>
  <city>Portland</city>
  <profile income="41889.41">
  <interest category="category0"/>
  <interest category="category0"/>
  <business>Yes</business>
  <age>18</age>
  </profile>
  <watches>
  <watch open_auction="open_auction6"/>
  <watch open_auction="open_auction2"/>
  <watch open_auction="open_auction6"/>
  <watch open_auction="open_auction5"/>
  </watches>
  </person>
  </people>
  </site>
  </doc>;

  dml:insert-nodes($auctions:auctions, $person);

  for $x in auctions:probe-point-watch($auctions:PersonWatches,
                                       ("open_auction6", "open_auction2"))
  return <person id = "{$x/@id}">{$x//watches}</person>
}
,
"

"
,
{
  dml:delete-nodes(dml:collection($auctions:auctions)[2]);

  for $x in auctions:probe-point-watch($auctions:PersonWatches,
                                       ("open_auction6", "open_auction2"))
  return <person id = "{$x/@id}">{$x//watches}</person>
}
,
"
"

