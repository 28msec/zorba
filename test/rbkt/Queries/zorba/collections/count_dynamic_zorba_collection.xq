import module namespace ddl =
    "http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl";
import module namespace dml =
    "http://www.zorba-xquery.com/modules/store/dynamic/collections/dml";

declare variable $coll := xs:QName("collection");

ddl:create($coll);

fn:count(dml:collection($coll))
