import module namespace ddl =
    "http://zorba.io/modules/store/dynamic/collections/ddl";
import module namespace dml =
    "http://zorba.io/modules/store/dynamic/collections/dml";

declare variable $coll := xs:QName("collection");

ddl:create($coll);

fn:count(dml:collection($coll))
