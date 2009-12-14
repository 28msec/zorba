import module namespace dc = "http://www.zorba-xquery.com/modules/introspection/dctx";
import module namespace xqddf = "http://www.zorba-xquery.com/modules/xqddf";
import module namespace ns = "http://example.org/datamodule/" at "collections.xqdata";

declare sequential function local:create() {
  xqddf:create-collection($ns:collection_1);
  xqddf:create-collection($ns:collection_2);
  xqddf:create-collection($ns:http);
  xqddf:create-collection($ns:test1);
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
  xqddf:delete-collection($ns:collection_1);
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
