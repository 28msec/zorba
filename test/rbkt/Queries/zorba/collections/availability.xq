import module namespace dc = "http://www.zorba-xquery.com/modules/introspection/dctx";
import module namespace ddl = "http://www.zorba-xquery.com/modules/ddl";
import datamodule namespace ns = "http://example.org/datamodule/" at "collections.xqdata";

declare sequential function local:create() {
  ddl:create-collection($ns:collection_1);
  ddl:create-collection($ns:collection_2);
  ddl:create-collection($ns:http);
  ddl:create-collection($ns:test1);
  ( 
    "create",
    for $x in dc:available-collections()
    order by xs:string($x)
    return $x,
    dc:is-available-collection($ns:collection_1),
    dc:is-available-collection(xs:QName("ns:test3"))
  );
};

declare sequential function local:delete() {
  ddl:delete-collection($ns:collection_1);
  ( 
    "delete",
    dc:is-available-collection($ns:collection_1),
    for $x in dc:available-collections()
    order by xs:string($x)
    return $x
  );
};

declare sequential function local:main() {
  (
    local:create(),
    local:delete()
  );
};

local:main()
