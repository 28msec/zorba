import module namespace ddl =
    "http://www.zorba-xquery.com/modules/store/static/collections/ddl";

import module namespace dml =
    "http://www.zorba-xquery.com/modules/store/static/collections/dml";

import module namespace ns = "http://example.org/datamodule/" 
    at "collections.xqdata";

declare variable $coll := xs:QName("ns:test1");

ddl:create($coll);

fn:count(dml:collection($coll))
