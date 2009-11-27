import datamodule namespace decl = "http://www.test.com/" at "declared.xqlib";

import module namespace ddl = "http://www.zorba-xquery.com/modules/ddl";
import module namespace dc = "http://www.zorba-xquery.com/modules/introspection/dctx";

declare sequential function local:test_create() {
  ddl:create-collection(xs:QName("decl:coll1"));
  ddl:create-index(xs:QName("decl:coll1_index"));
  ddl:create-collection(xs:QName("decl:coll3"));
  ddl:create-index(xs:QName("decl:coll3_index"));
  (
    dc:is-available-index(xs:QName("decl:coll1_index")),
    dc:is-available-index(xs:QName("decl:coll2_index")),
    dc:is-available-index(xs:QName("decl:coll3_index")),
    for $x in dc:available-indexes()
    order by xs:string($x)
    return $x
  );
};

declare sequential function local:test_delete() {
  ddl:delete-index(xs:QName("decl:coll1_index"));
  (
    dc:is-available-index(xs:QName("decl:coll1_index")),
    dc:is-available-index(xs:QName("decl:coll2_index")),
    dc:is-available-index(xs:QName("decl:coll3_index")),
    dc:available-indexes()
  );
};

local:test_create(),local:test_delete()
