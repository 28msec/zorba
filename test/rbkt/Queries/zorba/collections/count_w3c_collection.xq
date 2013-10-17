import module namespace ddl =
    "http://zorba.io/modules/store/dynamic/collections/w3c/ddl";

declare variable $coll := "http://zorba.io/collection";

ddl:create($coll);

fn:count(fn:collection($coll))
