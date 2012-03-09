import module namespace auctions = "http://www.w3.org/TestModules/auctions" at
                                   "auctions_module1.xqlib";

import module namespace ddl = "http://www.zorba-xquery.com/modules/store/static/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/static/collections/dml";
import module namespace index_ddl = "http://www.zorba-xquery.com/modules/store/static/indexes/ddl";
import module namespace index_dml = "http://www.zorba-xquery.com/modules/store/static/indexes/dml";

declare namespace err = "http://www.w3.org/2005/xqt-errors";

auctions:create-db();

variable $cities := ();

$cities := for $x in auctions:probe-point-city(xs:QName("auctions:PersonCity"), "Macon")
           return <person id = "{$x/@id}">{$x//city}</person>;

dml:truncate(xs:QName("auctions:auctions"));

$cities := ($cities, 
            for $x in auctions:probe-point-city(xs:QName("auctions:PersonCity"), "Macon")
            return <person id = "{$x/@id}">{$x//city}</person>);

$cities

