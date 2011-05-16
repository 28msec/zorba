import module namespace ddl = "http://www.zorba-xquery.com/modules/store/static/collections/ddl";
import module namespace ns = "http://example.org/datamodule/" at "collections.xqdata";

declare %sequential function local:create() {
  ddl:create-collection($ns:collection_1);
  ddl:create-collection($ns:collection_2);
  ddl:create-collection($ns:http);
  ddl:create-collection($ns:test1);
  ( 
    "create",
    for $x in ddl:available-collections()
    order by xs:string($x)
    return $x,
    ddl:is-available-collection($ns:collection_1),
    ddl:is-available-collection(xs:QName("ns:test3"))
  )
};

declare %sequential function local:delete() {
  ddl:delete-collection($ns:collection_1);
  ( 
    "delete",
    ddl:is-available-collection($ns:collection_1),
    for $x in ddl:available-collections()
    order by xs:string($x)
    return $x
  )
};

declare %sequential function local:main() {
  (
    local:create(),
    local:delete()
  )
};

local:main()
