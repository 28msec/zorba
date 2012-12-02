
import module namespace auctions = "http://www.w3.org/TestModules/auctions" at
                                   "auctions_module1.xqlib";

import module namespace ddl = "http://www.zorba-xquery.com/modules/store/static/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/static/collections/dml";
import module namespace index_ddl = "http://www.zorba-xquery.com/modules/store/static/indexes/ddl";
import module namespace index_dml = "http://www.zorba-xquery.com/modules/store/static/indexes/dml";

declare namespace err = "http://www.w3.org/2005/xqt-errors";

{
  ddl:create($auctions:auctions);

  dml:insert-nodes($auctions:auctions, doc("auctions1.xml"));

  index_ddl:create($auctions:PersonCity);

  ()
}

,

"
First probing for Amsterdam:
"
,

for $x in auctions:probe-point-city($auctions:PersonCity, "Amsterdam")
return <person id = "{$x/@id}">{$x/name}</person>

,

"

"
,

{
  variable $foo := dml:collection($auctions:auctions)[1];

  (
    try
    {
    {
      (
        insert node
          <person id="person50"><name>Some Name</name><city>Amsterdam</city></person>
        as first into
          dml:collection($auctions:auctions)/site/people
        ,
        ddl:delete($auctions:auctions)
      );

      ()
    }
    }
    catch *
    {
      <exception>{ $err:code } : { $err:description }</exception>
    }

    ,

    "

Second probing for Amsterdam
"
    ,
    for $x in auctions:probe-point-city($auctions:PersonCity, "Amsterdam")
    return <person id = "{$x/@id}">{$x/name}</person>
  )
}
