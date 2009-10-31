
import module namespace dc = "http://www.zorba-xquery.com/module/dynamic-context";
import module namespace ddl = "http://www.zorba-xquery.com/module/ddl";

import datamodule namespace auctions = "http://www.w3.org/TestModules/auctions" at
                                       "auctions_module1.xqlib";

declare variable $idxname := $auctions:EmpId;

block
{
  auctions:create-db();

  for $x in auctions:probe-point-id($idxname, "person1")
  return <person id = "{$x/@id}">{$x/name}</person>;
}
,
block
{
  insert node
    <person id="person50"><name>Some Name</name></person>
  as first into
    dc:collection($auctions:auctions)/site/people
  ,
  ddl:refresh-index($idxname);
}
,
"

"
,
for $x in auctions:probe-point-id($idxname, "person50")
return <person id = "{$x/@id}">{$x/name}</person>
