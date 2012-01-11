import module namespace ddl =
    "http://www.zorba-xquery.com/modules/store/dynamic/collections/w3c/ddl";

declare variable $coll := "http://www.zorba-xquery.com/collection";

ddl:create($coll);

fn:count(fn:collection($coll))
