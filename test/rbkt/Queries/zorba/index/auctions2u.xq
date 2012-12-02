import module namespace ddl = "http://www.zorba-xquery.com/modules/store/static/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/static/collections/dml";
import module namespace index_ddl = "http://www.zorba-xquery.com/modules/store/static/indexes/ddl";
import module namespace index_dml = "http://www.zorba-xquery.com/modules/store/static/indexes/dml";

import module namespace auctions = "http://www.w3.org/TestModules/auctions" at
                                       "auctions_module1.xqlib";

declare namespace err = "http://www.w3.org/2005/xqt-errors";


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


variable $person2 := 
  <doc>
  <site>
  <people>
  <person id="person205">
  <name>Dr Who</name>
  <emailaddress>mailto:boo@hell.edu</emailaddress>
  <city>Amsterdam</city>
  <profile income="41000000000889.41">
  <interest category="category0"/>
  <interest category="category0"/>
  <business>Yes</business>
  <age>18000</age>
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


"
TEST 1:

"
,
{
  auctions:create-db();

  for $x in auctions:probe-point-watch($auctions:PersonWatches,
                                       ("open_auction6", "open_auction2"))
  return <person id = "{$x/@id}">{$x//watches}</person>
}
,
"

TEST 2:

"
,
{
  dml:insert-nodes($auctions:auctions, $person);

  for $x in auctions:probe-point-watch($auctions:PersonWatches,
                                       ("open_auction6", "open_auction2"))
  return <person id = "{$x/@id}">{$x//watches}</person>
}
,
"

TEST 3:

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

TEST 4:

"
,
{
  dml:insert-nodes($auctions:auctions, $person);

  (
    dml:insert-nodes($auctions:auctions, $person2),

    dml:delete-nodes(dml:collection($auctions:auctions)[2]),

    insert node <watch open_auction="open_auction6"/> into 
    (dml:collection($auctions:auctions)[2])//watches
  );

  for $x in auctions:probe-point-watch($auctions:PersonWatches,
                                       ("open_auction6", "open_auction2"))
  return <person id = "{$x/@id}">{$x//watches}</person>
}
,
"

TEST 5:

"
,
{
  (
    dml:insert-nodes($auctions:auctions, $person),

    insert node <watch open_auction="open_auction8"/> into 
    (dml:collection($auctions:auctions)[2])//watches
  );

  for $x in auctions:probe-point-watch($auctions:PersonWatches,
                                       ("open_auction6", "open_auction2"))
  return <person id = "{$x/@id}">{$x//watches}</person>
}
,
"

TEST 6 (undo without do):

"
,
{
  try
  {{
  (
    dml:insert-nodes($auctions:auctions, $person),

    insert node (attribute id { 1 }) into $person//person
  );
  ()
  }}
  catch *
  {
    <exception>{$err:code} : { $err:description }</exception>
  }
  ,
  for $x in auctions:probe-point-watch($auctions:PersonWatches,
                                       ("open_auction6", "open_auction2"))
  return <person id = "{$x/@id}">{$x//watches}</person>
}
,
"
"

