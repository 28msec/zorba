import module namespace ddl = "http://zorba.io/modules/store/static/collections/ddl";
import module namespace ns = "http://example.org/datamodule/" at "collections.xqdata";

declare namespace ann = "http://zorba.io/annotations";

declare %ann:sequential function local:create() {
  ddl:create($ns:collection_1);
  ddl:create($ns:collection_2);
  ddl:create($ns:http);
  ddl:create($ns:test1);
  ( 
    "create",
    for $x in ddl:available-collections()
    order by xs:string($x)
    return $x,
    ddl:is-available-collection($ns:collection_1),
    ddl:is-available-collection(xs:QName("ns:test3"))
  )
};

declare %ann:sequential function local:delete() {
  ddl:delete($ns:collection_1);
  ( 
    "delete",
    ddl:is-available-collection($ns:collection_1),
    for $x in ddl:available-collections()
    order by xs:string($x)
    return $x
  )
};

declare %ann:sequential function local:main() {
  (
    local:create(),
    local:delete()
  )
};

local:main()
