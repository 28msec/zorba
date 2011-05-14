import module namespace init = "http://www.zorba-xquery.com/modules/store/static-collections/initialization";
import module namespace manip = "http://www.zorba-xquery.com/modules/store/static-collections/manipulation";
import module namespace ns = "http://example.org/datamodule/" at "collections.xqdata";

declare %sequential function local:create() {
  init:create-collection($ns:collection_1);
  init:create-collection($ns:collection_2);
  init:create-collection($ns:http);
  init:create-collection($ns:test1);
  ( 
    "create",
    for $x in manip:available-collections()
    order by xs:string($x)
    return $x,
    manip:is-available-collection($ns:collection_1),
    manip:is-available-collection(xs:QName("ns:test3"))
  )
};

declare %sequential function local:delete() {
  init:delete-collection($ns:collection_1);
  ( 
    "delete",
    manip:is-available-collection($ns:collection_1),
    for $x in manip:available-collections()
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
