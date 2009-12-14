import module namespace decl = "http://www.test.com/" at "declared.xqlib";

import module namespace xqddf = "http://www.zorba-xquery.com/modules/xqddf";
import module namespace dc = "http://www.zorba-xquery.com/modules/introspection/dctx";

declare sequential function local:test_create() {
  xqddf:create-collection(xs:QName("decl:coll1"));
  xqddf:create-index(xs:QName("decl:coll1_index"));
  xqddf:create-collection(xs:QName("decl:coll3"));
  xqddf:create-index(xs:QName("decl:coll3_index"));
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
  xqddf:delete-index(xs:QName("decl:coll1_index"));
  (
    dc:is-available-index(xs:QName("decl:coll1_index")),
    dc:is-available-index(xs:QName("decl:coll2_index")),
    dc:is-available-index(xs:QName("decl:coll3_index")),
    dc:available-indexes()
  );
};

local:test_create(),local:test_delete()
