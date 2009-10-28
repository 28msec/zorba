import module namespace dc = "http://www.zorba-xquery.com/module/dynamic-context";
import module namespace ddl = "http://www.zorba-xquery.com/module/ddl";
import datamodule namespace ns = "http://example.org/datamodule/" at "collections.xqdata";

declare sequential function local:create() {
  ddl:create-collection($ns:collection_1);
  ddl:create-collection($ns:collection_2);
  ddl:create-collection($ns:http);
  ddl:create-collection($ns:test1);
  ( 
    "create",
    dc:available-collections(),
    dc:is-available-collection($ns:collection_1),
    dc:is-available-collection(xs:QName("ns:test3"))
  );
};

declare sequential function local:drop() {
  ddl:drop-collection($ns:collection_1);
  ( 
    "drop",
    dc:is-available-collection($ns:collection_1),
    dc:available-collections()
  );
};

declare sequential function local:drop-all() {
  ddl:drop-all-collections();
  ("afterdropall",dc:available-collections());
};

declare sequential function local:main() {
  (
    local:create(),
    local:drop(),
    local:drop-all()
  );
};

local:main()
